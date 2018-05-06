// <copyright file="Vector2F.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "pch.h"
#include "Vector2F.h"

#include "ScalarF.h"

using namespace DirectX;
using namespace VectorMath;

std::wostream& VectorMath::operator<<(std::wostream& stream, const Vector2F& value)
{
	stream << L"["
		<< value.GetX().GetValue() << L","
		<< value.GetY().GetValue() << L"]";

	return stream;
}

/*static*/ Vector2F Vector2F::Zero()
{
	return XMVectorZero();
}

/*static*/ Vector2F Vector2F::One()
{
	return XMVectorSplatOne();
}

/*static*/ Vector2F Vector2F::UnitX()
{
	XMVECTORF32 result = { 1.0f, 0.0f, 0.0f, 0.0f };
	return result.v;
}

/*static*/ Vector2F Vector2F::UnitY()
{
	XMVECTORF32 result = { 0.0f, 1.0f, 0.0f, 0.0f };
	return result.v;
}

Vector2F::Vector2F() :
	m_values({ 0, 0 })
{
}

Vector2F::Vector2F(float x, float y) :
	m_values({ x, y })
{
}

ScalarF Vector2F::GetX() const
{
	return XMVectorSplatX(m_values);
}

ScalarF Vector2F::GetY() const
{
	return XMVectorSplatY(m_values);
}

void Vector2F::SetX(float value)
{
	m_values = XMVectorSetX(m_values, value);
}

void Vector2F::SetY(float value)
{
	m_values = XMVectorSetY(m_values, value);
}

ScalarF Vector2F::Length() const
{
	return XMVector2Length(m_values);
}

Vector2F Vector2F::Normalize() const
{
	return XMVector2Normalize(m_values);
}

bool Vector2F::IsNaN() const
{
	return XMVector2IsNaN(m_values);
}

bool Vector2F::IsInfinite() const
{
	return XMVector2IsInfinite(m_values);
}

Vector2F& Vector2F::operator=(const Vector2F& rhs)
{
	m_values = rhs.m_values;
	return *this;
}

Vector2F& Vector2F::operator+=(const Vector2F& rhs)
{
	*this = *this + rhs;
	return *this;
}

Vector2F& Vector2F::operator-=(const Vector2F& rhs)
{
	*this = *this - rhs;
	return *this;
}

Vector2F& Vector2F::operator*=(const Vector2F& rhs)
{
	*this = *this * rhs;
	return *this;
}

Vector2F& Vector2F::operator/=(const Vector2F& rhs)
{
	*this = *this / rhs;
	return *this;
}

Vector2F& Vector2F::operator*=(const ScalarF& rhs)
{
	*this = *this * rhs;
	return *this;
}

Vector2F& Vector2F::operator/=(const ScalarF& rhs)
{
	*this = *this / rhs;
	return *this;
}

Vector2F Vector2F::operator-() const
{
	return XMVectorNegate(m_values);
}

Vector2F Vector2F::operator+(const Vector2F& rhs) const
{
	return XMVectorAdd(m_values, rhs);
}

Vector2F Vector2F::operator-(const Vector2F& rhs) const
{
	return XMVectorSubtract(m_values, rhs);
}

Vector2F Vector2F::operator*(const Vector2F& rhs) const
{
	return XMVectorMultiply(m_values, rhs);
}

Vector2F Vector2F::operator/(const Vector2F& rhs) const
{
	return XMVectorDivide(m_values, rhs);
}

Vector2F Vector2F::operator*(const ScalarF& rhs) const
{
	return XMVectorMultiply(m_values, rhs);
}

Vector2F Vector2F::operator/(const ScalarF& rhs) const
{
	return XMVectorDivide(m_values, rhs);
}

bool Vector2F::operator==(const Vector2F& rhs) const
{
	return XMVector2Equal(m_values, rhs);
}

bool Vector2F::operator!=(const Vector2F& rhs) const
{
	return XMVector2NotEqual(m_values, rhs);
}

bool Vector2F::NearEqual(const Vector2F& rhs, const ScalarF& epsilon) const
{
	return XMVector2NearEqual(m_values, rhs, epsilon);
}

Vector2F::Vector2F(SimdVector values) :
	m_values(values)
{
}

Vector2F::operator SimdVector() const
{
	return m_values;
}
