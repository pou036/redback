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

#include "RedbackSandProductionAux.h"

template <>
InputParameters
validParams<RedbackSandProductionAux>()
{
  InputParameters params = validParams<AuxKernel>();
    params.addCoupledVar("total_porosity", 0.0, "The total porosity (as AuxKernel)");
    params.addParam<Real>("peak_strain", 0.0, "The plastic peak shear strain");
    params.addParam<Real>("lambda_1", 1.0, "The first sand production coefficient (Papamichos et al 2001)");
    params.addParam<Real>("lambda_2", 1.0, "The second sand production coefficient (Papamichos et al 2001)");

  return params;
}

RedbackSandProductionAux::RedbackSandProductionAux(const InputParameters & parameters) :
    AuxKernel(parameters),
    _total_porosity(coupledValue("total_porosity")),

    _peak_strain(getParam<Real>("peak_strain")),
    _lambda_1(getParam<Real>("lambda_1")),
    _lambda_2(getParam<Real>("lambda_2")),

    _sand_production_rate(getMaterialProperty<Real>("sand_production_rate")),
    _eqv_plastic_strain(getMaterialProperty<Real>("eqv_plastic_strain"))
{
}

Real
RedbackSandProductionAux::computeValue()
{
  Real mass_production_rate, lambda;

  if (_eqv_plastic_strain[_qp] < _peak_strain)
       lambda = 0;
  else if (_eqv_plastic_strain[_qp] > _peak_strain + _lambda_2/_lambda_1)
       lambda = _lambda_2;
  else lambda = _lambda_1 * (_eqv_plastic_strain[_qp] - _peak_strain);

  mass_production_rate = lambda*_sand_production_rate[_qp];
  return mass_production_rate;
}
