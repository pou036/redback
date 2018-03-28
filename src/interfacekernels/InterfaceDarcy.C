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
  params.addRequiredCoupledVar("fault_lewis_number", "Lewis number of the fault.");
  params.addParam<Real>("fault_thickness", 1., "The neighboring diffusion coefficient.");
  return params;
}

InterfaceDarcy::InterfaceDarcy(const InputParameters & parameters) :
    InterfaceKernel(parameters),
    _Le(getMaterialProperty<Real>("lewis_number")),
    _Le_fault(coupledValue("fault_lewis_number")),
    _gravity_term(getMaterialProperty<RealVectorValue>("fluid_gravity_term")),
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
  Real res = (_neighbor_value[ _qp ] - _u[ _qp ]) / (_Le_fault[ _qp ] * _thickness) +
           _gravity_term[ _qp ] * _normals[ _qp ] * (1 / _Le[ _qp ] - 1 / _Le_fault[ _qp ]);
  // RealVectorValue res = (_neighbor_value[ _qp ] - _u[ _qp ]) / (_Le_fault[ _qp ] * _thickness) * _normals[ _qp ] +
  //            _gravity_term[ _qp ] * (1 / _Le[ _qp ] - 1 / _Le_fault[ _qp ]);

  Real res2 = res - _grad_u[ _qp ] * _normals[ _qp ] / _Le[ _qp ];
  Real res3 = res - _grad_neighbor_value[ _qp ] * _normals[ _qp ] / _Le[ _qp ];

  switch (type)
  {
    case Moose::Element:
      return (res - _grad_u[ _qp ] * _normals[ _qp ] / _Le[ _qp ]) * _test[ _i ][ _qp ];
      // return (_grad_u[ _qp ] / _Le[ _qp ] - res) * _grad_test[ _i ][ _qp ];

    case Moose::Neighbor:
      return (res - _grad_neighbor_value[ _qp ] * _normals[ _qp ] / _Le[ _qp ]) * _test_neighbor[ _i ][ _qp ];
      // return (_grad_neighbor_value[ _qp ] / _Le[ _qp ] - res) * _grad_test_neighbor[ _i ][ _qp ];

    default:
      mooseError("InterfaceDarcy type not supported.");
  }
}

Real
InterfaceDarcy::computeQpJacobian(Moose::DGJacobianType /*type*/)
{
  return 0;
}
