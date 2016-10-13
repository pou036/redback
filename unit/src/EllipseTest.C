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

CPPUNIT_TEST_SUITE_REGISTRATION(EllipseTest);

EllipseTest::EllipseTest()
{
}

EllipseTest::~EllipseTest()
{
}

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
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/2.0,
                                       /*y=*/1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/2.0,
                                       /*y=*/2.0);
  CPPUNIT_ASSERT(r == true);
  // top left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/-2.0,
                                       /*y=*/1.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/0.5,
                                       /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  // bottom left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/0.5,
                                       /*y=*/-1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/0.5,
                                       /*y=*/-1.5);
  CPPUNIT_ASSERT(r == true);
  // bottom right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/2.0,
                                       /*y=*/-1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/2.0,
                                       /*y=*/-2.0);
  CPPUNIT_ASSERT(r == true);
  // on horizontal axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/-1.0,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/0.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/2.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/3.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  // on ellipse's vertical axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/1.5,
                                       /*y=*/-2.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/1.5,
                                       /*y=*/-1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/1.5,
                                       /*y=*/1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/3.0,
                                       /*x=*/1.5,
                                       /*y=*/2.0);
  CPPUNIT_ASSERT(r == true);

  // Case: circle, p_c < 0
  // top left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.0,
                                       /*y=*/1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.0,
                                       /*y=*/2.0);
  CPPUNIT_ASSERT(r == true);
  // top right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/2.0,
                                       /*y=*/1.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/-0.5,
                                       /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  // bottom right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/-0.5,
                                       /*y=*/-1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/-0.5,
                                       /*y=*/-1.5);
  CPPUNIT_ASSERT(r == true);
  // bottom left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.0,
                                       /*y=*/-1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.0,
                                       /*y=*/-2.0);
  CPPUNIT_ASSERT(r == true);
  // on horizontal axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/1.0,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/-0.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/-3.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  // on ellipse's vertical axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.5,
                                       /*y=*/-2.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.5,
                                       /*y=*/-1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.5,
                                       /*y=*/1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.5,
                                       /*y=*/2.0);
  CPPUNIT_ASSERT(r == true);
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
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/2.0,
                                       /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/2.0,
                                       /*y=*/1.0);
  CPPUNIT_ASSERT(r == true);
  // top left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/-2.0,
                                       /*y=*/1.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/0.5,
                                       /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  // bottom left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/0.5,
                                       /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/0.5,
                                       /*y=*/-1.0);
  CPPUNIT_ASSERT(r == true);
  // bottom right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/2.0,
                                       /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/2.0,
                                       /*y=*/-1.0);
  CPPUNIT_ASSERT(r == true);
  // on horizontal axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/-1.0,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/0.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/2.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/3.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  // on ellipse's vertical axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/1.5,
                                       /*y=*/-2.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/1.5,
                                       /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/1.5,
                                       /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/3.0,
                                       /*x=*/1.5,
                                       /*y=*/2.0);
  CPPUNIT_ASSERT(r == true);

  // Case: ellipse, major axis horizontal, p_c < 0
  // top left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.0,
                                       /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.0,
                                       /*y=*/1.0);
  CPPUNIT_ASSERT(r == true);
  // top left right
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/2.0,
                                       /*y=*/1.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-0.5,
                                       /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  // bottom right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-0.5,
                                       /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-0.5,
                                       /*y=*/-1.0);
  CPPUNIT_ASSERT(r == true);
  // bottom left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.0,
                                       /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.0,
                                       /*y=*/-1.0);
  CPPUNIT_ASSERT(r == true);
  // on horizontal axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/1.0,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-0.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-3.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  // on ellipse's vertical axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.5,
                                       /*y=*/-2.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.5,
                                       /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.5,
                                       /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/0.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.5,
                                       /*y=*/2.0);
  CPPUNIT_ASSERT(r == true);
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
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/2.0,
                                       /*y=*/2.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/2.0,
                                       /*y=*/3.0);
  CPPUNIT_ASSERT(r == true);
  // top left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/1.3,
                                       /*y=*/3.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/1.3,
                                       /*y=*/2.0);
  CPPUNIT_ASSERT(r == false);
  // bottom left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/1.3,
                                       /*y=*/-2.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/1.3,
                                       /*y=*/-3.0);
  CPPUNIT_ASSERT(r == true);
  // bottom right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/2.0,
                                       /*y=*/-2.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/2.0,
                                       /*y=*/-3.0);
  CPPUNIT_ASSERT(r == true);
  // on horizontal axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/-1.0,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/0.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/2.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/3.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  // on ellipse's vertical axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/1.5,
                                       /*y=*/-2.5);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/1.5,
                                       /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/1.5,
                                       /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/3.0,
                                       /*x=*/1.5,
                                       /*y=*/2.5);
  CPPUNIT_ASSERT(r == true);

  // Case: ellipse, major axis vertical, p_c < 0
  // top left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.0,
                                       /*y=*/2.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.0,
                                       /*y=*/3.0);
  CPPUNIT_ASSERT(r == true);
  // top right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.3,
                                       /*y=*/3.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.3,
                                       /*y=*/2.0);
  CPPUNIT_ASSERT(r == false);
  // bottom right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.3,
                                       /*y=*/-2.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.3,
                                       /*y=*/-3.0);
  CPPUNIT_ASSERT(r == true);
  // bottom left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.0,
                                       /*y=*/-2.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.0,
                                       /*y=*/-3.0);
  CPPUNIT_ASSERT(r == true);
  // on horizontal axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/1.0,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-0.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-2.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-3.5,
                                       /*y=*/0.0);
  CPPUNIT_ASSERT(r == true);
  // on ellipse's vertical axis
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.5,
                                       /*y=*/-2.5);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.5,
                                       /*y=*/-0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.5,
                                       /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.5,
                                       /*p_c=*/-3.0,
                                       /*x=*/-1.5,
                                       /*y=*/2.5);
  CPPUNIT_ASSERT(r == true);
}

