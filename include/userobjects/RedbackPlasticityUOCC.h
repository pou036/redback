/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef REDBACKPLASTICITYUOCC_H
#define REDBACKPLASTICITYUOCC_H

#include "RedbackPlasticityUOBase.h"

class RedbackPlasticityUOCC;

template <>
InputParameters validParams<RedbackPlasticityUOCC>();

/**
 * derived UO contains four functions used in RedbackMechMaterial
 */

class RedbackPlasticityUOCC : public RedbackPlasticityUOBase
{
public:
  RedbackPlasticityUOCC(const InputParameters & parameters);

  virtual ~RedbackPlasticityUOCC()
  {
  }

  virtual Real getFlowIncrement(Real, Real, Real, Real, Real, Real, Real, Real, Real) const;
  virtual void getFlowTensor(const RankTwoTensor &, Real, Real, Real, RankTwoTensor &) const;
  virtual void getJac(const RankTwoTensor &,
                      const RankFourTensor &,
                      Real,
                      Real,
                      Real,
                      Real,
                      Real,
                      Real,
                      RankFourTensor &,
                      Real,
                      Real,
                      Real,
                      Real) const;
  virtual void get_py_qy(Real, Real, Real &, Real &, Real) const;

protected:
  Real _slope_yield_surface; // coefficient for yield surface
  virtual Real
  getDerivativeFlowIncrement(const RankTwoTensor &, Real, Real, Real, Real, Real, Real, Real, Real, Real) const;
};

#endif // REDBACKPLASTICITYUOCC_H
