// <copyright file="Vector3Utils.h" company="mwasplund"> 
//   Copyright (c) mwasplund. All rights reserved.
// </copyright>

#pragma once

namespace VectorMath
{
	/// <summary>
	/// The vector 3 utils
	/// </summary>
	class Vector3Utils
	{
	public:
		// Math
		static SimdVector LengthSq(const SimdVector& values);
		static SimdVector Length(const SimdVector& values);
		static SimdVector Normalize(const SimdVector& values);
		static SimdVector Cross(const SimdVector& lhs, const SimdVector& rhs);
		static SimdVector Dot(const SimdVector& lhs, const SimdVector& rhs);

		// Comparison
		static bool Equal(const SimdVector& lhs, const SimdVector& rhs);
		static bool NotEqual(const SimdVector& lhs, const SimdVector& rhs);
		static bool NearEqual(const SimdVector& lhs, const SimdVector& rhs, const SimdVector& epsilon);
		static bool IsInfinite(const SimdVector& values);
		static bool IsNaN(const SimdVector& values);

		// Store
		static std::array<float, 3> Store(const SimdVector& values);
	};
}
