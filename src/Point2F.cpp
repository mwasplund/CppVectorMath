// <copyright file="Point2F.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "pch.h"
#include "Point2F.h"

using namespace VectorMath;

std::wostream& VectorMath::operator<<(std::wostream& stream, const Point2F& value)
{
	stream << L"Point2F["
		<< value.GetX() << L","
		<< value.GetY() << L"]";

	return stream;
}

/*static*/ const Point2F& Point2F::Zero()
{
	static Point2F value = Point2F(0, 0);
	return value;
}

/*static*/ const Point2F& Point2F::One()
{
	static Point2F value = Point2F(1, 1);
	return value;
}

/*static*/ const Point2F& Point2F::UnitX()
{
	static Point2F value = Point2F(1, 0);
	return value;
}

/*static*/ const Point2F& Point2F::UnitY()
{
	static Point2F value = Point2F(0, 1);
	return value;
}

Point2F::Point2F() :
	m_x(0),
	m_y(0)
{
}

Point2F::Point2F(float x, float y) :
	m_x(x),
	m_y(y)
{
}

float Point2F::GetX() const
{
	return m_x;
}

float Point2F::GetY() const
{
	return m_y;
}

void Point2F::SetX(float value)
{
	m_x = value;
}

void Point2F::SetY(float value)
{
	m_y = value;
}

Point2F& Point2F::operator=(const Point2F& rhs)
{
	m_x = rhs.m_x;
	m_y = rhs.m_y;
	return *this;
}

Point2F& Point2F::operator+=(const Point2F& rhs)
{
	m_x += rhs.m_x;
	m_y += rhs.m_y;
	return *this;
}

Point2F& Point2F::operator-=(const Point2F& rhs)
{
	m_x -= rhs.m_x;
	m_y -= rhs.m_y;
	return *this;
}

Point2F& Point2F::operator*=(const Point2F& rhs)
{
	m_x *= rhs.m_x;
	m_y *= rhs.m_y;
	return *this;
}

Point2F& Point2F::operator/=(const Point2F& rhs)
{
	m_x /= rhs.m_x;
	m_y /= rhs.m_y;
	return *this;
}

Point2F Point2F::operator+(const Point2F& rhs) const
{
	return Point2F(
		m_x + rhs.m_x,
		m_y + rhs.m_y);
}

Point2F Point2F::operator-(const Point2F& rhs) const
{
	return Point2F(
		m_x - rhs.m_x,
		m_y - rhs.m_y);
}

Point2F Point2F::operator*(const Point2F& rhs) const
{
	return Point2F(
		m_x * rhs.m_x,
		m_y * rhs.m_y);
}

Point2F Point2F::operator/(const Point2F& rhs) const
{
	return Point2F(
		m_x / rhs.m_x,
		m_y / rhs.m_y);
}

bool Point2F::operator==(const Point2F& rhs) const
{
	return
		m_x == rhs.m_x &&
		m_y == rhs.m_y;
}

bool Point2F::operator!=(const Point2F& rhs) const
{
	return
		m_x != rhs.m_x ||
		m_y != rhs.m_y;
}
