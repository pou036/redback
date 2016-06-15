/*
 * RedbackElementalObjects.C
 *
 */

#include "RedbackElementParameters.h"
#include "MooseEnum.h"


namespace {

  const std::string RedbackElementParametersEnumString
    = "ar gr delta alpha_1 alpha_2 alpha_3";

}

template <>
InputParameters
validParams<RedbackElementParameters>()
{
  InputParameters params = validParams<DiscreteElementUserObject>();

  MultiMooseEnum paramEnum = MultiMooseEnum::withNamesFrom( RedbackElementParameters::GetRedbackElementParametersEnum() );
  params.addParam<MultiMooseEnum>("parameters", paramEnum,
                                          "List of supported redback material parameters.");
  params.addParam<std::vector< UserObjectName > >("user_objects", "List of names of user objects defining the corresponding user parameters.");

  return params;
}


/// Static method for use in validParams for getting the continuation method
RedbackElementParameters::RedbackElementParameters(const InputParameters& parameters) :
DiscreteElementUserObject(parameters)
{

	MultiMooseEnum paramTypes = getParam<MultiMooseEnum>("parameters");
	std::vector< UserObjectName > user_object_names
	        = isParamValid("user_objects") ? getParam<std::vector<UserObjectName> >("user_objects") : std::vector<UserObjectName>(0);

	for(unsigned int i=0; i<paramTypes.size(); ++i){
		_userObjectMap[  paramTypes.get(i) ] = &getUserObjectByName<RedbackMaterialUserObject>( user_object_names[i]);
	}

}


MooseEnum
RedbackElementParameters::GetRedbackElementParametersEnum()
{
  return MooseEnum(RedbackElementParametersEnumString);
}

