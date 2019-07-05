#ifndef DPGMYPB12_H
#define DPGMYPB12_H

#include "Kernel.h"

class DPGmypb12;

template <>
InputParameters validParams<DPGmypb12>();

class DPGmypb12 : public Kernel
{
public:
  DPGmypb12(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;

private:
  const MaterialProperty<Real> & _lambda;
  const MaterialProperty<Real> & _alpha_2;
  const MaterialProperty<Real> & _m;
  const MaterialProperty<Real> & _mu;
  const MaterialProperty<Real> & _beta;
};

#endif // DPGMYPB12_H
