//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "MatchedValueJumpBC.h"
#include "Assembly.h"

template <>
InputParameters
validParams<MatchedValueJumpBC>()
{
  InputParameters params = validParams<NodalBC>();
  params.addRequiredCoupledVar("v", "The variable whose value we are to match.");
  params.addClassDescription("Implements a NodalBC which equates two different Variables' values "
                             "on a specified boundary.");
  params.addParam<PostprocessorName>("tangent_jump", 0, "jump value on the interface. Note that the tangent vector is oriented +90deg from the normal vector.");
  params.addRequiredRangeCheckedParam<unsigned int>("component",
                                                    "component >= 0 & component <= 2",
                                                    "An integer corresponding to the direction the variable "
                                                    "this kernel acts in. (0 for x, 1 for y, 2 for z)");
  return params;
}

MatchedValueJumpBC::MatchedValueJumpBC(const InputParameters & parameters)
  : NodalBC(parameters),
    _v(coupledValue("v")),
    _v_num(coupled("v")),
    _jump(getPostprocessorValue("tangent_jump")),
    _component(getParam<unsigned int>("component")),
    _normals(_assembly.normals())
{
}

Real
MatchedValueJumpBC::computeQpResidual()
{
  RealVectorValue fault_tangent(- _normals[ _qp ](1), _normals[ _qp ](0)); //90deg rotation of the normal vector
  return _u[ _qp ] - _v[ _qp ] + _jump * fault_tangent(_component);
}

Real
MatchedValueJumpBC::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _v_num)
    return -1.0;
  else
    return 0.;
}
