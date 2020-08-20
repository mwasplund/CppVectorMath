// <copyright file="Vector4Utils.h" company="mwasplund"> 
//   Copyright (c) mwasplund. All rights reserved.
// </copyright>

module;

#include <cmath>

module VectorMath;

using namespace VectorMath;

/*static*/ bool Vector4Utils::Equal(const SimdVector& lhs, const SimdVector& rhs)
{
	return
		lhs[0] == rhs[0] &&
		lhs[1] == rhs[1] &&
		lhs[2] == rhs[2] &&
		lhs[3] == rhs[3];
}

/*static*/ bool Vector4Utils::NotEqual(const SimdVector& lhs, const SimdVector& rhs)
{
	return
		lhs[0] != rhs[0] ||
		lhs[1] != rhs[1] ||
		lhs[2] != rhs[2] ||
		lhs[3] != rhs[3];
}

/*static*/ bool Vector4Utils::NearEqual(const SimdVector& lhs, const SimdVector& rhs, const SimdVector& epsilon)
{
	auto delta = VectorUtils::Subtract(lhs, rhs);
	delta = VectorUtils::Abs(delta);

	return
		delta[0] <= epsilon[0] &&
		delta[1] <= epsilon[1] &&
		delta[2] <= epsilon[2] &&
		delta[3] <= epsilon[3];
}

/*static*/ bool Vector4Utils::IsInfinite(const SimdVector& values)
{
	return
		std::isinf(values[0]) &&
		std::isinf(values[1]) &&
		std::isinf(values[2]) &&
		std::isinf(values[3]);
}

/*static*/ bool Vector4Utils::IsNaN(const SimdVector& values)
{
	return
		std::isnan(values[0]) &&
		std::isnan(values[1]) &&
		std::isnan(values[2]) &&
		std::isnan(values[3]);
}

/*static*/ std::array<float, 4> Vector4Utils::Store(const SimdVector& values)
{
	return values;
}
