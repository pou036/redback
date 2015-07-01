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

#include "RedbackChemPressure.h"


template<>
InputParameters validParams<RedbackChemPressure>()
{
  InputParameters params = validParams<Kernel>();
  params.addCoupledVar("temperature", 0.0, "Temperature variable.");
  params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");
  return params;
}


RedbackChemPressure::RedbackChemPressure(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _chemical_source_mass(getMaterialProperty<Real>("chemical_source_mass")),
  _chemical_source_mass_jac(getMaterialProperty<Real>("chemical_source_mass_jacobian")),
  _temp_var(coupled("temperature")),
  _time_factor(getParam<Real>("time_factor"))
{

}

RedbackChemPressure::~RedbackChemPressure()
{

}

Real
RedbackChemPressure::computeQpResidual()
{
  return -_time_factor*_test[_i][_qp]*_chemical_source_mass[_qp];
}

Real
RedbackChemPressure::computeQpJacobian()
{
  return 0;
}

Real
RedbackChemPressure::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _temp_var)
  {
    return -_time_factor*_test[_i][_qp] * _chemical_source_mass_jac[_qp] * _phi[_j][_qp];
  }
  return 0;
}
