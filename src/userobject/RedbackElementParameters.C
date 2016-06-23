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
  /*
  params.addParam<MultiMooseEnum>("parameters", paramEnum,
                                          "List of supported redback material parameters.");
  params.addParam<std::vector< UserObjectName > >("user_objects", "List of names of user objects defining the corresponding user parameters.");
  */

  for(const RedbackParameters::RedbackParam& param : RedbackParameters::ParameterList){
	  params.addParam< UserObjectName >(param.str,param.description);
  }

  params.addParam< UserObjectName >("plastic_model","User object defining the plastic response of the material");

  return params;
}


/// Static method for use in validParams for getting the continuation method
RedbackElementParameters::RedbackElementParameters(const InputParameters& parameters) :
DiscreteElementUserObject(parameters)
{

	/*
	MultiMooseEnum paramTypes = getParam<MultiMooseEnum>("parameters");
	std::vector< UserObjectName > user_object_names
	        = isParamValid("user_objects") ? getParam<std::vector<UserObjectName> >("user_objects") : std::vector<UserObjectName>(0);

	// sanity check
	if( paramTypes.size() != user_object_names.size() ){
        mooseError("Error! RedbackElementParameters: Number of user objects " + std::to_string( user_object_names.size() ) + " does not match number of parameters " + std::to_string( paramTypes.size() ));
	}
	*/

	// Get active params
	typedef std::pair< std::string, UserObjectName > StringObjectPair;
	std::vector< StringObjectPair  > activeParams;

	for(const RedbackParameters::RedbackParam& param :  RedbackParameters::ParameterList){
      if( isParamValid( param.str ) ){

    	  UserObjectName uoName = getParam< UserObjectName >( param.str );
    	  activeParams.push_back( StringObjectPair( param.str , uoName  ) );

      }
	}

	for(const StringObjectPair& paramObject : activeParams ){
		 MooseEnum indx = RedbackElementParameterEnum( paramObject.first  );
		_userObjectMap[  (int) indx ] = &getUserObjectByName<RedbackMaterialParameterUserObject>( paramObject.second );
	}


    // insert default values for params that have not been defined
	for( const std::pair<std::string, Real >& keyValue : RedbackParameters::DefaultValues  ){
	  const std::string& paramStr = keyValue.first;
	  const Real& val = keyValue.second;

	  MooseEnum indx = RedbackElementParameterEnum( paramStr  );
	  if( !HasParameterObject( (int) indx ) ){

		_default_objects[  (int) indx ] = std::make_shared<RedbackMaterialConstant>(parameters,val); // nb slightly dodgy - using parameters from this class to initialize the constant fields
		_userObjectMap[  (int) indx ] = &( *_default_objects[ (int) indx ] );
	  }
	}


	// plastic model  define here or in material??
	 if( isParamValid("plastic_model") ){
   	      UserObjectName pmName = getParam< UserObjectName >( "plastic_model" );
		 _plastic_model = &getUserObjectByName<TensorMechanicsPlasticModel>( pmName );
	 }


}


MooseEnum
RedbackElementParameters::GetRedbackElementParametersEnum()
{
  return MooseEnum(RedbackParameters::ElementEnumString);
}

MooseEnum RedbackElementParameters::RedbackElementParameterEnum(const std::string& parameterName)
{
		return MooseEnum( RedbackParameters::ElementEnumString, parameterName) ;
}

