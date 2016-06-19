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

#ifndef RedbackMaterial_UO_H
#define RedbackMaterial_UO_H

//#include "FiniteStrainPlasticMaterial.h"
#include "Material.h"

#include "RedbackElementParameters.h"

// Forward Declarations
class RedbackMaterial_UO;

template <>
InputParameters validParams<RedbackMaterial_UO>();

class RedbackMaterial_UO : public Material
{
public:
  RedbackMaterial_UO(const InputParameters & parameters);

  /// Static method for use in validParams for getting the continuation method
  static MooseEnum continuationMethodEnum();

  // various choices to decide which variable to use for continuation
  enum ContinuationMethod
  {
    Gruntfest,
    Lewis
  };

  /// Static method for use in validParams for getting the density method
  static MooseEnum densityMethodEnum();

  // various methods to handle density (variation with T and P)
  enum DensityMethod
  {
    linear
  };

  /// Static method for use in validParams for getting the permeability method
  static MooseEnum permeabilityMethodEnum();

  // various methods to handle permeability evolution
  enum PermeabilityMethod
  {
    KozenyCarman
  };

protected:
  virtual void stepInitQpProperties();
  virtual void computeQpProperties();
  virtual void computeRedbackTerms();

  bool _has_T;
  const VariableValue & _T;
  bool _has_pore_pres;

  const VariableValue & _pore_pres; //, & _pore_pres_old;
  const VariableValue & _total_porosity;
  const VariableValue & _inverse_lewis_number_tilde;
  const VariableValue & _concentration;
  const VariableValue & _continuation_parameter; // Coupled scalar variable value


  /*
   // Initialization has been removed - ultimately this will be handled by the user objects.

  // functionality to initialise some parameters from function (overwrites
  // initialisation as float)
  std::vector<std::string> _init_from_functions__params;
  std::vector<FunctionName> _init_from_functions__function_names;
  std::vector<Function *> _init_functions;
  int _num_init_functions;

  */

  Real _ar_F_param, _ar_R_param, _chemical_ar_F_factor, _da_endo_param, _da_exo_param, _mu_param, _Kc_param,
    _eta1_param, _eta2_param, _Aphi_param, _pressurization_coefficient_param;

  RealVectorValue _gravity_param;

  MaterialProperty<RealVectorValue> & _mixture_gravity_term;
  MaterialProperty<RealVectorValue> & _fluid_gravity_term;

  // the following constants will be controlled by the common redback material parameters block
  /*
  Real _phi0_param;
   Real _gr_param, _ref_lewis_nb_param, _ar_param, _delta_param

   Real _confining_pressure_param, _biot_coeff_param, _alpha_1_param, _alpha_2_param, _alpha_3_param,
    _peclet_number_param;

  Real _solid_compressibility_param, _fluid_compressibility_param, _solid_thermal_expansion_param,
    _fluid_thermal_expansion_param;

   */

  // these (I think) should remain as a material property...
  Real _solid_density_param, _fluid_density_param;

  /*
  MaterialProperty<Real> & _gr;
  MaterialProperty<Real> & _ar;
  MaterialProperty<Real> & _confining_pressure;
  MaterialProperty<Real> & _alpha_1;
  MaterialProperty<Real> & _alpha_2;
  MaterialProperty<Real> & _alpha_3;

  MaterialProperty<Real> & _delta;
  MaterialProperty<Real> & _initial_porosity;
  MaterialProperty<Real> & _peclet_number;

  MaterialProperty<Real> & _biot_coeff;

  MaterialProperty<Real> & _solid_compressibility;   // \bar(\beta_s)/\sigma_{ref}
  MaterialProperty<Real> & _fluid_compressibility;   // \bar(\beta_f)/\sigma_{ref}
  MaterialProperty<Real> & _solid_thermal_expansion; // \bar(\lambda_s)/ \delta T_ref
  MaterialProperty<Real> & _fluid_thermal_expansion; // \bar(\lambda_f)/delta T_ref

  MaterialProperty<Real> & _ref_lewis_nb;

  */

