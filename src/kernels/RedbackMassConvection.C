#include "RedbackMassConvection.h"


template<>
InputParameters validParams<RedbackMassConvection>()
{
  InputParameters params = validParams<Kernel>();
  params.addCoupledVar("temperature", "Temperature variable.");
  return params;
}

RedbackMassConvection::RedbackMassConvection(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _grad_temp(coupledGradient("temperature")),
  //_dtemp_dot_dtemp(coupledDotDu("temperature")),

  _pressure_convective_mass(getMaterialProperty<RealVectorValue>("pressure_convective_mass")),
  _pressure_convective_mass_jac(getMaterialProperty<RealVectorValue>("pressure_convective_mass_jacobian")),
  _thermal_convective_mass(getMaterialProperty<RealVectorValue>("thermal_convective_mass")),
  _thermal_convective_mass_jac(getMaterialProperty<RealVectorValue>("thermal_convective_mass_jacobian"))
{}


Real
RedbackMassConvection::computeQpResidual()
{
  return _test[_i][_qp] * (_pressure_convective_mass[_qp] * _grad_u[_qp]
    - _thermal_convective_mass[_qp] * _grad_temp[_qp]); // scalar product done by "*"
}

Real
RedbackMassConvection::computeQpJacobian()
{
  return _test[_i][_qp] * (_pressure_convective_mass[_qp]
    + _pressure_convective_mass_jac[_qp] - _thermal_convective_mass_jac[_qp]) * _grad_phi[_j][_qp] ;
}
