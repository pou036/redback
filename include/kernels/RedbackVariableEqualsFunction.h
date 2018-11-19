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
