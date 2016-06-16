/*
 * RedbackElementalObjects.h
 *
 */

#ifndef SRC_USEROBJECTS_REDBACKELEMENTALOBJECTS_H_
#define SRC_USEROBJECTS_REDBACKELEMENTALOBJECTS_H_

#include "DiscreteElementUserObject.h"

#include "RedbackMaterialUserObject.h"

class RedbackElementParameters;

template<>
InputParameters validParams<RedbackElementParameters>();

/**
 * This user object provides a common location to store redback material parameters
 */
class RedbackElementParameters : public DiscreteElementUserObject
{
public:

	RedbackElementParameters(const InputParameters & parameters);


	// Has parameters

	bool HasParameterObject(const std::string& parameterName) const{
		MooseEnum parameterEnum(GetRedbackElementParametersEnum() , parameterName) ;
		return HasParameterObject((int)parameterEnum);
	};

	bool HasParameterObject(int parameterEnum) const{
		return _userObjectMap.find(parameterEnum) != _userObjectMap.end();
	};

	// Get parameters

	const RedbackMaterialParameterUserObject* GetParameterObject (const std::string& parameterName) const{
		MooseEnum parameterEnum(GetRedbackElementParametersEnum() , parameterName) ;
		return GetParameterObject((int)parameterEnum);
	}

	const RedbackMaterialParameterUserObject* GetParameterObject (int parameterEnum) const{
		return _userObjectMap.at(parameterEnum);
	}

	const RedbackMaterialParameterUserObject* GetIfHasParameterObject (const std::string& parameterName) const{

		if( HasParameterObject( parameterName) )
			   return GetParameterObject (parameterName);

		return 0; // return null ptr
	}

	const RedbackMaterialParameterUserObject* GetRequiredParameterObject (const std::string& parameterName) const{

		if( HasParameterObject( parameterName) ){
			   return GetParameterObject (parameterName);
		} else {
		      mooseError("Error! RedbackElementParameters: Expected parameter " + parameterName + " was not found in parameter list.");
		}

		// should not get here
		return 0;
	}

	/**
	 * Returns available elemental parameters for Redback
	 * @return MooseEnum with the valid parameters for Redback elemental parameters
	 */
	static MooseEnum GetRedbackElementParametersEnum();

protected:

  std::map< int ,const RedbackMaterialParameterUserObject* > _userObjectMap;

};


#endif /* SRC_USEROBJECTS_REDBACKELEMENTALOBJECTS_H_ */
