#ifndef REDBACKPOLARSTRESSAUX_H
#define REDBACKPOLARSTRESSAUX_H

#include "AuxKernel.h"
#include "RankTwoTensor.h"

// Forward declarations
class RedbackPolarStressAux;

template <>
InputParameters validParams<RedbackPolarStressAux>();

class RedbackPolarStressAux : public AuxKernel
{
public:
  RedbackPolarStressAux(const InputParameters & parameters);
  virtual ~RedbackPolarStressAux()
  {
  }

protected:
  virtual Real computeValue();

private:
  const MaterialProperty<RankTwoTensor> & _stress;
};

#endif // REDBACKPOLARSTRESSAUX_H
