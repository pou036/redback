// Flow law for grain size sensitive material
#include "RedbackFlowLawPeierls.h"

template<>
InputParameters validParams<RedbackFlowLawPeierls>()
{
  InputParameters params = validParams<RedbackFlowLaw>();
  params.addRequiredParam<Real>("A", "Pre-exponential factor");
  params.addRequiredParam<Real>("Ar", "Arrhenius term = Q*(RT_{ref})");
  params.addRequiredParam<Real>("m", "Grain size exponent");
  params.addRequiredParam<Real>("n", "Stress exponent");
  params.addRequiredParam<Real>("Sigma_po", "constant in Peierls stress");
  params.addRequiredParam<Real>("K_p", "Constant mutliplying grain size in Peierls stress");
  params.addRequiredParam<Real>("T_m", "Reference temperature in Peierls stress");
  params.addClassDescription("Flow law for Peierl material. epsilon_dot = A * sigma^n *exp(sigma/sigma_p) * exp(-Ar/(1+delta*T)), with sigma_p = (Sigma_po + K_p*d^(-m))*(T_m-T)");
  return params;
}

RedbackFlowLawPeierls::RedbackFlowLawPeierls(const InputParameters parameters) :
    RedbackFlowLaw(parameters),
    _A(getParam<Real>("A")),
    _Ar(getParam<Real>("Ar")),
    _m(getParam<Real>("m")),
    _n(getParam<Real>("n")),
    _Sigma_po(getParam<Real>("Sigma_po")),
    _K_p(getParam<Real>("K_p")),
    _T_m(getParam<Real>("T_m"))
{}


Real
RedbackFlowLawPeierls::strainRate(Real sigma, Real T, Real delta, Real d) const
{
  Real sigma_p = (_Sigma_po + _K_p*std::pow(d, -_m))*(_T_m - T);
  return _A*std::pow(sigma, _n)*std::exp(sigma/sigma_p)*std::exp(-_Ar / (1 + delta*T));
}

Real
RedbackFlowLawPeierls::dStrainRatedSigma(Real sigma, Real T, Real delta, Real d) const
{
  Real sigma_p = (_Sigma_po + _K_p*std::pow(d, -_m))*(_T_m - T);
  return _A*_n*std::pow(sigma, _n-1)*std::exp(sigma/sigma_p)*std::exp(-_Ar / (1 + delta*T));
}

// DEPRECATED CONSTRUCTOR
RedbackFlowLawPeierls::RedbackFlowLawPeierls(const std::string & deprecated_name, InputParameters parameters) :
    RedbackFlowLaw(parameters),
    _A(getParam<Real>("A")),
    _Ar(getParam<Real>("Ar")),
    _m(getParam<Real>("m")),
    _n(getParam<Real>("n")),
    _Sigma_po(getParam<Real>("Sigma_po")),
    _K_p(getParam<Real>("K_p")),
    _T_m(getParam<Real>("T_m"))
{}
