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

#ifndef DPGMYBC23T_H
#define DPGMYBC23T_H

#include "IntegratedBC.h"

class DPGmyBC23T;

template <>
InputParameters validParams<DPGmyBC23T>();

class DPGmyBC23T : public IntegratedBC
{
public:
  DPGmyBC23T(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  const VariableValue & _coupled_variable;
  unsigned int _k_var; // index of _coupled_variable
  const VariablePhiValue & _phi_coupled_variable;
  const VariableValue & _kappa;
};

#endif // DPGMYBC23T_H
