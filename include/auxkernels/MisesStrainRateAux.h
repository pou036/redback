#ifndef MISESSTRAINRATEAUX_H
#define MISESSTRAINRATEAUX_H

#include "AuxKernel.h"
#include "RedbackMaterial.h"

//Forward declarations
class MisesStrainRateAux;

template<>
InputParameters validParams<MisesStrainRateAux>();


/**
 * Obtains equivalent plastic strain for output
 */
class MisesStrainRateAux : public AuxKernel
{
public:
  MisesStrainRateAux(const std::string & name, InputParameters parameters);
  virtual ~MisesStrainRateAux() {}

protected:
  virtual Real computeValue();

private:
  MaterialProperty<Real> & _mises_strain_rate;
};

#endif // MISESSTRAINRATEAUX_H
