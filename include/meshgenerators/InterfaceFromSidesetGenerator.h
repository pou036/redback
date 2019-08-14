/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*                     (c) 2019 CSIRO                           */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#pragma once

#include "BreakMeshByBlockGeneratorBase.h"

class InterfaceFromSidesetGenerator;

template <>
InputParameters validParams<InterfaceFromSidesetGenerator>();

class InterfaceFromSidesetGenerator : public BreakMeshByBlockGeneratorBase
{
public:
  InterfaceFromSidesetGenerator(const InputParameters & parameters);

  std::unique_ptr<MeshBase> generate() override;

protected:
  std::unique_ptr<MeshBase> & _input;

private:
  /// generate the new boundary interface
  void addInterfaceBoundary(MeshBase & mesh, BoundaryName);
  /// test if node/element on given side of segment
  bool isNodeOnThatSideOfSegment(const Node &, const Node &, const Node &, const std::vector<Real>);
  bool isElementOnThatSideOfSegment(MeshBase & mesh, const Elem *, const dof_id_type, const dof_id_type, const std::set<int>, const std::vector<Real>);
  std::vector<Real> getMeshNormalVector(MeshBase & mesh);

  std::map<std::pair<subdomain_id_type, subdomain_id_type>,
           std::set<std::pair<dof_id_type, unsigned int>>>
      _new_boundary_sides_map;
  /// The sidesets on which to transform to interfaces
  std::vector<BoundaryName> _sidesets;
  /// The sidesets delimiting the border of the whole mesh
  std::vector<BoundaryName> _boundaries;
};

