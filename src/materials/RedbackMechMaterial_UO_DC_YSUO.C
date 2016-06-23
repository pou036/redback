/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "Function.h"
#include "libmesh/quadrature.h"
#include "RedbackMechMaterial_UO_DC_YSUO.h"
#include "MooseMesh.h"

/**
RedbackMechMaterial_UO_DC_YSUO integrates the rate dependent plasticity model of Perzyna
(Overstress model) in a
finite strain framework using return mapping algorithm. Ideally this material
should inherit from both
the Redback material and the tensor mechanics finite strain equivalent

Three yield criteria are included:
1. pressure-independent (J2 plasticity)
2. linear pressure-dependent (Drucker-Prager with smoothing of the apex)
3. Non-linear, capped pressure dependent (modified cam clay)

Integration is performed for associative flow rules in an incremental manner
using Newton Raphson.
Isotropic hardening/softening has been incorporated where yield stress as a
function of equivalent
plastic strain has to be specified by the user.
*/

template <>
InputParameters
validParams<RedbackMechMaterial_UO_DC_YSUO>()
{
  InputParameters params = validParams<Material>();

  // Copy-paste from TensorMechanicsMaterial.C
  params.addRequiredCoupledVar("disp_x", "The x displacement");
  params.addRequiredCoupledVar("disp_y", "The y displacement");
  params.addCoupledVar("disp_z", 0.0, "The z displacement");
  params.addCoupledVar("temperature", 0.0, "temperature variable");
  params.addCoupledVar("damage", 0.0, "damage variable");

  // Copy-paste from FiniteStrainMaterial.C
  // nothing

  // Copy-paste from FiniteStrainPlasticMaterial.C
  // params.addRequiredParam< std::vector<Real> >("yield_stress", "Input data as
  // pairs of equivalent plastic strain and yield stress: Should start with
  // equivalent plastic strain 0");
  params.addParam<std::vector<Real> >("yield_stress",
                                      "Input data as pairs of equivalent "
                                      "plastic strain and yield stress: Should "
                                      "start with equivalent plastic strain 0");
  params.addParam<Real>("rtol", 1e-8, "Plastic strain NR tolerance");
  params.addParam<Real>("ftol", 1e-4, "Consistency condition NR tolerance");
  params.addParam<Real>("eptol", 1e-7, "Equivalent plastic strain NR tolerance");
  params.addClassDescription("Associative overstress plasticity");

  //  Copy-paste from FiniteStrainPlasticRateMaterial.C
  params.addParam<Real>("ref_pe_rate",
                        1.0,
                        "Reference plastic strain rate "
                        "parameter for rate dependent "
                        "plasticity (Overstress model)");
  params.addParam<Real>("exponent", 1.0, "Exponent for rate dependent plasticity (Perzyna)");
  params.addParam<Real>(
    "chemo_mechanical_porosity_coeff", 1.0, "The coefficient of volumetric plastic strain in chemical porosity");

  params.addCoupledVar("pore_pres", 0.0, "Dimensionless pore pressure");
 // params.addRequiredParam<Real>("youngs_modulus", "Youngs modulus.");
 //  params.addRequiredParam<Real>("poisson_ratio", "Poisson ratio.");

  // For the damage mechanics functionality
  params.addParam<Real>("damage_coefficient", 0.0, "The fraction of energies used in damage flow law (e.g. E_D/E_D0)");
  params.addParam<Real>("damage_exponent", 0.0, "The damage exponent in the incremental flow law of plasticity");
  params.addParam<Real>(
    "healing_coefficient", 0.0, "The fraction of energies used in healing flow law (e.g. E_H/E_H0)");
  params.addParam<MooseEnum>("damage_method",
                             RedbackMechMaterial_UO_DC_YSUO::damageMethodEnum() = "CreepDamage",
                             "The method to describe damage evolution");

  params.addCoupledVar("total_porosity", 0.0, "The total porosity (as AuxKernel)");
  params.addParam<Real>("temperature_reference", 0.0, "Reference temperature used for thermal expansion");
  params.addParam<Real>("pressure_reference", 0.0, "Reference pressure used for compressibility");

  params.addRequiredParam<UserObjectName>("redback_material_parameters","Element parameters common to redback materials and kernels");

  return params;
}

