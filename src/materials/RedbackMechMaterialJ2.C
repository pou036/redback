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

#include "RedbackMechMaterialJ2.h"

template<>
InputParameters validParams<RedbackMechMaterialJ2>()
{
  InputParameters params = validParams<RedbackMechMaterial>();
  return params;
}

RedbackMechMaterialJ2::RedbackMechMaterialJ2(const std::string & name, InputParameters parameters) :
  RedbackMechMaterial(name, parameters)
{
  _Cijkl.fillFromInputVector(_Cijkl_vector, _fill_method);
}

void
RedbackMechMaterialJ2::returnMap(const RankTwoTensor & sig_old, const RankTwoTensor & delta_d, const RankFourTensor & E_ijkl, RankTwoTensor & dp, RankTwoTensor & sig, Real & p_y, Real & q_y)
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

  tol1 = 1e-15; // TODO: expose to user interface and/or make the tolerance relative
  tol3 = 1e-10; // TODO: expose to user interface and/or make the tolerance relative
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
    get_py_qyJ2(p, q, p_y, q_y, yield_stress);

    //TODO: checking whether in plasticity

    flow_incr = getFlowIncrementJ2(q, p, q_y, p_y, yield_stress);
    getFlowTensorJ2(sig_new, q, p, yield_stress, flow_tensor); 
    flow_tensor *= flow_incr;
    resid = flow_tensor - delta_dp;
    err1 = resid.L2norm();
    //TODO: do not compute flow tensor if in elasticity

    while (err1 > tol1  && iter < maxiter) //Stress update iteration (hardness fixed)
    {
      iter++;
      
      //Jacobian = d(residual)/d(sigma)
      getJacJ2(sig_new, E_ijkl, flow_incr, q, p, p_y, q_y, yield_stress, dr_dsig); 
      dr_dsig_inv = dr_dsig.invSymm();
      ddsig = -dr_dsig_inv * resid; // Newton Raphson
      delta_dp -= E_ijkl.invSymm() * ddsig; //Update increment of plastic rate of deformation tensor
      sig_new += ddsig; //Update stress

      // Update residual
      p = sig_new.trace()/3.0;
      q = getSigEqv(sig_new);
      get_py_qyJ2(p, q, p_y, q_y, yield_stress);
      flow_incr = getFlowIncrementJ2(q, p, q_y, p_y, yield_stress);
      if (flow_incr < 0.0) //negative flow increment not allowed
        mooseError("Constitutive Error-Negative flow increment: Reduce time increment.");
      getFlowTensorJ2(sig_new, q, p, yield_stress, flow_tensor); 
      flow_tensor *= flow_incr;
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
}

/**
 * Get unitary flow tensor in deviatoric direction, J2 plasticity. It only has a deviatoric part
 */
void
RedbackMechMaterialJ2::getFlowTensorJ2(const RankTwoTensor & sig, Real q, Real p, Real yield_stress, RankTwoTensor & flow_tensor_dev)
{
  RankTwoTensor sig_dev;
  Real val;

  sig_dev = sig.deviatoric();
  val = 0.0;
  if (q > 1e-8)
    val = 3.0 / (2.0 * q);
  flow_tensor_dev = sig_dev * val;
  //flow_tensor_dev /= flow_tensor_dev.L2norm();
  // TODO: norm is actually sqrt(3/2)
}


Real
RedbackMechMaterialJ2::getFlowIncrementJ2(Real sig_eqv, Real p, Real q_y, Real p_y, Real yield_stress)
{
  return _ref_pe_rate * _dt * std::pow(macaulayBracket(sig_eqv / yield_stress - 1.0), _exponent) * 
      _exponential;
}

/**
 * Derivative of getFlowIncrement with respect to equivalent stress, only has deviatoric component in J2 plasiticity
 */
Real
RedbackMechMaterialJ2::getDerivativeFlowIncrementJ2(const RankTwoTensor & sig, Real yield_stress)
{
  // Derivative of getFlowIncrement with respect to equivalent stress
  return _ref_pe_rate * _dt * _exponent * std::pow(macaulayBracket(getSigEqv(sig) / yield_stress - 1.0), _exponent - 1.0) * _exponential / yield_stress;
}

//Jacobian for stress update algorithm
void
RedbackMechMaterialJ2::getJacJ2(const RankTwoTensor & sig, const RankFourTensor & E_ijkl, Real flow_incr_dev,
        Real q, Real p, Real p_y, Real q_y, Real yield_stress, RankFourTensor & dresid_dsig)
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

  getFlowTensorJ2(sig, q, p, yield_stress, flow_dirn_dev); 
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
RedbackMechMaterialJ2::get_py_qyJ2(Real p, Real q, Real & p_y, Real & q_y, Real yield_stress)
{
  p_y = p;
  q_y = yield_stress;
}
