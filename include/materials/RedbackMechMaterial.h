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

#ifndef REDBACKMECHMATERIAL_H
#define REDBACKMECHMATERIAL_H

#include "Material.h"
#include "RankTwoTensor.h"
#include "ElasticityTensorR4.h"
#include "RotationTensor.h"


#include "RedbackMaterial.h"

//#include "FiniteStrainPlasticMaterial.h"

//Forward Declarations
class RedbackMechMaterial;

template<>
InputParameters validParams<RedbackMechMaterial>();

/**
 * This class copy-pastes the stack from tensorMechanics module since we don't
 * know yet how to derive our class from 2 base clases... (multiple inheritance)
 * TODO: do that properly!
 */
class RedbackMechMaterial : public RedbackMaterial
{
public:
  RedbackMechMaterial(const std::string & name, InputParameters parameters);
  // Redback
  static MooseEnum yieldCriterionEnum();
  enum YieldCriterion
  {
    J2_plasticity, // Von Mises
    Drucker_Prager,
    modified_Cam_Clay
  };

protected:
  // Copy-paste from TensorMechanicsMaterial.h
  virtual void computeProperties();
  virtual void computeQpElasticityTensor();
  virtual void computeStrain();
  virtual void computeQpStrain();
  virtual void computeQpStrain(const RankTwoTensor & Fhat); // from FiniteStrainMaterial.h
  virtual void computeQpStress();
  virtual void initQpStatefulProperties(); // from FiniteStrainMaterial.h

  VariableGradient & _grad_disp_x;
  VariableGradient & _grad_disp_y;
  VariableGradient & _grad_disp_z;

  VariableGradient & _grad_disp_x_old;
  VariableGradient & _grad_disp_y_old;
  VariableGradient & _grad_disp_z_old;

  MaterialProperty<RankTwoTensor> & _stress;
  MaterialProperty<RankTwoTensor> & _total_strain;
  MaterialProperty<RankTwoTensor> & _elastic_strain;
  MaterialProperty<ElasticityTensorR4> & _elasticity_tensor;
  MaterialProperty<ElasticityTensorR4> & _Jacobian_mult;

  // vectors to get the input values
  std::vector<Real> _Cijkl_vector;

  /// Individual material information
  ElasticityTensorR4 _Cijkl;

  // MaterialProperty<RankTwoTensor> & _d_stress_dT;
  //RankTwoTensor _strain_increment;

  /// Current deformation gradient
  //RankTwoTensor _dfgrd;

  //VariableValue & _T;

  /// determines the translation from C_ijkl to the Rank-4 tensor
  RankFourTensor::FillMethod _fill_method;

  // Copy-paste from FiniteStrainMaterial.h
  MaterialProperty<RankTwoTensor> & _strain_rate;
  MaterialProperty<RankTwoTensor> & _strain_increment;
  MaterialProperty<RankTwoTensor> & _total_strain_old;
  MaterialProperty<RankTwoTensor> & _elastic_strain_old;
  MaterialProperty<RankTwoTensor> & _stress_old;
  MaterialProperty<RankTwoTensor> & _rotation_increment;
  MaterialProperty<RankTwoTensor> & _dfgrd;

  // Copy-paste from FiniteStrainPlasticMaterial.h
  std::vector<Real> _yield_stress_vector;
  MaterialProperty<RankTwoTensor> & _plastic_strain;
  MaterialProperty<RankTwoTensor> & _plastic_strain_old;
  MaterialProperty<Real> & _eqv_plastic_strain;
  MaterialProperty<Real> & _eqv_plastic_strain_old;

  //virtual Real yieldFunction(const RankTwoTensor & stress, const Real yield_stress);
  Real getSigEqv(const RankTwoTensor & stress);
  Real deltaFunc(unsigned int i, unsigned int j);
  Real getYieldStress(const Real equivalent_plastic_strain);

  // Copy-paste from FiniteStrainPlasticRateMaterial.h
  virtual void returnMap(const RankTwoTensor &, const RankTwoTensor &, const RankFourTensor &, RankTwoTensor &, RankTwoTensor &, Real &, Real &);
  virtual void returnMapJ2(const RankTwoTensor &, const RankTwoTensor &, const RankFourTensor &, RankTwoTensor &, RankTwoTensor &, Real &, Real &);
  Real getPressureProjectionDP(Real, Real, Real);
  void getStressProjectionsCC(Real, Real, Real, Real, Real &, Real &);
  virtual void returnMapDP(const RankTwoTensor &, const RankTwoTensor &, const RankFourTensor &, RankTwoTensor &, RankTwoTensor &, Real &, Real &);
  virtual void returnMapCC(const RankTwoTensor &, const RankTwoTensor &, const RankFourTensor &, RankTwoTensor &, RankTwoTensor &, Real &, Real &);

  void getJacJ2(const RankTwoTensor &, const RankFourTensor &, Real, Real, RankFourTensor &);
  void getJacDP(const RankTwoTensor &, const RankFourTensor &, Real, Real, Real, Real, RankFourTensor &);
  void getJacCC(const RankTwoTensor &, const RankFourTensor &, Real, Real, Real, Real, Real, RankFourTensor &);

  void getFlowTensorCC(const RankTwoTensor &, Real, Real, RankTwoTensor &);
  void getFlowTensorJ2(const RankTwoTensor &, Real, RankTwoTensor &);
  void getFlowTensorDP(const RankTwoTensor &, Real, RankTwoTensor &);

  Real getFlowIncrementCC(Real, Real, Real, Real, Real);
  Real getFlowIncrementDP(Real, Real, Real, Real);
  Real getFlowIncrementJ2(const RankTwoTensor &, Real);

  Real getDerivativeFlowIncrementDP(const RankTwoTensor &, Real, Real, Real, Real);
  Real getDerivativeFlowIncrementCC(const RankTwoTensor &, Real, Real, Real, Real, Real);
  Real getDerivativeFlowIncrementJ2(const RankTwoTensor &, Real);

  Real _ref_pe_rate;
  Real _exponent;

  Real macaulayBracket(Real);

  // Redback specific
  MaterialProperty<Real> & _mises_stress;
  MaterialProperty<Real> & _mean_stress;
  MaterialProperty<Real> & _mises_strain_rate;
  MaterialProperty<Real> & _volumetric_strain;
  MaterialProperty<Real> & _volumetric_strain_rate;
  Real _mixture_compressibility_param;
  MaterialProperty<Real> & _mixture_compressibility;
  Real _exponential;
  YieldCriterion _yield_criterion;
  Real _slope_yield_surface;  // coefficient for yield surface
  virtual void computeRedbackTerms(RankTwoTensor &, Real, Real);
};

#endif //REDBACKMECHMATERIAL_H
