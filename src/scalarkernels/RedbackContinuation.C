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

#include "RedbackContinuation.h"

/**
 * This function defines the valid parameters for
 * this Kernel and their default values
 */
template <>
InputParameters
validParams<RedbackContinuation>()
{
  InputParameters params = validParams<ODEKernel>();
  params.addParam<Real>("ds", 1.0, "Continuation increment");
  params.addParam<Real>("ds_old", 1.0, "Old continuation increment");
  params.addParam<Real>("continuation_parameter_old", 0.0, "Old value of continuation parameter");
  params.addParam<Real>("continuation_parameter_older", 0.0, "Older value of continuation parameter");
  params.addCoupledVar("directional_derivative", 0.0, "The directional derivative function");
  return params;
}

RedbackContinuation::RedbackContinuation(const InputParameters & parameters) :
    ODEKernel(parameters),
    _ds_param(getParam<Real>("ds")),
    _ds_old_param(getParam<Real>("ds_old")),
    _continuation_parameter_old_param(getParam<Real>("continuation_parameter_old")),
    _continuation_parameter_older_param(getParam<Real>("continuation_parameter_older")),
    _directional_derivative(coupledScalarValue("directional_derivative"))
{
}

Real
RedbackContinuation::computeQpResidual()
{
  Real lambda_dot_old_param =
    (_continuation_parameter_old_param - _continuation_parameter_older_param) / _ds_old_param;
  return _directional_derivative[ 0 ] + lambda_dot_old_param * (_u[ _i ] - _continuation_parameter_old_param) -
         _ds_param;
}

Real
RedbackContinuation::computeQpJacobian()
{
  // dF/dx
  Real lambda_dot_old_param =
    (_continuation_parameter_old_param - _continuation_parameter_older_param) / _ds_old_param;
  // TODO: compute lambda_dot_old_param only once...
  return lambda_dot_old_param;
}

/*Real
RedbackContinuation::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _y_var)
    return -2.;         // dF/dy
  else
    return 0.;          // everything else
}
*/
