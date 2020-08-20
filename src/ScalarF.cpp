// <copyright file="ScalarF.cpp" company="mwasplund"> 
//   Copyright (c) mwasplund. All rights reserved.
// </copyright>

module;

#include <iostream>

module VectorMath;

namespace VectorMath
{
	std::wostream& operator<<(std::wostream& stream, const ScalarF& value)
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
		return ScalarUtils::NearEqual(m_values, rhs, epsilon);
	}

	ScalarF::ScalarF(SimdVector values) :
		m_values(values)
	{
	}

	ScalarF::operator SimdVector() const
	{
		return m_values;
	}
}