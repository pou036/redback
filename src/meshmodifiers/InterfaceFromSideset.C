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

#include "InterfaceFromSideset.h"
#include "MooseMesh.h"

#include "libmesh/elem.h"

registerMooseObject("RedbackApp", InterfaceFromSideset);

template <>
InputParameters
validParams<InterfaceFromSideset>()
{
  InputParameters params = validParams<BreakMeshByBlockBase>();
  params.addRequiredParam<std::vector<BoundaryName>>(
        "sidesets", "The names of sidesets from which to create the new interface(s). "
        "They MUST be straight and NOT have branches");
  params.addRequiredParam<std::vector<BoundaryName>>(
        "boundaries", "The names of sidesets forming the outside '"
            "boundaries of the whole mesh");

  params.addClassDescription("Transform sidesets into interfaces. "
                             "At the moment"
                             "this only works on REPLICATED 2D mesh");
  return params;
}

InterfaceFromSideset::InterfaceFromSideset(const InputParameters & parameters)
  : BreakMeshByBlockBase(parameters),
    _sidesets(getParam<std::vector<BoundaryName>>("sidesets")),
    _boundaries(getParam<std::vector<BoundaryName>>("boundaries"))
{
  if (!isParamValid("sidesets"))
    mooseError("Invalid sidesets provided");
}

