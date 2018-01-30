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

#ifndef REDBACKCONTINUATION_H
#define REDBACKCONTINUATION_H

#include "ODEKernel.h"

class RedbackContinuation;

template <>
InputParameters validParams<RedbackContinuation>();

class RedbackContinuation : public ODEKernel
{
public:
  RedbackContinuation(const InputParameters & parameters);

protected:
  Real _ds_param, _ds_old_param, _continuation_parameter_old_param, _continuation_parameter_older_param;
  VariableValue & _directional_derivative;

  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  // virtual Real computeQpOffDiagJacobian(unsigned int jvar);
};

#endif /* REDBACKCONTINUATION_H */
