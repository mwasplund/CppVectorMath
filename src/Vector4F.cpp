// <copyright file="Vector4F.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "pch.h"
#include "Vector4F.h"

#include "Point4F.h"
#include "ScalarF.h"
#include "Vector2F.h"
#include "Vector3F.h"

using namespace DirectX;
using namespace VectorMath;

std::wostream& VectorMath::operator<<(std::wostream& stream, const Vector4F& value)
{
	stream << L"["
		<< value.GetX().GetValue() << L","
		<< value.GetY().GetValue() << L","
		<< value.GetZ().GetValue() << L","
		<< value.GetW().GetValue() << L"]";

	return stream;
}

/*static*/ Vector4F Vector4F::Zero()
{
	return XMVectorZero();
}

/*static*/ Vector4F Vector4F::One()
{
	return XMVectorSplatOne();
}

/*static*/ Vector4F Vector4F::UnitX()
{
	XMVECTORF32 result = { 1.0f, 0.0f, 0.0f, 0.0f };
	return result.v;
}

/*static*/ Vector4F Vector4F::UnitY()
{
	XMVECTORF32 result = { 0.0f, 1.0f, 0.0f, 0.0f };
	return result.v;
}

/*static*/ Vector4F Vector4F::UnitZ()
{
	XMVECTORF32 result = { 0.0f, 0.0f, 1.0f, 0.0f };
	return result.v;
}

/*static*/ Vector4F Vector4F::UnitW()
{
	XMVECTORF32 result = { 0.0f, 0.0f, 0.0f, 1.0f };
	return result.v;
}

Vector4F::Vector4F() :
	m_values()
{
}

Vector4F::Vector4F(const Vector3F& xyz, const ScalarF& w) :
	m_values(XMVectorSelect(w, xyz, g_XMSelect1110))
{
}

Vector4F::Vector4F(float x, float y, float z, float w) :
	m_values(XMVectorSet(x, y, z, w))
{
}

Point4F Vector4F::GetValues() const
{
	XMFLOAT4 values;
	XMStoreFloat4(&values, m_values);
	return Point4F(values.x, values.y, values.z, values.w);
}

ScalarF Vector4F::GetX() const
{
	return XMVectorSplatX(m_values);
}

ScalarF Vector4F::GetY() const
{
	return XMVectorSplatY(m_values);
}

ScalarF Vector4F::GetZ() const
{
	return XMVectorSplatZ(m_values);
}

ScalarF Vector4F::GetW() const
{
	return XMVectorSplatW(m_values);
}

void Vector4F::SetX(float value)
{
	m_values = XMVectorSetX(m_values, value);
}

void Vector4F::SetY(float value)
{
	m_values = XMVectorSetY(m_values, value);
}

void Vector4F::SetZ(float value)
{
	m_values = XMVectorSetZ(m_values, value);
}

void Vector4F::SetW(float value)
{
	m_values = XMVectorSetW(m_values, value);
}

Vector4F& Vector4F::operator=(const Vector4F& rhs)
{
	m_values = rhs.m_values;
	return *this;
}

Vector4F& Vector4F::operator+=(const Vector4F& rhs)
{
	*this = *this + rhs;
	return *this;
}

Vector4F& Vector4F::operator-=(const Vector4F& rhs)
{
	*this = *this - rhs;
	return *this;
}

Vector4F& Vector4F::operator*=(const Vector4F& rhs)
{
	*this = *this * rhs;
	return *this;
}

Vector4F& Vector4F::operator/=(const Vector4F& rhs)
{
	*this = *this / rhs;
	return *this;
}

Vector4F& Vector4F::operator*=(const ScalarF& rhs)
{
	*this = *this * rhs;
	return *this;
}

Vector4F& Vector4F::operator/=(const ScalarF& rhs)
{
	*this = *this / rhs;
	return *this;
}

Vector4F Vector4F::operator-() const
{
	return XMVectorNegate(m_values);
}

Vector4F Vector4F::operator+(const Vector4F& rhs) const
{
	return XMVectorAdd(m_values, rhs);
}

Vector4F Vector4F::operator-(const Vector4F& rhs) const
{
	return XMVectorSubtract(m_values, rhs);
}

Vector4F Vector4F::operator*(const Vector4F& rhs) const
{
	return XMVectorMultiply(m_values, rhs);
}

Vector4F Vector4F::operator/(const Vector4F& rhs) const
{
	return XMVectorDivide(m_values, rhs);
}

Vector4F Vector4F::operator*(const ScalarF& rhs) const
{
	return XMVectorMultiply(m_values, rhs);
};

Vector4F Vector4F::operator/(const ScalarF& rhs) const
{
	return XMVectorDivide(m_values, rhs);
}

bool Vector4F::operator==(const Vector4F& rhs) const
{
	return XMVector4Equal(m_values, rhs);
}

bool Vector4F::operator!=(const Vector4F& rhs) const
{
	return XMVector4NotEqual(m_values, rhs);
}

bool Vector4F::NearEqual(const Vector4F& rhs, const ScalarF& epsilon) const
{
	return XMVector4NearEqual(m_values, rhs, epsilon);
}

Vector4F::Vector4F(SimdVector values) :
	m_values(values)
{
}

Vector4F::operator SimdVector() const
{
	return m_values;
}