void
InterfaceFromSideset::modify()
{

  // TODO remove when distributed MESH capabilities are implemented
  _mesh_ptr->errorIfDistributedMesh("InterfaceFromSideset only works on a REPLICATED mesh");
  checkInputParameter();

  // save reference to mesh
  MeshBase & mesh = _mesh_ptr->getMesh();

  // Get sidesets IDs
  std::set<BoundaryID> sideset_ids;
  auto & sideset_names = getParam<std::vector<BoundaryName>>("sidesets");
  for (auto & sideset_name : sideset_names)
    sideset_ids.insert(_mesh_ptr->getBoundaryID(sideset_name));

  // Get boundaries IDs
  std::set<BoundaryID> boundary_ids;
  auto & boundary_names = getParam<std::vector<BoundaryName>>("boundaries");
  for (auto & boundary_name : boundary_names)
    boundary_ids.insert(_mesh_ptr->getBoundaryID(boundary_name));

  _mesh_ptr->buildBndElemList();

  // Identify node IDs on given boundaries and all sidesets
  std::set<int> boundary_node_ids;
  std::set<int> allsidesets_node_ids;
  std::map<BoundaryName, std::set<int>> sidesets_node_ids;
  for (auto it = _mesh_ptr->bndElemsBegin(); it != _mesh_ptr->bndElemsEnd(); ++it)
  {
    if (boundary_ids.count((*it)->_bnd_id) > 0)
    {
      Elem * elem = (*it)->_elem;
      auto s = (*it)->_side;
      std::vector<unsigned int> nodes_on_side = elem->nodes_on_side(s);
      for (unsigned int n = 0; n < nodes_on_side.size(); ++n)
        boundary_node_ids.insert(elem->node_id(nodes_on_side[n]));
    }
    for (auto & sideset_name : sideset_names)
    {
      auto sidedset_id = _mesh_ptr->getBoundaryID(sideset_name);
      if ((*it)->_bnd_id == sidedset_id)
      {
        Elem * elem = (*it)->_elem;
        auto s = (*it)->_side;
        std::vector<unsigned int> nodes_on_side = elem->nodes_on_side(s);
        for (unsigned int n = 0; n < nodes_on_side.size(); ++n)
        {
          sidesets_node_ids[sideset_name].insert(elem->node_id(nodes_on_side[n]));
          allsidesets_node_ids.insert(elem->node_id(nodes_on_side[n]));
        }
      }
    }
  }

  // identify nodes "not at the edge" for each sideset
  std::map<BoundaryName, std::map<int,int>> nb_neighbors_on_sideset;
  for (auto & sideset_name : sideset_names)
  {
    auto sidedset_id = _mesh_ptr->getBoundaryID(sideset_name);
    for (auto it = _mesh_ptr->bndElemsBegin(); it != _mesh_ptr->bndElemsEnd(); ++it)
      if ((*it)->_bnd_id == sidedset_id)
      {
        Elem * elem = (*it)->_elem;
        auto s = (*it)->_side;
        std::vector<unsigned int> nodes_on_side = elem->nodes_on_side(s);
        for (unsigned int n = 0; n < nodes_on_side.size(); ++n)
        {
          auto current_node_id = elem->node_id(nodes_on_side[n]);
          if (nb_neighbors_on_sideset[sideset_name].count(current_node_id) == 0)
            nb_neighbors_on_sideset[sideset_name][current_node_id] = 1;
          else
            nb_neighbors_on_sideset[sideset_name][current_node_id] += 1;
        }
      }
  }

  // Find normal vector to plane of mesh by looking at first element
  auto normal_vec = getMeshNormalVector(mesh);

  // initialize the node to elemen map
  const auto & node_to_elem_map = _mesh_ptr->nodeToElemMap();
  std::map<dof_id_type, std::vector<dof_id_type>> new_node_to_elem_map;

  // loop on each provided sideset
  for (auto & sideset_name : sideset_names)
  {
    auto sidedset_id = _mesh_ptr->getBoundaryID(sideset_name);
    printf("\nLoop on sideset '%s' (ID %d)\n",sideset_name.c_str(), sidedset_id);
    std::set<int> treated_node_ids;
    _new_boundary_sides_map.clear();

    // get a set of nodes on all sidesets but this sideset
    std::set<int> othersidesets_node_ids;
    for (auto & sideset_name2 : sideset_names)
      if (sideset_name2 != sideset_name)
        othersidesets_node_ids.insert(sidesets_node_ids[sideset_name2].begin(),
            sidesets_node_ids[sideset_name2].end());

    // loop on all elements involved in that sideset
    for (auto it = _mesh_ptr->bndElemsBegin(); it != _mesh_ptr->bndElemsEnd(); ++it)
      if ((*it)->_bnd_id == sidedset_id)
      {
        Elem * elem = (*it)->_elem;
        auto s = (*it)->_side;
        std::vector<unsigned int> nodes_on_side = elem->nodes_on_side(s);
        for (unsigned int n = 0; n < nodes_on_side.size(); ++n)
        {
          auto current_node_id = elem->node_id(nodes_on_side[n]);
          if (treated_node_ids.find(current_node_id) != treated_node_ids.end())
            continue; // already  processed that node ID

          // Find out if we need to duplicate this node or not
          const bool is_node_on_boundary =
            boundary_node_ids.find(current_node_id) != boundary_node_ids.end();
          const bool has_two_neighbours = nb_neighbors_on_sideset[sideset_name][current_node_id]>2;
          const bool is_node_on_other_sidesets =
            othersidesets_node_ids.find(current_node_id) != othersidesets_node_ids.end();
          bool do_duplicate = false;
          if (is_node_on_boundary)
            do_duplicate = true;
          else if (has_two_neighbours)
            do_duplicate = true;
          else if (is_node_on_other_sidesets)
            do_duplicate = true;
          if (do_duplicate)
          {
            // node to be duplicated
            printf("  Node %d needs to be duplicated", current_node_id);
            const Node * current_node = mesh.node_ptr(current_node_id);
            std::set<BoundaryID> elem_ids_on_that_side;
            std::set<BoundaryID> elem_ids_on_other_side;

            // add new node
            Node * new_node = nullptr;
            new_node = Node::build(*current_node, mesh.n_nodes()).release();
            new_node->processor_id() = current_node->processor_id();
            mesh.add_node(new_node);
            printf(" -> node %d\n", new_node->id());
            if (is_node_on_boundary)
              boundary_node_ids.insert(new_node->id());
            treated_node_ids.insert(new_node->id());  // to avoid looping on new node
            sidesets_node_ids[sideset_name].insert(new_node->id());
            allsidesets_node_ids.insert(new_node->id());
            std::map<dof_id_type, std::vector<dof_id_type>>::const_iterator
            node_to_elem_pair = node_to_elem_map.find(current_node_id);
            if (node_to_elem_pair==node_to_elem_map.end())
              node_to_elem_pair = new_node_to_elem_map.find(current_node_id);
            new_node_to_elem_map[new_node->id()] = node_to_elem_pair->second;
            for (auto & sideset_name2 : sideset_names)
              if (sideset_name2 != sideset_name)
              {
                nb_neighbors_on_sideset[sideset_name2][new_node->id()] =
                  nb_neighbors_on_sideset[sideset_name2][current_node_id];
                if (sidesets_node_ids[sideset_name2].find(current_node_id)
                    != sidesets_node_ids[sideset_name2].end())
                  sidesets_node_ids[sideset_name2].insert(new_node->id());
              }

            // Add sideset/boundary info to the new node
            std::vector<boundary_id_type> node_boundary_ids =
                mesh.boundary_info->boundary_ids(current_node);
            mesh.boundary_info->add_node(new_node, node_boundary_ids);

            if (nodes_on_side.size()!=2)
              mooseError("Implementation restriction: sides must contain 2 nodes");
            auto other_node_id = elem->node_id(nodes_on_side[(n+1)%2]);

            // retrieve connected elements from the map
            const std::vector<dof_id_type> & connected_elems =
                node_to_elem_pair->second;
            for (auto elem_id : connected_elems)
            {
              Elem * current_elem = mesh.elem_ptr(elem_id);
              // Find which side is it from our segment
              bool is_on_that_side = isElementOnThatSideOfSegment(
                mesh, current_elem, current_node_id, other_node_id,
                sidesets_node_ids[sideset_name], normal_vec);
              if (is_on_that_side)
              {
                elem_ids_on_that_side.insert(elem_id);
                // assign the newly added node to current_elem
                for (unsigned int node_id = 0; node_id < current_elem->n_nodes(); ++node_id)
                  if (current_elem->node_id(node_id) == current_node_id)
                  {
                    current_elem->set_node(node_id) = new_node;
                    break;
                  }
              }
              else
                elem_ids_on_other_side.insert(elem_id);
            }

            // create blocks pair and assign element side to new interface boundary map
            for (auto elem_id : connected_elems)
            {
              for (auto connected_elem_id : connected_elems)
              {
                Elem * current_elem = mesh.elem_ptr(elem_id);
                Elem * connected_elem = mesh.elem_ptr(connected_elem_id);
                if (current_elem != connected_elem &&
                  (elem_ids_on_that_side.find(elem_id) != elem_ids_on_that_side.end())  &&
                  (elem_ids_on_other_side.find(connected_elem_id) != elem_ids_on_other_side.end()))
                {
                  if (current_elem->has_neighbor(connected_elem))
                  {
                    std::pair<subdomain_id_type, subdomain_id_type> blocks_pair =
                        std::make_pair(current_elem->subdomain_id(), connected_elem->subdomain_id());
                    _new_boundary_sides_map[blocks_pair].insert(std::make_pair(
                        current_elem->id(), current_elem->which_neighbor_am_i(connected_elem)));
                  }
                }
              }
            }
          }
          else
            printf("  Node %d does NOT need to be duplicated\n", current_node_id);
          treated_node_ids.insert(current_node_id);
        }
      }
    addInterfaceBoundary(sideset_name);
  }
}

