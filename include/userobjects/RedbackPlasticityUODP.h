/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef REDBACKPLASTICITYUODP_H
#define REDBACKPLASTICITYUODP_H

#include "RedbackPlasticityUOBase.h"

class RedbackPlasticityUODP;

template<>
InputParameters validParams<RedbackPlasticityUODP>();

/**
 * derived UO contains four functions used in RedbackMechMaterial
 */

class RedbackPlasticityUODP : public RedbackPlasticityUOBase
{
public:
  RedbackPlasticityUODP(const InputParameters & parameters);
  virtual ~RedbackPlasticityUODP() {}

  static MooseEnum damageMethodEnum();
  enum DamageMethod
  {
    BrittleDamage,
    CreepDamage,
    BreakageMechanics,
    DamageHealing,
    FromMultiApp
  };

  virtual Real getFlowIncrement(Real, Real, Real, Real, Real, Real, Real, Real, Real) const;

  virtual void getFlowTensor(const RankTwoTensor &, Real, Real, Real, RankTwoTensor &) const;

  virtual void
  getJac(const RankTwoTensor &, const RankFourTensor &, Real, Real, Real, Real, Real, Real, RankFourTensor &, Real, Real, Real, Real) const;

  virtual void get_py_qy(Real, Real, Real &, Real &, Real) const;

  virtual void form_damage_kernels(DamageMethod, VariableValue &, Real, Real, MaterialProperty<Real> &, MaterialProperty<Real> &, MaterialProperty<Real> &, MaterialProperty<Real> &, unsigned int) const;

protected:
  Real _slope_yield_surface; // coefficient for yield surface

  Real getPressureProjection(Real, Real, Real);
  virtual Real getDerivativeFlowIncrement(const RankTwoTensor &, Real, Real, Real, Real, Real, Real, Real, Real) const;
  virtual Real getPressureProjection(Real, Real, Real) const;

  virtual void formBrittleDamage(VariableValue &, Real, Real, MaterialProperty<Real> &, MaterialProperty<Real> &, MaterialProperty<Real> &, MaterialProperty<Real> &, unsigned int) const;
  virtual void formCreepDamage(VariableValue &, Real, Real, MaterialProperty<Real> &, MaterialProperty<Real> &, MaterialProperty<Real> &, MaterialProperty<Real> &, unsigned int) const;



};

#endif // REDBACKPLASTICITYUODP_H
