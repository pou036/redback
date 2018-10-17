//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "PointValueFileWriter.h"
#include <fstream>

// MOOSE includes
#include "Function.h"
#include "MooseMesh.h"
#include "MooseVariable.h"
#include "SubProblem.h"

#include "libmesh/system.h"

template <>
InputParameters
validParams<PointValueFileWriter>()
{
  InputParameters params = validParams<GeneralPostprocessor>();
  params.addRequiredParam<VariableName>(
      "variable", "The name of the variable that this postprocessor operates on.");
  params.addRequiredParam<Point>("point",
                                 "The physical point where the solution will be evaluated.");
  params.addRequiredParam<FileName>("file", "Name of the CTscan data file");
  params.addRequiredParam<FileName>("working_file", "Name of the data file to be created");
  params.addRequiredParam<FileName>("multiapp_file",
                                    "Name of the file to know if multiapp should be run");
  params.addRequiredParam<std::string>("pore_value", "Value of the pore (string)");
  params.addRequiredParam<std::string>("grain_value", "Value of the grain (string)");
  params.addParam<unsigned int>(
      "refinement_level", 0, "Number of elements wanted per pixel of the image");

  return params;
}

PointValueFileWriter::PointValueFileWriter(const InputParameters & parameters)
  : GeneralPostprocessor(parameters),
    _var_number(_subproblem.getVariable(_tid, parameters.get<VariableName>("variable")).number()),
    _system(_subproblem.getSystem(getParam<VariableName>("variable"))),
    _point(getParam<Point>("point")),
    _old_poro_value(0),
    _file_name(getParam<FileName>("file")),
    _working_file_name(getParam<FileName>("working_file")),
    _multiapp_file_name(getParam<FileName>("multiapp_file")),
    _value_pore(getParam<std::string>("pore_value")),
    _value_grain(getParam<std::string>("grain_value")),
    _refinement(getParam<unsigned int>("refinement_level") + 1)
{
  // read the CTscan txt file and extract the information
  std::string line;
  std::ifstream myfile(_file_name);
  std::vector<std::vector<std::string>> data;
  if (myfile.is_open())
  {
    while (myfile.good())
    {
      getline(myfile, line);
      std::stringstream ss(line);
      std::istream_iterator<std::string> begin(ss);
      std::istream_iterator<std::string> end;
      std::vector<std::string> vstrings(begin, end);
      data.push_back(vstrings);
    }
    myfile.close();
  }
  else
    mooseError("Unable to open file");

  // keeping only necessary data
  data.erase(data.end() - 1);
  data.erase(data.begin(), data.begin() + 5);

  std::vector<std::vector<std::string>> data_refined;
  if (_refinement > 1)
  {
    // uniform refinement
    data_refined.resize(_refinement * data.size());
    for (int i = 0; i < data.size(); ++i)
    {
      for (int j = 0; j < data.size(); ++j)
        for (int k = 0; k < _refinement; ++k)
          data_refined[_refinement * i].push_back(data[i][j]);
      for (int l = 1; l < _refinement; ++l)
        data_refined[_refinement * i + l] = data_refined[_refinement * i];
    }
  }
  else
    data_refined = data;

  // calculating _size_CT in both direction of CTscan
  _size_CT = data_refined.size();
  std::cout << "_size_CT = " << _size_CT << std::endl;

  // calculating the pore_volume
  for (int i = 0; i < _size_CT; ++i)
    for (int j = 0; j < _size_CT; ++j)
      if (data_refined[i][j] == _value_pore)
        _pore_volume += std::pow(1 / (float)_size_CT, 2);
  std::cout << "_pore_volume = " << _pore_volume << std::endl;

  // init value
  _poro_value = _pore_volume;

  // init _upper_layer_bound
  std::vector<std::pair<int, int>> boundary_elements = BoundaryElements(_value_grain, data_refined);
  Real layer_volume = std::pow(1 / (float)_size_CT, 2) * boundary_elements.size();
  _upper_layer_bound = _pore_volume + layer_volume;
  std::cout << "_upper_layer_bound = " << _upper_layer_bound << std::endl;

  // init _lower_layer_bound
  boundary_elements = BoundaryElements(_value_pore, data_refined);
  layer_volume = std::pow(1 / (float)_size_CT, 2) * boundary_elements.size();
  _lower_layer_bound = _pore_volume - layer_volume;
  std::cout << "_lower_layer_bound = " << _lower_layer_bound << std::endl;

  // position along x or y axis for writing data file
  std::vector<Real> data_axis;
  for (int i = 0; i < _size_CT; ++i)
    data_axis.push_back(i * 1. / (float)_size_CT);
  // convert data to text
  std::stringstream ss;
  for (size_t i = 0; i < data_axis.size(); ++i)
    ss << data_axis[i] << " ";
  _data_axis_text = ss.str();
  // write file
  FileWriter(data_refined, _working_file_name);
}

