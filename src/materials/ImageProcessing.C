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

#include "ImageProcessing.h"
#include "Function.h"
#include <fstream>

template <>
InputParameters
validParams<ImageProcessing>()
{
  InputParameters params = validParams<Material>();
  params.addRequiredParam<FunctionName>("function", "Name of the function");
  return params;
}

ImageProcessing::ImageProcessing(const InputParameters & parameters) :
    Material(parameters), _func(getParam<FunctionName>("function"))
{
  _function.resize(1);
  _function[ 0 ] = &getFunctionByName(_func);
  idFile = fopen("idfile.txt", "w");
  fputs("", idFile);
  fclose(idFile);
}

void
ImageProcessing::initQpStatefulProperties()
{
  computeQpFunctions();
}

void
ImageProcessing::computeQpProperties()
{
  computeQpFunctions();
}

void
ImageProcessing::computeQpFunctions()
{
  if (_t_step == 1 && (*_function[ 0 ]).value(_t, _q_point[ _qp ]) == 0)
  {
    idFile = fopen("idfile.txt", "a");
    std::ostringstream convert; // stream used for the conversion
    convert << _current_elem->id();
    fputs(convert.str().c_str(), idFile);
    fputs(" ", idFile);
    fclose(idFile);
  }
}
