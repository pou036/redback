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

#ifndef REDBACKMECHMATERIALDP_H
#define REDBACKMECHMATERIALDP_H

#include "RedbackMechMaterial.h"

//Forward Declarations
class RedbackMechMaterialDP;

template<>
InputParameters validParams<RedbackMechMaterialDP>();

class RedbackMechMaterialDP : public RedbackMechMaterial
{
public:
  RedbackMechMaterialDP(const std::string & name, InputParameters parameters);

protected:
  virtual void returnMap(const RankTwoTensor &, const RankTwoTensor &, const RankFourTensor &, RankTwoTensor &, RankTwoTensor &, Real &, Real &);
  Real getPressureProjectionDP(Real, Real, Real);
  void getJacDP(const RankTwoTensor &, const RankFourTensor &, Real, Real, Real, Real, RankFourTensor &);
  void getFlowTensorDP(const RankTwoTensor &, Real, RankTwoTensor &);
  Real getFlowIncrementDP(Real, Real, Real, Real);
  Real getDerivativeFlowIncrementDP(const RankTwoTensor &, Real, Real, Real, Real);
  void get_py_qy_DP(Real, Real, Real &, Real &, Real);

};

#endif //REDBACKMECHMATERIALDP_H
