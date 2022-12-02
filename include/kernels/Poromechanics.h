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

#ifndef POROMECHANICS_H
#define POROMECHANICS_H

#include "Kernel.h"

/**
 * Kernel that is calling coupledDot
 */
class Poromechanics : public Kernel
{
public:
  Poromechanics(const InputParameters & parameters);
  static InputParameters validParams();
  virtual ~Poromechanics();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian();

  const VariableGradient & _grad_disp_x;
  const VariableGradient & _grad_disp_y;
  const VariableGradient & _grad_disp_z;

  const VariableGradient & _grad_disp_x_old;
  const VariableGradient & _grad_disp_y_old;
  const VariableGradient & _grad_disp_z_old;

  Real _peclet_number;
  Real _mixture_compressibility;
};

#endif /* POROMECHANICS_H */
