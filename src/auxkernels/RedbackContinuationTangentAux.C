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

#include "MooseMesh.h"
#include "RedbackContinuationTangentAux.h"

template <>
InputParameters
validParams<RedbackContinuationTangentAux>()
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
  // Check that all variables defined contain all 3 components
  int sum_1 = (int)isCoupled("sum_var_1") + (int)isCoupled("sum_var_old_1") + (int)isCoupled("sum_var_older_1");
  int sum_2 = (int)isCoupled("sum_var_2") + (int)isCoupled("sum_var_old_2") + (int)isCoupled("sum_var_older_2");
  int sum_3 = (int)isCoupled("sum_var_3") + (int)isCoupled("sum_var_old_3") + (int)isCoupled("sum_var_older_3");
  int sum_4 = (int)isCoupled("sum_var_4") + (int)isCoupled("sum_var_old_4") + (int)isCoupled("sum_var_older_4");
  int sum_5 = (int)isCoupled("sum_var_5") + (int)isCoupled("sum_var_old_5") + (int)isCoupled("sum_var_older_5");
  int sum_6 = (int)isCoupled("sum_var_6") + (int)isCoupled("sum_var_old_6") + (int)isCoupled("sum_var_older_6");

  if (sum_1 != 0 && sum_1 != 3)
    mooseError("RedbackContinuationTangentAux requires three inputs for variable 1: sum_var_1, sum_var_old_1, and "
               "sum_var_older_1");
  if (sum_2 != 0 && sum_2 != 3)
    mooseError("RedbackContinuationTangentAux requires three inputs for variable 2: sum_var_2, sum_var_old_2, and "
               "sum_var_older_2");
  if (sum_3 != 0 && sum_3 != 3)
    mooseError("RedbackContinuationTangentAux requires three inputs for variable 3: sum_var_3, sum_var_old_3, and "
               "sum_var_older_3");
  if (sum_4 != 0 && sum_4 != 3)
    mooseError("RedbackContinuationTangentAux requires three inputs for variable 4: sum_var_4, sum_var_old_4, and "
               "sum_var_older_4");
  if (sum_5 != 0 && sum_5 != 3)
    mooseError("RedbackContinuationTangentAux requires three inputs for variable 5: sum_var_5, sum_var_old_5, and "
               "sum_var_older_5");
  if (sum_6 != 0 && sum_6 != 3)
    mooseError("RedbackContinuationTangentAux requires three inputs for variable 6: sum_var_6, sum_var_old_6, and "
               "sum_var_older_6");

  _is_var1_coupled = (sum_1 == 3);
  _is_var2_coupled = (sum_2 == 3);
  _is_var3_coupled = (sum_3 == 3);
  _is_var4_coupled = (sum_4 == 3);
  _is_var5_coupled = (sum_5 == 3);
  _is_var6_coupled = (sum_6 == 3);

  // Check that all variables to sum have same size
  if (_is_var1_coupled)
  {
    int var_size = _sum_var_1.size();
    if (_is_var2_coupled && (_sum_var_2.size() != var_size))
      mooseError("RedbackContinuationTangentAux: variable 2 has different size from variable 1");
    if (_is_var3_coupled && (_sum_var_3.size() != var_size))
      mooseError("RedbackContinuationTangentAux: variable 3 has different size from variable 1");
    if (_is_var4_coupled && (_sum_var_4.size() != var_size))
      mooseError("RedbackContinuationTangentAux: variable 4 has different size from variable 1");
    if (_is_var5_coupled && (_sum_var_5.size() != var_size))
      mooseError("RedbackContinuationTangentAux: variable 5 has different size from variable 1");
    if (_is_var6_coupled && (_sum_var_6.size() != var_size))
      mooseError("RedbackContinuationTangentAux: variable 6 has different size from variable 1");
  }
  else
  {
    mooseError("RedbackContinuationTangentAux: at least one variable must be defined (and it must be variable 1)");
  }
}

RedbackContinuationTangentAux::~RedbackContinuationTangentAux()
{
}

void
RedbackContinuationTangentAux::compute()
{
  int nb_nodes = _subproblem.mesh().getMesh().n_nodes();
  std::vector<dof_id_type> all_node_ids(nb_nodes);

  // const libMesh::MeshBase::node_iterator begin = _subproblem.mesh().getMesh().nodes_begin();
  // const libMesh::MeshBase::node_iterator end = _subproblem.mesh().getMesh().nodes_end();
  // for (libMesh::MeshBase::node_iterator k = begin; k != end; ++k)
  for (int k = 0; k < nb_nodes; ++k)
  {
    all_node_ids[ k ] = k;
  }
  _subproblem.reinitNodes(all_node_ids, _tid); // compute variables at nodes

  for (_i = 0; _i < _var.order(); ++_i) // _var.order()=1 for a scalar
  {
    Real value = computeValue();
    _communicator.sum(value);
    _var.setValue(_i, value); // update variable data, which is referenced by other kernels, so the value is up-to-date
  }
}

Real
RedbackContinuationTangentAux::computeValue()
{
  Real sum = 0;

  for (unsigned int i = 0; i < _sum_var_1.size(); i++)
  {
    // At least variable 1 is involved
    sum += (_sum_var_1[ i ] - _sum_var_old_1[ i ]) * (_sum_var_old_1[ i ] - _sum_var_older_1[ i ]);
    // Other variables could be involved
    if (_is_var2_coupled)
      sum += (_sum_var_2[ i ] - _sum_var_old_2[ i ]) * (_sum_var_old_2[ i ] - _sum_var_older_2[ i ]);
    if (_is_var3_coupled)
      sum += (_sum_var_3[ i ] - _sum_var_old_3[ i ]) * (_sum_var_old_3[ i ] - _sum_var_older_3[ i ]);
    if (_is_var4_coupled)
      sum += (_sum_var_4[ i ] - _sum_var_old_4[ i ]) * (_sum_var_old_4[ i ] - _sum_var_older_4[ i ]);
    if (_is_var5_coupled)
      sum += (_sum_var_5[ i ] - _sum_var_old_5[ i ]) * (_sum_var_old_5[ i ] - _sum_var_older_5[ i ]);
    if (_is_var6_coupled)
      sum += (_sum_var_6[ i ] - _sum_var_old_6[ i ]) * (_sum_var_old_6[ i ] - _sum_var_older_6[ i ]);
  }
  sum = sum / _ds_old_param;
  return sum;
}
