#pragma once

#include <cmath>
#include "Vec2.hpp"

namespace Math
{
	const float Pi = 3.1415926535f;
	const float TwoPi = Pi * 2.0f;

	inline float Cos(float angle)
	{
		return cosf(angle);
	}

	inline float Sin(float angle)
	{
		return sinf(angle);
	}

	inline bool Zero(float val, float effectiveZero = 0.001f)
	{
		if (fabs(val) <= effectiveZero)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	inline bool Zero(Vec2 val, float effectiveZero = 0.001f)
	{
		if ((fabs(val.x) <= effectiveZero) && (fabs(val.y) <= effectiveZero))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}