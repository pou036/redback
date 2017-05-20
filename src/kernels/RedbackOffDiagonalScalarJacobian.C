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

#include "RedbackOffDiagonalScalarJacobian.h"

template <>
InputParameters
validParams<RedbackOffDiagonalScalarJacobian>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("scalar_variable", "Scalar variable coupled into this kernel");
  params.addCoupledVar("normal_variable", "Normal variable Z coupled into this kernel");
  return params;
}

RedbackOffDiagonalScalarJacobian::RedbackOffDiagonalScalarJacobian(const InputParameters & parameters) :
    Kernel(parameters),
    _sc_var(coupledScalar("scalar_variable")),
    _sc(coupledScalarValue("scalar_variable")),
    _z_var(isCoupled("normal_variable")?coupled("normal_variable"):0),
    _z(isCoupled("normal_variable")?coupledValue("normal_variable"):_zero)
{
  std::cout << "RedbackOffDiagonalScalarJacobian, _sc_var=" << _sc_var << std::endl;
  //std::cout << "RedbackOffDiagonalScalarJacobian, _z_var=" << _z_var << std::endl;
}

RedbackOffDiagonalScalarJacobian::~RedbackOffDiagonalScalarJacobian()
{
}

Real
RedbackOffDiagonalScalarJacobian::computeQpResidual()
{
  return 0;
}

Real
RedbackOffDiagonalScalarJacobian::computeQpJacobian()
{
  return 0;
}

Real
RedbackOffDiagonalScalarJacobian::computeQpOffDiagJacobian(unsigned int jvar)
{
  // This code is only called for the (normal) variables
  //std::string name = _sys.system().variable_name(jvar); => doens't work :-(
  Real x = _u[_qp];
  Real y = _sc[_i];
  std::cout << "RedbackOffDiagonalScalarJacobian::computeQpOffDiagJacobian, jvar=" << jvar <<", x=" << x << ", y=" << y <<std::endl;
  return 0;
}
