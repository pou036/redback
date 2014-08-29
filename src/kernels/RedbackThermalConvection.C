#include "RedbackThermalConvection.h"

template<>
InputParameters validParams<RedbackThermalConvection>()
{
  InputParameters params = validParams<Kernel>();
  return params;
}

RedbackThermalConvection::RedbackThermalConvection(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _mixture_convective_energy(getMaterialProperty<RealVectorValue>("mixture_convective_energy"))
  //_mixture_convective_energy_jac(getMaterialProperty<Real>("mixture_convective_energy_jacobian"))
{}


Real
RedbackThermalConvection::computeQpResidual()
{
  return _test[_i][_qp] * (_mixture_convective_energy[_qp] * _grad_u[_qp]); // scalar product done by "*"
}

Real
RedbackThermalConvection::computeQpJacobian()
{
  return _test[_i][_qp] * (_mixture_convective_energy[_qp] * _grad_phi[_j][_qp]);
}
