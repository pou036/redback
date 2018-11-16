#ifndef DPG4_H
#define DPG4_H

#include "Kernel.h"

class DPG4;

template <>
InputParameters validParams<DPG4>();

class DPG4 : public Kernel
{
public:
  DPG4(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  bool _is_kp1_coupled, _is_kp2_coupled;
  unsigned int _kp1_var, _kp2_var; // indices of variables
  const unsigned int _component;
  const VariableGradient & _grad_coupled_var_kp1;
  const VariableGradient & _grad_coupled_var_kp2;
  const VariablePhiGradient & _grad_phi_kp1;
  const VariablePhiGradient & _grad_phi_kp2;
  const VariablePhiGradient _grad_phi_zero; // convenience zero
};

#endif // DPG4_H
