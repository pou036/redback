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

#include "RedbackWeakPhase.h"

registerMooseObject("RedbackApp", RedbackWeakPhase);

template <>
InputParameters
validParams<RedbackWeakPhase>()
{
  InputParameters params = validParams<Kernel>();
  params.addCoupledVar("temperature", 0.0, "Temperature variable.");
  params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");

  params.set<bool>("use_displaced_mesh") = true;
  return params;
}

RedbackWeakPhase::RedbackWeakPhase(const InputParameters & parameters)
  : Kernel(parameters),
    _poromech_kernel(getMaterialProperty<Real>("poromechanics_kernel")),
    _poromech_jac(getMaterialProperty<Real>("poromechanics_jacobian")),
    _temp_var(coupled("temperature")),
    _time_factor(getParam<Real>("time_factor"))
{
}

RedbackWeakPhase::~RedbackWeakPhase() {}

Real
RedbackWeakPhase::computeQpResidual()
{
  return _time_factor * _poromech_kernel[_qp] *(1-_u[_qp])* _test[_i][_qp];
  // TODO: add note in doco to tell users not to turn on term if compress=0
  // TODO: add check compress > 0
}

Real
RedbackWeakPhase::computeQpJacobian()
{
  return -_time_factor * _poromech_kernel[_qp] * _test[_i][_qp]*_phi[_j][_qp];
}

Real
RedbackWeakPhase::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _temp_var)
  {
    return _time_factor * _poromech_kernel[_qp] * _poromech_jac[_qp] * _phi[_j][_qp]*(1-_u[_qp]) *
           _test[_i][_qp];
  }
  return 0;
}
