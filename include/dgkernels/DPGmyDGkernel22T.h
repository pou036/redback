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

/**
 * DG kernel for advection
 *
 * General DG kernel that this class can handle is:
 * \f$ <[\kappa\nabla \tilde{u} . n_e], \{v\}> \f$
 *
 * \f$ [a] = [ a_1 - a_2 ] \f$
 * \f$ {a} = 0.5 * (a_1 + a_2) \f$
 *
 */
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
