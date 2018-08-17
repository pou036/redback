//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "InputParameters.h"
#include "MooseMesh.h"
#include "MooseTypes.h"
#include "RemoveLayerElements.h"
#include <fstream>

// #include "libmesh/mesh_refinement.h"
#include "libmesh/remote_elem.h"

template <>
InputParameters
validParams<RemoveLayerElements>()
{
  InputParameters params = validParams<MeshModifier>();
  params.addRequiredParam<SubdomainName>("master_block",
                                         "The master block from which we select the boundary elements");
  params.addRequiredParam<SubdomainName>("paired_block", "The paired block for which we add the boundary elements");
  params.addRequiredParam<FileName>("file", "Name of the txt file with the porosity change");
  params.addRequiredParam<FileName>("upper_layer_file", "Name of the txt file with the next layer to erode");
  params.addRequiredParam<FileName>("lower_layer_file", "Name of the txt file with the last layer eroded");
  return params;
}

RemoveLayerElements::RemoveLayerElements(const InputParameters & parameters) : MeshModifier(parameters)
{
}

void
RemoveLayerElements::modify()
{
  FileName file = getParam<FileName>("file");
  Real porosity_change = 0;
  std::string line;
  std::ifstream myfile(file.c_str());
  if (myfile.is_open())
  {
    while (myfile.good())
    {
      getline(myfile, line);
      std::stringstream ss(line);
      std::cout << "line:" << line << std::endl;
      std::istream_iterator<std::string> begin(ss);
      std::istream_iterator<std::string> end;
      std::vector<std::string> vstrings(begin, end);

      if (vstrings.size() == 0)
      {
        mooseWarning("file is empty");
        break;
      }
      porosity_change = std::stod(vstrings[ 0 ].c_str());
      break;
    }
    myfile.close();
  }

  MeshBase & mesh = _mesh_ptr->getMesh();
  //std::unique_ptr<MeshRefinement> mesh_refinement = libmesh_make_unique<MeshRefinement>(mesh);

  SubdomainID master_id;
  SubdomainID paired_id;
  // separate between erosion and dilation
  if (porosity_change >= 0)
  {
    master_id = _mesh_ptr->getSubdomainID(getParam<SubdomainName>("master_block"));
    paired_id = _mesh_ptr->getSubdomainID(getParam<SubdomainName>("paired_block"));
  }
  else
  {
    paired_id = _mesh_ptr->getSubdomainID(getParam<SubdomainName>("master_block"));
    master_id = _mesh_ptr->getSubdomainID(getParam<SubdomainName>("paired_block"));
  }

  Real total_volume = 1; // 0
  Real frac_volume = 0;
  int N_elem = 0;
  for (const auto & elem : mesh.active_element_ptr_range())
  {
    // total_volume+=elem->volume();
    N_elem += 1;
    if (elem->subdomain_id() == paired_id)
      frac_volume += elem->volume();
  }
  std::cout << "total_volume = " << total_volume << std::endl;
  std::cout << "paired_id_volume = " << frac_volume << std::endl;
  std::cout << "total_nb_elem = " << N_elem << std::endl;
  Real total_volume_to_change = total_volume * std::abs(porosity_change);
  std::cout << "total_volume_to_change = " << total_volume_to_change << std::endl;
  Real volume_changed = 0;
  Real volume_to_change;

  while (frac_volume < 1.-1e-10)
  {
    frac_volume = 0;
    for (const auto & elem : mesh.active_element_ptr_range())
    {
      if (elem->subdomain_id() == paired_id)
        frac_volume += elem->volume();
    }
    std::cout << std::endl << "current_paired_id_volume = " << frac_volume << std::endl;
    std::cout << "volume_changed = " << volume_changed << std::endl;
    volume_to_change = total_volume_to_change - volume_changed;
    // if (volume_to_change < volume_change_threshold)
    //   return;
    std::cout << "volume_to_change = " << volume_to_change << std::endl;

    // vector of the elements on the boundary to be stored
    std::vector<Elem *> elements;
    // Real min_size=total_volume;
    //
    // int nb_loops2 = 0;
    // while (nb_loops2 < 4)
    // {
    //   std::cout<<"nb_loops2 = "<<nb_loops2<<std::endl;
    // int nb_loops3 = 0;
    // while (nb_loops3<3)
    // {
    //   std::cout<<"nb_loops3 = "<<nb_loops3<<std::endl;
    elements = BoundaryElements(master_id, paired_id);
    //   bool diff_volume = false;
    //   min_size = elements[0]->volume();
    //   std::cout<<"min_size = "<<min_size<<std::endl;
    //   for (unsigned int i = 0; i < elements.size(); i++)
    //   {
    //     if (elements[i]->volume() < min_size)
    //     {
    //       if (std::abs(elements[i]->volume() - min_size) < std::pow(10,-10)) continue;
    //       std::cout<<"diff = "<<min_size - elements[i]->volume()<<std::endl;
    //       diff_volume = true;
    //       min_size = elements[i]->volume();
    //       std::cout<< i<<"'s size is "<<min_size<<std::endl;
    //     }
    //   }
    //   std::cout<<"min_size = "<<min_size<<std::endl;
    //   if (diff_volume==false) break;
    //   mesh_refinement->clean_refinement_flags();
    //   for (unsigned int i = 0; i < elements.size(); i++)
    //     if (elements[i]->volume() > min_size)
    //     {
    //       if (std::abs(elements[i]->volume() - min_size) < std::pow(10,-10)) continue;
    //       elements[i]->set_refinement_flag(Elem::REFINE);
    //     }
    //   mesh_refinement->refine_elements();
    //   mesh_refinement->clean_refinement_flags();
    //
    //   nb_loops3+=1;
    // }

    // check if we need to remove the layer
    Real layer_volume = 0;
    for (unsigned int i = 0; i < elements.size(); i++)
      layer_volume += elements[ i ]->volume();
    std::cout << "layer_volume = " << layer_volume << std::endl;
    // if (layer_volume < volume_change_threshold)
    //   return;
    if (layer_volume > volume_to_change)
    {
      FileName file = getParam<FileName>("upper_layer_file");
      FILE * output_file = fopen(file.c_str(), "w");
      fputs(std::to_string(volume_changed+layer_volume).c_str(), output_file);
      fclose(output_file);
      return;
    }
    // if (layer_volume <= volume_to_change) break;

    //   mesh_refinement->clean_refinement_flags();
    //   for (unsigned int i = 0; i < elements.size(); i++)
    //     elements[i]->set_refinement_flag(Elem::REFINE);
    //   mesh_refinement->refine_elements();
    //   mesh_refinement->clean_refinement_flags();
    //
    //   nb_loops2+=1;
    // }

    // Real layer_volume = 0;
    // for (unsigned int i = 0; i < elements.size(); i++)
    //   layer_volume+=elements[i]->volume();

    // Assign new subdomain IDs and make sure elements in different types are not assigned with the
    // same subdomain ID
    std::map<ElemType, std::set<SubdomainID> > type2blocks;
    for (unsigned int i = 0; i < elements.size(); i++)
    {
      // Get the element we need to assign, or skip it if we just have a
      // nullptr placeholder indicating a remote element.
      Elem * elem = elements[ i ];
      if (!elem)
        continue;

      ElemType type = elem->type();

      bool has_type = false;
      for (auto & it : type2blocks)
      {
        if (it.first == type)
        {
          has_type = true;
          it.second.insert(paired_id);
        }
        else if (it.second.count(paired_id) > 0)
          mooseError("trying to assign elements with different types with the same subdomain ID");
      }

      if (!has_type)
      {
        std::set<SubdomainID> blocks;
        blocks.insert(paired_id);
        type2blocks.insert(std::make_pair(type, blocks));
      }

      elem->subdomain_id() = paired_id;
    }

    volume_changed += layer_volume;
    FileName file = getParam<FileName>("lower_layer_file");
    FILE * output_file = fopen(file.c_str(), "w");
    fputs(std::to_string(volume_changed).c_str(), output_file);
    fclose(output_file);
  }
  // mooseError("MeshModifier RemoveLayerElements exceeded number of loops possible");
}

