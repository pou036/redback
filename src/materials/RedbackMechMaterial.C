/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "RedbackMechMaterial.h"
#include "Ellipse.h"

#include <cmath> //used for fabs

/**
RedbackMechMaterial integrates the rate dependent plasticity model of Perzyna (Overstress model) in a
finite strain framework using return mapping algorithm. Ideally this matrial should inherit from both
the Redback material and the tensor mechanics finite strain equivalent

Three yield criteria are included:
1. pressure-independent (J2 plasticity)
2. linear pressure-dependent (Drucker-Prager with smoothing of the apex)
3. Non-linear, capped pressur dependent (modified cam clay)

Integration is performed for associative flow rules in an incremental manner using Newton Raphson.
Isotropic hardening/softening has been incorporated where yield stress as a function of equivalent
plastic strain has to be specified by the user.
*/

template<>
InputParameters validParams<RedbackMechMaterial>()
{
  InputParameters params = validParams<RedbackMaterial>();

  // Copy-paste from TensorMechanicsMaterial.C
  params.addRequiredParam<std::vector<Real> >("C_ijkl", "Stiffness tensor for material");
  params.addParam<MooseEnum>("fill_method", RankFourTensor::fillMethodEnum() = "symmetric9", "The fill method");
  params.addParam<Real>("euler_angle_1", 0.0, "Euler angle in direction 1");
  params.addParam<Real>("euler_angle_2", 0.0, "Euler angle in direction 2");
  params.addParam<Real>("euler_angle_3", 0.0, "Euler angle in direction 3");
  params.addRequiredCoupledVar("disp_x", "The x displacement");
  params.addRequiredCoupledVar("disp_y", "The y displacement");
  params.addCoupledVar("disp_z", "The z displacement");
  params.addCoupledVar("temperature", "temperature variable");

  // Copy-paste from FiniteStrainMaterial.C
  // nothing

  // Copy-paste from FiniteStrainPlasticMaterial.C
  params.addRequiredParam< std::vector<Real> >("yield_stress", "Input data as pairs of equivalent plastic strain and yield stress: Should start with equivalent plastic strain 0");
  params.addParam<Real>("rtol",1e-8,"Plastic strain NR tolerance");
  params.addParam<Real>("ftol",1e-4,"Consistency condition NR tolerance");
  params.addParam<Real>("eptol",1e-7,"Equivalent plastic strain NR tolerance");
  params.addClassDescription("Associative J2 plasticity with isotropic hardening.");

  //  Copy-paste from FiniteStrainPlasticRateMaterial.C
  params.addParam< Real >("ref_pe_rate", "Reference plastic strain rate parameter for rate dependent plasticity (Overstress model)");
  params.addParam< Real >("exponent", "Exponent for rate dependent plasticity (Perzyna)");
  params.addParam<MooseEnum>("yield_criterion", RedbackMechMaterial::yieldCriterionEnum() = "J2_plasticity", "Yield criterion");
  params.addParam< Real >("slope_yield_surface", 0,"Slope of yield surface (positive, see documentation)");
  params.addParam< Real >("mixture_compressibility", 1,"Compressibility of the rock+fluid mixture");

  return params;
}

RedbackMechMaterial::RedbackMechMaterial(const std::string & name, InputParameters parameters) :
  RedbackMaterial(name, parameters),
  // Copy-paste from TensorMechanicsMaterial.C
  _grad_disp_x(coupledGradient("disp_x")),
  _grad_disp_y(coupledGradient("disp_y")),
  _grad_disp_z(_mesh.dimension() == 3 ? coupledGradient("disp_z") : _grad_zero),
  _grad_disp_x_old(_fe_problem.isTransient() ? coupledGradientOld("disp_x") : _grad_zero),
  _grad_disp_y_old(_fe_problem.isTransient() ? coupledGradientOld("disp_y") : _grad_zero),
  _grad_disp_z_old(_fe_problem.isTransient() && _mesh.dimension() == 3 ? coupledGradientOld("disp_z") : _grad_zero),
  _stress(declareProperty<RankTwoTensor>("stress")),
  _total_strain(declareProperty<RankTwoTensor>("total_strain")),
  _elastic_strain(declareProperty<RankTwoTensor>("elastic_strain")),
  _elasticity_tensor(declareProperty<ElasticityTensorR4>("elasticity_tensor")),
  _Jacobian_mult(declareProperty<ElasticityTensorR4>("Jacobian_mult")),
  // _d_stress_dT(declareProperty<RankTwoTensor>("d_stress_dT")),
  _Cijkl_vector(getParam<std::vector<Real> >("C_ijkl")),
  _Cijkl(),
  _fill_method((RankFourTensor::FillMethod)(int)getParam<MooseEnum>("fill_method")),

  // Copy-paste from FiniteStrainMaterial.C
  _strain_rate(declareProperty<RankTwoTensor>("strain_rate")),
  _strain_increment(declareProperty<RankTwoTensor>("strain_increment")),
  _total_strain_old(declarePropertyOld<RankTwoTensor>("total_strain")),
  _elastic_strain_old(declarePropertyOld<RankTwoTensor>("elastic_strain")),
  _stress_old(declarePropertyOld<RankTwoTensor>("stress")),
  _rotation_increment(declareProperty<RankTwoTensor>("rotation_increment")),
  _dfgrd(declareProperty<RankTwoTensor>("deformation gradient")),

  // Copy-paste from FiniteStrainPlasticMaterial.C
  _yield_stress_vector(getParam< std::vector<Real> >("yield_stress")),//Read from input file
  _plastic_strain(declareProperty<RankTwoTensor>("plastic_strain")),
  _plastic_strain_old(declarePropertyOld<RankTwoTensor>("plastic_strain")),
  _eqv_plastic_strain(declareProperty<Real>("eqv_plastic_strain")),
  _eqv_plastic_strain_old(declarePropertyOld<Real>("eqv_plastic_strain")),

  // Copy-paste from FiniteStrainPlasticRateMaterial.C
  _ref_pe_rate(getParam<Real>("ref_pe_rate")),
  _exponent(getParam<Real>("exponent")),

  // Redback
  _mises_stress(declareProperty<Real>("mises_stress")),
  _mean_stress(declareProperty<Real>("mean_stress")),
  _mises_strain_rate(declareProperty<Real>("mises_strain_rate")),
  _volumetric_strain(declareProperty<Real>("volumetric_strain")),
  _volumetric_strain_rate(declareProperty<Real>("volumetric_strain_rate")),
  _mixture_compressibility_param(getParam<Real>("mixture_compressibility")),
  _mixture_compressibility(declareProperty<Real>("mixture_compressibility")),
  _yield_criterion((YieldCriterion)(int)getParam<MooseEnum>("yield_criterion")),
  _slope_yield_surface(getParam<Real>("slope_yield_surface")),
  _dispx_dot(coupledDot("disp_x")),
  _dispy_dot(coupledDot("disp_y")),
  _dispz_dot(coupledDot("disp_z"))

  {
  _Cijkl.fillFromInputVector(_Cijkl_vector, _fill_method);
  }

