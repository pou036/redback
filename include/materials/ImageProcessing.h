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

#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include "Material.h"

// Forward Declarations
class ImageProcessing;

template <>
InputParameters validParams<ImageProcessing>();

/**
 * This material automatically declares as material properties whatever is
 *passed to it
 * through the parameters 'prop_names' and uses the Functions from 'prop_values'
 *as the values
 * for those properties.
 *
 * This is not meant to be used in a production capacity... and instead is meant
 *to be used
 * during development phases for ultimate flexibility.
 */
class ImageProcessing : public Material
{
public:
  ImageProcessing(const InputParameters & parameters);

protected:
  virtual void initQpStatefulProperties();
  virtual void computeQpProperties();

  FunctionName _func;
  std::vector<Function *> _function;
  FILE * idFile;

private:
  /**
   * A helper method for evaluating the functions
   */
  void computeQpFunctions();
};

#endif // IMAGEPROCESSING_H
