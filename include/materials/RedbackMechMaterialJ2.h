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

#ifndef REDBACKMECHMATERIALJ2_H
#define REDBACKMECHMATERIALJ2_H

#include "RedbackMechMaterial.h"

//Forward Declarations
class RedbackMechMaterialJ2;

template<>
InputParameters validParams<RedbackMechMaterialJ2>();

class RedbackMechMaterialJ2 : public RedbackMechMaterial
{
public:
  RedbackMechMaterialJ2(const std::string & name, InputParameters parameters);

protected:
  void returnMap(const RankTwoTensor &, const RankTwoTensor &, const RankFourTensor &, RankTwoTensor &, RankTwoTensor &, Real &, Real &);
  void getJacJ2(const RankTwoTensor &, const RankFourTensor &, Real, Real, Real, Real, Real, Real, RankFourTensor &);
  void getFlowTensorJ2(const RankTwoTensor &, Real, Real, Real, RankTwoTensor &);
  Real getFlowIncrementJ2(Real, Real, Real, Real, Real);
  Real getDerivativeFlowIncrementJ2(const RankTwoTensor &, Real);
  void get_py_qyJ2(Real, Real, Real &, Real &, Real);
};

#endif //REDBACKMECHMATERIAL_H
