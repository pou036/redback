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

#include "PressureNeumannBC.h"

template <>
InputParameters
validParams<PressureNeumannBC>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredCoupledVar("coupled_var", "The variable whose value we are to match.");
  params.addRequiredParam<unsigned int>("component",
                                        "An integer corresponding to the direction the variable "
                                        "this BC acts in. (0 for x, 1 for y, 2 for z)");
  params.addParam<Real>("scale_factor", 1.0, "rescaling factor");
  return params;
}

PressureNeumannBC::PressureNeumannBC(const InputParameters & parameters)
  : IntegratedBC(parameters),
    _var(coupledValue("coupled_var")),
    _var_num(coupled("coupled_var")),
    _component(getParam<unsigned int>("component")),
    _scale_factor(getParam<Real>("scale_factor"))
{
}

Real
PressureNeumannBC::computeQpResidual()
{
  return -_var[_qp] * _normals[_qp](_component) * _test[_i][_qp] * _scale_factor;
}

Real
PressureNeumannBC::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _var_num)
    return -_phi[_j][_qp] * _normals[_qp](_component) * _test[_i][_qp] * _scale_factor;

  else
    return 0.;
}
