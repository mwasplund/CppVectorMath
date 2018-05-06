// <copyright file="Point2U.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once

namespace VectorMath
{
	/// <summary>
	/// The unsigned integer point 2D
	/// </summary>
	struct Point2U
	{
		friend std::wostream& operator<<(std::wostream& stream, const Point2U& value);

	public:
		/// <summary>
		/// Defaults
		/// </summary>
		static const Point2U& Zero();
		static const Point2U& One();
		static const Point2U& UnitX();
		static const Point2U& UnitY();

	public:
		/// <summary>
		/// Initialize a new instance of the Point2U class
		/// </summary>
		Point2U();
		Point2U(uint32_t x, uint32_t y);

		/// <summary>
		/// Named Access
		/// </summary>
		uint32_t GetX() const;
		uint32_t GetY() const;
		void SetX(uint32_t value);
		void SetY(uint32_t value);

		/// <summary>
		/// Assignment Operators
		/// </summary>
		Point2U& operator=(const Point2U& rhs);
		Point2U& operator+=(const Point2U& rhs);
		Point2U& operator-=(const Point2U& rhs);
		Point2U& operator*=(const Point2U& rhs);
		Point2U& operator/=(const Point2U& rhs);

		/// <summary>
		/// Arithmetic Operators
		/// </summary>
		Point2U operator+(const Point2U& rhs) const;
		Point2U operator-(const Point2U& rhs) const;
		Point2U operator*(const Point2U& rhs) const;
		Point2U operator/(const Point2U& rhs) const;

		/// <summary>
		/// Comparison Operators
		/// </summary>
		bool operator==(const Point2U& rhs) const;
		bool operator!=(const Point2U& rhs) const;

	private:
		/// <summary>
		/// The values
		/// </summary>
		uint32_t m_x;
		uint32_t m_y;
	};
} // namespace VectorMath

