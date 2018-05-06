// <copyright file="PlaneF.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once
#include "Vector3F.h"

namespace VectorMath
{
	/// <summary>
	/// Plane vector math
	/// 4-vector to represent the coefficients of the plane equation, Ax+By+Cz+D = 0
	/// </summary>
	class PlaneF
	{
		friend std::wostream& operator<<(std::wostream& stream, const PlaneF& value);

	public:
		/// <summary>
		/// Initialize a new instance of the PlaneF class
		/// </summary>
		PlaneF();
		PlaneF(const Vector3F& min, const Vector3F& max);

		/// <summary>
		/// Named Access
		/// </summary>
		Point4F GetValues() const;

		/// <summary>
		/// Assignment Operators
		/// </summary>
		PlaneF& operator=(const PlaneF& rhs);

		/// <summary>
		/// Comparison Operators
		/// </summary>
		bool operator==(const PlaneF& rhs) const;
		bool operator!=(const PlaneF& rhs) const;

	private:
		/// <summary>
		/// Raw Access
		/// </summary>
		PlaneF(SimdVector values);
		operator SimdVector() const;

		/// <summary>
		/// The values
		/// </summary>
		SimdVector m_values;
	};
} // namespace VectorMath

