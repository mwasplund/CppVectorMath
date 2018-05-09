// <copyright file="VectorUtils.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once
#include "VectorMath.h"

namespace VectorMath
{
	/// <summary>
	/// The floating point vector s3D
	/// </summary>
	class VectorUtils
	{
	public:
		static SimdVector MergeXY(const SimdVector& lhs, const SimdVector& rhs);
		static SimdVector MergeZW(const SimdVector& lhs, const SimdVector& rhs);

		// Initialize a vector with all elements set to a single value
		static SimdVector Zero();
		static SimdVector One();
		static SimdVector Replicate(float value);

		// Set an specific value
		static SimdVector Set(float x, float y, float z, float w);
		static SimdVector SetX(const SimdVector& values, float value);
		static SimdVector SetY(const SimdVector& values, float value);
		static SimdVector SetZ(const SimdVector& values, float value);
		static SimdVector SetW(const SimdVector& values, float value);

		// Access internal values
		static float GetX(const SimdVector& values);
		static float GetY(const SimdVector& values);
		static float GetZ(const SimdVector& values);
		static float GetW(const SimdVector& values);

		// Splat methods
		static SimdVector SplatX(const SimdVector& values);
		static SimdVector SplatY(const SimdVector& values);
		static SimdVector SplatZ(const SimdVector& values);
		static SimdVector SplatW(const SimdVector& values);

		// Initialize a vector with unit length in each direction
		static SimdVector UnitX();
		static SimdVector UnitY();
		static SimdVector UnitZ();
		static SimdVector UnitW();

		// Math methods
		static SimdVector Negate(const SimdVector& values);
		static SimdVector Abs(const SimdVector& values);
		static SimdVector Sqrt(const SimdVector& values);
		static SimdVector Add(const SimdVector& lhs, const SimdVector& rhs);
		static SimdVector Subtract(const SimdVector& lhs, const SimdVector& rhs);
		static SimdVector Multiply(const SimdVector& lhs, const SimdVector& rhs);
		static SimdVector Divide(const SimdVector& lhs, const SimdVector& rhs);

		// Comparison methods
		static bool NearEqual(const SimdVector& lhs, const SimdVector& rhs, const SimdVector& epsilon);

	};
}
