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
  params.addParam< Real >("slope_yield_surface", 0,"Slope of yield surface (see documentation)");

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
  _volumetric_strain(declareProperty<Real>("volumetric_strain")),
  _volumetric_strain_rate(declareProperty<Real>("volumetric_strain_rate")),
  _yield_criterion((YieldCriterion)(int)getParam<MooseEnum>("yield_criterion")),
  _slope_yield_surface(getParam<Real>("slope_yield_surface"))

  {
  _Cijkl.fillFromInputVector(_Cijkl_vector, _fill_method);
  }

MooseEnum
RedbackMechMaterial::yieldCriterionEnum()
{
  return MooseEnum("J2_plasticity, Drucker_Prager, modified_Cam_Clay");
}


void
RedbackMechMaterial::initQpStatefulProperties()
{
  _total_strain[_qp].zero();
  _elastic_strain[_qp].zero();
  _stress[_qp].zero();
  _plastic_strain[_qp].zero();
  _plastic_strain_old[_qp].zero();
  _eqv_plastic_strain[_qp] = 0.0;

  // Redback properties
  _mises_stress[_qp] = 0;
  _mean_stress[_qp] = 0;
  _volumetric_strain[_qp] = 0;
  _volumetric_strain_rate[_qp] = 0;
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

  //Obtain previous plastic rate of deformation tensor
  dp=_plastic_strain_old[_qp];

  //Solve J2 plastic constitutive equations based on current strain increment
  //Returns current  stress and plastic rate of deformation tensor

  returnMap(_stress_old[_qp], _strain_increment[_qp], _elasticity_tensor[_qp], dp, sig);
  _stress[_qp] = sig;

  //Rotate the stress to the current configuration
  _stress[_qp] = _rotation_increment[_qp] * _stress[_qp] * _rotation_increment[_qp].transpose();

  //Updates current plastic rate of deformation tensor
  _plastic_strain[_qp] = dp;

  //Evaluate and update current equivalent plastic strain
  _eqv_plastic_strain[_qp] = std::pow(2.0/3.0,0.5) * dp.L2norm();

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

}

void
RedbackMechMaterial::returnMap(const RankTwoTensor & sig_old, const RankTwoTensor & delta_d, const RankFourTensor & E_ijkl, RankTwoTensor & dp, RankTwoTensor & sig)
{
  RankTwoTensor sig_new, delta_dp, dpn;
  RankTwoTensor flow_tensor, flow_dirn;
  RankTwoTensor resid,ddsig;
  RankFourTensor dr_dsig, dr_dsig_inv;
  Real flow_incr, flow_incr_tmp;
  Real err1, err3, tol1, tol3;
  unsigned int iterisohard, iter, maxiterisohard = 20, maxiter = 50;
  Real eqvpstrain;
  Real yield_stress, yield_stress_prev;

  tol1 = 1e-10;
  tol3 = 1e-6;

  iterisohard = 0;
  eqvpstrain = std::pow(2.0/3.0,0.5) * dp.L2norm();
  yield_stress = getYieldStress(eqvpstrain);

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
    flow_incr=_ref_pe_rate*_dt * std::pow(macaulayBracket(getSigEqv(sig_new) / yield_stress - 1.0), _exponent) * _exponential;

    getFlowTensor(sig_new, yield_stress, flow_tensor);
    flow_dirn = flow_tensor;

    resid = flow_dirn * flow_incr - delta_dp;
    err1 = resid.L2norm();

    while (err1 > tol1  && iter < maxiter) //Stress update iteration (hardness fixed)
    {
      iter++;

      getJac(sig_new, E_ijkl, flow_incr, yield_stress, dr_dsig); //Jacobian
      dr_dsig_inv = dr_dsig.invSymm();

      ddsig = -dr_dsig_inv * resid;

      sig_new += ddsig; //Update stress
      delta_dp -= E_ijkl.invSymm() * ddsig; //Update plastic rate of deformation tensor

      flow_incr_tmp = _ref_pe_rate * _dt * std::pow(macaulayBracket(getSigEqv(sig_new) / yield_stress - 1.0), _exponent) * _exponential;

      if (flow_incr_tmp < 0.0) //negative flow increment not allowed
        mooseError("Constitutive Error-Negative flow increment: Reduce time increment.");

      flow_incr = flow_incr_tmp;

      getFlowTensor(sig_new, yield_stress, flow_tensor);
      flow_dirn = flow_tensor;

      resid = flow_dirn * flow_incr - delta_dp; //Residual

      err1=resid.L2norm();
    }

    if (iter>=maxiter)//Convergence failure
      mooseError("Constitutive Error-Too many iterations: Reduce time increment.\n"); //Convergence failure

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

  //Compute the energy dissipation and the properties declared
  computeRedbackTerms(sig, yield_stress, flow_incr);
}

