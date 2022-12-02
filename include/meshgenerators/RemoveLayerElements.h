/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*                     (c) 2019 CSIRO                           */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*                    Prepared by CSIRO                         */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/
#pragma once

// MOOSE includes
#include "MeshGenerator.h"

/**
 * MeshModifier for assigning subdomain IDs of all elements
 */
class RemoveLayerElements : public MeshGenerator
{
public:
  RemoveLayerElements(const InputParameters & parameters);
  static InputParameters validParams();

  std::unique_ptr<MeshBase> generate() override;

protected:
  std::unique_ptr<MeshBase> & _input;

  std::vector<Elem *> BoundaryElements(SubdomainID master_id, SubdomainID paired_id);
};
