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

#include "FunctionNormalDistributionIC.h"
#include "Function.h"
#include "MooseRandom.h"

#include "libmesh/point.h"

template <>
InputParameters
validParams<FunctionNormalDistributionIC>()
{
  InputParameters params = validParams<InitialCondition>();
  params.addRequiredParam<Real>("mean", "Mean value of normal distribution function");
  params.addRequiredParam<Real>("standard_deviation", "Standard deviation of normal distribution function");
  params.addParam<unsigned int>("seed", 0, "Seed value for the random number generator");
  return params;
}

FunctionNormalDistributionIC::FunctionNormalDistributionIC(const InputParameters & parameters) :
    InitialCondition(parameters),
    _mean(getParam<Real>("mean")),
    _stddev(getParam<Real>("standard_deviation"))
{
  mooseAssert(_stddev > 0.0, "standard_deviation must be positive for FunctionNormalDistributionIC!");
  MooseRandom::seed(getParam<unsigned int>("seed"));
}

Real
FunctionNormalDistributionIC::value(const Point & p)
{
  return MooseRandom::randNormal(_mean, _stddev);
}