/**
 * Testing Ellipse::distanceCC
 * Case: circle
 */
void
EllipseTest::distanceCCTestCircle()
{
  Real d, x2, y2;

  // Case: circle, p_c < 0
  // top right quadrant
  d = Ellipse::distanceCC(/*m=*/1.0, /*p_c=*/-3.0, /*x1=*/1.5, /*y1=*/3.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3 * std::sqrt(2) - 1.5, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.5 / std::sqrt(2) - 1.5, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.5 / std::sqrt(2), y2, 1e-5);
  // top left quadrant
  d = Ellipse::distanceCC(/*m=*/1.0, /*p_c=*/-3.0, /*x1=*/-4.5, /*y1=*/3.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3 * std::sqrt(2) - 1.5, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5 / std::sqrt(2) - 1.5, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.5 / std::sqrt(2), y2, 1e-5);
  // bottom right quadrant
  d = Ellipse::distanceCC(/*m=*/1.0, /*p_c=*/-3.0, /*x1=*/1.5, /*y1=*/-3.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3 * std::sqrt(2) - 1.5, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.5 / std::sqrt(2) - 1.5, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5 / std::sqrt(2), y2, 1e-5);
  // bottom left quadrant
  d = Ellipse::distanceCC(/*m=*/1.0, /*p_c=*/-3.0, /*x1=*/-4.5, /*y1=*/-3.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(3 * std::sqrt(2) - 1.5, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5 / std::sqrt(2) - 1.5, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5 / std::sqrt(2), y2, 1e-5);
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
}

/**
 * Testing Ellipse::distanceCC
 * Case: ellipse, major axis horizontal
 */
void
EllipseTest::distanceCCTestMajorAxisHorizontal()
{
  Real d, x2, y2;

  // Case: ellipse, major axis horizontal, p_c < 0
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
 * Testing Ellipse::distanceCC
 * Case: ellipse, major axis vertical
 */
void
EllipseTest::distanceCCTestMajorAxisVertical()
{
  Real d, x2, y2;

  // Case: ellipse, major axis vertical, p_c < 0
  // top right quadrant
  d = Ellipse::distanceCC(/*m=*/1.5, /*p_c=*/-3.0, /*x1=*/-0.5, /*y1=*/2.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.2094051, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-0.650317, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.854209, y2, 1e-5);
  // top left quadrant
  d = Ellipse::distanceCC(/*m=*/1.5, /*p_c=*/-3.0, /*x1=*/-2.5, /*y1=*/2.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.2094051, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-2.349682, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.854209, y2, 1e-5);
  // bottom right quadrant
  d = Ellipse::distanceCC(/*m=*/1.5, /*p_c=*/-3.0, /*x1=*/-0.5, /*y1=*/-2.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.2094051, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-0.650317, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.854209, y2, 1e-5);
  // bottom left quadrant
  d = Ellipse::distanceCC(/*m=*/1.5, /*p_c=*/-3.0, /*x1=*/-2.5, /*y1=*/-2.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.2094051, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-2.349682, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.854209, y2, 1e-5);

  // on horizontal axis, left hand side of ellipse
  d = Ellipse::distanceCC(/*m=*/1.5, /*p_c=*/-3.0, /*x1=*/-4.0, /*y1=*/0.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-3.0, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, y2, 1e-5);
  // on horizontal axis, right hand side of ellipse
  d = Ellipse::distanceCC(/*m=*/1.5, /*p_c=*/-3.0, /*x1=*/1.0, /*y1=*/0.0, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.0, y2, 1e-5);
  // on vertical axis, below ellipse
  d = Ellipse::distanceCC(/*m=*/1.5, /*p_c=*/-3.0, /*x1=*/-1.5, /*y1=*/-2.5, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.25, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-2.25, y2, 1e-5);
  // on vertical axis, above ellipse
  d = Ellipse::distanceCC(/*m=*/1.5, /*p_c=*/-3.0, /*x1=*/-1.5, /*y1=*/2.5, x2, y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.25, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.5, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(2.25, y2, 1e-5);
}

/**
 * Testing Ellipse::distanceCCanisotropic
 * Case: rotated ellipse, major axis ~horizontal
 */
void
EllipseTest::distanceCCanisotropicTestMajorAxisHorizontal()
{
  Real d, x2, y2;

  d = Ellipse::distanceCCanisotropic(/*m=*/1.4,
                                     /*p_0=*/2.0,
                                     /*alpha=*/0.2,
                                     /*y0=*/2.0,
                                     /*y1*/ 1.5,
                                     x2,
                                     y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.340201, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.731422, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.291187, y2, 1e-5);
}

/**
 * Testing Ellipse::rotatePoint
 */
void
EllipseTest::rotatePointTest()
{
  Real z0, z1;
  Ellipse::rotatePoint(/*m=*/1.4,
                       /*p_0=*/2.0,
                       /*alpha=*/0.2,
                       /*forward=*/true,
                       /*y0=*/2.0,
                       /*y1*/ 1.5,
                       z0,
                       z1);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.47087, z0, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-0.72563, z1, 1e-5);
  Ellipse::rotatePoint(/*m=*/1.4,
                       /*p_0=*/2.0,
                       /*alpha=*/0.2,
                       /*forward=*/false,
                       /*y0=*/1.47087101353638,
                       /*y1*/ -0.725629700011281,
                       z0,
                       z1);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(2.0, z0, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.5, z1, 1e-5);
}

/**
 * Testing Ellipse::getDafaliasEllipseAxesAndCentre
 */
void
EllipseTest::getDafaliasEllipseAxesAndCentreTest()
{
  Real horizontal_axis, vertical_axis, center_p, center_q;
  Ellipse::getDafaliasEllipseAxesAndCentre(
    /*m=*/1.4, /*p_0=*/2.0, /*alpha=*/0.2, horizontal_axis, vertical_axis, center_p, center_q);

  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.4142135, horizontal_axis, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.979796, vertical_axis, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0, center_p, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.2, center_q, 1e-5);
}

/**
 * Testing Ellipse::distanceCCanisotropic
 * Case: rotated ellipse, major axis ~vertical
 */
void
EllipseTest::distanceCCanisotropicTestMajorAxisVertical()
{
  Real d, x2, y2;

  d = Ellipse::distanceCCanisotropic(/*m=*/0.4,
                                     /*p_0=*/2.0,
                                     /*alpha=*/0.2,
                                     /*y0=*/2.0,
                                     /*y1*/ 1.5,
                                     x2,
                                     y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.952959979, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.7821427634, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.57227647, y2, 1e-5);
}

/**
 * Testing Ellipse::isPointOutsideOfRotatedEllipse
 * Case: ellipse, major axis ~horizontal
 */
void
EllipseTest::isPointOutsideOfRotatedEllipseTestMajorAxisHorizontal()
{
  bool r;
  Real d, x2, y2;
  r = Ellipse::isPointOutsideOfRotatedEllipse(
    /*m=*/1.4, /*p_0=*/2.0, /*alpha=*/0.2, /*y0=*/2.0, /*y1*/ 1.5);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfRotatedEllipse(
    /*m=*/1.4, /*p_0=*/2.0, /*alpha=*/0.2, /*y0=*/1.5, /*y1*/ 1.51);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfRotatedEllipse(
    /*m=*/1.4, /*p_0=*/2.0, /*alpha=*/0.2, /*y0=*/1.5, /*y1*/ 1.49);
  CPPUNIT_ASSERT(r == false);
}

/**
 * Testing Ellipse::isPointOutsideOfRotatedEllipse
 * Case: ellipse, major axis ~vertical
 */
void
EllipseTest::isPointOutsideOfRotatedEllipseTestMajorAxisVertical()
{
  bool r;
  Real d, x2, y2;
  r = Ellipse::isPointOutsideOfRotatedEllipse(
    /*m=*/0.4, /*p_0=*/2.0, /*alpha=*/0.2, /*y0=*/1.53, /*y1*/ 0.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfRotatedEllipse(
    /*m=*/0.4, /*p_0=*/2.0, /*alpha=*/0.2, /*y0=*/1.49, /*y1*/ 0.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfRotatedEllipse(
    /*m=*/0.4, /*p_0=*/2.0, /*alpha=*/0.2, /*y0=*/0.5, /*y1*/ 0.41);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfRotatedEllipse(
    /*m=*/0.4, /*p_0=*/2.0, /*alpha=*/0.2, /*y0=*/0.5, /*y1*/ 0.39);
  CPPUNIT_ASSERT(r == false);
}
