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
#ifndef DPGMYDGKERNEL22_H
#define DPGMYDGKERNEL22_H

#include "DGKernel.h"

// Forward Declarations
class DPGmyDGkernel22;

template <>
InputParameters validParams<DPGmyDGkernel22>();

/**
 * DG kernel for advection
 *
 * General DG kernel that this class can handle is:
 * \f$ <[\kappa\nabla u . n_e], \{\tilde{u}\}> \f$
 *
 * \f$ [a] = [ a_1 - a_2 ] \f$
 * \f$ {a} = 0.5 * (a_1 + a_2) \f$
 *
 */
class DPGmyDGkernel22 : public DGKernel
{
public:
  DPGmyDGkernel22(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type) override;
  virtual Real computeQpJacobian(Moose::DGJacobianType type) override;
  virtual Real computeQpOffDiagJacobian(Moose::DGJacobianType type, unsigned int jvar) override;

private:
  const VariableValue & _kappa;
  const VariableValue & _kappa_neighbor;
  unsigned int _k_var; // index of _coupled_variable
  const VariableGradient & _grad_coupled_variable;
  const VariableGradient & _grad_cvar_neighbor;
  const VariablePhiGradient & _grad_phi_cvariable;
  const VariablePhiGradient & _grad_phi_cvar_neighbor;
};

#endif
