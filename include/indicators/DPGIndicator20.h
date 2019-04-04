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
#ifndef DPGINDICATOR20_H
#define DPGINDICATOR20_H

#include "ElementIndicator.h"

class DPGIndicator20;

template <>
InputParameters validParams<DPGIndicator20>();

class DPGIndicator20 : public ElementIndicator
{
public:
  DPGIndicator20(const InputParameters & parameters);

  virtual void computeIndicator() override;

protected:
  virtual Real computeQpIntegral();

private:
  const VariableValue & _vel_x;
  const VariableValue & _vel_y;
  const VariableValue & _vel_z;
  const VariableValue & _kappa;
};

#endif /* DPGINDICATOR20_H */
