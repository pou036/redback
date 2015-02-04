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

#include "RedbackMechMaterialDP.h"

template<>
InputParameters validParams<RedbackMechMaterialDP>()
{
  InputParameters params = validParams<RedbackMechMaterial>();
  return params;
}

RedbackMechMaterialDP::RedbackMechMaterialDP(const std::string & name, InputParameters parameters) :
  RedbackMechMaterial(name, parameters)
{
  _Cijkl.fillFromInputVector(_Cijkl_vector, _fill_method);
}

/**
 * Compute pressure projection of stress on Drucker-Prager yield surface
 */
Real
RedbackMechMaterialDP::getPressureProjectionDP(Real pressure, Real sig_eqv, Real cohesion)
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
RedbackMechMaterialDP::returnMap(const RankTwoTensor & sig_old, const RankTwoTensor & delta_d, const RankFourTensor & E_ijkl, RankTwoTensor & dp, RankTwoTensor & sig, Real & p_y, Real & q_y)
{
  RankTwoTensor sig_new, delta_dp, dpn;
  RankTwoTensor flow_tensor;
  RankTwoTensor resid, ddsig;
  RankFourTensor dr_dsig, dr_dsig_inv;
  Real flow_incr;
  Real p, q;
  Real err1, err3, tol1, tol3;
  unsigned int iterisohard, iter, maxiterisohard = 20, maxiter = 50;
  Real eqvpstrain;
  Real yield_stress, yield_stress_prev;

  tol1 = 1e-10;
  tol3 = 1e-6;
  err3 = 1.1 * tol3;
  iterisohard = 0;

  eqvpstrain = std::pow(2.0/3.0,0.5) * dp.L2norm();
  yield_stress = getYieldStress(eqvpstrain); // User defined yield stress is the cohesion only (evolving with plastic strain)

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

    // Elastic guess
    sig_new = sig_old + E_ijkl * delta_d;
    // Compute distance to current yield surface (line), only valid for associative potential
    p = sig_new.trace()/3.0; // p
    q = getSigEqv(sig_new);   // q
    get_py_qy_DP(p, q, p_y, q_y, yield_stress);

    // TODO checking whether in plasticity

    // trying normalizing with the norm of the total vector
    flow_incr = getFlowIncrementDP(q, p, q_y, p_y);
    getFlowTensorDP(sig_new, q, flow_tensor);
    flow_tensor *= flow_incr;
    resid = flow_tensor - delta_dp;
    err1 = resid.L2norm();

    //TODO: do not compute flow tensor if in elasticity

    // Compute plastic strain increment
    while (err1 > tol1  && iter < maxiter) //Stress update iteration (hardness fixed)
    {
      iter++;
      
      //Jacobian = d(residual)/d(sigma)
      getJacDP(sig_new, E_ijkl, q, p, p_y, q_y, dr_dsig); 
      dr_dsig_inv = dr_dsig.invSymm();
      ddsig = -dr_dsig_inv * resid; // Newton Raphson
      delta_dp -= E_ijkl.invSymm() * ddsig; //Update increment of plastic rate of deformation tensor
      sig_new += ddsig; //Update stress

      // Update residual
      p = sig_new.trace()/3.0;
      q = getSigEqv(sig_new);
      get_py_qy_DP(p, q, p_y, q_y, yield_stress);
      flow_incr = getFlowIncrementDP(q, p, q_y, p_y);
      if (flow_incr < 0.0) //negative flow increment not allowed
        mooseError("Constitutive Error-Negative flow increment Drucker-Prager: Reduce time increment.");
      getFlowTensorDP(sig_new, q, flow_tensor);
      flow_tensor *= flow_incr;
      resid = flow_tensor - delta_dp; //Residual
      err1=resid.L2norm();
    }

    if (iter>=maxiter)//Convergence failure
      mooseError("Constitutive Error-Too many iterations: Reduce time increment.\n"); //Convergence failure

    dpn = dp + delta_dp;
    eqvpstrain = std::pow(2.0/3.0, 0.5) * dpn.L2norm();
    yield_stress_prev = yield_stress;
    yield_stress = getYieldStress(eqvpstrain);
    err3 = std::abs(yield_stress - yield_stress_prev);
  }

  if (iterisohard>=maxiterisohard)
    mooseError("Constitutive Error-Too many iterations in Hardness Update:Reduce time increment.\n"); //Convergence failure

  dp = dpn; //Plastic rate of deformation tensor in unrotated configuration
  sig = sig_new;
}

void
RedbackMechMaterialDP::getFlowTensorDP(const RankTwoTensor & sig, Real sig_eqv, RankTwoTensor & flow_tensor)
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
 * Compute flow increment for Drucker-Prager case
 */
Real
RedbackMechMaterialDP::getFlowIncrementDP(Real sig_eqv, Real pressure, Real q_yield_stress, Real p_yield_stress)
{
  Real flow_incr_vol = _ref_pe_rate * _dt * 
      std::pow(macaulayBracket(pressure - p_yield_stress), _exponent) * _exponential;
  // TODO: q_yield_stress can be 0, we should handle that case properly...
  Real flow_incr_dev = _ref_pe_rate * _dt * std::pow(macaulayBracket((q_yield_stress > 0 ? 1:-1)*
              (sig_eqv / q_yield_stress - 1.0)), _exponent)* _exponential; 
              //(q_yield_stress > 0 ? 1:-1) is the sign function
  return std::pow(flow_incr_vol * flow_incr_vol + flow_incr_dev * flow_incr_dev, 0.5);
  // TODO: change the formula to use dist_pq^m
}

Real
RedbackMechMaterialDP::getDerivativeFlowIncrementDP(const RankTwoTensor & sig, Real pressure, Real sig_eqv, Real q_yield_stress, Real p_yield_stress)
{
  Real delta_lambda_p = _ref_pe_rate * _dt * std::pow(macaulayBracket(pressure - p_yield_stress), _exponent) * _exponential;
  Real delta_lambda_q = _ref_pe_rate * _dt * std::pow(macaulayBracket((q_yield_stress > 0 ? 1:-1)*(sig_eqv / q_yield_stress - 1.0)), _exponent) * _exponential;
  Real delta_lambda = (std::pow(delta_lambda_p * delta_lambda_p + delta_lambda_q * delta_lambda_q, 0.5));
  Real der_flow_incr_dev = _ref_pe_rate * _dt * _exponent * std::pow(macaulayBracket((q_yield_stress > 0 ? 1:-1)*(sig_eqv / q_yield_stress - 1.0)), _exponent - 1.0) * _exponential / q_yield_stress;
  Real der_flow_incr_vol = _ref_pe_rate * _dt * _exponent * std::pow(macaulayBracket(pressure - p_yield_stress), _exponent - 1.0) * _exponential;
  return (delta_lambda_q * der_flow_incr_dev + delta_lambda_p * der_flow_incr_vol) / delta_lambda;
}


void
RedbackMechMaterialDP::getJacDP(const RankTwoTensor & sig, const RankFourTensor & E_ijkl,
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
RedbackMechMaterialDP::get_py_qy_DP(Real p, Real q, Real & p_y, Real & q_y, Real yield_stress)
{
    p_y = getPressureProjectionDP(p /*p*/, q /*q*/, yield_stress/*yield stress*/);
    q_y = yield_stress + _slope_yield_surface * p_y; // yield deviatoric stress
}
