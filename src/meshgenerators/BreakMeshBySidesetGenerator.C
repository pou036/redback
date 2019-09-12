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

#include "BreakMeshBySidesetGenerator.h"
#include "CastUniquePointer.h"

#include "libmesh/distributed_mesh.h"
#include "libmesh/elem.h"
#include "MooseMeshUtils.h"

#include <typeinfo>

registerMooseObject("RedbackApp", BreakMeshBySidesetGenerator);

template <>
InputParameters
validParams<BreakMeshBySidesetGenerator>()
{
  InputParameters params = validParams<BreakMeshByBlockGeneratorBase>();
  params.addRequiredParam<MeshGeneratorName>("input", "The mesh we want to modify");
  params.addRequiredParam<std::vector<BoundaryName>>(
        "sidesets", "The names of sidesets from which to create the new interface(s).");
  params.addRequiredParam<std::vector<BoundaryName>>(
        "boundaries", "The names of sidesets forming the outside '"
        "boundaries of the whole mesh");
  params.addParam<bool>("create_lower_D_blocks", false,
        "Boolean to create or not lower dimensional blocks");
  params.addParam<bool>("verbose", false,
        "Boolean to print info to console (for debugging purposes)");
  params.addClassDescription("Break sidesets as interfaces and create "
        "corresponding lower dimensionality block if asked. At the moment"
        "this only works on REPLICATED mesh");
  return params;
}

BreakMeshBySidesetGenerator::BreakMeshBySidesetGenerator(const InputParameters & parameters)
  : BreakMeshByBlockGeneratorBase(parameters),
    _input(getMesh("input")),
    _sidesets(getParam<std::vector<BoundaryName>>("sidesets")),
    _boundaries(getParam<std::vector<BoundaryName>>("boundaries")),
    _do_lower_d_blocks(getParam<bool>("create_lower_D_blocks")),
    _verbose(getParam<bool>("verbose"))
{
  if (typeid(_input).name() == typeid(DistributedMesh).name())
    mooseError("BreakMeshBySidesetGenerator only works with ReplicatedMesh.");
}

std::string
BreakMeshBySidesetGenerator::getColorString(
    std::map<boundary_id_type, bool> & map_ssid_colors,
    std::set<boundary_id_type> & relevant_ss_ids)
{
  std::string s = "";
  for (auto ss_id: relevant_ss_ids)
    if (map_ssid_colors.find(ss_id) != map_ssid_colors.end())
      s += std::to_string(ss_id) + "_"
        + std::to_string(map_ssid_colors[ss_id]) + "__";
  return s;
}

void
BreakMeshBySidesetGenerator::assignNeighborColor(
    const Elem* elem,
    const Elem* elem_ref,
    std::set<dof_id_type> & elem_ids_colored,
    bool ref_color,
    std::map<dof_id_type, std::map<boundary_id_type, bool>> & elt_colors,
    const Node & node_ref,
    std::set<dof_id_type> & remaining_split_node_ids,
    std::set<dof_id_type> & ss_node_ids,
    boundary_id_type sideset_id,
    std::set<dof_id_type> & ss_split_node_ids,
    std::set<dof_id_type> & duplicated_node_ids)
{
  // find new color
  auto s = elem->which_neighbor_am_i(elem_ref);
  std::vector<unsigned int> nodes_on_side = elem->nodes_on_side(s);
  bool is_on_same_side = false;
  for (int n = 0; n < nodes_on_side.size(); ++n)
  {
    dof_id_type node_id = elem->node_id(nodes_on_side[n]);
    if (ss_node_ids.count(node_id) == 0)
    {
      is_on_same_side = true;
      //break; // could break if only interested in is_on_same_side...
    }
    else
    {
      // node is on sideset and in the splitting list -> next candidate
      if (node_id != node_ref.id() && ss_split_node_ids.count(node_id)>0
          && duplicated_node_ids.count(node_id)==0)
        remaining_split_node_ids.insert(node_id);
    }
  }
  if (std::find(elem_ids_colored.begin(), elem_ids_colored.end(), elem->id()) != elem_ids_colored.end())
    return;

  bool new_color = (is_on_same_side) ? ref_color : !ref_color;
  // update color map
  if (elt_colors.count(elem->id()) == 0)
    elt_colors[elem->id()] = {{sideset_id,new_color}};
  else
    elt_colors[elem->id()].insert(std::pair<boundary_id_type,bool>(sideset_id,new_color));
  // this element is done, add it from the list of elements done
  elem_ids_colored.insert(elem->id());
}

