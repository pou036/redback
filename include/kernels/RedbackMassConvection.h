#ifndef REDBACKMASSCONVECTION_H
#define REDBACKMASSCONVECTION_H

#include "Kernel.h"

class RedbackMassConvection : public Kernel
{
public:

  RedbackMassConvection(const std::string & name, InputParameters parameters);
  virtual ~RedbackMassConvection() {}

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  VariableGradient & _grad_temp;

  MaterialProperty<RealVectorValue> & _pressure_convective_mass;
  MaterialProperty<RealVectorValue> & _pressure_convective_mass_jac;
  MaterialProperty<RealVectorValue> & _thermal_convective_mass;
  MaterialProperty<RealVectorValue> & _thermal_convective_mass_jac;
};

template<>
InputParameters validParams<RedbackMassConvection>();

#endif //REDBACKMASSCONVECTION_H
