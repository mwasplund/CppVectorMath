// <copyright file="Point3F.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once

namespace VectorMath
{
	/// <summary>
	/// The floating point 2D
	/// </summary>
	struct Point3F
	{
		friend std::wostream& operator<<(std::wostream& stream, const Point3F& value);

	public:
		/// <summary>
		/// Defaults
		/// </summary>
		static const Point3F& Zero();
		static const Point3F& One();
		static const Point3F& UnitX();
		static const Point3F& UnitY();
		static const Point3F& UnitZ();

	public:
		/// <summary>
		/// Initialize a new instance of the Point3F class
		/// </summary>
		Point3F();
		Point3F(float x, float y, float z);

		/// <summary>
		/// Named Access
		/// </summary>
		float GetX() const;
		float GetY() const;
		float GetZ() const;
		void SetX(float value);
		void SetY(float value);
		void SetZ(float value);

		/// <summary>
		/// Assignment Operators
		/// </summary>
		Point3F& operator=(const Point3F& rhs);
		Point3F& operator+=(const Point3F& rhs);
		Point3F& operator-=(const Point3F& rhs);
		Point3F& operator*=(const Point3F& rhs);
		Point3F& operator/=(const Point3F& rhs);

		/// <summary>
		/// Arithmetic Operators
		/// </summary>
		Point3F operator+(const Point3F& rhs) const;
		Point3F operator-(const Point3F& rhs) const;
		Point3F operator*(const Point3F& rhs) const;
		Point3F operator/(const Point3F& rhs) const;

		/// <summary>
		/// Comparison Operators
		/// </summary>
		bool operator==(const Point3F& rhs) const;
		bool operator!=(const Point3F& rhs) const;

	private:
		/// <summary>
		/// The values
		/// </summary>
		float m_x;
		float m_y;
		float m_z;
	};
} // namespace VectorMath

