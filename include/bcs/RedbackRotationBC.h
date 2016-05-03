/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef REDBACKROTATIONBC_H
#define REDBACKROTATIONBC_H

#include "NodalBC.h"
#include "MaterialPropertyInterface.h"


//Forward Declarations
class RedbackRotationBC;

template<>
InputParameters validParams<RedbackRotationBC>();

class RedbackRotationBC : public NodalBC,
public MaterialPropertyInterface

{
public:
  RedbackRotationBC(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();

  const VariableValue & _disp_x;
  const VariableValue & _disp_y;
  const VariableValue & _disp_z;

  const VariableGradient & _grad_ux;
  const VariableGradient & _grad_uy;
  const VariableGradient & _grad_uz;

  Real _comp_1;
  Real _comp_2;
  Real _scalar;

};

#endif //RedbackRotationBC_H
