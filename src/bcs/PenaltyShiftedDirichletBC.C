//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "PenaltyShiftedDirichletBC.h"

registerMooseObject("MooseApp", PenaltyShiftedDirichletBC);

defineLegacyParams(PenaltyShiftedDirichletBC);

InputParameters
PenaltyShiftedDirichletBC::validParams()
{
  InputParameters params = IntegratedBC::validParams();
  params.addClassDescription("Enforces a Dirichlet boundary condition "
                             "in a weak sense by penalizing differences between the current "
                             "solution and the Dirichlet data.");
  params.addParam<Real>("penalty", 1.0, "Penalty scalar");
  params.addParam<Real>("mesh_resolution", 1.0, "size of one element");
  params.addParam<Real>("value", 0.0, "Boundary value of the variable");
  params.addCoupledVar("distance", 0.0, "distance to interface");
  params.declareControllable("value");
  return params;
}

PenaltyShiftedDirichletBC::PenaltyShiftedDirichletBC(const InputParameters & parameters)
  : IntegratedBC(parameters),
  _p(getParam<Real>("penalty")),
  _size(getParam<Real>("mesh_resolution")),
  _v(getParam<Real>("value")),
  _d_to_stl(coupledVectorValue("distance"))
{
}

Real
PenaltyShiftedDirichletBC::computeQpResidual()
{
  //const Real size = 0.5 * _current_elem->hmax();
  return _p/_size * (_test[_i][_qp] + _grad_test[_i][_qp] * _d_to_stl[_qp]) * (-_v + _u[_qp] + _grad_u[_qp] * _d_to_stl[_qp]) - _grad_u[_qp] * _normals[_qp] * _test[_i][_qp];
}

Real
PenaltyShiftedDirichletBC::computeQpJacobian()
{
  //const Real size = 0.5 * _current_elem->hmax();
  return _p/_size * (_test[_i][_qp] + _grad_test[_i][_qp] * _d_to_stl[_qp]) * (_phi[_j][_qp] + _grad_phi[_j][_qp] * _d_to_stl[_qp]) - _grad_phi[_j][_qp] * _normals[_qp] * _test[_i][_qp];
}
