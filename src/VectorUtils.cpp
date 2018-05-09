// <copyright file="VectorUtils.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "VectorUtils.h"

#include <cmath>

using namespace VectorMath;

/*static*/ SimdVector VectorUtils::MergeXY(const SimdVector& lhs, const SimdVector& rhs)
{
	return { lhs[0], rhs[0], lhs[1], rhs[1],};
}

/*static*/ SimdVector VectorUtils::MergeZW(const SimdVector& lhs, const SimdVector& rhs)
{
	return { lhs[2], rhs[2], lhs[3], rhs[3] };
}

/*static*/ SimdVector VectorUtils::Zero()
{
	return { 0.0f, 0.0f, 0.0f, 0.0f };
}

/*static*/ SimdVector VectorUtils::One()
{
	return { 1.0f, 1.0f, 1.0f, 1.0f };
}

/*static*/ SimdVector VectorUtils::Replicate(float value)
{
	return { value, value, value, value };
}

/*static*/ SimdVector VectorUtils::Set(float x, float y, float z, float w)
{
	return { x, y, z, w };
}

/*static*/ SimdVector VectorUtils::SetX(const SimdVector& values, float value)
{
	return { value, values[1], values[2], values[3] };
}

/*static*/ SimdVector VectorUtils::SetY(const SimdVector& values, float value)
{
	return { values[0], value, values[2], values[3] };
}

/*static*/ SimdVector VectorUtils::SetZ(const SimdVector& values, float value)
{
	return { values[0], values[1], value, values[3] };
}

/*static*/ SimdVector VectorUtils::SetW(const SimdVector& values, float value)
{
	return { values[0], values[1], values[2], value };
}

/*static*/ float VectorUtils::GetX(const SimdVector& values)
{
	return values[0];
}

/*static*/ float VectorUtils::GetY(const SimdVector& values)
{
	return values[1];
}

/*static*/ float VectorUtils::GetZ(const SimdVector& values)
{
	return values[2];
}

/*static*/ float VectorUtils::GetW(const SimdVector& values)
{
	return values[3];
}

/*static*/ SimdVector VectorUtils::SplatX(const SimdVector& values)
{
	return { values[0], values[0], values[0], values[0] };
}

/*static*/ SimdVector VectorUtils::SplatY(const SimdVector& values)
{
	return { values[1], values[1], values[1], values[1] };
}

/*static*/ SimdVector VectorUtils::SplatZ(const SimdVector& values)
{
	return { values[2], values[2], values[2], values[2] };
}

/*static*/ SimdVector VectorUtils::SplatW(const SimdVector& values)
{
	return { values[3], values[3], values[3], values[3] };
}

/*static*/ SimdVector VectorUtils::UnitX()
{
	return { 1.0f, 0.0f, 0.0f, 0.0f };
}

/*static*/ SimdVector VectorUtils::UnitY()
{
	return { 0.0f, 1.0f, 0.0f, 0.0f };
}

/*static*/ SimdVector VectorUtils::UnitZ()
{
	return { 0.0f, 0.0f, 1.0f, 0.0f };
}

/*static*/ SimdVector VectorUtils::UnitW()
{
	return { 0.0f, 0.0f, 0.0f, 1.0f };
}

/*static*/ SimdVector VectorUtils::Negate(const SimdVector& values)
{
	return { -values[0], -values[1], -values[2], -values[3] };
}

/*static*/ SimdVector VectorUtils::Abs(const SimdVector& values)
{
	return { std::abs(values[0]), std::abs(values[1]), std::abs(values[2]), std::abs(values[3]) };
}

/*static*/ SimdVector VectorUtils::Sqrt(const SimdVector& values)
{
	return { std::sqrt(values[0]), std::sqrt(values[1]), std::sqrt(values[2]), std::sqrt(values[3]) };
}

/*static*/ SimdVector VectorUtils::Add(const SimdVector& lhs, const SimdVector& rhs)
{
	return { lhs[0] + rhs[0], lhs[1] + rhs[1], lhs[2] + rhs[2], lhs[3] + rhs[3] };
}

/*static*/ SimdVector VectorUtils::Subtract(const SimdVector& lhs, const SimdVector& rhs)
{
	return { lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2], lhs[3] - rhs[3] };
}

/*static*/ SimdVector VectorUtils::Multiply(const SimdVector& lhs, const SimdVector& rhs)
{
	return { lhs[0] * rhs[0], lhs[1] * rhs[1], lhs[2] * rhs[2], lhs[3] * rhs[3] };
}

/*static*/ SimdVector VectorUtils::Divide(const SimdVector& lhs, const SimdVector& rhs)
{
	return { lhs[0] / rhs[0], lhs[1] / rhs[1], lhs[2] / rhs[2], lhs[3] / rhs[3] };
}