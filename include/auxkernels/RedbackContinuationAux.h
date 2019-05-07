#ifndef REDBACKCONTINUATIONAUX_H
#define REDBACKCONTINUATIONAUX_H

#include "AuxKernel.h"
#include "RankTwoTensor.h"

// Forward declarations
class RedbackContinuationAux;

template <>
InputParameters validParams<RedbackContinuationAux>();

class RedbackContinuationAux : public AuxKernel
{
public:
  RedbackContinuationAux(const InputParameters & parameters);
  virtual ~RedbackContinuationAux() {}

protected:
  virtual Real computeValue();
  Real _ds_old_param;
  unsigned int _nb_sum_vars, _nb_sum_vars_old, _nb_sum_vars_older; // number of variables to sum
  std::vector<const VariableValue *> _sum_vars; // coupled variables to sum
  std::vector<const VariableValue *> _sum_vars_old; // old coupled variables to sum
  std::vector<const VariableValue *> _sum_vars_older; // older coupled variables to sum
  bool _are_nodal_vars_involved, _are_elemental_vars_involved;
};

#endif // REDBACKCONTINUATIONAUX_H
