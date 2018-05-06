// <copyright file="Point4F.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once

namespace VectorMath
{
	/// <summary>
	/// The floating point 2D
	/// </summary>
	struct Point4F
	{
		friend std::wostream& operator<<(std::wostream& stream, const Point4F& value);

	public:
		/// <summary>
		/// Defaults
		/// </summary>
		static const Point4F& Zero();
		static const Point4F& One();
		static const Point4F& UnitX();
		static const Point4F& UnitY();
		static const Point4F& UnitZ();
		static const Point4F& UnitW();

	public:
		/// <summary>
		/// Initialize a new instance of the Point4F class
		/// </summary>
		Point4F();
		Point4F(float x, float y, float z, float w);

		/// <summary>
		/// Named Access
		/// </summary>
		float GetX() const;
		float GetY() const;
		float GetZ() const;
		float GetW() const;
		void SetX(float value);
		void SetY(float value);
		void SetZ(float value);
		void SetW(float value);

		/// <summary>
		/// Assignment Operators
		/// </summary>
		Point4F& operator=(const Point4F& rhs);
		Point4F& operator+=(const Point4F& rhs);
		Point4F& operator-=(const Point4F& rhs);
		Point4F& operator*=(const Point4F& rhs);
		Point4F& operator/=(const Point4F& rhs);

		/// <summary>
		/// Arithmetic Operators
		/// </summary>
		Point4F operator+(const Point4F& rhs) const;
		Point4F operator-(const Point4F& rhs) const;
		Point4F operator*(const Point4F& rhs) const;
		Point4F operator/(const Point4F& rhs) const;

		/// <summary>
		/// Comparison Operators
		/// </summary>
		bool operator==(const Point4F& rhs) const;
		bool operator!=(const Point4F& rhs) const;

	private:
		/// <summary>
		/// The values
		/// </summary>
		float m_x;
		float m_y;
		float m_z;
		float m_w;
	};
} // namespace VectorMath

