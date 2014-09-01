#ifndef REDBACKTHERMALCONVECTION_H
#define REDBACKTHERMALCONVECTION_H

#include "Kernel.h"

class RedbackThermalConvection : public Kernel
{
public:

  RedbackThermalConvection(const std::string & name, InputParameters parameters);
  virtual ~RedbackThermalConvection() {}

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  MaterialProperty<RealVectorValue> & _mixture_convective_energy;
};

template<>
InputParameters validParams<RedbackThermalConvection>();

#endif //REDBACKTHERMALCONVECTION_H
