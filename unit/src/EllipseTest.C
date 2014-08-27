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

#include "EllipseTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( EllipseTest );

EllipseTest::EllipseTest()
{}

EllipseTest::~EllipseTest()
{}

/**
 * Testing Ellipse::isPointOutsideOfEllipse
 * Case: circle
 */
void
EllipseTest::isPointOutsideOfEllipseTestCircle()
{
  bool r;
  Real d, x2, y2;

  // Case: circle, p_c > 0
  // top right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/2.0, /*y=*/1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/2.0, /*y=*/2.0);
  CPPUNIT_ASSERT(r == true);
  // top left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/-2.0, /*y=*/1.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/0.5, /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  // bottom left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/0.5, /*y=*/-1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/0.5, /*y=*/-1.5);
  CPPUNIT_ASSERT(r == true);
  // bottom right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/2.0, /*y=*/-1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/2.0, /*y=*/-2.0);
  CPPUNIT_ASSERT(r == true);
  // on horizontal axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/-1.0, /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/0.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/2.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/3.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  // on ellipse's vertical axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/1.5, /*y=*/-2.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/1.5, /*y=*/-1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/1.5, /*y=*/1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/3.0, /*x=*/1.5, /*y=*/2.0);
  CPPUNIT_ASSERT(r == true);

  // Case: circle, p_c < 0
  // top left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/2.0);
  CPPUNIT_ASSERT(r == true);
  // top right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/2.0, /*y=*/1.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-0.5, /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  // bottom right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-0.5, /*y=*/-1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-0.5, /*y=*/-1.5);
  CPPUNIT_ASSERT(r == true);
  // bottom left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/-1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/-2.0);
  CPPUNIT_ASSERT(r == true);
  // on horizontal axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/1.0, /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-0.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-2.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-3.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  // on ellipse's vertical axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-1.5, /*y=*/-2.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-1.5, /*y=*/-1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-1.5, /*y=*/1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-1.5, /*y=*/2.0);
  CPPUNIT_ASSERT(r == true);

  //std::cout << "is point outside ellipse? " << r << std::endl << std::endl;
}

/**
 * Testing Ellipse::isPointOutsideOfEllipse
 * Case: ellipse, major axis horizontal
 */
void
EllipseTest::isPointOutsideOfEllipseTestMajorAxisHorizontal()
{
  bool r;
  Real d, x2, y2;

  // Case: ellipse, major axis horizontal, p_c > 0
  // top right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/2.0, /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/2.0, /*y=*/1.0);
  CPPUNIT_ASSERT(r == true);
  // top left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/-2.0, /*y=*/1.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/0.5, /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  // bottom left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/0.5, /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/0.5, /*y=*/-1.0);
  CPPUNIT_ASSERT(r == true);
  // bottom right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/2.0, /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/2.0, /*y=*/-1.0);
  CPPUNIT_ASSERT(r == true);
  // on horizontal axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/-1.0, /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/0.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/2.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/3.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  // on ellipse's vertical axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/1.5, /*y=*/-2.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/1.5, /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/1.5, /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/3.0, /*x=*/1.5, /*y=*/2.0);
  CPPUNIT_ASSERT(r == true);

  // Case: ellipse, major axis horizontal, p_c < 0
  // top left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/1.0);
  CPPUNIT_ASSERT(r == true);
  // top left right
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/2.0, /*y=*/1.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/-0.5, /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  // bottom right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/-0.5, /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/-0.5, /*y=*/-1.0);
  CPPUNIT_ASSERT(r == true);
  // bottom left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/-1.0);
  CPPUNIT_ASSERT(r == true);
  // on horizontal axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/1.0, /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/-0.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/-2.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/-3.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  // on ellipse's vertical axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/-1.5, /*y=*/-2.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/-1.5, /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/-1.5, /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5, /*p_c=*/-3.0, /*x=*/-1.5, /*y=*/2.0);
  CPPUNIT_ASSERT(r == true);

  //std::cout << "is point outside ellipse? " << r << std::endl << std::endl;
}

/**
 * Testing Ellipse::isPointOutsideOfEllipse
 * Case: ellipse, major axis vertical
 */
void
EllipseTest::isPointOutsideOfEllipseTestMajorAxisVertical()
{
  bool r;
  Real d, x2, y2;

  // Case: ellipse, major axis vertical, p_c > 0
  // top right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/2.0, /*y=*/2.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/2.0, /*y=*/3.0);
  CPPUNIT_ASSERT(r == true);
  // top left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/1.3, /*y=*/3.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/1.3, /*y=*/2.0);
  CPPUNIT_ASSERT(r == false);
  // bottom left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/1.3, /*y=*/-2.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/1.3, /*y=*/-3.0);
  CPPUNIT_ASSERT(r == true);
  // bottom right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/2.0, /*y=*/-2.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/2.0, /*y=*/-3.0);
  CPPUNIT_ASSERT(r == true);
  // on horizontal axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/-1.0, /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/0.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/2.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/3.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  // on ellipse's vertical axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/1.5, /*y=*/-2.5);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/1.5, /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/1.5, /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/3.0, /*x=*/1.5, /*y=*/2.5);
  CPPUNIT_ASSERT(r == true);

  // Case: ellipse, major axis vertical, p_c < 0
  // top left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/2.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/3.0);
  CPPUNIT_ASSERT(r == true);
  // top right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-1.3, /*y=*/3.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-1.3, /*y=*/2.0);
  CPPUNIT_ASSERT(r == false);
  // bottom right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-1.3, /*y=*/-2.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-1.3, /*y=*/-3.0);
  CPPUNIT_ASSERT(r == true);
  // bottom left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/-2.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/-3.0);
  CPPUNIT_ASSERT(r == true);
  // on horizontal axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/1.0, /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-0.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-2.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-3.5, /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  // on ellipse's vertical axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-1.5, /*y=*/-2.5);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-1.5, /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-1.5, /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5, /*p_c=*/-3.0, /*x=*/-1.5, /*y=*/2.5);
  CPPUNIT_ASSERT(r == true);

  //std::cout << "is point outside ellipse? " << r << std::endl << std::endl;
}

