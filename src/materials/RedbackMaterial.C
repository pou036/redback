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

#include "RedbackMaterial.h"

template<>
InputParameters validParams<RedbackMaterial>()
{
  InputParameters params = validParams<Material>();

  //params.addParam<Real>("phi0", 0, "initial porosity value.");
  params.addRangeCheckedParam<Real>("phi0", 0.0, "phi0>=0 & phi0<1", "initial porosity value.");
  params.addRangeCheckedParam<Real>("gr", "gr>=0", "Gruntfest number.");
  params.addParam<Real>("ref_lewis_nb", "Reference Lewis number.");
  params.addParam<Real>("ar", "Arrhenius number.");
  params.addParam<Real>("delta", 1, "Kamenetskii coefficient.");
  params.addParam<Real>("m", "Exponent for rate dependent plasticity (Perzyna)");
  params.addParam<bool>("is_chemistry_on", false, "is chemistry on?");
  params.addParam<bool>("are_convective_terms_on", false, "are convective terms on?");
  params.addCoupledVar("temperature", "Dimensionless temperature");
  params.addCoupledVar("pore_pres", "Dimensionless pore pressure");
  params.addCoupledVar("disp_x", "The x displacement");
  params.addCoupledVar("disp_y", "The y displacement");
  params.addCoupledVar("disp_z", "The z displacement");

  //params.addCoupledVar("solid_velocity_aux", "Solid velocity (AuxKernel) from RedbackMechMaterial (if used)");
  params.addParam<MooseEnum>("density_method", RedbackMaterial::densityMethodEnum() = "linear", "The method to describe density evolution with temperature and pore pressure"); // TODO: fluid, solid, mixture?...
  params.addParam<MooseEnum>("permeability_method", RedbackMaterial::permeabilityMethodEnum() = "KozenyCarman", "The method to describe permeability evolution");

  params.addParam<Real>("ar_F", "Arrhenius number for the forward reaction.");
  params.addParam<Real>("ar_R", "Arrhenius number for the reverse reaction.");
  params.addParam<Real>("da_endo", 0, "Damkoehler number for the endothermic reaction.");
  params.addParam<Real>("da_exo", 0, "Damkoehler number for the exothermic reaction.");
  params.addParam<Real>("mu", 0, "Chemical pressurization coefficient.");
  params.addParam<Real>("Kc", 0, "Equilibtium constant.");
  params.addParam<Real>("eta1", 1, "ratio of concentrations (see documentation).");
  params.addParam<Real>("eta2", 1, "ratio of concentrations (see documentation).");
  params.addRangeCheckedParam<Real>("Aphi","Aphi>=0 & Aphi<=1", "percentage of volume change from chemistry contributing to porosity (see documentation)");
  params.addParam<Real>("pressurization_coefficient", 0, "Pressurization coefficient (Lambda).");
  params.addParam<Real>("Peclet_number", 1, "Reference K/Pa quantity for Peclet number (delta*T_ref/sigma_ref)");

  params.addParam<Real>("solid_compressibility", 1, "solid compressibility (beta^{(s)} in 1/Pa)"); // _solid_compressibility_param
  params.addParam<Real>("fluid_compressibility", 0, "fluid compressibility (beta^{(f)} in 1/Pa)"); // _fluid_compressibility_param
  params.addParam<Real>("solid_thermal_expansion", 0, "solid expansion (lambda^{(s)} in 1/K)"); // _solid_thermal_expansion_param
  params.addParam<Real>("fluid_thermal_expansion", 0, "fluid expansion (lambda^{(f)} in 1/K)"); // _fluid_thermal_expansion_param
  params.addParam<Real>("solid_density", 2.5, "solid density in kg/m3"); // solid_density_param
  params.addParam<Real>("fluid_density", 1, "fluid density in kg/m3"); // fluid_density_param

  params.addParam<RealVectorValue>("gravity", RealVectorValue(), "Gravitational acceleration (m/s^2) as a vector pointing downwards.  Eg (0,0,-9.81)");
  return params;
}

