//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "ChemicalCoupling2a.h"

#include "MooseVariable.h"

registerMooseObject("MooseApp", ChemicalCoupling2a);

template <>
InputParameters
validParams<ChemicalCoupling2a>()
{
  InputParameters params = validParams<Kernel>();

  params.addClassDescription("Implements a source term proportional to the value of a coupled "
                             "variable. Weak form: $(\\psi_i, -\\sigma v)$.");
  params.addRequiredCoupledVar("v", "The coupled variable which provides the force");
  params.addParam<Real>(
      "coef", 1.0, "Coefficent ($\\sigma$) multiplier for the coupled force term.");

  return params;
}

ChemicalCoupling2a::ChemicalCoupling2a(const InputParameters & parameters)
  : Kernel(parameters), _v_var(coupled("v")), _v(coupledValue("v")), _coef(getParam<Real>("coef"))
{
  if (_var.number() == _v_var)
    mooseError("Coupled variable 'v' needs to be different from 'variable' with ChemicalCoupling2a, "
               "consider using Reaction or somethig similar");
}

Real
ChemicalCoupling2a::computeQpResidual()
{
  return _coef * (1-_v[_qp]*_v[_qp]*(3-2*_v[_qp])) * _test[_i][_qp];
}

Real
ChemicalCoupling2a::computeQpJacobian()
{
  return 0;
}

Real
ChemicalCoupling2a::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _v_var)
    return _coef * _phi[_j][_qp] * _test[_i][_qp];
  return 0.0;
}
