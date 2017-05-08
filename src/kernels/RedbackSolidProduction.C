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

#include "RedbackSolidProduction.h"

template <>
InputParameters
validParams<RedbackSolidProduction>()
{
  InputParameters params = validParams<Kernel>();
  params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");
  params.addParam<Real>("density_ratio", 1.0, "The density ratio (rho_s/rho_f - 1)");

  params.addCoupledVar("solid_production", 0.0, "The solid production model (as AuxKernel)");

  params.set<bool>("use_displaced_mesh") = true;
  return params;
}

RedbackSolidProduction::RedbackSolidProduction(const InputParameters & parameters) :
    Kernel(parameters),
    _solid_production(coupledValue("solid_production")),
    _time_factor(getParam<Real>("time_factor")),
    _density_ratio(getParam<Real>("density_ratio"))
{
}

RedbackSolidProduction::~RedbackSolidProduction()
{
}

Real
RedbackSolidProduction::computeQpResidual()
{
  Real solid_production_kernel = _density_ratio * _solid_production[ _qp ];
  return _time_factor * _test[ _i ][ _qp ] * solid_production_kernel;
}

Real
RedbackSolidProduction::computeQpJacobian()
{
  return 0; //_time_factor * _test[ _i ][ _qp ] * _solid_production[ _qp ] * _phi[ _j ][ _qp ];
}
