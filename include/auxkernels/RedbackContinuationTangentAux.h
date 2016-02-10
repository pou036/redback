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

template<>
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
  VariableValue & _sum_var_1;
  VariableValue & _sum_var_2;
  VariableValue & _sum_var_3;
  VariableValue & _sum_var_4;
  VariableValue & _sum_var_5;
  VariableValue & _sum_var_6;
  VariableValue & _sum_var_old_1;
  VariableValue & _sum_var_old_2;
  VariableValue & _sum_var_old_3;
  VariableValue & _sum_var_old_4;
  VariableValue & _sum_var_old_5;
  VariableValue & _sum_var_old_6;
  VariableValue & _sum_var_older_1;
  VariableValue & _sum_var_older_2;
  VariableValue & _sum_var_older_3;
  VariableValue & _sum_var_older_4;
  VariableValue & _sum_var_older_5;
  VariableValue & _sum_var_older_6;
};

#endif /* REDBACKCONTINUATIONTANGENTAUX_H */