MooseEnum
RedbackMechMaterial::yieldCriterionEnum()
{
  return MooseEnum("elasticity, J2_plasticity, Drucker_Prager, modified_Cam_Clay");
}

// TODO: break down this file for separate yield criteria
void
RedbackMechMaterial::initQpStatefulProperties()
{
  RedbackMaterial::initQpStatefulProperties();
  _total_strain[_qp].zero();
  _elastic_strain[_qp].zero();
  _stress[_qp].zero();
  _plastic_strain[_qp].zero();
  _plastic_strain_old[_qp].zero();
  _eqv_plastic_strain[_qp] = 0.0;

  // Redback properties
  _mises_stress[_qp] = 0;
  _mean_stress[_qp] = 0;
  _mises_strain_rate[_qp] = 0;
  _volumetric_strain[_qp] = 0;
  _volumetric_strain_rate[_qp] = 0;
  _mixture_compressibility[_qp] = _mixture_compressibility_param;

  // TODO: deal with sign of _slope_yield_surface properly in DP case
  switch (_yield_criterion)
  {
  case modified_Cam_Clay:
    if (_slope_yield_surface == 0)
      mooseError("modified Cam-Clay cannot deal with 0 CSL slope ('slope_yield_surface')");
    if (getYieldStress(0) <= 0)
      mooseError("modified Cam-Clay cannot deal with negative pre-consolidation stress ('yield_stress')");
    break;
  default:
    ;
  }

}

void
RedbackMechMaterial::computeProperties()
{
  computeStrain();
  for (_qp = 0; _qp < _qrule->n_points(); ++_qp)
  {
    computeQpElasticityTensor();
    computeQpStress();
  }
}

void RedbackMechMaterial::computeQpElasticityTensor()
{
  // Fill in the matrix stiffness material property
  _elasticity_tensor[_qp] = _Cijkl;
  _Jacobian_mult[_qp] = _Cijkl;
}

void RedbackMechMaterial::computeStrain()
{
  //Method from Rashid, 1993
  std::vector<RankTwoTensor> Fhat;
  Fhat.resize(_qrule->n_points());
  RankTwoTensor ave_Fhat;
  Real volume(0);
  Real ave_dfgrd_det;

  ave_dfgrd_det=0.0;
  for (_qp = 0; _qp < _qrule->n_points(); ++_qp)
  {
    //Deformation gradient
    RankTwoTensor A(_grad_disp_x[_qp], _grad_disp_y[_qp], _grad_disp_z[_qp]); //Deformation gradient
    RankTwoTensor Fbar(_grad_disp_x_old[_qp], _grad_disp_y_old[_qp], _grad_disp_z_old[_qp]); //Old Deformation gradient

    _dfgrd[_qp] = A;
    _dfgrd[_qp].addIa(1.0);//Gauss point deformation gradient

    A -= Fbar; //A = gradU - gradUold

    Fbar.addIa(1.0); //Fbar = ( I + gradUold)

    //Incremental deformation gradient Fhat = I + A Fbar^-1
    Fhat[_qp] = A * Fbar.inverse();
    Fhat[_qp].addIa(1.0);

    //Calculate average Fhat for volumetric locking correction
    ave_Fhat += Fhat[_qp] * _JxW[_qp];
    volume += _JxW[_qp];

    ave_dfgrd_det += _dfgrd[_qp].det() * _JxW[_qp]; //Average deformation gradient
  }

  ave_Fhat /= volume; //This is needed for volumetric locking correction
  ave_dfgrd_det /=volume; //Average deformation gradient

  for (_qp = 0; _qp < _qrule->n_points(); ++_qp)
  {
    Real factor( std::pow( ave_Fhat.det() / Fhat[_qp].det(), 1.0/3.0));
    Fhat[_qp] *= factor; //Finalize volumetric locking correction

    computeQpStrain(Fhat[_qp]);

    factor = std::pow(ave_dfgrd_det / _dfgrd[_qp].det(), 1.0/3.0);//Volumetric locking correction
    _dfgrd[_qp] *= factor;//Volumetric locking correction
  }
}

void RedbackMechMaterial::computeQpStrain()
{
  mooseError("Wrong computeQpStrain called in FiniteStrainMaterial");
}

void RedbackMechMaterial::computeQpStress()
{
  RankTwoTensor dp,sig;
  Real p_y, q_y; // volumetric (p) and deviatoric (q) projections of yield stress

  //Obtain previous plastic rate of deformation tensor
  dp=_plastic_strain_old[_qp];

  //Solve J2 plastic constitutive equations based on current strain increment
  //Returns current  stress and plastic rate of deformation tensor

  returnMap(_stress_old[_qp], _strain_increment[_qp], _elasticity_tensor[_qp], dp, sig, p_y, q_y);
  _stress[_qp] = sig;

  //Rotate the stress to the current configuration
  _stress[_qp] = _rotation_increment[_qp] * _stress[_qp] * _rotation_increment[_qp].transpose();

  //Updates current plastic rate of deformation tensor
  _plastic_strain[_qp] = dp;

  //Evaluate and update current equivalent and volumetric plastic strain
  _eqv_plastic_strain[_qp] = std::pow(2.0/3.0,0.5) * dp.L2norm();
  _volumetric_strain[_qp] = dp.trace()/3.0;

  //Calculate elastic strain increment
  RankTwoTensor delta_ee = _strain_increment[_qp]-(_plastic_strain[_qp]-_plastic_strain_old[_qp]);

  //Update elastic strain tensor in intermediate configuration
  _elastic_strain[_qp] = _elastic_strain_old[_qp] + delta_ee;

  //Rotate elastic strain tensor to the current configuration
  _elastic_strain[_qp] = _rotation_increment[_qp] * _elastic_strain[_qp] * _rotation_increment[_qp].transpose();

  //Rotate to plastic rate of deformation tensor the current configuration
  _plastic_strain[_qp] = _rotation_increment[_qp] * _plastic_strain[_qp] * _rotation_increment[_qp].transpose();

  //Update strain in intermediate configuration
  _total_strain[_qp] = _total_strain_old[_qp] + _strain_increment[_qp];

  //Rotate strain to current configuration
  _total_strain[_qp] = _rotation_increment[_qp] * _total_strain[_qp] * _rotation_increment[_qp].transpose();

  //Compute the energy dissipation and the properties declared
  computeRedbackTerms(sig, q_y, p_y);
}

//Delta Function
Real
RedbackMechMaterial::deltaFunc(const unsigned int i, const unsigned int j)
{
  if (i == j)
    return 1.0;
  else
    return 0.0;
}

