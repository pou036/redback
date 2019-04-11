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

#ifndef DPGMYBC30T_H
#define DPGMYBC30T_H

#include "IntegratedBC.h"

class DPGmyBC30T;

template <>
InputParameters validParams<DPGmyBC30T>();

class DPGmyBC30T : public IntegratedBC
{
public:
  DPGmyBC30T(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  const VariableValue & _coupled_variable;
  unsigned int _k_var; // index of _coupled_variable
  const VariablePhiValue & _phi_coupled_variable;
};

#endif // DPGMYBC30T_H
