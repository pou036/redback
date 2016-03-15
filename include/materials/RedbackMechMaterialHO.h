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

#ifndef REDBACKMECHMATERIALHO_H
#define REDBACKMECHMATERIALHO_H

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
  virtual void stepInitQpProperties();
  virtual void computeQpStrain(const RankTwoTensor & Fhat);
  virtual void computeQpStress();
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

  MaterialProperty<RankTwoTensor> & _symmetric_strain;
  MaterialProperty<RankTwoTensor> & _antisymmetric_strain;
  MaterialProperty<RankTwoTensor> & _symmetric_plastic_strain;
  MaterialProperty<RankTwoTensor> & _antisymmetric_plastic_strain;

  MaterialProperty<RankTwoTensor> & _curvature;
  MaterialProperty<RankTwoTensor> & _elastic_curvature;
  //MaterialProperty<RankTwoTensor> & _elastic_curvature_old;
  MaterialProperty<RankTwoTensor> & _total_curvature;
  MaterialProperty<RankTwoTensor> & _total_curvature_old;

  MaterialProperty<RankTwoTensor> & _symmetric_stress;
  MaterialProperty<RankTwoTensor> & _antisymmetric_stress;
  MaterialProperty<RankTwoTensor> & _stress_couple;

  MaterialProperty<Real> & _stress_trace;

  MaterialProperty<RankTwoTensor> & _macro_rotation;

  MaterialProperty<ElasticityTensorR4> & _elastic_flexural_rigidity_tensor;
  MaterialProperty<ElasticityTensorR4> & _Jacobian_mult_couple;

  std::vector<Real> _Bijkl_vector;
  ElasticityTensorR4 _Bijkl;

  MaterialProperty<RankTwoTensor> & _curvature_increment;
  MaterialProperty<RankTwoTensor> & _plastic_curvature;
  MaterialProperty<RankTwoTensor> & _plastic_curvature_old;


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
};
#endif // REDBACKMECHMATERIALHO_H
