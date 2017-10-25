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
#include "RankTwoContractionAction.h"

template <>
InputParameters
validParams<RankTwoContractionAction>()
{
  InputParameters params = validParams<Action>();
  params.addRequiredParam<std::vector<MaterialPropertyName> >("rank_two_tensor", "The rank two material tensors name");

  return params;
}

RankTwoContractionAction::RankTwoContractionAction(InputParameters params) : Action(params)
{
}

void
RankTwoContractionAction::act()
{
  std::vector<MaterialPropertyName> tensors = getParam<std::vector<MaterialPropertyName> >("rank_two_tensor");

  for (int i = 0; i < 2; i++)
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
        _problem->addPostprocessor("MaterialTensorIntegral",
                                   std::string("RankTwoContractionAction_") + std::string(tensors[ i ]) +
                                     std::to_string(j) + std::to_string(k),
                                   pp_params);
      }
    }
  }

  InputParameters pp_params = _factory.getValidParams("RankTwoContractionPostprocessor");
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < LIBMESH_DIM; j++)
    {
      for (int k = 0; k < LIBMESH_DIM; k++)
      {
        pp_params.set<PostprocessorName>(std::to_string(i + 1) + std::string("_index") + std::to_string(j) +
                                         std::to_string(k)) =
          std::string("RankTwoContractionAction_") + std::string(tensors[ i ]) + std::to_string(j) + std::to_string(k);
      }
    }
  }
  _problem->addPostprocessor("RankTwoContractionPostprocessor", "macro_pl_dissipation", pp_params);
}
