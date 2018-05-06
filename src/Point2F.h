// <copyright file="Point2F.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once

namespace VectorMath
{
	/// <summary>
	/// The floating point 2D
	/// </summary>
	struct Point2F
	{
		friend std::wostream& operator<<(std::wostream& stream, const Point2F& value);

	public:
		/// <summary>
		/// Defaults
		/// </summary>
		static const Point2F& Zero();
		static const Point2F& One();
		static const Point2F& UnitX();
		static const Point2F& UnitY();

	public:
		/// <summary>
		/// Initialize a new instance of the Point2F class
		/// </summary>
		Point2F();
		Point2F(float x, float y);

		/// <summary>
		/// Named Access
		/// </summary>
		float GetX() const;
		float GetY() const;
		void SetX(float value);
		void SetY(float value);

		/// <summary>
		/// Assignment Operators
		/// </summary>
		Point2F& operator=(const Point2F& rhs);
		Point2F& operator+=(const Point2F& rhs);
		Point2F& operator-=(const Point2F& rhs);
		Point2F& operator*=(const Point2F& rhs);
		Point2F& operator/=(const Point2F& rhs);

		/// <summary>
		/// Arithmetic Operators
		/// </summary>
		Point2F operator+(const Point2F& rhs) const;
		Point2F operator-(const Point2F& rhs) const;
		Point2F operator*(const Point2F& rhs) const;
		Point2F operator/(const Point2F& rhs) const;

		/// <summary>
		/// Comparison Operators
		/// </summary>
		bool operator==(const Point2F& rhs) const;
		bool operator!=(const Point2F& rhs) const;

	private:
		/// <summary>
		/// The values
		/// </summary>
		float m_x;
		float m_y;
	};
} // namespace VectorMath

