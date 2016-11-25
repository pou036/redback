/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#include "LneFluidPorePressure.h"

template<>
InputParameters validParams<LneFluidPorePressure>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("Kernel for the pore pressure as a function of saturation");
  params.addRequiredCoupledVar("sat", "Coupled variable-for fluid degree of saturation");
  params.addParam<Real>("residual saturation", 0.1, "Residual saturation");
  params.addParam<Real>("max capillary pressure",-1.0, "max capillary pressure");  
  params.addParam<Real>("BrooksCorey parameter",5.0, "BrooksCorey exponent");    
  return params;
}

LneFluidPorePressure::LneFluidPorePressure(const InputParameters & parameters) :
    Kernel(parameters),  

    _v_var(coupled("sat")),
    _v(coupledValue("sat")), 
    
    _S0(getParam<Real>("residual saturation")),
    _pc0(getParam<Real>("max capillary pressure")),
    _alpha(getParam<Real>("BrooksCorey parameter"))                       
{
}

Real
LneFluidPorePressure::computeQpResidual()
{
  Real dmass = 0.0;
  Real rS = 0.0;
// Getting the value of saturation to use  
  rS = std::min(1.0,_v[_qp]);
  rS = std::max(rS,_S0);
  
  dmass += _u[_qp];
  dmass += -_pc0*pow(rS,-1/_alpha);
  
  
  return _test[_i][_qp]*dmass;
}

Real
LneFluidPorePressure::computeQpJacobian()
{
  Real  QpJ = 0.0;
   
  QpJ += _phi[_j][_qp];      
    
  return _test[_i][_qp]*QpJ;
}

Real
LneFluidPorePressure::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _v_var) {
    Real QoJ = 0.0;	
    Real rS = 0.0;    
//  Getting the value of saturation to use  
    rS = std::min(1.0,_v[_qp]);
    rS = std::max(rS,_S0);    
    
    QoJ += -(-1.0/_alpha)*_pc0*pow(rS,-1.0/_alpha-1.0)*_phi[_j][_qp];

    if (_v[_qp]>=1.01) {
		QoJ = 0.0;
    }	
    if (_v[_qp]<=_S0) {
		QoJ = 0.0;
    }      

    return _test[_i][_qp] * QoJ;
  } 
  return 0.0;
}


