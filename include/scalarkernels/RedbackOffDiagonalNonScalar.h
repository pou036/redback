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

#ifndef REDBACKOFFDIAGONALNONSCALAR_H
#define REDBACKOFFDIAGONALNONSCALAR_H

#include "ODEKernel.h"

class RedbackOffDiagonalNonScalar;

template <>
InputParameters validParams<RedbackOffDiagonalNonScalar>();

class RedbackOffDiagonalNonScalar : public ODEKernel
{
public:
  RedbackOffDiagonalNonScalar(const InputParameters & parameters);

protected:
  Real _ds_old_param;
  const VariableValue & _x;
  unsigned int _x_var;
  const VariableValue & _x_old;
  const VariableValue & _x_older;

  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);
};

#endif /* REDBACKOFFDIAGONALNONSCALAR_H */
