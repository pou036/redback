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
#ifndef RANKTWOSCALARPOSTPROCESSOR_H
#define RANKTWOSCALARPOSTPROCESSOR_H

#include "GeneralPostprocessor.h"
#include "RankTwoTensor.h"

class RankTwoScalarPostprocessor;

template <>
InputParameters validParams<RankTwoScalarPostprocessor>();

class RankTwoScalarPostprocessor : public GeneralPostprocessor
{
public:
  RankTwoScalarPostprocessor(const InputParameters & parameters);

  virtual PostprocessorValue getValue() override;

protected:
  const PostprocessorValue & _index00;
  const PostprocessorValue & _index01;
  const PostprocessorValue & _index02;
  const PostprocessorValue & _index10;
  const PostprocessorValue & _index11;
  const PostprocessorValue & _index12;
  const PostprocessorValue & _index20;
  const PostprocessorValue & _index21;
  const PostprocessorValue & _index22;
  MooseEnum _scalar_type;
};

#endif /* RANKTWOSCALARPOSTPROCESSOR_H */
