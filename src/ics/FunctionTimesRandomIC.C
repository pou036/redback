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

#include "FunctionTimesRandomIC.h"
#include "Function.h"
#include "MooseRandom.h"

#include "libmesh/point.h"

template <>
InputParameters
validParams<FunctionTimesRandomIC>()
{
  InputParameters params = validParams<InitialCondition>();
  params.addParam<Real>("min", 0.0, "Lower bound of the randomly generated values");
  params.addParam<Real>("max", 1.0, "Upper bound of the randomly generated values");
  params.addParam<unsigned int>("seed", 0, "Seed value for the random number generator");
  params.addRequiredParam<FunctionName>("function", "The initial condition function (without randomness).");
  return params;
}

FunctionTimesRandomIC::FunctionTimesRandomIC(const InputParameters & parameters) :
    InitialCondition(parameters),
    _min(getParam<Real>("min")),
    _max(getParam<Real>("max")),
    _range(_max - _min),
    _func(getFunction("function"))
{
  mooseAssert(_range > 0.0, "Min > Max for FunctionTimesRandomIC!");
  MooseRandom::seed(getParam<unsigned int>("seed"));
}

Real
FunctionTimesRandomIC::value(const Point & p)
{
  // Random number between 0 and 1
  Real rand_num = MooseRandom::rand();

  // Between 0 and range
  rand_num *= _range;

  // Between min and max
  rand_num += _min;

  return rand_num * _func.value(_t, p);
}