bool
InterfaceFromSideset::isElementOnThatSideOfSegment(
    const MeshBase & mesh,
    const Elem * elem,
    const dof_id_type node_id1,
    const dof_id_type node_id2,
    const std::set<int> sideset_node_ids,
    const std::vector<Real> normal_vec)
{
  // Find which side that element is from segment defined by other 2 nodes
  // by testing all nodes of that element
  const Node & node1 = mesh.node_ref(node_id1);
  const Node & node2 = mesh.node_ref(node_id2);
  // Order nodes to be consistent (assuming straight sidesets)
  bool is_node1_smaller_than_node2 = false;
  for (unsigned int i = 0; i < LIBMESH_DIM; ++i)
  {
    if ((node1)(i) != (node2)(i))
    {
      is_node1_smaller_than_node2 = ((node1)(i) < (node2)(i));
      break;
    }
  }

  bool result = true; // element is on "that" (one) side of segment
  for (MooseIndex(elem->n_vertices()) i_v = 0; i_v < elem->n_vertices(); ++i_v)
  {
    dof_id_type node_id = elem->node_id(i_v);
    bool is_node_on_sideset = (sideset_node_ids.find(node_id) != sideset_node_ids.end());
    if ((node_id != node_id1) && (node_id != node_id2) && !is_node_on_sideset)
    {
      const Node & test_node = mesh.node_ref(node_id);
      bool is_node_on_that_side;
      if (is_node1_smaller_than_node2)
        is_node_on_that_side = isNodeOnThatSideOfSegment(
            test_node, node1, node2, normal_vec);
      else
        is_node_on_that_side = isNodeOnThatSideOfSegment(
            test_node, node2, node1, normal_vec);
       return is_node_on_that_side; // one node on one side is enough to decide
    }
  }
  mooseError("No node evaluated in isElementOnThatSideOfSegment");
  return result;
}

