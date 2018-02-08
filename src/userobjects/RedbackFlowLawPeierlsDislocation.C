#include "RedbackFlowLawBase.h"
#include "RedbackFlowLawDislocation.h"
#include "RedbackFlowLawPeierlsDislocation.h"
#include "Utils.h"
#include <math.h> // for M_PI

template <>
InputParameters
validParams<RedbackFlowLawPeierlsDislocation>()
{
  InputParameters params = validParams<RedbackFlowLawDislocation>();
  params.addCoupledVar("temperature", 0.0, "temperature variable");
  params.addCoupledVar("grain_size", 0.0, "grain size aux variable");
  params.addParam<Real>("pre_exponential_factor", 1.0, "Value of pre-exponential factor.");
  params.addParam<Real>("exponent", 2.0, "Exponent for rate dependent plasticity (Perzyna)");
  params.addParam<Real>("Arrhenius", 1.0, "Value of Arrhenius coefficient.");
  //Peierls Stress params
  params.addParam<Real>("Peierls_grain_size_exponent", -0.5, "Exponent for grain size in the Peierls stress calc");
  params.addParam<Real>("Sigma_p", 1.0, "Value of Peierls coefficient.");
  params.addParam<Real>("K_p", 1.0, "Value of backstress coefficient.");
  params.addParam<Real>("T_m", 1.0, "Value of melting temperature.");

  return params;
}

RedbackFlowLawPeierlsDislocation::RedbackFlowLawPeierlsDislocation(const InputParameters& parameters) :
    RedbackFlowLawDislocation(parameters),
    _has_T(isCoupled("temperature")),
    _T(_has_T ? coupledValue("temperature") : _zero),
    _has_grain_size(isCoupled("grain_size")),
    _grain_size(_has_grain_size ? coupledValue("grain_size") : _zero),
    _pre_exponential_factor(getParam<Real>("pre_exponential_factor")),
    _exponent(getParam<Real>("exponent")),
    _arrhenius(getParam<Real>("Arrhenius")),

    _peierls_grain_exponent(getParam<Real>("Peierls_grain_size_exponent")),
    _Sigma_p(getParam<Real>("Sigma_p")),
    _K_p(getParam<Real>("K_p")),
    _T_m(getParam<Real>("T_m"))
{
  /* empty */
}

Real
RedbackFlowLawPeierlsDislocation::value(Real sig_eqv, Real pressure, Real q_yield_stress,
                                 Real p_yield_stress, Real /*yield_stress*/, unsigned int qp, Real dt) const
{
  // define Peierls Stress for calculation
  Real peierls_stress =
    (_Sigma_p + _K_p * std::pow(_grain_size[qp],_peierls_grain_exponent)) * (_T_m - _T[ qp ]);

   Real exponential = RedbackFlowLawBase::computeExponentialTemperature(qp, _arrhenius);

   // TODO: exponential to include all terms: temperature, grain size, damage, pore collapse...


  Real flow_incr_vol =
    _pre_exponential_factor * dt * std::pow(Utils::macaulayBracket(pressure - p_yield_stress), _exponent) *
    std::exp(Utils::macaulayBracket(pressure - p_yield_stress)/peierls_stress) * exponential;
  // TODO: q_yield_stress can be 0, we should handle that case properly...
  Real flow_incr_dev =
    _pre_exponential_factor * dt *
    std::pow(Utils::macaulayBracket((q_yield_stress > 0 ? 1 : -1) * (sig_eqv / q_yield_stress - 1.0)), _exponent) *
    std::exp(Utils::macaulayBracket((q_yield_stress > 0 ? 1 : -1) * (sig_eqv / q_yield_stress - 1.0))/peierls_stress) *
    exponential;
  //(q_yield_stress > 0 ? 1:-1) is the sign function
  return std::pow(flow_incr_vol * flow_incr_vol + flow_incr_dev * flow_incr_dev, 0.5);
}

Real
RedbackFlowLawPeierlsDislocation::derivative_p(Real sig_eqv, Real pressure, Real q_yield_stress,
                                        Real p_yield_stress, const RankTwoTensor & /*sig*/,
                                        unsigned int qp, Real /*dt*/) const
{
  Real peierls_stress =
    (_Sigma_p + _K_p * std::pow(_grain_size[qp],_peierls_grain_exponent)) * (_T_m - _T[ qp ]);
  Real exponential = RedbackFlowLawBase::computeExponentialTemperature(qp, _arrhenius);
  Real p_term = Utils::macaulayBracket(pressure - p_yield_stress);
  Real q_term = Utils::macaulayBracket(sig_eqv - q_yield_stress);

  Real der_flow_incr_vol = _pre_exponential_factor * _dt * (_exponent + p_term/peierls_stress) *
    std::pow(p_term,2*_exponent-1) * std::exp(2*p_term/peierls_stress) *
    exponential / std::sqrt(std::pow(p_term,2*_exponent) * std::exp(2*p_term/peierls_stress) + std::pow(q_term,2*_exponent) *
    std::exp(2*q_term/peierls_stress));
  return der_flow_incr_vol;
}

Real
RedbackFlowLawPeierlsDislocation::derivative_q(Real sig_eqv, Real pressure, Real q_yield_stress,
                                        Real p_yield_stress, const RankTwoTensor & /*sig*/,
                                        unsigned int qp, Real /*dt*/) const
{
  Real peierls_stress =
    (_Sigma_p + _K_p * std::pow(_grain_size[qp],_peierls_grain_exponent)) * (_T_m - _T[ qp ]);
  Real exponential = RedbackFlowLawBase::computeExponentialTemperature(qp, _arrhenius);
  Real p_term = Utils::macaulayBracket(pressure - p_yield_stress);
  Real q_term = Utils::macaulayBracket(sig_eqv - q_yield_stress);

  Real der_flow_incr_dev = _pre_exponential_factor * _dt * (_exponent + q_term/peierls_stress) *
    std::pow(q_term,2*_exponent-1) * std::exp(2*q_term/peierls_stress) *
    exponential / std::sqrt(std::pow(p_term,2*_exponent) * std::exp(2*p_term/peierls_stress) + std::pow(q_term,2*_exponent) *
    std::exp(2*q_term/peierls_stress));
  return der_flow_incr_dev;
}

Real
RedbackFlowLawPeierlsDislocation::getPreExponentialFactor() const
{
  return _pre_exponential_factor;
}

Real
RedbackFlowLawPeierlsDislocation::getArrhenius() const
{
  return _arrhenius;
}

Real
RedbackFlowLawPeierlsDislocation::getStressExponent() const
{
  return _exponent;
}
