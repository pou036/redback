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

#include "RedbackContinuationTangentAux.h"
#include "MooseMesh.h"

template<>
InputParameters validParams<RedbackContinuationTangentAux>()
{
  InputParameters params = validParams<AuxNodalScalarKernel>();
  params.addParam<Real>("ds_old", 1.0, "Old continuation increment");

  params.addCoupledVar("sum_var_1", 0.0, "Variable 1 to be summed");
  params.addCoupledVar("sum_var_2", 0.0, "Variable 2 to be summed");
  params.addCoupledVar("sum_var_3", 0.0, "Variable 3 to be summed");
  params.addCoupledVar("sum_var_4", 0.0, "Variable 4 to be summed");
  params.addCoupledVar("sum_var_5", 0.0, "Variable 5 to be summed");
  params.addCoupledVar("sum_var_6", 0.0, "Variable 6 to be summed");

  params.addCoupledVar("sum_var_old_1", 0.0, "Old variable 1 to be summed");
  params.addCoupledVar("sum_var_old_2", 0.0, "Old variable 2 to be summed");
  params.addCoupledVar("sum_var_old_3", 0.0, "Old variable 3 to be summed");
  params.addCoupledVar("sum_var_old_4", 0.0, "Old variable 4 to be summed");
  params.addCoupledVar("sum_var_old_5", 0.0, "Old variable 5 to be summed");
  params.addCoupledVar("sum_var_old_6", 0.0, "Old variable 6 to be summed");

  params.addCoupledVar("sum_var_older_1", 0.0, "Older variable 1 to be summed");
  params.addCoupledVar("sum_var_older_2", 0.0, "Older variable 2 to be summed");
  params.addCoupledVar("sum_var_older_3", 0.0, "Older variable 3 to be summed");
  params.addCoupledVar("sum_var_older_4", 0.0, "Older variable 4 to be summed");
  params.addCoupledVar("sum_var_older_5", 0.0, "Older variable 5 to be summed");
  params.addCoupledVar("sum_var_older_6", 0.0, "Older variable 6 to be summed");

  return params;
}

RedbackContinuationTangentAux::RedbackContinuationTangentAux(const InputParameters & parameters) :
    AuxNodalScalarKernel(parameters),
    _ds_old_param(getParam<Real>("ds_old")),
    _sum_var_1(coupledValue("sum_var_1")),
    _sum_var_2(coupledValue("sum_var_2")),
    _sum_var_3(coupledValue("sum_var_3")),
    _sum_var_4(coupledValue("sum_var_4")),
    _sum_var_5(coupledValue("sum_var_5")),
    _sum_var_6(coupledValue("sum_var_6")),
    _sum_var_old_1(coupledValue("sum_var_old_1")),
    _sum_var_old_2(coupledValue("sum_var_old_2")),
    _sum_var_old_3(coupledValue("sum_var_old_3")),
    _sum_var_old_4(coupledValue("sum_var_old_4")),
    _sum_var_old_5(coupledValue("sum_var_old_5")),
    _sum_var_old_6(coupledValue("sum_var_old_6")),
    _sum_var_older_1(coupledValue("sum_var_older_1")),
    _sum_var_older_2(coupledValue("sum_var_older_2")),
    _sum_var_older_3(coupledValue("sum_var_older_3")),
    _sum_var_older_4(coupledValue("sum_var_older_4")),
    _sum_var_older_5(coupledValue("sum_var_older_5")),
    _sum_var_older_6(coupledValue("sum_var_older_6"))
{
}

RedbackContinuationTangentAux::~RedbackContinuationTangentAux()
{
}

void
RedbackContinuationTangentAux::compute()
{
  _subproblem.reinitNodes(_node_ids, _tid);        // compute variables at nodes
  int nb_nodes  = _subproblem.mesh().getMesh().n_nodes();


  /*std::vector<int> test_vector(nb_nodes);
  for (int k = 0; k < nb_nodes; ++k)
  {
    std::fill(test_vector.begin() + k, test_vector.begin() + k, k);
    std::cout << " k  = " << k << std::endl;
  }*/


/*
  std::vector<dof_id_type> all_node_ids(nb_nodes);
  const libMesh::MeshBase::node_iterator begin = _subproblem.mesh().getMesh().nodes_begin();
  const libMesh::MeshBase::node_iterator end = _subproblem.mesh().getMesh().nodes_end();
  //for (libMesh::MeshBase::node_iterator k = begin; k != end; ++k)
  for (int k = 0; k < nb_nodes; ++k)
  {
    std::fill(all_node_ids.begin() + k, all_node_ids.begin() + k, (dof_id_type)k);
    std::cout << " k  = " << k << ", all_node_ids[k]=" << all_node_ids[k] << std::endl;
  }
*/
  /*int nb_nodes  = _subproblem.mesh().getMesh().max_node_id();
  int nb_nodes2  = _subproblem.mesh().getMesh().n_nodes();
  std::cout << "nb of nodes = " << nb_nodes << std::endl;
  std::cout << "nb of nodes2 = " << nb_nodes2 << std::endl;
  //std::cout << "test=" << test << std::endl;*/

// TODO: get the full list of nodes programmatically!!!


  //std::cout << "_var.order()=" << _var.order()<<std::endl;
  for (_i = 0; _i < _var.order(); ++_i) // _var.order()=1 for a scalar
  {
    Real value = computeValue();
    _communicator.sum(value);
    _var.setValue(_i, value);                  // update variable data, which is referenced by other kernels, so the value is up-to-date
  }
}

Real
RedbackContinuationTangentAux::computeValue()
{
  Real sum = 0;
  // TODO: check that all variables to sum have same size!
  for (unsigned int i = 0; i < _sum_var_1.size(); i++)
  {
    sum += (  (_sum_var_1[i] - _sum_var_old_1[i]) * (_sum_var_old_1[i] - _sum_var_older_1[i])
        //TODO: implement a switch to only sum variables which are defined!!!
            //+ (_sum_var_2[i] - _sum_var_old_2[i]) * (_sum_var_old_2[i] - _sum_var_older_2[i])
            //+ (_sum_var_3[i] - _sum_var_old_3[i]) * (_sum_var_old_3[i] - _sum_var_older_3[i])
            //+ (_sum_var_4[i] - _sum_var_old_4[i]) * (_sum_var_old_4[i] - _sum_var_older_4[i])
            //+ (_sum_var_5[i] - _sum_var_old_5[i]) * (_sum_var_old_5[i] - _sum_var_older_5[i])
            //+ (_sum_var_6[i] - _sum_var_old_6[i]) * (_sum_var_old_6[i] - _sum_var_older_6[i])
           )/_ds_old_param;
  }
  return sum;
}