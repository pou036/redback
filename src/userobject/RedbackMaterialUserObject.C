/*
 * RedbackMaterialUserObject.C
 *
 *  Created on: Jun 15, 2016
 */


#include "RedbackMaterialUserObject.h"


template <>
InputParameters
validParams<RedbackMaterialParameterUserObject>()
{
  InputParameters params = validParams<DiscreteElementUserObject>();

  return params;
}

RedbackMaterialParameterUserObject::RedbackMaterialParameterUserObject(const InputParameters& parameters) :
DiscreteElementUserObject(parameters)
{
 /* empty */
}

/////


template <>
InputParameters
validParams<RedbackMaterialConstant>()
{
  InputParameters params = validParams<RedbackMaterialParameterUserObject>();

  params.addParam<Real>("value", 0.0, "Value of material parameter.");

  return params;
}

RedbackMaterialConstant::RedbackMaterialConstant(const InputParameters& parameters) :
		RedbackMaterialParameterUserObject(parameters),
		_value(getParam<Real>("value"))
{
	/* empty */
}


RedbackMaterialConstant::RedbackMaterialConstant(const InputParameters&  params, Real val) :
		RedbackMaterialParameterUserObject( params  ),
		_value(val)
{
	/* empty */
}

