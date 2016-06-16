/*
 * RedbackElementalObjects.C
 *
 */

#include "RedbackElementParameters.h"
#include "MooseEnum.h"




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

	// sanity check
	if( paramTypes.size() != user_object_names.size() ){
        mooseError("Error! RedbackElementParameters: Number of user objects " + std::to_string( user_object_names.size() ) + " does not match number of parameters " + std::to_string( paramTypes.size() ));
	}


	for(unsigned int i=0; i<paramTypes.size(); ++i){
		_userObjectMap[  paramTypes.get(i) ] = &getUserObjectByName<RedbackMaterialParameterUserObject>( user_object_names[i]);
	}

}


MooseEnum
RedbackElementParameters::GetRedbackElementParametersEnum()
{
  return MooseEnum(RedbackParameters::ElementEnumStrings);
}

