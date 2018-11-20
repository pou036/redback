/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#include "GenericConstantVector.h"

registerMooseObject("RedbackApp", GenericConstantVector);

template <>
InputParameters
validParams<GenericConstantVector>()
{
  InputParameters params = validParams<Material>();
  params.addRequiredParam<RealVectorValue>("vector_values",
                                           "Vector of values defining the constant vector");
  params.addRequiredParam<MaterialPropertyName>(
      "vector_name", "Name of the vector material property to be created");
  return params;
}

GenericConstantVector::GenericConstantVector(const InputParameters & parameters)
  : Material(parameters),
    _vector(getParam<RealVectorValue>("vector_values")),
    _prop(declareProperty<RealVectorValue>(getParam<MaterialPropertyName>("vector_name")))
{
}

void
GenericConstantVector::computeQpProperties()
{
  _prop[_qp] = _vector;
}
