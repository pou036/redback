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

#ifndef REDBACKMECHMATERIALDPRATEANDSTATE_H
#define REDBACKMECHMATERIALDPRATEANDSTATE_H

#include "RedbackMechMaterial.h"

class RedbackMechMaterialDPRateAndState : public RedbackMechMaterial
{
public:
  RedbackMechMaterialDPRateAndState(const InputParameters & parameters);
  static InputParameters validParams();

protected:
  Real _slope_yield_surface; // coefficient for yield surface
  Real _a;
  Real _b;

  virtual void getJac(const RankTwoTensor &,
                      const RankFourTensor &,
                      Real,
                      Real,
                      Real,
                      Real,
                      Real,
                      Real,
                      RankFourTensor &) override;
  virtual void
  getFlowTensor(const RankTwoTensor &, Real, Real, Real, Real, Real, RankTwoTensor &) override;
  virtual Real getFlowIncrement(Real, Real, Real, Real, Real) override;
  virtual void get_py_qy(Real, Real, Real &, Real &, Real, bool &) override;
  void
  getDerivativeFlowIncrement(Real &, Real &, const RankTwoTensor &, Real, Real, Real, Real, Real);
  Real getPressureProjection(Real, Real, Real);

  // virtual void form_damage_kernels(Real);
  // virtual void formBrittleDamage();
  // virtual void formCreepDamage(Real);
};

#endif // REDBACKMECHMATERIALDPRATEANDSTATE_H