RedbackMechMaterial_UO_DC_YSUO::RedbackMechMaterial_UO_DC_YSUO(const InputParameters & parameters) :
    Material(parameters),
    // Copy-paste from TensorMechanicsMaterial.C
    _grad_disp_x(coupledGradient("disp_x")),
    _grad_disp_y(coupledGradient("disp_y")),
    _grad_disp_z(_mesh.dimension() == 3 ? coupledGradient("disp_z") : _grad_zero),
    _grad_disp_x_old(_fe_problem.isTransient() ? coupledGradientOld("disp_x") : _grad_zero),
    _grad_disp_y_old(_fe_problem.isTransient() ? coupledGradientOld("disp_y") : _grad_zero),
    _grad_disp_z_old(_fe_problem.isTransient() && _mesh.dimension() == 3 ? coupledGradientOld("disp_z") : _grad_zero),
    _stress(declareProperty<RankTwoTensor>("stress")),
    _total_strain(declareProperty<RankTwoTensor>("total_strain")),
    _elastic_strain(declareProperty<RankTwoTensor>("elastic_strain")),
    _elasticity_tensor(getMaterialPropertyByName<RankFourTensor>("elasticity_tensor")),
    _Jacobian_mult(declareProperty<RankFourTensor>("Jacobian_mult")),
    // _d_stress_dT(declareProperty<RankTwoTensor>("d_stress_dT")),
   // _Cijkl(),

    // Copy-paste from FiniteStrainMaterial.C
    _strain_rate(getMaterialPropertyByName<RankTwoTensor>("strain_rate")),
    _strain_increment(getMaterialPropertyByName<RankTwoTensor>("strain_increment")),
    _total_strain_old(declarePropertyOld<RankTwoTensor>("total_strain")),
    _elastic_strain_old(declarePropertyOld<RankTwoTensor>("elastic_strain")),
    _stress_old(declarePropertyOld<RankTwoTensor>("stress")),
    _rotation_increment(getMaterialPropertyByName<RankTwoTensor>("rotation_increment")),
    _dfgrd(declareProperty<RankTwoTensor>("deformation gradient")),

    // Copy-paste from FiniteStrainPlasticMaterial.C
    _yield_stress_vector(getParam<std::vector<Real> >("yield_stress")), // Read from input file
    _plastic_strain(declareProperty<RankTwoTensor>("plastic_strain")),
    _plastic_strain_old(declarePropertyOld<RankTwoTensor>("plastic_strain")),
    _eqv_plastic_strain(declareProperty<Real>("eqv_plastic_strain")),
    _eqv_plastic_strain_old(declarePropertyOld<Real>("eqv_plastic_strain")),

    // Copy-paste from FiniteStrainPlasticRateMaterial.C
    _ref_pe_rate(getParam<Real>("ref_pe_rate")),
    _exponent(getParam<Real>("exponent")),
    _chemo_mechanical_porosity_coeff(getParam<Real>("chemo_mechanical_porosity_coeff")),

    // Redback
   // _youngs_modulus(getParam<Real>("youngs_modulus")),
   // _poisson_ratio(getParam<Real>("poisson_ratio")),
    _mises_stress(declareProperty<Real>("mises_stress")),
    _mean_stress(declareProperty<Real>("mean_stress")),
    _mises_strain_rate(declareProperty<Real>("mises_strain_rate")),
    _volumetric_strain(declareProperty<Real>("volumetric_strain")),
    _volumetric_strain_rate(declareProperty<Real>("volumetric_strain_rate")),
    _total_volumetric_strain(declareProperty<Real>("total_volumetric_strain")),
    _mechanical_porosity(declareProperty<Real>("mechanical_porosity")),
    _mass_removal_rate(declareProperty<Real>("mass_removal_rate")),

    _poromech_kernel(declareProperty<Real>("poromechanics_kernel")),
    _poromech_jac(declareProperty<Real>("poromechanics_jacobian")),
    _mod_gruntfest_number(declareProperty<Real>("mod_gruntfest_number")),
    _mechanical_dissipation_mech(declareProperty<Real>("mechanical_dissipation_mech")),
    _mechanical_dissipation_jac_mech(declareProperty<Real>("mechanical_dissipation_jacobian_mech")),

    _damage_kernel(declareProperty<Real>("damage_kernel")),
    _damage_kernel_jac(declareProperty<Real>("damage_kernel_jacobian")),
    _damage_coeff(getParam<Real>("damage_coefficient")),
    _dmg_exponent(getParam<Real>("damage_exponent")),
    _healing_coeff(getParam<Real>("healing_coefficient")),

    // Get coupled variables (T & P & porosity & damage)
    _has_T(isCoupled("temperature")),
    _T(_has_T ? coupledValue("temperature") : _zero),
    _T_old(_has_T ? coupledValueOld("temperature") : _zero),
    _has_pore_pres(isCoupled("pore_pres")),
    _pore_pres(_has_pore_pres ? coupledValue("pore_pres") : _zero),
    _total_porosity(coupledValue("total_porosity")), // total_porosity MUST be
                                                     // coupled! Check that
                                                     // (TODO)
    _has_D(isCoupled("damage")),
    //_damage(_has_D ? coupledValue("damage") : _zero),
    //_damage_old(_has_D ? coupledValueOld("damage") : _zero),
    _damage(coupledValue("damage")),
    _damage_old(coupledValueOld("damage")),

    _damage_method((DamageMethod)(int)getParam<MooseEnum>("damage_method")),

    // Get some material properties from RedbackMaterial
	/*
    _gr(getMaterialProperty<Real>("gr")),
    _ar(getMaterialProperty<Real>("ar")),
    _confining_pressure(getMaterialProperty<Real>("confining_pressure")),
    _alpha_1(getMaterialProperty<Real>("alpha_1")),
    _alpha_2(getMaterialProperty<Real>("alpha_2")),
    _alpha_3(getMaterialProperty<Real>("alpha_3")),
    _delta(getMaterialProperty<Real>("delta")),
    _solid_thermal_expansion(getMaterialProperty<Real>("solid_thermal_expansion")),
    _solid_compressibility(getMaterialProperty<Real>("solid_compressibility")),
    _peclet_number(getMaterialProperty<Real>("Peclet_number")),
    */

	_mixture_compressibility(getMaterialProperty<Real>("mixture_compressibility")),
	_lewis_number(getMaterialProperty<Real>("lewis_number")),

    _returnmap_iter(declareProperty<Real>("returnmap_iter")),

    _T0_param(getParam<Real>("temperature_reference")),
	_P0_param(getParam<Real>("pressure_reference"))
{

  // common redback material parameters
  UserObjectName rep_uo_name = getParam<UserObjectName>("redback_material_parameters");
  _common_redback_material_parameters = &getUserObjectByName<RedbackElementParameters>( rep_uo_name);

  // extract pointers to active parameters
  _ar_uo = _common_redback_material_parameters->GetRequiredParameterObject(RedbackParameters::ar.str);
  _gr_uo = _common_redback_material_parameters->GetRequiredParameterObject(RedbackParameters::gr.str);
  _confining_pressure_uo = _common_redback_material_parameters->GetRequiredParameterObject(RedbackParameters::confiningPressure.str);
  _alpha_1_uo = _common_redback_material_parameters->GetRequiredParameterObject(RedbackParameters::alpha1.str);
  _alpha_2_uo = _common_redback_material_parameters->GetRequiredParameterObject(RedbackParameters::alpha2.str);
  _alpha_3_uo = _common_redback_material_parameters->GetRequiredParameterObject(RedbackParameters::alpha3.str);

  _delta_uo= _common_redback_material_parameters->GetRequiredParameterObject(RedbackParameters::delta.str);

  _solid_thermal_expansion_uo = _common_redback_material_parameters->GetRequiredParameterObject(RedbackParameters::solidThermalExpansion.str);
  _solid_compressibility_uo = _common_redback_material_parameters->GetRequiredParameterObject(RedbackParameters::solidCompressiblity.str);

  _peclet_number_uo = _common_redback_material_parameters->GetRequiredParameterObject(RedbackParameters::PecletNumber.str);


  _plastic_model = _common_redback_material_parameters->GetPlasticModel();

// these should be set by the elastic component
  /*
//  Real E = _youngs_modulus;
//  Real nu = _poisson_ratio;
  Real l1 = E * nu / (1 + nu) / (1 - 2 * nu); // First Lame modulus
  Real l2 = 0.5 * E / (1 + nu);               // Second Lame modulus (shear)
  Real input_array[] = { l1, l2 };
  std::vector<Real> input_vector(input_array, input_array + 2);

  // Choose fill method, hardcoded.
  MooseEnum fill_method = RankFourTensor::fillMethodEnum();
  fill_method = "symmetric_isotropic"; // Creates symmetric and isotropic
                                       // elasticity tensor.
  _Cijkl.fillFromInputVector(input_vector, (RankFourTensor::FillMethod)(int)fill_method);

*/

}

