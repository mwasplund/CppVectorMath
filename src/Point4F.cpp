// <copyright file="Point4F.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "Point4F.h"

using namespace VectorMath;

std::wostream& VectorMath::operator<<(std::wostream& stream, const Point4F& value)
{
	stream << L"Point4F["
		<< value.GetX() << L","
		<< value.GetY() << L","
		<< value.GetZ() << L","
		<< value.GetW() << L"]";

	return stream;
}

/*static*/ const Point4F& Point4F::Zero()
{
	static Point4F value = Point4F(0, 0, 0, 0);
	return value;
}

/*static*/ const Point4F& Point4F::One()
{
	static Point4F value = Point4F(1, 1, 1, 1);
	return value;
}

/*static*/ const Point4F& Point4F::UnitX()
{
	static Point4F value = Point4F(1, 0, 0, 0);
	return value;
}

/*static*/ const Point4F& Point4F::UnitY()
{
	static Point4F value = Point4F(0, 1, 0, 0);
	return value;
}

/*static*/ const Point4F& Point4F::UnitZ()
{
	static Point4F value = Point4F(0, 0, 1, 0);
	return value;
}

/*static*/ const Point4F& Point4F::UnitW()
{
	static Point4F value = Point4F(0, 0, 0, 1);
	return value;
}

Point4F::Point4F() :
	m_x(0),
	m_y(0),
	m_z(0),
	m_w(0)
{
}

Point4F::Point4F(float x, float y, float z, float w) :
	m_x(x),
	m_y(y),
	m_z(z),
	m_w(w)
{
}

float Point4F::GetX() const
{
	return m_x;
}

float Point4F::GetY() const
{
	return m_y;
}

float Point4F::GetZ() const
{
	return m_z;
}

float Point4F::GetW() const
{
	return m_w;
}

void Point4F::SetX(float value)
{
	m_x = value;
}

void Point4F::SetY(float value)
{
	m_y = value;
}

void Point4F::SetZ(float value)
{
	m_z = value;
}

void Point4F::SetW(float value)
{
	m_w = value;
}

Point4F& Point4F::operator=(const Point4F& rhs)
{
	m_x = rhs.m_x;
	m_y = rhs.m_y;
	m_z = rhs.m_z;
	m_w = rhs.m_w;
	return *this;
}

Point4F& Point4F::operator+=(const Point4F& rhs)
{
	m_x += rhs.m_x;
	m_y += rhs.m_y;
	m_z += rhs.m_z;
	m_w += rhs.m_w;
	return *this;
}

Point4F& Point4F::operator-=(const Point4F& rhs)
{
	m_x -= rhs.m_x;
	m_y -= rhs.m_y;
	m_z -= rhs.m_z;
	m_w -= rhs.m_w;
	return *this;
}

Point4F& Point4F::operator*=(const Point4F& rhs)
{
	m_x *= rhs.m_x;
	m_y *= rhs.m_y;
	m_z *= rhs.m_z;
	m_w *= rhs.m_w;
	return *this;
}

Point4F& Point4F::operator/=(const Point4F& rhs)
{
	m_x /= rhs.m_x;
	m_y /= rhs.m_y;
	m_z /= rhs.m_z;
	m_w /= rhs.m_w;
	return *this;
}

Point4F Point4F::operator+(const Point4F& rhs) const
{
	return Point4F(
		m_x + rhs.m_x,
		m_y + rhs.m_y,
		m_z + rhs.m_z,
		m_w + rhs.m_w);
}

Point4F Point4F::operator-(const Point4F& rhs) const
{
	return Point4F(
		m_x - rhs.m_x,
		m_y - rhs.m_y,
		m_z - rhs.m_z,
		m_w - rhs.m_w);
}

Point4F Point4F::operator*(const Point4F& rhs) const
{
	return Point4F(
		m_x * rhs.m_x,
		m_y * rhs.m_y,
		m_z * rhs.m_z,
		m_w * rhs.m_w);
}

Point4F Point4F::operator/(const Point4F& rhs) const
{
	return Point4F(
		m_x / rhs.m_x,
		m_y / rhs.m_y,
		m_z / rhs.m_z,
		m_w / rhs.m_w);
}

bool Point4F::operator==(const Point4F& rhs) const
{
	return
		m_x == rhs.m_x &&
		m_y == rhs.m_y &&
		m_z == rhs.m_z &&
		m_w == rhs.m_w;
}

bool Point4F::operator!=(const Point4F& rhs) const
{
	return
		m_x != rhs.m_x ||
		m_y != rhs.m_y ||
		m_z != rhs.m_z ||
		m_w != rhs.m_w;
}
