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
#ifndef DPGMYDGKERNEL22T_H
#define DPGMYDGKERNEL22T_H

#include "DGKernel.h"

// Forward Declarations
class DPGmyDGkernel22T;

template <>
InputParameters validParams<DPGmyDGkernel22T>();

class DPGmyDGkernel22T : public DGKernel
{
public:
  DPGmyDGkernel22T(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type) override;
  virtual Real computeQpJacobian(Moose::DGJacobianType type) override;
  virtual Real computeQpOffDiagJacobian(Moose::DGJacobianType type, unsigned int jvar) override;

private:
  const VariableValue & _kappa;
  const VariableValue & _kappa_neighbor;
  unsigned int _k_var; // index of _coupled_variable
  const VariableValue & _coupled_variable;
  const VariableValue & _coupled_neighbor_variable;
  const VariablePhiValue & _phi_cvariable;
  const VariablePhiValue & _phi_cvar_neighbor;
};

#endif
