#ifndef BEZIERTEST_H
#define BEZIERTEST_H

// CPPUnit includes
#include "cppunit/extensions/HelperMacros.h"

// Moose includes
#include "Bezier.h"

class BezierTest : public CppUnit::TestFixture
{

  CPPUNIT_TEST_SUITE(BezierTest);

  CPPUNIT_TEST(overstressTestQH0TensileStrength);
  CPPUNIT_TEST(overstressTestQH0NoTensileStrength);
  CPPUNIT_TEST(derivativeOverstressTest);

  CPPUNIT_TEST_SUITE_END();

public:
  BezierTest();
  ~BezierTest();

  void overstressTestQH0TensileStrength();
  void overstressTestQH0NoTensileStrength();
  void derivativeOverstressTest();
};

#endif // BEZIERTEST_H
