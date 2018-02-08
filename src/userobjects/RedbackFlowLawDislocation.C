#include "RedbackFlowLawBase.h"
#include "RedbackFlowLawDislocation.h"
#include "Utils.h"
#include <math.h> // for M_PI

template <>
InputParameters
validParams<RedbackFlowLawDislocation>()
{
  InputParameters params = validParams<RedbackFlowLawBase>();
  params.addParam<Real>("pre_exponential_factor", 1.0, "Value of pre-exponential factor.");
  params.addParam<Real>("exponent", 1.0, "Exponent for rate dependent plasticity (Perzyna)");
  params.addParam<Real>("Arrhenius", 1.0, "Value of Arrhenius coefficient.");

  return params;
}

RedbackFlowLawDislocation::RedbackFlowLawDislocation(const InputParameters& parameters) :
    RedbackFlowLawBase(parameters),
  _pre_exponential_factor(getParam<Real>("pre_exponential_factor")),
  _exponent(getParam<Real>("exponent")),
  _arrhenius(getParam<Real>("Arrhenius"))
{
  /* empty */
}

Real
RedbackFlowLawDislocation::value(Real sig_eqv, Real pressure, Real q_yield_stress,
                                 Real p_yield_stress, Real /*yield_stress*/, unsigned int qp, Real dt) const
{
   Real exponential = RedbackFlowLawBase::computeExponentialTemperature(qp, _arrhenius);

  // TODO: exponential to include all terms: temperature, grain size, damage, pore collapse...
  // TODO: hardcoded for Drucker Prager, with negative slope.

  Real flow_incr_vol =
    _pre_exponential_factor * dt *
    std::pow(Utils::macaulayBracket(pressure - p_yield_stress), _exponent) *
    exponential;

  Real flow_incr_dev =
    _pre_exponential_factor * dt *
    std::pow(Utils::macaulayBracket(sig_eqv - q_yield_stress), _exponent) *
    exponential;
  return std::pow(flow_incr_vol * flow_incr_vol + flow_incr_dev * flow_incr_dev, 0.5);
}

Real
RedbackFlowLawDislocation::derivative_p(Real sig_eqv, Real pressure, Real q_yield_stress,
                                        Real p_yield_stress, const RankTwoTensor & /*sig*/,
                                        unsigned int qp, Real /*dt*/) const
{
  Real exponential = RedbackFlowLawBase::computeExponentialTemperature(qp, _arrhenius);
  Real p_term = Utils::macaulayBracket(pressure - p_yield_stress);
  Real q_term = Utils::macaulayBracket(sig_eqv - q_yield_stress);
  Real der_flow_incr_vol = _pre_exponential_factor * _dt * _exponent *
    std::pow(p_term,2*_exponent-1) *
    exponential / std::sqrt(std::pow(p_term,2*_exponent) + std::pow(q_term,2*_exponent));
  return der_flow_incr_vol;
}

Real
RedbackFlowLawDislocation::derivative_q(Real sig_eqv, Real pressure, Real q_yield_stress,
                                        Real p_yield_stress, const RankTwoTensor & /*sig*/,
                                        unsigned int qp, Real /*dt*/) const
{
  Real exponential = RedbackFlowLawBase::computeExponentialTemperature(qp, _arrhenius);
  Real p_term = Utils::macaulayBracket(pressure - p_yield_stress);
  Real q_term = Utils::macaulayBracket(sig_eqv - q_yield_stress);
  Real der_flow_incr_dev = _pre_exponential_factor * _dt * _exponent *
    std::pow(q_term,2*_exponent-1) *
    exponential / std::sqrt(std::pow(p_term,2*_exponent) + std::pow(q_term,2*_exponent));
  return der_flow_incr_dev;
}

Real
RedbackFlowLawDislocation::getPreExponentialFactor() const
{
  return _pre_exponential_factor;
}

Real
RedbackFlowLawDislocation::getArrhenius() const
{
  return _arrhenius;
}

Real
RedbackFlowLawDislocation::getStressExponent() const
{
  return _exponent;
}
