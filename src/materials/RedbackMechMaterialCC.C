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

#include "RedbackMechMaterialCC.h"
#include "Ellipse.h"
#include <cmath> //used for fabs

template<>
InputParameters validParams<RedbackMechMaterialCC>()
{
  InputParameters params = validParams<RedbackMechMaterial>();
  //TODO: Check sign of slope_yield_surface
  //  if (_slope_yield_surface == 0)
  //    mooseError("modified Cam-Clay cannot deal with 0 CSL slope ('slope_yield_surface')");
  //  if (getYieldStress(0) <= 0)
  //    mooseError("modified Cam-Clay cannot deal with negative pre-consolidation stress ('yield_stress')");
  params.addParam<Real>("slope_yield_surface", 0,"Slope of yield surface (positive, see documentation)");
  return params;
}

RedbackMechMaterialCC::RedbackMechMaterialCC(const std::string & name, InputParameters parameters) :
  RedbackMechMaterial(name, parameters),
  _slope_yield_surface(getParam<Real>("slope_yield_surface"))
{
  _Cijkl.fillFromInputVector(_Cijkl_vector, _fill_method);
}

/**
 * Get unitary flow tensor in deviatoric direction, modified Cam-Clay
 */
void
RedbackMechMaterialCC::getFlowTensor(const RankTwoTensor & sig, Real q, Real p, Real pc, RankTwoTensor & flow_tensor)
{
  if (pc > 0) pc *= -1;

  flow_tensor = 3.0*sig.deviatoric()/(_slope_yield_surface*_slope_yield_surface);
  flow_tensor.addIa((2.0*p - pc)/3.0); //(p > 0 ? 1:-1)
  // TODO: do we need to normalise? If so, do we need the sqrt(3/2) factor?
  //flow_tensor /= std::pow(2.0/3.0,0.5)*flow_tensor.L2norm(); 
}

/**
 * Compute the flow incrmement for modified Cam-clay
 * pc ... pre-consolidation pressure (pc = -getYieldStress(eqvpstrain))
 */
Real
RedbackMechMaterialCC::getFlowIncrement(Real sig_eqv, Real pressure, Real q_yield_stress, Real p_yield_stress, Real pc)
{
  pc *= -1;
  if (Ellipse::isPointOutsideOfEllipse(/*m=*/_slope_yield_surface, /*p_c=*/pc, /*x=*/pressure, /*y=*/sig_eqv))
  {
    Real flow_incr_vol = _ref_pe_rate * _dt * std::pow(std::fabs(pressure - p_yield_stress), _exponent) * _exponential;
    Real flow_incr_dev = _ref_pe_rate * _dt * std::pow(std::fabs(sig_eqv - q_yield_stress), _exponent) * _exponential;
    return std::pow(flow_incr_vol * flow_incr_vol + flow_incr_dev * flow_incr_dev, 0.5);
  }
  else
    return 0;
}

Real
RedbackMechMaterialCC::getDerivativeFlowIncrement(const RankTwoTensor & sig, Real pressure, Real sig_eqv, Real pc, Real q_yield_stress, Real p_yield_stress)
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

void
RedbackMechMaterialCC::getJac(const RankTwoTensor & sig, const RankFourTensor & E_ijkl, Real flow_incr,
    Real sig_eqv, Real pressure, Real p_yield_stress, Real q_yield_stress, Real pc,
    RankFourTensor & dresid_dsig)
{
  unsigned i, j, k ,l;
  RankTwoTensor sig_dev, flow_dirn_vol, flow_dirn_dev, fij, flow_dirn, flow_tensor;
  RankTwoTensor dfi_dft;
  RankFourTensor dfd_dsig, dfi_dsig;
  Real f1, f2;
  Real dfi_dseqv_dev, dfi_dseqv_vol, dfi_dseqv;

  pc *= -1;

  sig_dev = sig.deviatoric();

  dfi_dseqv = getDerivativeFlowIncrement(sig, pressure, sig_eqv, pc, q_yield_stress, p_yield_stress);
  getFlowTensor(sig, sig_eqv, pressure, pc, flow_dirn); 

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

void
RedbackMechMaterialCC::returnMap(const RankTwoTensor & sig_old, const RankTwoTensor & delta_d, const RankFourTensor & E_ijkl, RankTwoTensor & dp, RankTwoTensor & sig, Real & p_y, Real & q_y)
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
  yield_stress = getYieldStress(eqvpstrain);

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
    p = sig_new.trace()/3.0;
    q = getSigEqv(sig_new);
    get_py_qy(p, q, p_y, q_y, yield_stress);

    // TODO checking whether in plasticity

    // trying normalizing with the norm of the total vector
    flow_incr = getFlowIncrement(q, p, q_y, p_y, yield_stress);
    getFlowTensor(sig_new, q, p, yield_stress, flow_tensor); 
    flow_tensor *= flow_incr;
    resid = flow_tensor - delta_dp;
    err1 = resid.L2norm();
    //TODO: do not compute flow tensor if in elasticity

    // Compute plastic strain increment
    while (err1 > tol1  && iter < maxiter) //Stress update iteration (hardness fixed)
    {
      iter++;

      //Jacobian = d(residual)/d(sigma)
      getJac(sig_new, E_ijkl, flow_incr, q, p, p_y, q_y, yield_stress, dr_dsig); 
      dr_dsig_inv = dr_dsig.invSymm();
      ddsig = -dr_dsig_inv * resid; // Newton Raphson
      delta_dp -= E_ijkl.invSymm() * ddsig; //Update increment of plastic rate of deformation tensor
      sig_new += ddsig; //Update stress

      // Update residual
      p = sig_new.trace()/3.0;
      q = getSigEqv(sig_new);
      get_py_qy(p, q, p_y, q_y, yield_stress);
      flow_incr = getFlowIncrement(q, p, q_y, p_y, yield_stress);
      if (flow_incr < 0.0) //negative flow increment not allowed
        mooseError("Constitutive Error-Negative flow increment Drucker-Prager: Reduce time increment.");
      getFlowTensor(sig_new, q, p, yield_stress, flow_tensor); 
      flow_tensor *= flow_incr;
      resid = flow_tensor - delta_dp; //Residual
      err1=resid.L2norm();
    }
    if (iter>=maxiter)//Convergence failure
      mooseError("Constitutive Error-Too many iterations: Reduce time increment.\n"); //Convergence failure

    dpn = dp + delta_dp;
    eqvpstrain = std::pow(2.0/3.0, 0.5) * dpn.L2norm();
    yield_stress_prev = yield_stress;
    yield_stress = getYieldStress(eqvpstrain); // pre-consolidation stress (warning: negative!)
    err3 = std::abs(yield_stress-yield_stress_prev);
  }

  if (iterisohard>=maxiterisohard)
    mooseError("Constitutive Error-Too many iterations in Hardness Update:Reduce time increment.\n"); //Convergence failure

  dp = dpn; //Plastic rate of deformation tensor in unrotated configuration
  sig = sig_new;
}

void
RedbackMechMaterialCC::get_py_qy(Real p, Real q, Real & p_y, Real & q_y, Real yield_stress)
{
    Ellipse::distanceCC(_slope_yield_surface, -yield_stress, p, q, p_y, q_y);
}
