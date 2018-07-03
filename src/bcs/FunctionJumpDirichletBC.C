//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "FunctionJumpDirichletBC.h"
#include "Function.h"
#include "Assembly.h"

template <>
InputParameters
validParams<FunctionJumpDirichletBC>()
{
  InputParameters params = validParams<NodalBC>();
  params.addRequiredParam<FunctionName>("function", "The forcing function.");
  params.addCoupledVar("tangent_jump",
                       0.0,
                       "The variable describing the tangential jump on the interface. Note that "
                       "the tangent vector is "
                       "oriented +90deg from the normal vector.");
  params.addRequiredParam<Real>(
      "fault_angle", "The (direct) angle of the fault in degrees/radians from the horizontal");
  params.addParam<bool>("convert_to_radians",
                        false,
                        "If true, the value you entered will be "
                        "multiplied by Pi/180");
  params.addRequiredRangeCheckedParam<unsigned int>(
      "component",
      "component >= 0 & component <= 2",
      "An integer corresponding to the direction the variable "
      "this kernel acts in. (0 for x, 1 for y, 2 for z)");
  params.addClassDescription(
      "Imposes the essential boundary condition $u=g(t,\\vec{x})$, where $g$ "
      "is a (possibly) time and space-dependent MOOSE Function.");
  return params;
}

FunctionJumpDirichletBC::FunctionJumpDirichletBC(const InputParameters & parameters)
  : NodalBC(parameters),
    _func(getFunction("function")),
    _tangent_jump(coupledValue("tangent_jump")),
    _angle(getParam<bool>("convert_to_radians") ? getParam<Real>("fault_angle") * M_PI / 180.0
                                                : getParam<Real>("fault_angle")),
    _component(getParam<unsigned int>("component"))
{
}

Real
FunctionJumpDirichletBC::f()
{
  return _func.value(_t, *_current_node);
}

Real
FunctionJumpDirichletBC::computeQpResidual()
{
  RealVectorValue fault_tangent(cos(_angle), sin(_angle)); // only works for linear fault
  return _u[_qp] - (f() + _tangent_jump[_qp] * fault_tangent(_component));
}
