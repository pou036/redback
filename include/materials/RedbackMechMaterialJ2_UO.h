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

#ifndef RedbackMechMaterialJ2_UO_H
#define RedbackMechMaterialJ2_UO_H

#include "RedbackMechMaterial_UO.h"

// Forward Declarations
class RedbackMechMaterialJ2_UO;

template <>
InputParameters validParams<RedbackMechMaterialJ2_UO>();

class RedbackMechMaterialJ2_UO : public RedbackMechMaterial_UO
{
public:
  RedbackMechMaterialJ2_UO(const InputParameters & parameters);

protected:
  void getJac(const RankTwoTensor &, const RankFourTensor &, Real, Real, Real, Real, Real, Real, RankFourTensor &);
  void getFlowTensor(const RankTwoTensor &, Real, Real, Real, RankTwoTensor &);
  Real getFlowIncrement(Real, Real, Real, Real, Real);
  void get_py_qy(Real, Real, Real &, Real &, Real);
  Real getDerivativeFlowIncrement(const RankTwoTensor &, Real);
};

#endif // REDBACKMECHMATERIAL_H
