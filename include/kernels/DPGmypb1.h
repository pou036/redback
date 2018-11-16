#ifndef DPGMYPB1_H
#define DPGMYPB1_H

#include "Kernel.h"

class DPGmypb1;

template <>
InputParameters validParams<DPGmypb1>();

class DPGmypb1 : public Kernel
{
public:
  DPGmypb1(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  const VariableValue & _scalar_var;
  const VariableValue & _coupled_vector_k;
  const VariableGradient & _grad_scalar_var;
  unsigned int _coupled_var, _k_var; // indices of variables
  const VariablePhiValue & _phi_k;
  const VariablePhiValue & _phi_var;
  const VariablePhiGradient & _grad_phi_var;
  const unsigned int _component;
  const MaterialProperty<Real> & _vel_x; // x component of  velocity vector
  const MaterialProperty<Real> & _vel_y; // y component of  velocity vector
  const MaterialProperty<Real> & _vel_z; // z component of  velocity vector
  const MaterialProperty<Real> & _kappa; // diffusivity
};

#endif // DPGMYPB1_H
