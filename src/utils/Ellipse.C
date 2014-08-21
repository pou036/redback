/**
 * Code from Geometric Tools LLC, Redmond WA 98052
 * Copyright (c) 1998-2014
 * Distributed under the Boost Software License, Version 1.0.
 * http://www.boost.org/LICENSE_1_0.txt
 * http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
 * File Version: 1.0.0 (2014/08/11)
 */

#include "Ellipse.h"

Ellipse::Ellipse()
{}

Real
Ellipse::SqrDistanceSpecial(Real const e[2], Real const y[2], Real x[2])
{
  Real sqrDistance;
  if (y[1] > (Real)0)
  {
    if (y[0] > (Real)0)
    {
      // Bisect to compute the root of F(t) for t >= -e1*e1.
      Real esqr[2] = { e[0]*e[0], e[1]*e[1] };
      Real ey[2] = { e[0]*y[0], e[1]*y[1] };
      Real t0 = -esqr[1] + ey[1];
      Real t1 = -esqr[1] + sqrt(ey[0]*ey[0] + ey[1]*ey[1]);
      Real t = t0;
      const int imax = 2*std::numeric_limits<Real>::max_exponent;
      for (int i = 0; i < imax; ++i)
      {
        t = ((Real)0.5)*(t0 + t1);
        if (t == t0 || t == t1)
        {
          break;
        }

        Real r[2] = { ey[0]/(t + esqr[0]), ey[1]/(t + esqr[1]) };
        Real f = r[0]*r[0] + r[1]*r[1] - (Real)1;
        if (f > (Real)0)
        {
          t0 = t;
        }
        else if (f < (Real)0)
        {
          t1 = t;
        }
        else
        {
          break;
        }
      }

      x[0] = esqr[0]*y[0]/(t + esqr[0]);
      x[1] = esqr[1]*y[1]/(t + esqr[1]);
      Real d[2] = { x[0] - y[0], x[1] - y[1] };
      sqrDistance = d[0]*d[0] + d[1]*d[1];
    }
    else  // y0 == 0
    {
      x[0] = (Real)0;
      x[1] = e[1];
      Real diff = y[1] - e[1];
      sqrDistance = diff*diff;
    }
  }
  else  // y1 == 0
  {
    Real denom0 = e[0]*e[0] - e[1]*e[1];
    Real e0y0 = e[0]*y[0];
    if (e0y0 < denom0)
    {
      // y0 is inside the subinterval.
      Real x0de0 = e0y0/denom0;
      Real x0de0sqr = x0de0*x0de0;
      x[0] = e[0]*x0de0;
      x[1] = e[1]*sqrt(fabs((Real)1 - x0de0sqr));
      Real d0 = x[0] - y[0];
      sqrDistance = d0*d0 + x[1]*x[1];
    }
    else
    {
      // y0 is outside the subinterval.  The closest ellipse point has
      // x1 == 0 and is on the domain-boundary interval (x0/e0)^2 = 1.
      x[0] = e[0];
      x[1] = (Real)0;
      Real diff = y[0] - e[0];
      sqrDistance = diff*diff;
    }
  }
  return sqrDistance;
}

Real
Ellipse::SqrDistance(Real const e[2], Real const y[2], Real x[2])
{
  // Determine reflections for y to the first quadrant.
  bool reflect[2];
  int i, j;
  for (i = 0; i < 2; ++i)
  {
    reflect[i] = (y[i] < (Real)0);
  }

  // Determine the axis order for decreasing extents.
  int permute[2];
  if (e[0] < e[1])
  {
    permute[0] = 1;  permute[1] = 0;
  }
  else
  {
    permute[0] = 0;  permute[1] = 1;
  }

  int invpermute[2];
  for (i = 0; i < 2; ++i)
  {
    invpermute[permute[i]] = i;
  }

  Real locE[2], locY[2];
  for (i = 0; i < 2; ++i)
  {
    j = permute[i];
    locE[i] = e[j];
    locY[i] = y[j];
    if (reflect[j])
    {
      locY[i] = -locY[i];
    }
  }

  Real locX[2];
  Real sqrDistance = SqrDistanceSpecial(locE, locY, locX);

  // Restore the axis order and reflections.
  for (i = 0; i < 2; ++i)
  {
    j = invpermute[i];
    if (reflect[i])
    {
        locX[j] = -locX[j];
    }
    x[i] = locX[j];
  }

  return sqrDistance;
}

Real
Ellipse::SqrDistanceCC(Real const m, Real const p_c, Real const y[2], Real x[2])
{
  Real e[2]; // ellipse axes
  Real shifted_y[2]; // ellipse axes
  e[0] = p_c/2.0;
  e[1] = m*e[0];
  // Shift by pc_2 to centre the ellipse on (0,0)
  shifted_y[0] = y[0] - p_c/2.0;
  shifted_y[1] = y[1];
  Real d = SqrDistance(e, shifted_y, x);
  // Shift coordinates back to real space
  x[0] += p_c/2.0;
  return sqrt(d);
}
