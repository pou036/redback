/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#include "RankTwoProjectionAux.h"

template <>
InputParameters
validParams<RankTwoProjectionAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addClassDescription("Compute the norm of a RankTwoTensor projected on a vector");
  params.addRequiredParam<MaterialPropertyName>("rank_two_tensor", "The rank two material tensor name");
  params.addRequiredParam<Real>("fault_angle", "The angle of the fault with respect to the horizontal in degrees");
  params.addParam<bool>("normal",
                        false,
                        "If true, the normal value to the fault "
                        "will be computed");
  params.addParam<bool>("convert_to_radians",
                        false,
                        "If true, the value you entered will be "
                        "multiplied by Pi/180");
  return params;
}

RankTwoProjectionAux::RankTwoProjectionAux(const InputParameters & parameters) :
    AuxKernel(parameters),
    _tensor(getMaterialProperty<RankTwoTensor>("rank_two_tensor")),
    _normal(getParam<bool>("normal")),
    _angle(getParam<bool>("convert_to_radians") ? getParam<Real>("fault_angle") * M_PI / 180.0
                                                : getParam<Real>("fault_angle"))
{
}

Real
RankTwoProjectionAux::computeValue()
{
  // traction ti = sigma_ij . n_i
  // ti = ti_t + ti_n
  // ||ti_t|| = (ti - ||ti_n||.n_i) . t_i
  // ||ti_t|| = (ti - (ti . n_i).n_i) . t_i
  RealVectorValue fault_normal(-sin(_angle), cos(_angle));
  RealVectorValue fault_tangent(cos(_angle), sin(_angle));
  RealVectorValue traction = _tensor[ _qp ] * fault_normal;
  return (traction - (traction * fault_normal) * fault_normal) * fault_tangent;
  // RealVectorValue fault(-sin(_angle), cos(_angle));
  // if (_normal)
  //   fault = RealVectorValue(cos(_angle), sin(_angle));
  // RealVectorValue vec_temp(_tensor[ _qp ].row(0) * fault, _tensor[ _qp ].row(1) * fault);
  // return std::pow(std::pow(vec_temp(0), 2) + std::pow(vec_temp(1), 2), 0.5);
}
