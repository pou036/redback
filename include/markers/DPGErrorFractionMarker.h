/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*                 (c) 2019 CSIRO                               */
/*               ALL RIGHTS RESERVED                            */
/*                                                              */
/*                Prepared by CSIRO                             */
/*                                                              */
/*        See COPYRIGHT for full restrictions                   */
/****************************************************************/
#ifndef DPGERRORFRACTIONMARKER_H
#define DPGERRORFRACTIONMARKER_H

#include "ErrorFractionMarker.h"

class DPGErrorFractionMarker;

template <>
InputParameters validParams<DPGErrorFractionMarker>();

class DPGErrorFractionMarker : public ErrorFractionMarker
{
public:
  DPGErrorFractionMarker(const InputParameters & parameters);

  virtual void markerSetup() override;

protected:
  virtual MarkerValue computeElementMarker() override;

  bool _is_ev2_supplied, _is_ev3_supplied;
  Real _mult_fact1, _mult_fact2, _mult_fact3;
  ErrorVector & _error_vector2;
  ErrorVector & _error_vector3;
};

#endif /* DPGERRORFRACTIONMARKER_H */
