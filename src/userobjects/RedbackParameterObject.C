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

#include "RedbackParameterObject.h"

template <>
InputParameters
validParams<RedbackParameterObject>()
{
  InputParameters params = validParams<GeneralUserObject>();
  //params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");

  //params.set<bool>("use_displaced_mesh") = true;
  return params;
}

RedbackParameterObject::RedbackParameterObject(const InputParameters & parameters) :
		GeneralUserObject(parameters)
{
}


void
RedbackParameterObject::initialize()
{

}

void
RedbackParameterObject::execute()
{

}

void
RedbackParameterObject::threadJoin(const UserObject & y)
{

}

void
RedbackParameterObject::finalize()
{


}


