#include "RedbackTotalPorosityAux.h"

template<>
InputParameters validParams<RedbackTotalPorosityAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addParam<bool>("is_mechanics_on", false, "is mechanics on?");
  //params.addParam<bool>("is_chemistry_on", false, "is chemistry on?");
  return params;
}

RedbackTotalPorosityAux::RedbackTotalPorosityAux(const std::string & name, InputParameters parameters) :
    AuxKernel( name, parameters ),
    _is_mechanics_on(getParam<bool>("is_mechanics_on")),
    // TODO: would be nicer to initialise _delta_porosity_mech with NULL/_zero if not _is_mechanics_on. I just don't know how to do that...
    _delta_porosity_mech(_is_mechanics_on ? getMaterialProperty<Real>("delta_porosity_mech"): getMaterialProperty<Real>("initial_porosity")),
    //_delta_porosity_mech(getMaterialProperty<Real>("mechanical_porosity")),
    //_is_chemistry_on(getParam<bool>("is_chemistry_on")),
    //_delta_porosity_chem(_is_chemistry_on ? getMaterialProperty<Real>("delta_porosity_chem"): getDefaultMaterialProperty<Real>("delta_porosity_mech")),
    _delta_porosity_chem(getMaterialProperty<Real>("chemical_porosity")),
    _initial_porosity(getMaterialProperty<Real>("initial_porosity"))
{
}

Real
RedbackTotalPorosityAux::computeValue()
{
  Real total_porosity;
  //Moose::out << "RedbackTotalPorosityAux::computeValue() at _qp" << _qp << "\n";
  total_porosity = _initial_porosity[_qp] + _delta_porosity_chem[_qp];
  if (_is_mechanics_on)
    total_porosity = total_porosity + _delta_porosity_mech[_qp];
  return total_porosity;
}
