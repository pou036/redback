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

#include "RedbackOffDiagonalNonScalar.h"

/**
 * This function defines the valid parameters for
 * this Kernel and their default values
 */
template <>
InputParameters
validParams<RedbackOffDiagonalNonScalar>()
{
  InputParameters params = validParams<ODEKernel>();
  params.addParam<Real>("ds_old", 1.0, "Old continuation increment");
  params.addRequiredCoupledVar("x", "The (non scalar) variable to couple");
  params.addRequiredCoupledVar("x_old", "The old version of the (non scalar) variable to couple");
  params.addRequiredCoupledVar("x_older", "The older version of the (non scalar) variable to couple");
  return params;
}

RedbackOffDiagonalNonScalar::RedbackOffDiagonalNonScalar(const InputParameters & parameters) :
    ODEKernel(parameters),
    _ds_old_param(getParam<Real>("ds_old")),
    _x(coupledValue("x")),
    _x_var(coupled("x")),
    _x_old(coupledValue("x_old")),
    _x_older(coupledValue("x_older"))
{
}

Real
RedbackOffDiagonalNonScalar::computeQpResidual()
{
  return 0.;
}

Real
RedbackOffDiagonalNonScalar::computeQpJacobian()
{
  return 0.;
}

Real
RedbackOffDiagonalNonScalar::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _x_var)
  {
    //std::cout << "RedbackOffDiagonalNonScalar::computeQpOffDiagJacobian (jvar == _non_scalar_variable_var)" << std::endl;
    //std::cout << "_non_scalar_variable[_qp] = " << _non_scalar_variable[_qp] << std::endl;
    //std::cout << "_u[_i] = " << _u[_i] << std::endl;
    return (_x_old[_qp] - _x_older[_qp])/_ds_old_param;
  }
  else
  {
    //std::cout << "RedbackOffDiagonalNonScalar::computeQpOffDiagJacobian (jvar == else)" << std::endl;
    return 0.;
  }
}
