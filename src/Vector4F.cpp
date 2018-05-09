// <copyright file="Vector4F.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "Vector4F.h"

#include "VectorUtils.h"
#include "Vector4Utils.h"
#include "ScalarF.h"
#include "Vector2F.h"
#include "Vector3F.h"

using namespace VectorMath;

std::wostream& VectorMath::operator<<(std::wostream& stream, const Vector4F& value)
{
	auto values = value.GetValues();
	stream << L"["
		<< values[0] << L","
		<< values[1] << L","
		<< values[2] << L","
		<< values[3] << L"]";

	return stream;
}

/*static*/ Vector4F Vector4F::Zero()
{
	return VectorUtils::Zero();
}

/*static*/ Vector4F Vector4F::One()
{
	return VectorUtils::One();
}

/*static*/ Vector4F Vector4F::UnitX()
{
	return VectorUtils::UnitX();
}

/*static*/ Vector4F Vector4F::UnitY()
{
	return VectorUtils::UnitY();
}

/*static*/ Vector4F Vector4F::UnitZ()
{
	return VectorUtils::UnitZ();
}

/*static*/ Vector4F Vector4F::UnitW()
{
	return VectorUtils::UnitW();
}

Vector4F::Vector4F() :
	m_values(VectorUtils::Zero())
{
}

Vector4F::Vector4F(const Vector3F& xyz, const ScalarF& w) :
	m_values(VectorUtils::SetW(xyz, VectorUtils::GetX(w)))
{
}

Vector4F::Vector4F(float x, float y, float z, float w) :
	m_values(VectorUtils::Set(x, y, z, w))
{
}

std::array<float, 4> Vector4F::GetValues() const
{
	return Vector4Utils::Store(m_values);
}

ScalarF Vector4F::GetX() const
{
	return VectorUtils::SplatX(m_values);
}

ScalarF Vector4F::GetY() const
{
	return VectorUtils::SplatY(m_values);
}

ScalarF Vector4F::GetZ() const
{
	return VectorUtils::SplatZ(m_values);
}

ScalarF Vector4F::GetW() const
{
	return VectorUtils::SplatW(m_values);
}

void Vector4F::SetX(float value)
{
	m_values = VectorUtils::SetX(m_values, value);
}

void Vector4F::SetY(float value)
{
	m_values = VectorUtils::SetY(m_values, value);
}

void Vector4F::SetZ(float value)
{
	m_values = VectorUtils::SetZ(m_values, value);
}

void Vector4F::SetW(float value)
{
	m_values = VectorUtils::SetW(m_values, value);
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
	return VectorUtils::Negate(m_values);
}

Vector4F Vector4F::operator+(const Vector4F& rhs) const
{
	return VectorUtils::Add(m_values, rhs);
}

Vector4F Vector4F::operator-(const Vector4F& rhs) const
{
	return VectorUtils::Subtract(m_values, rhs);
}

Vector4F Vector4F::operator*(const Vector4F& rhs) const
{
	return VectorUtils::Multiply(m_values, rhs);
}

Vector4F Vector4F::operator/(const Vector4F& rhs) const
{
	return VectorUtils::Divide(m_values, rhs);
}

Vector4F Vector4F::operator*(const ScalarF& rhs) const
{
	return VectorUtils::Multiply(m_values, rhs);
};

Vector4F Vector4F::operator/(const ScalarF& rhs) const
{
	return VectorUtils::Divide(m_values, rhs);
}

bool Vector4F::operator==(const Vector4F& rhs) const
{
	return Vector4Utils::Equal(m_values, rhs);
}

bool Vector4F::operator!=(const Vector4F& rhs) const
{
	return Vector4Utils::NotEqual(m_values, rhs);
}

bool Vector4F::NearEqual(const Vector4F& rhs, const ScalarF& epsilon) const
{
	return Vector4Utils::NearEqual(m_values, rhs, epsilon);
}

Vector4F::Vector4F(SimdVector values) :
	m_values(values)
{
}

Vector4F::operator SimdVector() const
{
	return m_values;
}