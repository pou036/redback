/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*                 (c) 2019 CSIRO                               */
/*               ALL RIGHTS RESERVED                            */
/*                                                              */
/*                Prepared by CSIRO                             */
/*                                                              */
/*        See COPYRIGHT for full restrictions                   */
/****************************************************************/
// Kernel for the term (\nabla.(b \tilde{u}-\kappa\nabla \tilde{u}),v)

#include "DPGmypb21T.h"

registerMooseObject("RedbackApp", DPGmypb21T);

template <>
InputParameters
validParams<DPGmypb21T>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  params.addRequiredCoupledVar("velocity_x", "X component of velocity AuxVariable");
  params.addCoupledVar("velocity_y", 0.0, "Y component of velocity AuxVariable");
  params.addCoupledVar("velocity_z", 0.0, "Z component of velocity AuxVariable");
  params.addRequiredCoupledVar("kappa", "Diffusivity AuxVariable");
  return params;
}

DPGmypb21T::DPGmypb21T(const InputParameters & parameters):
  Kernel(parameters),
  _is_vel_y_coupled(isCoupled("velocity_y")),
  _is_vel_z_coupled(isCoupled("velocity_z")),
  _coupled_variable(coupledValue("coupled_variable")),
  _k_var(coupled("coupled_variable")),
  _phi_coupled_variable(_assembly.phi(*getVar("coupled_variable",0))),
  _vel_x(coupledValue("velocity_x")),
  _vel_y(coupledValue("velocity_y")),
  _vel_z(coupledValue("velocity_z")),
  _grad_vel_x(coupledGradient("velocity_x")),
  _grad_vel_y(coupledGradient("velocity_y")),
  _grad_vel_z(coupledGradient("velocity_z")),
  _kappa(coupledValue("kappa")),
  _grad_kappa(coupledGradient("kappa")),
  _second_test(secondTest())
{
}

Real
DPGmypb21T::computeQpResidual()
{
  Real div_vel = _grad_vel_x[_qp](0);
  Real vel_dot_grad_test = _vel_x[_qp] * _grad_test[_i][_qp](0);
  if (_is_vel_y_coupled)
  {
    div_vel += _grad_vel_y[_qp](1);
    vel_dot_grad_test += _vel_y[_qp] * _grad_test[_i][_qp](1);
  }
  if (_is_vel_z_coupled)
  {
    div_vel += _grad_vel_z[_qp](2);
    vel_dot_grad_test += _vel_z[_qp] * _grad_test[_i][_qp](2);
  }
  return (_test[_i][_qp] * div_vel + vel_dot_grad_test
    - _kappa[_qp] * _second_test[_i][_qp].tr()
    - _grad_test[_i][_qp] * _grad_kappa[_qp]) * _coupled_variable[_qp];
}

Real
DPGmypb21T::computeQpJacobian()
{
  return 0;
}


Real
DPGmypb21T::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _k_var)
  {
    Real div_vel = _grad_vel_x[_qp](0);
    Real vel_dot_grad_test = _vel_x[_qp] * _grad_test[_i][_qp](0);
    if (_is_vel_y_coupled)
    {
      div_vel += _grad_vel_y[_qp](1);
      vel_dot_grad_test += _vel_y[_qp] * _grad_test[_i][_qp](1);
    }
    if (_is_vel_z_coupled)
    {
      div_vel += _grad_vel_z[_qp](2);
      vel_dot_grad_test += _vel_z[_qp] * _grad_test[_i][_qp](2);
    }
    return (_test[_i][_qp] * div_vel + vel_dot_grad_test
      - _kappa[_qp] * _second_test[_i][_qp].tr()
      - _grad_test[_i][_qp] * _grad_kappa[_qp]) * _phi_coupled_variable[_j][_qp];
  }
  return 0;
}