//Obtain yield stress for a given equivalent plastic strain (input)
Real
RedbackMechMaterial::getYieldStress(const Real eqpe)
{
  unsigned nsize;

  nsize = _yield_stress_vector.size();

  if (_yield_stress_vector[0] > 0.0 || nsize % 2 > 0)//Error check for input inconsitency
    mooseError("Error in yield stress input: Should be a vector with eqv plastic strain and yield stress pair values.\n");

  unsigned int ind = 0;
  Real tol = 1e-8;

  while (ind<nsize)
  {
    if (std::abs(eqpe - _yield_stress_vector[ind]) < tol)
      return _yield_stress_vector[ind+1];

    if (ind + 2 < nsize)
    {
      if (eqpe > _yield_stress_vector[ind] && eqpe < _yield_stress_vector[ind+2])
        return _yield_stress_vector[ind+1] +
          (eqpe - _yield_stress_vector[ind]) /
          (_yield_stress_vector[ind+2] - _yield_stress_vector[ind]) *
          (_yield_stress_vector[ind+3] - _yield_stress_vector[ind+1]);
    }
    else
      return _yield_stress_vector[nsize-1];

    ind += 2;
  }

  return 0.0;
}

Real
RedbackMechMaterial::macaulayBracket(Real val)
{
  if (val > 0.0)
    return val;
  else
    return 0.0;
}

void
RedbackMechMaterial::computeRedbackTerms(RankTwoTensor & sig, Real q_y, Real p_y)
{
  // update velocities
  _solid_velocity[_qp] = RealVectorValue(_dispx_dot[_qp], _dispy_dot[_qp], _dispz_dot[_qp]);// TODO

  RedbackMaterial::computeRedbackTerms();

  // Compute stresses
  _mises_stress[_qp] = getSigEqv(sig);
  _mean_stress[_qp] = sig.trace()/3.0;

  // Compute platic strains
  RankTwoTensor instantaneous_strain_rate = (_plastic_strain[_qp] - _plastic_strain_old[_qp])/_dt;
  _mises_strain_rate[_qp] = std::pow(2.0/3.0,0.5) * instantaneous_strain_rate.L2norm();
  _volumetric_strain_rate[_qp] = instantaneous_strain_rate.trace()/3.0;

  // Compute Mechanical Dissipation. Note that the term of the pore-pressure denotes chemical degradation of the skeleton
  _mechanical_dissipation[_qp] = _gr[_qp]* std::pow(1 - _pore_pres[_qp], _exponent) *sig.doubleContraction(instantaneous_strain_rate);
  //std::cout << "Gr = " << _gr[_qp] << std::endl;
  //std::cout << "PP = " << _pore_pres[_qp] << std::endl;
  //std::cout << "mech_diss = " << _mechanical_dissipation[_qp] << std::endl;
  //std::cout << "eps.sig = " << sig.doubleContraction(instantaneous_strain_rate) << std::endl << std::endl;

  // Compute Mechanical Dissipation Jacobian
  //_mechanical_dissipation_jac[_qp] = _gr[_qp] *
   //   (getSigEqv(sig) * std::pow(1 - _pore_pres[_qp], _exponent) *std::pow( macaulayBracket( getSigEqv(sig) / q_y - 1.0 ), _exponent) +  _mean_stress[_qp] * std::pow( macaulayBracket(_mean_stress[_qp]- p_y), _exponent))*
   //   _ar[_qp]*_delta[_qp] * std::exp( _ar[_qp]*_delta[_qp] *_T[_qp] / (1 + _delta[_qp] *_T[_qp]) ) /
   //   (1 + _delta[_qp] * _T[_qp]) / (1 + _delta[_qp] * _T[_qp]);

  _mechanical_dissipation_jac[_qp] = _mechanical_dissipation[_qp] / (1 + _delta[_qp] * _T[_qp]) / (1 + _delta[_qp] * _T[_qp]);

  // Compute the equivalent Gruntfest number for comparison with SuCCoMBE
  _mod_gruntfest_number[_qp] = _gr[_qp] * std::pow(1 - _pore_pres[_qp], _exponent) *
      (
      std::fabs(getSigEqv(sig) * std::pow( macaulayBracket( getSigEqv(sig) / q_y - 1.0 ), _exponent)) +
      std::fabs(_mean_stress[_qp] * std::pow( macaulayBracket(_mean_stress[_qp] - p_y), _exponent))
      );
  return;
}

void
RedbackMechMaterial::returnMap(const RankTwoTensor & sig_old, const RankTwoTensor & delta_d, const RankFourTensor & E_ijkl, RankTwoTensor & dp, RankTwoTensor & sig, Real & p_y, Real & q_y)
{
  switch (_yield_criterion)
  {
    case elasticity:
      returnMapElasticity(sig_old, delta_d, E_ijkl, dp, sig);
      return;
    case J2_plasticity:
      returnMapJ2(sig_old, delta_d, E_ijkl, dp, sig, p_y, q_y);
      return;
    case Drucker_Prager:
      returnMapDP(sig_old, delta_d, E_ijkl, dp, sig, p_y, q_y);
      return;
    case modified_Cam_Clay:
      returnMapCC(sig_old, delta_d, E_ijkl, dp, sig, p_y, q_y);
      return;
    default:
      mooseError("returnMap called with unknown yield_criterion of " << _yield_criterion);
  }
}



