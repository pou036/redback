/*
 * RedbackElementalObjects.h
 *
 */

#ifndef SRC_USEROBJECTS_REDBACKELEMENTALOBJECTS_H_
#define SRC_USEROBJECTS_REDBACKELEMENTALOBJECTS_H_

#include "DiscreteElementUserObject.h"

#include "RedbackMaterialUserObject.h"

namespace RedbackParameters{

  //struct RedbackParam{
	//  std::string str;
	//  int index;
  //};
  //const RedbackParam ar{"ar",0};

  const std::string arStr = "ar";
  const std::string grStr = "gr";
  const std::string confiningPressureStr = "confining_pressure";
  const std::string alpha1Str = "alpha_1";
  const std::string alpha2Str = "alpha_2";
  const std::string alpha3Str = "alpha_3";
  const std::string deltaStr = "delta";
  const std::string initialPorosityStr = "initial_porosity";
  const std::string PecletNumberStr = "Peclet_number";
  const std::string biotCoefficientStr = "biot_coefficient";
  const std::string refLewisNumberStr = "ref_lewis_number";
  const std::string solidCompressiblityStr = "solid_compressibility";
  const std::string fluidCompressiblityStr = "fluid_compressibility";
  const std::string solidThermalExpansionStr = "solid_thermal_expansion";
  const std::string fluidThermalExpansionStr = "fluid_thermal_expansion";

  const std::string ElementEnumStrings
    = arStr             + " " +
	  grStr              + " " +
	  confiningPressureStr + " " +
	  alpha1Str          + " " +
	  alpha2Str          + " " +
	  alpha3Str          + " " +
	  deltaStr           + " " +
	  initialPorosityStr + " " +
	  PecletNumberStr    + " " +
	  biotCoefficientStr + " " +
	  refLewisNumberStr  + " " +
	  solidCompressiblityStr  + " " +
	  fluidCompressiblityStr  + " " +
	  solidThermalExpansionStr  + " " +
	  fluidThermalExpansionStr;
}


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

		MooseEnum parameterEnum( RedbackParameters::ElementEnumStrings , parameterName) ;
		return HasParameterObject((int)parameterEnum);
	};

	bool HasParameterObject(int parameterEnum) const{
		return _userObjectMap.find(parameterEnum) != _userObjectMap.end();
	};


	// Get parameters

	/**
	 * Returns available elemental parameters for Redback
	 * @return MooseEnum with the valid parameters for Redback elemental parameters
	 */
	static MooseEnum GetRedbackElementParametersEnum();

	static MooseEnum RedbackElementParameterEnum(const std::string& parameterName);

	const RedbackMaterialParameterUserObject* GetParameterObject (const std::string& parameterName) const{
		MooseEnum parameterEnum = RedbackElementParameterEnum(parameterName) ;
		return GetParameterObject((int)parameterEnum);
	}

	const RedbackMaterialParameterUserObject* GetParameterObject (int parameterEnum) const{
		return _userObjectMap.at(parameterEnum);
	}

	const RedbackMaterialParameterUserObject* GetIfHasParameterObject (const std::string& parameterName) const{

		if( HasParameterObject( parameterName) ){
			return GetParameterObject (parameterName);
		}

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



protected:

  std::map< int ,const RedbackMaterialParameterUserObject* > _userObjectMap;

  std::map < int , std::shared_ptr< RedbackMaterialConstant> > _default_objects;
   // used to set default values - map allows us to check which default values have been set

};


#endif /* SRC_USEROBJECTS_REDBACKELEMENTALOBJECTS_H_ */
