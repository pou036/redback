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
  unsigned int _nb_sum_vars, _nb_sum_vars_old, _nb_sum_vars_older; // number of variables to sum
  std::vector<const VariableValue *> _sum_vars; // coupled variables to sum
  std::vector<const VariableValue *> _sum_vars_old; // old coupled variables to sum
  std::vector<const VariableValue *> _sum_vars_older; // older coupled variables to sum
  bool _are_nodal_vars_involved, _are_elemental_vars_involved;
};

#endif /* REDBACKCONTINUATIONTANGENTAUX_H */
