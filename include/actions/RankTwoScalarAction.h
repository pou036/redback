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

#ifndef RANKTWOSCALARACTION_H
#define RANKTWOSCALARACTION_H

#include "Action.h"

class RankTwoScalarAction : public Action
{
public:
  RankTwoScalarAction(InputParameters params);

  MultiMooseEnum scalarOptions();
  virtual void act() override;
};

template <>
InputParameters validParams<RankTwoScalarAction>();

#endif // RANKTWOSCALARACTION_H
