// Flow law for grain size insensitive material
#include "RedbackFlowLawGSI.h"

template<>
InputParameters validParams<RedbackFlowLawGSI>()
{
  InputParameters params = validParams<RedbackFlowLaw>();
  params.addRequiredParam<Real>("A", "Pre-exponential factor");
  params.addRequiredParam<Real>("Ar", "Arrhenius term = Q*(RT_{ref})");
  params.addRequiredParam<Real>("n", "Stress exponent");
  params.addClassDescription("Flow law for grain size independent material. epsilon_dot = A * sigma^n * exp(-Ar/(1+delta*T))");
  return params;
}

RedbackFlowLawGSI::RedbackFlowLawGSI(const InputParameters parameters) :
    RedbackFlowLaw(parameters),
    _A(getParam<Real>("A")),
    _Ar(getParam<Real>("Ar")),
    _n(getParam<Real>("n"))
{}


Real
RedbackFlowLawGSI::strainRate(Real sigma, Real T, Real delta, Real d) const
{
  return _A*std::pow(sigma, _n)*std::exp(-_Ar / (1 + delta*T));
}

Real
RedbackFlowLawGSI::dStrainRatedSigma(Real sigma, Real T, Real delta, Real d) const
{
  return _A*_n*std::pow(sigma, _n-1)*std::exp(-_Ar / (1 + delta*T));
}

// DEPRECATED CONSTRUCTOR
RedbackFlowLawGSI::RedbackFlowLawGSI(const std::string & deprecated_name, InputParameters parameters) :
    RedbackFlowLaw(parameters),
    _A(getParam<Real>("A")),
    _Ar(getParam<Real>("Ar")),
    _n(getParam<Real>("n"))
{}
