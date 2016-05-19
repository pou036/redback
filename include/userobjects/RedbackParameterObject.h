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
 *  Created on: May 19, 2016
 *      Author: stuartwalsh
 */

#ifndef INCLUDE_USEROBJECTS_REDBACKPARAMETEROBJECT_H_
#define INCLUDE_USEROBJECTS_REDBACKPARAMETEROBJECT_H_


#include "GeneralUserObject.h"

//Forward Declarations
class RedbackParameterObject;

template<>
InputParameters validParams<RedbackParameterObject>();

/**
 * Computes the average value of a variable on each block
 */
class RedbackParameterObject : public GeneralUserObject
{
public:
	RedbackParameterObject(const InputParameters & parameters);

  /**
   * This is called before execute to reset any internal data.
   */
  virtual void initialize();

  /**
   * Called on every "object" (like every element or node).
   */
  virtual void execute();

  /**
   * Called when using threading.  You need to combine the data from "y"
   * into _this_ object.
   */
  virtual void threadJoin(const UserObject & y);

  /**
   * Called _once_ after execute has been called all all "objects".
   */
  virtual void finalize();

protected:

};




#endif /* INCLUDE_USEROBJECTS_REDBACKPARAMETEROBJECT_H_ */
