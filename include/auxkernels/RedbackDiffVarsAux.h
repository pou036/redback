#ifndef REDBACKDIFFVARSAUX_H
#define REDBACKDIFFVARSAUX_H

#include "AuxKernel.h"
#include "RankTwoTensor.h"

// Forward declarations
class RedbackDiffVarsAux;

template <>
InputParameters validParams<RedbackDiffVarsAux>();

class RedbackDiffVarsAux : public AuxKernel
{
public:
  RedbackDiffVarsAux(const InputParameters & parameters);
  virtual ~RedbackDiffVarsAux()
  {
  }

protected:
  virtual Real computeValue();
  VariableValue & _variable_1;
  VariableValue & _variable_2;

};

#endif // REDBACKDIFFVARSAUX_H
