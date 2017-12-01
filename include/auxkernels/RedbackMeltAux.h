#ifndef REDBACKMELTAUX_H
#define REDBACKMELTAUX_H

#include "AuxKernel.h"
#include "RankTwoTensor.h"

// Forward declarations
class RedbackMeltAux;

template <>
InputParameters validParams<RedbackMeltAux>();

class RedbackMeltAux : public AuxKernel
{
public:
  RedbackMeltAux(const InputParameters & parameters);
  virtual ~RedbackMeltAux()
  {
  }

protected:
  virtual Real computeValue();
  const VariableValue & _temp;
};

#endif // REDBACKMELTAUX_H
