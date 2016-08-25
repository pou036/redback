/**
 * Utilities
 */

#include "Utils.h"

Utils::Utils()
{
}

Real
Utils::macaulayBracket(Real val)
{
  if (val > 0.0)
    return val;
  else
    return 0.0;
}
