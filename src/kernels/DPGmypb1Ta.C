// Kernel for the term (-\kappa\nabla \tilde{u} + b \tilde{u},\tau)

#include "DPGmypb1Ta.h"

//registerMooseObject("RedbackApp", DPGmypb1Ta);

template <>
InputParameters
validParams<DPGmypb1Ta>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("coupled_variable_x", "Component x of vector variable");
  params.addCoupledVar("coupled_variable_y", "Component y of vector variable");
  params.addCoupledVar("coupled_variable_z", "Component z of vector variable");
  return params;
}

DPGmypb1Ta::DPGmypb1Ta(const InputParameters & parameters):
  Kernel(parameters),
  _is_y_coupled(isCoupled("coupled_variable_y")),
  _is_z_coupled(isCoupled("coupled_variable_z")),
  _x_var(coupled("coupled_variable_x")),
  _y_var(coupled("coupled_variable_y")),
  _z_var(coupled("coupled_variable_z")),
  _coupled_var_x(coupledValue("coupled_variable_x")),
  _coupled_var_y(_is_y_coupled ? coupledValue("coupled_variable_y") : _zero),
  _coupled_var_z(_is_z_coupled ? coupledValue("coupled_variable_z") : _zero),
  _kappa(getMaterialProperty<Real>("kappa")),
  _vel_x(getMaterialProperty<Real>("velocity_x")),
  _vel_y(getMaterialProperty<Real>("velocity_y")),
  _vel_z(getMaterialProperty<Real>("velocity_z")),
  _phi_x(_assembly.phi(*getVar("coupled_variable_x",0))),
  _phi_y(_is_y_coupled ? _assembly.phi(*getVar("coupled_variable_y",0)) : _phi_zero),
  _phi_z(_is_z_coupled ? _assembly.phi(*getVar("coupled_variable_z",0)) : _phi_zero)
{
}

Real
DPGmypb1Ta::computeQpResidual()
{
  Real residual = _coupled_var_x[_qp]*(-_kappa[_qp]*_grad_test[_i][_qp](0) + _vel_x[_qp]*_test[_i][_qp]);
  if (_is_y_coupled)
    residual += _coupled_var_y[_qp]*(-_kappa[_qp]*_grad_test[_i][_qp](1) + _vel_y[_qp]*_test[_i][_qp]);
  if (_is_z_coupled)
    residual += _coupled_var_z[_qp]*(-_kappa[_qp]*_grad_test[_i][_qp](2) + _vel_z[_qp]*_test[_i][_qp]);
  return residual;
}

Real
DPGmypb1Ta::computeQpJacobian()
{
  return 0;
}

Real
DPGmypb1Ta::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _x_var)
  {
    return _phi_x[_j][_qp]*(-_kappa[_qp]*_grad_test[_i][_qp](0) + _vel_x[_qp]*_test[_i][_qp]);
  }
  else if (jvar == _y_var)
  {
    return _phi_y[_j][_qp]*(-_kappa[_qp]*_grad_test[_i][_qp](1) + _vel_y[_qp]*_test[_i][_qp]);
  }
  else if (jvar == _z_var)
  {
    return _phi_z[_j][_qp]*(-_kappa[_qp]*_grad_test[_i][_qp](2) + _vel_z[_qp]*_test[_i][_qp]);
  }
  return 0;
}
