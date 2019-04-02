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

#ifndef DPGMYBC21T_H
#define DPGMYBC21T_H

#include "IntegratedBC.h"

class DPGmyBC21T;

template <>
InputParameters validParams<DPGmyBC21T>();

class DPGmyBC21T : public IntegratedBC
{
public:
  DPGmyBC21T(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  bool _is_vel_y_coupled, _is_vel_z_coupled;
  const VariableValue & _vel_x; // x component of  velocity vector
  const VariableValue & _vel_y; // y component of  velocity vector
  const VariableValue & _vel_z; // z component of  velocity vector
  const VariableValue & _coupled_variable;
  unsigned int _k_var; // index of _coupled_variable
  const VariablePhiValue & _phi_coupled_variable;
};

#endif // DPGMYBC21T_H
