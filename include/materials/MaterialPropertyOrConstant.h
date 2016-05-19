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

// helper functions
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

/////////////////////////////

// MaterialPropertyOrConstant

/// used to declare an property that may either be a field or a constant in space
template<class Type>
class MaterialPropertyOrConstant
{

public:

	MaterialPropertyOrConstant(Material& theMaterial, std::string name):
		_name(name),
		_constantValue( GetParamIfRealZeroOtherwise<Type>(theMaterial,name) )
	{

		bool isConstant =  theMaterial.getParam<bool>(name+"_is_constant"); // is constant in space
		if( !isConstant ){
			_fieldPtr = &theMaterial.declareProperty<Type>(name);
		}

	}

  /**
   * Get element i out of the array or the constant value if field is not set
   *
   **/
	const Type & operator[](const unsigned int i) const{  // constant to prevent accidental assignment

	  if(_fieldPtr){
		  return (*_fieldPtr)[i];
	  }
	  return _constantValue;
	}


	/**
	 * Set the whole field to a constant value
	 *
	 **/
	void SetConstantValue(const unsigned int i, const Type& value){

		if(_fieldPtr){
			(*_fieldPtr)[i] = value;
		} else {
			_constantValue = value;
		}

	}


	/**
	 * Set the value of an element of the field - throw an error if spatially constant
	 *
	 **/
	void SetValue(const unsigned int i, const Type& value){

		if(_fieldPtr){
			(*_fieldPtr)[i] = value;
		} else {
			  mooseError("Attempting to vary value of constant field " + _name + ".");
		}

	}


private:
  std::string _name;
  Type _constantValue;
  MaterialProperty<Type>* _fieldPtr;

};


/////////////////////////////

// OptionalMaterialProperty

// used to define an optional material property
// i.e. one that may not be needed for some simulations,
// but should throw an error if required and not explicitly declared
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
   * Get element i out of the array or throw an error if the field is not set
   */
	Type & operator[](const unsigned int i) {

	  if(_fieldPtr){
		  return (*_fieldPtr)[i];
	  }

	  // error - attempting to access the field when it hasn't been set.
	  mooseError("Attempting to access uninitialized optional field" + _name);

	}

	bool IsActive(){ return _fieldPtr != nullptr; }

   /**
    *  Set if the field is active, but don't freak out if it is not.
    */
	void SetIfActive(const unsigned int i, const Type& value) {

		if(_fieldPtr){
			(*_fieldPtr)[i] = value;
		}

	}

private:

  std::string _name;

  MaterialProperty<Type>* _fieldPtr;


};


#endif /* INCLUDE_MATERIALS_MATERIALPROPERTYORCONSTANT_H_ */
