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
#ifndef DPGMYDGKERNEL33_H
#define DPGMYDGKERNEL33_H

#include "DGKernel.h"

// Forward Declarations
class DPGmyDGkernel33;

template <>
InputParameters validParams<DPGmyDGkernel33>();

class DPGmyDGkernel33 : public DGKernel
{
public:
  DPGmyDGkernel33(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type) override;
  virtual Real computeQpJacobian(Moose::DGJacobianType type) override;
};

#endif