void
RedbackMechMaterial::computeQpStrain(const RankTwoTensor & Fhat)
{
  //Cinv - I = A A^T - A - A^T;
  RankTwoTensor A; //A = I - Fhatinv
  A.addIa(1.0);
  A -= Fhat.inverse();
  RankTwoTensor Cinv_I = A*A.transpose() - A - A.transpose();

  //strain rate D from Taylor expansion, Chat = (-1/2(Chat^-1 - I) + 1/4*(Chat^-1 - I)^2 + ...
  _strain_increment[_qp] = -Cinv_I*0.5 + Cinv_I*Cinv_I*0.25;

  // thermo-elasticity
  _strain_increment[_qp].addIa(-_solid_thermal_expansion[_qp]*(_T[_qp] - _T_old[_qp]));

  /*RankTwoTensor Chat = Fhat.transpose()*Fhat;
  RankTwoTensor A = Chat;
  A.addIa(-1.0);

  RankTwoTensor B = Chat*0.25;
  B.addIa(-0.75);
  _strain_increment[_qp] = -B*A;*/

  RankTwoTensor D = _strain_increment[_qp]/_t_step;
  _strain_rate[_qp] = D;

  //Calculate rotation R_incr
  RankTwoTensor invFhat(Fhat.inverse());

  std::vector<Real> a(3);
  a[0] = invFhat(1,2) - invFhat(2,1);
  a[1] = invFhat(2,0) - invFhat(0,2);
  a[2] = invFhat(0,1) - invFhat(1,0);
  Real q = (a[0]*a[0] + a[1]*a[1] + a[2]*a[2])/4.0;
  Real trFhatinv_1 = invFhat.trace() - 1.0;
  Real p = trFhatinv_1*trFhatinv_1/4.0;
  // Real y = 1.0/((q + p)*(q + p)*(q + p));

  /*Real C1 = std::sqrt(p * (1 + (p*(q+q+(q+p))) * (1-(q+p)) * y));
  Real C2 = 0.125 + q * 0.03125 * (p*p - 12*(p-1)) / (p*p);
  Real C3 = 0.5 * std::sqrt( (p*q*(3-q) + p*p*p + q*q)*y );
  */

  Real C1 = std::sqrt(p + 3.0*p*p*(1.0 - (p + q))/((p+q)*(p+q)) - 2.0*p*p*p*(1-(p+q))/((p+q)*(p+q)*(p+q))); //cos theta_a
  Real C2 = 0.0;
  if (q > 0.01)
    C2 = (1.0 - C1)/(4.0*q); // (1-cos theta_a)/4q
  else //alternate form for small q
    C2 = 0.125 + q*0.03125*(p*p - 12*(p-1))/(p*p) + q*q*(p - 2.0)*(p*p - 10.0*p + 32.0)/(p*p*p) + q*q*q*(1104.0 - 992.0*p + 376.0*p*p - 72*p*p*p + 5.0*p*p*p*p)/(512.0*p*p*p*p);

  Real C3 = 0.5*std::sqrt((p*q*(3.0 - q) + p*p*p + q*q)/((p + q)*(p + q)*(p + q))); //sin theta_a/(2 sqrt(q))

  //Calculate incremental rotation. Note that this value is the transpose of that from Rashid, 93, so we transpose it before storing
  RankTwoTensor R_incr;
  R_incr.addIa(C1);
  for (unsigned int i=0; i<3; ++i)
    for (unsigned int j = 0; j < 3; ++j)
      R_incr(i,j) += C2*a[i]*a[j];

  R_incr(0,1) += C3*a[2];
  R_incr(0,2) -= C3*a[1];
  R_incr(1,0) -= C3*a[2];
  R_incr(1,2) += C3*a[0];
  R_incr(2,0) += C3*a[1];
  R_incr(2,1) -= C3*a[0];
  _rotation_increment[_qp] = R_incr.transpose();
}

Real
RedbackMechMaterial::getSigEqv(const RankTwoTensor & stress)
{
  return std::pow(3*stress.secondInvariant(), 0.5);
}

/* *********************************************************************************************************************************************************************************************************************************
 * *********************************************************************************************************************************************************************************************************************************
 * ***************Beginning of yield criterion specific code************************************************************************************************************************************************************************
 * *********************************************************************************************************************************************************************************************************************************
 * **********************************************************************************************************************************************************************************************************************************/
void
RedbackMechMaterial::returnMapElasticity(const RankTwoTensor & sig_old, const RankTwoTensor & delta_d, const RankFourTensor & E_ijkl, RankTwoTensor & dp, RankTwoTensor & sig)
{
  sig = sig_old + E_ijkl * delta_d;
  dp = RankTwoTensor(); //Plastic rate of deformation tensor in unrotated configuration
}

void
RedbackMechMaterial::returnMapJ2(const RankTwoTensor & sig_old, const RankTwoTensor & delta_d, const RankFourTensor & E_ijkl, RankTwoTensor & dp, RankTwoTensor & sig, Real & p_y, Real & q_y)
{
  RankTwoTensor sig_new, delta_dp, dpn;
  RankTwoTensor flow_tensor;
  RankTwoTensor resid,ddsig;
  RankFourTensor dr_dsig, dr_dsig_inv;
  Real flow_incr_dev;
  Real err1, err3, tol1, tol3;
  unsigned int iterisohard, iter, maxiterisohard = 20, maxiter = 50;
  Real eqvpstrain;
  Real yield_stress, yield_stress_prev;

  tol1 = 1e-15; // TODO: expose to user interface and/or make the tolerance relative
  tol3 = 1e-10; // TODO: expose to user interface and/or make the tolerance relative

  iterisohard = 0;
  eqvpstrain = std::pow(2.0/3.0,0.5) * dp.L2norm();
  yield_stress = getYieldStress(eqvpstrain);

  //TODO: checking whether in plasticity
  /*if (getSigEqv(sig_old) < yield_stress)
  {
    sig = sig_old;
    p_y = 1e99; // irrelevant (no plasticity)
    q_y = 1e99; // irrelevant (no plasticity)
    return; // in this case we are in elasticity. dp is left unchanged
  }*/

  err3 = 1.1 * tol3;

  _exponential = 1;
  if (_has_T)
  {
    _exponential = std::exp(-_ar[_qp])* std::exp(_ar[_qp]*_delta[_qp] *_T[_qp]/(1 + _delta[_qp] *_T[_qp]));
  }

  while (err3 > tol3 && iterisohard < maxiterisohard) //Hardness update iteration
  {
    iterisohard++;
    iter = 0;
    delta_dp.zero();

    sig_new = sig_old + E_ijkl * delta_d;

    flow_incr_dev = getFlowIncrementJ2(sig_new, yield_stress);
    getFlowTensorJ2(sig_new, yield_stress, flow_tensor); // flow increment and flow direction combined
    flow_tensor *= flow_incr_dev;

    resid = flow_tensor - delta_dp;

    err1 = resid.L2norm();

    while (err1 > tol1  && iter < maxiter) //Stress update iteration (hardness fixed)
    {
      iter++;

      getJacJ2(sig_new, E_ijkl, flow_incr_dev, yield_stress, dr_dsig); //Jacobian = d(residual)/d(sigma)

      dr_dsig_inv = dr_dsig.invSymm();

      ddsig = -dr_dsig_inv * resid; // Newton Raphson

      sig_new += ddsig; //Update stress
      delta_dp -= E_ijkl.invSymm() * ddsig; //Update increment of plastic rate of deformation tensor

      flow_incr_dev = getFlowIncrementJ2(sig_new, yield_stress);
      if (flow_incr_dev < 0.0) //negative flow increment not allowed
        mooseError("Constitutive Error-Negative flow increment: Reduce time increment.");
      //TODO: check if we need to update the flow tensor
      getFlowTensorJ2(sig_new, yield_stress, flow_tensor); // flow increment and flow direction combined
      flow_tensor *= flow_incr_dev;

      resid = flow_tensor - delta_dp; //Residual
      err1=resid.L2norm();
    }

    if (iter>=maxiter)//Convergence failure
      mooseError("Constitutive Error-Too many iterations: Reduce time increment.\n"); //Convergence failure //TODO: check the adaptive time stepping

    dpn = dp + delta_dp;
    eqvpstrain = std::pow(2.0/3.0, 0.5) * dpn.L2norm();

    yield_stress_prev = yield_stress;
    yield_stress = getYieldStress(eqvpstrain);

    err3 = std::abs(yield_stress-yield_stress_prev);
  }

  if (iterisohard>=maxiterisohard)
    mooseError("Constitutive Error-Too many iterations in Hardness Update:Reduce time increment.\n"); //Convergence failure

  dp = dpn; //Plastic rate of deformation tensor in unrotated configuration
  sig = sig_new;
  q_y = yield_stress;
  p_y = sig.trace()/3.0;
}

