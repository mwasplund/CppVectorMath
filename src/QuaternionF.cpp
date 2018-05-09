// <copyright file="QuaternionF.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "QuaternionF.h"

#include "ScalarF.h"
#include "Vector3F.h"
#include "Vector4F.h"

using namespace VectorMath;

std::wostream& VectorMath::operator<<(std::wostream& stream, const QuaternionF& value)
{
	stream << L"QuaternionF["
		<< value.GetX() << L","
		<< value.GetY() << L","
		<< value.GetZ() << L","
		<< value.GetW() << L"]";

	return stream;
}

/*static*/ QuaternionF QuaternionF::Identity()
{
	return XMQuaternionIdentity();
}

QuaternionF::QuaternionF() :
	m_values()
{
}

QuaternionF::QuaternionF(float pitch, float yaw, float roll) :
	m_values(XMQuaternionRotationRollPitchYaw(pitch, yaw, roll))
{
}

QuaternionF::QuaternionF(const Vector3F& axis, float angle) :
	m_values(XMQuaternionRotationAxis(axis, angle))
{
}

float QuaternionF::GetX() const
{
	return VectorUtils::GetX(m_values);
}

float QuaternionF::GetY() const
{
	return VectorUtils::GetY(m_values);
}

float QuaternionF::GetZ() const
{
	return VectorUtils::GetZ(m_values);
}

float QuaternionF::GetW() const
{
	return VectorUtils::GetW(m_values);
}

QuaternionF& QuaternionF::operator=(const QuaternionF& rhs)
{
	m_values = rhs.m_values;
	return *this;
}

QuaternionF& QuaternionF::operator*=(const QuaternionF& rhs)
{
	*this = *this * rhs;
	return *this;
}

QuaternionF QuaternionF::operator~() const
{
	return XMQuaternionConjugate(m_values);
}

QuaternionF QuaternionF::operator-() const
{
	return VectorUtils::Negate(m_values);
}

QuaternionF QuaternionF::operator*(const QuaternionF& rhs) const
{
	return XMQuaternionMultiply(m_values, rhs);
}

Vector3F QuaternionF::operator*(const Vector3F& rhs) const
{
	return VectorUtils::3Rotate(rhs, m_values);
}

bool QuaternionF::operator==(const QuaternionF& rhs) const
{
	return XMQuaternionEqual(m_values, rhs);
}

bool QuaternionF::operator!=(const QuaternionF& rhs) const
{
	return XMQuaternionNotEqual(m_values, rhs);
}

QuaternionF::QuaternionF(SimdVector values) :
	m_values(values)
{
}

QuaternionF::operator SimdVector() const
{
	return m_values;
}