/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#include "RedbackPlasticityUOCC.h"
#include "Ellipse.h"
#include <cmath> //used for fabs

template<>
InputParameters validParams<RedbackPlasticityUOCC>()
{
  InputParameters params = validParams<RedbackPlasticityUOBase>();
  params.addClassDescription("User object to store plasticity functions based on CC");
  params.addRequiredParam<Real>("slope_yield_surface", "Slope of yield surface (positive, see documentation)");
  return params;
}

RedbackPlasticityUOCC::RedbackPlasticityUOCC(const InputParameters & parameters) :
    RedbackPlasticityUOBase(parameters),
    _slope_yield_surface(getParam<Real>("slope_yield_surface"))
{
}

/**
 * Derivative of getFlowIncrement with respect to equivalent stress, only has deviatoric component in J2 plasiticity
 */
Real
RedbackPlasticityUOCC::getDerivativeFlowIncrement(
  const RankTwoTensor & sig, Real pressure, Real sig_eqv, Real pc, Real q_yield_stress, Real p_yield_stress, Real dt, Real exponent, Real exponential, Real ref_pe_rate) const
{
  if (Ellipse::isPointOutsideOfEllipse(/*m=*/_slope_yield_surface, /*p_c=*/pc, /*x=*/pressure, /*y=*/sig_eqv))
  {
    Real delta_lambda_p =
      ref_pe_rate * dt * std::pow(std::fabs(pressure - p_yield_stress), exponent) * exponential;
    Real delta_lambda_q = ref_pe_rate * dt * std::pow(std::fabs(sig_eqv - q_yield_stress), exponent) * exponential;
    Real delta_lambda = (std::pow(delta_lambda_p * delta_lambda_p + delta_lambda_q * delta_lambda_q, 0.5));
    Real der_flow_incr_dev =
      ref_pe_rate * dt * exponent * std::pow(std::fabs(sig_eqv - q_yield_stress), exponent - 1.0) * exponential;
    Real der_flow_incr_vol =
      ref_pe_rate * dt * exponent * std::pow(std::fabs(pressure - p_yield_stress), exponent - 1.0) * exponential;
    return (delta_lambda_q * der_flow_incr_dev + delta_lambda_p * der_flow_incr_vol) / delta_lambda;
  }
  else
    return 0;
}

Real
RedbackPlasticityUOCC::getFlowIncrement(Real sig_eqv, Real pressure, Real q_yield_stress, Real p_yield_stress, Real pc, Real dt, Real exponent, Real exponential, Real ref_pe_rate) const
{
  pc *= -1;
  if (Ellipse::isPointOutsideOfEllipse(/*m=*/_slope_yield_surface, /*p_c=*/pc, /*x=*/pressure, /*y=*/sig_eqv))
  {
    Real flow_incr_vol = ref_pe_rate * dt * std::pow(std::fabs(pressure - p_yield_stress), exponent) * exponential;
    Real flow_incr_dev = ref_pe_rate * dt * std::pow(std::fabs(sig_eqv - q_yield_stress), exponent) * exponential;
    return std::pow(flow_incr_vol * flow_incr_vol + flow_incr_dev * flow_incr_dev, 0.5);
  }
  else
    return 0;
}

void
RedbackPlasticityUOCC::getFlowTensor(
  const RankTwoTensor & sig, Real q, Real p, Real pc, RankTwoTensor & flow_tensor) const
{
  if (pc > 0)
    pc *= -1;

  flow_tensor = 3.0 * sig.deviatoric() / (_slope_yield_surface * _slope_yield_surface);
  flow_tensor.addIa((2.0 * p - pc) / 3.0); //(p > 0 ? 1:-1)
                                           // TODO: do we need to normalise? If so, do we need the sqrt(3/2) factor?
  // flow_tensor /= std::pow(2.0/3.0,0.5)*flow_tensor.L2norm();
}

// Jacobian for stress update algorithm
void
RedbackPlasticityUOCC::getJac(const RankTwoTensor & sig,
                              const RankFourTensor & E_ijkl,
                              Real flow_incr,
                              Real sig_eqv,
                              Real pressure,
                              Real p_yield_stress,
                              Real q_yield_stress,
                              Real pc,
                              RankFourTensor & dresid_dsig,
                              Real dt,
                              Real exponent,
                              Real exponential,
                              Real ref_pe_rate) const
{
  unsigned i, j, k, l;
  RankTwoTensor sig_dev, flow_dirn_vol, flow_dirn_dev, fij, flow_dirn, flow_tensor;
  RankTwoTensor dfi_dft;
  RankFourTensor dfd_dsig, dfi_dsig;
  Real f1, f2;
  Real dfi_dseqv_dev, dfi_dseqv_vol, dfi_dseqv;

  pc *= -1;

  sig_dev = sig.deviatoric();

  dfi_dseqv = getDerivativeFlowIncrement(sig, pressure, sig_eqv, pc, q_yield_stress, p_yield_stress, dt, exponent, exponential, ref_pe_rate);
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
          dfi_dsig(i, j, k, l) = flow_dirn(i, j) * flow_dirn(k, l) * dfi_dseqv;

  // Real flow_tensor_norm = flow_dirn.L2norm();

  // This loop calculates the second term. Read REDBACK's documentation
  // (same as J2 plasticity case)
  f1 = 0.0;
  f2 = 0.0;
  if (sig_eqv > 1e-8)
  {
    f1 = 3.0 / (_slope_yield_surface * _slope_yield_surface);
    f2 = 2.0 / 9.0 - 1.0 / (_slope_yield_surface * _slope_yield_surface);
  }
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfd_dsig(i, j, k, l) =
            f1 * deltaFunc(i, k) * deltaFunc(j, l) -
            f2 * deltaFunc(i, j) * deltaFunc(k, l); // d_flow_dirn/d_sig - 2nd part (J2 plasticity)

  // dfd_dsig = dft_dsig1/flow_tensor_norm - 3.0 * dft_dsig2 /
  // (2*sig_eqv*flow_tensor_norm*flow_tensor_norm*flow_tensor_norm); //d_flow_dirn/d_sig
  // TODO: check if the previous two lines (i.e normalizing the flow vector) should be activated or not. Currently we
  // are using the non-unitary flow vector

  dresid_dsig = E_ijkl.invSymm() + dfd_dsig * flow_incr + dfi_dsig; // Jacobian
}

void
RedbackPlasticityUOCC::get_py_qy(Real p, Real q, Real & p_y, Real & q_y, Real yield_stress) const
{
  Ellipse::distanceCC(_slope_yield_surface, -yield_stress, p, q, p_y, q_y);
}
