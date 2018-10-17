//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "TimesFileUserObject.h"

template <>
InputParameters
validParams<TimesFileUserObject>()
{
  InputParameters params = validParams<GeneralUserObject>();
  params.addRequiredParam<PostprocessorName>(
      "postprocessor_value", "The name of the postprocessor that holds the current value.");
  params.addRequiredParam<FileName>("times_file", "Name of the txt file to write the time values");
  params.addRequiredParam<FileName>("perm_file",
                                    "Name of the txt file to write the permeability values");
  params.addClassDescription("Write the times in a txt file when the postprocessor changes value.");
  return params;
}

TimesFileUserObject::TimesFileUserObject(const InputParameters & params)
  : GeneralUserObject(params),
    _val(getPostprocessorValue("postprocessor_value")),
    _val_old(getPostprocessorValueOld("postprocessor_value")),
    _times_file(getParam<FileName>("times_file")),
    _perm_file(getParam<FileName>("perm_file"))
{
  FILE * output_file = fopen(_times_file.c_str(), "w");
  fputs("", output_file);
  fclose(output_file);
  output_file = fopen(_perm_file.c_str(), "w");
  fputs("", output_file);
  fclose(output_file);
}

void
TimesFileUserObject::execute()
{
  if (std::abs(_val - _val_old) > 1e-5)
  {
    FILE * output_file = fopen(_times_file.c_str(), "a");
    fputs(" ", output_file);
    fputs(std::to_string(_t).c_str(), output_file);
    fclose(output_file);
    output_file = fopen(_perm_file.c_str(), "a");
    fputs(" ", output_file);
    fputs(std::to_string(_val).c_str(), output_file);
    fclose(output_file);
  }
}
