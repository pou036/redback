#include "RedbackFlowLawBase.h"
#include "RedbackFlowLawDislocation.h"
#include "Utils.h"
#include <math.h> // for M_PI

template <>
InputParameters
validParams<RedbackFlowLawDislocation>()
{
  InputParameters params = validParams<RedbackFlowLawDislocation>();
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
                                 Real p_yield_stress, Real yield_stress, unsigned int qp, Real dt) const
{
   Real exponential = RedbackFlowLawBase::computeExponentialTemperature(qp, _arrhenius);

   // TODO: exponential to include all terms: temperature, grain size, damage, pore collapse...


  Real flow_incr_vol =
    _pre_exponential_factor * dt * std::pow(Utils::macaulayBracket(pressure - p_yield_stress), _exponent) * exponential;
  // TODO: q_yield_stress can be 0, we should handle that case properly...
  Real flow_incr_dev =
    _pre_exponential_factor * dt *
    std::pow(Utils::macaulayBracket((q_yield_stress > 0 ? 1 : -1) * (sig_eqv / q_yield_stress - 1.0)), _exponent) *
    exponential;
  //(q_yield_stress > 0 ? 1:-1) is the sign function
  return std::pow(flow_incr_vol * flow_incr_vol + flow_incr_dev * flow_incr_dev, 0.5);
}


Real
RedbackFlowLawDislocation::derivative(Real sig_eqv, Real pressure, Real q_yield_stress,
                                      Real p_yield_stress, const RankTwoTensor & sig,
                                      unsigned int qp, Real dt) const
{
  Real exponential = RedbackFlowLawBase::computeExponentialTemperature(qp, _arrhenius);

  // TODO: exponential to include all terms: temperature, grain size, damage, pore collapse...

  Real delta_lambda_p =
    _pre_exponential_factor * _dt * std::pow(Utils::macaulayBracket(pressure - p_yield_stress),
        _exponent) * exponential;
  Real delta_lambda_q =
    _pre_exponential_factor * _dt *
    std::pow(Utils::macaulayBracket((q_yield_stress > 0 ? 1 : -1) * (sig_eqv / q_yield_stress - 1.0)),
        _exponent) * exponential;
  Real delta_lambda = (std::pow(delta_lambda_p * delta_lambda_p + delta_lambda_q * delta_lambda_q, 0.5));
  //Real delta_lambda = value(sig_eqv, pressure, q_yield_stress, p_yield_stress, 0, qp, dt);
  Real der_flow_incr_dev =
    _pre_exponential_factor * dt * _exponent *
    std::pow(Utils::macaulayBracket((q_yield_stress > 0 ? 1 : -1) * (sig_eqv / q_yield_stress - 1.0)),
        _exponent - 1.0) * exponential / q_yield_stress;
  Real der_flow_incr_vol = _pre_exponential_factor * _dt * _exponent *
    std::pow(Utils::macaulayBracket(pressure - p_yield_stress), _exponent - 1.0) * exponential;
  return (delta_lambda_q * der_flow_incr_dev + delta_lambda_p * der_flow_incr_vol) / delta_lambda;
}

/*Real
RedbackFlowLawDislocation::Utils::macaulayBracket(Real val) const
{
  if (val > 0.0)
    return val;
  else
    return 0.0;
}
*/
