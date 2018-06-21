/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#include "Assembly.h"
#include "RankTwoProjectionAux.h"

template <>
InputParameters
validParams<RankTwoProjectionAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addClassDescription("Compute the norm of a RankTwoTensor projected on a vector");
  params.addRequiredParam<MaterialPropertyName>("rank_two_tensor",
                                                "The rank two material tensor name");
  params.addParam<bool>("normal", false, "If true, the normal value to the fault will be computed");
  params.addCoupledVar("pressure", 0.0, "Dimensionless pore pressure");
  return params;
}

RankTwoProjectionAux::RankTwoProjectionAux(const InputParameters & parameters)
  : AuxKernel(parameters),
    _tensor(getMaterialProperty<RankTwoTensor>("rank_two_tensor")),
    _normal(getParam<bool>("normal")),
    _has_pres(isCoupled("pressure")),
    _pressure(_has_pres ? coupledValue("pressure") : _zero),
    _normals(_assembly.normals())
{
}

Real
RankTwoProjectionAux::computeValue()
{
  // traction ti = sigma_ij . n_i
  // traction ti = (sigma_ij' - pI) . n_i
  // ti = ti_t + ti_n
  // ti_t = ti - ||ti_n||.n_i
  // ti_t = ti - (ti . n_i).n_i
  RankTwoTensor total_stress = _tensor[_qp];
  total_stress.addIa(-_pressure[_qp]);
  RealVectorValue traction = total_stress * _normals[_qp];
  if (_normal)
    return traction * _normals[_qp];
  RealVectorValue tangent_traction = traction - (traction * _normals[_qp]) * _normals[_qp];
  return std::sqrt(tangent_traction.norm_sq());
}
