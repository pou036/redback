/*
 * RedbackMaterialUserObject.h
 *
 *  Created on: Jun 15, 2016
 */

#ifndef INCLUDE_USEROBJECT_REDBACKMATERIALUSEROBJECT_H_
#define INCLUDE_USEROBJECT_REDBACKMATERIALUSEROBJECT_H_

#include "DiscreteElementUserObject.h"

class RedbackMaterialParameterUserObject;

template<>
InputParameters validParams<RedbackMaterialParameterUserObject>();

/**
 * This user object provides a base class for user objects representing material parameters
 */
class RedbackMaterialParameterUserObject : public DiscreteElementUserObject
{
public:
	RedbackMaterialParameterUserObject(const InputParameters & parameters);

	virtual Real value(unsigned int qp) const = 0;

	Real operator[](unsigned int qp) const{ return value(qp);}

	virtual Real derivative(unsigned int qp) const = 0;

	virtual std::string activeModelName(unsigned int qp) const = 0;

protected:

};

////////////////

class RedbackMaterialConstant;

template<>
InputParameters validParams<RedbackMaterialConstant>();

// User object representing a parameter that is a spatial and temporal constant
class RedbackMaterialConstant : public RedbackMaterialParameterUserObject
{
public:
	RedbackMaterialConstant(const InputParameters & parameters);
	RedbackMaterialConstant(const InputParameters & parameters, Real value);

	virtual Real value(unsigned int qp) const {return _value;};

	virtual Real derivative(unsigned int qp) const {return 0;};

	virtual std::string activeModelName(unsigned int qp) const {return "Redback_Material_Constant";};

protected:
	Real _value; // the value of the constant
};




#endif /* INCLUDE_USEROBJECT_REDBACKMATERIALUSEROBJECT_H_ */
