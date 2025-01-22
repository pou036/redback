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

#ifndef RANKTWOSCALARVOIDACTION_H
#define RANKTWOSCALARVOIDACTION_H

#include "Action.h"

class RankTwoScalarVoidAction : public Action
{
public:
  RankTwoScalarVoidAction(const InputParameters & params);

  MultiMooseEnum scalarOptions();
  virtual void act() override;
};

template <>
InputParameters validParams<RankTwoScalarVoidAction>();

#endif // RANKTWOSCALARVOIDACTION_H
