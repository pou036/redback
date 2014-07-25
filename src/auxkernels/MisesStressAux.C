#include "MisesStressAux.h"

template<>
InputParameters validParams<MisesStressAux>()
{
  InputParameters params = validParams<AuxKernel>();
  return params;
}

MisesStressAux::MisesStressAux(const std::string & name, InputParameters parameters) :
    AuxKernel(name, parameters),
    _equivalent_stress(getMaterialProperty<Real>("equivalent_stress"))
{
}

Real
MisesStressAux::computeValue()
{
  return _equivalent_stress[_qp];
}