RedbackMaterial::RedbackMaterial(const std::string & name, InputParameters parameters) :
  Material(name, parameters),
  _has_T(isCoupled("temperature")),
  _T(_has_T ? coupledValue("temperature") : _zero),
  _T_old(_has_T ? coupledValueOld("temperature") : _zero),

  _has_pore_pres(isCoupled("pore_pres")),
  _pore_pres(_has_pore_pres ? coupledValue("pore_pres") : _zero),
  //_pore_pres_old(_has_pore_pres ? coupledValueOld("pore_pres") : _zero),

  //_disp_x(isCoupled("disp_x") ? coupledValue("disp_x") : _zero),

  _phi0_param(getParam<Real>("phi0")),
  _gr_param(getParam<Real>("gr")),
  _ref_lewis_nb_param(getParam<Real>("ref_lewis_nb")),
  _ar_param(getParam<Real>("ar")),
  _delta_param(getParam<Real>("delta")),
  _m_param(getParam<Real>("m")),
  _peclet_number(getParam<Real>("Peclet_number")),
  _ar_F_param(getParam<Real>("ar_F")),
  _ar_R_param(getParam<Real>("ar_R")),
  _da_endo_param(getParam<Real>("da_endo")),
  _da_exo_param(getParam<Real>("da_exo")),
  _mu_param(getParam<Real>("mu")),
  _Kc_param(getParam<Real>("Kc")),
  _eta1_param(getParam<Real>("eta1")),
  _eta2_param(getParam<Real>("eta2")),
  _Aphi_param(getParam<Real>("Aphi")),
  _pressurization_coefficient_param(getParam<Real>("pressurization_coefficient")),

  _solid_compressibility_param(getParam<Real>("solid_compressibility")),
  _fluid_compressibility_param(getParam<Real>("fluid_compressibility")),
  _solid_thermal_expansion_param(getParam<Real>("solid_thermal_expansion")),
  _fluid_thermal_expansion_param(getParam<Real>("fluid_thermal_expansion")),
  _solid_density_param(getParam<Real>("solid_density")),
  _fluid_density_param(getParam<Real>("fluid_density")),

  _is_chemistry_on(getParam<bool>("is_chemistry_on")),
  _are_convective_terms_on(getParam<bool>("are_convective_terms_on")),

  _gravity_param(getParam<RealVectorValue>("gravity")),
  _mixture_gravity_term(declareProperty<RealVectorValue>("mixture_gravity_term")), //rho_mixture * g
  _fluid_gravity_term(declareProperty<RealVectorValue>("fluid_gravity_term")), //rho_fluid * g

  _gr(declareProperty<Real>("gr")),
  _ref_lewis_nb(declareProperty<Real>("ref_lewis_nb")),
  _ar(declareProperty<Real>("ar")),
  _delta(declareProperty<Real>("delta")),
  _m(declareProperty<Real>("m")),

  _porosity(declareProperty<Real>("porosity")),
  _lewis_number(declareProperty<Real>("lewis_number")),

  _mod_gruntfest_number(declareProperty<Real>("mod_gruntfest_number")),
  _mechanical_dissipation(declareProperty<Real>("mechanical_dissipation")),
  _mechanical_dissipation_jac(declareProperty<Real>("mechanical_dissipation_jacobian")),

  _ar_F(declareProperty<Real>("ar_F")),
  _ar_R(declareProperty<Real>("ar_R")),
  _mu(declareProperty<Real>("mu")),

  _chemical_porosity(declareProperty<Real>("chemical_porosity")),
  _solid_ratio(declareProperty<Real>("solid_ratio")),
  _chemical_endothermic_energy(declareProperty<Real>("chemical_endothermic_energy")),
  _chemical_endothermic_energy_jac(declareProperty<Real>("chemical_endothermic_energy_jacobian")),
  _chemical_exothermic_energy(declareProperty<Real>("chemical_exothermic_energy")),
  _chemical_exothermic_energy_jac(declareProperty<Real>("chemical_exothermic_energy_jacobian")),
  _chemical_source_mass(declareProperty<Real>("chemical_source_mass")),
  _chemical_source_mass_jac(declareProperty<Real>("chemical_source_mass_jacobian")),

  _thermal_convective_mass(declareProperty<RealVectorValue>("thermal_convective_mass")),
  _thermal_convective_mass_jac(declareProperty<RealVectorValue>("thermal_convective_mass_jacobian")),
  _pressure_convective_mass(declareProperty<RealVectorValue>("pressure_convective_mass")),
  _pressure_convective_mass_jac(declareProperty<RealVectorValue>("pressure_convective_mass_jacobian")),
  _mixture_convective_energy(declareProperty<RealVectorValue>("mixture_convective_energy")),
  _mixture_convective_energy_jac(declareProperty<RealVectorValue>("mixture_convective_energy_jacobian")),

  //_solid_velocity(declareProperty<RealVectorValue>("solid_velocity")),
  _fluid_velocity(declareProperty<RealVectorValue>("fluid_velocity")),
  _solid_compressibility(declareProperty<Real>("solid_compressibility")),
  _fluid_compressibility(declareProperty<Real>("fluid_compressibility")),
  _solid_thermal_expansion(declareProperty<Real>("solid_thermal_expansion")),
  _fluid_thermal_expansion(declareProperty<Real>("fluid_thermal_expansion")),

  _mixture_density(declareProperty<Real>("mixture_density")),

  _density_method((DensityMethod)(int)getParam<MooseEnum>("density_method")),
  _permeability_method((PermeabilityMethod)(int)getParam<MooseEnum>("permeability_method")),

  _mises_strain(declareProperty<Real>("mises_strain")),
  _mises_strain_rate(declareProperty<Real>("mises_strain_rate")),

  _pressurization_coefficient(declareProperty<Real>("pressurization_coefficient")),

  _grad_pore_pressure(coupledGradient("pore_pres")),
  //_grad_pore_pressure(_has_pore_pres ? coupledGradient("pore_pres") : _zero) // TODO: what if H is not activated?

  _dispx_dot(coupledDot("disp_x")), // TODO: what if no disp_x var?
  _dispy_dot(coupledDot("disp_y")),
  _dispz_dot(coupledDot("disp_z")),
  _solid_velocity(declareProperty<RealVectorValue>("solid_velocity"))

