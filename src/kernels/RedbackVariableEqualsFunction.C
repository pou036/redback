/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "Function.h"
#include "RedbackVariableEqualsFunction.h"

template <>
InputParameters
validParams<RedbackVariableEqualsFunction>()
{
  InputParameters params = validParams<TimeKernel>();
  params.addRequiredParam<FunctionName>("function", "The function to assign values to the variable.");
  return params;
}

RedbackVariableEqualsFunction::RedbackVariableEqualsFunction(const InputParameters & parameters) :
    TimeKernel(parameters), _func(getFunction("function"))
{
}

Real
RedbackVariableEqualsFunction::computeQpResidual()
{
  return _test[ _i ][ _qp ] * (_u[ _qp ] - _func.value(_t, _q_point[ _qp ]));
}

Real
RedbackVariableEqualsFunction::computeQpJacobian()
{
  return _test[ _i ][ _qp ] * 1 * _phi[ _j ][ _qp ];
}
