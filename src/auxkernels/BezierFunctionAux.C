//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "BezierFunctionAux.h"
#include "BezierUserObject.h"

template <>
InputParameters
validParams<BezierFunctionAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addClassDescription("Auxiliary Kernel that creates and updates a field variable by "
                             "sampling a function through space and time.");
  params.addRequiredParam<UserObjectName>("bezier_function", "The name of the BezierUserObject");
  return params;
}

BezierFunctionAux::BezierFunctionAux(const InputParameters & parameters)
  : AuxKernel(parameters), _func(getUserObject<BezierUserObject>("bezier_function"))
{
}

Real
BezierFunctionAux::computeValue()
{
  if (isNodal())
    return _func.value(*_current_node);
  else
    return _func.value(_q_point[_qp]);
}
