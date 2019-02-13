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

#include "RedbackMechMaterialDP.h"

registerMooseObject("RedbackApp", RedbackMechMaterialDP);

template <>
InputParameters
validParams<RedbackMechMaterialDP>()
{
  InputParameters params = validParams<RedbackMechMaterial>();
  params.addParam<Real>("slope_yield_surface", 0, "Slope of yield surface (usually negative)");

  return params;
}

RedbackMechMaterialDP::RedbackMechMaterialDP(const InputParameters & parameters)
  : RedbackMechMaterial(parameters), _mu(getParam<Real>("slope_yield_surface"))
{
}

/**
 * Compute pressure projection of stress on Drucker-Prager yield surface
 */
Real
RedbackMechMaterialDP::getPressureProjection(Real pressure, Real sig_eqv, Real cohesion)
{
  // yield pressure, for non-associative, replace mu^2 with mu*dilatency
  // the "fmin" is to handle the apex. Apparently fmin(1/0, x) = x, so it's
  // always true
  // return fmin(-cohesion/_mu, (pressure +
  // _mu*(sig_eqv - cohesion))
  //    / (1.0 + (_mu) * (_mu)));

  if (_mu == 0)
    return pressure;
  else if (_mu < 0)
    return fmin(-cohesion / _mu, (pressure + _mu * (sig_eqv - cohesion)) / (1.0 + (_mu) * (_mu)));
  else
  {
    // _mu > 0, for whatever reason...
    return fmax(-cohesion / _mu, (pressure + _mu * (sig_eqv - cohesion)) / (1.0 + (_mu) * (_mu)));
  }
}

void
RedbackMechMaterialDP::getFlowTensor(const RankTwoTensor & sig,
                                     Real q,
                                     Real /*p*/,
                                     Real /*q_y*/,
                                     Real /*p_y*/,
                                     Real /*yield_stress*/,
                                     RankTwoTensor & flow_tensor)
{
  RankTwoTensor sig_dev;
  Real val;

  sig_dev = sig.deviatoric();
  val = 0.0;
  if (q > 1e-8)
    val = 3.0 / (2.0 * q);
  flow_tensor = sig_dev * val;
  flow_tensor.addIa(-_mu / 3.0);
  // Normalise flow tensor
  flow_tensor /= std::pow(3.0 / 2.0 + _mu * _mu, 0.5);
}

/**
 * Compute flow increment for Drucker-Prager case
 */
Real
RedbackMechMaterialDP::getFlowIncrement(Real sig_eqv,
                                        Real pressure,
                                        Real q_yield_stress,
                                        Real p_yield_stress,
                                        Real yield_stress,
                                        Real /*s*/)
{
  Real flow_incr_vol =
      _ref_pe_rate * _dt *
      std::pow(macaulayBracket(((pressure - p_yield_stress) / yield_stress) * (_mu < 0 ? 1 : -1)),
               _exponent) *
      _exponential;
  Real flow_incr_dev = _ref_pe_rate * _dt *
                       std::pow(macaulayBracket((q_yield_stress > 0 ? 1 : -1) *
                                                ((sig_eqv - q_yield_stress) / yield_stress)),
                                _exponent) *
                       _exponential;
  //(q_yield_stress > 0 ? 1:-1) is the sign function
  return std::pow(flow_incr_vol * flow_incr_vol + flow_incr_dev * flow_incr_dev, 0.5);
  // TODO: change the formula to use dist_pq^m
}

