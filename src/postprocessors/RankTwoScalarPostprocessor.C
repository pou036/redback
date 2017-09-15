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
#include "RankTwoScalarPostprocessor.h"
#include "RankTwoScalarTools.h"

template <>
InputParameters
validParams<RankTwoScalarPostprocessor>()
{
  InputParameters params = validParams<GeneralPostprocessor>();
  params.addRequiredParam<PostprocessorName>("index00", "Tensor's element");
  params.addRequiredParam<PostprocessorName>("index01", "Tensor's element");
  params.addRequiredParam<PostprocessorName>("index02", "Tensor's element");
  params.addRequiredParam<PostprocessorName>("index10", "Tensor's element");
  params.addRequiredParam<PostprocessorName>("index11", "Tensor's element");
  params.addRequiredParam<PostprocessorName>("index12", "Tensor's element");
  params.addRequiredParam<PostprocessorName>("index20", "Tensor's element");
  params.addRequiredParam<PostprocessorName>("index21", "Tensor's element");
  params.addRequiredParam<PostprocessorName>("index22", "Tensor's element");
  params.addParam<MooseEnum>("scalar_type", RankTwoScalarTools::scalarOptions(), "Type of scalar output");

  return params;
}

RankTwoScalarPostprocessor::RankTwoScalarPostprocessor(const InputParameters & parameters) :
    GeneralPostprocessor(parameters),
    _index00(getPostprocessorValue("index00")),
    _index01(getPostprocessorValue("index01")),
    _index02(getPostprocessorValue("index02")),
    _index10(getPostprocessorValue("index10")),
    _index11(getPostprocessorValue("index11")),
    _index12(getPostprocessorValue("index12")),
    _index20(getPostprocessorValue("index20")),
    _index21(getPostprocessorValue("index21")),
    _index22(getPostprocessorValue("index22")),
    _scalar_type(getParam<MooseEnum>("scalar_type"))
{
}

void
RankTwoScalarPostprocessor::initialize()
{
}

void
RankTwoScalarPostprocessor::execute()
{
}

PostprocessorValue
RankTwoScalarPostprocessor::getValue()
{
  RankTwoTensor tensor =
    RankTwoTensor(_index00, _index01, _index02, _index10, _index11, _index12, _index20, _index21, _index22);
  switch (_scalar_type)
  {
    case 0:
      return RankTwoScalarTools::vonMisesStress(tensor);
    case 1:
      return RankTwoScalarTools::effectiveStrain(tensor);
    case 2:
      return RankTwoScalarTools::hydrostatic(tensor);
    case 3:
      return RankTwoScalarTools::L2norm(tensor);
    case 7:
      return RankTwoScalarTools::volumetricStrain(tensor);
    case 8:
      return RankTwoScalarTools::firstInvariant(tensor);
    case 9:
      return RankTwoScalarTools::secondInvariant(tensor);
    case 10:
      return RankTwoScalarTools::thirdInvariant(tensor);
    case 14:
      return RankTwoScalarTools::triaxialityStress(tensor);
    default:
      mooseError("RankTwoScalar Error: unvalid scalar type");
  }
}
