// <copyright file="QuaternionF.cpp" company="mwasplund"> 
//   Copyright (c) mwasplund. All rights reserved.
// </copyright>

module;

#include <iostream>

module VectorMath;

namespace VectorMath
{
	std::wostream& operator<<(std::wostream& stream, const QuaternionF& value)
	{
		auto values = value.GetValues();
		stream << L"QuaternionF["
			<< values[0] << L","
			<< values[1] << L","
			<< values[2] << L","
			<< values[3] << L"]";

		return stream;
	}

	/*static*/ QuaternionF QuaternionF::Identity()
	{
		return QuaternionF(SimdVector({ 0.0f, 0.0f, 0.0f, 1.0f }));
	}

	QuaternionF::QuaternionF() :
		m_values()
	{
	}

	QuaternionF::QuaternionF(float pitch, float yaw, float roll) :
		m_values() // TODO: XMQuaternionRotationRollPitchYaw(pitch, yaw, roll))
	{
	}

	QuaternionF::QuaternionF(const Vector3F& axis, float angle) :
		m_values() // TODO: XMQuaternionRotationAxis(axis, angle))
	{
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

	std::array<float, 4> QuaternionF::GetValues() const
	{
		return m_values;
	}

	QuaternionF QuaternionF::operator~() const
	{
		return *this; // TODO: XMQuaternionConjugate(m_values);
	}

	QuaternionF QuaternionF::operator-() const
	{
		return VectorUtils::Negate(m_values);
	}

	QuaternionF QuaternionF::operator*(const QuaternionF& rhs) const
	{
		return *this; // TODO: XMQuaternionMultiply(m_values, rhs);
	}

	Vector3F QuaternionF::operator*(const Vector3F& rhs) const
	{
		return Vector3F(); // TODO: VectorUtils::Rotate(rhs, m_values);
	}

	bool QuaternionF::operator==(const QuaternionF& rhs) const
	{
		return false; // TODO: XMQuaternionEqual(m_values, rhs);
	}

	bool QuaternionF::operator!=(const QuaternionF& rhs) const
	{
		return false; // TODO: XMQuaternionNotEqual(m_values, rhs);
	}

	QuaternionF::QuaternionF(SimdVector values) :
		m_values(values)
	{
	}

	QuaternionF::operator SimdVector() const
	{
		return m_values;
	}
}