/**
 * Testing Ellipse::isPointOutsideOfEllipse
 * Case: circle
 */
void
EllipseTest::distanceCCTestCircle()
{
  Real d, x2, y2;

  // Case: circle, p_c < 0
  // top right quadrant
  d = Ellipse::distanceCC(/*m=*/1.0, /*p_c=*/-3.0, /*x1=*/1.5, /*y1=*/3.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3*std::sqrt(2) - 1.5, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.5/std::sqrt(2) - 1.5, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.5/std::sqrt(2), y2, 1e-5);
  // top left quadrant
  d = Ellipse::distanceCC(/*m=*/1.0, /*p_c=*/-3.0, /*x1=*/-4.5, /*y1=*/3.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3*std::sqrt(2) - 1.5, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5/std::sqrt(2) - 1.5, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.5/std::sqrt(2), y2, 1e-5);
  // bottom right quadrant
  d = Ellipse::distanceCC(/*m=*/1.0, /*p_c=*/-3.0, /*x1=*/1.5, /*y1=*/-3.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3*std::sqrt(2) - 1.5, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.5/std::sqrt(2) - 1.5, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5/std::sqrt(2), y2, 1e-5);
  // bottom left quadrant
  d = Ellipse::distanceCC(/*m=*/1.0, /*p_c=*/-3.0, /*x1=*/-4.5, /*y1=*/-3.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3*std::sqrt(2) - 1.5, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5/std::sqrt(2) - 1.5, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5/std::sqrt(2), y2, 1e-5);
  // on horizontal axis, left hand side of ellipse
  d = Ellipse::distanceCC(/*m=*/1.0, /*p_c=*/-3.0, /*x1=*/-4.0, /*y1=*/0.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-3.0, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, y2, 1e-5);
  // on horizontal axis, right hand side of ellipse
  d = Ellipse::distanceCC(/*m=*/1.0, /*p_c=*/-3.0, /*x1=*/1.0, /*y1=*/0.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, y2, 1e-5);
  // on vertical axis, below ellipse
  d = Ellipse::distanceCC(/*m=*/1.0, /*p_c=*/-3.0, /*x1=*/-1.5, /*y1=*/-2.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.5, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5, y2, 1e-5);
  // on vertical axis, above ellipse
  d = Ellipse::distanceCC(/*m=*/1.0, /*p_c=*/-3.0, /*x1=*/-1.5, /*y1=*/2.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.5, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.5, y2, 1e-5);

  /*std::cout << "distance to the ellipse: " << d << std::endl;
  std::cout << "projection point on ellipse: coord(0)=" << x2 << std::endl;
  std::cout << "projection point on ellipse: coord(0)=" << y2 << std::endl;*/
}

/**
 * Testing Ellipse::isPointOutsideOfEllipse
 * Case: ellipse, major axis horizontal
 */
void
EllipseTest::distanceCCTestMajorAxisHorizontal()
{
  Real d, x2, y2;

  // Case: circle, p_c < 0
  // top right quadrant
  d = Ellipse::distanceCC(/*m=*/0.5, /*p_c=*/-3.0, /*x1=*/1.5, /*y1=*/3.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3.1210069, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-0.282058, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.437784, y2, 1e-5);
  // top left quadrant
  d = Ellipse::distanceCC(/*m=*/0.5, /*p_c=*/-3.0, /*x1=*/-4.5, /*y1=*/3.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3.1210069, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-2.717941, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.437784, y2, 1e-5);
  // bottom right quadrant
  d = Ellipse::distanceCC(/*m=*/0.5, /*p_c=*/-3.0, /*x1=*/1.5, /*y1=*/-3.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3.1210069, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-0.282058, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-0.437784, y2, 1e-5);
  // bottom left quadrant
  d = Ellipse::distanceCC(/*m=*/0.5, /*p_c=*/-3.0, /*x1=*/-4.5, /*y1=*/-3.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3.1210069, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-2.717941, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-0.437784, y2, 1e-5);
  // on horizontal axis, left hand side of ellipse
  d = Ellipse::distanceCC(/*m=*/0.5, /*p_c=*/-3.0, /*x1=*/-4.0, /*y1=*/0.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-3.0, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, y2, 1e-5);
  // on horizontal axis, right hand side of ellipse
  d = Ellipse::distanceCC(/*m=*/0.5, /*p_c=*/-3.0, /*x1=*/1.0, /*y1=*/0.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, y2, 1e-5);
  // on vertical axis, below ellipse
  d = Ellipse::distanceCC(/*m=*/0.5, /*p_c=*/-3.0, /*x1=*/-1.5, /*y1=*/-1.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.25, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-0.75, y2, 1e-5);
  // on vertical axis, above ellipse
  d = Ellipse::distanceCC(/*m=*/0.5, /*p_c=*/-3.0, /*x1=*/-1.5, /*y1=*/1.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.25, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.75, y2, 1e-5);
}

/**
 * Testing Ellipse::isPointOutsideOfEllipse
 * Case: ellipse, major axis vertical
 */
void
EllipseTest::distanceCCTestMajorAxisVertical()
{
  Real d, x2, y2;

  CPPUNIT_ASSERT_DOUBLES_EQUAL(3.1210069, 3, 1e-5);
  // TODO
}
