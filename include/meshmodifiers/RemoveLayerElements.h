//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef REMOVELAYERELEMENTS_H
#define REMOVELAYERELEMENTS_H

// MOOSE includes
#include "MeshModifier.h"

// Forward declerations
class RemoveLayerElements;

template <>
InputParameters validParams<RemoveLayerElements>();

/**
 * MeshModifier for assigning subdomain IDs of all elements
 */
class RemoveLayerElements : public MeshModifier
{
public:
  RemoveLayerElements(const InputParameters & parameters);

protected:
  virtual void modify() override;
  std::vector<Elem *> BoundaryElements();

  SubdomainID _master_id;
  SubdomainID _paired_id;
};

#endif // REMOVELAYERELEMENTS_H
