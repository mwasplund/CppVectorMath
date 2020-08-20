// <copyright file="Vector2F.cpp" company="mwasplund"> 
//   Copyright (c) mwasplund. All rights reserved.
// </copyright>

module;

#include <iostream>

module VectorMath;

namespace VectorMath
{
	std::wostream& operator<<(std::wostream& stream, const Vector2F& value)
	{
		auto values = value.GetValues();
		stream << L"["
			<< values[0] << L","
			<< values[1] << L"]";

		return stream;
	}

	/*static*/ Vector2F Vector2F::Zero()
	{
		return VectorUtils::Zero();
	}

	/*static*/ Vector2F Vector2F::One()
	{
		return VectorUtils::One();
	}

	/*static*/ Vector2F Vector2F::UnitX()
	{
		return VectorUtils::UnitX();
	}

	/*static*/ Vector2F Vector2F::UnitY()
	{
		return VectorUtils::UnitY();
	}

	Vector2F::Vector2F() :
		m_values(VectorUtils::Zero())
	{
	}

	Vector2F::Vector2F(float x, float y) :
		m_values({ x, y })
	{
	}

	std::array<float, 2> Vector2F::GetValues() const
	{
		return Vector2Utils::Store(m_values);
	}

	ScalarF Vector2F::GetX() const
	{
		return VectorUtils::SplatX(m_values);
	}

	ScalarF Vector2F::GetY() const
	{
		return VectorUtils::SplatY(m_values);
	}

	void Vector2F::SetX(float value)
	{
		m_values = VectorUtils::SetX(m_values, value);
	}

	void Vector2F::SetY(float value)
	{
		m_values = VectorUtils::SetY(m_values, value);
	}

	ScalarF Vector2F::Length() const
	{
		return Vector2Utils::Length(m_values);
	}

	Vector2F Vector2F::Normalize() const
	{
		return Vector2Utils::Normalize(m_values);
	}

	bool Vector2F::IsNaN() const
	{
		return Vector2Utils::IsNaN(m_values);
	}

	bool Vector2F::IsInfinite() const
	{
		return Vector2Utils::IsInfinite(m_values);
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
		return VectorUtils::Negate(m_values);
	}

	Vector2F Vector2F::operator+(const Vector2F& rhs) const
	{
		return VectorUtils::Add(m_values, rhs);
	}

	Vector2F Vector2F::operator-(const Vector2F& rhs) const
	{
		return VectorUtils::Subtract(m_values, rhs);
	}

	Vector2F Vector2F::operator*(const Vector2F& rhs) const
	{
		return VectorUtils::Multiply(m_values, rhs);
	}

	Vector2F Vector2F::operator/(const Vector2F& rhs) const
	{
		return VectorUtils::Divide(m_values, rhs);
	}

	Vector2F Vector2F::operator*(const ScalarF& rhs) const
	{
		return VectorUtils::Multiply(m_values, rhs);
	}

	Vector2F Vector2F::operator/(const ScalarF& rhs) const
	{
		return VectorUtils::Divide(m_values, rhs);
	}

	bool Vector2F::operator==(const Vector2F& rhs) const
	{
		return Vector2Utils::Equal(m_values, rhs);
	}

	bool Vector2F::operator!=(const Vector2F& rhs) const
	{
		return Vector2Utils::NotEqual(m_values, rhs);
	}

	bool Vector2F::NearEqual(const Vector2F& rhs, const ScalarF& epsilon) const
	{
		return Vector2Utils::NearEqual(m_values, rhs, epsilon);
	}

	Vector2F::Vector2F(SimdVector values) :
		m_values(values)
	{
	}

	Vector2F::operator SimdVector() const
	{
		return m_values;
	}
}