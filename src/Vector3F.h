// <copyright file="Vector3F.h" company="mwasplund"> 
//   Copyright (c) mwasplund. All rights reserved.
// </copyright>

#pragma once

namespace VectorMath
{
	/// <summary>
	/// The floating point vector s3D
	/// </summary>
	export class Vector3F
	{
		friend std::wostream& operator<<(std::wostream& stream, const Vector3F& value);
		friend class Matrix4x4F;
		friend class QuaternionF;
		friend class ScalarF;
		friend class Vector4F;

	public:
		/// <summary>
		/// Defaults
		/// </summary>
		static Vector3F Zero();
		static Vector3F One();
		static Vector3F UnitX();
		static Vector3F UnitY();
		static Vector3F UnitZ();

		static Vector3F Cross(const Vector3F& lhs, const Vector3F& rhs);
		static ScalarF Dot(const Vector3F& lhs, const Vector3F& rhs);

	public:
		/// <summary>
		/// Initialize a new instance of the Vector3F class
		/// </summary>
		Vector3F();
		Vector3F(float x, float y, float z);

		/// <summary>
		/// Named Access
		/// </summary>
		std::array<float, 3> GetValues() const;
		ScalarF GetX() const;
		ScalarF GetY() const;
		ScalarF GetZ() const;
		void SetX(float value);
		void SetY(float value);
		void SetZ(float value);

		/// <summary>
		/// Functions
		/// </summary>
		ScalarF Length() const;
		Vector3F Normalize() const;

		bool IsNaN() const;
		bool IsInfinite() const;

		/// <summary>
		/// Assignment Operators
		/// </summary>
		Vector3F& operator=(const Vector3F& rhs);
		Vector3F& operator+=(const Vector3F& rhs);
		Vector3F& operator-=(const Vector3F& rhs);
		Vector3F& operator*=(const Vector3F& rhs);
		Vector3F& operator/=(const Vector3F& rhs);

		Vector3F& operator*=(const ScalarF& rhs);
		Vector3F& operator/=(const ScalarF& rhs);

		/// <summary>
		/// Arithmetic Operators
		/// </summary>
		Vector3F operator-() const;

		Vector3F operator+(const Vector3F& rhs) const;
		Vector3F operator-(const Vector3F& rhs) const;
		Vector3F operator*(const Vector3F& rhs) const;
		Vector3F operator/(const Vector3F& rhs) const;

		Vector3F operator*(const ScalarF& rhs) const;
		Vector3F operator/(const ScalarF& rhs) const;

		/// <summary>
		/// Comparison Operators
		/// </summary>
		bool operator==(const Vector3F& rhs) const;
		bool operator!=(const Vector3F& rhs) const;
		bool NearEqual(const Vector3F& rhs, const ScalarF& epsilon) const;

	// TODO: Friend bug
	// private:
		/// <summary>
		/// Raw Access
		/// </summary>
		Vector3F(SimdVector values);
		operator SimdVector() const;

		/// <summary>
		/// The values
		/// </summary>
		SimdVector m_values;
	};

	export std::wostream& operator<<(std::wostream& stream, const Vector3F& value);
} // namespace VectorMath

