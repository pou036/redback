#ifndef MISESSTRESSAUX_H
#define MISESSTRESSAUX_H

#include "AuxKernel.h"
#include "RedbackMaterial.h"

//Forward declarations
class MisesStressAux;

template<>
InputParameters validParams<MisesStressAux>();


/**
 * Obtains equivalent plastic strain for output
 */
class MisesStressAux : public AuxKernel
{
public:
  MisesStressAux(const std::string & name, InputParameters parameters);
  virtual ~MisesStressAux() {}

protected:
  virtual Real computeValue();

private:
  MaterialProperty<Real> & _equivalent_stress;
};

#endif // MISESSTRESSAUX_H
