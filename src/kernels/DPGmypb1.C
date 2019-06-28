/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2018 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/
// Kernel for the term ({\tau-\kappa\nabla u + b u}_k,\tilde{\tau}_k)

#include "DPGmypb1.h"
#include "Assembly.h"

registerMooseObject("RedbackApp", DPGmypb1);

template <>
InputParameters
validParams<DPGmypb1>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("coupled_variable_scalar", "Coupled scalar variable");
  params.addRequiredCoupledVar("coupled_variable_vector_k", "Component k of vector variable");
  params.addRequiredParam<unsigned int>("component",
                                        "An integer corresponding to the direction "
                                        "the variable this kernel acts in. (0 for x, "
                                        "1 for y, 2 for z)");
  return params;
}

DPGmypb1::DPGmypb1(const InputParameters & parameters):
  Kernel(parameters),
  _scalar_var(coupledValue("coupled_variable_scalar")),
  _coupled_vector_k(coupledValue("coupled_variable_vector_k")),
  _grad_scalar_var(coupledGradient("coupled_variable_scalar")),
  _coupled_var(coupled("coupled_variable_scalar")),
  _k_var(coupled("coupled_variable_vector_k")),
  _phi_k(_assembly.phi(*getVar("coupled_variable_vector_k",0))),
  _phi_var(_assembly.phi(*getVar("coupled_variable_scalar",0))),
  _grad_phi_var(_assembly.gradPhi(*getVar("coupled_variable_scalar",0))),
  _component(getParam<unsigned int>("component")),
  _vel_x(getMaterialProperty<Real>("velocity_x")),
  _vel_y(getMaterialProperty<Real>("velocity_y")),
  _vel_z(getMaterialProperty<Real>("velocity_z")),
  _kappa(getMaterialProperty<Real>("kappa"))
{
  if (_component > 2)
    mooseError("Invalid 'component' (",_component,") in DPGmypb1");
}

Real
DPGmypb1::computeQpResidual()
{
  Real vel_k; // velocity component needed
  switch(_component) {
    case 0 : vel_k = _vel_x[_qp]; break;
    case 1 : vel_k = _vel_y[_qp]; break;
    case 2 : vel_k = _vel_z[_qp]; break;
  }
  return _test[_i][_qp] * (_coupled_vector_k[_qp]
    -_kappa[_qp]*_grad_scalar_var[_qp](_component)
    + vel_k*_scalar_var[_qp]);
}

Real
DPGmypb1::computeQpJacobian()
{
  return 0;
}


Real
DPGmypb1::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _k_var)
  {
    return _phi_k[_j][_qp] * _test[_i][_qp];
  }
  else if (jvar == _coupled_var)
  {
    Real vel_k; // velocity component needed
    switch(_component) {
      case 0 : vel_k = _vel_x[_qp]; break;
      case 1 : vel_k = _vel_y[_qp]; break;
      case 2 : vel_k = _vel_z[_qp]; break;
    }
    return (-_kappa[_qp]*_grad_phi_var[_j][_qp](_component)
      + vel_k*_phi_var[_j][_qp]) * _test[_i][_qp];
  }
  return 0;
}
