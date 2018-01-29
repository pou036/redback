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

#ifndef REDBACKCONTINUATIONTANGENTAUX_H
#define REDBACKCONTINUATIONTANGENTAUX_H

#include "AuxNodalScalarKernel.h"

class RedbackContinuationTangentAux;

template <>
InputParameters validParams<RedbackContinuationTangentAux>();

/**
 *
 */
class RedbackContinuationTangentAux : public AuxNodalScalarKernel
{
public:
  RedbackContinuationTangentAux(const InputParameters & parameters);
  virtual ~RedbackContinuationTangentAux();

  virtual void compute();

protected:
  virtual Real computeValue();
  Real _ds_old_param;
  const VariableValue & _sum_var_1;
  const VariableValue & _sum_var_2;
  const VariableValue & _sum_var_3;
  const VariableValue & _sum_var_4;
  const VariableValue & _sum_var_5;
  const VariableValue & _sum_var_6;
  const VariableValue & _sum_var_old_1;
  const VariableValue & _sum_var_old_2;
  const VariableValue & _sum_var_old_3;
  const VariableValue & _sum_var_old_4;
  const VariableValue & _sum_var_old_5;
  const VariableValue & _sum_var_old_6;
  const VariableValue & _sum_var_older_1;
  const VariableValue & _sum_var_older_2;
  const VariableValue & _sum_var_older_3;
  const VariableValue & _sum_var_older_4;
  const VariableValue & _sum_var_older_5;
  const VariableValue & _sum_var_older_6;
  bool _is_var1_coupled, _is_var2_coupled, _is_var3_coupled, _is_var4_coupled, _is_var5_coupled, _is_var6_coupled;
};

#endif /* REDBACKCONTINUATIONTANGENTAUX_H */
