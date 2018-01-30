/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef REDBACKFLUIDMATERIAL_H
#define REDBACKFLUIDMATERIAL_H

//#include "FiniteStrainPlasticMaterial.h"
#include "Material.h"
#include "RankFourTensor.h"
#include "RankTwoTensor.h"

// Forward Declarations
class RedbackFluidMaterial;

template <>
InputParameters validParams<RedbackFluidMaterial>();

class RedbackFluidMaterial : public Material
{
public:
  RedbackFluidMaterial(const InputParameters & parameters);

protected:
  virtual void stepInitQpProperties();
  virtual void computeQpProperties() override;
  virtual void computeRedbackTerms();

  bool _has_T;
  const VariableValue & _T;
  bool _has_pore_pres;
  const VariableValue & _pore_pres; //, & _pore_pres_old;

  const VariableValue & _fluid_vel_x;
  const VariableValue & _fluid_vel_y;
  const VariableValue & _fluid_vel_z;

  const VariableGradient & _grad_fluid_vel_x;
  const VariableGradient & _grad_fluid_vel_y;
  const VariableGradient & _grad_fluid_vel_z;

  RealVectorValue _gravity_param;

  Real _peclet_number_param, _reynolds_number_param, _froude_number_param;

  MaterialProperty<RealVectorValue> & _gravity_term;
  MaterialProperty<Real> & _fluid_density;
  MaterialProperty<Real> & _div_fluid_vel;
  MaterialProperty<Real> & _div_fluid_kernel;
  MaterialProperty<Real> & _pressurization_coefficient;
  MaterialProperty<Real> & _peclet_number;
  MaterialProperty<Real> & _reynolds_number;
  MaterialProperty<Real> & _froude_number;
  MaterialProperty<Real> & _viscosity_ratio;
  MaterialProperty<RealVectorValue> & _thermal_convective_mass;
  MaterialProperty<RealVectorValue> & _pressure_convective_mass;
  MaterialProperty<RankTwoTensor> & _fluid_stress;
  // MaterialProperty<RankFourTensor> & _Jacobian_fluid_mult;

  Real _viscosity_ratio_param; //_bulk_viscosity_param, _dynamic_viscosity_param;
  Real _fluid_density_param, _fluid_compressibility_param, _fluid_thermal_expansion_param;

  const VariableGradient & _grad_temp;
  const VariableGradient & _grad_pore_pressure;

  Real _T0_param, _P0_param;

  // MaterialProperty<Real> & _Re;
};

#endif // REDBACKFLUIDMATERIAL_H
