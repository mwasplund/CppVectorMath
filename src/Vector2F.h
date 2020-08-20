// <copyright file="Vector2F.h" company="mwasplund"> 
//   Copyright (c) mwasplund. All rights reserved.
// </copyright>

#pragma once

namespace VectorMath
{
	/// <summary>
	/// The floating point vector 2D
	/// </summary>
	export class Vector2F
	{
		friend std::wostream& operator<<(std::wostream& stream, const Vector2F& value);
		friend class ScalarF;

	public:
		/// <summary>
		/// Defaults
		/// </summary>
		static Vector2F Zero();
		static Vector2F One();
		static Vector2F UnitX();
		static Vector2F UnitY();

	public:
		/// <summary>
		/// Initialize a new instance of the Vector2F class
		/// </summary>
		Vector2F();
		Vector2F(float x, float y);

		/// <summary>
		/// Named Access
		/// </summary>
		std::array<float, 2> GetValues() const;
		ScalarF GetX() const;
		ScalarF GetY() const;
		void SetX(float value);
		void SetY(float value);

		/// <summary>
		/// Functions
		/// </summary>
		ScalarF Length() const;
		Vector2F Normalize() const;

		bool IsNaN() const;
		bool IsInfinite() const;

		/// <summary>
		/// Assignment Operators
		/// </summary>
		Vector2F& operator=(const Vector2F& rhs);
		Vector2F& operator+=(const Vector2F& rhs);
		Vector2F& operator-=(const Vector2F& rhs);
		Vector2F& operator*=(const Vector2F& rhs);
		Vector2F& operator/=(const Vector2F& rhs);

		Vector2F& operator*=(const ScalarF& rhs);
		Vector2F& operator/=(const ScalarF& rhs);

		/// <summary>
		/// Arithmetic Operators
		/// </summary>
		Vector2F operator-() const;

		Vector2F operator+(const Vector2F& rhs) const;
		Vector2F operator-(const Vector2F& rhs) const;
		Vector2F operator*(const Vector2F& rhs) const;
		Vector2F operator/(const Vector2F& rhs) const;

		Vector2F operator*(const ScalarF& rhs) const;
		Vector2F operator/(const ScalarF& rhs) const;

		/// <summary>
		/// Comparison Operators
		/// </summary>
		bool operator==(const Vector2F& rhs) const;
		bool operator!=(const Vector2F& rhs) const;
		bool NearEqual(const Vector2F& rhs, const ScalarF& epsilon) const;

	private:
		/// <summary>
		/// Raw Access
		/// </summary>
		Vector2F(SimdVector values);
		operator SimdVector() const;

		/// <summary>
		/// The values
		/// </summary>
		SimdVector m_values;
	};

	export std::wostream& operator<<(std::wostream& stream, const Vector2F& value);
} // namespace VectorMath

