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

#include "RandomPermeability.h"

template<> InputParameters validParams<RandomPermeability>()
{
   InputParameters params = validParams<Function>();
   params.addParam<Real>("value", 0.0, "The random(?) value");
   return params;
}

RandomPermeability::RandomPermeability(const std::string & name, InputParameters parameters) :
    Function(name, parameters),
    _value(getParam<Real>("value"))
{
}

Real
RandomPermeability::value(Real, const Point &)
{
  return _value;
}

