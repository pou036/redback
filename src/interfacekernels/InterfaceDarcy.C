/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "InterfaceDarcy.h"
#include "MooseVariable.h"

#include <cmath>

registerMooseObject("RedbackApp", InterfaceDarcy);

template <>
InputParameters
validParams<InterfaceDarcy>()
{
  InputParameters params = validParams<InterfaceKernel>();
  params.addParam<Real>("fault_lewis_number", 1., "The diffusion coefficient.");
  params.addParam<Real>("fault_thickness", 1., "The neighboring diffusion coefficient.");
  return params;
}

InterfaceDarcy::InterfaceDarcy(const InputParameters & parameters)
  : InterfaceKernel(parameters),
    _Le(getMaterialProperty<Real>("lewis_number")),
    _Le_fault(getParam<Real>("fault_lewis_number")),
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
  Real res = (_neighbor_value[_qp] - _u[_qp]) / (_Le_fault * _thickness) +
             _gravity_term[_qp] * _normals[_qp] * (1 / _Le[_qp] - 1 / _Le_fault);

  switch (type)
  {
    case Moose::Element:
      return (res - _grad_u[_qp] * _normals[_qp] / _Le[_qp]) * _test[_i][_qp];

    case Moose::Neighbor:
      return (res - _grad_neighbor_value[_qp] * _normals[_qp] / _Le[_qp]) * _test_neighbor[_i][_qp];

    default:
      mooseError("InterfaceDarcy type not supported.");
  }
}

Real InterfaceDarcy::computeQpJacobian(Moose::DGJacobianType /*type*/) { return 0; }