MooseEnum
RedbackMechMaterial_UO_DC_YSUO::damageMethodEnum()
{
  return MooseEnum("BrittleDamage CreepDamage BreakageMechanics DamageHealing FromMultiApp");
}

void
RedbackMechMaterial_UO_DC_YSUO::initQpStatefulProperties()
{
  // called only once at the very beginning of the simulation
  _total_strain[ _qp ].zero();
  _elastic_strain[ _qp ].zero();
  _stress[ _qp ].zero();
  _plastic_strain[ _qp ].zero();
  _eqv_plastic_strain[ _qp ] = 0.0;
  //_elasticity_tensor[ _qp ].zero();
  _Jacobian_mult[ _qp ].zero();
 // _strain_rate[ _qp ].zero();
 // _strain_increment[ _qp ].zero();
 // _rotation_increment[ _qp ].zero();
  _dfgrd[ _qp ].zero();

  // Redback properties
  _mises_stress[ _qp ] = 0;
  _mean_stress[ _qp ] = 0;
  _mises_strain_rate[ _qp ] = 0;
  _volumetric_strain[ _qp ] = 0;
  _volumetric_strain_rate[ _qp ] = 0;
  _total_volumetric_strain[ _qp ] = 0;
  _mechanical_porosity[ _qp ] = 0;
  _poromech_kernel[ _qp ] = 0;
  _poromech_jac[ _qp ] = 0;
  _mod_gruntfest_number[ _qp ] = 0;
  _mechanical_dissipation_mech[ _qp ] = 0;
  _mechanical_dissipation_jac_mech[ _qp ] = 0;
  _damage_kernel[ _qp ] = 0;
  _damage_kernel_jac[ _qp ] = 0;
  _mass_removal_rate[ _qp ] = 0;
}

void
RedbackMechMaterial_UO_DC_YSUO::computeProperties()
{
  // computeStrain();
  for (_qp = 0; _qp < _qrule->n_points(); ++_qp)
  {
   // stepInitQpProperties();
    computeQpElasticityTensor();  // this applies damage rule to elasticity tensor - do externally? - or add a user function
    computeQpStress();
  }
}

void
RedbackMechMaterial_UO_DC_YSUO::stepInitQpProperties()
{
}

void
RedbackMechMaterial_UO_DC_YSUO::computeQpElasticityTensor()
{
  // Fill in the matrix stiffness material property
  //_elasticity_tensor[ _qp ] = _Cijkl * (1 - _damage[ _qp ]);
  _Jacobian_mult[ _qp ] = _elasticity_tensor[ _qp ]; // _Cijkl  * (1 - _damage[ _qp ]);
}


void
RedbackMechMaterial_UO_DC_YSUO::computeQpStrain()
{
  mooseError("Wrong computeQpStrain called in RedbackMechMaterial_UO_DC_YSUO");
}

