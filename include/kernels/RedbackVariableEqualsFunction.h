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

#ifndef REDBACKVARIABLEEQUALSFUNCTION_H
#define REDBACKVARIABLEEQUALSFUNCTION_H

#include "TimeKernel.h"

// Forward Declaration
class RedbackVariableEqualsFunction;

template <>
InputParameters validParams<RedbackVariableEqualsFunction>();

class RedbackVariableEqualsFunction : public TimeKernel
{
public:
  RedbackVariableEqualsFunction(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  Function & _func;
};

#endif // REDBACKVARIABLEEQUALSFUNCTION_H
