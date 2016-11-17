/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#ifndef LNEFLUIDMASSTIMEDERIVATIVE_H
#define LNEFLUIDMASSTIMEDERIVATIVE_H

#include "TimeDerivative.h"
#include "CoupledTimeDerivative.h"

// Forward Declarations
class LneFluidMassTimeDerivative;

template<>
InputParameters validParams<LneFluidMassTimeDerivative>();

/**
 * This calculates the time derivative for the mass of a fluid
 **/
class LneFluidMassTimeDerivative : public Kernel
{
public:
  LneFluidMassTimeDerivative(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

  const VariableValue & _v_dot;
  const VariableValue & _dv_dot;
  const unsigned int _v_var;
  const VariableValue & _v;  
  
  const VariableValue & _w_dot;
  const VariableValue & _dw_dot;
  const unsigned int _w_var; 
  const VariableValue & _w;     
};

#endif //LNEFLUIDMASSTIMEDERIVATIVE_H
