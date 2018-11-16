#ifndef DPGMYPB11T_H
#define DPGMYPB11T_H

#include "Kernel.h"

class DPGmypb11T;

template <>
InputParameters validParams<DPGmypb11T>();

class DPGmypb11T : public Kernel
{
public:
  DPGmypb11T(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  const VariableValue & _scalar_var;
  unsigned int _coupled_var; // index of coupled variable
  const VariablePhiValue & _phi_var;
  const MaterialProperty<Real> & _lambda;
  const MaterialProperty<Real> & _alpha_2;
  const MaterialProperty<Real> & _m;
  const MaterialProperty<Real> & _mu;
  const MaterialProperty<Real> & _beta;
};

#endif // DPGMYPB11T_H
