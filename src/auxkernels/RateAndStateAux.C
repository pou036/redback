/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#include "RateAndStateAux.h"

registerMooseObject("RedbackApp", RateAndStateAux);

InputParameters
RateAndStateAux::validParams()
{
  InputParameters params = AuxKernel::validParams();
  params.addClassDescription("Compute fault slippage according to rate and state law");
  params.addRequiredParam<PostprocessorName>("mises_stress", "Von Mises stress postprocessor.");
  params.addRequiredParam<PostprocessorName>("mises_stress_old", "Von Mises stress postprocessor.");
  params.addRequiredParam<Real>("activation_mises", "Value above which the fault is reactivated.");
  params.addRequiredParam<Real>("deactivation_mises", "Value under which the fault is reactivated.");
  params.addRequiredParam<Real>("creeping_vel", "Velocity of the creeping fault.");
  params.addRequiredParam<Real>("vel_0", "Dynamic velocity.");
  params.addRequiredParam<Real>("mises_0", "Dynamic mises.");
  params.addRequiredParam<Real>("Ar", "Arrhenius number.");
  return params;
}

RateAndStateAux::RateAndStateAux(const InputParameters & parameters)
  : AuxKernel(parameters),
    _mises(getPostprocessorValue("mises_stress")),
    _mises_old(getPostprocessorValue("mises_stress_old")),
    _activation_mises(getParam<Real>("activation_mises")),
    _deactivation_mises(getParam<Real>("deactivation_mises")),
    _creeping_vel(getParam<Real>("creeping_vel")),
    _vel_0(getParam<Real>("vel_0")),
    _mises_0(getParam<Real>("mises_0")),
    _Ar(getParam<Real>("Ar")),
    _u_old(uOld())
{
  _activation = false;
}

Real
RateAndStateAux::computeValue()
{
  if (_mises>_activation_mises && !_activation)
    _activation = true;
  else if (_mises<_deactivation_mises && _activation)
    _activation = false;

  if (!_activation)
    return _u_old[_qp] + _creeping_vel * _dt;

  //Rate and state
  return _u_old[_qp] + _vel_0/exp(_Ar*_mises_0)*exp(_Ar*_mises) * _dt;
  //Slip-Weakening
  //return 81.48 - 62.85 * _mises;
  //return _u_old[_qp] + 62.85 * abs(_mises-_mises_old);
}
