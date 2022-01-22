#include "Double—omparison.h"
#include <limits>

bool double_is_equal(double d1, double d2, double epsilon)
{
	return fabs(d1 - d2) < epsilon;
}

bool double_is_lower(double d1, double d2, double epsilon)
{
	return  d2 - d1 > epsilon;
}
