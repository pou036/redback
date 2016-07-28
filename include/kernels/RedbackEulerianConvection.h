/*
 * RedbackEulerianConvection.h
 *
 *  Created on: Jul 28, 2016
 *      Author: stuartwalsh
 */

#ifndef INCLUDE_KERNELS_REDBACKEULERIANCONVECTION_H_
#define INCLUDE_KERNELS_REDBACKEULERIANCONVECTION_H_


#include "Kernel.h"

// Forward Declarations
class RedbackEulerianConvection;

template<>
InputParameters validParams<RedbackEulerianConvection>();

/**
 * This class computes momentum equation residual and Jacobian
 * contributions for the incompressible Navier-Stokes momentum
 * equation.
 */
class RedbackEulerianConvection : public Kernel
{
public:
  RedbackEulerianConvection(const InputParameters & parameters);

  virtual ~RedbackEulerianConvection(){}

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned jvar);

  // Coupled variables
  const VariableValue & _u_vel;
  const VariableValue & _v_vel;
  const VariableValue & _w_vel;

  const VariableValue & _rho;

  // Gradients
  const VariableGradient & _grad_u_vel;
  const VariableGradient & _grad_v_vel;
  const VariableGradient & _grad_w_vel;

  // Variable numberings
  unsigned _u_vel_var_number;
  unsigned _v_vel_var_number;
  unsigned _w_vel_var_number;

  // Parameters
  unsigned _component;
};



#endif /* INCLUDE_KERNELS_REDBACKEULERIANCONVECTION_H_ */
