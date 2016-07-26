#ifndef RedbackConservativeAdvection_H
#define RedbackConservativeAdvection_H

#include "Kernel.h"

// Forward Declaration
class RedbackConservativeAdvection;


template<>
InputParameters validParams<RedbackConservativeAdvection>();

class RedbackConservativeAdvection : public Kernel
{
public:
  RedbackConservativeAdvection(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  RealVectorValue _velocity;

  const VariableValue & _vel_x;
  const VariableValue & _vel_y;
  const VariableValue & _vel_z;
};

#endif // RedbackConservativeAdvection_H