  // the container that holds all of the redback material parameters
  // NB it is "common" in the sense that it is shared by more than one entity
  const RedbackElementParameters* _common_redback_material_parameters;

  // the individual user objects that define the parameters used by the solver
  const RedbackMaterialParameterUserObject*  _gr_uo;
  const RedbackMaterialParameterUserObject*  _ar_uo;
  const RedbackMaterialParameterUserObject*  _confining_pressure_uo;
  const RedbackMaterialParameterUserObject*  _alpha_1_uo;
  const RedbackMaterialParameterUserObject*  _alpha_2_uo;
  const RedbackMaterialParameterUserObject*  _alpha_3_uo;

  const RedbackMaterialParameterUserObject*  _delta_uo;
  const RedbackMaterialParameterUserObject*  _initial_porosity_uo;
  const RedbackMaterialParameterUserObject*  _peclet_number_uo;

  //const RedbackMaterialParameterUserObject*  _biot_coeff_uo;

  const RedbackMaterialParameterUserObject*  _solid_compressibility_uo;   // \bar(\beta_s)/\sigma_{ref}
  const RedbackMaterialParameterUserObject*  _fluid_compressibility_uo;   // \bar(\beta_f)/\sigma_{ref}
  const RedbackMaterialParameterUserObject*  _solid_thermal_expansion_uo; // \bar(\lambda_s)/ \delta T_ref
  const RedbackMaterialParameterUserObject*  _fluid_thermal_expansion_uo; // \bar(\lambda_f)/delta T_ref

  const RedbackMaterialParameterUserObject*  _ref_lewis_nb_uo;

  // Idealy terms should be defined based on what is in the common container
  bool _is_mechanics_on, _is_chemistry_on, _are_convective_terms_on;


  MaterialProperty<Real> & _lewis_number;
  MaterialProperty<Real> & _mixture_compressibility;

  MaterialProperty<Real> & _mechanical_dissipation_no_mech;
  MaterialProperty<Real> & _mechanical_dissipation_jac_no_mech;

  MaterialProperty<Real> & _ar_F;
  MaterialProperty<Real> & _ar_R;
  MaterialProperty<Real> & _mu;

  MaterialProperty<Real> & _chemical_porosity;
  MaterialProperty<Real> & _solid_ratio;
  MaterialProperty<Real> & _chemical_endothermic_energy;
  MaterialProperty<Real> & _chemical_endothermic_energy_jac;
  MaterialProperty<Real> & _chemical_exothermic_energy;
  MaterialProperty<Real> & _chemical_exothermic_energy_jac;
  MaterialProperty<Real> & _chemical_source_mass;
  MaterialProperty<Real> & _chemical_source_mass_jac;

  MaterialProperty<RealVectorValue> & _thermal_convective_mass;
  MaterialProperty<RealVectorValue> & _pressure_convective_mass;
  MaterialProperty<RealVectorValue> & _mixture_convective_energy;

  MaterialProperty<RealVectorValue> & _fluid_velocity;

  MaterialProperty<Real> & _mixture_density;

  ContinuationMethod _continuation_method;
  DensityMethod _density_method;
  PermeabilityMethod _permeability_method;

  Real _exponential;

  MaterialProperty<Real> & _mises_strain;
  MaterialProperty<Real> & _mises_strain_rate;

  MaterialProperty<Real> & _pressurization_coefficient;

  const VariableGradient & _grad_temp;
  const VariableGradient & _grad_pore_pressure;

  const VariableValue & _dispx_dot;
  const VariableValue & _dispy_dot;
  const VariableValue & _dispz_dot;
  MaterialProperty<RealVectorValue> & _solid_velocity;

  Real _T0_param, _P0_param;

};

#endif // RedbackMaterial_UO_H
