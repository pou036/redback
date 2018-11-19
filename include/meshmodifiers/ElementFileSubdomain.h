/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
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