void
RedbackMechMaterial_UO_DC_YSUO::computeQpStress()
{
  RankTwoTensor dp, sig;
  Real p_y, q_y; // volumetric (p) and deviatoric (q) projections of yield stress

  // Obtain previous plastic rate of deformation tensor
  dp = _plastic_strain_old[ _qp ];

  // Solve J2 plastic constitutive equations based on current strain increment
  // Returns current  stress and plastic rate of deformation tensor
  _returnmap_iter[ _qp ] = 0;
  returnMap(_stress_old[ _qp ], _strain_increment[ _qp ], _elasticity_tensor[ _qp ], dp, sig, p_y, q_y);
  _stress[ _qp ] = sig;

  // Rotate the stress to the current configuration
  _stress[ _qp ] = _rotation_increment[ _qp ] * _stress[ _qp ] * _rotation_increment[ _qp ].transpose();

  // Updates current plastic rate of deformation tensor
  _plastic_strain[ _qp ] = dp;

  // Evaluate and update current equivalent and volumetric plastic strain
  _eqv_plastic_strain[ _qp ] = std::pow(2.0 / 3.0, 0.5) * dp.L2norm();
  _volumetric_strain[ _qp ] = dp.trace();

  // Calculate elastic strain increment
  RankTwoTensor delta_ee = _strain_increment[ _qp ] - (_plastic_strain[ _qp ] - _plastic_strain_old[ _qp ]);

  // Update elastic strain tensor in intermediate configuration
  _elastic_strain[ _qp ] = _elastic_strain_old[ _qp ] + delta_ee;

  // Rotate elastic strain tensor to the current configuration
  _elastic_strain[ _qp ] =
    _rotation_increment[ _qp ] * _elastic_strain[ _qp ] * _rotation_increment[ _qp ].transpose();

  // Rotate to plastic rate of deformation tensor the current configuration
  _plastic_strain[ _qp ] =
    _rotation_increment[ _qp ] * _plastic_strain[ _qp ] * _rotation_increment[ _qp ].transpose();

  // Update strain in intermediate configuration
  _total_strain[ _qp ] = _total_strain_old[ _qp ] + _strain_increment[ _qp ];
  /*RankTwoTensor grad_tensor(_grad_disp_x[_qp], _grad_disp_y[_qp],
  _grad_disp_z[_qp]);
  RankTwoTensor total_strain_small_deformation = ( grad_tensor +
  grad_tensor.transpose() )/2.0;*/

  // Rotate strain to current configuration
  _total_strain[ _qp ] = _rotation_increment[ _qp ] * _total_strain[ _qp ] * _rotation_increment[ _qp ].transpose();
  _total_volumetric_strain[ _qp ] = _total_strain[ _qp ].trace();

  // Compute the energy dissipation and the properties declared
  computeRedbackTerms(sig, q_y, p_y);
}

// Delta Function
Real
RedbackMechMaterial_UO_DC_YSUO::deltaFunc(const unsigned int i, const unsigned int j)
{
  if (i == j)
    return 1.0;
  else
    return 0.0;
}

// Obtain yield stress for a given equivalent plastic strain (input)
Real
RedbackMechMaterial_UO_DC_YSUO::getYieldStress(const Real eqpe)
{
  unsigned nsize;

  nsize = _yield_stress_vector.size();

  if (_yield_stress_vector[ 0 ] > 0.0 || nsize % 2 > 0) // Error check for input inconsitency
    mooseError("Error in yield stress input: Should be a vector with eqv "
               "plastic strain and yield stress pair values.\n");

  unsigned int ind = 0;
  Real tol = 1e-8;

  while (ind < nsize)
  {
    if (std::abs(eqpe - _yield_stress_vector[ ind ]) < tol)
      return _yield_stress_vector[ ind + 1 ];

    if (ind + 2 < nsize)
    {
      if (eqpe > _yield_stress_vector[ ind ] && eqpe < _yield_stress_vector[ ind + 2 ])
        return _yield_stress_vector[ ind + 1 ] +
               (eqpe - _yield_stress_vector[ ind ]) / (_yield_stress_vector[ ind + 2 ] - _yield_stress_vector[ ind ]) *
                 (_yield_stress_vector[ ind + 3 ] - _yield_stress_vector[ ind + 1 ]);
    }
    else
      return _yield_stress_vector[ nsize - 1 ];

    ind += 2;
  }

  return 0.0;
}

Real
RedbackMechMaterial_UO_DC_YSUO::macaulayBracket(Real val)
{
  if (val > 0.0)
    return val;
  else
    return 0.0;
}