{
}

//=================================================================

MooseEnum
RedbackMaterial::densityMethodEnum()
{
  return MooseEnum("linear");
}

MooseEnum
RedbackMaterial::permeabilityMethodEnum()
{
  return MooseEnum("KozenyCarman");
}

/*void
RedbackMaterial::initQpStatefulProperties()
{
  std::cout << "initQpStatefulProperties at coords " << _q_point[_qp](0) << std::endl;
  //_useless_property_old[_qp] = 0; // TODO: find a better way to have a one off init
  // TODO: why is this function called twice???
  // TODO: apparently, _my_prop[_qp]=x here does not set properly for the element
  //      but overwrites every element with the same _qp. Why does it actually
  //      work usually???

  // Variable initialisation (one off)
  //_porosity[_qp] = _phi0_param + _q_point[_qp](0)/100.; // TODO: thomas playing
  //std::cout << "init _porosity[_qp]=" << _porosity[_qp] << " at coords " << _q_point[_qp](0) << std::endl;

  //_chemical_porosity[_qp]= 0;
  //_solid_ratio[_qp] = 0;
  //_mises_strain[_qp] = 0;
  //_solid_velocity[_qp] = RealVectorValue();
  //_fluid_velocity[_qp] = RealVectorValue();
}*/

void RedbackMaterial::stepInitQpProperties()
{
  // TODO: Variable initialisation we'd like done only once (one off)
  // but can't figure out how so doing it at every step...
  _porosity[_qp] = _phi0_param;
  _chemical_porosity[_qp]= 0;
  _solid_ratio[_qp] = 0;
  _mises_strain[_qp] = 0;
  _solid_velocity[_qp] = RealVectorValue(_dispx_dot[_qp], _dispy_dot[_qp], _dispz_dot[_qp]);// TODO, dimension dependent
  _fluid_velocity[_qp] = RealVectorValue();

  // Variable initialisation (called at each step)
  _gr[_qp] = _gr_param;
  _ref_lewis_nb[_qp] = _ref_lewis_nb_param;
  _ar[_qp] = _ar_param;
  _delta[_qp] = _delta_param;
  _m[_qp] = _m_param;
  _lewis_number[_qp] = _ref_lewis_nb[_qp];
  _ar_F[_qp] = _ar_F_param;
  _ar_R[_qp] = _ar_R_param;
  _mu[_qp] = _mu_param;
  _pressurization_coefficient[_qp] = _pressurization_coefficient_param;
  _solid_compressibility[_qp] = _solid_compressibility_param;
  _fluid_compressibility[_qp] = _fluid_compressibility_param;
  _solid_thermal_expansion[_qp] = _solid_thermal_expansion_param;
  _fluid_thermal_expansion[_qp] = _fluid_thermal_expansion_param;
  _mixture_density[_qp] = (1-_phi0_param)*_solid_density_param + _phi0_param*_fluid_density_param;
  _mixture_gravity_term[_qp] = _mixture_density[_qp]*_gravity_param;
  _fluid_gravity_term[_qp] = _fluid_density_param*_gravity_param;
}