void
PointValueFileWriter::execute()
{
  _old_poro_value = _poro_value;
  _poro_value = _system.point_value(_var_number, _point, false);

  std::cout << "_old_poro_value = " << _old_poro_value << std::endl;
  std::cout << "_poro_value = " << _poro_value << std::endl;

  /**
   * If we get exactly zero, we don't know if the locator couldn't find an element, or
   * if the solution is truly zero, more checking is needed.
   */
  if (MooseUtils::absoluteFuzzyEqual(_poro_value, 0.0))
  {
    auto pl = _subproblem.mesh().getPointLocator();
    pl->enable_out_of_mesh_mode();

    auto * elem = (*pl)(_point);
    auto elem_id = elem ? elem->id() : DofObject::invalid_id;
    gatherMin(elem_id);

    if (elem_id == DofObject::invalid_id)
      mooseError("No element located at ",
                 _point,
                 " in PointValueFileWriter Postprocessor named: ",
                 name());
  }
}

Real
PointValueFileWriter::getValue()
{
  // define precipitation
  bool precip = false;
  if (_poro_value - _old_poro_value < 0)
    precip = true;

  std::cout << "precip = " << precip << std::endl;
  std::cout << "_poro_value = " << _poro_value << std::endl;
  std::cout << "_lower_layer_bound = " << _lower_layer_bound << std::endl;
  std::cout << "_upper_layer_bound = " << _upper_layer_bound << std::endl;

  // write to run multiapp or not
  FILE * output_file = fopen(_multiapp_file_name.c_str(), "w");

  // don't run erosion if change of porosity is too low

  if (_poro_value > _lower_layer_bound && _poro_value < _upper_layer_bound)
  {
    fputs(std::to_string(0).c_str(), output_file);
    fclose(output_file);
    return _poro_value;
  }
  fputs(std::to_string(1).c_str(), output_file);
  fclose(output_file);

  std::cout << "running code for erosion..." << std::endl;

  // read the CTscan txt file and extract the information
  std::string line;
  std::ifstream myfile(_working_file_name);
  std::vector<std::vector<std::string>> data;
  if (myfile.is_open())
  {
    while (myfile.good())
    {
      getline(myfile, line);
      std::stringstream ss(line);
      std::istream_iterator<std::string> begin(ss);
      std::istream_iterator<std::string> end;
      std::vector<std::string> vstrings(begin, end);
      data.push_back(vstrings);
    }
    myfile.close();
  }
  else
    mooseError("Unable to open file");

  // keeping only necessary data
  data.erase(data.end() - 1);
  data.erase(data.begin(), data.begin() + 5);

  // how to check which elements are boundary, precip or disso
  std::string boundary_element_value = _value_grain;
  std::string new_value = _value_pore;
  if (precip == true)
  {
    boundary_element_value = _value_pore;
    new_value = _value_grain;
  }

  Real layer_volume;
  std::vector<std::pair<int, int>> boundary_elements;
  while (_pore_volume < 1. - 1e-10 && _pore_volume > 0. + 1e-10)
  {
    boundary_elements = BoundaryElements(boundary_element_value, data);

    // Calculating the volume of the boundary elements layer
    layer_volume = std::pow(1 / (float)_size_CT, 2) * boundary_elements.size();
    std::cout << "layer_volume = " << layer_volume << std::endl;

    // break of loop if layer is too big to remove
    if (precip == true)
    {
      if (_pore_volume - layer_volume <= _poro_value)
      {
        _lower_layer_bound = _pore_volume - layer_volume;
        std::cout << "_lower_layer_bound = " << _lower_layer_bound << std::endl;
        break;
      }
    }
    else if (_pore_volume + layer_volume > _poro_value)
    {
      _upper_layer_bound = _pore_volume + layer_volume;
      std::cout << "_upper_layer_bound = " << _upper_layer_bound << std::endl;
      _lower_layer_bound = _pore_volume;
      std::cout << "_lower_layer_bound = " << _lower_layer_bound << std::endl;
      break;
    }

    // assign new value to the boundary elements
    for (int i = 0; i < boundary_elements.size(); ++i)
      data[boundary_elements[i].first][boundary_elements[i].second] = new_value;

    // updating _pore_volume
    if (precip == true)
    {
      _upper_layer_bound = _pore_volume;
      std::cout << "_upper_layer_bound = " << _upper_layer_bound << std::endl;
      _pore_volume -= layer_volume;
    }
    else
    {
      _pore_volume += layer_volume;
    }
    std::cout << "_pore_volume = " << _pore_volume << std::endl;
  }

  // write file
  FileWriter(data, _working_file_name);

  std::cout << "... erosion done" << std::endl;

  return _poro_value;
}