void
RedbackMechMaterial_UO_DC_YSUO::computeRedbackTerms(RankTwoTensor & sig, Real q_y, Real p_y)
{
  Real delta_phi_mech_el, delta_phi_mech_pl; // elastic and plastic
                                             // delta_porosity components for
                                             // that step
  Real def_grad, def_grad_old, def_grad_rate;
  // update velocities
  //_solid_velocity[_qp] = RealVectorValue(_dispx_dot[_qp], _dispy_dot[_qp],
  //_dispz_dot[_qp]);// TODO

  // Material::computeRedbackTerms();

  // Compute stresses
  _mises_stress[ _qp ] = getSigEqv(sig);
  _mean_stress[ _qp ] = sig.trace() / 3.0;

  // Compute plastic strains
  RankTwoTensor instantaneous_strain_rate, total_volumetric_strain_rate;

  if (_dt == 0)
  {
    instantaneous_strain_rate.zero();
    total_volumetric_strain_rate.zero();
  }
  else
  {
    instantaneous_strain_rate = (_plastic_strain[ _qp ] - _plastic_strain_old[ _qp ]) / _dt;
    total_volumetric_strain_rate = (_total_strain[ _qp ] - _total_strain_old[ _qp ]) / _dt;
  }
  _mises_strain_rate[ _qp ] = std::pow(2.0 / 3.0, 0.5) * instantaneous_strain_rate.L2norm();
  _volumetric_strain_rate[ _qp ] = total_volumetric_strain_rate.trace();
  def_grad = _grad_disp_x[ _qp ](0) + _grad_disp_y[ _qp ](1) + _grad_disp_z[ _qp ](2);
  def_grad_old = _grad_disp_x_old[ _qp ](0) + _grad_disp_y_old[ _qp ](1) + _grad_disp_z_old[ _qp ](2);
  def_grad_rate = (def_grad - def_grad_old) / _dt;

  // Update mechanical porosity (elastic and plastic components)
  // TODO: set T0 properly (once only, at the very beginning). Until then, T = T
  // - T0, P = P - P0

  const RedbackMaterialParameterUserObject& solid_compressibility = *_solid_compressibility_uo;
  const RedbackMaterialParameterUserObject& solid_thermal_expansion = *_solid_thermal_expansion_uo;
  const RedbackMaterialParameterUserObject& ar = *_ar_uo;
  const RedbackMaterialParameterUserObject& gr = *_gr_uo;

  const RedbackMaterialParameterUserObject& delta = *_delta_uo;

  const RedbackMaterialParameterUserObject& peclet_number = *_peclet_number_uo;

  delta_phi_mech_el =
    (1.0 - _total_porosity[ _qp ]) * (solid_compressibility[ _qp ] * (_pore_pres[ _qp ] - _P0_param) -
                                      solid_thermal_expansion[ _qp ] * (_T[ _qp ] - _T0_param) +
                                      (_elastic_strain[ _qp ] - _elastic_strain_old[ _qp ]).trace());
  delta_phi_mech_pl = (1.0 - _total_porosity[ _qp ]) * (_plastic_strain[ _qp ] - _plastic_strain_old[ _qp ]).trace();

  _mechanical_porosity[ _qp ] = delta_phi_mech_el + delta_phi_mech_pl;

  Real gruntfest_number;

  if (_has_D)
  {
    _mechanical_porosity[ _qp ] += std::pow(_damage[ _qp ], 3 / 2);

    switch (_damage_method)
    {
      case BrittleDamage:
        formDamageDissipation(sig);
        break;
      case CreepDamage:
        formDamageDissipation(sig);
        break;
      case BreakageMechanics:
        formDamageDissipation(sig);
        break;
      case DamageHealing:
        formDamageDissipation(sig);
        break;
      default:
        mooseError("damage method not implemented yet, use other options");
    }

    form_damage_kernels(q_y);
  }

  gruntfest_number = gr[ _qp ] * std::exp(ar[ _qp ]);

  // Compute Mechanical Dissipation.
  _mechanical_dissipation_mech[ _qp ] = gruntfest_number * sig.doubleContraction(instantaneous_strain_rate) +
                                        _damage_dissipation; // The negative sign in damage dissipation is
                                                             // according
                                                             // to thermodynamics with internal state variables (see
                                                             // Rosakis et al, 2000)
  /* The following loop can ensure positive mechanical dissipation.
   * if (_mechanical_dissipation_mech[_qp] < 0)
  {
          mooseWarning("Dissipation is negative. Check the reason!");
  }*/

  // Compute Mechanical Dissipation Jacobian
  _mechanical_dissipation_jac_mech[ _qp ] =
    _mechanical_dissipation_mech[ _qp ] / (1 + delta[ _qp ] * _T[ _qp ]) / (1 + delta[ _qp ] * _T[ _qp ]);

  _poromech_kernel[ _qp ] = def_grad_rate * peclet_number[ _qp ] / _mixture_compressibility[ _qp ];
  _poromech_jac[ _qp ] = (1 / (1 + delta[ _qp ] * _T[ _qp ]) / (1 + delta[ _qp ] * _T[ _qp ]));

  // Compute the equivalent Gruntfest number for comparison with SuCCoMBE TODO:
  // Remove this number from the tests!!!
  _mod_gruntfest_number[ _qp ] =
    gruntfest_number * std::exp(-ar[ _qp ]) *
    (std::fabs(getSigEqv(sig) * std::pow(macaulayBracket(getSigEqv(sig) / q_y - 1.0), _exponent)) +
     std::fabs(_mean_stress[ _qp ] * std::pow(macaulayBracket(_mean_stress[ _qp ] - p_y), _exponent)));

  // Begin of the chemical degradation method of Hu and Hueckel 2013 (doi:10.1680/geot.SIP13.P.020)
  // _mass_removal_rate[_qp] = 0;
  Real total_energy_input = sig.doubleContraction(instantaneous_strain_rate);

  _mass_removal_rate[ _qp ] = _chemo_mechanical_porosity_coeff * (1 + total_energy_input);
  if (_volumetric_strain[ _qp ] > 0)
  {
    _mass_removal_rate[ _qp ] = _chemo_mechanical_porosity_coeff * _volumetric_strain[ _qp ];
  }
  // End of the chemical degradation method of Hu and Hueckel 2013

  // formulate the Taylor-Quinney coefficient and Gruntfest numbers for the case
  // of damage

  return;
}

void
RedbackMechMaterial_UO_DC_YSUO::computeQpStrain(const RankTwoTensor & Fhat)
{
// no longer required
}

Real
RedbackMechMaterial_UO_DC_YSUO::getSigEqv(const RankTwoTensor & stress)
{
  return std::pow(3 * stress.secondInvariant(), 0.5);
}

