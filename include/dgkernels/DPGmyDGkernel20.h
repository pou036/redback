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
#ifndef DPGMYDGKERNEL20_H
#define DPGMYDGKERNEL20_H

#include "DGKernel.h"

// Forward Declarations
class DPGmyDGkernel20;

template <>
InputParameters validParams<DPGmyDGkernel20>();

/**
 * DG kernel for advection
 *
 * General DG kernel that this class can handle is:
 * \f$ 0.5 <abs(b.n_e) * [u], [\tilde{u}]> \f$
 *
 * \f$ [a] = [ a_1 - a_2 ] \f$
 * \f$ {a} = 0.5 * (a_1 + a_2) \f$
 *
 */
class DPGmyDGkernel20 : public DGKernel
{
public:
  DPGmyDGkernel20(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type) override;
  virtual Real computeQpJacobian(Moose::DGJacobianType type) override;

private:
  bool _is_vel_y_coupled, _is_vel_z_coupled;
  const VariableValue & _vel_x;
  const VariableValue & _vel_y;
  const VariableValue & _vel_z;
};

#endif