// Used to temporarily store information about which lower-dimensional
// sides to add and what subdomain id to use for the added sides.
struct ElemSideDouble
{
  ElemSideDouble(Elem * elem_in, unsigned short int side_in) : elem(elem_in), side(side_in) {}

  Elem * elem;
  unsigned short int side;
};

std::unique_ptr<MeshBase>
BreakMeshBySidesetGenerator::generate()
{
  std::unique_ptr<MeshBase> mesh = std::move(_input);

  // initialize the node to element map
  std::map<dof_id_type, std::vector<dof_id_type>> node_to_elem_map;
  for (const auto & elem : mesh->active_element_ptr_range())
    for (unsigned int n = 0; n < elem->n_nodes(); n++)
      node_to_elem_map[elem->node_id(n)].push_back(elem->id());

  // initialize the sideset IDs
  std::set<boundary_id_type> sideset_ids;
  std::map<dof_id_type, std::vector<boundary_id_type>> node_to_sidesets_map;
  auto & sideset_names = getParam<std::vector<BoundaryName>>("sidesets");
  for (auto & sideset_name : sideset_names)
    sideset_ids.insert(MooseMeshUtils::getBoundaryIDs(*mesh, {sideset_name}, true)[0]);

  // Equivalent to MooseMesh::buildBndElemList()
  auto & boundary_info = mesh->get_boundary_info();
  auto bc_tuples = boundary_info.build_active_side_list();
  int n = bc_tuples.size();
  std::vector<std::unique_ptr<BndElement>> bnd_elems;
  std::map<boundary_id_type, std::set<dof_id_type>> bnd_elem_ids;
  bnd_elems.reserve(n);
  for (const auto & t : bc_tuples)
  {
    auto elem_id = std::get<0>(t);
    auto side_id = std::get<1>(t);
    auto bc_id = std::get<2>(t);

    std::unique_ptr<BndElement> bndElem =
        libmesh_make_unique<BndElement>(mesh->elem_ptr(elem_id), side_id, bc_id);
    bnd_elems.push_back(std::move(bndElem));
    bnd_elem_ids[bc_id].insert(elem_id);
  }

  // Get boundaries IDs
  std::set<boundary_id_type> boundary_ids;
  auto & boundary_names = getParam<std::vector<BoundaryName>>("boundaries");
  for (auto & boundary_name : boundary_names)
    boundary_ids.insert(MooseMeshUtils::getBoundaryIDs(*mesh, {boundary_name}, true)[0]);

  // Identify node IDs on given boundaries
  std::set<int> boundary_node_ids;
  for (auto it = bnd_elems.begin(); it != bnd_elems.end(); ++it)
  {
    if (boundary_ids.count((*it)->_bnd_id) > 0)
    {
      Elem * elem = (*it)->_elem;
      auto s = (*it)->_side;
      std::vector<unsigned int> nodes_on_side = elem->nodes_on_side(s);
      for (unsigned int n = 0; n < nodes_on_side.size(); ++n)
        boundary_node_ids.insert(elem->node_id(nodes_on_side[n]));
    }
  }

  // Identify node IDs on given sidesets and their borders
  std::set<int> allsidesets_node_ids;
  std::map<BoundaryName, std::set<dof_id_type>> sidesets_node_ids;
  std::map<BoundaryName, std::set<dof_id_type>> ss_border_node_ids; // sideset border node IDs
  std::map<BoundaryName, std::set<dof_id_type>> ss_inside_node_ids; // sideset inside node IDs
  if (_verbose)
    printf("Identifying dimensionality of sidesets and getting all node IDs...\n");
  for (auto & sideset_name : sideset_names)
  {
    auto sideset_id = mesh->get_boundary_info().get_id_by_name(sideset_name);

    // Find if 2D or 3D based on first element only (assuming all the same..)
    int dim_ss; // dimensionality of sideset (2 or 3)
    auto it = bnd_elems.begin();
    Elem * elem = (*it)->_elem;
    if (elem->n_faces() > 0)
      dim_ss = 3;
    else
      dim_ss = 2;
    if (_verbose)
      printf("  Loop on sideset '%s' (ID %d) -> dim=%d\n",sideset_name.c_str(), sideset_id, dim_ss);

    std::set<std::vector<unsigned int>> face_node_ids;
    for (auto it = bnd_elems.begin(); it != bnd_elems.end(); ++it)
      if ((*it)->_bnd_id == sideset_id)
      {
        Elem * elem = (*it)->_elem;
        auto s = (*it)->_side;
        std::vector<unsigned int> nodes_on_side = elem->nodes_on_side(s);
        // get node IDs in whole sideset
        for (unsigned int n = 0; n < nodes_on_side.size(); ++n)
        {
          sidesets_node_ids[sideset_name].insert(elem->node_id(nodes_on_side[n]));
          allsidesets_node_ids.insert(elem->node_id(nodes_on_side[n]));
        }
        // get node IDs on sideset border
        if (dim_ss == 3)
        {
          // 3D case
          mooseError("BreakMeshBySidesetGenerator 3D case not implemented yet");// TODO
        } else
        {
          // 2D case
          std::vector<unsigned int> sorted_node_ids;
          for (unsigned int n = 0; n < nodes_on_side.size(); ++n)
          {
            sorted_node_ids.push_back(elem->node_id(nodes_on_side[n]));
          }
          sort(sorted_node_ids.begin(), sorted_node_ids.end());
          face_node_ids.insert(sorted_node_ids);
        }
      }
    if (dim_ss==2)
    {
      // count node_id occurrences on the sideset
      std::map<unsigned int, int> node_ids_nb;
      for(auto const& sorted_node_ids: face_node_ids)
      {
        for(int j = 0; j< sorted_node_ids.size(); j++)
          if (node_ids_nb.count(sorted_node_ids[j]) == 0)
            node_ids_nb[sorted_node_ids[j]] = 1;
          else
            node_ids_nb[sorted_node_ids[j]] += 1;
      }
      // Find which nodes are on the border (single occurrence)
      for(auto const& elt: node_ids_nb)
      {
        if (elt.second == 1)
          ss_border_node_ids[sideset_name].insert(elt.first);
        else
          ss_inside_node_ids[sideset_name].insert(elt.first);
      }
    } else
    {
      mooseError("BreakMeshBySidesetGenerator 3D case not implemented yet");// TODO
    }
  }

  // identify element "colors" (which side of sideset they are)
  if (_verbose)
    printf("Identifying element 'colors'...\n");
  std::map<dof_id_type, std::map<boundary_id_type, bool>> elt_colors; // {elt_id:{sideset_id:boolean}}
  std::set<dof_id_type> split_node_ids; // all nodes to be split
  for (auto & sideset_name : sideset_names)
  {
    if (_verbose)
      printf("Processing sideset %s...\n",sideset_name.c_str());
    auto sideset_id = mesh->get_boundary_info().get_id_by_name(sideset_name);
    std::map<dof_id_type, std::set<BoundaryName>> node_bounding_ss_names; // {node_id:[bounding sideset names]} for T-junction case
    // identify all nodes needing splitting on that sideset
    // include all nodes not on border
    std::set<dof_id_type> ss_split_node_ids(ss_inside_node_ids[sideset_name]);
    // include also nodes on border that are ...
    for (auto & node_id : ss_border_node_ids[sideset_name])
    {
      // ... inside other set's interior ("T junction")...
      // (needed even though that node will be tagged for splitting in other sideset)
      for (auto & other_sideset_name : sideset_names)
      {
        if (other_sideset_name != sideset_name)
          if (ss_inside_node_ids[other_sideset_name].count(node_id)>0)
          {
            ss_split_node_ids.insert(node_id);
            node_bounding_ss_names[node_id].insert(other_sideset_name);
          }
      }
      // ... or on boundary
      if (boundary_node_ids.count(node_id)>0)
        ss_split_node_ids.insert(node_id);
    }
    if (_verbose)
    {
      printf("  List of nodes to split: [");
      for (auto & node_id : ss_split_node_ids)
        printf("%d, ",node_id);
      printf("]\n");
    }
    // add to total list of nodes to split
    split_node_ids.insert(ss_split_node_ids.begin(), ss_split_node_ids.end());

    // identify element colors for that sideset
    std::set<dof_id_type> elem_ids_colored;
    std::set<dof_id_type> remaining_split_node_ids {*ss_split_node_ids.begin()};
    std::set<dof_id_type> duplicated_node_ids;
    while (remaining_split_node_ids.size() > 0)
    {
      // Pick next node to treat (paint elements around that node)
      auto it = remaining_split_node_ids.begin();
      auto node_id = *it;
      remaining_split_node_ids.erase(it);
      duplicated_node_ids.insert(node_id);

      // Painting elements around that node
      const Node & node_ref = mesh->node_ref(node_id);
      std::vector<dof_id_type> elt_ids_around_node = node_to_elem_map[node_id];
      std::set<dof_id_type> refed_elt_ids; // element IDs already used as reference
      // Pick reference element already seen if possible
      dof_id_type elt_ref_id;
      bool ref_color;
      bool found_elt_ref_id = false;
      for (const auto & elem_id : elt_ids_around_node)
      {
        if (elem_ids_colored.find(elem_id) != elem_ids_colored.end())
        {
          elt_ref_id = elem_id;
          found_elt_ref_id = true;
          ref_color = elt_colors[elt_ref_id][sideset_id];
          break;
        }
      }
      if (!found_elt_ref_id)
      {
        // if not found (for first node)
        if (node_bounding_ss_names[node_id].empty())
        {
          // pick one randomly
          elt_ref_id = elt_ids_around_node.back();
          elt_ids_around_node.pop_back();
        }
        else
        {
          // need to ensure the reference element has 2 nodes on sideset_name
          int test_count = 0;
          for (const auto & elem_id : elt_ids_around_node)
          {
            Elem * test_elem_ref = mesh->elem_ptr(elem_id);
            const Node * const * nodes_ptr = test_elem_ref->get_nodes();
            unsigned int n_nodes = test_elem_ref->n_nodes();
            for (unsigned int n=0; n<n_nodes; n++)
            {
              const Node * node = nodes_ptr[n];
              if (sidesets_node_ids[sideset_name].count(node->id())>0)
                test_count += 1;
            }
            if (test_count > 1)
            {
              elt_ref_id = elem_id;
              elt_ids_around_node.erase(std::remove(elt_ids_around_node.begin(),
                  elt_ids_around_node.end(), elem_id), elt_ids_around_node.end());
              break;
            }
          }
          if (test_count == 0)
            mooseError("Could not find reference element around node %d",node_id);
        }
        ref_color = true;
        if (elt_colors.count(elt_ref_id) == 0)
          elt_colors[elt_ref_id] = {{sideset_id, ref_color}};
        else if (elt_colors[elt_ref_id].count(sideset_id) == 0)
          elt_colors[elt_ref_id].insert(std::pair<boundary_id_type,bool>(sideset_id,ref_color));
      }
      Elem * elem_ref = mesh->elem_ptr(elt_ref_id);
      elem_ids_colored.insert(elt_ref_id);
      refed_elt_ids.insert(elt_ref_id);
      std::set<std::pair<subdomain_id_type, bool>> elt_ref_pairs = {std::make_pair(elt_ref_id,ref_color)};

      while (!elt_ref_pairs.empty())
      {
        // take next elt_ref_id and its color
        auto it = elt_ref_pairs.begin();
        std::pair<subdomain_id_type, bool> ref_pair = *it;
        elt_ref_id = ref_pair.first;
        ref_color = ref_pair.second;
        elem_ref = mesh->elem_ptr(elt_ref_id);
        elt_ref_pairs.erase(it);
        elt_ids_around_node.erase(std::remove(elt_ids_around_node.begin(),
            elt_ids_around_node.end(), elt_ref_id), elt_ids_around_node.end());

        // find neighboring elements (common edge)
        std::set<dof_id_type> next_ids_to_try;
        for (const auto & elem_id : elt_ids_around_node)
        {
          Elem * elem_i = mesh->elem_ptr(elem_id);
          if (elem_ref->contains_edge_of(elem_i))
          {
            // check if that edge is a bounding limit (i.e has 2 nodes on bounds)
            auto s = elem_ref->which_neighbor_am_i(elem_i);
            std::vector<unsigned int> nodes_on_side = elem_ref->nodes_on_side(s);
            int nb_nodes_on_bound = 0;
            for (int n = 0; n < nodes_on_side.size(); ++n)
            {
              dof_id_type tmp_node_id = elem_ref->node_id(nodes_on_side[n]);
              for (auto & other_sideset_name : node_bounding_ss_names[node_id])
              {
                if (sidesets_node_ids[other_sideset_name].count(tmp_node_id)>0)
                  nb_nodes_on_bound += 1;
              }
            }
            if (nb_nodes_on_bound < 2)
            {
              // that edge is not a bounding limit
              next_ids_to_try.insert(elem_id);
            }
          }
        }
        // Paint neighbouring elements
        for (const auto elem_id : next_ids_to_try)
        {
          if (refed_elt_ids.find(elem_id) == refed_elt_ids.end())
          {
            Elem * elem_neighbor = mesh->elem_ptr(elem_id);
            // paint neighbor element + identify next nodes (update remaining_split_node_ids)
            assignNeighborColor(elem_neighbor, elem_ref, elem_ids_colored,
                ref_color, elt_colors, node_ref, remaining_split_node_ids,
                sidesets_node_ids[sideset_name], sideset_id,
                ss_split_node_ids, duplicated_node_ids);

            // add that element to reference list
            // (needed even if elem_id was already painted, as other elements
            //  might only be accessible through that element)
            elt_ref_pairs.insert(std::make_pair(elem_id, elt_colors[elem_id][sideset_id]));
          }
        }
      }
      // this node is done
    }

    if (_verbose)
    {
      printf("  Colors for sideset '%s' (ID %d):\n",sideset_name.c_str(),sideset_id);
      for (auto & x: elt_colors)
      {
        if (elt_colors[x.first].count(sideset_id) > 0)
          printf("    element %d: %d\n",x.first, x.second[sideset_id]);
      }
    }
  }

  // splitting loop
  if (_verbose)
    printf("Splitting nodes...\n");
  for (auto current_node_id : split_node_ids)
  {
    const Node * current_node = mesh->node_ptr(current_node_id);

    if (current_node != nullptr)
    {
      // retrieve connected elements from the map
      const std::vector<dof_id_type> & connected_elems = node_to_elem_map[current_node_id];

      // find relevant sidesets, i.e. where both colors are involved
      std::map<boundary_id_type, std::set<bool>> involved_ss_colors; // {ss_id:set(colors)};
      for (auto elem_id = connected_elems.begin(); elem_id != connected_elems.end(); elem_id++)
      {
        for (auto & ssid_color: elt_colors[*elem_id]) // for ss_id in elt_colors[elem_id].keys():
        { // ssid_color.first=ss_id, ssid_color.second=elt_colors[elem_id][ss_id]
          if (involved_ss_colors.count(ssid_color.first) == 0)
            involved_ss_colors[ssid_color.first] = {ssid_color.second};
          else
            involved_ss_colors[ssid_color.first].insert(ssid_color.second);
        }
      }
      std::set<boundary_id_type> relevant_ss_ids;
      for (auto & x: involved_ss_colors)
      { // x.first=ss_id, x.second=set of involved colors
        if (x.second.size() == 2)
          relevant_ss_ids.insert(x.first);
      }

      // find node multiplicity
      std::set<std::string> connected_colors;
      for (auto elem_id = connected_elems.begin(); elem_id != connected_elems.end(); elem_id++)
        if (elt_colors.count(*elem_id) > 0)
          connected_colors.insert(getColorString(elt_colors[*elem_id], relevant_ss_ids));
      unsigned int node_multiplicity = connected_colors.size();

      // check if current_node need to be duplicated
      if (node_multiplicity > 1)
      {
        if (_verbose)
          printf("  node %d -> %d new node%s:", current_node->id(),
              node_multiplicity-1,(node_multiplicity>2 ? "s" : ""));

        // find reference_color (e.g. the first color alphabetically)
        auto color_it = connected_colors.begin();
        std::string reference_color_s = *color_it;

        // multiplicity counter to keep track of how many nodes we added
        unsigned int multiplicity_counter = node_multiplicity;
        for (auto elem_id : connected_elems)
        {
          // all the duplicate nodes are added and assigned
          if (multiplicity_counter == 0)
            break;
          Elem * current_elem = mesh->elem_ptr(elem_id);
          std::string elem_color_s = getColorString(elt_colors[elem_id],
              relevant_ss_ids);

          if (elem_color_s != reference_color_s)
          {
            // assign the newly added node to current_elem
            Node * new_node = nullptr;

            std::vector<boundary_id_type> node_boundary_ids;

            bool is_node_split = false;
            for (unsigned int node_id = 0; node_id < current_elem->n_nodes(); ++node_id)
              if (current_elem->node_id(node_id) ==
                  current_node->id()) // if current node == node on element
              {
                // add new node
                new_node = Node::build(*current_node, mesh->n_nodes()).release();
                new_node->processor_id() = current_node->processor_id();
                mesh->add_node(new_node);

                // Add boundary info to the new node
                mesh->boundary_info->boundary_ids(current_node, node_boundary_ids);
                mesh->boundary_info->add_node(new_node, node_boundary_ids);

                multiplicity_counter--; // node created, update multiplicity counter

                current_elem->set_node(node_id) = new_node;
                if (_verbose)
                  printf(" %d (elements [%d, ", new_node->id(), current_elem->id());
                is_node_split = true;
                break; // once proper node fixed in one element, break loop
              }

            if (is_node_split)
            {
              for (auto connected_elem_id : connected_elems)
              {
                Elem * connected_elem = mesh->elem_ptr(connected_elem_id);
                // Assign the newly added node to other connected elements with the same color_s
                std::string con_elem_color_s = getColorString(
                    elt_colors[connected_elem->id()],
                    relevant_ss_ids);
                if (con_elem_color_s == elem_color_s &&
                    connected_elem != current_elem)
                {
                  for (unsigned int node_id = 0; node_id < connected_elem->n_nodes(); ++node_id)
                    if (connected_elem->node_id(node_id) ==
                        current_node->id()) // if current node == node on element
                    {
                      connected_elem->set_node(node_id) = new_node;
                      if (_verbose)
                        printf("%d, ", connected_elem_id);
                      break;
                    }
                }
              }
              if (_verbose)
                printf("]), ");
            }
          }
        }
        if (_verbose)
          printf("\n");

        // assign element side to new interface boundary map
        for (auto elem_id : connected_elems)
        {
          for (auto connected_elem_id : connected_elems)
          {
            if (elem_id<=connected_elem_id)
              continue;
            Elem * current_elem = mesh->elem_ptr(elem_id);
            Elem * connected_elem = mesh->elem_ptr(connected_elem_id);

            if (current_elem != connected_elem)
            {
              if (current_elem->has_neighbor(connected_elem))
              {
                for (auto ss_id: relevant_ss_ids)
                {
                  if (elt_colors[current_elem->id()].find(ss_id) != elt_colors[current_elem->id()].end()
                      &&  elt_colors[connected_elem->id()].find(ss_id) != elt_colors[connected_elem->id()].end()
                      && elt_colors[current_elem->id()][ss_id] != elt_colors[connected_elem->id()][ss_id])
                  {
                    std::string ss_name = mesh->get_boundary_info().get_sideset_name(ss_id);
                    _new_boundary_sides_map2[ss_name].insert(std::make_pair(
                      current_elem->id(), current_elem->which_neighbor_am_i(connected_elem)));
                  }
                }
              }
            }
          }
        }

      } // end multiplicity check
    }   // end loop over nodes
  }     // end nodeptr check

  addInterfaceBoundary(*mesh);

  // create lower dimensional entities if needed
  if (_do_lower_d_blocks)
    addLowerDElements(*mesh);

  return dynamic_pointer_cast<MeshBase>(mesh);
}

