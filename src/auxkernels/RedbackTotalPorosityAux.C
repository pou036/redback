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

#include "RedbackTotalPorosityAux.h"

registerMooseObject("RedbackApp", RedbackTotalPorosityAux);

template <>
InputParameters
validParams<RedbackTotalPorosityAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addParam<bool>("is_mechanics_on", false, "is mechanics on?");
  // params.addParam<bool>("is_chemistry_on", false, "is chemistry on?");
  params.addParam<Real>("minimum_porosity", 0.0, "minimum value of porosity (must be positive)");
  params.addParam<Real>("maximum_porosity", 1.0, "maximum value of porosity (must be positive)");
  params.addCoupledVar("mechanical_porosity", 0.0, "Mechanical porosity (as AuxKernel)");
  return params;
}

RedbackTotalPorosityAux::RedbackTotalPorosityAux(const InputParameters & parameters)
  : AuxKernel(parameters),
    _is_mechanics_on(getParam<bool>("is_mechanics_on")),
    _minimum_porosity(getParam<Real>("minimum_porosity")),
    _maximum_porosity(getParam<Real>("maximum_porosity")),
    _delta_porosity_mech(_is_mechanics_on ? coupledValue("mechanical_porosity") : _zero),
    _delta_porosity_chem(getMaterialProperty<Real>("chemical_porosity")),
    _initial_porosity(getMaterialProperty<Real>("initial_porosity")),

    //_has_T(isCoupled("temperature")),
    //_T(_has_T ? coupledValue("temperature") : _zero),

    _mass_removal_rate(_is_mechanics_on ? getMaterialProperty<Real>("mass_removal_rate")
                                        : getZeroMaterialProperty<Real>("mass_removal_rate"))
{
  if (_minimum_porosity<0)
    mooseError("Minimum porosity must be positive (or zero)");
  if (_maximum_porosity>1)
    mooseError("Maximum porosity must be less (of equal) than 1");
}

Real
RedbackTotalPorosityAux::computeValue()
{
  Real total_porosity;
  // Moose::out << "RedbackTotalPorosityAux::computeValue() at _qp" << _qp <<
  // "\n";
  total_porosity = _initial_porosity[_qp] + _delta_porosity_chem[_qp];
  if (_is_mechanics_on)
    total_porosity = _initial_porosity[_qp] +
                     _delta_porosity_chem[_qp] * (1 + _mass_removal_rate[_qp]) +
                     _delta_porosity_mech[_qp];

  total_porosity = fmin(_maximum_porosity, fmax(_minimum_porosity, total_porosity));
  return total_porosity;
}