std::vector<Elem *>
RemoveLayerElements::BoundaryElements(SubdomainID master_id, SubdomainID paired_id)
{
  std::vector<Elem *> elements;

  MeshBase & mesh = _mesh_ptr->getMesh();

  // Prepare to query about sides adjacent to remote elements if we're
  // on a distributed mesh
  const processor_id_type my_n_proc = mesh.n_processors();
  const processor_id_type my_proc_id = mesh.processor_id();
  typedef std::vector<std::pair<dof_id_type, unsigned int> > vec_type;
  std::vector<vec_type> queries(my_n_proc);

  for (auto & elem : mesh.active_element_ptr_range())
  {
    // We only need to loop over elements in the master subdomain
    if (elem->subdomain_id() != master_id)
      continue;

    for (unsigned int side = 0; side < elem->n_sides(); side++)
    {
      const Elem * neighbor = elem->neighbor_ptr(side);

      // On a replicated mesh, we add all subdomain sides ourselves.
      // On a distributed mesh, we may have missed sides which
      // neighbor remote elements.  We should query any such cases.
      if (neighbor == remote_elem)
      {
        queries[ elem->processor_id() ].push_back(std::make_pair(elem->id(), side));
      }
      else if (neighbor != NULL && neighbor->subdomain_id() == paired_id)
      {
        Elem * elem1 = elem;
        if (std::find(elements.begin(), elements.end(), elem1) == elements.end())
          elements.push_back(elem1);
      }
    }
  }

  if (!mesh.is_serial())
  {
    Parallel::MessageTag queries_tag = mesh.comm().get_unique_tag(867), replies_tag = mesh.comm().get_unique_tag(5309);

    std::vector<Parallel::Request> side_requests(my_n_proc - 1), reply_requests(my_n_proc - 1);

    // Make all requests
    for (processor_id_type p = 0; p != my_n_proc; ++p)
    {
      if (p == my_proc_id)
        continue;

      Parallel::Request & request = side_requests[ p - (p > my_proc_id) ];

      mesh.comm().send(p, queries[ p ], request, queries_tag);
    }

    // Reply to all requests
    std::vector<vec_type> responses(my_n_proc - 1);

    for (processor_id_type p = 1; p != my_n_proc; ++p)
    {
      vec_type query;

      Parallel::Status status(mesh.comm().probe(Parallel::any_source, queries_tag));
      const processor_id_type source_pid = cast_int<processor_id_type>(status.source());

      mesh.comm().receive(source_pid, query, queries_tag);

      Parallel::Request & request = reply_requests[ p - 1 ];

      for (const auto & q : query)
      {
        const Elem * elem = mesh.elem_ptr(q.first);
        const unsigned int side = q.second;
        const Elem * neighbor = elem->neighbor_ptr(side);

        if (neighbor != NULL && neighbor->subdomain_id() == paired_id)
        {
          responses[ p - 1 ].push_back(std::make_pair(elem->id(), side));
        }
      }

      mesh.comm().send(source_pid, responses[ p - 1 ], request, replies_tag);
    }

    // Process all incoming replies
    for (processor_id_type p = 1; p != my_n_proc; ++p)
    {
      Parallel::Status status(this->comm().probe(Parallel::any_source, replies_tag));
      const processor_id_type source_pid = cast_int<processor_id_type>(status.source());

      vec_type response;

      this->comm().receive(source_pid, response, replies_tag);

      for (const auto & r : response)
      {
        Elem * elem = mesh.elem_ptr(r.first);
        if (std::find(elements.begin(), elements.end(), elem) == elements.end())
          elements.push_back(elem);
      }
    }

    Parallel::wait(side_requests);
    Parallel::wait(reply_requests);
  }

  std::cout << "layer of nb element =" << elements.size() << std::endl;
  return elements;
}
