#ifndef DARCYBRINKMAN_H
#define DARCYBRINKMAN_H

#include "Kernel.h"

class DarcyBrinkman : public Kernel
{
public:
  DarcyBrinkman(const InputParameters & parameters);
  static InputParameters validParams();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  const VariableValue & _perm;
  const MaterialProperty<Real> & _mu;
};

#endif // DARCYBRINKMAN_H
