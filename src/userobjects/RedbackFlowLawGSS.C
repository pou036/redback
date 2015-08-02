// Flow law for grain size sensitive material
#include "RedbackFlowLawGSS.h"

template<>
InputParameters validParams<RedbackFlowLawGSS>()
{
  InputParameters params = validParams<RedbackFlowLaw>();
  params.addRequiredParam<Real>("A", "Pre-exponential factor");
  params.addRequiredParam<Real>("Ar", "Arrhenius term = Q*(RT_{ref})");
  params.addRequiredParam<Real>("m", "Grain size exponent");
  params.addRequiredParam<Real>("n", "Stress exponent");
  params.addClassDescription("Flow law for grain size dependent material. epsilon_dot = A * sigma^n * d^m * exp(-Ar/(1+delta*T))");
  return params;
}

RedbackFlowLawGSS::RedbackFlowLawGSS(const InputParameters parameters) :
    RedbackFlowLaw(parameters),
    _A(getParam<Real>("A")),
    _Ar(getParam<Real>("Ar")),
    _m(getParam<Real>("m")),
    _n(getParam<Real>("n"))
{}


Real
RedbackFlowLawGSS::strainRate(Real sigma, Real T, Real delta, Real d) const
{
  return _A*std::pow(sigma, _n)*std::pow(d, _m)*std::exp(-_Ar / (1 + delta*T));
}

Real
RedbackFlowLawGSS::dStrainRatedSigma(Real sigma, Real T, Real delta, Real d) const
{
  return _A*_n*std::pow(sigma, _n-1)*std::pow(d, _m)*std::exp(-_Ar / (1 + delta*T));
}

// DEPRECATED CONSTRUCTOR
RedbackFlowLawGSS::RedbackFlowLawGSS(const std::string & deprecated_name, InputParameters parameters) :
    RedbackFlowLaw(parameters),
    _A(getParam<Real>("A")),
    _Ar(getParam<Real>("Ar")),
    _m(getParam<Real>("m")),
    _n(getParam<Real>("n"))
{}
