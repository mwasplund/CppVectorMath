// <copyright file="Point2U.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "Point2U.h"

using namespace VectorMath;

std::wostream& VectorMath::operator<<(std::wostream& stream, const Point2U& value)
{
	stream << L"Point2U["
		<< value.GetX() << L","
		<< value.GetY() << L"]";

	return stream;
}

/*static*/ const Point2U& Point2U::Zero()
{
	static Point2U value = Point2U(0, 0);
	return value;
}

/*static*/ const Point2U& Point2U::One()
{
	static Point2U value = Point2U(1, 1);
	return value;
}

/*static*/ const Point2U& Point2U::UnitX()
{
	static Point2U value = Point2U(1, 0);
	return value;
}

/*static*/ const Point2U& Point2U::UnitY()
{
	static Point2U value = Point2U(0, 1);
	return value;
}

Point2U::Point2U() :
	m_x(0),
	m_y(0)
{
}

Point2U::Point2U(uint32_t x, uint32_t y) :
	m_x(x),
	m_y(y)
{
}

uint32_t Point2U::GetX() const
{
	return m_x;
}

uint32_t Point2U::GetY() const
{
	return m_y;
}

void Point2U::SetX(uint32_t value)
{
	m_x = value;
}

void Point2U::SetY(uint32_t value)
{
	m_y = value;
}

Point2U& Point2U::operator=(const Point2U& rhs)
{
	m_x = rhs.m_x;
	m_y = rhs.m_y;
	return *this;
}

Point2U& Point2U::operator+=(const Point2U& rhs)
{
	m_x += rhs.m_x;
	m_y += rhs.m_y;
	return *this;
}

Point2U& Point2U::operator-=(const Point2U& rhs)
{
	m_x -= rhs.m_x;
	m_y -= rhs.m_y;
	return *this;
}

Point2U& Point2U::operator*=(const Point2U& rhs)
{
	m_x *= rhs.m_x;
	m_y *= rhs.m_y;
	return *this;
}

Point2U& Point2U::operator/=(const Point2U& rhs)
{
	m_x /= rhs.m_x;
	m_y /= rhs.m_y;
	return *this;
}

Point2U Point2U::operator+(const Point2U& rhs) const
{
	return Point2U(
		m_x + rhs.m_x,
		m_y + rhs.m_y);
}

Point2U Point2U::operator-(const Point2U& rhs) const
{
	return Point2U(
		m_x - rhs.m_x,
		m_y - rhs.m_y);
}

Point2U Point2U::operator*(const Point2U& rhs) const
{
	return Point2U(
		m_x * rhs.m_x,
		m_y * rhs.m_y);
}

Point2U Point2U::operator/(const Point2U& rhs) const
{
	return Point2U(
		m_x / rhs.m_x,
		m_y / rhs.m_y);
}

bool Point2U::operator==(const Point2U& rhs) const
{
	return
		m_x == rhs.m_x &&
		m_y == rhs.m_y;
}

bool Point2U::operator!=(const Point2U& rhs) const
{
	return
		m_x != rhs.m_x ||
		m_y != rhs.m_y;
}
