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

#include "RedbackMechDissipWithoutMech.h"


template<>
InputParameters validParams<RedbackMechDissipWithoutMech>()
{
  InputParameters params = validParams<Kernel>();
  params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");
  return params;
}


RedbackMechDissipWithoutMech::RedbackMechDissipWithoutMech(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _mechanical_dissipation_no_mech(getMaterialProperty<Real>("mechanical_dissipation_no_mech")),
  _mechanical_dissipation_jac_no_mech(getMaterialProperty<Real>("mechanical_dissipation_jacobian_no_mech")),
  _time_factor(getParam<Real>("time_factor"))
{

}

RedbackMechDissipWithoutMech::~RedbackMechDissipWithoutMech()
{

}

Real
RedbackMechDissipWithoutMech::computeQpResidual()
{
  return -_time_factor*_test[_i][_qp]*_mechanical_dissipation_no_mech[_qp];
}

Real
RedbackMechDissipWithoutMech::computeQpJacobian()
{
  return -_time_factor*_test[_i][_qp] *_mechanical_dissipation_jac_no_mech[_qp] * _phi[_j][_qp];
}
