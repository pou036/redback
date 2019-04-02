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
// Kernel for the term (\nabla.(b v-\kappa\nabla u),\tilde{u})

#include "DPGmypb21.h"

registerMooseObject("RedbackApp", DPGmypb21);

template <>
InputParameters
validParams<DPGmypb21>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  params.addRequiredCoupledVar("velocity_x", "X component of velocity AuxVariable");
  params.addCoupledVar("velocity_y", 0.0, "Y component of velocity AuxVariable");
  params.addCoupledVar("velocity_z", 0.0, "Z component of velocity AuxVariable");
  params.addRequiredCoupledVar("kappa", "Diffusivity AuxVariable");
  return params;
}

DPGmypb21::DPGmypb21(const InputParameters & parameters):
  Kernel(parameters),
  _is_vel_y_coupled(isCoupled("velocity_y")),
  _is_vel_z_coupled(isCoupled("velocity_z")),
  _coupled_variable(coupledValue("coupled_variable")),
  _k_var(coupled("coupled_variable")),
  _grad_coupled_variable(coupledGradient("coupled_variable")),
  _second_coupled_variable(coupledSecond("coupled_variable")),
  _phi_coupled_variable(_assembly.phi(*getVar("coupled_variable",0))),
  _grad_phi_cvariable(_assembly.gradPhi(*getVar("coupled_variable",0))),
  _second_phi_cvariable(_assembly.secondPhi(*getVar("coupled_variable",0))),
  _vel_x(coupledValue("velocity_x")),
  _vel_y(coupledValue("velocity_y")),
  _vel_z(coupledValue("velocity_z")),
  _grad_vel_x(coupledGradient("velocity_x")),
  _grad_vel_y(coupledGradient("velocity_y")),
  _grad_vel_z(coupledGradient("velocity_z")),
  _kappa(coupledValue("kappa")),
  _grad_kappa(coupledGradient("kappa"))
{
}

Real
DPGmypb21::computeQpResidual()
{
  Real div_vel = _grad_vel_x[_qp](0);
  Real vel_dot_grad_cvar = _vel_x[_qp] * _grad_coupled_variable[_qp](0);
  if (_is_vel_y_coupled)
  {
    div_vel += _grad_vel_y[_qp](1);
    vel_dot_grad_cvar += _vel_y[_qp] * _grad_coupled_variable[_qp](1);
  }
  if (_is_vel_z_coupled)
  {
    div_vel += _grad_vel_z[_qp](2);
    vel_dot_grad_cvar += _vel_z[_qp] * _grad_coupled_variable[_qp](2);
  }
  return (_coupled_variable[_qp] * div_vel + vel_dot_grad_cvar
    - _kappa[_qp] * _second_coupled_variable[_qp].tr()
    - _grad_coupled_variable[_qp] * _grad_kappa[_qp]) * _test[_i][_qp];
}

Real
DPGmypb21::computeQpJacobian()
{
  return 0;
}


Real
DPGmypb21::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _k_var)
  {
    Real div_vel = _grad_vel_x[_qp](0);
    Real vel_dot_grad_phi_cvar = _vel_x[_qp] * _grad_phi_cvariable[_j][_qp](0);
    if (_is_vel_y_coupled)
    {
      div_vel += _grad_vel_y[_qp](1);
      vel_dot_grad_phi_cvar += _vel_y[_qp] * _grad_phi_cvariable[_j][_qp](1);
    }
    if (_is_vel_z_coupled)
    {
      div_vel += _grad_vel_z[_qp](2);
      vel_dot_grad_phi_cvar += _vel_z[_qp] * _grad_phi_cvariable[_j][_qp](2);
    }
    return (_phi_coupled_variable[_j][_qp] * div_vel + vel_dot_grad_phi_cvar
        - _kappa[_qp] * _second_phi_cvariable[_j][_qp].tr()
        - _grad_phi_cvariable[_j][_qp] * _grad_kappa[_qp]) * _test[_i][_qp];
  }
  return 0;
}
