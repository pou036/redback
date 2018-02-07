#include "RedbackFlowLawBase.h"
#include <math.h> // for M_PI

template <>
InputParameters
validParams<RedbackFlowLawBase>()
{
  InputParameters params = validParams<DiscreteElementUserObject>();
  params.addCoupledVar("temperature", 0.0, "temperature variable");
  params.addParam<Real>("delta", 1, "Kamenetskii coefficient (if temperature involved)");

  return params;
}

RedbackFlowLawBase::RedbackFlowLawBase(const InputParameters& parameters) :
DiscreteElementUserObject(parameters),
  _has_T(isCoupled("temperature")),
  _T(_has_T ? coupledValue("temperature") : _zero),
  _delta_param(getParam<Real>("delta"))
{
 /* empty */
}

Real
RedbackFlowLawBase::computeExponentialTemperature(unsigned int qp, Real arrhenius) const
{
  // calculate the term exponential = -Q/(RT)
  Real exponential = 1;
  if (_has_T)
  {
    // E_0/(RT) = Ar/(1+delta T*)
    exponential =
      /*std::exp(-arrhenius) * */ std::exp(arrhenius * _delta_param * _T[ qp ] / (1 + _delta_param * _T[ qp ]));
  }
  return exponential;
}
