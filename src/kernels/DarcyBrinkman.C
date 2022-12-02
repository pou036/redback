/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "DarcyBrinkman.h"

registerMooseObject("RedbackApp", DarcyBrinkman);

InputParameters
<<<<<<< HEAD:src/kernels/DarcyBrinkman.C
validParams<DarcyBrinkman>()
{
  InputParameters params = validParams<Kernel>();
  params.addCoupledVar("permeability", 1.0, "the permeability of the solid phase");
=======
DarcyFluxBC::validParams()
{
  InputParameters params = FluxBC::validParams();
  params.addClassDescription(
      "Computes a boundary residual contribution consistent with the Diffusion Kernel. "
      "Does not impose a boundary condition; instead computes the boundary "
      "contribution corresponding to the current value of grad(u) and accumulates "
      "it in the residual vector.");
>>>>>>> master:src/bcs/DarcyFluxBC.C
  return params;
}

DarcyBrinkman::DarcyBrinkman(const InputParameters & parameters)
  : Kernel(parameters), _perm(coupledValue("permeability")), _mu(getMaterialProperty<Real>("mu"))
{
}

Real
DarcyBrinkman::computeQpResidual()
{
  return _mu[_qp] / _perm[_qp] * _u[_qp] * _test[_i][_qp];
}

Real
DarcyBrinkman::computeQpJacobian()
{
  return _mu[_qp] / _perm[_qp] * _phi[_j][_qp] * _test[_i][_qp];
}
