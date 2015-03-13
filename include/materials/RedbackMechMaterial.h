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
#include "RankFourTensor.h"
#include "ElasticityTensorR4.h"
#include "RotationTensor.h"
//#include "FiniteStrainPlasticMaterial.h"

//Forward Declarations
class RedbackMechMaterial;

template<>
InputParameters validParams<RedbackMechMaterial>();

/**
 * This class copy-pastes the stack from tensorMechanics module
 * TODO: add required features to moose and use proper tensorMechanics module
 */
class RedbackMechMaterial : public Material
{
public:
  RedbackMechMaterial(const std::string & name, InputParameters parameters);

protected:
  // Copy-paste from TensorMechanicsMaterial.h
  virtual void computeProperties();
  virtual void stepInitQpProperties();
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

  /// Individual material information
  ElasticityTensorR4 _Cijkl;

  // MaterialProperty<RankTwoTensor> & _d_stress_dT;
  //RankTwoTensor _strain_increment;

  /// Current deformation gradient
  //RankTwoTensor _dfgrd;

  //VariableValue & _T;

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
  // The following functions are needed in the return map, but the definition
  // is dependant on the yield criterion. Therefore we define them as abstract
  // virtual functions here such that no implementation is needed in
  // RedbackMechMaterial.C
  virtual void getJac(const RankTwoTensor &, const RankFourTensor &, Real, Real, Real, Real, Real, Real, RankFourTensor &) = 0;
  virtual void getFlowTensor(const RankTwoTensor &, Real, Real, Real, RankTwoTensor &) = 0;
  virtual Real getFlowIncrement(Real, Real, Real, Real, Real) = 0;
  virtual void get_py_qy(Real, Real, Real &, Real &, Real) = 0;

  Real _ref_pe_rate;
  Real _exponent;
  Real _mhc;

  Real macaulayBracket(Real);

  // Redback specific
  Real _youngs_modulus;
  Real _poisson_ratio;
  MaterialProperty<Real> & _mises_stress;
  MaterialProperty<Real> & _mean_stress;
  MaterialProperty<Real> & _mises_strain_rate;
  MaterialProperty<Real> & _volumetric_strain;
  MaterialProperty<Real> & _volumetric_strain_rate;
  MaterialProperty<Real> & _total_volumetric_strain;
  Real _mixture_compressibility_param;
  MaterialProperty<Real> & _mixture_compressibility;
  Real _exponential;
  //VariableValue & _dispx_dot;
  //VariableValue & _dispy_dot;
  //VariableValue & _dispz_dot;

  //MaterialProperty<RealVectorValue> & _solid_velocity;

  // Using variables
  bool _has_T;
  VariableValue & _T, & _T_old;
  bool _has_pore_pres;
  VariableValue & _pore_pres;
  // Reading material properties from RedbackMaterial
  MaterialProperty<Real> & _mechanical_dissipation;
  MaterialProperty<Real> & _gr;
  MaterialProperty<Real> & _ar;
  MaterialProperty<Real> & _mechanical_dissipation_jac;
  MaterialProperty<Real> & _delta;
  MaterialProperty<Real> & _mod_gruntfest_number;
  MaterialProperty<Real> & _solid_thermal_expansion;
  MaterialProperty<Real> & _returnmap_iter;

  virtual void computeRedbackTerms(RankTwoTensor &, Real, Real);
};

#endif //REDBACKMECHMATERIAL_H
