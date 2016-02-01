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

#ifndef REDBACKMECHMATERIALELASTIC_H
#define REDBACKMECHMATERIALELASTIC_H

#include "RedbackMechMaterial.h"

// Forward Declarations
class RedbackMechMaterial;

template <>
InputParameters validParams<RedbackMechMaterial>();

class RedbackMechMaterialElastic : public RedbackMechMaterial
{
public:
  RedbackMechMaterialElastic(const InputParameters & parameters);

protected:
  void returnMap(const RankTwoTensor &,
                 const RankTwoTensor &,
                 const RankFourTensor &,
                 RankTwoTensor &,
                 RankTwoTensor &,
                 Real &,
                 Real &);

};

#endif // REDBACKMECHMATERIALELASTIC_H
