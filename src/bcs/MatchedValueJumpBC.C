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

#include "Assembly.h"
#include "MatchedValueJumpBC.h"

registerMooseObject("RedbackApp", MatchedValueJumpBC);

InputParameters
MatchedValueJumpBC::validParams()
{
  InputParameters params = NodalBC::validParams();
  params.addRequiredCoupledVar("v", "The variable whose value we are to match.");
  params.addClassDescription("Implements a NodalBC which equates two different Variables' values "
                             "on a specified boundary.");
  params.addCoupledVar("tangent_jump",
                       0.0,
                       "The variable describing the tangential jump on the interface. Note that "
                       "the tangent vector is "
                       "oriented +90deg from the normal vector.");
  params.addRequiredRangeCheckedParam<unsigned int>(
      "component",
      "component >= 0 & component <= 2",
      "An integer corresponding to the direction the variable "
      "this kernel acts in. (0 for x, 1 for y, 2 for z)");
  return params;
}

MatchedValueJumpBC::MatchedValueJumpBC(const InputParameters & parameters)
  : NodalBC(parameters),
    _v(coupledValue("v")),
    _v_num(coupled("v")),
    _tangent_jump(coupledValue("tangent_jump")),
    _component(getParam<unsigned int>("component")),
    _normals(_assembly.normals())
{
}

Real
MatchedValueJumpBC::computeQpResidual()
{
  RealVectorValue fault_tangent(-_normals[_qp](1),
                                _normals[_qp](0)); // 90deg rotation of the normal vector
  return _u[_qp] - _v[_qp] + _tangent_jump[_qp] * fault_tangent(_component);
}

Real
MatchedValueJumpBC::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _v_num)
    return -1.0;
  else
    return 0.;
}
