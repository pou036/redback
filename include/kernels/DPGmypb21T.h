/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*                 (c) 2019 CSIRO                               */
/*               ALL RIGHTS RESERVED                            */
/*                                                              */
/*                Prepared by CSIRO                             */
/*                                                              */
/*        See COPYRIGHT for full restrictions                   */
/****************************************************************/
#ifndef DPGMYPB21T_H
#define DPGMYPB21T_H

#include "Kernel.h"

class DPGmypb21T;

template <>
InputParameters validParams<DPGmypb21T>();

class DPGmypb21T : public Kernel
{
public:
  DPGmypb21T(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  bool _is_vel_y_coupled, _is_vel_z_coupled;
  const VariableValue & _coupled_variable;
  unsigned int _k_var; // index of _coupled_variable
  const VariablePhiValue & _phi_coupled_variable;
  const VariableValue & _vel_x;
  const VariableValue & _vel_y;
  const VariableValue & _vel_z;
  const VariableGradient & _grad_vel_x;
  const VariableGradient & _grad_vel_y;
  const VariableGradient & _grad_vel_z;
  const VariableValue & _kappa;
  const VariableGradient & _grad_kappa;
  const VariableTestSecond & _second_test;
};

#endif // DPGMYPB21T_H