void
RedbackMechMaterial_UO_DC_YSUO::returnMap(const RankTwoTensor & sig_old,
                               const RankTwoTensor & delta_d,
                               const RankFourTensor & E_ijkl,
                               RankTwoTensor & dp,
                               RankTwoTensor & sig,
                               Real & p_y,
                               Real & q_y)
{
  RankTwoTensor sig_new, delta_dp, dpn;
  RankTwoTensor flow_tensor;
  RankTwoTensor resid, ddsig;
  RankFourTensor dr_dsig, dr_dsig_inv;
  Real flow_incr;
  Real p, q;
  Real err1, err3, tol1, tol3;
  unsigned int iterisohard, iter, maxiterisohard = 20, maxiter = 50;
  Real eqvpstrain, mean_stress_old;
  // Real volumetric_plastic_strain;
  Real yield_stress, yield_stress_prev;

  tol1 = 1e-10; // TODO: expose to user interface and/or make the tolerance
                // relative
  tol3 = 1e-6;  // TODO: expose to user interface and/or make the tolerance relative
  err3 = 1.1 * tol3;
  iterisohard = 0;

  // volumetric_plastic_strain = dp.trace();
  mean_stress_old = sig_old.trace() / 3.0;
  eqvpstrain = std::pow(2.0 / 3.0, 0.5) * dp.L2norm();
  yield_stress = getYieldStress(eqvpstrain);

  // calculate the term _exponential = -Q_{mech}/(RT) with Q_{mech} = E_0 + p'c
  // V_{ref} + p_f V_{act}
  _exponential = 1;
  if (_has_D)
  {
    _exponential *= std::pow(1 - _damage[ _qp ], -_dmg_exponent);
  }
  if (_has_T)
  {

	const RedbackMaterialParameterUserObject& ar = *_ar_uo;
	const RedbackMaterialParameterUserObject& delta = *_delta_uo;
    // E_0/(RT) = Ar/(1+delta T*)
    _exponential =
      std::exp(-ar[ _qp ]) * std::exp(ar[ _qp ] * delta[ _qp ] * _T[ _qp ] / (1 + delta[ _qp ] * _T[ _qp ]));
  }

  // The following expression should be further pursued for a forward
  // physics-based model

  const RedbackMaterialParameterUserObject& alpha_1 = *_alpha_1_uo;
  const RedbackMaterialParameterUserObject& alpha_2 = *_alpha_2_uo;
  const RedbackMaterialParameterUserObject& alpha_3 = *_alpha_3_uo;
  const RedbackMaterialParameterUserObject& confining_pressure = *_confining_pressure_uo;
  _exponential = _exponential * std::exp(-alpha_1[ _qp ] * confining_pressure[ _qp ] -
                                         _pore_pres[ _qp ] * alpha_2[ _qp ] *
                                           (1 + alpha_3[ _qp ] * std::log( confining_pressure[ _qp ] + 1e-64 )));

  while (err3 > tol3 && iterisohard < maxiterisohard) // Hardness update iteration
  {
    iterisohard++;
    iter = 0;
    delta_dp.zero();

    // Elastic guess
    sig_new = sig_old + E_ijkl * delta_d;
    // Compute distance to current yield surface (line), only valid for
    // associative potential
    p = sig_new.trace() / 3.0;
    q = getSigEqv(sig_new);


    get_py_qy_damaged(sig_new, E_ijkl , p_y, q_y, yield_stress);




    // TODO: checking whether in plasticity

    flow_incr = getFlowIncrement(q, p, q_y, p_y, yield_stress);
    getFlowTensor(sig_new, q, p, yield_stress, flow_tensor);
    flow_tensor *= flow_incr;
    resid = flow_tensor - delta_dp;
    err1 = resid.L2norm();
    // TODO: do not compute flow tensor if in elasticity

    while (err1 > tol1 && iter < maxiter) // Stress update iteration (hardness fixed)
    {
      iter++;

      // Jacobian = d(residual)/d(sigma)
      getJac(sig_new, E_ijkl, flow_incr, q, p, p_y, q_y, yield_stress, dr_dsig);
      dr_dsig_inv = dr_dsig.invSymm();
      ddsig = -dr_dsig_inv * resid;         // Newton Raphson
      delta_dp -= E_ijkl.invSymm() * ddsig; // Update increment of plastic rate of deformation tensor
      sig_new += ddsig;                     // Update stress

      // Update residual
      p = sig_new.trace() / 3.0;
      q = getSigEqv(sig_new);
      get_py_qy_damaged(sig_new, E_ijkl, p_y, q_y, yield_stress);

      flow_incr = getFlowIncrement(q, p, q_y, p_y, yield_stress);
      if (flow_incr < 0.0) // negative flow increment not allowed
        mooseError("Constitutive Error-Negative flow increment: Reduce time "
                   "increment.");
      getFlowTensor(sig_new, q, p, yield_stress, flow_tensor);
      flow_tensor *= flow_incr;
      resid = flow_tensor - delta_dp; // Residual
      err1 = resid.L2norm();
    }
    if (iter >= maxiter) // Convergence failure
      mooseError("Constitutive Error-Too many iterations: Reduce time "
                 "increment.\n"); // Convergence failure //TODO: check the
                                  // adaptive time stepping
    _returnmap_iter[ _qp ] = iter;

    dpn = dp + delta_dp;
    eqvpstrain = std::pow(2.0 / 3.0, 0.5) * dpn.L2norm();
    yield_stress_prev = yield_stress;
    yield_stress = getYieldStress(eqvpstrain);
    err3 = std::abs(yield_stress - yield_stress_prev);
  }

  if (iterisohard >= maxiterisohard)
    mooseError("Constitutive Error-Too many iterations in Hardness "
               "Update:Reduce time increment.\n"); // Convergence failure

  dp = dpn; // Plastic rate of deformation tensor in unrotated configuration
  sig = sig_new;
}

void
RedbackMechMaterial_UO_DC_YSUO::get_py_qy_damaged(const RankTwoTensor & trial_stress,
                                                  const RankFourTensor & E_ijkl,
										          Real & p_y, Real & q_y,
												  Real yield_stress)
{
  get_py_qy(trial_stress, E_ijkl, p_y, q_y, yield_stress);
  p_y *= (1 - _damage[ _qp ]);
  q_y *= (1 - _damage[ _qp ]);
}

