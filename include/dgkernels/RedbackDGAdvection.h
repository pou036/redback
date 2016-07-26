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


/////

#include "IntegratedBC.h"

class RedbackDGAdvectionBC : public IntegratedBC
{
public:

  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
	RedbackDGAdvectionBC(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();

private:
  /**
   * Multiplier on the boundary.
   */
  RealVectorValue _velocity;

};

#endif //RedbackDGAdvection_H
