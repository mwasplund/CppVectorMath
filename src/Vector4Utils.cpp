// <copyright file="Vector4Utils.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "Vector4Utils.h"

#include "VectorUtils.h"
#include <cmath>

using namespace VectorMath;

/*static*/ SimdVector Vector4Utils::LengthSq(const SimdVector& values)
{
	return Dot(values, values);
}

/*static*/ SimdVector Vector4Utils::Length(const SimdVector& values)
{
	auto result = LengthSq(values);
	result = VectorUtils::Sqrt(result);
	return result;
}

/*static*/ SimdVector Vector4Utils::Normalize(const SimdVector& values)
{
	auto lengthScalar = Vector4Utils::Length(values);
	auto length = lengthScalar[0];

	// Prevent divide by zero
	if (length != 0.0f)
	{
		length = 1.0f / length;
	}

	return
	{
		values[0] * length,
		values[1] * length,
		values[2] * length,
		values[3] * length
	};
}

/*static*/ SimdVector Vector4Utils::Cross(const SimdVector& lhs, const SimdVector& rhs)
{
	return
	{
		(lhs[1] * rhs[2]) - (lhs[2] * rhs[1]),
		(lhs[2] * rhs[0]) - (lhs[0] * rhs[2]),
		(lhs[0] * rhs[1]) - (lhs[1] * rhs[0]),
		0.0f
	};
}

/*static*/ SimdVector Vector4Utils::Dot(const SimdVector& lhs, const SimdVector& rhs)
{
	float value =
		lhs[0] * rhs[0] +
		lhs[1] * rhs[1] +
		lhs[2] * rhs[2] +
		lhs[3] * rhs[3];

	return { value, value, value, value };
}

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
