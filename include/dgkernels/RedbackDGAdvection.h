#ifndef RedbackDGAdvection_H
#define RedbackDGAdvection_H

#include "DGKernel.h"

class RedbackDGAdvection;

template<>
InputParameters validParams<RedbackDGAdvection>();

class RedbackDGAdvection : public DGKernel
{
public:
  RedbackDGAdvection(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type);
  virtual Real computeQpJacobian(Moose::DGJacobianType type);

  RealVectorValue _velocity;
};

#endif //RedbackDGAdvection_H
