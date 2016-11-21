/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#ifndef LNEFLUIDMASSSPACEDERIVATIVE_H
#define LNEFLUIDMASSSPACEDERIVATIVE_H

#include "Kernel.h"

// Forward Declarations
class LneFluidMassSpaceDerivative;

template<>
InputParameters validParams<LneFluidMassSpaceDerivative>();

/**
 * This calculates the time derivative for the mass of a fluid
 **/
class LneFluidMassSpaceDerivative : public Kernel
{
public:
  LneFluidMassSpaceDerivative(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

  const VariableGradient & _grad_v;
//  const VariableValue & _dv_dot;
  const unsigned int _v_var;
//  const VariableValue & _v;  
  
//  const VariableValue & _w_dot;
//  const VariableValue & _dw_dot;
  const unsigned int _w_var; 
//  const VariableValue & _w;  

  const MaterialProperty<Real>& _rho;  
  const MaterialProperty<Real>& _drhodp; 
  
  const MaterialProperty<Real>& _diff;  
  const MaterialProperty<Real>& _ddiffds;    
};

#endif //LNEFLUIDMASSTIMEDERIVATIVE_H
