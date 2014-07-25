#ifndef MISESSTRAINAUX_H
#define MISESSTRAINAUX_H

#include "AuxKernel.h"
#include "RedbackMaterial.h"

//Forward declarations
class MisesStrainAux;

template<>
InputParameters validParams<MisesStrainAux>();


/**
 * Obtains equivalent plastic strain for output
 */
class MisesStrainAux : public AuxKernel
{
public:
  MisesStrainAux(const std::string & name, InputParameters parameters);
  virtual ~MisesStrainAux() {}

protected:
  virtual Real computeValue();

private:
  MaterialProperty<Real> & _mises_strain;
};

#endif // MISESSTRAINAUX_H
