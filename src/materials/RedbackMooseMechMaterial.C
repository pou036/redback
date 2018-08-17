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
#include "MooseException.h"
#include "MooseMesh.h"
#include "RedbackMooseMechMaterial.h"
#include "libmesh/quadrature.h"

template <>
InputParameters
validParams<RedbackMooseMechMaterial>()
{
  InputParameters params = validParams<Material>();

  // Copy-paste from TensorMechanicsMaterial.C
  params.addRequiredCoupledVar("disp_x", "The x displacement");
  params.addRequiredCoupledVar("disp_y", "The y displacement");
  params.addCoupledVar("disp_z", 0.0, "The z displacement");
  params.addCoupledVar("temperature", 0.0, "temperature variable");

  //  Copy-paste from FiniteStrainPlasticRateMaterial.C
  params.addParam<Real>("chemo_mechanical_porosity_coeff",
                        1.0,
                        "The coefficient of volumetric plastic strain in chemical porosity");

  params.addCoupledVar("pore_pres", 0.0, "Dimensionless pore pressure");

  params.addCoupledVar("total_porosity", 0.0, "The total porosity (as AuxKernel)");
  params.addParam<Real>(
      "temperature_reference", 0.0, "Reference temperature used for thermal expansion");
  params.addParam<Real>("pressure_reference", 0.0, "Reference pressure used for compressibility");

  return params;
}

RedbackMooseMechMaterial::RedbackMooseMechMaterial(const InputParameters & parameters)
  : Material(parameters),
    // Copy-paste from TensorMechanicsMaterial.C
    _grad_disp_x(coupledGradient("disp_x")),
    _grad_disp_y(coupledGradient("disp_y")),
    _grad_disp_z(_mesh.dimension() == 3 ? coupledGradient("disp_z") : _grad_zero),
    _grad_disp_x_old(_fe_problem.isTransient() ? coupledGradientOld("disp_x") : _grad_zero),
    _grad_disp_y_old(_fe_problem.isTransient() ? coupledGradientOld("disp_y") : _grad_zero),
    _grad_disp_z_old(_fe_problem.isTransient() && _mesh.dimension() == 3
                         ? coupledGradientOld("disp_z")
                         : _grad_zero),
    _stress(getMaterialProperty<RankTwoTensor>("stress")),
    _total_strain(getMaterialProperty<RankTwoTensor>("total_strain")),
    _total_strain_old(getMaterialPropertyOld<RankTwoTensor>("total_strain")),
    _elastic_strain(getMaterialProperty<RankTwoTensor>("elastic_strain")),
    _elastic_strain_old(getMaterialPropertyOld<RankTwoTensor>("elastic_strain")),
    // _d_stress_dT(declareProperty<RankTwoTensor>("d_stress_dT")),

    // Copy-paste from FiniteStrainMaterial.C
    _strain_rate(getMaterialProperty<RankTwoTensor>("strain_rate")),

    // Copy-paste from FiniteStrainPlasticMaterial.C
    _plastic_strain(getMaterialProperty<RankTwoTensor>("plastic_strain")),
    _plastic_strain_old(getMaterialPropertyOld<RankTwoTensor>("plastic_strain")),

    // Copy-paste from FiniteStrainPlasticRateMaterial.C
    _chemo_mechanical_porosity_coeff(getParam<Real>("chemo_mechanical_porosity_coeff")),

    // Redback
    _mises_stress(declareProperty<Real>("mises_stress")),
    _mean_stress(declareProperty<Real>("mean_stress")),
    _mises_strain_rate(declareProperty<Real>("mises_strain_rate")),
    _volumetric_strain(declareProperty<Real>("volumetric_strain")),
    _volumetric_strain_rate(declareProperty<Real>("volumetric_strain_rate")),
    _mechanical_porosity(declareProperty<Real>("mechanical_porosity")),
    _mass_removal_rate(declareProperty<Real>("mass_removal_rate")),

    _poromech_kernel(declareProperty<Real>("poromechanics_kernel")),
    _poromech_jac(declareProperty<Real>("poromechanics_jacobian")),
    _mechanical_dissipation_mech(declareProperty<Real>("mechanical_dissipation_mech")),
    _mechanical_dissipation_jac_mech(declareProperty<Real>("mechanical_dissipation_jacobian_mech")),

    // Get coupled variables (T & P & porosity)
    _has_T(isCoupled("temperature")),
    _T(_has_T ? coupledValue("temperature") : _zero),
    _T_old(_has_T ? coupledValueOld("temperature") : _zero),
    _has_pore_pres(isCoupled("pore_pres")),
    _pore_pres(_has_pore_pres ? coupledValue("pore_pres") : _zero),
    _total_porosity(coupledValue("total_porosity")), // total_porosity MUST be
                                                     // coupled! Check that
                                                     // (TODO)

    // Get some material properties from RedbackMaterial
    _gr(getMaterialProperty<Real>("gr")),
    _lewis_number(getMaterialProperty<Real>("lewis_number")),
    _ar(getMaterialProperty<Real>("ar")),
    _confining_pressure(getMaterialProperty<Real>("confining_pressure")),
    _alpha_1(getMaterialProperty<Real>("alpha_1")),
    _alpha_2(getMaterialProperty<Real>("alpha_2")),
    _alpha_3(getMaterialProperty<Real>("alpha_3")),
    _delta(getMaterialProperty<Real>("delta")),
    _solid_thermal_expansion(getMaterialProperty<Real>("solid_thermal_expansion")),
    _solid_compressibility(getMaterialProperty<Real>("solid_compressibility")),
    _mixture_compressibility(getMaterialProperty<Real>("mixture_compressibility")),
    _peclet_number(getMaterialProperty<Real>("Peclet_number")),
    _T0_param(getParam<Real>("temperature_reference")),
    _P0_param(getParam<Real>("pressure_reference"))
{
}