void
RedbackMechMaterial::getFlowTensor(const RankTwoTensor & sig, Real /*yield_stress*/, RankTwoTensor & flow_tensor)
{
  RankTwoTensor sig_dev;
  Real sig_eqv, val;

  sig_eqv = getSigEqv(sig);
  sig_dev = sig.deviatoric();

  val = 0.0;
  if (sig_eqv > 1e-8)
    val = 3.0 / (2.0 * sig_eqv);

  flow_tensor = sig_dev * val;
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
RedbackMechMaterial::yieldFunction(const RankTwoTensor & stress, const Real yield_stress)
{
  Real pressure = stress.trace()/3.0;
  // TODO: check _deviatoric_stress...
  switch (_yield_criterion)
    {
      case J2_plasticity:
        return getSigEqv(stress) - yield_stress;
      case Drucker_Prager:
        return getSigEqv(stress) - yield_stress - _slope_yield_surface*pressure;
      case modified_Cam_Clay:
        return std::pow(getSigEqv(stress), 2) + std::pow(_slope_yield_surface,2)*pressure*(pressure-yield_stress);
      default:
        mooseError("yieldFunction called with unknown yield_criterion of " << _yield_criterion);
    }
}

Real
RedbackMechMaterial::getSigEqv(const RankTwoTensor & stress)
{
  return std::pow(3*stress.secondInvariant(), 0.5);
}

//Jacobian for stress update algorithm
void
RedbackMechMaterial::getJac(const RankTwoTensor & sig, const RankFourTensor & E_ijkl, Real flow_incr, Real yield_stress, RankFourTensor & dresid_dsig)
{
  unsigned i, j, k ,l;
  RankTwoTensor sig_dev, flow_tensor, flow_dirn,fij;
  RankTwoTensor dfi_dft;
  RankFourTensor dft_dsig, dfd_dft, dfd_dsig, dfi_dsig;
  Real sig_eqv;
  Real f1, f2, f3;
  Real dfi_dseqv;

  sig_dev = sig.deviatoric();
  sig_eqv = getSigEqv(sig);

  getFlowTensor(sig, yield_stress, flow_tensor);

  flow_dirn = flow_tensor;
  dfi_dseqv = _ref_pe_rate * _dt * _exponent * std::pow(macaulayBracket(sig_eqv / yield_stress - 1.0), _exponent - 1.0) * _exponential / yield_stress;

  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfi_dsig(i,j,k,l) = flow_dirn(i,j) * flow_dirn(k,l) * dfi_dseqv; //d_flow_increment/d_sig

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
  dresid_dsig = E_ijkl.invSymm() + dfd_dsig * flow_incr + dfi_dsig; //Jacobian
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
RedbackMechMaterial::computeRedbackTerms(RankTwoTensor & sig, Real yield_stress, Real flow_incr)
{
  RedbackMaterial::computeRedbackTerms();

  // Compute equivalent stress
  _mises_stress[_qp] = getSigEqv(sig);
  // Compute Mises strain
  _mises_strain[_qp] = flow_incr;
  // Compute Mises strain rate
  _mises_strain_rate[_qp] = flow_incr / _dt;

  // Compute Mechanical Dissipation
  _mechanical_dissipation[_qp] = _gr[_qp] * std::pow(1 - _pore_pres[_qp], _exponent) * getSigEqv(sig) / yield_stress *
      std::pow( macaulayBracket( getSigEqv(sig) / yield_stress - 1.0 ), _exponent) *
      std::exp( _ar[_qp]*_delta[_qp] *_T[_qp] / (1 + _delta[_qp] *_T[_qp]) );
  // Compute Mechanical Dissipation Jacobian
  _mechanical_dissipation_jac[_qp] = _gr[_qp] * std::pow(1 - _pore_pres[_qp], _exponent) * getSigEqv(sig) / yield_stress *
      std::pow( macaulayBracket( getSigEqv(sig) / yield_stress - 1.0 ), _exponent) *
      _ar[_qp]*_delta[_qp] * std::exp( _ar[_qp]*_delta[_qp] *_T[_qp] / (1 + _delta[_qp] *_T[_qp]) ) /
      (1 + _delta[_qp] * _T[_qp]) / (1 + _delta[_qp] * _T[_qp]);
  // Compute the equivalent Gruntfest number for comparison with SuCCoMBE
  _mod_gruntfest_number[_qp] = _gr[_qp] * getSigEqv(sig) / yield_stress * std::pow( macaulayBracket( getSigEqv(sig) / yield_stress - 1.0 ), _exponent);

  return;
}



