//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef TIMESFILEUSEROBJECT_H
#define TIMESFILEUSEROBJECT_H

#include "GeneralUserObject.h"

// Forward declarations
// class GriddedData;

class TimesFileUserObject;

template <>
InputParameters validParams<TimesFileUserObject>();

/**
 * Computes the average value of a variable on each block
 */
class TimesFileUserObject : public GeneralUserObject
{
public:
  TimesFileUserObject(const InputParameters & parameters);

  virtual void execute() override;
  virtual void initialize() override {}
  virtual void finalize() override {}

private:
  const PostprocessorValue & _val;
  const PostprocessorValue & _val_old;
  FileName _times_file;
  FileName _perm_file;
};

#endif
