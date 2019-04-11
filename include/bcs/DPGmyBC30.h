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

#ifndef DPGMYBC30_H
#define DPGMYBC30_H

#include "IntegratedBC.h"

class DPGmyBC30;

template <>
InputParameters validParams<DPGmyBC30>();

class DPGmyBC30 : public IntegratedBC
{
public:
  DPGmyBC30(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  unsigned int _k_var; // index of _coupled_variable
  const VariableGradient & _grad_coupled_variable;
  Function & _func;
  const VariablePhiGradient & _grad_phi_cvariable;
};

#endif // DPGMYBC30_H
