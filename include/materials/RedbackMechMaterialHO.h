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

#ifndef RedbackMechMaterialHO_H
#define RedbackMechMaterialHO_H

#include "RedbackMechMaterial.h"

// Forward Declarations
class RedbackMechMaterialHO;

template <>
InputParameters validParams<RedbackMechMaterialHO>();

class RedbackMechMaterialHO : public RedbackMechMaterial
{
public:
  RedbackMechMaterialHO(const InputParameters & parameters);

protected:
  virtual void initQpStatefulProperties();
  virtual void computeQpStrain(const RankTwoTensor & Fhat);
  virtual void computeQpStress();
  int corsigma(int , int );
  int cormoment(int , int );
  void remplSigmaOld(RankTwoTensor & , Real* vect, int );
  void remplMomentOld(RankTwoTensor &, Real* vect, int );
  void recupSigmaNew(RankTwoTensor &, Real* vect, int );
  void recupMomentNew(RankTwoTensor &, Real* vect, int );


  virtual void computeQpElasticityTensor();

  void returnMap(const RankTwoTensor &,
                 const RankTwoTensor &,
                 const RankFourTensor &,
                 RankTwoTensor &,
                 RankTwoTensor &,
                 Real &,
                 Real &);
  void getJac(const RankTwoTensor &, const RankFourTensor &, Real, Real, Real, Real, Real, Real, RankFourTensor &);
  void getFlowTensor(const RankTwoTensor &, Real, Real, Real, RankTwoTensor &);
  Real getFlowIncrement(Real, Real, Real, Real, Real);
  void get_py_qy(Real, Real, Real &, Real &, Real);
  Real getDerivativeFlowIncrement(const RankTwoTensor &, Real, Real, Real, Real, Real);
  virtual void computeRedbackTerms(RankTwoTensor &, Real, Real);


  MaterialProperty<RankTwoTensor> & _symmetric_strain;
  MaterialProperty<RankTwoTensor> & _antisymmetric_strain;
  MaterialProperty<RankTwoTensor> & _symmetric_plastic_strain;
  MaterialProperty<RankTwoTensor> & _antisymmetric_plastic_strain;

  MaterialProperty<RankTwoTensor> & _curvature;
  MaterialProperty<RankTwoTensor> & _elastic_curvature;
  MaterialProperty<RankTwoTensor> & _elastic_curvature_old;
  MaterialProperty<RankTwoTensor> & _total_curvature;
  MaterialProperty<RankTwoTensor> & _total_curvature_old;

  MaterialProperty<RankTwoTensor> & _symmetric_stress;
  MaterialProperty<RankTwoTensor> & _symmetric_stress_old;
  MaterialProperty<RankTwoTensor> & _antisymmetric_stress;
  MaterialProperty<RankTwoTensor> & _antisymmetric_stress_old;
  MaterialProperty<RankTwoTensor> & _stress_couple;
  MaterialProperty<RankTwoTensor> & _stress_couple_old;


  MaterialProperty<Real> & _stress_trace;

  MaterialProperty<RankTwoTensor> & _macro_rotation;

  MaterialProperty<ElasticityTensorR4> & _elastic_flexural_rigidity_tensor;
  MaterialProperty<ElasticityTensorR4> & _Jacobian_mult_couple;
  MaterialProperty<ElasticityTensorR4> & _Jacobian_offdiag_bc;
  MaterialProperty<ElasticityTensorR4> & _Jacobian_offdiag_cb;


  const std::vector<Real> _Bijkl_vector, _Cijkl_vector;
  ElasticityTensorR4 _Bijkl;

  MaterialProperty<RankTwoTensor> & _curvature_increment;
  MaterialProperty<RankTwoTensor> & _plastic_curvature;
  MaterialProperty<RankTwoTensor> & _plastic_curvature_old;
  MaterialProperty<RankTwoTensor> & _deviatoric_plastic_strain;

  MaterialProperty<RankTwoTensor> & _deviatoric_stress;
  MaterialProperty<Real> & _volumetric_stress;
  MaterialProperty<Real> & _stress_invariant;
  MaterialProperty<Real> & _hardening_variable;
  MaterialProperty<Real> & _lagrange_multiplier;
  MaterialProperty<Real> & _failure_surface;

private:
  const VariableValue & _wc_x;
  const VariableValue & _wc_y;
  const VariableValue & _wc_z;

  const VariableGradient & _grad_wc_x;
  const VariableGradient & _grad_wc_y;
  const VariableGradient & _grad_wc_z;

  const VariableGradient & _grad_wc_x_old;
  const VariableGradient & _grad_wc_y_old;
  const VariableGradient & _grad_wc_z_old;


  /// determines the translation from B_ijkl to the Rank-4 tensor
  MooseEnum _fill_method_bending;
  Real _cohesion, _friction_coefficient, _hardening_mech_modulus;
  Real _shear_modulus, _bulk_modulus, _cosserat_shear_modulus, _cosserat_radius;

};
#endif // RedbackMechMaterialHO_H