bool
InterfaceFromSideset::isNodeOnThatSideOfSegment(
    const Node & nodetest,
    const Node & node1,
    const Node & node2,
    const std::vector<Real> normal_vec)
{
  /*
   * We have 2 given nodes (A and B) and a test node C
   * Define vector v such that \vec{v}=\vec{AB}x\vec{AC}
   * and then test scalar product (\vec{v}x\vec{AB}).\vec{AC}
   */
  Real v [LIBMESH_DIM]; // cross product \vec{AB}x\vec{AC}
  Real test = 0;
  for (unsigned int i = 0; i < LIBMESH_DIM; ++i)
  {
    v[i] = ((node2)((i+1)%LIBMESH_DIM) - (node1)((i+1)%LIBMESH_DIM))
      * ((nodetest)((i+2)%LIBMESH_DIM) - (node1)((i+2)%LIBMESH_DIM))
      - ((node2)((i+2)%LIBMESH_DIM) - (node1)((i+2)%LIBMESH_DIM))
      * ((nodetest)((i+1)%LIBMESH_DIM) - (node1)((i+1)%LIBMESH_DIM));
    test += v[i] * normal_vec[i];
  }
  bool result = false;
  if (test > 0)
    result = true;
  return result;
}

std::vector<Real>
InterfaceFromSideset::getMeshNormalVector(const MeshBase & mesh)
{
  // Find normal vector to plane of mesh by looking at first element
  std::vector<Real> normal_vec(LIBMESH_DIM, 0.);
  const Elem * first_elem = mesh.elem_ptr(0);
  if (first_elem->n_vertices() < 3)
    mooseError("Expected element with at least 3 nodes (got %d)", first_elem->n_vertices());
  const Node & nodeA = mesh.node_ref(first_elem->node_id(0));
  const Node & nodeB = mesh.node_ref(first_elem->node_id(1));
  const Node & nodeC = mesh.node_ref(first_elem->node_id(2));
  for (unsigned int i = 0; i < LIBMESH_DIM; ++i)
    normal_vec[i] = ((nodeB)((i+1)%LIBMESH_DIM) - (nodeA)((i+1)%LIBMESH_DIM))
      * ((nodeC)((i+2)%LIBMESH_DIM) - (nodeA)((i+2)%LIBMESH_DIM))
      - ((nodeB)((i+2)%LIBMESH_DIM) - (nodeA)((i+2)%LIBMESH_DIM))
      * ((nodeC)((i+1)%LIBMESH_DIM) - (nodeA)((i+1)%LIBMESH_DIM));
  return normal_vec;
}

void
InterfaceFromSideset::addInterfaceBoundary(BoundaryName sideset_name)
{
  BoundaryInfo & boundary_info = _mesh_ptr->getMesh().get_boundary_info();

  BoundaryID boundaryID = findFreeBoundaryId();
  std::string boundaryName = _interface_name + "_" + sideset_name;

  // loop over boundary sides
  for (auto & boundary_side_map : _new_boundary_sides_map)
  {

    // find the appropriate boundary name and id
    //  given master and slave block ID
    if (_split_interface)
    {
      mooseError("split_interface not tested yet...");
      findBoundaryNameAndInd(boundary_side_map.first.first,
                             boundary_side_map.first.second,
                             boundaryName,
                             boundaryID,
                             boundary_info);
    }
    else
      boundary_info.sideset_name(boundaryID) = boundaryName;

    // loop over all the sides belonging to each pair and add them to the proper interface
    for (auto & element_side : boundary_side_map.second)
      boundary_info.add_side(element_side.first, element_side.second, boundaryID);
  }
}
