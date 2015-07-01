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

#include "RedbackMechDissip.h"


template<>
InputParameters validParams<RedbackMechDissip>()
{
  InputParameters params = validParams<Kernel>();
  params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");
  params.addParam<bool>("is_mechanics_on", false, "is mechanics on?");
  return params;
}


RedbackMechDissip::RedbackMechDissip(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _is_mechanics_on(getParam<bool>("is_mechanics_on")),
  _mechanical_dissipation_mech(getMaterialProperty<Real>("mechanical_dissipation_mech")),
  _mechanical_dissipation_no_mech(getMaterialProperty<Real>("mechanical_dissipation_no_mech")),
  _mechanical_dissipation_jac_mech(getMaterialProperty<Real>("mechanical_dissipation_jacobian_mech")),
  _mechanical_dissipation_jac_no_mech(getMaterialProperty<Real>("mechanical_dissipation_jacobian_no_mech")),
  _time_factor(getParam<Real>("time_factor"))
{

}

RedbackMechDissip::~RedbackMechDissip()
{

}

Real
RedbackMechDissip::computeQpResidual()
{
  if (_is_mechanics_on)
  {
    return -_time_factor*_test[_i][_qp]*_mechanical_dissipation_mech[_qp];
  }
  return -_time_factor*_test[_i][_qp]*_mechanical_dissipation_no_mech[_qp];
}

Real
RedbackMechDissip::computeQpJacobian()
{

  if (_is_mechanics_on)
  {
    return -_time_factor*_test[_i][_qp] *_mechanical_dissipation_jac_mech[_qp] * _phi[_j][_qp];
  }
  return -_time_factor*_test[_i][_qp] *_mechanical_dissipation_jac_no_mech[_qp] * _phi[_j][_qp];
}
