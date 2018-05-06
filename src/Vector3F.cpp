// <copyright file="Vector3F.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "pch.h"
#include "Vector3F.h"

#include "ScalarF.h"

using namespace DirectX;
using namespace VectorMath;

std::wostream& VectorMath::operator<<(std::wostream& stream, const Vector3F& value)
{
	stream << L"["
		<< value.GetX().GetValue() << L","
		<< value.GetY().GetValue() << L","
		<< value.GetZ().GetValue() << L"]";

	return stream;
}

/*static*/ Vector3F Vector3F::Zero()
{
	return XMVectorZero();
}

/*static*/ Vector3F Vector3F::One()
{
	return XMVectorSplatOne();
}

/*static*/ Vector3F Vector3F::UnitX()
{
	XMVECTORF32 result = { 1.0f, 0.0f, 0.0f, 0.0f };
	return result.v;
}

/*static*/ Vector3F Vector3F::UnitY()
{
	XMVECTORF32 result = { 0.0f, 1.0f, 0.0f, 0.0f };
	return result.v;
}

/*static*/ Vector3F Vector3F::UnitZ()
{
	XMVECTORF32 result = { 0.0f, 0.0f, 1.0f, 0.0f };
	return result.v;
}

/*static*/ Vector3F Vector3F::Cross(const Vector3F& lhs, const Vector3F& rhs)
{
	return XMVector3Cross(lhs, rhs);
}

/*static*/ ScalarF Vector3F::Dot(const Vector3F& lhs, const Vector3F& rhs)
{
	return XMVector3Dot(lhs, rhs);
}

Vector3F::Vector3F() :
	m_values()
{
}

Vector3F::Vector3F(float x, float y, float z) :
	m_values(XMVectorSet(x, y, z, 0))
{
}

ScalarF Vector3F::GetX() const
{
	return XMVectorSplatX(m_values);
}

ScalarF Vector3F::GetY() const
{
	return XMVectorSplatY(m_values);
}

ScalarF Vector3F::GetZ() const
{
	return XMVectorSplatZ(m_values);
}

void Vector3F::SetX(float value)
{
	m_values = XMVectorSetX(m_values, value);
}

void Vector3F::SetY(float value)
{
	m_values = XMVectorSetY(m_values, value);
}

void Vector3F::SetZ(float value)
{
	m_values = XMVectorSetZ(m_values, value);
}

ScalarF Vector3F::Length() const
{
	return XMVector3Length(m_values);
}

Vector3F Vector3F::Normalize() const
{
	return XMVector3Normalize(m_values);
}

bool Vector3F::IsNaN() const
{
	return XMVector3IsNaN(m_values);
}

bool Vector3F::IsInfinite() const
{
	return XMVector3IsInfinite(m_values);
}

Vector3F& Vector3F::operator=(const Vector3F& rhs)
{
	m_values = rhs.m_values;
	return *this;
}

Vector3F& Vector3F::operator+=(const Vector3F& rhs)
{
	*this = *this + rhs;
	return *this;
}

Vector3F& Vector3F::operator-=(const Vector3F& rhs)
{
	*this = *this - rhs;
	return *this;
}

Vector3F& Vector3F::operator*=(const Vector3F& rhs)
{
	*this = *this * rhs;
	return *this;
}

Vector3F& Vector3F::operator/=(const Vector3F& rhs)
{
	*this = *this / rhs;
	return *this;
}

Vector3F& Vector3F::operator*=(const ScalarF& rhs)
{
	*this = *this * rhs;
	return *this;
}

Vector3F& Vector3F::operator/=(const ScalarF& rhs)
{
	*this = *this / rhs;
	return *this;
}

Vector3F Vector3F::operator-() const
{
	return XMVectorNegate(m_values);
}

Vector3F Vector3F::operator+(const Vector3F& rhs) const
{
	return XMVectorAdd(m_values, rhs);
}

Vector3F Vector3F::operator-(const Vector3F& rhs) const
{
	return XMVectorSubtract(m_values, rhs);
}

Vector3F Vector3F::operator*(const Vector3F& rhs) const
{
	return XMVectorMultiply(m_values, rhs);
}

Vector3F Vector3F::operator/(const Vector3F& rhs) const
{
	return XMVectorDivide(m_values, rhs);
}

Vector3F Vector3F::operator*(const ScalarF& rhs) const
{
	return XMVectorMultiply(m_values, rhs);
}

Vector3F Vector3F::operator/(const ScalarF& rhs) const
{
	return XMVectorDivide(m_values, rhs);
}

bool Vector3F::operator==(const Vector3F& rhs) const
{
	return XMVector3Equal(m_values, rhs);
}

bool Vector3F::operator!=(const Vector3F& rhs) const
{
	return XMVector3NotEqual(m_values, rhs);
}

bool Vector3F::NearEqual(const Vector3F& rhs, const ScalarF& epsilon) const
{
	return XMVector3NearEqual(m_values, rhs, epsilon);
}

Vector3F::Vector3F(SimdVector values) :
	m_values(values)
{
}

Vector3F::operator SimdVector() const
{
	return m_values;
}