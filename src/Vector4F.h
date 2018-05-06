// <copyright file="Vector4F.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once

namespace VectorMath
{
	/// <summary>
	/// The floating point point 4D
	/// </summary>
	class Vector4F
	{
		friend std::wostream& operator<<(std::wostream& stream, const Vector4F& value);
		friend class Matrix4x4F;
		friend class ScalarF;
		friend class VectorUtils;

	public:
		/// <summary>
		/// Defaults
		/// </summary>
		static Vector4F Zero();
		static Vector4F One();
		static Vector4F UnitX();
		static Vector4F UnitY();
		static Vector4F UnitZ();
		static Vector4F UnitW();

	public:
		/// <summary>
		/// Initialize a new instance of the Vector4F class
		/// </summary>
		Vector4F();
		Vector4F(const Vector3F& xyz, const ScalarF& w);
		Vector4F(float x, float y, float z, float w);

		/// <summary>
		/// Named Access
		/// </summary>
		Point4F GetValues() const;
		ScalarF GetX() const;
		ScalarF GetY() const;
		ScalarF GetZ() const;
		ScalarF GetW() const;
		void SetX(float value);
		void SetY(float value);
		void SetZ(float value);
		void SetW(float value);

		/// <summary>
		/// Assignment Operators
		/// </summary>
		Vector4F& operator=(const Vector4F& rhs);
		Vector4F& operator+=(const Vector4F& rhs);
		Vector4F& operator-=(const Vector4F& rhs);
		Vector4F& operator*=(const Vector4F& rhs);
		Vector4F& operator/=(const Vector4F& rhs);

		Vector4F& operator*=(const ScalarF& rhs);
		Vector4F& operator/=(const ScalarF& rhs);

		/// <summary>
		/// Arithmetic Operators
		/// </summary>
		Vector4F operator-() const;

		Vector4F operator+(const Vector4F& rhs) const;
		Vector4F operator-(const Vector4F& rhs) const;
		Vector4F operator*(const Vector4F& rhs) const;
		Vector4F operator/(const Vector4F& rhs) const;

		Vector4F operator*(const ScalarF& rhs) const;
		Vector4F operator/(const ScalarF& rhs) const;

		/// <summary>
		/// Comparison Operators
		/// </summary>
		bool operator==(const Vector4F& rhs) const;
		bool operator!=(const Vector4F& rhs) const;
		bool NearEqual(const Vector4F& rhs, const ScalarF& epsilon) const;

	private:
		/// <summary>
		/// Raw Access
		/// </summary>
		Vector4F(SimdVector values);
		operator SimdVector() const;

		/// <summary>
		/// The values
		/// </summary>
		SimdVector m_values;
	};
} // namespace VectorMath

