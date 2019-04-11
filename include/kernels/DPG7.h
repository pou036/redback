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
#ifndef DPG7_H
#define DPG7_H

#include "Kernel.h"

class DPG7;

template <>
InputParameters validParams<DPG7>();

class DPG7 : public Kernel
{
public:
  DPG7(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  unsigned int _k_var; // index of _coupled_variable
  const VariableGradient & _grad_coupled_variable;
  const VariablePhiGradient & _grad_phi_cvariable;
};

#endif // DPG7_H
