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
  params.addRequiredCoupledVar("non_scalar_variable", "The (non scalar) variable to couple");
  return params;
}

RedbackOffDiagonalNonScalar::RedbackOffDiagonalNonScalar(const InputParameters & parameters) :
    ODEKernel(parameters),
    _non_scalar_variable(coupledValue("non_scalar_variable")),
    _non_scalar_variable_var(coupled("non_scalar_variable"))
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
  if (jvar == _non_scalar_variable_var)
    return 0.;
  else
    return 0.;
}
