// <copyright file="Vector3F.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "Vector3F.h"

#include "Vector3Utils.h"
#include "VectorUtils.h"
#include "ScalarF.h"

using namespace VectorMath;

std::wostream& VectorMath::operator<<(std::wostream& stream, const Vector3F& value)
{
	auto values = value.GetValues();
	stream << L"["
		<< values[0] << L","
		<< values[1] << L","
		<< values[2] << L"]";

	return stream;
}

/*static*/ Vector3F Vector3F::Zero()
{
	return VectorUtils::Zero();
}

/*static*/ Vector3F Vector3F::One()
{
	return VectorUtils::One();
}

/*static*/ Vector3F Vector3F::UnitX()
{
	return VectorUtils::UnitX();
}

/*static*/ Vector3F Vector3F::UnitY()
{
	return VectorUtils::UnitY();
}

/*static*/ Vector3F Vector3F::UnitZ()
{
	return VectorUtils::UnitZ();
}

/*static*/ Vector3F Vector3F::Cross(const Vector3F& lhs, const Vector3F& rhs)
{
	return Vector3Utils::Cross(lhs, rhs);
}

/*static*/ ScalarF Vector3F::Dot(const Vector3F& lhs, const Vector3F& rhs)
{
	return Vector3Utils::Dot(lhs, rhs);
}

Vector3F::Vector3F() :
	m_values()
{
}

Vector3F::Vector3F(float x, float y, float z) :
	m_values(VectorUtils::Set(x, y, z, 0))
{
}

std::array<float, 3> Vector3F::GetValues() const
{
	return Vector3Utils::Store(m_values);
}

ScalarF Vector3F::GetX() const
{
	return VectorUtils::SplatX(m_values);
}

ScalarF Vector3F::GetY() const
{
	return VectorUtils::SplatY(m_values);
}

ScalarF Vector3F::GetZ() const
{
	return VectorUtils::SplatZ(m_values);
}

void Vector3F::SetX(float value)
{
	m_values = VectorUtils::SetX(m_values, value);
}

void Vector3F::SetY(float value)
{
	m_values = VectorUtils::SetY(m_values, value);
}

void Vector3F::SetZ(float value)
{
	m_values = VectorUtils::SetZ(m_values, value);
}

ScalarF Vector3F::Length() const
{
	return Vector3Utils::Length(m_values);
}

Vector3F Vector3F::Normalize() const
{
	return Vector3Utils::Normalize(m_values);
}

bool Vector3F::IsNaN() const
{
	return Vector3Utils::IsNaN(m_values);
}

bool Vector3F::IsInfinite() const
{
	return Vector3Utils::IsInfinite(m_values);
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
	return VectorUtils::Negate(m_values);
}

Vector3F Vector3F::operator+(const Vector3F& rhs) const
{
	return VectorUtils::Add(m_values, rhs);
}

Vector3F Vector3F::operator-(const Vector3F& rhs) const
{
	return VectorUtils::Subtract(m_values, rhs);
}

Vector3F Vector3F::operator*(const Vector3F& rhs) const
{
	return VectorUtils::Multiply(m_values, rhs);
}

Vector3F Vector3F::operator/(const Vector3F& rhs) const
{
	return VectorUtils::Divide(m_values, rhs);
}

Vector3F Vector3F::operator*(const ScalarF& rhs) const
{
	return VectorUtils::Multiply(m_values, rhs);
}

Vector3F Vector3F::operator/(const ScalarF& rhs) const
{
	return VectorUtils::Divide(m_values, rhs);
}

bool Vector3F::operator==(const Vector3F& rhs) const
{
	return VectorUtils::3Equal(m_values, rhs);
}

bool Vector3F::operator!=(const Vector3F& rhs) const
{
	return VectorUtils::3NotEqual(m_values, rhs);
}

bool Vector3F::NearEqual(const Vector3F& rhs, const ScalarF& epsilon) const
{
	return VectorUtils::3NearEqual(m_values, rhs, epsilon);
}

Vector3F::Vector3F(SimdVector values) :
	m_values(values)
{
}

Vector3F::operator SimdVector() const
{
	return m_values;
}