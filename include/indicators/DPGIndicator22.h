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
#ifndef DPGINDICATOR22_H
#define DPGINDICATOR22_H

#include "ExternalSideIndicator.h"

class DPGIndicator22;

template <>
InputParameters validParams<DPGIndicator22>();

class DPGIndicator22 : public ExternalSideIndicator
{
public:
  DPGIndicator22(const InputParameters & parameters);

protected:
  virtual Real computeQpIntegral() override;

private:
  bool _is_vel_y_coupled, _is_vel_z_coupled;
  const VariableValue & _vel_x;
  const VariableValue & _vel_y;
  const VariableValue & _vel_z;
};

#endif /* DPGINDICATOR22_H */