void
RedbackMooseMechMaterial::initQpStatefulProperties()
{
  // Redback properties
  _mises_stress[_qp] = getSigEqv(_stress[_qp]);
  _mean_stress[_qp] = _stress[_qp].trace() / 3.0;
  _mises_strain_rate[_qp] = 0;
  _volumetric_strain[_qp] = 0;
  _volumetric_strain_rate[_qp] = 0;
  _mechanical_porosity[_qp] = 0;
  _poromech_kernel[_qp] = 0;
  _poromech_jac[_qp] = 0;
  _mechanical_dissipation_mech[_qp] = 0;
  _mechanical_dissipation_jac_mech[_qp] = 0;
  _mass_removal_rate[_qp] = 0;
}

void
RedbackMooseMechMaterial::computeQpProperties()
{
  // Default Material method
  Material::computeQpProperties();

  // Compute the terms used in Redback Kernels
  computeRedbackTerms();
}

void
RedbackMooseMechMaterial::computeRedbackTerms()
{
  // update velocities
  //_solid_velocity[_qp] = RealVectorValue(_dispx_dot[_qp], _dispy_dot[_qp],
  //_dispz_dot[_qp]);// TODO

  // Material::computeRedbackTerms();

  // Compute stresses
  _mises_stress[_qp] = getSigEqv(_stress[_qp]);
  _mean_stress[_qp] = _stress[_qp].trace() / 3.0;

  // Compute plastic strains
  RankTwoTensor instantaneous_strain_rate, total_volumetric_strain_rate;

  if (_dt == 0)
  {
    instantaneous_strain_rate.zero();
    total_volumetric_strain_rate.zero();
  }
  else
  {
    instantaneous_strain_rate = (_plastic_strain[_qp] - _plastic_strain_old[_qp]) / _dt;
    total_volumetric_strain_rate = (_total_strain[_qp] - _total_strain_old[_qp]) / _dt;
  }
  _mises_strain_rate[_qp] = std::pow(2.0 / 3.0, 0.5) * instantaneous_strain_rate.L2norm();
  _volumetric_strain_rate[_qp] = total_volumetric_strain_rate.trace();
  Real def_grad = _grad_disp_x[_qp](0) + _grad_disp_y[_qp](1) + _grad_disp_z[_qp](2);
  Real def_grad_old =
      _grad_disp_x_old[_qp](0) + _grad_disp_y_old[_qp](1) + _grad_disp_z_old[_qp](2);
  Real def_grad_rate = 0.;
  if (_dt > 0)
    def_grad_rate = (def_grad - def_grad_old) / _dt;

  // Update mechanical porosity (elastic and plastic components)
  // TODO: set T0 properly (once only, at the very beginning). Until then, T = T
  // - T0, P = P - P0
  Real delta_phi_mech_el =
      (1.0 - _total_porosity[_qp]) * (_solid_compressibility[_qp] * (_pore_pres[_qp] - _P0_param) -
                                      _solid_thermal_expansion[_qp] * (_T[_qp] - _T0_param) +
                                      (_elastic_strain[_qp] - _elastic_strain_old[_qp]).trace());
  Real delta_phi_mech_pl =
      (1.0 - _total_porosity[_qp]) * (_plastic_strain[_qp] - _plastic_strain_old[_qp]).trace();

  _mechanical_porosity[_qp] = delta_phi_mech_el + delta_phi_mech_pl;

  Real gruntfest_number = _gr[_qp] * std::exp(_ar[_qp]);

  // Compute Mechanical Dissipation.
  _mechanical_dissipation_mech[_qp] =
      gruntfest_number * _stress[_qp].doubleContraction(instantaneous_strain_rate);
  /* The following loop can ensure positive mechanical dissipation.
   * if (_mechanical_dissipation_mech[_qp] < 0)
  {
          mooseWarning("Dissipation is negative. Check the reason!");
  }*/

  // Compute Mechanical Dissipation Jacobian
  _mechanical_dissipation_jac_mech[_qp] =
      _mechanical_dissipation_mech[_qp] / (1 + _delta[_qp] * _T[_qp]) / (1 + _delta[_qp] * _T[_qp]);

  _poromech_kernel[_qp] = def_grad_rate * _peclet_number[_qp] / _mixture_compressibility[_qp];
  if (_has_T)
  {
    _poromech_jac[_qp] = (1 / (1 + _delta[_qp] * _T[_qp]) / (1 + _delta[_qp] * _T[_qp]));
  }
  else
  {
    _poromech_jac[_qp] = 0;
  }

  // Begin of the chemical degradation method of Hu and Hueckel 2013 (doi:10.1680/geot.SIP13.P.020)
  // _mass_removal_rate[_qp] = 0;
  Real total_energy_input = _stress[_qp].doubleContraction(instantaneous_strain_rate);

  _mass_removal_rate[_qp] = _chemo_mechanical_porosity_coeff * (1 + total_energy_input);
  if (_volumetric_strain[_qp] > 0)
  {
    _mass_removal_rate[_qp] = _chemo_mechanical_porosity_coeff * _volumetric_strain[_qp];
  }
  // End of the chemical degradation method of Hu and Hueckel 2013
  return;
}

Real
RedbackMooseMechMaterial::getSigEqv(const RankTwoTensor & stress)
{
  return std::pow(3 * stress.secondInvariant(), 0.5);
}
