// Kernel for the term
// (- \lambda(1+\tilde{u})^m e^{-\alpha\tilde{u}} + \mu e^{\beta\tilde{u}}, w)
#include "DPGmypb11T.h"

//registerMooseObject("RedbackApp", DPGmypb11T);

template <>
InputParameters
validParams<DPGmypb11T>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  return params;
}

DPGmypb11T::DPGmypb11T(const InputParameters & parameters):
  Kernel(parameters),
  _scalar_var(coupledValue("coupled_variable")),
  _coupled_var(coupled("coupled_variable")),
  _phi_var(_assembly.phi(*getVar("coupled_variable",0))),
  _lambda(getMaterialProperty<Real>("DPG_lambda")),
  _alpha_2(getMaterialProperty<Real>("alpha_2")),
  _m(getMaterialProperty<Real>("DPG_m")),
  _mu(getMaterialProperty<Real>("DPG_mu")),
  _beta(getMaterialProperty<Real>("DPG_beta"))
{
}

Real
DPGmypb11T::computeQpResidual()
{
  return -_scalar_var[_qp]*(
      - _lambda[_qp]*std::pow(1+_test[_i][_qp], _m[_qp])*std::exp(-_alpha_2[_qp]*_test[_i][_qp])
      + _mu[_qp]*std::exp(_beta[_qp]*_test[_i][_qp]));
}

Real
DPGmypb11T::computeQpJacobian()
{
  return 0;
}


Real
DPGmypb11T::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _coupled_var)
  {
    return -_phi_var[_j][_qp]*(
        - _lambda[_qp]*std::pow(1+_test[_i][_qp], _m[_qp])*std::exp(-_alpha_2[_qp]*_test[_i][_qp])
        + _mu[_qp]*std::exp(_beta[_qp]*_test[_i][_qp]));
  }
  return 0;
}
