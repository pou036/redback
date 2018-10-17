//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "ImageFunctionAux.h"
#include "ImageFunctionUserObject.h"

template <>
InputParameters
validParams<ImageFunctionAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addClassDescription("Auxiliary Kernel that creates and updates a field variable by "
                             "sampling a function through space and time.");
  params.addRequiredParam<UserObjectName>("image_function",
                                          "The name of the ImageFunctionUserObject");
  return params;
}

ImageFunctionAux::ImageFunctionAux(const InputParameters & parameters)
  : AuxKernel(parameters), _func(getUserObject<ImageFunctionUserObject>("image_function"))
{
}

Real
ImageFunctionAux::computeValue()
{
  if (isNodal())
    return _func.value(*_current_node);
  else
    return _func.value(_q_point[_qp]);
}
