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

#ifndef REDBACKRANDOMFUNCTION
#define REDBACKRANDOMFUNCTION

#include "Function.h"

// Forward Declarations
class RedbackRandomFunction;

template <>
InputParameters validParams<RedbackRandomFunction>();

/**
 * Defines random function
 */
class RedbackRandomFunction : public Function
{
public:
  RedbackRandomFunction(const InputParameters & parameters);

  virtual Real value(Real t, const Point & p);

protected:
  Real _min;
  Real _max;
  Real _range;
};

#endif // REDBACKRANDOMFUNCTION
