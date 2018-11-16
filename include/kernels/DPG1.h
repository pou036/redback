#ifndef DPG1_H
#define DPG1_H

#include "Kernel.h"

class DPG1;

template <>
InputParameters validParams<DPG1>();

class DPG1 : public Kernel
{
public:
  DPG1(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;

//private:
};

#endif // DPG1_H
