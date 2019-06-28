/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2018 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/
// Kernel for the term (-\nabla.\sigma,\tilde{w})

#include "DPG3.h"
#include "Assembly.h"

registerMooseObject("RedbackApp", DPG3);

template <>
InputParameters
validParams<DPG3>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("coupled_variable_x", "X component of coupled variable");
  params.addCoupledVar("coupled_variable_y", "Y component of coupled variable");
  params.addCoupledVar("coupled_variable_z", "Z component of coupled variable");
  return params;
}

DPG3::DPG3(const InputParameters & parameters):
  Kernel(parameters),
  _is_x_coupled(isCoupled("coupled_variable_x")),
  _is_y_coupled(isCoupled("coupled_variable_y")),
  _is_z_coupled(isCoupled("coupled_variable_z")),
  _x_var(coupled("coupled_variable_x")),
  _y_var(coupled("coupled_variable_y")),
  _z_var(coupled("coupled_variable_z")),
  _grad_coupled_var_x(coupledGradient("coupled_variable_x")),
  _grad_coupled_var_y(coupledGradient("coupled_variable_y")),
  _grad_coupled_var_z(coupledGradient("coupled_variable_z")),
  _grad_phi_x(_assembly.gradPhi(*getVar("coupled_variable_x",0))),
  //_grad_phi_x(_assembly.feGradPhi<Real>(getVar("coupled_variable_x", 0)->feType())),
  _grad_phi_y(_is_y_coupled ? _assembly.gradPhi(*getVar("coupled_variable_y",0)) : _grad_phi_zero),
  _grad_phi_z(_is_z_coupled ? _assembly.gradPhi(*getVar("coupled_variable_z",0)) : _grad_phi_zero)
{
}

Real
DPG3::computeQpResidual()
{
  Real div = _grad_coupled_var_x[_qp](0);
  if (_is_y_coupled)
    div += _grad_coupled_var_y[_qp](1);
  if (_is_z_coupled)
    div += _grad_coupled_var_z[_qp](2);
  return -div * _test[_i][_qp];
}

Real
DPG3::computeQpJacobian()
{
  return 0;
}

Real
DPG3::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _x_var)
  {
    return -_grad_phi_x[_j][_qp](0) * _test[_i][_qp];
  }
  else if (jvar == _y_var)
  {
    return -_grad_phi_y[_j][_qp](1) * _test[_i][_qp];
  }
  else if (jvar == _z_var)
  {
    return -_grad_phi_z[_j][_qp](2) * _test[_i][_qp];
  }
  return 0;
}
