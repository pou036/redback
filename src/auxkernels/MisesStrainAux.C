#include "MisesStrainAux.h"

template<>
InputParameters validParams<MisesStrainAux>()
{
  InputParameters params = validParams<AuxKernel>();
  return params;
}

MisesStrainAux::MisesStrainAux(const std::string & name, InputParameters parameters) :
    AuxKernel(name, parameters),
    _mises_strain(getMaterialProperty<Real>("mises_strain"))
{
}

Real
MisesStrainAux::computeValue()
{
  return _mises_strain[_qp];
}