void
RedbackMechMaterialDP::getDerivativeFlowIncrement(Real & dfi_dp,
                                                  Real & dfi_dq,
                                                  const RankTwoTensor & /*sig*/,
                                                  Real pressure,
                                                  Real sig_eqv,
                                                  Real yield_stress,
                                                  Real q_yield_stress,
                                                  Real p_yield_stress)
{
  Real p_term = macaulayBracket(((pressure - p_yield_stress) / yield_stress) * (_mu < 0 ? 1 : -1));
  Real q_term = macaulayBracket((sig_eqv - q_yield_stress) / yield_stress);
  Real factor = _ref_pe_rate * _dt * _exponent * _exponential /
                std::sqrt(std::pow(p_term, 2 * _exponent) + std::pow(q_term, 2 * _exponent));
  dfi_dp = factor * std::pow(p_term, 2 * _exponent - 1) / yield_stress;
  dfi_dq = factor * std::pow(q_term, 2 * _exponent - 1) / yield_stress;
}

void
RedbackMechMaterialDP::getJac(const RankTwoTensor & sig,
                              const RankFourTensor & E_ijkl,
                              Real flow_incr,
                              Real sig_eqv,
                              Real pressure,
                              Real p_yield_stress,
                              Real q_yield_stress,
                              Real yield_stress,
                              Real /*s*/,
                              RankFourTensor & dresid_dsig)
{
  unsigned i, j, k, l;
  RankTwoTensor sig_dev, fij, flow_dirn;
  RankTwoTensor dfi_dft;
  RankFourTensor dfd_dft, dfd_dsig, dfi_dsig;
  Real f1, f2, f3, f4;
  Real dfi_dp, dfi_dseqv;

  sig_dev = sig.deviatoric();

  getDerivativeFlowIncrement(
      dfi_dp, dfi_dseqv, sig, pressure, sig_eqv, yield_stress, q_yield_stress, p_yield_stress);
  getFlowTensor(sig, sig_eqv, pressure, q_yield_stress, p_yield_stress, yield_stress, flow_dirn);

  /* The following calculates the tensorial derivative (Jacobian) of the
   * residual with respect to stress, dr_dsig
   * It consists of two terms: The first is
   * dr_dsig = (dfi_dseqv_dev*flow_dirn_dev(k,l)) * flow_dirn_dev(i,j)
   * which is the tensorial product of the flow increment tensor times the flow
   * direction tensor
   *
   * The second is the product of the flow increment tensor times the derivative
   * of the flow direction tensor
   * with respect to the stress tensor. See also REDBACK's documentation
   * */

  f1 = 0.0;
  f2 = 0.0;
  f3 = 0.0;
  f4 = 0.0;
  if (sig_eqv > 1e-8)
  {
    f1 = 3.0 / (2.0 * sig_eqv * std::pow(3.0 / 2.0 + _mu * _mu, 0.5));
    f2 = f1 / 3.0;
    f3 = 9.0 / (4.0 * std::pow(sig_eqv, 3.0) * std::pow(3.0 / 2.0 + _mu * _mu, 0.5));
    f4 = 3.0 / (2.0 * sig_eqv);
  }

  // This loop calculates the first term
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfi_dsig(i, j, k, l) =
              flow_dirn(i, j) * (f4 * sig_dev(k, l) * dfi_dseqv + dfi_dp * deltaFunc(k, l) / 3.0);

  // This loop calculates the second term. Read REDBACK's documentation
  // (same as J2 plasticity case)
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfd_dsig(i, j, k, l) = f1 * deltaFunc(i, k) * deltaFunc(j, l) -
                                 f2 * deltaFunc(i, j) * deltaFunc(k, l) -
                                 f3 * sig_dev(i, j) * sig_dev(k, l);

  dresid_dsig = E_ijkl.invSymm() + dfd_dsig * flow_incr + dfi_dsig; // Jacobian
}

void
RedbackMechMaterialDP::get_py_qy(
    Real p, Real q, Real & p_y, Real & q_y, Real yield_stress, bool & is_plastic, Real & s)
{
  p_y = getPressureProjection(p /*p*/, q /*q*/, yield_stress /*yield stress*/);
  q_y = yield_stress + _mu * p_y; // yield deviatoric stress
  // Check for plasticity
  is_plastic = (q >= yield_stress + _mu * p);
  s = std::sqrt(std::pow(p - p_y, 2) + std::pow(q - q_y, 2));
}
