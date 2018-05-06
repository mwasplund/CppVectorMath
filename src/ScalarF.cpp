// <copyright file="ScalarF.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "pch.h"
#include "ScalarF.h"

#include "Vector2F.h"
#include "Vector3F.h"
#include "Vector4F.h"

using namespace DirectX;
using namespace VectorMath;

std::wostream& VectorMath::operator<<(std::wostream& stream, const ScalarF& value)
{
	stream << L"[" << value.GetValue() << L"]";
	return stream;
}

/*static*/ ScalarF ScalarF::Zero()
{
	return XMVectorZero();
}

/*static*/ ScalarF ScalarF::One()
{
	return XMVectorSplatOne();
}

ScalarF::ScalarF() :
	m_values()
{
}

ScalarF::ScalarF(float value) :
	m_values(XMVectorReplicate(value))
{
}

float ScalarF::GetValue() const
{
	return XMVectorGetX(m_values);
}

void ScalarF::SetValue(float value)
{
	m_values = XMVectorReplicate(value);
}

ScalarF& ScalarF::operator=(const ScalarF& rhs)
{
	m_values = rhs.m_values;
	return *this;
}

ScalarF& ScalarF::operator+=(const ScalarF& rhs)
{
	*this = *this + rhs;
	return *this;
}

ScalarF& ScalarF::operator-=(const ScalarF& rhs)
{
	*this = *this - rhs;
	return *this;
}

ScalarF& ScalarF::operator*=(const ScalarF& rhs)
{
	*this = *this * rhs;
	return *this;
}

ScalarF& ScalarF::operator/=(const ScalarF& rhs)
{
	*this = *this / rhs;
	return *this;
}

ScalarF ScalarF::operator-() const
{
	return XMVectorNegate(m_values);
}

ScalarF ScalarF::operator+(const ScalarF& rhs) const
{
	return XMVectorAdd(m_values, rhs);
}

ScalarF ScalarF::operator-(const ScalarF& rhs) const
{
	return XMVectorSubtract(m_values, rhs);
}

ScalarF ScalarF::operator*(const ScalarF& rhs) const
{
	return XMVectorMultiply(m_values, rhs);
}

ScalarF ScalarF::operator/(const ScalarF& rhs) const
{
	return XMVectorDivide(m_values, rhs);
}

Vector2F ScalarF::operator*(const Vector2F& rhs) const
{
	return XMVectorMultiply(m_values, rhs);
}

Vector2F ScalarF::operator/(const Vector2F& rhs) const
{
	return XMVectorDivide(m_values, rhs);
}

Vector3F ScalarF::operator*(const Vector3F& rhs) const
{
	return XMVectorMultiply(m_values, rhs);
}

Vector3F ScalarF::operator/(const Vector3F& rhs) const
{
	return XMVectorDivide(m_values, rhs);
}

Vector4F ScalarF::operator*(const Vector4F& rhs) const
{
	return XMVectorMultiply(m_values, rhs);
}

Vector4F ScalarF::operator/(const Vector4F& rhs) const
{
	return XMVectorDivide(m_values, rhs);
}

bool ScalarF::operator==(const ScalarF& rhs) const
{
	return GetValue() == rhs.GetValue();
}

bool ScalarF::operator!=(const ScalarF& rhs) const
{
	return GetValue() != rhs.GetValue();
}

bool ScalarF::NearEqual(const ScalarF& rhs, const ScalarF& epsilon) const
{
	return XMScalarNearEqual(GetValue(), rhs.GetValue(), epsilon.GetValue());
}

ScalarF::ScalarF(SimdVector values) :
	m_values(values)
{
}

ScalarF::operator SimdVector() const
{
	return m_values;
}