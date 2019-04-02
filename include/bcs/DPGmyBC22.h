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

#ifndef DPGMYBC22_H
#define DPGMYBC22_H

#include "IntegratedBC.h"

class DPGmyBC22;

template <>
InputParameters validParams<DPGmyBC22>();

class DPGmyBC22 : public IntegratedBC
{
public:
  DPGmyBC22(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  const VariableValue & _coupled_variable;
  unsigned int _k_var; // index of _coupled_variable
  Function & _func;
  const VariablePhiValue & _phi_coupled_variable;
  const VariableValue & _kappa;
};

#endif // DPGMYBC22_H