void
BreakMeshBySidesetGenerator::findInterfaceNameAndInd(MeshBase & mesh,
                                                    const std::string & sideset_name,
                                                    std::string & boundaryName,
                                                    boundary_id_type & boundaryID,
                                                    BoundaryInfo & boundary_info)
{
  // TODO need to be updated if distributed mesh is implemented
  // comments are left to ease implementation

  // mpi barrier
  // first check which boundary name will be created
  boundaryName = _interface_name + "_" + sideset_name;

  // check if the boundary name already exist
  bool checkBoundaryAlreadyExist = false;
  for (auto b : _bName_bID_set)
  {
    if (b.first.compare(boundaryName) == 0)
    {
      boundaryID = b.second;
      checkBoundaryAlreadyExist = true;
    }
  }

  if (checkBoundaryAlreadyExist)
  {
    // mpi barrier end
    return;
  }
  else
  {
    boundaryID = findFreeBoundaryId(mesh);
    //mapBoundaryIdAndBoundaryName(boundaryID, boundaryName);
    _bName_bID_set.insert(std::pair<std::string, int>(boundaryName, boundaryID));

    boundary_info.sideset_name(boundaryID) = boundaryName;

    return;
  }
}

void
BreakMeshBySidesetGenerator::addInterfaceBoundary(MeshBase & mesh)
{
  BoundaryInfo & boundary_info = mesh.get_boundary_info();

  boundary_id_type boundaryID = findFreeBoundaryId(mesh);
  std::string boundaryName = _interface_name;

  // loop over boundary sides
  for (auto & boundary_side_map : _new_boundary_sides_map2)
  {
    // find the appropriate boundary name and id
    //  given master and slave block ID
    if (_split_interface)
      findInterfaceNameAndInd(mesh,
                              boundary_side_map.first,
                              boundaryName,
                              boundaryID,
                              boundary_info);
    else
      boundary_info.sideset_name(boundaryID) = boundaryName;

    // loop over all the side belonging to each sideset and add it to the proper interface
    for (auto & element_side : boundary_side_map.second)
      boundary_info.add_side(element_side.first, element_side.second, boundaryID);
  }
}

