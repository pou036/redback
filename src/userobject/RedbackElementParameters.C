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

	// Could set default values (constants) earlier ...
	std::vector<std::pair<std::string, Real > > defaultValues{
		{RedbackParameters::arStr, 0.0},
		{RedbackParameters::grStr, 1.0},
		{RedbackParameters::alpha1Str, 0.0},
		{RedbackParameters::alpha2Str, 0.0},
		{RedbackParameters::alpha3Str, 0.0}
	};

	for( const std::pair<std::string, Real >& keyValue : defaultValues  ){
	  const std::string& paramStr = keyValue.first;
	  const Real& val = keyValue.second;

	  MooseEnum indx = RedbackElementParameterEnum( paramStr  );
	  if( !HasParameterObject( (int) indx ) ){

		_default_objects[  (int) indx ] = std::make_shared<RedbackMaterialConstant>(val);
		_userObjectMap[  (int) indx ] = &( *_default_objects[ (int) indx ] );
	  }
	}



}


MooseEnum
RedbackElementParameters::GetRedbackElementParametersEnum()
{
  return MooseEnum(RedbackParameters::ElementEnumStrings);
}

MooseEnum RedbackElementParameters::RedbackElementParameterEnum(const std::string& parameterName)
{
		return MooseEnum( RedbackParameters::ElementEnumStrings, parameterName) ;
	}

