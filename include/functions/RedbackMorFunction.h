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

#ifndef REDBACKMORFUNCTION_H
#define REDBACKMORFUNCTION_H

#include "Function.h"

class RedbackMorFunction;

template<> InputParameters validParams<RedbackMorFunction>();

/**
 * Class that represents constant function
 */
class RedbackMorFunction : public Function
{
public:
  RedbackMorFunction(const InputParameters & parameters);

  virtual Real value(Real t, const Point & p);

protected:
  const Real &  _mantle_temperature;
  const Real &  _surface_temperature;
  const Real &  _diffusivity;
  const Real &  _velocity;
};

#endif

