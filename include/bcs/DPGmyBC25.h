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

#ifndef DPGMYBC25_H
#define DPGMYBC25_H

#include "IntegratedBC.h"

class DPGmyBC25;

template <>
InputParameters validParams<DPGmyBC25>();

class DPGmyBC25 : public IntegratedBC
{
public:
  DPGmyBC25(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;

private:
  const Function & _func;
  const VariableValue & _kappa;
};

#endif // DPGMYBC25_H