/**
 * Compute pressure projection of stress on Drucker-Prager yield surface
 */
Real
RedbackMechMaterial::getPressureProjectionDP(Real pressure, Real sig_eqv, Real cohesion)
{
  // yield pressure, for non-associative, replace mu^2 with mu*dilatency
  // the "fmin" is to handle the apex. Apparently fmin(1/0, x) = x, so it's always true
  //return fmin(-cohesion/_slope_yield_surface, (pressure + _slope_yield_surface*(sig_eqv - cohesion))
  //    / (1.0 + (_slope_yield_surface) * (_slope_yield_surface)));

  if (_slope_yield_surface == 0)
    return pressure;
  else if (_slope_yield_surface < 0)
    return fmin(-cohesion/_slope_yield_surface, (pressure + _slope_yield_surface*(sig_eqv - cohesion))
        / (1.0 + (_slope_yield_surface) * (_slope_yield_surface)));
  else
  {
    // _slope_yield_surface > 0, for whatever reason...
    return fmax(-cohesion/_slope_yield_surface, (pressure + _slope_yield_surface*(sig_eqv - cohesion))
        / (1.0 + (_slope_yield_surface) * (_slope_yield_surface)));
  }
}

/**
 * returnMap for Drucker Prager
 */
void
RedbackMechMaterial::returnMapDP(const RankTwoTensor & sig_old, const RankTwoTensor & delta_d, const RankFourTensor & E_ijkl, RankTwoTensor & dp, RankTwoTensor & sig, Real & p_y, Real & q_y)
{
  RankTwoTensor sig_new, delta_dp, dpn;
  RankTwoTensor flow_tensor;
  RankTwoTensor resid,ddsig;
  RankFourTensor dr_dsig, dr_dsig_inv;
  Real flow_incr;
  Real pressure, sig_eqv;
  Real err1, err3, tol1, tol3;
  unsigned int iterisohard, iter, maxiterisohard = 20, maxiter = 50;
  Real eqvpstrain;
  Real cohesion, cohesion_prev;

  tol1 = 1e-10;
  tol3 = 1e-6;

  iterisohard = 0;
  eqvpstrain = std::pow(2.0/3.0,0.5) * dp.L2norm();
  // User defined yield stress is the cohesion only (evolving with plastic strain)
  cohesion = getYieldStress(eqvpstrain);

  err3 = 1.1 * tol3;

  _exponential = 1;
  if (_has_T)
  {
    _exponential = std::exp(-_ar[_qp])* std::exp(_ar[_qp]*_delta[_qp] *_T[_qp]/(1 + _delta[_qp] *_T[_qp]));
  }

  while (err3 > tol3 && iterisohard < maxiterisohard) //Hardness update iteration
  {
    iterisohard++;
    iter = 0;
    delta_dp.zero();

    sig_new = sig_old + E_ijkl * delta_d;

    // Compute distance to current yield surface (line), only valid for associative potential
    pressure = sig_new.trace()/3.0;
    sig_eqv = getSigEqv(sig_new);
    p_y = getPressureProjectionDP(pressure, sig_eqv, cohesion);
    q_y = cohesion + _slope_yield_surface * p_y; // yield deviatoric stress

    /*// TODO checking whether in plasticity
    if (sig_eqv < q_y)
    {
      sig = sig_new;
      return; // in this case we are in elasticity. dp is left unchanged
    }*/

    // trying normalizing with the norm of the total vector
    flow_incr = getFlowIncrementDP(sig_eqv, pressure, q_y, p_y);
    getFlowTensorDP(sig_new, sig_eqv, flow_tensor);

    flow_tensor = flow_incr*flow_tensor;

    resid = flow_tensor - delta_dp;

    err1 = resid.L2norm();
    //TODO: do not compute flow tensor if in elasticity

    while (err1 > tol1  && iter < maxiter) //Stress update iteration (hardness fixed)
    {
      iter++;

      getJacDP(sig_new, E_ijkl, sig_eqv, pressure, p_y, q_y, dr_dsig); //Jacobian = d(residual)/d(sigma)

      dr_dsig_inv = dr_dsig.invSymm();

      ddsig = -dr_dsig_inv * resid; // Newton Raphson

      sig_new += ddsig; //Update stress
      pressure = sig_new.trace()/3.0;
      sig_eqv = getSigEqv(sig_new);
      p_y = getPressureProjectionDP(pressure, sig_eqv, cohesion);
      q_y = cohesion + _slope_yield_surface * p_y; // yield deviatoric stress

      delta_dp -= E_ijkl.invSymm() * ddsig; //Update increment of plastic rate of deformation tensor

      flow_incr = getFlowIncrementDP(sig_eqv, pressure, q_y, p_y);
      if (flow_incr < 0.0) //negative flow increment not allowed
        mooseError("Constitutive Error-Negative flow increment Drucker-Prager: Reduce time increment.");
      getFlowTensorDP(sig_new, sig_eqv, flow_tensor);

      flow_tensor = flow_incr*flow_tensor;

      resid = flow_tensor - delta_dp; //Residual

      err1=resid.L2norm();
    }

    if (iter>=maxiter)//Convergence failure
      mooseError("Constitutive Error-Too many iterations: Reduce time increment.\n"); //Convergence failure

    dpn = dp + delta_dp;
    eqvpstrain = std::pow(2.0/3.0, 0.5) * dpn.L2norm();

    cohesion_prev = cohesion;
    cohesion = getYieldStress(eqvpstrain);

    err3 = std::abs(cohesion-cohesion_prev);
  }

  if (iterisohard>=maxiterisohard)
    mooseError("Constitutive Error-Too many iterations in Hardness Update:Reduce time increment.\n"); //Convergence failure

  dp = dpn; //Plastic rate of deformation tensor in unrotated configuration
  sig = sig_new;
}