/*void
RedbackMechMaterial_UO_DC_YSUO::form_damage_kernels(Real cohesion)
{
  mooseError("form_damage_kernels must be overwritten in children class");
}*/

void
RedbackMechMaterial_UO_DC_YSUO::formDamageDissipation(RankTwoTensor & sig)
{
  /* The damage potential is being formed in this function. We start by
   * postulating a helmholtz free energy of the form:
   *  Psi = Psi_damage * Psi0
   *  where Psi_damage = 1/2 *(1-D)^2
   *  and Psi0 is the purely mechanical expression of the Helmholtz free energy,
   * which in turn is split into a volumetric and a deviatoric part:
   *  Psi0 = Psi0_vol + Psi0_dev
   *  The volumetric part is: Psi0_vol = (2/3)*K*(epsilon^e_v)^2
   *  The deviatoric part is: Psi0_dev = (3/2)*G*(epsilon^e_d)^2
   *  Then, the damage potential is defined as damage_potential = - d Psi / d D
   * =  (1-D) * Psi0
   */

  Real bulk_modulus, shear_modulus, vol_elastic_strain, dev_elastic_strain;
  Real Psi0, Psi0_vol, Psi0_dev;
  Real damage_potential, damage_rate;

  /*
  bulk_modulus =
    _youngs_modulus * _poisson_ratio / (1 + _poisson_ratio) / (1 - 2 * _poisson_ratio); // First Lame modulus
  shear_modulus = 0.5 * _youngs_modulus / (1 + _poisson_ratio);   // Second Lame modulus (shear)

  */

  // fixme - not clear if we should be using the original _Cijkl here - do we need the moduli before damage is applied?
  // also this assumes linear isotropic (& 2D) material
  shear_modulus = _elasticity_tensor[ _qp ](0,1,0,1);  // 1d?? / anisotropic??
  bulk_modulus = _elasticity_tensor[ _qp ](0,0,0,0) - (4.0/3.0)*shear_modulus;

  //std::cout  << "shear_modulus " << shear_modulus << std::endl;
  //std::cout  << "bulk_modulus " << bulk_modulus << std::endl;


  vol_elastic_strain = _elastic_strain[ _qp ].trace();
  dev_elastic_strain = std::pow(2.0 / 3.0, 0.5) * _elastic_strain[ _qp ].L2norm();

  Psi0_vol = (2 / 3) * bulk_modulus * std::pow(vol_elastic_strain, 2);
  Psi0_dev = (3 / 2) * shear_modulus * std::pow(dev_elastic_strain, 2);
  Psi0 = Psi0_vol + Psi0_dev;

  damage_potential = (1 - _damage[ _qp ]) * Psi0;
  damage_rate = (_damage[ _qp ] - _damage_old[ _qp ]) / _dt;

  // _damage_dissipation is equal to (- d Psi / d D * D_dot) which in this code
  // is (damage_potential * damage_rate)
  _damage_dissipation = damage_potential * damage_rate;
}

void
RedbackMechMaterial_UO_DC_YSUO::form_damage_kernels(Real cohesion)
{
  // update damage evolution law from selected method
  switch (_damage_method)
  {
    case BrittleDamage:
      formBrittleDamage();
      break;
    case CreepDamage:
      formCreepDamage(cohesion);
      break;
    case BreakageMechanics:
      mooseError("damage method not implemented yet, use other options");
      break;
    case DamageHealing:
      mooseError("damage method not implemented yet, use other options");
      break;
    default:
      mooseError("damage method not implemented yet, use other options");
  }
}

void
RedbackMechMaterial_UO_DC_YSUO::formBrittleDamage()
{
  Real plastic_damage, healing_damage;
  Real kachanov, exponent_kachanov;

  // Kachanov's original law of Brittle Damage
  exponent_kachanov = 1;
  kachanov = _mises_stress[ _qp ] / (1 - _damage[ _qp ]);

  plastic_damage = _damage_coeff * std::pow(kachanov, exponent_kachanov);
  healing_damage = 0;

  _damage_kernel[ _qp ] = plastic_damage + healing_damage;
  _damage_kernel_jac[ _qp ] = 0;
}

void
RedbackMechMaterial_UO_DC_YSUO::formCreepDamage(Real cohesion)
{
  Real plastic_damage, healing_damage;
  Real lambda_dot;
  Real d_yield_dq; // The derivative of the yield surface with respect to the
                   // deviatoric stress q

  // Damage evolution law for creep damage
  // J2 plastic potential with evolving cohesion for the damage evolution law
  // (remember that cohesion is q_y which is updated as q_y * (1-D) in the
  // get_py_qy_damaged function)
  d_yield_dq = 1 / std::pow(cohesion, 2);

  if (d_yield_dq > 0) // ensuring positiveness of the plastic multiplier
  {
    /* the plastic multiplier could be having this form:
     * lambda_dot = _mises_stress[_qp] * _mises_strain_rate[_qp] / d_yield_dq;
     * but cohesion in J2 plasticity is the mises stress at yield, so we are
     * going with a much simpler form: */
    lambda_dot = _mises_strain_rate[ _qp ] / d_yield_dq;
  }
  else
    lambda_dot = 0;

  plastic_damage = _damage_coeff * lambda_dot;
  healing_damage = 0;
  _damage_kernel[ _qp ] = plastic_damage + healing_damage;
  _damage_kernel_jac[ _qp ] = 0;
}




