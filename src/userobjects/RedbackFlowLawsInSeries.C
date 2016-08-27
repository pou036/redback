#include "RedbackFlowLawBase.h"
#include "RedbackFlowLawsInSeries.h"

template <>
InputParameters
validParams<RedbackFlowLawsInSeries>()
{
  InputParameters params = validParams<RedbackFlowLawBase>();
  params.addRequiredParam<std::vector<UserObjectName> >("flow_law_user_objects", "List of names of user objects that define the flow laws to use in series");

  return params;
}

RedbackFlowLawsInSeries::RedbackFlowLawsInSeries(const InputParameters& parameters) :
    RedbackFlowLawBase(parameters),
    _num_flow_law_uos(getParam<std::vector<UserObjectName> >("flow_law_user_objects").size())
{
  // UserObject flow laws
  if (_num_flow_law_uos == 0)
    mooseError("Specify at least one flow law user object to use in series");

  _flow_laws_uo.resize(_num_flow_law_uos);
  for (unsigned int i = 0; i < _num_flow_law_uos; ++i)
  {
    _flow_laws_uo[i] = &getUserObjectByName<RedbackFlowLawBase>(parameters.get< std::vector<UserObjectName> >("flow_law_user_objects")[i]);
  }
}

Real
RedbackFlowLawsInSeries::value(Real sig_eqv, Real pressure, Real q_yield_stress,
                                 Real p_yield_stress, Real yield_stress, unsigned int qp, Real dt) const
{
  Real val = 0.;
  for (unsigned int i = 0; i < _num_flow_law_uos; ++i)
  {
    val = val + _flow_laws_uo[i]->value(sig_eqv, pressure, q_yield_stress, p_yield_stress, yield_stress, qp, dt);
  }
  return val;
}


Real
RedbackFlowLawsInSeries::derivative(Real sig_eqv, Real pressure, Real q_yield_stress,
                                      Real p_yield_stress, const RankTwoTensor & sig,
                                      unsigned int qp, Real dt) const
{
  Real der = 0.;
  for (unsigned int i = 0; i < _num_flow_law_uos; ++i)
  {
    der = der + _flow_laws_uo[i]->derivative(sig_eqv, pressure, q_yield_stress, p_yield_stress, sig, qp, dt);
  }
  return der;
}
