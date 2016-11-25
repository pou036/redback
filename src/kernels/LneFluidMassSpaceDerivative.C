/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#include "LneFluidMassSpaceDerivative.h"

template<>
InputParameters validParams<LneFluidMassSpaceDerivative>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("Time derivative Kernel that acts on a product of three variables");
  params.addRequiredCoupledVar("p", "Coupled variable one-for fluid flow the density");
  params.addRequiredCoupledVar("phi", "Coupled variable two-for fluid flow the porosity");  
  return params;
}

LneFluidMassSpaceDerivative::LneFluidMassSpaceDerivative(const InputParameters & parameters) :
    Kernel(parameters),  
    _grad_v(coupledGradient("p")),
    _v_var(coupled("p")),
    _w_var(coupled("phi")),
    _rho(getMaterialProperty<Real>("fluid_density")),     
    _drhodp(getMaterialProperty<Real>("fluid_density derivative with pressure")),
    _diff(getMaterialProperty<Real>("diffusivity")),     
    _ddiffds(getMaterialProperty<Real>("diffusivity derivative with saturation")),         
    _grav(getMaterialProperty<RealVectorValue>("gravity_term"))                        
{
}

Real
LneFluidMassSpaceDerivative::computeQpResidual()
{
  RealVectorValue dmass = 0.0;
  
  dmass += _rho[_qp]*_diff[_qp]*_grad_v[_qp] - _rho[_qp]*_rho[_qp]*_grav[_qp];
  
  return _grad_test[_i][_qp]*dmass;
}

Real
LneFluidMassSpaceDerivative::computeQpJacobian()
{
  RealVectorValue  QpJ = 0.0;
   
  QpJ += _rho[_qp]*_ddiffds[_qp]*_phi[_j][_qp]*_grad_v[_qp];      
    
  return _grad_test[_i][_qp]*QpJ;
}

Real
LneFluidMassSpaceDerivative::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _v_var) {
    RealVectorValue QoJ = 0.0;	
    
    QoJ += _rho[_qp]*_diff[_qp]*_grad_test[_j][_qp];
    QoJ += _drhodp[_qp]*_phi[_j][_qp]*_diff[_qp]*_grad_v[_qp];
    QoJ +=-2.0*_rho[_qp]*_drhodp[_qp]*_phi[_j][_qp]*_grav[_qp];    

    return _grad_test[_i][_qp] * QoJ;
  } 
  if (jvar == _w_var) {
    RealVectorValue QoJ = 0.0;	

    return _grad_test[_i][_qp] * QoJ;   
  }
  return 0.0;
}


