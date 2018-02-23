//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "InterfaceDarcy.h"
#include "MooseVariable.h"

#include <cmath>

template <>
InputParameters
validParams<InterfaceDarcy>()
{
  InputParameters params = validParams<InterfaceKernel>();
  params.addParam<Real>("fault_permeability", 1., "The diffusion coefficient.");
  params.addParam<Real>("fault_thickness", 1., "The neighboring diffusion coefficient.");
  return params;
}

InterfaceDarcy::InterfaceDarcy(const InputParameters & parameters)
  : InterfaceKernel(parameters),
    _u_dot(_var.uDot()),
    _neighbor_dot(_neighbor_var.uDot()),
    _permeability(getParam<Real>("fault_permeability")),
    _thickness(getParam<Real>("fault_thickness"))
{
  if (!parameters.isParamValid("boundary"))
  {
    mooseError("In order to use the InterfaceDarcy dgkernel, you must specify a boundary where "
               "it will live.");
  }
}

Real
InterfaceDarcy::computeQpResidual(Moose::DGResidualType type)
{
  Real r = _permeability * (_u[_qp] - _neighbor_value[_qp]) / _thickness;
  // 0.5 * (-_D * _grad_u[_qp] * _normals[_qp] +
  //                 -_D_neighbor * _grad_neighbor_value[_qp] * _normals[_qp]);

  switch (type)
  {
    case Moose::Element:
      r += _u_dot[_qp];
      r *= _test[_i][_qp];
      break;

    case Moose::Neighbor:
      r -= _neighbor_dot[_qp];
      r *= _test_neighbor[_i][_qp];
      break;
  }

  return r;
}

Real
InterfaceDarcy::computeQpJacobian(Moose::DGJacobianType type)
{
  Real jac = 0;

  // switch (type)
  // {
  //
  //   case Moose::ElementElement:
  //     jac -= 0.5 * _D * _grad_phi[_j][_qp] * _normals[_qp] * _test[_i][_qp];
  //     break;
  //
  //   case Moose::NeighborNeighbor:
  //     jac +=
  //         0.5 * _D_neighbor * _grad_phi_neighbor[_j][_qp] * _normals[_qp] * _test_neighbor[_i][_qp];
  //     break;
  //
  //   case Moose::NeighborElement:
  //     jac += 0.5 * _D * _grad_phi[_j][_qp] * _normals[_qp] * _test_neighbor[_i][_qp];
  //     break;
  //
  //   case Moose::ElementNeighbor:
  //     jac -= 0.5 * _D_neighbor * _grad_phi_neighbor[_j][_qp] * _normals[_qp] * _test[_i][_qp];
  //     break;
  // }

  return jac;
}
