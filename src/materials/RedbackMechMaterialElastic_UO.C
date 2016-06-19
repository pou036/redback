/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "RedbackMechMaterialElastic_UO.h"

template <>
InputParameters
validParams<RedbackMechMaterial_Elastic_UO>()
{
  InputParameters params = validParams<RedbackMechMaterial_UO>();
  return params;
}

RedbackMechMaterial_Elastic_UO::RedbackMechMaterial_Elastic_UO(const InputParameters & parameters) :
    RedbackMechMaterial_UO(parameters)
{
}

void
RedbackMechMaterial_Elastic_UO::returnMap(const RankTwoTensor & sig_old,
                                      const RankTwoTensor & delta_d,
                                      const RankFourTensor & E_ijkl,
                                      RankTwoTensor & dp,
                                      RankTwoTensor & sig,
                                      Real & p_y,
                                      Real & q_y)
{
  sig = sig_old + E_ijkl * delta_d;
  dp = RankTwoTensor(); // Plastic rate of deformation tensor in unrotated
                        // configuration
}

void
RedbackMechMaterial_Elastic_UO::getFlowTensor(
  const RankTwoTensor & sig, Real q, Real p, Real yield_stress, RankTwoTensor & flow_tensor_dev)
{
}

Real
RedbackMechMaterial_Elastic_UO::getFlowIncrement(Real sig_eqv, Real p, Real q_y, Real p_y, Real yield_stress)
{
  return 0;
}

void
RedbackMechMaterial_Elastic_UO::getJac(const RankTwoTensor & sig,
                                   const RankFourTensor & E_ijkl,
                                   Real flow_incr_dev,
                                   Real q,
                                   Real p,
                                   Real p_y,
                                   Real q_y,
                                   Real yield_stress,
                                   RankFourTensor & dresid_dsig)
{
}

void
RedbackMechMaterial_Elastic_UO::get_py_qy(Real p, Real q, Real & p_y, Real & q_y, Real yield_stress)
{
}
