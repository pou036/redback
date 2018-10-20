#include "BezierTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(BezierTest);

BezierTest::BezierTest() {}

BezierTest::~BezierTest() {}

/**
 * Testing Bezier::getOverstress for q_H=0, tensile strength
 */
void
BezierTest::overstressTestQH0TensileStrength()
{
  bool is_plastic;
  Real p_y, q_y, s, t;
  int quadrant;
  Real p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c, alpha_t, beta_t;
  p_H = -0.1;
  q_H = 0;
  p_M = -0.6;
  q_M = 0.9;
  p_t = 0.1;
  p_c = -1;
  alpha_c = 0.3;
  beta_c = 0.8;
  alpha_t = 1.3;
  beta_t = 1.8;

  // On the contractant side
  // Along the p axis
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c, alpha_t,
      beta_t, /*p=*/-1.9, /*q=*/0., is_plastic, s, p_y, q_y, quadrant, t);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong is_plastic", is_plastic==true);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong quadrant", quadrant==1);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong overstress s", 1, s, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong parametric t", 0, t, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong p_y", -1, p_y, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong q_y", 0, q_y, 1e-5);
  // Not along the p axis
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c, alpha_t,
      beta_t, /*p=*/-1.9, /*q=*/0.5, is_plastic, s, p_y, q_y, quadrant, t);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong is_plastic", is_plastic==true);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong quadrant", quadrant==1);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong overstress s", 1.07933981695, s, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong parametric t", 0.196990451208, t, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong p_y", -0.965659371943, p_y, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong q_y", 0.2404609366510, q_y, 1e-10);
  // close to the junction with dilatant quadrant
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c, alpha_t,
      beta_t, /*p=*/-1.1000001, /*q=*/1.8, is_plastic, s, p_y, q_y, quadrant, t);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong is_plastic", is_plastic==true);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong quadrant", quadrant==1);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong overstress s", 1, s, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong parametric t", 0.999999745011, t, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong p_y", -0.60000005, p_y, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong q_y", 0.9, q_y, 1e-10);

  // In between quadrants
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c, alpha_t,
      beta_t, /*p=*/-1.1, /*q=*/1.8, is_plastic, s, p_y, q_y, quadrant, t);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong is_plastic", is_plastic==true);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong quadrant", quadrant==0);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong overstress s", 1, s, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong parametric t", 0, t, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong p_y", -0.6, p_y, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong q_y", 0.9, q_y, 1e-10);

  // On the dilatant (tension) side
  //close to the junction with contractant quadrant
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c, alpha_t,
      beta_t, /*p=*/-1.1, /*q=*/1.8000001, is_plastic, s, p_y, q_y, quadrant, t);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong is_plastic", is_plastic==true);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong quadrant", quadrant==2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong overstress s", 1.00000011111, s, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong parametric t", 1.86805439957e-08, t, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong p_y", -0.599999972222, p_y, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong q_y", 0.9, q_y, 1e-10);
  // Along the p axis
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c, alpha_t,
      beta_t, /*p=*/0.2, /*q=*/0., is_plastic, s, p_y, q_y, quadrant, t);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong is_plastic", is_plastic==true);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong quadrant", quadrant==2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong overstress s", 0.5, s, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong parametric t", 1, t, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong p_y", 0.1, p_y, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong q_y", 0, q_y, 1e-10);
  // Not along the p axis
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c, alpha_t,
      beta_t, /*p=*/0.2, /*q=*/0.5, is_plastic, s, p_y, q_y, quadrant, t);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong is_plastic", is_plastic==true);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong quadrant", quadrant==2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong overstress s", 0.591936805721, s, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong parametric t", 0.864039346482, t, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong p_y", 0.0884496915467, p_y, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong q_y", 0.314082819244, q_y, 1e-10);

  //std::cout<< std::endl<<"DEBUG: is_plastic="<<is_plastic<<", s="<<s<<", p_y="<<p_y<<", q_y="<<q_y<<", quadrant="<<quadrant<<", t="<<t<<std::endl;
}

void
BezierTest::overstressTestQH0NoTensileStrength()
{
  bool is_plastic;
  Real p_y, q_y, s, t;
  int quadrant;
  Real p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c, alpha_t, beta_t;
  p_H = 0;
  q_H = 0;
  p_M = -0.6;
  q_M = 0.9;
  p_t = 0;
  p_c = -1;
  alpha_c = 0.3;
  beta_c = 0.8;
  alpha_t = 1.3;
  beta_t = 1.8;

  // On the contractant side
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c, alpha_t,
      beta_t, /*p=*/-2, /*q=*/0, is_plastic, s, p_y, q_y, quadrant, t);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong is_plastic", is_plastic==true);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong quadrant", quadrant==1);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong overstress s", 1., s, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong parametric t", 0., t, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong p_y", -1., p_y, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong q_y", 0., q_y, 1e-10);

  // On the dilatant side
  // Along p axis
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c, alpha_t,
      beta_t, /*p=*/1, /*q=*/0, is_plastic, s, p_y, q_y, quadrant, t);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong is_plastic", is_plastic==true);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong quadrant", quadrant==2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong overstress s", std::numeric_limits<Real>::infinity(), s, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong parametric t", 1., t, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong p_y", 0., p_y, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong q_y", 0., q_y, 1e-10);
  // At origin
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c, alpha_t,
      beta_t, /*p=*/0, /*q=*/0, is_plastic, s, p_y, q_y, quadrant, t);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong is_plastic", is_plastic==false);
  // Along q axis
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c, alpha_t,
      beta_t, /*p=*/0, /*q=*/1, is_plastic, s, p_y, q_y, quadrant, t);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong is_plastic", is_plastic==true);
  CPPUNIT_ASSERT_MESSAGE("overstressTest, wrong quadrant", quadrant==2);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong overstress s", std::numeric_limits<Real>::infinity(), s, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong parametric t", 1., t, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong p_y", 0., p_y, 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("overstressTest, wrong q_y", 0., q_y, 1e-10);
}

