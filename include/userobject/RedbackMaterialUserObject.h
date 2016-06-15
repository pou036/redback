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

	virtual Real value(Real qp) const;

	virtual Real derivative(Real qp) const;

	virtual std::string activeModelName(Real qp) const = 0;

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

	virtual Real value(Real qp) const {return _value;};

	virtual Real derivative(Real qp) const {return 0;};

	virtual std::string activeModelName(Real qp) const {return "Redback_Material_Constant";};

protected:
	Real _value; // the value of the constant
};




#endif /* INCLUDE_USEROBJECT_REDBACKMATERIALUSEROBJECT_H_ */
