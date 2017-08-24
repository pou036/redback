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

#include "FEProblem.h"
#include "Factory.h"
#include "Parser.h"
#include "RankTwoScalarAction.h"
#include "RankTwoScalarTools.h"

template <>
InputParameters
validParams<RankTwoScalarAction>()
{
  InputParameters params = validParams<Action>();
  params.addRequiredParam<std::vector<MaterialPropertyName> >("rank_two_tensor", "The rank two material tensors name");
  params.addRequiredParam<MultiMooseEnum>("scalar_type",
                                          MultiMooseEnum("VonMisesStress EffectiveStrain Hydrostatic L2norm "
                                                         "VolumetricStrain FirstInvariant SecondInvariant "
                                                         "ThirdInvariant TriaxialityStress"),
                                          "Type of scalar outputs");
  params.addParam<std::vector<SubdomainName> >("block",
                                               "The list of block ids (SubdomainID) that this object will be applied");
  // TODO: create function to divide the integral by the volme / allow to do surfacic

  return params;
}

RankTwoScalarAction::RankTwoScalarAction(InputParameters params) : Action(params)
{
}

void
RankTwoScalarAction::act()
{
  std::vector<MaterialPropertyName> tensors = getParam<std::vector<MaterialPropertyName> >("rank_two_tensor");
  const MultiMooseEnum scalar_types = getParam<MultiMooseEnum>("scalar_type");

  for (int i = 0; i < tensors.size(); i++)
  {
    for (int j = 0; j < LIBMESH_DIM; j++)
    {
      for (int k = 0; k < LIBMESH_DIM; k++)
      {
        InputParameters pp_params = _factory.getValidParams("MaterialTensorIntegral");
        pp_params.set<MaterialPropertyName>("rank_two_tensor") = tensors[ i ];
        pp_params.set<unsigned int>("index_i") = j;
        pp_params.set<unsigned int>("index_j") = k;
        pp_params.set<std::vector<OutputName> >("outputs") = { "none" };
        if (isParamValid("block"))
        {
          pp_params.set<std::vector<SubdomainName> >("block") = getParam<std::vector<SubdomainName> >("block");
        }
        _problem->addPostprocessor(
          "MaterialTensorIntegral", std::string(tensors[ i ]) + std::to_string(j) + std::to_string(k), pp_params);
      }
    }

    for (int j = 0; j < scalar_types.size(); j++)
    {
      InputParameters pp_params = _factory.getValidParams("RankTwoScalarPostprocessor");
      for (int j = 0; j < LIBMESH_DIM; j++)
      {
        for (int k = 0; k < LIBMESH_DIM; k++)
        {
          pp_params.set<PostprocessorName>(std::string("index") + std::to_string(j) + std::to_string(k)) =
            std::string(tensors[ i ]) + std::to_string(j) + std::to_string(k);
        }
      }
      pp_params.set<MooseEnum>("scalar_type") = scalar_types[ j ];
      _problem->addPostprocessor("RankTwoScalarPostprocessor",
                                 std::string(tensors[ i ]) + std::string("_") + std::string(scalar_types[ j ]),
                                 pp_params);
    }
  }
  
  // InputParameters pp_params = _factory.getValidParams("VolumePostprocessor");
  // if (isParamValid("block"))
  // {
  //   pp_params.set<std::vector<SubdomainName> >("block") = getParam<std::vector<SubdomainName> >("block");
  // }
  // _problem->addPostprocessor("VolumePostprocessor", "Volume", pp_params);
}
