//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef DARCYFLUXBC_H
#define DARCYFLUXBC_H

#include "FluxBC.h"

class DarcyFluxBC;

template <>
InputParameters validParams<DarcyFluxBC>();

/**
 * A FluxBC which is consistent with the boundary terms arising from
 * the Diffusion Kernel. The flux vector in this case is simply
 * grad(u) and the residual contribution is:
 *
 * \f$ F(u) = - \int_{\Gamma} \nabla u * \hat n * \phi d\Gamma \f$
 *
 * In contrast to e.g. VectorNeumannBC, the user does not provide a
 * specified value of the flux when using this class, instead the
 * residual contribution corresponding to the current value of grad(u)
 * is computed and accumulated into the residual vector.
 */
class DarcyFluxBC : public FluxBC
{
public:
  DarcyFluxBC(const InputParameters & parameters);

protected:
  virtual RealGradient computeQpFluxResidual() override;
  virtual RealGradient computeQpFluxJacobian() override;

  const MaterialProperty<Real> & _Le;
  const MaterialProperty<RealVectorValue> & _gravity_term;
};

#endif /* DARCYFLUXBC_H */
