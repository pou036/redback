//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "AppFactory.h"
#include "Executioner.h"
#include "LayeredSideDiffusiveFluxAverage.h"
#include "RedbackFullSolveMultiApp.h"

// libMesh
#include "libmesh/mesh_tools.h"

registerMooseObject("RedbackApp", RedbackFullSolveMultiApp);

InputParameters
RedbackFullSolveMultiApp::validParams()
{
  InputParameters params = MultiApp::validParams();
  params.addRequiredParam<FileName>("file", "Name of the txt file with the porosity change");
  params.addParam<FileName>("times_file", "", "Name of the txt file to write the time values");
  params.addRequiredParam<FileName>("upper_layer_file",
                                    "Name of the txt file with the next layer to erode");
  params.addRequiredParam<FileName>("lower_layer_file",
                                    "Name of the txt file with the last layer eroded");
  return params;
}

RedbackFullSolveMultiApp::RedbackFullSolveMultiApp(const InputParameters & parameters)
  : MultiApp(parameters), _times_file(getParam<FileName>("times_file"))
{
  _porosity_change = 0;
  _porosity_change_old = 0;

  // write text
  if (_times_file != "")
  {
    FILE * output_file = fopen(_times_file.c_str(), "w");
    fputs("", output_file);
    fclose(output_file);
  }
}

bool
RedbackFullSolveMultiApp::solveStep(Real /*dt*/, Real target_time, bool auto_advance)
{
  _porosity_change = ReadFile(getParam<FileName>("file"));
  Real upper_layer_threshold = ReadFile(getParam<FileName>("upper_layer_file"));
  Real lower_layer_threshold = ReadFile(getParam<FileName>("lower_layer_file"));

  // so that we don't run the subapp before we can remove the next layer
  if (_porosity_change - _porosity_change_old >= 0 &&
      std::abs(_porosity_change) < upper_layer_threshold)
    return true;
  if (_porosity_change - _porosity_change_old <= 0 &&
      std::abs(_porosity_change) > lower_layer_threshold)
    return true;
  // update the last time where we ran the subapp
  _porosity_change_old = _porosity_change;

  // write text
  if (_times_file != "")
  {
    FILE * output_file = fopen(_times_file.c_str(), "a");
    fputs(" ", output_file);
    fputs(std::to_string(target_time).c_str(), output_file);
    fclose(output_file);
  }

  // initial_setup
  if (!_has_an_app)
  {
    std::cout << "doesn't have an app" << std::endl;
    return true;
  }

  Moose::ScopedCommSwapper swapper(_my_comm);

  _apps.resize(_my_num_apps);

  // If the user provided an unregistered app type, see if we can load it dynamically
  if (!AppFactory::instance().isRegistered(_app_type))
    _app.dynamicAppRegistration(
        _app_type, getParam<std::string>("library_path"), getParam<std::string>("library_name"));

  for (unsigned int i = 0; i < _my_num_apps; i++)
    createApp(i, _app.getGlobalTimeOffset());

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

  // solver
  if (!auto_advance)
    mooseError("RedbackFullSolveMultiApp is not compatible with auto_advance=false");

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

Real
RedbackFullSolveMultiApp::ReadFile(FileName file_name)
{
  Real value = 0;
  std::string line;
  std::ifstream myfile(file_name.c_str());
  if (myfile.is_open())
  {
    while (myfile.good())
    {
      getline(myfile, line);
      std::stringstream ss(line);
      std::istream_iterator<std::string> begin(ss);
      std::istream_iterator<std::string> end;
      std::vector<std::string> vstrings(begin, end);
      if (vstrings.size() == 0)
      {
        mooseWarning("file is empty");
        break;
      }
      value = std::stod(vstrings[0].c_str());
      break;
    }
    myfile.close();
  }
  return value;
}
