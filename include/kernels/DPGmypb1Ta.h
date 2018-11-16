#ifndef DPGMYPB1TA_H
#define DPGMYPB1TA_H

#include "Kernel.h"

class DPGmypb1Ta;

template <>
InputParameters validParams<DPGmypb1Ta>();

class DPGmypb1Ta : public Kernel
{
public:
  DPGmypb1Ta(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  bool _is_y_coupled, _is_z_coupled;
  unsigned int _x_var, _y_var, _z_var; // indices of variables
  const VariableValue & _coupled_var_x;
  const VariableValue & _coupled_var_y;
  const VariableValue & _coupled_var_z;
  const MaterialProperty<Real> & _kappa; // diffusivity
  const MaterialProperty<Real> & _vel_x; // x component of  velocity vector
  const MaterialProperty<Real> & _vel_y; // y component of  velocity vector
  const MaterialProperty<Real> & _vel_z; // z component of  velocity vector
  const VariablePhiValue & _phi_x;
  const VariablePhiValue & _phi_y;
  const VariablePhiValue & _phi_z;
  const VariablePhiValue _phi_zero; // convenience zero
};

#endif // DPGMYPB1TA_H
