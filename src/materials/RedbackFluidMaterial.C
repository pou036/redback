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

#include "RedbackFluidMaterial.h"

template<>
InputParameters validParams<RedbackFluidMaterial>()
{
  InputParameters params = validParams<Material>();

  params.addCoupledVar("temperature", 0.0, "Dimensionless temperature");
  params.addCoupledVar("pore_pres", 0.0, "Dimensionless pore pressure");
  params.addCoupledVar("fluid_vel_x", 0.0, "The x component of fluid velocity");
  params.addCoupledVar("fluid_vel_y", 0.0, "The y component of fluid velocity");
  params.addCoupledVar("fluid_vel_z", 0.0, "The z component of fluid velocity");
  params.addParam<Real>("bulk_viscosity", 0.0, "Fluid bulk viscosity (λ)");
  params.addParam<Real>("dynamic_viscosity", 0.0, "Fluid dynamic viscosity (μ)");
  params.addParam<Real>("fluid_density", 0.0, "Reference fluid density (\rho)");
  params.addParam<Real>("fluid_compressibility", 0, "Fluid compressibility (beta^{(f)} in 1/Pa)"); // _fluid_compressibility_param
  params.addParam<Real>("fluid_thermal_expansion", 0, "Fluid expansion (lambda^{(f)} in 1/K)"); // _fluid_thermal_expansion_param
  params.addParam<Real>("temperature_reference", 0.0, "Reference temperature used for thermal expansion");
  params.addParam<Real>("pressure_reference", 0.0, "Reference pressure used for compressibility");
  //params.addParam< Real >("biot_coefficient", 1.0, "Biot coefficient");

  params.addParam<RealVectorValue>("gravity", RealVectorValue(), "Gravitational acceleration (m/s^2) as a vector pointing downwards.  Eg '0 0 -9.81'");
  return params;
}

RedbackFluidMaterial::RedbackFluidMaterial(const InputParameters & parameters) :
  Material(parameters),
  _has_T(isCoupled("temperature")),
  _T(_has_T ? coupledValue("temperature") : _zero),

  _has_pore_pres(isCoupled("pore_pres")),
  _pore_pres(_has_pore_pres ? coupledValue("pore_pres") : _zero),

  _fluid_vel_x(coupledValue("fluid_vel_x")),
  _fluid_vel_y(coupledValue("fluid_vel_y")),
  _fluid_vel_z(coupledValue("fluid_vel_z")),

  _grad_fluid_vel_x(coupledGradient("fluid_vel_x")),
  _grad_fluid_vel_y(coupledGradient("fluid_vel_y")),
  _grad_fluid_vel_z(_mesh.dimension() == 3 ? coupledGradient("fluid_vel_z") : _grad_zero),

  _gravity_param(getParam<RealVectorValue>("gravity")),
  _gravity_term(declareProperty<RealVectorValue>("mixture_gravity_term")), // actually fluid gravity (but need to be called mixture for the kernel)

  _div_fluid_vel(declareProperty<Real>("divergence_of_fluid_velocity")),
  _div_fluid_kernel(declareProperty<Real>("divergence_fluid_velocity_kernel")),
  _pressurization_coefficient(declareProperty<Real>("pressurization_coefficient")),
  _thermal_convective_mass(declareProperty<RealVectorValue>("thermal_convective_mass")),
  _pressure_convective_mass(declareProperty<RealVectorValue>("pressure_convective_mass")),
  _stress(declareProperty<RankTwoTensor>("stress")),

  _Jacobian_mult(declareProperty<ElasticityTensorR4>("Jacobian_mult")),
  _biot_coeff(declareProperty<Real>("biot_coefficient")),

  _bulk_viscosity_param(getParam<Real>("bulk_viscosity")),
  _dynamic_viscosity_param(getParam<Real>("dynamic_viscosity")),
  _fluid_density_param(getParam<Real>("fluid_density")),
  _fluid_compressibility_param(getParam<Real>("fluid_compressibility")),
  _fluid_thermal_expansion_param(getParam<Real>("fluid_thermal_expansion")),
  _grad_temp(coupledGradient("temperature")),
  _grad_pore_pressure(coupledGradient("pore_pres")),
  _T0_param(getParam<Real>("temperature_reference")),
  _P0_param(getParam<Real>("pressure_reference"))
  //_biot_coeff_param(getParam<Real>("biot_coefficient"))
  //_Re_param(getParam<Real>("Reynolds_number")),
  //_Re(declareProperty<Real>("Re"))


{
  //_Re[_qp] = _Re_param;
}

//=================================================================


void RedbackFluidMaterial::stepInitQpProperties()
{
  _gravity_term[_qp] = _fluid_density_param*_gravity_param;
}

void
RedbackFluidMaterial::computeQpProperties()
{
  // Set our variables
  stepInitQpProperties();

  // Default Material method
  Material::computeQpProperties();

  //Compute the terms used in Redback Kernels
  computeRedbackTerms();
}

void
RedbackFluidMaterial::computeRedbackTerms()
{
  // Gravity term in the momentum kernel
  Real fluid_density;
  fluid_density = _fluid_density_param*(1 + _fluid_compressibility_param*(_pore_pres[_qp] - _P0_param) - _fluid_thermal_expansion_param*(_T[_qp] - _T0_param));
  _gravity_term[_qp] = fluid_density*_gravity_param;

  // Constitutive law
  RankTwoTensor grad_v(_grad_fluid_vel_x[_qp], _grad_fluid_vel_y[_qp], _grad_fluid_vel_y[_qp]);
  //Real second_viscosity = _bulk_viscosity_param + 2*_dynamic_viscosity_param/3.0; //zeta
  _div_fluid_vel[_qp] = _grad_fluid_vel_x[_qp](0) + _grad_fluid_vel_y[_qp](1) + _grad_fluid_vel_z[_qp](2);
  _stress[_qp].zero();
  _stress[_qp].addIa(_bulk_viscosity_param*_div_fluid_vel[_qp]);
  _stress[_qp] += _dynamic_viscosity_param*(grad_v + grad_v.transpose());
  _biot_coeff[_qp] = 1/_fluid_density_param; //_biot_coeff_param;
  _Jacobian_mult[_qp].zero();

  // Fluid divergence
  _div_fluid_kernel[_qp] = _div_fluid_vel[_qp]/_fluid_compressibility_param;

  // Assembling mass kernels components
  _pressurization_coefficient[_qp] = _fluid_thermal_expansion_param/_fluid_compressibility_param;
  RealVectorValue fluid_vel_vector = RealVectorValue(_fluid_vel_x[_qp], _fluid_vel_y[_qp], _fluid_vel_z[_qp]);
  _pressure_convective_mass[_qp] = _grad_pore_pressure[_qp]*fluid_vel_vector;
  _thermal_convective_mass[_qp] = _grad_temp[_qp]*fluid_vel_vector;

  return;
}
