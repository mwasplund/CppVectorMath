// <copyright file="Vector3Utils.h" company="mwasplund"> 
//   Copyright (c) mwasplund. All rights reserved.
// </copyright>

module;

#include <cmath>

module VectorMath;

using namespace VectorMath;

/*static*/ SimdVector Vector3Utils::LengthSq(const SimdVector& values)
{
	return Dot(values, values);
}

/*static*/ SimdVector Vector3Utils::Length(const SimdVector& values)
{
	auto result = LengthSq(values);
	result = VectorUtils::Sqrt(result);
	return result;
}

/*static*/ SimdVector Vector3Utils::Normalize(const SimdVector& values)
{
	auto lengthScalar = Vector3Utils::Length(values);
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

/*static*/ SimdVector Vector3Utils::Cross(const SimdVector& lhs, const SimdVector& rhs)
{
	return
	{
		(lhs[1] * rhs[2]) - (lhs[2] * rhs[1]),
		(lhs[2] * rhs[0]) - (lhs[0] * rhs[2]),
		(lhs[0] * rhs[1]) - (lhs[1] * rhs[0]),
		0.0f
	};
}

/*static*/ SimdVector Vector3Utils::Dot(const SimdVector& lhs, const SimdVector& rhs)
{
	float value =
		lhs[0] * rhs[0] +
		lhs[1] * rhs[1] +
		lhs[2] * rhs[2];

	return { value, value, value, value };
}

/*static*/ bool Vector3Utils::Equal(const SimdVector& lhs, const SimdVector& rhs)
{
	return
		lhs[0] == rhs[0] &&
		lhs[1] == rhs[1] &&
		lhs[2] == rhs[2];
}

/*static*/ bool Vector3Utils::NotEqual(const SimdVector& lhs, const SimdVector& rhs)
{
	return
		lhs[0] != rhs[0] ||
		lhs[1] != rhs[1] ||
		lhs[2] != rhs[2];
}

/*static*/ bool Vector3Utils::NearEqual(const SimdVector& lhs, const SimdVector& rhs, const SimdVector& epsilon)
{
	auto delta = VectorUtils::Subtract(lhs, rhs);
	delta = VectorUtils::Abs(delta);

	return
		delta[0] <= epsilon[0] &&
		delta[1] <= epsilon[1] &&
		delta[2] <= epsilon[2];
}

/*static*/ bool Vector3Utils::IsInfinite(const SimdVector& values)
{
	return
		std::isinf(values[0]) &&
		std::isinf(values[1]) &&
		std::isinf(values[2]);
}

/*static*/ bool Vector3Utils::IsNaN(const SimdVector& values)
{
	return
		std::isnan(values[0]) &&
		std::isnan(values[1]) &&
		std::isnan(values[2]);
}

/*static*/ std::array<float, 3> Vector3Utils::Store(const SimdVector& values)
{
	return { values[0], values[1], values[2] };
}
