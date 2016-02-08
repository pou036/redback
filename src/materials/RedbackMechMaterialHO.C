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
#include "RedbackMechMaterialHO.h"

/**
 * RedbackMechMaterialHO handles a high order material.
 */
template <>
InputParameters
validParams<RedbackMechMaterialHO>()
{
  InputParameters params = validParams<RedbackMechMaterial>();
  params.addCoupledVar("wc_x", 0, "Cosserat rotation around x axis");
  params.addCoupledVar("wc_y", 0, "Cosserat rotation around y axis");
  params.addCoupledVar("wc_z", 0, "Cosserat rotation around z axis");
  params.addRequiredParam<std::vector<Real> >("B_ijkl", "Flexural bending rigidity tensor.  Should have 9 entries.");

  MooseEnum fm = RankFourTensor::fillMethodEnum();
  fm = "antisymmetric_isotropic";
  params.addParam<MooseEnum>("fill_method_bending", fm, "The fill method for the 'bending' tensor.");

  return params;
}

RedbackMechMaterialHO::RedbackMechMaterialHO(const InputParameters & parameters) :
    RedbackMechMaterial(parameters),
    _symmetric_strain(declareProperty<RankTwoTensor>("symmetric_strain")),
    _antisymmetric_strain(declareProperty<RankTwoTensor>("antisymmetric_strain")),
    _curvature(declareProperty<RankTwoTensor>("curvature")),
    _symmetric_stress(declareProperty<RankTwoTensor>("symmetric_stress")),
    _antisymmetric_stress(declareProperty<RankTwoTensor>("antisymmetric_stress")),
    _stress_couple(declareProperty<RankTwoTensor>("coupled_stress")),
    _elastic_flexural_rigidity_tensor(declareProperty<ElasticityTensorR4>("elastic_flexural_rigidity_tensor")),
    _Jacobian_mult_couple(declareProperty<ElasticityTensorR4>("coupled_Jacobian_mult")),
    _Bijkl_vector(getParam<std::vector<Real> >("B_ijkl")),
    _Bijkl(),
    _wc_x(coupledValue("wc_x")),
    _wc_y(coupledValue("wc_y")),
    _wc_z(coupledValue("wc_z")),
    _grad_wc_x(coupledGradient("wc_x")),
    _grad_wc_y(coupledGradient("wc_y")),
    _grad_wc_z(coupledGradient("wc_z")),
    _fill_method_bending(getParam<MooseEnum>("fill_method_bending"))
{
  _Bijkl.fillFromInputVector(_Bijkl_vector, (RankFourTensor::FillMethod)(int)_fill_method_bending);
}

void
RedbackMechMaterialHO::computeQpStrain()
{
  //strain = (grad_disp + grad_disp^T)/2
  RankTwoTensor grad_tensor(_grad_disp_x[_qp], _grad_disp_y[_qp], _grad_disp_z[_qp]);
  RealVectorValue wc_vector(_wc_x[_qp], _wc_y[_qp], _wc_z[_qp]);

  for (unsigned i = 0; i < LIBMESH_DIM; ++i)
    for (unsigned j = 0; j < LIBMESH_DIM; ++j)
      for (unsigned k = 0; k < LIBMESH_DIM; ++k)
        grad_tensor(i, j) += PermutationTensor::eps(i, j, k) * wc_vector(k);

  _symmetric_strain[_qp] = (grad_tensor + grad_tensor.transpose()) / 2.0;
  _antisymmetric_strain[_qp] = (grad_tensor - grad_tensor.transpose()) / 2.0;
  _elastic_strain[_qp] = grad_tensor;

  //_strain_increment[_qp].addIa(-_solid_thermal_expansion[_qp] * (_T[_qp] - _T_old[_qp]));
  _rotation_increment[_qp].zero();
  _rotation_increment[_qp].addIa(1);


  RankTwoTensor wc_grad_tensor(_grad_wc_x[_qp], _grad_wc_y[_qp], _grad_wc_z[_qp]);
  _curvature[_qp] = wc_grad_tensor;
}

void
RedbackMechMaterialHO::computeQpStress()
{
  RedbackMechMaterial::computeQpStress();

  // Additional outputs for post-processing
  _symmetric_stress[_qp] = (_stress[_qp] + _stress[_qp].transpose()) / 2.0;
  _antisymmetric_stress[_qp] = (_stress[_qp] - _stress[_qp].transpose()) / 2.0;
  _stress_couple[_qp] = _elastic_flexural_rigidity_tensor[_qp] * _curvature[_qp];
}

void RedbackMechMaterialHO::computeQpElasticityTensor()
{
  RedbackMechMaterial::computeQpElasticityTensor();

  _elastic_flexural_rigidity_tensor[_qp] = _Bijkl;
  _Jacobian_mult_couple[_qp] = _Bijkl;
}

/*
 * STARTING PSEUDO-LOOP IN PLASTICITY FUNCTIONS. NEED TO BE OVERWRITTEN WHEN IN PLASTICITY
 */

void
RedbackMechMaterialHO::returnMap(const RankTwoTensor & sig_old,
                                      const RankTwoTensor & delta_d,
                                      const RankFourTensor & E_ijkl,
                                      RankTwoTensor & dp,
                                      RankTwoTensor & sig,
                                      Real & p_y,
                                      Real & q_y)
{
  sig = sig_old + E_ijkl * delta_d;
  dp = RankTwoTensor(); // Plastic rate of deformation tensor in unrotated configuration
}

/**
 * Get unitary flow tensor in deviatoric direction
 */
void
RedbackMechMaterialHO::getFlowTensor(const RankTwoTensor & sig, Real q, Real p, Real pc, RankTwoTensor & flow_tensor)
{
  flow_tensor.zero(); // TODO: not implemented yet
}

/**
 * Compute the flow incrmement for modified Cam-clay
 * pc ... pre-consolidation pressure (pc = -getYieldStress(eqvpstrain))
 */
Real
RedbackMechMaterialHO::getFlowIncrement(Real sig_eqv, Real pressure, Real q_yield_stress, Real p_yield_stress, Real pc)
{
  return 0; // TODO: not implemented yet
}

Real
RedbackMechMaterialHO::getDerivativeFlowIncrement(
  const RankTwoTensor & sig, Real pressure, Real sig_eqv, Real pc, Real q_yield_stress, Real p_yield_stress)
{
  return 0; // TODO: not implemented yet
}

void
RedbackMechMaterialHO::getJac(const RankTwoTensor & sig,
                              const RankFourTensor & E_ijkl,
                              Real flow_incr,
                              Real sig_eqv,
                              Real pressure,
                              Real p_yield_stress,
                              Real q_yield_stress,
                              Real pc,
                              RankFourTensor & dresid_dsig)
{
  dresid_dsig.zero();
}

void
RedbackMechMaterialHO::get_py_qy(Real p, Real q, Real & p_y, Real & q_y, Real yield_stress)
{
  // TODO: not implemented yet
  p_y = 0;
  q_y = 0;
}