void
RedbackMaterial::computeQpProperties()
{
  // Set our variables
  stepInitQpProperties();

  // Default Material method
  Material::computeQpProperties();

  //Compute the terms used in Redback Kernels
  computeRedbackTerms();
}

void
RedbackMaterial::computeRedbackTerms()
{
  Real omega_rel, temporary, phi_prime, s_prime;

  //TODO: put flags for all properties depending on activated variables.

  //TODO: do not compute these when mechanics is on (5 fields overwritten)
  _exponential = std::exp(-_ar[_qp])* std::exp(_ar[_qp]*_delta[_qp] *_T[_qp]/(1 + _delta[_qp] *_T[_qp]));
  // Compute modified Gruntfest number
  _mod_gruntfest_number[_qp]=_gr[_qp];
  // Compute Mises strain
  _mises_strain[_qp] = _exponential * _dt;
  // Compute Mises strain rate
  _mises_strain_rate[_qp] = _exponential;

  // Compute Mechanical Dissipation
  _mechanical_dissipation[_qp] = _gr[_qp] * std::pow(1 - _pore_pres[_qp], _m[_qp]) *
      std::exp( _ar[_qp]*_delta[_qp] *_T[_qp] / (1 + _delta[_qp] *_T[_qp]) );

  // Compute Mechanical Dissipation Jacobian
  _mechanical_dissipation_jac[_qp] = _gr[_qp] * std::pow(1 - _pore_pres[_qp], _m[_qp]) *
    _ar[_qp]*_delta[_qp] * std::exp( _ar[_qp]*_delta[_qp] *_T[_qp] / (1 + _delta[_qp] *_T[_qp]) ) /
    (1 + _delta[_qp] * _T[_qp]) / (1 + _delta[_qp] * _T[_qp]);

  if (_is_chemistry_on)
  {
    /*
    * The following calculates the volume ratios of a generic reversible reaction of the form:
    * AB_(solid) <-> A_(solid)  + B_(fluid)
    * The chemical porosity is the volume ration of B over the total volume V=V_A + V_B + V_AB
    * and the solid ratio is the volume of product A over the solid volume V_A+V_AB
    */

    // Step 1: calculate the relative rate of reactions
    omega_rel = _eta2_param * _Kc_param * std::exp(- (_ar_F[_qp]-_ar_R[_qp]) / (1 + _delta[_qp]*_T[_qp]) );

    // Step 2: calculate the solid ratio
    _solid_ratio[_qp] = omega_rel/(1 + omega_rel);

    // Step 3: calculate the chemical porosity and update the total porosity
    _chemical_porosity[_qp] = _Aphi_param*(1 - _phi0_param)/(1+_eta1_param/_solid_ratio[_qp]);
    _porosity[_qp] =  _phi0_param + _chemical_porosity[_qp];

    // Step 4: calculate the partial derivatives for the jacobian
    temporary = _eta2_param * _Kc_param * (_ar_F[_qp] - _ar_R[_qp]) *_delta[_qp] *
        std::exp( (_ar_F[_qp]-_ar_R[_qp]) / (1 + _delta[_qp]*_T[_qp]) ) / std::pow(1+_delta[_qp]*_T[_qp], 2) ;

    phi_prime = - temporary*_Aphi_param*_eta1_param*(1-_phi0_param) /
        std::pow(_eta1_param * std::exp( _ar_R[_qp] / (1 + _delta[_qp]*_T[_qp])) +
            (1 + _eta1_param)*
        std::exp( _ar_F[_qp] / (1 + _delta[_qp]*_T[_qp]) )* _eta2_param * _Kc_param, 2);

    s_prime = - temporary/std::pow(
         std::exp( _ar_R[_qp] / (1 + _delta[_qp]*_T[_qp])) +
         std::exp( _ar_F[_qp] / (1 + _delta[_qp]*_T[_qp]) )* _eta2_param * _Kc_param, 2);

    // Compute Endothermic Chemical Energy
    _chemical_endothermic_energy[_qp] = _da_endo_param * (1 - _porosity[_qp]) * (1 - _solid_ratio[_qp]) *
        std::exp( (_ar_F[_qp]*_delta[_qp]*_T[_qp]) / (1 + _delta[_qp]*_T[_qp]) );

    // Compute Endothermic Chemical Energy Jacobian
    _chemical_endothermic_energy_jac[_qp] = _da_endo_param * std::exp( (_ar_F[_qp]) / (1 + _delta[_qp]*_T[_qp]) ) *
        (
         _ar_F[_qp] * _delta[_qp] * (1 - _porosity[_qp]) * (1 - _solid_ratio[_qp])
            / std::pow(1+_delta[_qp]*_T[_qp], 2)
        - (1 - _solid_ratio[_qp]) * phi_prime
        - (1 - _porosity[_qp]) * s_prime
        );

    // Compute Exothermic Chemical Energy
    _chemical_exothermic_energy[_qp] = _da_exo_param * (1 - _porosity[_qp]) * _solid_ratio[_qp] * _chemical_porosity[_qp] *
        std::exp( (_ar_R[_qp]*_delta[_qp]*_T[_qp]) / (1 + _delta[_qp]*_T[_qp]) );

    // Compute Exothermic Chemical Energy Jacobian
    _chemical_exothermic_energy_jac[_qp] = _da_exo_param * std::exp( _ar_R[_qp] / (1 + _delta[_qp]*_T[_qp]) ) *
        (
          _solid_ratio[_qp]*(
         _ar_R[_qp] * _delta[_qp] * _chemical_porosity[_qp] *(1 - _porosity[_qp])
            / std::pow(1+_delta[_qp]*_T[_qp], 2)
        + (1 - _porosity[_qp] - _chemical_porosity[_qp]) * phi_prime )
        + _chemical_porosity[_qp]*(1 - _porosity[_qp]) * s_prime
        );

    // Compute Chemical Source/Sink Term for the mass (pore pressure) equation
    _chemical_source_mass[_qp] =  _mu[_qp]* (1 - _porosity[_qp]) * (1 - _solid_ratio[_qp]) *std::exp( (_ar_F[_qp]*_delta[_qp]*_T[_qp]) / (1 + _delta[_qp]*_T[_qp]) );

    // Compute Jacobian of Chemical Source/Sink Term for the mass (pore pressure) equation. The corresponding variable is pore pressure
    _chemical_source_mass_jac[_qp] = 0;

    // Update Lewis number
    _lewis_number[_qp] = _ref_lewis_nb[_qp]*std::pow((1-_porosity[_qp])/(1-_phi0_param), 2) * std::pow(_phi0_param/_porosity[_qp], 3);
  }

  // convective terms
  if (_are_convective_terms_on)
  {
    Real solid_density, fluid_density;
    Real beta_m_star, beta_solid, beta_fluid;
    Real lambda_m_star, lambda_solid, lambda_fluid;
    Real x_ref, sigma_ref; //TODO: derive them directly from mesh dimensions and problem at hand - user provided?
    RealVectorValue mixture_velocity, normalized_gravity;

    //Step 1: forming the partial densities and gravity terms
    switch (_density_method)
     {
     case linear:
       //Linear approximation of the EOS (Equation Of State)
       solid_density = _solid_density_param*(1 + _solid_compressibility[_qp]*_pore_pres[_qp] - _solid_thermal_expansion[_qp]*_T[_qp]); // TODO: move to AuxKernel
       fluid_density = _fluid_density_param*(1 + _fluid_compressibility[_qp]*_pore_pres[_qp] - _fluid_thermal_expansion[_qp]*_T[_qp]);
       break;
     default:
       mooseError("density method not implemented yet, use linear");
     }
    _mixture_density[_qp] = (1-_porosity[_qp])*solid_density+ _porosity[_qp]*fluid_density;

    //Terms feeding the stress equilibrium and Darcy flux
    x_ref = 1; sigma_ref = 1e6;
    normalized_gravity = _gravity_param*(x_ref/sigma_ref);

    _mixture_gravity_term[_qp] = _mixture_density[_qp]*normalized_gravity; //for the stress equilibrium equation
    _fluid_gravity_term[_qp] = fluid_density*normalized_gravity; //for Darcy's flux

    //Step 2: forming the compressibilities of the phases
    beta_solid = (1-_porosity[_qp])*_solid_compressibility[_qp]; //normalized compressibility of the solid phase
    beta_fluid = _porosity[_qp]*_fluid_compressibility[_qp]; //normalized compressibility of the fluid phase
    beta_m_star = beta_solid+ beta_fluid; // normalized compressibility of the mixture

    //Step 4: forming the thermal expansions of the phases
    lambda_solid = (1-_porosity[_qp])*_solid_thermal_expansion[_qp]; //normalized thermal expansion coefficient of the solid phase
    lambda_fluid = _porosity[_qp]*_fluid_thermal_expansion[_qp]; //normalized thermal expansion coefficient of the fluid phase
    lambda_m_star = lambda_solid + lambda_fluid; // normalized compressibility of the mixture

    //Step 4: forming the velocities through mechanics and Darcy's flow law
    _fluid_velocity[_qp] = _solid_velocity[_qp] - (_grad_pore_pressure[_qp] - fluid_density*normalized_gravity)/(_lewis_number[_qp]*_porosity[_qp]); //solving Darcy's flux for the fluid velocity
    mixture_velocity = (solid_density/_mixture_density[_qp])*_solid_velocity[_qp] + (fluid_density/_mixture_density[_qp])*_fluid_velocity[_qp]; //barycentric velocity for the mixture
    //_fluid_velocity[_qp] = _solid_velocity[_qp] - beta_m_star*(_grad_pore_pressure[_qp] - _fluid_density_param*_gravity_param)/(_lewis_number[_qp]*_porosity[_qp]); //solving Darcy's flux for the fluid velocity
    //mixture_velocity = (_solid_density_param/_mixture_density[_qp])*_solid_velocity[_qp] + (_fluid_density_param/_mixture_density[_qp])*_fluid_velocity[_qp]; //barycentric velocity for the mixture

    //Step 5: forming the kernels and their jacobians
    _pressure_convective_mass[_qp] = (beta_solid/beta_m_star)*_solid_velocity[_qp] + (beta_fluid/beta_m_star)*_fluid_velocity[_qp]; //convective term multiplying the pressure flux in the mass equation. TODO: disable for incompressible case
    _pressure_convective_mass_jac[_qp] = RealVectorValue(); //derivative with respect to pore pressure TODO: this is not equal to zero!!

    _thermal_convective_mass[_qp] = _peclet_number*(lambda_solid/beta_m_star)*_solid_velocity[_qp] + (lambda_fluid/beta_m_star)*_fluid_velocity[_qp]; //convective term multiplying the thermal flux in the mass equation
    _thermal_convective_mass_jac[_qp] = RealVectorValue();//derivative with respect to pore pressure TODO: this is not equal to zero!!

    _mixture_convective_energy[_qp] = mixture_velocity; //convective term multiplying the thermal flux in the energy equation
    _mixture_convective_energy_jac[_qp] = RealVectorValue(); //derivative with respect to temperature
  }
  return;
}
