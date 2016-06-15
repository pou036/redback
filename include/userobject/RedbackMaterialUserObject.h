/*
 * RedbackMaterialUserObject.h
 *
 *  Created on: Jun 15, 2016
 */

#ifndef INCLUDE_USEROBJECT_REDBACKMATERIALUSEROBJECT_H_
#define INCLUDE_USEROBJECT_REDBACKMATERIALUSEROBJECT_H_

#include "DiscreteElementUserObject.h"

class RedbackMaterialUserObject;

template<>
InputParameters validParams<RedbackMaterialUserObject>();

/**
 * This user object is used as a common location for redback material parameters
 */
class RedbackMaterialUserObject : public DiscreteElementUserObject
{
public:
	RedbackMaterialUserObject(const InputParameters & parameters);

protected:

};



#endif /* INCLUDE_USEROBJECT_REDBACKMATERIALUSEROBJECT_H_ */
