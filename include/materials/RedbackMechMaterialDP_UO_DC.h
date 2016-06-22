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

#ifndef RedbackMechMaterialDP_UO_DC_H
#define RedbackMechMaterialDP_UO_DC_H

#include "RedbackMechMaterial_UO_DC.h"

// Forward Declarations
class RedbackMechMaterialDP_UO_DC;

template <>
InputParameters validParams<RedbackMechMaterialDP_UO_DC>();

class RedbackMechMaterialDP_UO_DC : public RedbackMechMaterial_UO_DC
{
public:
  RedbackMechMaterialDP_UO_DC(const InputParameters & parameters);

protected:
  Real _slope_yield_surface; // coefficient for yield surface

  void getJac(const RankTwoTensor &, const RankFourTensor &, Real, Real, Real, Real, Real, Real, RankFourTensor &);
  void getFlowTensor(const RankTwoTensor &, Real, Real, Real, RankTwoTensor &);
  Real getFlowIncrement(Real, Real, Real, Real, Real);
  void get_py_qy(Real, Real, Real &, Real &, Real);
  Real getDerivativeFlowIncrement(const RankTwoTensor &, Real, Real, Real, Real);
  Real getPressureProjection(Real, Real, Real);

  // virtual void form_damage_kernels(Real);
  // virtual void formBrittleDamage();
  // virtual void formCreepDamage(Real);
};

#endif // RedbackMechMaterialDP_UO_DC_H