void
RedbackMechMaterial::returnMapCC(const RankTwoTensor & sig_old, const RankTwoTensor & delta_d, const RankFourTensor & E_ijkl, RankTwoTensor & dp, RankTwoTensor & sig, Real & p_y, Real & q_y)
{
  RankTwoTensor sig_new, delta_dp, dpn;
  RankTwoTensor flow_tensor;
  RankTwoTensor resid,ddsig;
  RankFourTensor dr_dsig, dr_dsig_inv;
  Real flow_incr;
  Real pressure, sig_eqv;
  Real err1, err3, tol1, tol3;
  unsigned int iterisohard, iter, maxiterisohard = 20, maxiter = 50;
  Real eqvpstrain;
  Real pc, pc_prev, distance_pq;
  //bool is_plastic;

  tol1 = 1e-10;
  tol3 = 1e-6;

  iterisohard = 0;
  eqvpstrain = std::pow(2.0/3.0,0.5) * dp.L2norm();
  // User defined yield stress is the cohesion only (evolving with plastic strain)
  pc = -getYieldStress(eqvpstrain); // pre-consolidation stress (warning: negative!)
  // _slope_yield_surface is slope "M" of the critical state line

  err3 = 1.1 * tol3;

  _exponential = 1;
  if (_has_T)
  {
    _exponential = std::exp(-_ar[_qp])* std::exp(_ar[_qp]*_delta[_qp] *_T[_qp]/(1 + _delta[_qp] *_T[_qp]));
  }

  while (err3 > tol3 && iterisohard < maxiterisohard) //Hardness update iteration
  {
    iterisohard++;
    iter = 0;
    delta_dp.zero();

    sig_new = sig_old + E_ijkl * delta_d;

    // Compute distance to current yield surface (line), only valid for associative potential
    pressure = sig_new.trace()/3.0;
    sig_eqv = getSigEqv(sig_new);
    //is_plastic = Ellipse::isPointOutsideOfEllipse(_slope_yield_surface, pc, pressure, sig_eqv);
    distance_pq = Ellipse::distanceCC(_slope_yield_surface, pc, pressure, sig_eqv, p_y, q_y);

    /*std::cout << "pressure = " << pressure << std::endl;
    std::cout << "sig_eqv  = " << sig_eqv << std::endl;
    std::cout << "M        = " << _slope_yield_surface << std::endl;
    std::cout << "p_c      = " << pc << std::endl<< std::endl;
    std::cout << "p_y      = " << p_y << std::endl;
    std::cout << "q_y      = " << q_y << std::endl<< std::endl;*/

    /*// TODO checking whether in plasticity
    if (sig_eqv < q_y)
    {
      sig = sig_new;
      return; // in this case we are in elasticity. dp is left unchanged
    }*/

    // trying normalizing with the norm of the total vector
    flow_incr = getFlowIncrementCC(sig_eqv, pressure, pc, q_y, p_y);
    getFlowTensorCC(sig_new, pc, pressure, flow_tensor);

    flow_tensor = flow_incr*flow_tensor;

    resid = flow_tensor - delta_dp;

    err1 = resid.L2norm();
    //std::cout << "first err1=" << err1 <<std::endl;
    //TODO: do not compute flow tensor if in elasticity

    while (err1 > tol1  && iter < maxiter) //Stress update iteration (hardness fixed)
    {
      iter++;

      getJacCC(sig_new, E_ijkl, sig_eqv, pressure, pc, p_y, q_y, dr_dsig); //Jacobian = d(residual)/d(sigma)

      dr_dsig_inv = dr_dsig.invSymm();

      ddsig = -dr_dsig_inv * resid; // Newton Raphson

      sig_new += ddsig; //Update stress
      pressure = sig_new.trace()/3.0;
      sig_eqv = getSigEqv(sig_new);
      distance_pq = Ellipse::distanceCC(_slope_yield_surface, pc, pressure, sig_eqv, p_y, q_y);

      delta_dp -= E_ijkl.invSymm() * ddsig; //Update increment of plastic rate of deformation tensor

      flow_incr = getFlowIncrementCC(sig_eqv, pressure, pc, q_y, p_y);
      if (flow_incr < 0.0) //negative flow increment not allowed
        mooseError("Constitutive Error-Negative flow increment Drucker-Prager: Reduce time increment.");
      getFlowTensorCC(sig_new, pc, pressure, flow_tensor);

      flow_tensor = flow_incr*flow_tensor;

      resid = flow_tensor - delta_dp; //Residual

      err1=resid.L2norm();
      //std::cout << "err1=" << err1<< " at iter=" << iter <<std::endl;
    }
    //std::cout << "err1=" << err1<< " at iter=" << iter <<std::endl;
    if (iter>=maxiter)//Convergence failure
      mooseError("Constitutive Error-Too many iterations: Reduce time increment.\n"); //Convergence failure

    dpn = dp + delta_dp;
    eqvpstrain = std::pow(2.0/3.0, 0.5) * dpn.L2norm();

    pc_prev = pc;
    pc = -getYieldStress(eqvpstrain); // pre-consolidation stress (warning: negative!)

    err3 = std::abs(pc-pc_prev);
  }

  if (iterisohard>=maxiterisohard)
    mooseError("Constitutive Error-Too many iterations in Hardness Update:Reduce time increment.\n"); //Convergence failure

  dp = dpn; //Plastic rate of deformation tensor in unrotated configuration
  sig = sig_new;
}

/**
 * Get unitary flow tensor in deviatoric direction, J2 plasticity. It only has a deviatoric part
 */
void
RedbackMechMaterial::getFlowTensorJ2(const RankTwoTensor & sig, Real yield_stress, RankTwoTensor & flow_tensor_dev)
{
  RankTwoTensor sig_dev;
  Real sig_eqv, val;

  sig_dev = sig.deviatoric();
  sig_eqv = getSigEqv(sig);
  val = 0.0;
  if (sig_eqv > 1e-8)
    val = 3.0 / (2.0 * sig_eqv);
  flow_tensor_dev = sig_dev * val;
  //flow_tensor_dev /= flow_tensor_dev.L2norm();
  // TODO: norm is actually sqrt(3/2)
}

void
RedbackMechMaterial::getFlowTensorDP(const RankTwoTensor & sig, Real sig_eqv, RankTwoTensor & flow_tensor)
{
  RankTwoTensor sig_dev;
  Real val, pressure;

  sig_dev = sig.deviatoric();
  pressure = sig.trace()/3.0;
  val = 0.0;
  if (sig_eqv > 1e-8)
    val = 3.0 / (2.0 * sig_eqv);
  flow_tensor = sig_dev * val;
  flow_tensor.addIa(-_slope_yield_surface*(pressure > 0 ? 1:-1)/3.0); //(pressure > 0 ? 1:-1) is the sign function
  flow_tensor /= std::pow(2.0/3.0,0.5)*flow_tensor.L2norm();
  //flow_tensor /= std::pow(2.0/3.0,0.5)*flow_tensor.L2norm(); // TODO: debugging, returning a tensor of norm sqrt(3/2) to match the J2 case
}

/**
 * Get unitary flow tensor in deviatoric direction, modified Cam-Clay
 */
void
RedbackMechMaterial::getFlowTensorCC(const RankTwoTensor & sig, Real pc, Real pressure, RankTwoTensor & flow_tensor)
{
  flow_tensor = 3.0*sig.deviatoric()/(_slope_yield_surface*_slope_yield_surface);
  flow_tensor.addIa((2.0*pressure - pc)/3.0); //(pressure > 0 ? 1:-1)

  //flow_tensor /= std::pow(2.0/3.0,0.5)*flow_tensor.L2norm(); // TODO: do we need to normalise? If so, do we need the sqrt(3/2) factor?
}

