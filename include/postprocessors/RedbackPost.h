/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef REDBACKPOST_H
#define REDBACKPOST_H

#include "PointValue.h"

//Forward Declarations
class RedbackPost;

template<>
InputParameters validParams<RedbackPost>();

class RedbackPost : public PointValue
{
public:
  RedbackPost(const std::string & name, InputParameters parameters);
  virtual ~RedbackPost();
  virtual Real variableValue();

protected:
  MaterialProperty<Real> & _equivalent_stress;
  MaterialProperty<Real> & _mises_strain;
  MaterialProperty<Real> & _mises_strain_rate;
  MaterialProperty<Real> & _mechanical_dissipation;
};

#endif // REDBACKPOST_H
