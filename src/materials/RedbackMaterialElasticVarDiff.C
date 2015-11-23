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

#include "RedbackMaterialElasticVarDiff.h"

template<>
InputParameters validParams<RedbackMaterialElasticVarDiff>()
{
  InputParameters params = validParams<RedbackMechMaterial>();

  params.addParam<std::vector<Real> >("cracks","Crack geometry:density,length,aperture,angle");
  params.addParam<Real>("Prefactor","Between 0 and 1, depending on interconnectivity");

  return params;
}

RedbackMaterialElasticVarDiff::RedbackMaterialElasticVarDiff(const InputParameters & parameters) :
    RedbackMechMaterial(parameters),

   _crack(getParam<std::vector<Real> >("cracks")),
   _lambda(getParam<Real>("Prefactor")),


   _k(declareProperty<RealTensorValue>("tensor_diffusivity"))
{

}

void RedbackMaterialElasticVarDiff::stepInitQpProperties()
{
	_k[_qp].zero();
}

void
RedbackMaterialElasticVarDiff::returnMap(const RankTwoTensor & sig_old, const RankTwoTensor & delta_d, const RankFourTensor & E_ijkl, RankTwoTensor & dp, RankTwoTensor & sig, Real & p_y, Real & q_y)
{
  sig = sig_old + E_ijkl * delta_d;
  dp = RankTwoTensor(); //Plastic rate of deformation tensor in unrotated configuration
}

void
RedbackMaterialElasticVarDiff::getFlowTensor(const RankTwoTensor & sig, Real q, Real p, Real yield_stress, RankTwoTensor & flow_tensor_dev)
{
}

Real
RedbackMaterialElasticVarDiff::getFlowIncrement(Real sig_eqv, Real p, Real q_y, Real p_y, Real yield_stress)
{
  return 0;
}

void
RedbackMaterialElasticVarDiff::getJac(const RankTwoTensor & sig, const RankFourTensor & E_ijkl, Real flow_incr_dev,
        Real q, Real p, Real p_y, Real q_y, Real yield_stress, RankFourTensor & dresid_dsig)
{
}

void
RedbackMaterialElasticVarDiff::get_py_qy(Real p, Real q, Real & p_y, Real & q_y, Real yield_stress)
{
}

void
RedbackMaterialElasticVarDiff::computeRedbackTerms(RankTwoTensor & sig, Real q_y, Real p_y)
{
    RealTensorValue perm(_lambda, 0, 0, 0, 0.01, 0, 0, 0, 0.01);
    _k[_qp] = perm;
    return;
}



