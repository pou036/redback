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

#include "RedbackChemEndo.h"


template<>
InputParameters validParams<RedbackChemEndo>()
{
  InputParameters params = validParams<Kernel>();
  params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");
  return params;
}


RedbackChemEndo::RedbackChemEndo(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _chemical_endothermic_energy(getMaterialProperty<Real>("chemical_endothermic_energy")),
  _chemical_endothermic_energy_jac(getMaterialProperty<Real>("chemical_endothermic_energy_jacobian")),
  _time_factor(getParam<Real>("time_factor"))
{

}

RedbackChemEndo::~RedbackChemEndo()
{

}

Real
RedbackChemEndo::computeQpResidual()
{
  return _time_factor*_test[_i][_qp]*_chemical_endothermic_energy[_qp];
}

Real
RedbackChemEndo::computeQpJacobian()
{
  //std::cout<<"chemical endothermic kernel="<<_chemical_endothermic_energy[_qp] <<std::endl;
  return _time_factor*_test[_i][_qp] * _chemical_endothermic_energy_jac[_qp] * _phi[_j][_qp];
}
