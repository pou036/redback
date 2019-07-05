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
#ifndef DPGMYDGKERNEL32T_H
#define DPGMYDGKERNEL32T_H

#include "DGKernel.h"

// Forward Declarations
class DPGmyDGkernel32T;

template <>
InputParameters validParams<DPGmyDGkernel32T>();

class DPGmyDGkernel32T : public DGKernel
{
public:
  DPGmyDGkernel32T(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type) override;
  virtual Real computeQpJacobian(Moose::DGJacobianType type) override;
};

#endif
