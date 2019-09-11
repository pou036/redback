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

#include "BreakMeshByBlockGeneratorBase.h"

class BreakMeshBySidesetGenerator;

template <>
InputParameters validParams<BreakMeshBySidesetGenerator>();

class BreakMeshBySidesetGenerator : public BreakMeshByBlockGeneratorBase
{
public:
  BreakMeshBySidesetGenerator(const InputParameters & parameters);

  std::unique_ptr<MeshBase> generate() override;

protected:
  std::unique_ptr<MeshBase> & _input;

private:
  /// find interface name and ID
  void findInterfaceNameAndInd(MeshBase & mesh,
      const std::string & sideset_name,
      std::string & boundaryName,
      boundary_id_type & boundaryID,
      BoundaryInfo & boundary_info);
  /// generate the new boundary interface
  void addInterfaceBoundary(MeshBase & mesh);
  /// get string representing "color"
  std::string getColorString(
      std::map<boundary_id_type, bool> &,
      std::set<boundary_id_type> &);
  /// assign "color" of neighbor element
  void assignNeighborColor(
      const Elem*,
      const Elem*,
      std::set<dof_id_type> &,
      bool,
      std::map<dof_id_type, std::map<boundary_id_type, bool>> &,
      const Node &,
      std::set<dof_id_type> &,
      std::set<dof_id_type> &,
      boundary_id_type,
      std::set<dof_id_type> &,
      std::set<dof_id_type> &);

  std::set<std::pair<subdomain_id_type, subdomain_id_type>> _neighboring_block_list;
  std::map<std::pair<subdomain_id_type, subdomain_id_type>,
           std::set<std::pair<dof_id_type, unsigned int>>>
      _new_boundary_sides_map;

  /// The sidesets on which to transform to interfaces
  std::vector<BoundaryName> _sidesets;
  /// The sidesets delimiting the border of the whole mesh
  std::vector<BoundaryName> _boundaries;

  std::map<std::string, std::set<std::pair<dof_id_type, unsigned int>>>
      _new_boundary_sides_map2;
  /// Verbose flag for debugging prints to appear on console
  const bool _verbose;
};
