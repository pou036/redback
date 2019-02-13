/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "RedbackMechMaterialJ2.h"

registerMooseObject("RedbackApp", RedbackMechMaterialJ2);

template <>
InputParameters
validParams<RedbackMechMaterialJ2>()
{
  InputParameters params = validParams<RedbackMechMaterial>();
  return params;
}

RedbackMechMaterialJ2::RedbackMechMaterialJ2(const InputParameters & parameters)
  : RedbackMechMaterial(parameters)
{
}

/**
 * Get unitary flow tensor in deviatoric direction, J2 plasticity. It only has a
 * deviatoric part
 */
void
RedbackMechMaterialJ2::getFlowTensor(const RankTwoTensor & sig,
                                     Real q,
                                     Real /*p*/,
                                     Real /*q_y*/,
                                     Real /*p_y*/,
                                     Real /*yield_stress*/,
                                     RankTwoTensor & flow_tensor_dev)
{
  RankTwoTensor sig_dev;
  Real val;

  sig_dev = sig.deviatoric();
  val = 0.0;
  if (q > 1e-8)
    val = std::sqrt(3.0 / 2.0) / q; // normalised flow tensor
  flow_tensor_dev = sig_dev * val;
}

Real
RedbackMechMaterialJ2::getFlowIncrement(
    Real sig_eqv, Real /*p*/, Real /*q_y*/, Real /*p_y*/, Real yield_stress, Real /*s*/)
{
  return _ref_pe_rate * _dt * std::pow(macaulayBracket(sig_eqv / yield_stress - 1.0), _exponent) *
         _exponential;
}

/**
 * Derivative of getFlowIncrement with respect to equivalent stress, only has
 * deviatoric component in J2 plasiticity
 */
Real
RedbackMechMaterialJ2::getDerivativeFlowIncrement(const RankTwoTensor & sig, Real yield_stress)
{
  // Derivative of getFlowIncrement with respect to equivalent stress
  return _ref_pe_rate * _dt * _exponent *
         std::pow(macaulayBracket(getSigEqv(sig) / yield_stress - 1.0), _exponent - 1.0) *
         _exponential / yield_stress;
}

// Jacobian for stress update algorithm
void
RedbackMechMaterialJ2::getJac(const RankTwoTensor & sig,
                              const RankFourTensor & E_ijkl,
                              Real flow_incr_dev,
                              Real q,
                              Real p,
                              Real p_y,
                              Real q_y,
                              Real yield_stress,
                              Real /*s*/,
                              RankFourTensor & dresid_dsig)
{
  Real sig_eqv = getSigEqv(sig);

  RankTwoTensor flow_dirn_dev;
  getFlowTensor(sig, q, p, q_y, p_y, yield_stress, flow_dirn_dev);
  Real dfi_dseqv_dev = getDerivativeFlowIncrement(sig, yield_stress);

  Real f1 = 0.0;
  Real f2 = 0.0;
  Real f3 = std::sqrt(3.0 / 2.0);

  if (sig_eqv > 1e-8)
  {
    f1 = f3 / sig_eqv;
    f2 = f1 / 3.0;
  }

  RankFourTensor dfi_dsig;
  for (unsigned int i = 0; i < 3; ++i)
    for (unsigned int j = 0; j < 3; ++j)
      for (unsigned int k = 0; k < 3; ++k)
        for (unsigned int l = 0; l < 3; ++l)
          dfi_dsig(i, j, k, l) = f3 * flow_dirn_dev(i, j) * flow_dirn_dev(k, l) *
                                 dfi_dseqv_dev; // d_flow_increment/d_sig

  RankFourTensor dft_dsig;
  for (unsigned int i = 0; i < 3; ++i)
    for (unsigned int j = 0; j < 3; ++j)
      for (unsigned int k = 0; k < 3; ++k)
        for (unsigned int l = 0; l < 3; ++l)
          dft_dsig(i, j, k, l) =
              f1 * deltaFunc(i, k) * deltaFunc(j, l) - f2 * deltaFunc(i, j) * deltaFunc(k, l) -
              f1 * flow_dirn_dev(i, j) * flow_dirn_dev(k, l); // d_flow_dirn/d_sig - 2nd part

  // d_flow_dirn/d_sig
  dresid_dsig = E_ijkl.invSymm() + dft_dsig * flow_incr_dev + dfi_dsig; // Jacobian
}

void
RedbackMechMaterialJ2::get_py_qy(
    Real p, Real q, Real & p_y, Real & q_y, Real yield_stress, bool & is_plastic, Real & s)
{
  p_y = p;
  q_y = yield_stress;
  // Check for plasticity
  is_plastic = (q >= q_y);
  s = std::abs(q - q_y);
}
