// <copyright file="ScalarUtils.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "ScalarUtils.h"

#include "VectorUtils.h"
#include <cmath>

using namespace VectorMath;

/*static*/ bool ScalarUtils::Equal(const SimdVector& lhs, const SimdVector& rhs)
{
	return
		lhs[0] == rhs[0];
}

/*static*/ bool ScalarUtils::NotEqual(const SimdVector& lhs, const SimdVector& rhs)
{
	return
		lhs[0] != rhs[0];
}

/*static*/ bool ScalarUtils::NearEqual(const SimdVector& lhs, const SimdVector& rhs, const SimdVector& epsilon)
{
	auto delta = VectorUtils::Subtract(lhs, rhs);
	delta = VectorUtils::Abs(delta);

	return
		delta[0] <= epsilon[0];
}

/*static*/ bool ScalarUtils::IsInfinite(const SimdVector& values)
{
	return
		std::isinf(values[0]);
}

/*static*/ bool ScalarUtils::IsNaN(const SimdVector& values)
{
	return
		std::isnan(values[0]);
}

/*static*/ float ScalarUtils::Store(const SimdVector& values)
{
	return values[0];
}
