#ifndef MECHDISSIPATIONAUX_H
#define MECHDISSIPATIONAUX_H

#include "AuxKernel.h"
#include "DimensionlessRock.h"

//Forward declarations
class MechDissipationAux;

template<>
InputParameters validParams<MechDissipationAux>();


/**
 * Obtains equivalent plastic strain for output
 */
class MechDissipationAux : public AuxKernel
{
public:
  MechDissipationAux(const std::string & name, InputParameters parameters);
  virtual ~MechDissipationAux() {}

protected:
  virtual Real computeValue();

private:
  MaterialProperty<Real> & _mechanical_dissipation;
};

#endif // MECHDISSIPATIONAUX_H
