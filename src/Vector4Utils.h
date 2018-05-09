// <copyright file="Vector4Utils.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once
#include "VectorMath.h"

namespace VectorMath
{
	/// <summary>
	/// The vector 4 utils
	/// </summary>
	class Vector4Utils
	{
	public:
		// Math
		static SimdVector LengthSq(const SimdVector& values);
		static SimdVector Length(const SimdVector& values);
		static SimdVector Normalize(const SimdVector& values);
		static SimdVector Dot(const SimdVector& lhs, const SimdVector& rhs);

		// Comparison methods
		static bool Equal(const SimdVector& lhs, const SimdVector& rhs);
		static bool NotEqual(const SimdVector& lhs, const SimdVector& rhs);
		static bool NearEqual(const SimdVector& lhs, const SimdVector& rhs, const SimdVector& epsilon);
		static bool IsInfinite(const SimdVector& values);
		static bool IsNaN(const SimdVector& values);

		// Store
		static std::array<float, 4> Store(const SimdVector& values);

	};
}
