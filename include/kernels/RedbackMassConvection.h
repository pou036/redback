#ifndef REDBACKMASSCONVECTION_H
#define REDBACKMASSCONVECTION_H

#include "Kernel.h"

class RedbackMassConvection : public Kernel
{
public:
  RedbackMassConvection(const InputParameters & parameters);
  virtual ~RedbackMassConvection()
  {
  }

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  const VariableGradient & _grad_temp;

  const MaterialProperty<RealVectorValue> & _pressure_convective_mass;
  const MaterialProperty<RealVectorValue> & _thermal_convective_mass;
  // MaterialProperty<RealVectorValue> & _convective_mass_jac_vec;
  // MaterialProperty<Real> & _convective_mass_jac_real;
  // MaterialProperty<RealVectorValue> & _convective_mass_off_diag_vec;
  // MaterialProperty<Real> & _convective_mass_off_diag_real;

  unsigned int _temp_var; // variable number of the temperature variable

private:
  Real _time_factor;
};

template <>
InputParameters validParams<RedbackMassConvection>();

#endif // REDBACKMASSCONVECTION_H
