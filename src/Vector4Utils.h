// <copyright file="Vector4Utils.h" company="mwasplund"> 
//   Copyright (c) mwasplund. All rights reserved.
// </copyright>

#pragma once

namespace VectorMath
{
	/// <summary>
	/// The vector 4 utils
	/// </summary>
	class Vector4Utils
	{
	public:
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
