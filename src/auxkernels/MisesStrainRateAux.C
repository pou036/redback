#include "MisesStrainRateAux.h"

template<>
InputParameters validParams<MisesStrainRateAux>()
{
  InputParameters params = validParams<AuxKernel>();
  return params;
}

MisesStrainRateAux::MisesStrainRateAux(const std::string & name, InputParameters parameters) :
    AuxKernel(name, parameters),
    _mises_strain_rate(getMaterialProperty<Real>("mises_strain_rate"))
{
}

Real
MisesStrainRateAux::computeValue()
{
  return _mises_strain_rate[_qp];
}
