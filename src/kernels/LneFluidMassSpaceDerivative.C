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
  params.addRequiredCoupledVar("rho", "Coupled variable one-for fluid flow the density");
  params.addRequiredCoupledVar("phi", "Coupled variable two-for fluid flow the porosity");  
  return params;
}

LneFluidMassSpaceDerivative::LneFluidMassSpaceDerivative(const InputParameters & parameters) :
    Kernel(parameters),  
    _grad_v(coupledGradient("rho")),
    _v_var(coupled("rho")),
    _w_var(coupled("phi"))            
{
}

Real
LneFluidMassSpaceDerivative::computeQpResidual()
{
  RealVectorValue dmass = 0.0;
  dmass += 0.01*_grad_u[_qp];
  return _grad_test[_i][_qp]*dmass;
}

Real
LneFluidMassSpaceDerivative::computeQpJacobian()
{
  RealVectorValue  QpJ = 0.0;
     
  return _grad_test[_i][_qp]*QpJ;
}

Real
LneFluidMassSpaceDerivative::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _v_var) {
    RealVectorValue QoJ = 0.0;	

    return _grad_test[_i][_qp] * QoJ;
  } 
  if (jvar == _w_var) {
    RealVectorValue QoJ = 0.0;	

    return _grad_test[_i][_qp] * QoJ;   
  }
  return 0.0;
}


