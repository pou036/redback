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
#ifndef DPGINDICATOR21_H
#define DPGINDICATOR21_H

#include "InternalSideIndicator.h"

class DPGIndicator21;

template <>
InputParameters validParams<DPGIndicator21>();

class DPGIndicator21 : public InternalSideIndicator
{
public:
  DPGIndicator21(const InputParameters & parameters);

protected:
  virtual Real computeQpIntegral() override;

private:
  bool _is_vel_y_coupled, _is_vel_z_coupled;
  const VariableValue & _vel_x;
  const VariableValue & _vel_y;
  const VariableValue & _vel_z;
  const VariableValue & _kappa;
};

#endif /* DPGINDICATOR21_H */
