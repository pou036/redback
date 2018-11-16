#ifndef DPG5_H
#define DPG5_H

#include "Kernel.h"

class DPG5;

template <>
InputParameters validParams<DPG5>();

class DPG5 : public Kernel
{
public:
  DPG5(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  const unsigned int _component;
  const VariableValue & _coupled_var;
  unsigned int _k_var; // indices of variables
  VariablePhiValue & _phi_k;
};

#endif // DPG5_H
