/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef REDBACKPLASTICITYUOJ2_H
#define REDBACKPLASTICITYUOJ2_H

#include "RedbackPlasticityUOBase.h"

class RedbackPlasticityUOJ2;

template <>
InputParameters validParams<RedbackPlasticityUOJ2>();

/**
 * derived UO contains four functions used in RedbackMechMaterial
 */

class RedbackPlasticityUOJ2 : public RedbackPlasticityUOBase
{
public:
  RedbackPlasticityUOJ2(const InputParameters & parameters);
  virtual ~RedbackPlasticityUOJ2()
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
  virtual Real getDerivativeFlowIncrement(const RankTwoTensor &, Real, Real, Real, Real, Real) const;
};

#endif // REDBACKPLASTICITYUOJ2_H
