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
  bool _is_var1_coupled, _is_var2_coupled, _is_var3_coupled, _is_var4_coupled, _is_var5_coupled,
      _is_var6_coupled;
};

#endif /* REDBACKCONTINUATIONTANGENTAUX_H */
