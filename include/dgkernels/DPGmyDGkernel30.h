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
#ifndef DPGMYDGKERNEL30_H
#define DPGMYDGKERNEL30_H

#include "DGKernel.h"

// Forward Declarations
class DPGmyDGkernel30;

template <>
InputParameters validParams<DPGmyDGkernel30>();

class DPGmyDGkernel30 : public DGKernel
{
public:
  DPGmyDGkernel30(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type) override;
  virtual Real computeQpJacobian(Moose::DGJacobianType type) override;
  virtual Real computeQpOffDiagJacobian(Moose::DGJacobianType type, unsigned int jvar) override;

private:
  unsigned int _k_var; // index of _coupled_variable
  const VariableGradient & _grad_coupled_variable;
  const VariableGradient & _grad_cvar_neighbor;
  const VariablePhiGradient & _grad_phi_cvariable;
  const VariablePhiGradient & _grad_phi_cvar_neighbor;
};

#endif
