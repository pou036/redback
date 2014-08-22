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

#ifndef ELLIPSETEST_H
#define ELLIPSETEST_H

//CPPUnit includes
#include "cppunit/extensions/HelperMacros.h"

// Moose includes
#include "Ellipse.h"

class EllipseTest : public CppUnit::TestFixture
{

  CPPUNIT_TEST_SUITE( EllipseTest );

  CPPUNIT_TEST( distanceCCTest );
  CPPUNIT_TEST( isPointOutsideOfEllipseTest );

  CPPUNIT_TEST_SUITE_END();

public:
  EllipseTest();
  ~EllipseTest();

  void distanceCCTest();
  void isPointOutsideOfEllipseTest();

};

#endif  // ELLIPSETEST_H
