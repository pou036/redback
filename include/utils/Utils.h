/**
 * Code from Geometric Tools LLC, Redmond WA 98052
 * Copyright (c) 1998-2014
 * Distributed under the Boost Software License, Version 1.0.
 * http://www.boost.org/LICENSE_1_0.txt
 * http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
 * File Version: 1.0.0 (2014/08/11)
 */

#ifndef UTILS_H
#define UTILS_H

#include "GeneralUserObject.h"

class Utils
{
public:
  Utils();

  /**
   * Macaulay bracket operator
   * @param x: value to apply operator on
   * @return x if x>0, else 0
   */
  static Real macaulayBracket(Real x);

};

#endif // UTILS_H
