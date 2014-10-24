/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "RedbackDummyMaterial.h"

template<>
InputParameters validParams<RedbackDummyMaterial>()
{
  InputParameters params = validParams<Material>();

  params.addParam<Real>("dummy_param", 0.12, "Something or other...");

  return params;
}

RedbackDummyMaterial::RedbackDummyMaterial(const std::string & name, InputParameters parameters) :
  Material(name, parameters),
  _dummy_prop_param(getParam<Real>("dummy_param")),
  _dummy_prop(declareProperty<Real>("dummy_prop")),

  _phi0(getMaterialProperty<Real>("porosity"))


{
}

//=================================================================



void
RedbackDummyMaterial::computeQpProperties()
{
  _dummy_prop[_qp] = _dummy_prop_param + _q_point[_qp](0)/100.;
  std::cout << "RedbackDummyMaterial::computeQpProperties()" <<std::endl;
  std::cout << "  _dummy_prop[_qp]=" << _dummy_prop[_qp] << "\tat coords " << _q_point[_qp](0) << std::endl;
  std::cout << "  _phi0[_qp]=" << _phi0[_qp] << "\t\tat coords " << _q_point[_qp](0) << std::endl;
  if (_qp == 1)
  {
    std::cout << std::endl << std::endl;
  }
}


