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
#ifndef DPGMYPB20_H
#define DPGMYPB20_H

#include "Kernel.h"

class DPGmypb20;

template <>
InputParameters validParams<DPGmypb20>();

class DPGmypb20 : public Kernel
{
public:
  DPGmypb20(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;

private:
  const VariableValue & _vel_x; // x component of  velocity vector
  const VariableValue & _vel_y; // y component of  velocity vector
  const VariableValue & _vel_z; // z component of  velocity vector
};

#endif // DPGMYPB20_H
