//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "ChemicalCoupling.h"

registerMooseObject("RedbackApp", ChemicalCoupling);

template <>
InputParameters
validParams<ChemicalCoupling>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("c", "chemical concentration");
  params.addParam<Real>("lambda","chemical coupling coefficient");
  return params;
}

ChemicalCoupling::ChemicalCoupling(const InputParameters & parameters)
  : Kernel(parameters),
    _lambda(getParam<Real>("lambda")),
    _c(coupledValue("c"))
{
}

Real
ChemicalCoupling::computeQpResidual()
{
  return _test[_i][_qp] * 6 * _u[_qp] * (1 - _u[_qp]) * _lambda * _c[_qp];
}

Real
ChemicalCoupling::computeQpJacobian()
{
  return 0;
}
