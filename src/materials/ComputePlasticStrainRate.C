/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#include "ComputePlasticStrainRate.h"

template <>
InputParameters
validParams<ComputePlasticStrainRate>()
{
  InputParameters params = validParams<Material>();
  params.addParam<std::string>("base_name",
                               "Optional parameter that allows the user to define "
                               "multiple mechanics material systems on the same "
                               "block, i.e. for multiple phases");
  return params;
}

ComputePlasticStrainRate::ComputePlasticStrainRate(const InputParameters & parameters)
  : DerivativeMaterialInterface<Material>(parameters),
    _base_name(isParamValid("base_name") ? getParam<std::string>("base_name") + "_" : ""),
    _plastic_strain(getMaterialProperty<RankTwoTensor>("plastic_strain")),
    _plastic_strain_old(getMaterialPropertyOld<RankTwoTensor>("plastic_strain")),
    _plastic_strain_rate(declareProperty<RankTwoTensor>(_base_name + "plastic_strain_rate"))
{
}

void
ComputePlasticStrainRate::computeQpProperties()
{
  if (_dt > 0)
    _plastic_strain_rate[ _qp ] = (_plastic_strain[ _qp ] - _plastic_strain_old[ _qp ]) / _dt;
  else
    _plastic_strain_rate[ _qp ].zero();
}
