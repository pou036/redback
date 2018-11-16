#ifndef DPGMYPB1TB_H
#define DPGMYPB1TB_H

#include "Kernel.h"

class DPGmypb1Tb;

template <>
InputParameters validParams<DPGmypb1Tb>();

class DPGmypb1Tb : public Kernel
{
public:
  DPGmypb1Tb(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  const VariableValue & _coupled_var;
  unsigned int _k_var; // indices of variables
  VariablePhiValue & _phi_k;
};

#endif // DPGMYPB1TB_H
