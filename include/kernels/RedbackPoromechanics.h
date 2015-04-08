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

#ifndef REDBACKPOROMECHANICS_H
#define REDBACKPOROMECHANICS_H

#include "Kernel.h"

class RedbackPoromechanics;

template<>
InputParameters validParams<RedbackPoromechanics>();

/**
 * Kernel that is calling coupledDot
 */
class RedbackPoromechanics : public Kernel
{
public:
  RedbackPoromechanics(const std::string & name, InputParameters parameters);
  virtual ~RedbackPoromechanics();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  MaterialProperty<Real> & _volumetric_strain_rate;
  MaterialProperty<Real> & _mixture_compressibility;
  MaterialProperty<Real> & _poromech_jac;

  unsigned int _temp_var; // variable number of the temperature variable
};


#endif /* REDBACKPOROMECHANICS_H */
