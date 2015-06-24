#include "RedbackThermalConvection.h"

template<>
InputParameters validParams<RedbackThermalConvection>()
{
  InputParameters params = validParams<Kernel>();
  params.addCoupledVar("pore_pres", "Pore pressure variable.");
  return params;
}

RedbackThermalConvection::RedbackThermalConvection(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _mixture_convective_energy(getMaterialProperty<RealVectorValue>("mixture_convective_energy")),
  //_mixture_convective_energy_jac(getMaterialProperty<Real>("mixture_convective_energy_jacobian")),
  //_mixture_convective_energy_off_jac(getMaterialProperty<Real>("mixture_convective_energy_off_jacobian")),
  _pore_pres_var(coupled("pore_pres"))
{}


Real
RedbackThermalConvection::computeQpResidual()
{
  return _test[_i][_qp] * (_mixture_convective_energy[_qp] * _grad_u[_qp]);
}

Real
RedbackThermalConvection::computeQpJacobian()
{
  return 0;
  //return _test[_i][_qp] * _mixture_convective_energy[_qp] * _grad_phi[_j][_qp]
  //  + _test[_i][_qp] * _mixture_convective_energy_jac[_qp] * _phi[_j][_qp];
}

Real
RedbackThermalConvection::computeQpOffDiagJacobian(unsigned int jvar)
{
  /*if (jvar == _pore_pres_var)
  {
    return _test[_i][_qp] * _mixture_convective_energy_off_jac[_qp] * _phi[_j][_qp];
  }*/
  return 0;
}
