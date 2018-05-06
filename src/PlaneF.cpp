// <copyright file="PlaneF.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "PlaneF.h"

#include "Point4F.h"

using namespace DirectX;
using namespace VectorMath;

std::wostream& VectorMath::operator<<(std::wostream& stream, const PlaneF& value)
{
	auto values = value.GetValues();
	stream << L"PlaneF["
		<< values.GetX() << L","
		<< values.GetY() << L","
		<< values.GetZ() << L","
		<< values.GetW() << L"]";

	return stream;
}

PlaneF::PlaneF() :
	m_values()
{
}

PlaneF::PlaneF(const Vector3F& point, const Vector3F& normal) :
	m_values()
{
	// TODO
	(point);
	(normal);
}

Point4F PlaneF::GetValues() const
{
	XMFLOAT4 values;
	XMStoreFloat4(&values, m_values);
	return Point4F(values.x, values.y, values.z, values.w);
}

PlaneF& PlaneF::operator=(const PlaneF& rhs)
{
	m_values = rhs.m_values;
	return *this;
}

bool PlaneF::operator==(const PlaneF& rhs) const
{
	return XMPlaneEqual(m_values, rhs);
}

bool PlaneF::operator!=(const PlaneF& rhs) const
{
	return XMPlaneNotEqual(m_values, rhs);
}

PlaneF::PlaneF(SimdVector values) :
	m_values(values)
{
}

PlaneF::operator SimdVector() const
{
	return m_values;
}
