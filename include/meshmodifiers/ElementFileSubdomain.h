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

#ifndef ELEMENTFILESUBDOMAIN_H
#define ELEMENTFILESUBDOMAIN_H

// MOOSE includes
#include "MeshModifier.h"

// Forward declerations
class ElementFileSubdomain;

template <>
InputParameters validParams<ElementFileSubdomain>();

/**
 * MeshModifier for assigning subdomain IDs of all elements
 */
class ElementFileSubdomain : public MeshModifier
{
public:
  /**
   * Class constructor
   * @param parameters The input parameters
   */
  ElementFileSubdomain(const InputParameters & parameters);

  /**
   * Class destructor
   */
  virtual ~ElementFileSubdomain();

  /**
   * Perform the actual element subdomain ID assignment
   */
  virtual void modify();
};

#endif // ELEMENTFILESUBDOMAIN_H
