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

#ifndef FUNCTIONPOINTSOURCE_H
#define FUNCTIONPOINTSOURCE_H

// Moose Includes
#include "DiracKernel.h"

// Forward Declarations
class FunctionPointSource;
class Function;

template <>
InputParameters validParams<FunctionPointSource>();

/**
 * TOOD
 */
class FunctionPointSource : public DiracKernel
{
public:
  FunctionPointSource(const InputParameters & parameters);

  virtual void addPoints();
  virtual Real computeQpResidual();

protected:
  Real f();

  // Real _value;
  Function & _func;
  std::vector<Real> _point_param;
  Point _p;
};

#endif // FUNCTIONPOINTSOURCE_H
