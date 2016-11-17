/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#include "LneFluidMassTimeDerivative.h"

template<>
InputParameters validParams<LneFluidMassTimeDerivative>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("Time derivative Kernel that acts on a product of three variables");
  params.addRequiredCoupledVar("rho", "Coupled variable one-for fluid flow the density");
  params.addRequiredCoupledVar("phi", "Coupled variable two-for fluid flow the porosity");  
  return params;
}

LneFluidMassTimeDerivative::LneFluidMassTimeDerivative(const InputParameters & parameters) :
    Kernel(parameters),  
    _v_dot(coupledDot("rho")),
    _dv_dot(coupledDotDu("rho")),
    _v_var(coupled("rho")),
    _v(coupledValue("rho")),   
    _w_dot(coupledDot("phi")),
    _dw_dot(coupledDotDu("phi")),
    _w_var(coupled("phi")),   
    _w(coupledValue("phi"))     
{
}

Real
LneFluidMassTimeDerivative::computeQpResidual()
{
  Real dmass = 0.0;
  dmass += _v[_qp]     *_w[_qp]     * _u_dot[_qp];
  dmass += _v_dot[_qp] *_w[_qp]     * _u[_qp];
  dmass += _v[_qp]     *_w_dot[_qp] * _u[_qp];  
  return _test[_i][_qp]*dmass;
}

Real
LneFluidMassTimeDerivative::computeQpJacobian()
{
  Real QpJ = 0.0;
  QpJ += _v[_qp]     *_w[_qp]*_phi[_j][_qp]*_du_dot_du[_qp];  
  QpJ += _v_dot[_qp] *_w[_qp]     *_phi[_j][_qp];      
  QpJ += _v[_qp]     *_w_dot[_qp] *_phi[_j][_qp];      
  
  return _test[_i][_qp]*QpJ;
}

Real
LneFluidMassTimeDerivative::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _v_var) {
    Real QoJ = 0.0;	
    QoJ += _phi[_j][_qp] *_w[_qp]     * _u_dot[_qp];
    QoJ += _phi[_j][_qp] * _dv_dot[_qp]*_w[_qp]     * _u[_qp];        
    QoJ += _phi[_j][_qp] *_w_dot[_qp] * _u[_qp];
    return _test[_i][_qp] * QoJ;
  } 
  if (jvar == _w_var) {
    Real QoJ = 0.0;	
    QoJ += _phi[_j][_qp] *_v[_qp]     * _u_dot[_qp];
    QoJ += _phi[_j][_qp] * _dw_dot[_qp]*_v[_qp]     * _u[_qp];        
    QoJ += _phi[_j][_qp] *_v_dot[_qp] * _u[_qp];
    return _test[_i][_qp] * QoJ;   
  }
  return 0.0;
}


