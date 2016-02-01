/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#include "RedbackPlasticityUOBase.h"

template<>
InputParameters validParams<RedbackPlasticityUOBase>()
{
  InputParameters params = validParams<GeneralUserObject>();
  // params.addParam<std::string>("strength_prop_name", "Name of strength property: Same as strength user object specified in input file");
  // params.addParam<std::string>("base_name", "Base name of tensor properties to fetch");
  // params.addClassDescription("User object to evaluate flow rate");
  params.addClassDescription("Plastic Model base class.  Override the virtual functions in your class");

  return params;
}

RedbackPlasticityUOBase::RedbackPlasticityUOBase(const InputParameters & parameters) :
    GeneralUserObject(parameters)
    // ,
    // _strength_prop_name(getParam<std::string>("strength_prop_name")),
    // _base_name(isParamValid("base_name") ? getParam<std::string>("base_name") + "_" : ""),
    // _strength(getMaterialPropertyByName<Real>(_strength_prop_name)),
    // _pk2_prop_name(_base_name + "pk2"),
    // _pk2(getMaterialPropertyByName<RankTwoTensor>(_pk2_prop_name)),
    // _ce(getMaterialPropertyByName<RankTwoTensor>(_base_name + "ce"))
{
}


Real
RedbackPlasticityUOBase::macaulayBracket(Real val) const
{
  if (val > 0.0)
    return val;
  else
    return 0.0;
}

Real
RedbackPlasticityUOBase::getSigEqv(const RankTwoTensor & stress) const
{
  return std::pow(3 * stress.secondInvariant(), 0.5);
}


Real
RedbackPlasticityUOBase::deltaFunc(const unsigned int i, const unsigned int j) const
{
  if (i == j)
    return 1.0;
  else
    return 0.0;
}
