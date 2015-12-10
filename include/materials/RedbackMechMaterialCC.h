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

#ifndef REDBACKMECHMATERIALCC_H
#define REDBACKMECHMATERIALCC_H

#include "RedbackMechMaterial.h"

// Forward Declarations
class RedbackMechMaterialCC;

template <>
InputParameters validParams<RedbackMechMaterialCC>();

class RedbackMechMaterialCC : public RedbackMechMaterial
{
public:
  RedbackMechMaterialCC(const InputParameters & parameters);

protected:
  Real _slope_yield_surface; // coefficient for yield surface

  void getJac(const RankTwoTensor &, const RankFourTensor &, Real, Real, Real, Real, Real, Real, RankFourTensor &);
  void getFlowTensor(const RankTwoTensor &, Real, Real, Real, RankTwoTensor &);
  Real getFlowIncrement(Real, Real, Real, Real, Real);
  void get_py_qy(Real, Real, Real &, Real &, Real);
  Real getDerivativeFlowIncrement(const RankTwoTensor &, Real, Real, Real, Real, Real);
};

#endif // REDBACKMECHMATERIALCC_H
