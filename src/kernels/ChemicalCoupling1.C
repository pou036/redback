//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "ChemicalCoupling1.h"

registerMooseObject("RedbackApp", ChemicalCoupling1);

template <>
InputParameters
validParams<ChemicalCoupling1>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("c", "chemical concentration");
  params.addParam<Real>("beta","chemical coupling coefficient");
  return params;
}

ChemicalCoupling1::ChemicalCoupling1(const InputParameters & parameters)
  : Kernel(parameters),
    _beta(getParam<Real>("beta")),
    _c(coupledValue("c"))
{
}

Real
ChemicalCoupling1::computeQpResidual()
{
  return _test[_i][_qp] * 6 * _u[_qp] * (1 - _u[_qp]) * _beta * _c[_qp];
}

Real
ChemicalCoupling1::computeQpJacobian()
{
  return 0;
}