//////////////////




/**
 * Get unitary flow tensor in deviatoric direction, J2 plasticity. It only has a
 * deviatoric part
 */
void
RedbackMechMaterial_UO_DC_YSUO::getFlowTensor(
  const RankTwoTensor & sig, Real q, Real p, Real yield_stress, RankTwoTensor & flow_tensor)
{


	/*
  RankTwoTensor sig_dev;
  Real val;

  sig_dev = sig.deviatoric();
  val = 0.0;
  if (q > 1e-8)
    val = 3.0 / (2.0 * q);
  flow_tensor_dev = sig_dev * val;
  // flow_tensor_dev /= flow_tensor_dev.L2norm();
  // TODO: norm is actually sqrt(3/2)

  */

  std::vector<RankTwoTensor> df_dstress;
  _plastic_model->dyieldFunction_dstressV(sig, yield_stress, df_dstress);

  flow_tensor = df_dstress[0]; // Only dealing with one yield surface
  flow_tensor /= std::pow(2.0 / 3.0, 0.5) * flow_tensor.L2norm();
  // returning sqrt(3/2)*norm as was done before...
}

Real
RedbackMechMaterial_UO_DC_YSUO::getFlowIncrement(Real sig_eqv, Real p, Real q_y, Real p_y, Real yield_stress)
{
  return _ref_pe_rate * _dt * std::pow(macaulayBracket(sig_eqv / yield_stress - 1.0), _exponent) * _exponential;
}

/**
 * Derivative of getFlowIncrement with respect to equivalent stress, only has
 * deviatoric component in J2 plasticity
 */
Real
RedbackMechMaterial_UO_DC_YSUO::getDerivativeFlowIncrement(const RankTwoTensor & sig, Real yield_stress)
{
  // Derivative of getFlowIncrement with respect to equivalent stress
  return _ref_pe_rate * _dt * _exponent *
         std::pow(macaulayBracket(getSigEqv(sig) / yield_stress - 1.0), _exponent - 1.0) * _exponential / yield_stress;
}

// Jacobian for stress update algorithm
void
RedbackMechMaterial_UO_DC_YSUO::getJac(const RankTwoTensor & sig,
                              const RankFourTensor & E_ijkl,
                              Real flow_incr_dev,
                              Real q,
                              Real p,
                              Real p_y,
                              Real q_y,
                              Real yield_stress,
                              RankFourTensor & dresid_dsig)
{
  unsigned i, j, k, l;
  RankTwoTensor sig_dev, flow_dirn_dev, fij;
  RankTwoTensor dfi_dft;
  RankFourTensor dft_dsig, dfd_dft, dfd_dsig, dfi_dsig;
  Real sig_eqv;
  Real f1, f2, f3;
  Real dfi_dseqv_dev;

  sig_dev = sig.deviatoric();
  sig_eqv = getSigEqv(sig);

  getFlowTensor(sig, q, p, yield_stress, flow_dirn_dev);
  dfi_dseqv_dev = getDerivativeFlowIncrement(sig, yield_stress);

  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfi_dsig(i, j, k, l) = flow_dirn_dev(i, j) * flow_dirn_dev(k, l) * dfi_dseqv_dev; // d_flow_increment/d_sig

  f1 = 0.0;
  f2 = 0.0;
  f3 = 0.0;

  if (sig_eqv > 1e-8)
  {
    f1 = 3.0 / (2.0 * sig_eqv);
    f2 = f1 / 3.0;
    f3 = 9.0 / (4.0 * std::pow(sig_eqv, 3.0));
  }

  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dft_dsig(i, j, k, l) = f1 * deltaFunc(i, k) * deltaFunc(j, l) - f2 * deltaFunc(i, j) * deltaFunc(k, l) -
                                 f3 * sig_dev(i, j) * sig_dev(k, l); // d_flow_dirn/d_sig - 2nd part

  dfd_dsig = dft_dsig;                                                  // d_flow_dirn/d_sig
  dresid_dsig = E_ijkl.invSymm() + dfd_dsig * flow_incr_dev + dfi_dsig; // Jacobian
}

void
RedbackMechMaterial_UO_DC_YSUO::get_py_qy(const RankTwoTensor & trial_stress,
		                                  const RankFourTensor & E_ijkl,
										  Real & p_y, Real & q_y,
										  Real yield_stress)
{

	RankTwoTensor returned_stress;
	Real intnl_old = yield_stress; // Fixme need to make state constant but with the ability to update based on yield stress from plastic law
	Real ep_plastic_tolerance = 1e-9;  // fixme set as a material parameter
	Real returned_intnl; // should be ignored.
	RankTwoTensor delta_dp; // change in plastic strain
	std::vector<Real> dpm(1); // the plastic multipliers needed to bring about the return. fixme - check if we need more than one dpm?
	std::vector<Real> yf(1); // In case (C): the yield function at (returned_stress, returned_intnl).  Otherwise: the yield function at (trial_stress, intnl_old)
	bool trial_stress_inadmissible; // Should be set to false if the trial_stress is admissible, and true if the trial_stress is inadmissible.  This can be used by the calling prorgram

	bool sucess = _plastic_model->returnMap(trial_stress, intnl_old, E_ijkl,
                                            ep_plastic_tolerance, returned_stress, returned_intnl,
                                            dpm, delta_dp, yf,
                                            trial_stress_inadmissible);

	//Real returned_yield = returned_intnl;

	p_y = returned_stress.trace() / 3.0;
    q_y = getSigEqv(returned_stress);

    // orig j2
	//p_y = p;
    //q_y = yield_stress;
}



