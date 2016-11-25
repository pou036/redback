/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#ifndef LNEFLUIDPOREPRESSURE_H
#define LNEFLUIDPOREPRESSURE_H

#include "Kernel.h"

// Forward Declarations
class LneFluidPorePressure;

template<>
InputParameters validParams<LneFluidPorePressure>();

/**
 * This calculates the time derivative for the mass of a fluid
 **/
class LneFluidPorePressure : public Kernel
{
public:
  LneFluidPorePressure(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

  const unsigned int _v_var;
  const VariableValue & _v;    

  Real _S0, _pc0, _alpha;

};

#endif //LNEFLUIDPOREPRESSURE_H
