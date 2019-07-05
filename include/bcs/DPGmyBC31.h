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

#ifndef DPGMYBC31_H
#define DPGMYBC31_H

#include "IntegratedBC.h"

class DPGmyBC31;

template <>
InputParameters validParams<DPGmyBC31>();

class DPGmyBC31 : public IntegratedBC
{
public:
  DPGmyBC31(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;

private:
  const Function & _func;
};

#endif // DPGMYBC31_H
