#ifndef DARCYBRINKMAN_H
#define DARCYBRINKMAN_H

#include "Kernel.h"

// Forward Declarations
class DarcyBrinkman;
// class RankFourTensor;
class RankTwoTensor;

template <>
InputParameters validParams<DarcyBrinkman>();

class DarcyBrinkman : public Kernel
{
public:
  DarcyBrinkman(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  const VariableValue & _perm;
  const MaterialProperty<Real> & _mu;
};

#endif // DARCYBRINKMAN_H
