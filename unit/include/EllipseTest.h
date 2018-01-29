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

// CPPUnit includes
#include "cppunit/extensions/HelperMacros.h"

// Moose includes
#include "Ellipse.h"

class EllipseTest : public CppUnit::TestFixture
{

  CPPUNIT_TEST_SUITE(EllipseTest);

  CPPUNIT_TEST(distanceCCTestCircle);
  CPPUNIT_TEST(distanceCCTestMajorAxisHorizontal);
  CPPUNIT_TEST(distanceCCTestMajorAxisVertical);
  CPPUNIT_TEST(isPointOutsideOfEllipseTestCircle);
  CPPUNIT_TEST(isPointOutsideOfEllipseTestMajorAxisHorizontal);
  CPPUNIT_TEST(isPointOutsideOfEllipseTestMajorAxisVertical);
  CPPUNIT_TEST(distanceCCanisotropicTestMajorAxisHorizontal);
  CPPUNIT_TEST(distanceCCanisotropicTestMajorAxisVertical);
  CPPUNIT_TEST(rotatePointTest);
  CPPUNIT_TEST(getDafaliasEllipseAxesAndCentreTest);
  CPPUNIT_TEST(isPointOutsideOfRotatedEllipseTestMajorAxisHorizontal);
  CPPUNIT_TEST(isPointOutsideOfRotatedEllipseTestMajorAxisVertical);

  CPPUNIT_TEST_SUITE_END();

public:
  EllipseTest();
  ~EllipseTest();

  void distanceCCTestCircle();
  void distanceCCTestMajorAxisHorizontal();
  void distanceCCTestMajorAxisVertical();
  void distanceCCanisotropicTestMajorAxisHorizontal();
  void distanceCCanisotropicTestMajorAxisVertical();
  void rotatePointTest();
  void getDafaliasEllipseAxesAndCentreTest();
  void isPointOutsideOfEllipseTestCircle();
  void isPointOutsideOfEllipseTestMajorAxisHorizontal();
  void isPointOutsideOfEllipseTestMajorAxisVertical();
  void isPointOutsideOfRotatedEllipseTestMajorAxisHorizontal();
  void isPointOutsideOfRotatedEllipseTestMajorAxisVertical();
};

#endif // ELLIPSETEST_H