/**
 * Compute the flow incrmement for modified Cam-Clay
 */
Real
RedbackMechMaterial::getFlowIncrementCC(Real sig_eqv, Real pressure, Real pc, Real q_yield_stress, Real p_yield_stress)
{
  if (Ellipse::isPointOutsideOfEllipse(/*m=*/_slope_yield_surface, /*p_c=*/pc, /*x=*/pressure, /*y=*/sig_eqv))
  {
    Real flow_incr_vol = _ref_pe_rate * _dt * std::pow(std::fabs(pressure - p_yield_stress), _exponent) * _exponential;
    Real flow_incr_dev = _ref_pe_rate * _dt * std::pow(std::fabs(sig_eqv - q_yield_stress), _exponent) * _exponential;
    return std::pow(flow_incr_vol * flow_incr_vol + flow_incr_dev * flow_incr_dev, 0.5);
  }
  else
    return 0;
}

/**
 * Compute flow increment for Drucker-Prager case
 */
Real
RedbackMechMaterial::getFlowIncrementDP(Real sig_eqv, Real pressure, Real q_yield_stress, Real p_yield_stress)
{
  Real flow_incr_vol = _ref_pe_rate * _dt * std::pow(macaulayBracket(pressure - p_yield_stress), _exponent) * _exponential;
  // TODO: q_yield_stress can be 0, we should handle that case properly...
  Real flow_incr_dev = _ref_pe_rate * _dt * std::pow(macaulayBracket((q_yield_stress > 0 ? 1:-1)*(sig_eqv / q_yield_stress - 1.0)), _exponent)* _exponential; //(q_yield_stress > 0 ? 1:-1) is the sign function
  return std::pow(flow_incr_vol * flow_incr_vol + flow_incr_dev * flow_incr_dev, 0.5);
  // TODO: change the formula to use dist_pq^m
}

Real
RedbackMechMaterial::getFlowIncrementJ2(const RankTwoTensor & sig, Real yield_stress)
{
  return _ref_pe_rate * _dt * std::pow(macaulayBracket(getSigEqv(sig) / yield_stress - 1.0), _exponent) * _exponential;
}

/**
 * Derivative of getFlowIncrement with respect to equivalent stress, only has deviatoric component in J2 plasiticity
 */
Real
RedbackMechMaterial::getDerivativeFlowIncrementJ2(const RankTwoTensor & sig, Real yield_stress)
{
  // Derivative of getFlowIncrement with respect to equivalent stress
  return _ref_pe_rate * _dt * _exponent * std::pow(macaulayBracket(getSigEqv(sig) / yield_stress - 1.0), _exponent - 1.0) * _exponential / yield_stress;
}

Real
RedbackMechMaterial::getDerivativeFlowIncrementDP(const RankTwoTensor & sig, Real pressure, Real sig_eqv, Real q_yield_stress, Real p_yield_stress)
{
  Real delta_lambda_p = _ref_pe_rate * _dt * std::pow(macaulayBracket(pressure - p_yield_stress), _exponent) * _exponential;
  Real delta_lambda_q = _ref_pe_rate * _dt * std::pow(macaulayBracket((q_yield_stress > 0 ? 1:-1)*(sig_eqv / q_yield_stress - 1.0)), _exponent) * _exponential;
  Real delta_lambda = (std::pow(delta_lambda_p * delta_lambda_p + delta_lambda_q * delta_lambda_q, 0.5));
  Real der_flow_incr_dev = _ref_pe_rate * _dt * _exponent * std::pow(macaulayBracket((q_yield_stress > 0 ? 1:-1)*(sig_eqv / q_yield_stress - 1.0)), _exponent - 1.0) * _exponential / q_yield_stress;
  Real der_flow_incr_vol = _ref_pe_rate * _dt * _exponent * std::pow(macaulayBracket(pressure - p_yield_stress), _exponent - 1.0) * _exponential;
  return (delta_lambda_q * der_flow_incr_dev + delta_lambda_p * der_flow_incr_vol) / delta_lambda;
}

Real
RedbackMechMaterial::getDerivativeFlowIncrementCC(const RankTwoTensor & sig, Real pressure, Real sig_eqv, Real pc, Real q_yield_stress, Real p_yield_stress)
{
  if (Ellipse::isPointOutsideOfEllipse(/*m=*/_slope_yield_surface, /*p_c=*/pc, /*x=*/pressure, /*y=*/sig_eqv))
  {
    Real delta_lambda_p = _ref_pe_rate * _dt * std::pow(std::fabs(pressure - p_yield_stress), _exponent) * _exponential;
    Real delta_lambda_q = _ref_pe_rate * _dt * std::pow(std::fabs(sig_eqv - q_yield_stress), _exponent) * _exponential;
    Real delta_lambda = (std::pow(delta_lambda_p * delta_lambda_p + delta_lambda_q * delta_lambda_q, 0.5));
    Real der_flow_incr_dev = _ref_pe_rate * _dt * _exponent * std::pow(std::fabs(sig_eqv - q_yield_stress), _exponent - 1.0) * _exponential;
    Real der_flow_incr_vol = _ref_pe_rate * _dt * _exponent * std::pow(std::fabs(pressure - p_yield_stress), _exponent - 1.0) * _exponential;
    return (delta_lambda_q * der_flow_incr_dev + delta_lambda_p * der_flow_incr_vol) / delta_lambda;
  }
  else
    return 0;
}

//Jacobian for stress update algorithm
void
RedbackMechMaterial::getJacJ2(const RankTwoTensor & sig, const RankFourTensor & E_ijkl, Real flow_incr_dev, Real yield_stress, RankFourTensor & dresid_dsig)
{
  unsigned i, j, k ,l;
  RankTwoTensor sig_dev, flow_dirn_dev, fij;
  RankTwoTensor dfi_dft;
  RankFourTensor dft_dsig, dfd_dft, dfd_dsig, dfi_dsig;
  Real sig_eqv;
  Real f1, f2, f3;
  Real dfi_dseqv_dev;

  sig_dev = sig.deviatoric();
  sig_eqv = getSigEqv(sig);

  getFlowTensorJ2(sig, yield_stress, flow_dirn_dev);
  dfi_dseqv_dev = getDerivativeFlowIncrementJ2(sig, yield_stress);

  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfi_dsig(i,j,k,l) = flow_dirn_dev(i,j) * flow_dirn_dev(k,l) * dfi_dseqv_dev; //d_flow_increment/d_sig

  f1 = 0.0;
  f2 = 0.0;
  f3 = 0.0;

  if (sig_eqv > 1e-8)
  {
    f1 = 3.0 / (2.0 * sig_eqv);
    f2 = f1 / 3.0;
    f3 = 9.0 / (4.0 * std::pow(sig_eqv, 3.0));
  }

  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dft_dsig(i,j,k,l) = f1 * deltaFunc(i,k) * deltaFunc(j,l) - f2 * deltaFunc(i,j) * deltaFunc(k,l) - f3 * sig_dev(i,j) * sig_dev(k,l); //d_flow_dirn/d_sig - 2nd part

  dfd_dsig = dft_dsig; //d_flow_dirn/d_sig
  dresid_dsig = E_ijkl.invSymm() + dfd_dsig * flow_incr_dev + dfi_dsig; //Jacobian
}

