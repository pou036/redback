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
#ifndef DPGMYDGKERNEL32_H
#define DPGMYDGKERNEL32_H

#include "DGKernel.h"

// Forward Declarations
class DPGmyDGkernel32;

template <>
InputParameters validParams<DPGmyDGkernel32>();

class DPGmyDGkernel32 : public DGKernel
{
public:
  DPGmyDGkernel32(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type) override;
  virtual Real computeQpJacobian(Moose::DGJacobianType type) override;
};

#endif
