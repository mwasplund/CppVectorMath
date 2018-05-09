// <copyright file="ScalarF.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "ScalarF.h"

#include "ScalarUtils.h"
#include "VectorUtils.h"
#include "Vector2F.h"
#include "Vector3F.h"
#include "Vector4F.h"

using namespace VectorMath;

std::wostream& VectorMath::operator<<(std::wostream& stream, const ScalarF& value)
{
	stream << L"[" << value.GetValue() << L"]";
	return stream;
}

/*static*/ ScalarF ScalarF::Zero()
{
	return VectorUtils::Zero();
}

/*static*/ ScalarF ScalarF::One()
{
	return VectorUtils::One();
}

ScalarF::ScalarF() :
	m_values()
{
}

ScalarF::ScalarF(float value) :
	m_values(VectorUtils::Replicate(value))
{
}

float ScalarF::GetValue() const
{
	return VectorUtils::GetX(m_values);
}

void ScalarF::SetValue(float value)
{
	m_values = VectorUtils::Replicate(value);
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
	return VectorUtils::Negate(m_values);
}

ScalarF ScalarF::operator+(const ScalarF& rhs) const
{
	return VectorUtils::Add(m_values, rhs);
}

ScalarF ScalarF::operator-(const ScalarF& rhs) const
{
	return VectorUtils::Subtract(m_values, rhs);
}

ScalarF ScalarF::operator*(const ScalarF& rhs) const
{
	return VectorUtils::Multiply(m_values, rhs);
}

ScalarF ScalarF::operator/(const ScalarF& rhs) const
{
	return VectorUtils::Divide(m_values, rhs);
}

Vector2F ScalarF::operator*(const Vector2F& rhs) const
{
	return VectorUtils::Multiply(m_values, rhs);
}

Vector2F ScalarF::operator/(const Vector2F& rhs) const
{
	return VectorUtils::Divide(m_values, rhs);
}

Vector3F ScalarF::operator*(const Vector3F& rhs) const
{
	return VectorUtils::Multiply(m_values, rhs);
}

Vector3F ScalarF::operator/(const Vector3F& rhs) const
{
	return VectorUtils::Divide(m_values, rhs);
}

Vector4F ScalarF::operator*(const Vector4F& rhs) const
{
	return VectorUtils::Multiply(m_values, rhs);
}

Vector4F ScalarF::operator/(const Vector4F& rhs) const
{
	return VectorUtils::Divide(m_values, rhs);
}

bool ScalarF::operator==(const ScalarF& rhs) const
{
	return ScalarUtils::Equal(m_values, rhs);
}

bool ScalarF::operator!=(const ScalarF& rhs) const
{
	return ScalarUtils::NotEqual(m_values, rhs);
}

bool ScalarF::NearEqual(const ScalarF& rhs, const ScalarF& epsilon) const
{
	return VectorUtils::NearEqual(m_values, rhs, epsilon);
}

ScalarF::ScalarF(SimdVector values) :
	m_values(values)
{
}

ScalarF::operator SimdVector() const
{
	return m_values;
}