void
PointValueFileWriter::FileWriter(std::vector<std::vector<std::string>> data, FileName file)
{
  // convert data to text
  std::vector<std::string> data_text;
  for (size_t i = 0; i < _size_CT; ++i)
  {
    std::stringstream ss;
    for (size_t j = 0; j < _size_CT; ++j)
    {
      ss << data[i][j] << " ";
    }
    data_text.push_back(ss.str());
  }

  // write text
  FILE * output_file = fopen(file.c_str(), "w");
  fputs("AXIS X\n", output_file);
  fputs(_data_axis_text.c_str(), output_file);
  fputs("\nAXIS Y\n", output_file);
  fputs(_data_axis_text.c_str(), output_file);
  fputs("\nDATA\n", output_file);
  for (size_t i = 0; i < _size_CT; ++i)
  {
    fputs(data_text[i].c_str(), output_file);
    fputs("\n", output_file);
  }
  fclose(output_file);
}

std::vector<std::pair<int, int>>
PointValueFileWriter::BoundaryElements(std::string boundary_element_value,
                                       std::vector<std::vector<std::string>> data)
{
  std::vector<std::pair<int, int>> boundary_elements;
  bool boundary;
  for (int i = 0; i < _size_CT; ++i)
  {
    for (int j = 0; j < _size_CT; ++j)
    {
      if (data[i][j] == boundary_element_value)
      {
        boundary = false;
        if (i - 1 >= 0)
          if (data[i - 1][j] != boundary_element_value)
            boundary = true;
        if (i + 1 < _size_CT)
          if (data[i + 1][j] != boundary_element_value)
            boundary = true;
        if (j - 1 >= 0)
          if (data[i][j - 1] != boundary_element_value)
            boundary = true;
        if (j + 1 < _size_CT)
          if (data[i][j + 1] != boundary_element_value)
            boundary = true;
        if (boundary == true &&
            std::find(boundary_elements.begin(), boundary_elements.end(), std::make_pair(i, j)) ==
                boundary_elements.end())
          boundary_elements.push_back(std::make_pair(i, j));
      }
    }
  }
  return boundary_elements;
}
