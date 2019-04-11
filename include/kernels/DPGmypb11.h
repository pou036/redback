#ifndef DPGMYPB11_H
#define DPGMYPB11_H

#include "Kernel.h"

class DPGmypb11;

template <>
InputParameters validParams<DPGmypb11>();

class DPGmypb11 : public Kernel
{
public:
  DPGmypb11(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

private:
  const VariableValue & _scalar_var;
  unsigned int _k_var; // index of coupled variable
  const VariablePhiValue & _phi_var;
  const MaterialProperty<Real> & _lambda;
  const MaterialProperty<Real> & _alpha_2;
  const MaterialProperty<Real> & _m;
  const MaterialProperty<Real> & _mu;
  const MaterialProperty<Real> & _beta;
};

#endif // DPGMYPB11_H
