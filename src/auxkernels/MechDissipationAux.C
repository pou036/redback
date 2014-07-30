#include "MechDissipationAux.h"

template<>
InputParameters validParams<MechDissipationAux>()
{
  InputParameters params = validParams<AuxKernel>();
  return params;
}

MechDissipationAux::MechDissipationAux(const std::string & name, InputParameters parameters) :
    AuxKernel(name, parameters),
    _mechanical_dissipation(getMaterialProperty<Real>("mechanical_dissipation"))
{
}

Real
MechDissipationAux::computeValue()
{
  return _mechanical_dissipation[_qp];
}
