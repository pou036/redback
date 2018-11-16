#ifndef DPG3_H
#define DPG3_H

#include "Kernel.h"

class DPG3;

template <>
InputParameters validParams<DPG3>();

class DPG3 : public Kernel
{
public:
  DPG3(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  bool _is_x_coupled, _is_y_coupled, _is_z_coupled;
  unsigned int _x_var, _y_var, _z_var; // indices of variables
  const VariableGradient & _grad_coupled_var_x;
  const VariableGradient & _grad_coupled_var_y;
  const VariableGradient & _grad_coupled_var_z;
  const VariablePhiGradient & _grad_phi_x;
  const VariablePhiGradient & _grad_phi_y;
  const VariablePhiGradient & _grad_phi_z;
  const VariablePhiGradient _grad_phi_zero; // convenience zero
};

#endif // DPG3_H
