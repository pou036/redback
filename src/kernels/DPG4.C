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
// Kernel for the term (\nabla.\tau,{\nabla\tilde{\tau_k}}_k)

#include "DPG4.h"
#include "Assembly.h"

registerMooseObject("RedbackApp", DPG4);

template <>
InputParameters
validParams<DPG4>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredParam<unsigned int>("component",
                                        "An integer corresponding to the direction k"
                                        "the variable this kernel acts in. (0 for x, "
                                        "1 for y, 2 for z)");
  params.addCoupledVar("coupled_variable_k_plus_1", "Component k+1 (mod 3) of vector variable");
  params.addCoupledVar("coupled_variable_k_plus_2", "Component k+2 (mod 3) of vector variable");
  return params;
}

DPG4::DPG4(const InputParameters & parameters):
  Kernel(parameters),
  _is_kp1_coupled(isCoupled("coupled_variable_k_plus_1")),
  _is_kp2_coupled(isCoupled("coupled_variable_k_plus_2")),
  _kp1_var(coupled("coupled_variable_k_plus_1")),
  _kp2_var(coupled("coupled_variable_k_plus_2")),
  _component(getParam<unsigned int>("component")),
  _grad_coupled_var_kp1(coupledGradient("coupled_variable_k_plus_1")),
  _grad_coupled_var_kp2(coupledGradient("coupled_variable_k_plus_2")),
  _grad_phi_kp1(_is_kp1_coupled ? _assembly.gradPhi(*getVar("coupled_variable_k_plus_1",0)) : _grad_phi_zero),
  _grad_phi_kp2(_is_kp2_coupled ? _assembly.gradPhi(*getVar("coupled_variable_k_plus_2",0)) : _grad_phi_zero)
{
}

Real
DPG4::computeQpResidual()
{
  Real div = _grad_u[_qp](_component);
  if (_is_kp1_coupled)
    div += _grad_coupled_var_kp1[_qp]((_component+1) % 3);
  if (_is_kp2_coupled)
    div += _grad_coupled_var_kp2[_qp]((_component+2) % 3);
  return div * _grad_test[_i][_qp](_component);
}

Real
DPG4::computeQpJacobian()
{
  return _grad_phi[_j][_qp](_component) * _grad_test[_i][_qp](_component);
}

Real
DPG4::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _kp1_var)
  {
    return _grad_phi_kp1[_j][_qp]((_component+1) % 3) * _grad_test[_i][_qp](_component);
  }
  else if (jvar == _kp2_var)
  {
    return _grad_phi_kp2[_j][_qp]((_component+2) % 3) * _grad_test[_i][_qp](_component);
  }
  return 0;
}
