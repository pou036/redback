//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "InterfaceStress.h"
#include "RankTwoScalarTools.h"
#include "RankTwoTensor.h"
#include <cmath>

template <>
InputParameters
validParams<InterfaceStress>()
{
  InputParameters params = validParams<InterfaceKernel>();
  params.addRequiredParam<MaterialPropertyName>("stress_master", "The rank two material tensor name");
  params.addRequiredParam<MaterialPropertyName>("stress_slave", "The rank two material tensor name");
  params.addRequiredRangeCheckedParam<unsigned int>("component",
                                                    "component >= 0 & component <= 2",
                                                    "An integer corresponding to the direction the variable "
                                                    "this kernel acts in. (0 for x, 1 for y, 2 for z)");
  params.addCoupledVar("pressure_master", 0.0, "Dimensionless pore pressure");
  params.addCoupledVar("pressure_slave", 0.0, "Dimensionless pore pressure");
  return params;
}

InterfaceStress::InterfaceStress(const InputParameters & parameters)
  : InterfaceKernel(parameters),
    _stress0(getMaterialProperty<RankTwoTensor>("stress_master")),
    _stress1(getMaterialProperty<RankTwoTensor>("stress_slave")),
    _component(getParam<unsigned int>("component")),
    _has_pres0(isCoupled("pressure_master")),
    _pressure0(_has_pres0 ? coupledValue("pressure_master") : _zero),
    _has_pres1(isCoupled("pressure_slave")),
    _pressure1(_has_pres1 ? coupledValue("pressure_slave") : _zero)
{
  if (!parameters.isParamValid("boundary"))
  {
    mooseError("In order to use the InterfaceStress dgkernel, you must specify a boundary where "
               "it will live.");
  }
}

Real
InterfaceStress::computeQpResidual(Moose::DGResidualType type)
{
  // continuity of each component of traction: (sigma_ij' - p) . n_i
  RankTwoTensor stress = _stress0[ _qp ] - _stress1[ _qp ];
  stress.addIa( - _pressure0[ _qp ] + _pressure1[ _qp ]);
  RealVectorValue res = stress * _normals[ _qp ];

  switch (type)
  {
    case Moose::Element:
      return res(_component) * _test[ _i ][ _qp ];

    case Moose::Neighbor:
      return res(_component) * _test_neighbor[ _i ][ _qp ];

    default:
      mooseError("InterfaceStress type not supported.");
  }
}

Real
InterfaceStress::computeQpJacobian(Moose::DGJacobianType type)
{
  return 0;
}