void
BreakMeshBySidesetGenerator::addLowerDElements(MeshBase & mesh)
{
  bool distributed = false;
  if (typeid(mesh).name() == typeid(std::unique_ptr<DistributedMesh>).name())
    distributed = true;

  BoundaryInfo & boundary_info = mesh.get_boundary_info();
  auto side_list = boundary_info.build_side_list();
  std::sort(side_list.begin(),
            side_list.end(),
            [](std::tuple<dof_id_type, unsigned short int, boundary_id_type> a,
               std::tuple<dof_id_type, unsigned short int, boundary_id_type> b) {
              auto a_elem_id = std::get<0>(a);
              auto b_elem_id = std::get<0>(b);
              if (a_elem_id == b_elem_id)
              {
                auto a_side_id = std::get<1>(a);
                auto b_side_id = std::get<1>(b);
                if (a_side_id == b_side_id)
                  return std::get<2>(a) < std::get<2>(b);
                else
                  return a_side_id < b_side_id;
              }
              else
                return a_elem_id < b_elem_id;
            });

  // Get sidesets IDs
  auto & sideset_names = getParam<std::vector<BoundaryName>>("sidesets");
  for (auto & sideset_name : sideset_names)
  {
    boundary_id_type sideset_id = MooseMeshUtils::getBoundaryIDs(mesh, {sideset_name}, true)[0];
    std::vector<ElemSideDouble> element_sides_on_sideset;
    for (const auto & triple : side_list)
      if (sideset_id == std::get<2>(triple))
        element_sides_on_sideset.push_back(
            ElemSideDouble(mesh.elem_ptr(std::get<0>(triple)), std::get<1>(triple)));

    dof_id_type max_elem_id = mesh.max_elem_id();
    mesh.comm().max(max_elem_id);
    auto max_elems_to_add = element_sides_on_sideset.size();
    mesh.comm().max(max_elems_to_add);

    subdomain_id_type new_block_id = findFreeBlockId(mesh);

    for (MooseIndex(element_sides_on_sideset) i = 0; i < element_sides_on_sideset.size(); ++i)
    {
      Elem * elem = element_sides_on_sideset[i].elem;
      if (distributed && elem->processor_id() != processor_id())
        continue;

      unsigned int side = element_sides_on_sideset[i].side;

      // Build a non-proxy element from this side.
      std::unique_ptr<Elem> side_elem(elem->build_side_ptr(side, /*proxy=*/false));

      // The side will be added with the same processor id as the parent.
      side_elem->processor_id() = elem->processor_id();

      // Add subdomain ID
      side_elem->subdomain_id() = new_block_id;

      // Also assign the side's interior parent, so it is always
      // easy to figure out the Elem we came from.
      side_elem->set_interior_parent(elem);

      // Add id for distributed
      if (distributed)
        side_elem->set_id(max_elem_id + processor_id() * max_elems_to_add + i);

      // Finally, add the lower-dimensional element to the Mesh.
      mesh.add_elem(side_elem.release());
    };

    // Assign block name
    std::string new_block_name("lowerD_");
    new_block_name += sideset_name.c_str();
    mesh.subdomain_name(new_block_id) = new_block_name;
  }
}

subdomain_id_type
BreakMeshBySidesetGenerator::findFreeBlockId(MeshBase & mesh)
{
  auto blocks = MooseMeshUtils::getSubdomainIDs(mesh, {"ANY_BLOCK_ID"});
  std::set<subdomain_id_type> current_block_ids(blocks.begin(), blocks.end());
  bool free_block_not_found = true;
  subdomain_id_type free_id;
  for (free_id = 0; free_id < std::numeric_limits<subdomain_id_type>::max(); free_id++)
  {
    if (current_block_ids.count(free_id) == 0)
    {
      // bid is not in the set, block ID is free
      free_block_not_found = false;
      break;
    }
  }

  if (free_block_not_found)
    mooseError("Too many blocks. Maximum limit exceeded!");

  return free_id;
}
