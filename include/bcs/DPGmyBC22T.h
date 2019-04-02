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

#ifndef DPGMYBC22T_H
#define DPGMYBC22T_H

#include "IntegratedBC.h"

class DPGmyBC22T;

template <>
InputParameters validParams<DPGmyBC22T>();

class DPGmyBC22T : public IntegratedBC
{
public:
  DPGmyBC22T(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  unsigned int _k_var; // index of _coupled_variable
  const VariableGradient & _grad_coupled_variable;
  const VariablePhiGradient & _grad_phi_cvariable;
  const VariableValue & _kappa;
};

#endif // DPGMYBC22T_H
