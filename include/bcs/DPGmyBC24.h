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

#ifndef DPGMYBC24_H
#define DPGMYBC24_H

#include "IntegratedBC.h"

class DPGmyBC24;

template <>
InputParameters validParams<DPGmyBC24>();

class DPGmyBC24 : public IntegratedBC
{
public:
  DPGmyBC24(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;

private:
  const Function & _func;
  const VariableValue & _kappa;
};

#endif // DPGMYBC24_H
