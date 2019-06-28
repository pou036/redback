/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*                 (c) 2019 CSIRO                               */
/*               ALL RIGHTS RESERVED                            */
/*                                                              */
/*                Prepared by CSIRO                             */
/*                                                              */
/*        See COPYRIGHT for full restrictions                   */
/****************************************************************/
// BC for the term 0.5*<(abs(b.n)-b.n)*\tilde{u},u-g>
#include "DPGmyBC21.h"
#include "Assembly.h"
#include "Function.h"

registerMooseObject("MooseApp", DPGmyBC21);

template <>
InputParameters
validParams<DPGmyBC21>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  params.addRequiredParam<FunctionName>("function", "Function to impose Dirichlet boundary condition.");
  params.addRequiredCoupledVar("velocity_x", "X component of velocity AuxVariable");
  params.addCoupledVar("velocity_y", 0.0, "Y component of velocity AuxVariable");
  params.addCoupledVar("velocity_z", 0.0, "Z component of velocity AuxVariable");
  params.addClassDescription("Imposes the integrated boundary condition "
                             "$0.5*<|b.n|u,\\tilde{u}>=h$");
  return params;
}

DPGmyBC21::DPGmyBC21(const InputParameters & parameters)
  : IntegratedBC(parameters),
    _is_vel_y_coupled(isCoupled("velocity_y")),
    _is_vel_z_coupled(isCoupled("velocity_z")),
    _vel_x(coupledValue("velocity_x")),
    _vel_y(coupledValue("velocity_y")),
    _vel_z(coupledValue("velocity_z")),
    _coupled_variable(coupledValue("coupled_variable")),
    _k_var(coupled("coupled_variable")),
    _func(getFunction("function")),
    _phi_coupled_variable(_assembly.phi(*getVar("coupled_variable",0)))
{
}

Real
DPGmyBC21::computeQpResidual()
{
  Real g = _func.value(_t, _q_point[_qp]);
  Real vdotn = _vel_x[_qp] * _normals[_qp](0);
  if (_is_vel_y_coupled)
  {
    vdotn += _vel_y[_qp] * _normals[_qp](1);
  }
  if (_is_vel_z_coupled)
  {
    vdotn += _vel_z[_qp] * _normals[_qp](2);
  }
  return 0.5 * (fabs(vdotn) - vdotn) * _test[_i][_qp] * (_coupled_variable[_qp] - g);
}

Real
DPGmyBC21::computeQpJacobian()
{
  return 0;
}

Real
DPGmyBC21::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _k_var)
  {
    Real vdotn = _vel_x[_qp] * _normals[_qp](0);
    if (_is_vel_y_coupled)
    {
      vdotn += _vel_y[_qp] * _normals[_qp](1);
    }
    if (_is_vel_z_coupled)
    {
      vdotn += _vel_z[_qp] * _normals[_qp](2);
    }
    return 0.5 * (fabs(vdotn) - vdotn) * _test[_i][_qp] * _phi_coupled_variable[_j][_qp];
  }
  return 0;
}

