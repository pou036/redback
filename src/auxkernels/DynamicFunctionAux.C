//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "DynamicFunctionAux.h"
#include "FunctionUserObject.h"

template <>
InputParameters
validParams<DynamicFunctionAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addClassDescription("Auxiliary Kernel that creates and updates a field variable by "
                             "sampling a function through space and time.");
  params.addRequiredParam<UserObjectName>("dynamic_function", "The name of the UserObject");
  return params;
}

DynamicFunctionAux::DynamicFunctionAux(const InputParameters & parameters) :
    AuxKernel(parameters), _func(getUserObject<FunctionUserObject>("dynamic_function"))
{
}

Real
DynamicFunctionAux::computeValue()
{
  if (isNodal())
    return _func.value(_t, *_current_node);
  else
    return _func.value(_t, _q_point[ _qp ]);
}
