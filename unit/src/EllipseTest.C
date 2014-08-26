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

void
EllipseTest::isPointOutsideOfEllipseTest()
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

  // Case: circle, p_c < 0
  // top right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/2.0);
  CPPUNIT_ASSERT(r == true);
  // top left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/+2.0, /*y=*/1.0);
  CPPUNIT_ASSERT(r == true);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-0.5, /*y=*/0.5);
  CPPUNIT_ASSERT(r == false);
  // bottom left quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-0.5, /*y=*/-1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-0.5, /*y=*/-1.5);
  CPPUNIT_ASSERT(r == true);
  // bottom right quadrant
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/-1.0);
  CPPUNIT_ASSERT(r == false);
  r = Ellipse::isPointOutsideOfEllipse(/*m=*/1.0, /*p_c=*/-3.0, /*x=*/-2.0, /*y=*/-2.0);
  CPPUNIT_ASSERT(r == true);

  //std::cout << "is point outside ellipse? " << r << std::endl << std::endl;
}

void
EllipseTest::distanceCCTest()
{
  Real d, x2, y2;

  d = Ellipse::distanceCC(/*m=*/1.0, /*p_c=*/-3.0, /*x1=*/-2.0, /*y1=*/1.0, /*x2=*/x2, /*y2=*/y2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(0.381966, d, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(-2.17082, x2, 1e-5);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(1.34164, y2, 1e-5);


  /*std::cout << "distance to the ellipse: " << d << std::endl;
  std::cout << "projection point on ellipse: coord(0)=" << x2 << std::endl;
  std::cout << "projection point on ellipse: coord(0)=" << y2 << std::endl;*/


}
