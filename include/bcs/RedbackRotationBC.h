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

//Forward Declarations
class RedbackRotationBC;

template<>
InputParameters validParams<RedbackRotationBC>();

/**
 * Implements a simple coupled boundary condition where u=alpha*grad(v) on the boundary.
 */
class RedbackRotationBC : public NodalBC
{
public:
  RedbackRotationBC(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  //virtual Real computeQpOffDiagJacobian(unsigned int jvar);
 //VariableGradient & _some_var_1;
 //VariableGradient & _some_var_2;
 //double _d1;
 //double _d2;
  //const MaterialProperty<Real> _test;// _antisymmetric_strain;
  //const MaterialProperty<Real> & _test;
  VariableValue & _grad_ux;

  /// The id of the coupled variable
  //unsigned int _v_num;
};

#endif //RedbackRotationBC_H
