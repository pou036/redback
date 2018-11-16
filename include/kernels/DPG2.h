#ifndef DPG2_H
#define DPG2_H

#include "Kernel.h"

class DPG2;

template <>
InputParameters validParams<DPG2>();

class DPG2 : public Kernel
{
public:
  DPG2(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;

//private:
};

#endif // DPG2_H
