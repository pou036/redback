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

#include "DimensionlessRock.h"

template<>
InputParameters validParams<DimensionlessRock>()
{
  InputParameters params = validParams<FiniteStrainPlasticMaterial>();

  params.addRequiredRangeCheckedParam<Real>("gr", "gr>=0", "Gruntfest number.");
  params.addRequiredParam<Real>("ar", "Arrhenius number.");
  params.addRequiredParam<Real>("ar_c", "Chemical Arrhenius number.");
  params.addRequiredParam<Real>("delta", "Kamenetskii coefficient.");
  params.addRequiredParam<Real>("da", "Damkoehler number.");
  params.addRequiredParam<Real>("mu", "Chemical pressurization coefficient.");
  params.addRequiredParam<Real>("m", "Exponent for rate dependent plasticity (Perzyna)");
  params.addCoupledVar("T", 0, "Temperature in Kelvin");
  
  return params;
}

DimensionlessRock::DimensionlessRock(const std::string & name, InputParameters parameters) :
    FiniteStrainPlasticMaterial(name, parameters),
    _T(coupledValue("T")),
    
    _gr_param(getParam<Real>("gr")),
    _ar_param(getParam<Real>("ar")),
    _ar_c_param(getParam<Real>("ar_c")),
    _delta_param(getParam<Real>("delta")),
    _da_param(getParam<Real>("da")),
    _mu_param(getParam<Real>("mu")),
    _m_param(getParam<Real>("m")),

    _gr(declareProperty<Real>("gr")),
    _ar(declareProperty<Real>("ar")),
    _ar_c(declareProperty<Real>("ar_c")),
    _delta(declareProperty<Real>("delta")),
    _da(declareProperty<Real>("da")),
    _mu(declareProperty<Real>("mu")),
    _m(declareProperty<Real>("m")),
    
    _equivalent_stress(declareProperty<Real>("equivalent_stress")),
    _mises_strain(declareProperty<Real>("mises_strain")),
    _mises_strain_rate(declareProperty<Real>("mises_strain_rate")),
    _mechanical_dissipation(declareProperty<Real>("mechanical_dissipation"))
   
  {
}

//=================================================================


void
DimensionlessRock::initQpStatefulProperties()
{
  _elastic_strain[_qp].zero();
  _stress[_qp].zero();
  _equivalent_stress[_qp] = 0;
  _mises_strain[_qp] = 0;
  _plastic_strain[_qp].zero();
  _plastic_strain_old[_qp].zero();
  _eqv_plastic_strain[_qp] = 0.0;
}

void
DimensionlessRock::computeQpStress()
{
  RankTwoTensor dp,sig;
  
  _exponential = 1;
  if (_has_T)
  {
    _exponential = std::exp(-_ar[_qp])* std::exp(_ar[_qp]*_delta[_qp] *_T[_qp]/(1 + _delta[_qp] *_T[_qp]));
  }
  
  // Initialise our made up variables...
  _gr[_qp] = _gr_param;
  _ar[_qp] = _ar_param;
  _ar_c[_qp] = _ar_c_param;
  _delta[_qp] = _delta_param;
  _da[_qp] = _da_param;
  _mu[_qp] = _mu_param;
  _m[_qp] = _m_param;
  _exponent = _m[_qp];
  
  //In elastic problem, all the strain is elastic
  _elastic_strain[_qp] = _elastic_strain_old[_qp] + _strain_increment[_qp];

  //Obtain previous plastic rate of deformation tensor
  dp=_plastic_strain_old[_qp];
  
  //Solve J2 plastic constitutive equations based on current strain increment
  //Returns current  stress and plastic rate of deformation tensor

  returnMap(_stress_old[_qp], _strain_increment[_qp], _elasticity_tensor[_qp], dp, sig);
  _stress[_qp] = sig;

  //Updates current plastic rate of deformation tensor
  _plastic_strain[_qp] = dp;

  //Evaluate and update current equivalent plastic strain
  _eqv_plastic_strain[_qp] = std::pow(2.0/3.0,0.5) * dp.L2norm();


  //Rotate the stress to the current configuration
  _stress[_qp] = _rotation_increment[_qp] * _stress[_qp] * _rotation_increment[_qp].transpose();

  //Rotate to plastic rate of deformation tensor the current configuration
  _plastic_strain[_qp] = _rotation_increment[_qp] * _plastic_strain[_qp] * _rotation_increment[_qp].transpose();
}

/*
 *Solves for incremental plastic rate of deformation tensor and stress in unrotated frame.
 *Input: Strain incrment, 4th order elasticity tensor, stress tensor in previous incrmenent and
 *plastic rate of deformation tensor.
 */
void
DimensionlessRock::returnMap(const RankTwoTensor & sig_old, const RankTwoTensor & delta_d, const RankFourTensor & E_ijkl, RankTwoTensor & dp, RankTwoTensor & sig)
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

  while (err3 > tol3 && iterisohard < maxiterisohard) //Hardness update iteration
  {
    iterisohard++;
    iter = 0;
    delta_dp.zero();

    sig_new = sig_old + E_ijkl * delta_d;
    flow_incr=_dt * std::pow(macaulayBracket(getSigEqv(sig_new) / yield_stress - 1.0), _exponent)*_exponential;

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

      flow_incr_tmp = _dt * std::pow(macaulayBracket(getSigEqv(sig_new) / yield_stress - 1.0), _exponent)*_exponential;

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

  // Compute equivalent stress
  _equivalent_stress[_qp] = getSigEqv(sig_new);
  // Compute Mises strain
  _mises_strain[_qp] = flow_incr;
  // Compute Mises strain rate
  _mises_strain_rate[_qp] = flow_incr / _dt;
  // Compute Mechanical Dissipation
  _mechanical_dissipation[_qp]=_gr[_qp] * getSigEqv(sig_new)* std::pow(macaulayBracket(getSigEqv(sig_new) / yield_stress - 1.0), _exponent)*std::exp(_ar[_qp]*_delta[_qp] *_T[_qp]/(1 + _delta[_qp] *_T[_qp]));
  
  dp = dpn; //Plastic rate of deformation tensor in unrotated configuration
  sig = sig_new;
}

//Obtain derivative of flow potential w.r.t. stress (plastic flow direction)
void
DimensionlessRock::getFlowTensor(const RankTwoTensor & sig, Real /*yield_stress*/, RankTwoTensor & flow_tensor)
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

//Jacobian for stress update algorithm
void
DimensionlessRock::getJac(const RankTwoTensor & sig, const RankFourTensor & E_ijkl, Real flow_incr, Real yield_stress, RankFourTensor & dresid_dsig)
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
  dfi_dseqv = _dt * _exponent * std::pow(macaulayBracket(sig_eqv / yield_stress - 1.0), _exponent - 1.0) * _exponential / yield_stress;

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

//Macaulay Bracket used in Perzyna Model
Real
DimensionlessRock::macaulayBracket(Real val)
{
  if (val > 0.0)
    return val;
  else
    return 0.0;
}
