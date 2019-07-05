#ifndef DPGLAPLACIAN_H
#define DPGLAPLACIAN_H

#include "Kernel.h"

class DPGlaplacian;

template <>
InputParameters validParams<DPGlaplacian>();

class DPGlaplacian : public Kernel
{
public:
  DPGlaplacian(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  const VariableSecond & _second_u;
  const VariablePhiSecond & _second_phi;
};

#endif // DPGLAPLACIAN_H
