/*
 * RedbackEulerianMomentumTimeDerivative.h
 *
 *  Created on: Jul 28, 2016
 *      Author: stuartwalsh
 */

#ifndef INCLUDE_KERNELS_REDBACKEULERIANMOMENTUMTIMEDERIVATIVE_H_
#define INCLUDE_KERNELS_REDBACKEULERIANMOMENTUMTIMEDERIVATIVE_H_


#include "TimeDerivative.h"

// Forward Declarations
class RedbackEulerianMomentumTimeDerivative;

template<>
InputParameters validParams<RedbackEulerianMomentumTimeDerivative>();

/**
 * This class computes the time derivative for the Redback Eulerian solver
 */
class RedbackEulerianMomentumTimeDerivative : public TimeDerivative
{
public:
	RedbackEulerianMomentumTimeDerivative(const InputParameters & parameters);

  virtual ~RedbackEulerianMomentumTimeDerivative(){}

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned jvar);

  // Parameters


  const VariableValue & _rho;
  //Real _rho;
};




#endif /* INCLUDE_KERNELS_REDBACKEULERIANMOMENTUMTIMEDERIVATIVE_H_ */
