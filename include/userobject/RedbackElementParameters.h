/*
 * RedbackElementalObjects.h
 *
 */

#ifndef SRC_USEROBJECTS_REDBACKELEMENTALOBJECTS_H_
#define SRC_USEROBJECTS_REDBACKELEMENTALOBJECTS_H_

#include "DiscreteElementUserObject.h"

#include "RedbackMaterialUserObject.h"

namespace RedbackParameters{

  struct RedbackParam{
	  std::string str;
	  std::string description;
	 // int index;
  };
  //const RedbackParam ar{"ar",0};

  const RedbackParam ar{"ar","Arrhenius number."};
  const RedbackParam gr{"gr","Gruntfest number."};
  const RedbackParam confiningPressure{"confining_pressure","Normalised confining pressure"};
  const RedbackParam alpha1{"alpha_1","First parameter for activation "
                                         "volume, alpha_1 V_{ref} / (R T_{ref}) "
                                         "in the redback paper"};
  const RedbackParam alpha2{"alpha_2", "Second parameter for activation "
                                          "volume, alpha_2 V_{ref} / (R T_{ref}) "
                                          "in the redback paper"};
  const RedbackParam alpha3{"alpha_3","Third parameter for activation volume, alpha_3 in the redback paper"};
  const RedbackParam delta{"delta","Kamenetskii coefficient."};
  const RedbackParam initialPorosity{"initial_porosity","Initial porosity value."};
  const RedbackParam PecletNumber{"Peclet_number","Peclet number"};
  const RedbackParam biotCoefficient{"biot_coefficient","Biot coefficient"};
  const RedbackParam refLewisNumber{"ref_lewis_number", "Reference Lewis number."};
  const RedbackParam solidCompressiblity{"solid_compressibility","solid compressibility (beta^{(s)} in 1/Pa)"};
  const RedbackParam fluidCompressiblity{"fluid_compressibility",
                                            "fluid compressibility (beta^{(f)} in 1/Pa)"};
  const RedbackParam solidThermalExpansion{"solid_thermal_expansion","solid expansion (lambda^{(s)} in 1/K)"};
  const RedbackParam fluidThermalExpansion{"fluid_thermal_expansion","fluid expansion (lambda^{(f)} in 1/K)"};

  const std::vector<const RedbackParam> ParameterList{
	  ar,
	  gr,
	  confiningPressure,
	  alpha1,alpha2,alpha3,
	  delta,
	  initialPorosity,
	  PecletNumber,
	  biotCoefficient,refLewisNumber,
	  solidCompressiblity,
	  fluidCompressiblity,solidThermalExpansion,
	  fluidThermalExpansion
  };

  inline
  std::string JoinStrings(const std::vector<const RedbackParam>& paramVector , const std::string& separator = " "){
	  std::string rv = "";

	  for(const RedbackParam& param: paramVector ) rv += param.str + separator;
	  return rv;
  }

  const std::string ElementEnumString = JoinStrings(ParameterList);
  /*
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
	  */

  // Default values
  // - only add parameters that *must* be initialized here.
  const std::map< std::string, Real > DefaultValues{
  		{ar.str, 0.0},
  		{gr.str, 1.0},
  		{alpha1.str, 0.0},
  		{alpha2.str, 0.0},
  		{alpha3.str, 0.0},
  		{delta.str, 0.0},
		{solidCompressiblity.str, 1.0},
		{fluidCompressiblity.str, 0.0},
		{solidThermalExpansion.str, 0.0},
		{fluidThermalExpansion.str, 0.0}
  };

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

		MooseEnum parameterEnum( RedbackParameters::ElementEnumString , parameterName) ;
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
