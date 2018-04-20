//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "RedbackFullSolveMultiApp.h"
#include "LayeredSideFluxAverage.h"
#include "Executioner.h"

// libMesh
#include "libmesh/mesh_tools.h"

template <>
InputParameters
validParams<RedbackFullSolveMultiApp>()
{
  InputParameters params = validParams<MultiApp>();
  return params;
}

RedbackFullSolveMultiApp::RedbackFullSolveMultiApp(const InputParameters & parameters)
  : MultiApp(parameters)
{
}

bool
RedbackFullSolveMultiApp::solveStep(Real /*dt*/, Real /*target_time*/, bool auto_advance)
{
  MultiApp::initialSetup();

  if (_has_an_app)
  {
    Moose::ScopedCommSwapper swapper(_my_comm);

    _executioners.resize(_my_num_apps);

    // Grab Executioner from each app
    for (unsigned int i = 0; i < _my_num_apps; i++)
    {
      auto & app = _apps[i];
      Executioner * ex = app->getExecutioner();

      if (!ex)
        mooseError("Executioner does not exist!");

      ex->init();

      _executioners[i] = ex;
    }
  }

  if (!auto_advance)
    mooseError("RedbackFullSolveMultiApp is not compatible with auto_advance=false");

  if (!_has_an_app)
  {
    std::cout<<"doesn't have an app"<<std::endl;
    return true;
  }

  Moose::ScopedCommSwapper swapper(_my_comm);

  int rank;
  int ierr;
  ierr = MPI_Comm_rank(_orig_comm, &rank);
  mooseCheckMPIErr(ierr);

  bool last_solve_converged = true;
  for (unsigned int i = 0; i < _my_num_apps; i++)
  {
    Executioner * ex = _executioners[i];
    ex->execute();
    if (!ex->lastSolveConverged())
      last_solve_converged = false;
  }

  return last_solve_converged;
}
