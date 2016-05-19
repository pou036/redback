/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/


/*
 * MaterialPropertyOrConstant.h
 *
 *  Created on: May 19, 2016
 *      Author: stuartwalsh
 */

#ifndef INCLUDE_MATERIALS_MATERIALPROPERTYORCONSTANT_H_
#define INCLUDE_MATERIALS_MATERIALPROPERTYORCONSTANT_H_

#include "MaterialProperty.h"


namespace{

  template<class Type> Type GetParamIfRealZeroOtherwise(Material& theMaterial, std::string& name);

  template<>
  Real GetParamIfRealZeroOtherwise<Real>(Material& theMaterial, std::string& name){
	return theMaterial.getParam<Real>(name);
  };

  template<class Type>
  Type GetParamIfRealZeroOtherwise(Material& theMaterial, std::string& name){
	return Type();
  };

}


// used to declare an property that may either be a field or a constant in space
template<class Type>
class MaterialPropertyOrConstant
{

public:

	MaterialPropertyOrConstant(Material& theMaterial, std::string name):
		_constantValue( GetParamIfRealZeroOtherwise<Type>(theMaterial,name) )
	{

		bool isConstant =  theMaterial.getParam<bool>(name+"_is_constant"); // is constant in space
		if( !isConstant ){
			_fieldPtr = &theMaterial.declareProperty<Type>(name);
		}

	}

  /**
   * Get element i out of the array or the constant value if field is not set
   */
	const Type & operator[](const unsigned int i) const{

	  if(_fieldPtr){
		  return (*_fieldPtr)[i];
	  }
	  return _constantValue;
   }

	/**
	 * Get element i out of the array or the constant value if the field is not set
	 */
	/*Type & operator[](const unsigned int i) {

	  if(_fieldPtr){
		  return (*_fieldPtr)[i];
	  }
	  // This is dangerous - may want to throw a warning here.
	  return _constantValue;
   }*/

private:

  Type _constantValue;
  MaterialProperty<Type>* _fieldPtr;

};



// used to declare an optional material property
// i.e. one that may not be needed for some simulation,
// but should an error if not declared and requested
template<class Type>
class OptionalMaterialProperty
{

public:

	OptionalMaterialProperty(Material& theMaterial, std::string name):
		_name(name)
	{

		bool isValid =  theMaterial.isParamValid(name); // i.e. has been given a default value or set from the input file
		if( isValid ){
			_fieldPtr = &theMaterial.declareProperty<Type>(name);
		}

	}

  /**
   * Get element i out of the array or the constant value if field is not set
   */
	Type & operator[](const unsigned int i) {

	  if(_fieldPtr){
		  return (*_fieldPtr)[i];
	  }

	  // error - attempting to access the field when it hasn't been set.
	    mooseError("Attempting to access uninitialized optional field" + _name);

   }

private:

  std::string _name;

  MaterialProperty<Type>* _fieldPtr;


};


#endif /* INCLUDE_MATERIALS_MATERIALPROPERTYORCONSTANT_H_ */
