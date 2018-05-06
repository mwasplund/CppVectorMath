// <copyright file="Point3F.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "Point3F.h"

using namespace VectorMath;

std::wostream& VectorMath::operator<<(std::wostream& stream, const Point3F& value)
{
	stream << L"Point3F["
		<< value.GetX() << L","
		<< value.GetY() << L","
		<< value.GetZ() << L"]";

	return stream;
}

/*static*/ const Point3F& Point3F::Zero()
{
	static Point3F value = Point3F(0, 0, 0);
	return value;
}

/*static*/ const Point3F& Point3F::One()
{
	static Point3F value = Point3F(1, 1, 1);
	return value;
}

/*static*/ const Point3F& Point3F::UnitX()
{
	static Point3F value = Point3F(1, 0, 0);
	return value;
}

/*static*/ const Point3F& Point3F::UnitY()
{
	static Point3F value = Point3F(0, 1, 0);
	return value;
}

/*static*/ const Point3F& Point3F::UnitZ()
{
	static Point3F value = Point3F(0, 0, 1);
	return value;
}

Point3F::Point3F() :
	m_x(0),
	m_y(0),
	m_z(0)
{
}

Point3F::Point3F(float x, float y, float z) :
	m_x(x),
	m_y(y),
	m_z(z)
{
}

float Point3F::GetX() const
{
	return m_x;
}

float Point3F::GetY() const
{
	return m_y;
}

float Point3F::GetZ() const
{
	return m_z;
}

void Point3F::SetX(float value)
{
	m_x = value;
}

void Point3F::SetY(float value)
{
	m_y = value;
}

void Point3F::SetZ(float value)
{
	m_z = value;
}

Point3F& Point3F::operator=(const Point3F& rhs)
{
	m_x = rhs.m_x;
	m_y = rhs.m_y;
	m_z = rhs.m_z;
	return *this;
}

Point3F& Point3F::operator+=(const Point3F& rhs)
{
	m_x += rhs.m_x;
	m_y += rhs.m_y;
	m_z += rhs.m_z;
	return *this;
}

Point3F& Point3F::operator-=(const Point3F& rhs)
{
	m_x -= rhs.m_x;
	m_y -= rhs.m_y;
	m_z -= rhs.m_z;
	return *this;
}

Point3F& Point3F::operator*=(const Point3F& rhs)
{
	m_x *= rhs.m_x;
	m_y *= rhs.m_y;
	m_z *= rhs.m_z;
	return *this;
}

Point3F& Point3F::operator/=(const Point3F& rhs)
{
	m_x /= rhs.m_x;
	m_y /= rhs.m_y;
	m_z /= rhs.m_z;
	return *this;
}

Point3F Point3F::operator+(const Point3F& rhs) const
{
	return Point3F(
		m_x + rhs.m_x,
		m_y + rhs.m_y,
		m_z + rhs.m_z);
}

Point3F Point3F::operator-(const Point3F& rhs) const
{
	return Point3F(
		m_x - rhs.m_x,
		m_y - rhs.m_y,
		m_z - rhs.m_z);
}

Point3F Point3F::operator*(const Point3F& rhs) const
{
	return Point3F(
		m_x * rhs.m_x,
		m_y * rhs.m_y,
		m_z * rhs.m_z);
}

Point3F Point3F::operator/(const Point3F& rhs) const
{
	return Point3F(
		m_x / rhs.m_x,
		m_y / rhs.m_y,
		m_z / rhs.m_z);
}

bool Point3F::operator==(const Point3F& rhs) const
{
	return
		m_x == rhs.m_x &&
		m_y == rhs.m_y &&
		m_z == rhs.m_z;
}

bool Point3F::operator!=(const Point3F& rhs) const
{
	return
		m_x != rhs.m_x ||
		m_y != rhs.m_y ||
		m_z != rhs.m_z;
}
