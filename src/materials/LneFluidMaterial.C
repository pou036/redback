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

#include "LneFluidMaterial.h"

template <>
InputParameters
validParams<LneFluidMaterial>()
{
  InputParameters params = validParams<Material>();

  params.addCoupledVar("sat", 0.0, "Degree of saturation");
  params.addCoupledVar("pore_pres", 0.0, "Pore pressure");
  params.addParam<Real>("fluid_density", 1, "Reference fluid density (\rho)");
  params.addParam<Real>(
    "fluid_compressibility", 1, "Fluid compressibility (beta^{(f)} in 1/Pa)"); // default value is 1 even if the fluid
                                                                               // is not compressible because we often
                                                                               // divide by compressibility
  params.addParam<RealVectorValue>(
    "gravity",
    RealVectorValue(),
    "Gravitational acceleration (m/s^2) as a vector pointing downwards.  Eg '0 0 -9.81'");
  return params;
}

LneFluidMaterial::LneFluidMaterial(const InputParameters & parameters) :
    Material(parameters),
    _has_sat(isCoupled("sat")),
    _sat(_has_sat ? coupledValue("sat") : _zero),

    _has_pore_pres(isCoupled("pore_pres")),
    _pore_pres(_has_pore_pres ? coupledValue("pore_pres") : _zero),

    _gravity_param(getParam<RealVectorValue>("gravity")),

    _gravity_term(declareProperty<RealVectorValue>(
      "gravity_term")), // actually fluid gravity (but need to be called mixture for the kernel)

    _fluid_density(
      declareProperty<Real>("fluid_density")), // this fluid density is used in the stressdivergence kernel
    _dfluid_density(
      declareProperty<Real>("fluid_density derivative with pressure")), 
    _diffusivity(
      declareProperty<Real>("diffusivity")),     
    _ddiffusivity(
      declareProperty<Real>("diffusivity derivative with saturation")),         

    _fluid_density_param(getParam<Real>("fluid_density")),
    _fluid_compressibility_param(getParam<Real>("fluid_compressibility")),

    _grad_sat(coupledGradient("sat")),
    _grad_pore_pres(coupledGradient("pore_pres")),
    _T0_param(getParam<Real>("temperature_reference")),
    _P0_param(getParam<Real>("pressure_reference"))

{
}

//=================================================================

void
LneFluidMaterial::stepInitQpProperties()
{
  _fluid_density[ _qp ] = _fluid_density_param;
  _dfluid_density[ _qp ] = _fluid_compressibility_param ;  
  _diffusivity[ _qp ] = _fluid_density_param;
  _ddiffusivity[ _qp ] = _fluid_compressibility_param ;   
  _gravity_term[_qp] = _gravity_param;
}

void
LneFluidMaterial::computeQpProperties()
{
  // Set our variables
  stepInitQpProperties();

  // Default Material method
  Material::computeQpProperties();

  // Compute the terms used in Redback Kernels
  computeLneTerms();
}

void
LneFluidMaterial::computeLneTerms()
{
  _fluid_density[ _qp ] = (_fluid_density_param + _fluid_compressibility_param * _pore_pres[ _qp ]);
  _dfluid_density[ _qp ] = _fluid_compressibility_param ;  
  _diffusivity[ _qp ] = (_fluid_density_param + _fluid_compressibility_param * _pore_pres[ _qp ]);
  _ddiffusivity[ _qp ] = _fluid_compressibility_param ;    

  return;
}
