// <copyright file="QuaternionF.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once

namespace VectorMath
{
	/// <summary>
	/// The floating point point 4D
	/// </summary>
	class QuaternionF
	{
		friend std::wostream& operator<<(std::wostream& stream, const QuaternionF& value);
		friend class Matrix4x4F;

	public:
		/// <summary>
		/// Get a reference to the identity quaternion
		/// </summary>
		static QuaternionF Identity();

	public:
		/// <summary>
		/// Initialize a new instance of the QuaternionF class
		/// </summary>
		QuaternionF();
		QuaternionF(float pitch, float yaw, float roll);
		QuaternionF(const Vector3F& axis, float angle);

	public:
		/// <summary>
		/// Named Access
		/// TODO : PROLY REMOVE
		/// </summary>
		float GetX() const;
		float GetY() const;
		float GetZ() const;
		float GetW() const;

		/// <summary>
		/// Assignment Operators
		/// </summary>
		QuaternionF& operator=(const QuaternionF& rhs);
		QuaternionF& operator*=(const QuaternionF& rhs);

		/// <summary>
		/// Arithmetic Operators
		/// </summary>
		QuaternionF operator~() const;
		QuaternionF operator-() const;
		QuaternionF operator*(const QuaternionF& rhs) const;
		Vector3F operator*(const Vector3F& rhs) const;

		/// <summary>
		/// Comparison Operators
		/// </summary>
		bool operator==(const QuaternionF& rhs) const;
		bool operator!=(const QuaternionF& rhs) const;

	private:
		/// <summary>
		/// Raw Access
		/// </summary>
		QuaternionF(SimdVector values);
		operator SimdVector() const;

		/// <summary>
		/// The values
		/// </summary>
		SimdVector m_values;
	};
} // namespace VectorMath

