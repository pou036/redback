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

#ifndef REDBACKMOOSEMECHMATERIAL_H
#define REDBACKMOOSEMECHMATERIAL_H

#include "Material.h"
#include "RankTwoTensor.h"
//#include "FiniteStrainPlasticMaterial.h"

// Forward Declarations
class RedbackMooseMechMaterial;

template <>
InputParameters validParams<RedbackMooseMechMaterial>();

/**
 * This class copy-pastes the stack from tensorMechanics module
 * TODO: add required features to moose and use proper tensorMechanics module
 */
class RedbackMooseMechMaterial : public Material
{
public:
  RedbackMooseMechMaterial(const InputParameters & parameters);

protected:
  // Copy-paste from TensorMechanicsMaterial.h
  virtual void computeQpProperties() override;
  virtual void initQpStatefulProperties() override;

  const VariableGradient & _grad_disp_x;
  const VariableGradient & _grad_disp_y;
  const VariableGradient & _grad_disp_z;

  const VariableGradient & _grad_disp_x_old;
  const VariableGradient & _grad_disp_y_old;
  const VariableGradient & _grad_disp_z_old;

  const MaterialProperty<RankTwoTensor> & _stress;
  const MaterialProperty<RankTwoTensor> & _total_strain;
  const MaterialProperty<RankTwoTensor> & _total_strain_old;
  const MaterialProperty<RankTwoTensor> & _elastic_strain;
  const MaterialProperty<RankTwoTensor> & _elastic_strain_old;

  // const VariableValue & _T;

  // Copy-paste from FiniteStrainMaterial.h
  const MaterialProperty<RankTwoTensor> & _strain_rate;

  // Copy-paste from FiniteStrainPlasticMaterial.h
  const MaterialProperty<RankTwoTensor> & _plastic_strain;
  const MaterialProperty<RankTwoTensor> & _plastic_strain_old;

  // virtual Real yieldFunction(const RankTwoTensor & stress, const Real
  // yield_stress);
  Real getSigEqv(const RankTwoTensor & stress);

  Real _chemo_mechanical_porosity_coeff;

  // Redback specific
  MaterialProperty<Real> & _mises_stress;
  MaterialProperty<Real> & _mean_stress;
  MaterialProperty<Real> & _mises_strain_rate;
  MaterialProperty<Real> & _volumetric_strain;
  MaterialProperty<Real> & _volumetric_strain_rate;
  MaterialProperty<Real> & _mechanical_porosity;
  MaterialProperty<Real> & _mass_removal_rate;
  MaterialProperty<Real> & _poromech_kernel;
  MaterialProperty<Real> & _poromech_jac;
  MaterialProperty<Real> & _mechanical_dissipation_mech;
  MaterialProperty<Real> & _mechanical_dissipation_jac_mech;

  // const VariableValue & _dispx_dot;
  // const VariableValue & _dispy_dot;
  // const VariableValue & _dispz_dot;

  // MaterialProperty<RealVectorValue> & _solid_velocity;

  // Using variables
  bool _has_T;
  const VariableValue & _T;
  const VariableValue & _T_old;
  bool _has_pore_pres;
  const VariableValue & _pore_pres;
  const VariableValue & _total_porosity;

  // Reading material properties from RedbackMaterial
  const MaterialProperty<Real> & _gr;
  const MaterialProperty<Real> & _lewis_number;
  const MaterialProperty<Real> & _ar;
  const MaterialProperty<Real> & _confining_pressure;
  const MaterialProperty<Real> & _alpha_1;
  const MaterialProperty<Real> & _alpha_2;
  const MaterialProperty<Real> & _alpha_3;

  const MaterialProperty<Real> & _delta;
  const MaterialProperty<Real> & _solid_thermal_expansion;
  const MaterialProperty<Real> & _solid_compressibility;
  const MaterialProperty<Real> & _mixture_compressibility;
  const MaterialProperty<Real> & _peclet_number;

  Real _T0_param, _P0_param;

  virtual void computeRedbackTerms();
};

#endif // REDBACKMOOSEMECHMATERIAL_H
