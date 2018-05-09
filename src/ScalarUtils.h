// <copyright file="ScalarUtils.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once
#include "VectorMath.h"

namespace VectorMath
{
	/// <summary>
	/// The scalar utils
	/// </summary>
	class ScalarUtils
	{
	public:
		// Comparison methods
		static bool Equal(const SimdVector& lhs, const SimdVector& rhs);
		static bool NotEqual(const SimdVector& lhs, const SimdVector& rhs);
		static bool NearEqual(const SimdVector& lhs, const SimdVector& rhs, const SimdVector& epsilon);
		static bool IsInfinite(const SimdVector& values);
		static bool IsNaN(const SimdVector& values);

		// Store
		static float Store(const SimdVector& values);

	};
}
