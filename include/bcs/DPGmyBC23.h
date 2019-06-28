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

#ifndef DPGMYBC23_H
#define DPGMYBC23_H

#include "IntegratedBC.h"

class DPGmyBC23;

template <>
InputParameters validParams<DPGmyBC23>();

class DPGmyBC23 : public IntegratedBC
{
public:
  DPGmyBC23(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  const VariableValue & _coupled_variable;
  unsigned int _k_var; // index of _coupled_variable
  const Function & _func;
  const VariablePhiValue & _phi_coupled_variable;
  const VariableValue & _kappa;
};

#endif // DPGMYBC23_H
