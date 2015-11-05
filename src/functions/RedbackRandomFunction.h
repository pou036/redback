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

#ifndef REDBACKRANDOMFUNCTION_H
#define REDBACKRANDOMFUNCTION_H

#include "Function.h"

class RedbackRandomFunction;

template<> InputParameters validParams<RedbackRandomFunction>();

/**
 * Class that represents constant function
 */
class RedbackRandomFunction : public Function
{
public:
  RedbackRandomFunction(const std::string & name, InputParameters parameters);

  virtual Real value(Real t, const Point & p);

protected:
  const Real & _value;
};

#endif


