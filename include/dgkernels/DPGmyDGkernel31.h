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
#ifndef DPGMYDGKERNEL31_H
#define DPGMYDGKERNEL31_H

#include "DGKernel.h"

// Forward Declarations
class DPGmyDGkernel31;

template <>
InputParameters validParams<DPGmyDGkernel31>();

class DPGmyDGkernel31 : public DGKernel
{
public:
  DPGmyDGkernel31(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type) override;
  virtual Real computeQpJacobian(Moose::DGJacobianType type) override;
  virtual Real computeQpOffDiagJacobian(Moose::DGJacobianType type, unsigned int jvar) override;

private:
  unsigned int _k_var; // index of _coupled_variable
  const VariableValue & _coupled_variable;
  const VariableValue & _coupled_neighbor_variable;
  const VariablePhiValue & _phi_cvariable;
  const VariablePhiValue & _phi_cvar_neighbor;
};

#endif