void
RedbackMechMaterial::getJacDP(const RankTwoTensor & sig, const RankFourTensor & E_ijkl,
    Real sig_eqv, Real pressure, Real p_yield_stress, Real q_yield_stress,
    RankFourTensor & dresid_dsig)
{
  unsigned i, j, k ,l;
  RankTwoTensor sig_dev, fij, flow_dirn, flow_tensor;
  RankTwoTensor dfi_dft;
  RankFourTensor dft_dsig1, /*dft_dsig2,*/ dfd_dft, dfd_dsig, dfi_dsig;
  Real f1, f2, f3, flow_incr;
  Real dfi_dseqv_dev, dfi_dseqv_vol, dfi_dseqv;

  sig_dev = sig.deviatoric();

  flow_incr = getFlowIncrementDP(sig_eqv, pressure, q_yield_stress, p_yield_stress); // TODO: should pass it instead of recalculating it...

  dfi_dseqv = getDerivativeFlowIncrementDP(sig, pressure, sig_eqv, q_yield_stress, p_yield_stress);
  getFlowTensorDP(sig, sig_eqv, flow_dirn);

  /* The following calculates the tensorial derivative (Jacobian) of the residual with respect to stress, dr_dsig
   * It consists of two terms: The first is
   * dr_dsig = (dfi_dseqv_dev*flow_dirn_dev(k,l)) * flow_dirn_dev(i,j)
   * which is the tensorial product of the flow increment tensor times the flow direction tensor
   *
   * The second is the product of the flow increment tensor times the derivative of the flow direction tensor
   * with respect to the stress tensor. See also REDBACK's documentation
   * */

  // This loop calculates the first term
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfi_dsig(i,j,k,l) = flow_dirn(i,j) * flow_dirn(k,l) * dfi_dseqv;

  Real flow_tensor_norm = flow_dirn.L2norm();

  // This loop calculates the second term. Read REDBACK's documentation
  // (same as J2 plasticity case)
  f1 = 0.0;
  f2 = 0.0;
  f3 = 0.0;
  if (sig_eqv > 1e-8)
  {
    f1 = 3.0 / (2.0 * sig_eqv);
    f2 = f1 / 3.0;
    f3 = 9.0 / (4.0 * std::pow(sig_eqv, 3.0));
  }
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dft_dsig1(i,j,k,l) = f1 * deltaFunc(i,k) * deltaFunc(j,l) - f2 * deltaFunc(i,j) * deltaFunc(k,l) - f3 * sig_dev(i,j) * sig_dev(k,l); //d_flow_dirn/d_sig - 2nd part (J2 plasticity)
          //dft_dsig2(i,j,k,l) = flow_tensor(i,j)*flow_tensor(k,l);

  //dfd_dsig = dft_dsig1/flow_tensor_norm - 3.0 * dft_dsig2 / (2*sig_eqv*flow_tensor_norm*flow_tensor_norm*flow_tensor_norm); //d_flow_dirn/d_sig
  //TODO: check if the previous two lines (i.e normalizing the flow vector) should be activated or not. Currently we are using the non-unitary flow vector

  dfd_dsig = dft_dsig1; //d_flow_dirn/d_sig
  dresid_dsig = E_ijkl.invSymm() + dfd_dsig * flow_incr + dfi_dsig; //Jacobian
}

void
RedbackMechMaterial::getJacCC(const RankTwoTensor & sig, const RankFourTensor & E_ijkl,
    Real sig_eqv, Real pressure, Real pc, Real p_yield_stress, Real q_yield_stress,
    RankFourTensor & dresid_dsig)
{
  unsigned i, j, k ,l;
  RankTwoTensor sig_dev, flow_dirn_vol, flow_dirn_dev, fij, flow_dirn, flow_tensor;
  RankTwoTensor dfi_dft;
  RankFourTensor dfd_dsig, dfi_dsig;
  Real f1, f2, flow_incr;
  Real dfi_dseqv_dev, dfi_dseqv_vol, dfi_dseqv;

  sig_dev = sig.deviatoric();

  flow_incr = getFlowIncrementCC(sig_eqv, pressure, pc, q_yield_stress, p_yield_stress);

  dfi_dseqv = getDerivativeFlowIncrementCC(sig, pressure, sig_eqv, pc, q_yield_stress, p_yield_stress);

  getFlowTensorCC(sig, pc, pressure, flow_dirn);

  /* The following calculates the tensorial derivative (Jacobian) of the residual with respect to stress, dr_dsig
   * It consists of two terms: The first is
   * dr_dsig = (dfi_dseqv_dev*flow_dirn_dev(k,l)) * flow_dirn_dev(i,j)
   * which is the tensorial product of the flow increment tensor times the flow direction tensor
   *
   * The second is the product of the flow increment tensor times the derivative of the flow direction tensor
   * with respect to the stress tensor. See also REDBACK's documentation
   * */

  // This loop calculates the first term
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfi_dsig(i,j,k,l) = flow_dirn(i,j) * flow_dirn(k,l) * dfi_dseqv;

  //Real flow_tensor_norm = flow_dirn.L2norm();

  // This loop calculates the second term. Read REDBACK's documentation
  // (same as J2 plasticity case)
  f1 = 0.0;
  f2 = 0.0;
  if (sig_eqv > 1e-8)
  {
    f1 = 3.0 / (_slope_yield_surface * _slope_yield_surface);
    f2 = 2.0 /3.0 - 1.0 / (_slope_yield_surface * _slope_yield_surface);
  }
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfd_dsig(i,j,k,l) = f1 * deltaFunc(i,k) * deltaFunc(j,l) - f2 * deltaFunc(i,j) * deltaFunc(k,l); //d_flow_dirn/d_sig - 2nd part (J2 plasticity)

  //dfd_dsig = dft_dsig1/flow_tensor_norm - 3.0 * dft_dsig2 / (2*sig_eqv*flow_tensor_norm*flow_tensor_norm*flow_tensor_norm); //d_flow_dirn/d_sig
  //TODO: check if the previous two lines (i.e normalizing the flow vector) should be activated or not. Currently we are using the non-unitary flow vector

  dresid_dsig = E_ijkl.invSymm() + dfd_dsig * flow_incr + dfi_dsig; //Jacobian
}