void
BezierTest::derivativesOverstressTest()
{
  bool is_plastic;
  Real p_y, q_y, s, t, p, q;
  int quadrant;
  Real p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c, alpha_t, beta_t;
  p_H = -0.1;
  q_H = 0;
  p_M = -0.6;
  q_M = 0.9;
  p_t = 0.1;
  p_c = -1;
  alpha_c = 0.3;
  beta_c = 0.8;
  alpha_t = 1.3;
  beta_t = 1.8;
  Real derivatives[5];

  // Testing
  /*Real dp = 1e-5;
  Real dq = 1e-5;
  Real s1, s2, ds_dp, ds_dq;
  std::cout << std::fixed;
  std::cout << std::setprecision(12);*/

  // On the contractant side
  // Along the p axis
  p = -1.9;
  q = 0.;
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c,
      alpha_t, beta_t, p, q, is_plastic, s, p_y, q_y, quadrant, t);
  Bezier::getDerivativeOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c,
      beta_c, alpha_t, beta_t, p, q, is_plastic, s,
      p_y, q_y, quadrant, t, derivatives);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong ds_dp, case 1a", -1.11111111111111, derivatives[0], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong ds_dq, case 1a", 0., derivatives[1], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dp2, case 1a", 0., derivatives[2], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dq2, case 1a", 0.805852690672, derivatives[3], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dpdq, case 1a", 0., derivatives[4], 1e-10);

  // Not along the p axis
  p = -1.9;
  q = 0.5;
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c,
      alpha_t, beta_t, p, q, is_plastic, s, p_y, q_y, quadrant, t);
  Bezier::getDerivativeOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c,
      beta_c, alpha_t, beta_t, p, q, is_plastic, s,
      p_y, q_y, quadrant, t, derivatives);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong ds_dp, case 1b", -1.076781552305, derivatives[0], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong ds_dq, case 1b", 0.282266045610, derivatives[1], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dp2, case 1a", 0.0294423616955, derivatives[2], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dq2, case 1a", 0.381573007574, derivatives[3], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dpdq, case 1a", 0.105992502104, derivatives[4], 1e-10);

  // In between quadrants
  p = -1.1;
  q = 1.8;
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c,
      alpha_t, beta_t, p, q, is_plastic, s, p_y, q_y, quadrant, t);
  Bezier::getDerivativeOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c,
      beta_c, alpha_t, beta_t, p, q, is_plastic, s,
      p_y, q_y, quadrant, t, derivatives);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong ds_dp, case 0", 0., derivatives[0], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong ds_dq, case 0",  1.11111111111111, derivatives[1], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dp2, case 0",  0.0265482166267, derivatives[2], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dq2, case 0",  0.00819389402057, derivatives[3], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dpdq, case 0",  0.014749009237, derivatives[4], 1e-10);

  // On the dilatant (tension) side
  // Along the p axis
  p = 1.;
  q = 0.;
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c,
      alpha_t, beta_t, p, q, is_plastic, s, p_y, q_y, quadrant, t);
  Bezier::getDerivativeOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c,
      beta_c, alpha_t, beta_t, p, q, is_plastic, s,
      p_y, q_y, quadrant, t, derivatives);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong ds_dp, case 2a", 5, derivatives[0], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong ds_dq, case 2a", 0, derivatives[1], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dp2, case 2a", 0., derivatives[2], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dq2, case 2a", 0.159053039389, derivatives[3], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dpdq, case 2a", 0., derivatives[4], 1e-10);
  // Not along the p axis
  p = 0.;
  q = 1.;
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c,
      alpha_t, beta_t, p, q, is_plastic, s, p_y, q_y, quadrant, t);
  Bezier::getDerivativeOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c,
      beta_c, alpha_t, beta_t, p, q, is_plastic, s,
      p_y, q_y, quadrant, t, derivatives);
  //std::cout << "First method, ds_dp="<<derivatives[0]<<", ds_dq="<<derivatives[1] <<std::endl;
  //std::cout << "Second method, ds_dp="<<other_derivatives[0]<<", ds_dq="<<other_derivatives[1] <<std::endl;
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong ds_dp, case 2b", 1.717864193706, derivatives[0], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong ds_dq, case 2b", 1.188351947710, derivatives[1], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dp2, case 2b", 9.65186549938, derivatives[2], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dq2, case 2b", 0.0965186549938, derivatives[3], 1e-10);
  CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("wrong d2s_dpdq, case 2b", -0.965186549938, derivatives[4], 1e-10);
  // Testing manually...
  /*Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c,
        alpha_t, beta_t, p+dp, q, is_plastic, s1, p_y, q_y, quadrant, t);
  ds_dp = (s1 - s)/dp;
  Bezier::getOverstress(p_H, q_H, p_M, q_M, p_t, p_c, alpha_c, beta_c,
        alpha_t, beta_t, p, q+dq, is_plastic, s2, p_y, q_y, quadrant, t);
  ds_dq = (s2 - s)/dq;
  std::cout << "Manually, ds_dp="<<ds_dp<<", ds_dq="<<ds_dq <<std::endl;*/

}
