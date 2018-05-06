// <copyright file="Matrix4x4F.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "Matrix4x4F.h"

#include "MathConstants.h"
#include "QuaternionF.h"
#include "RangeF.h"
#include "ScalarF.h"
#include "Vector3F.h"
#include "VectorUtils.h"

using namespace DirectX;
using namespace VectorMath;

std::wostream& VectorMath::operator<<(std::wostream& stream, const Matrix4x4F& value)
{
	stream << L"["
		<< value[0] << L","
		<< value[1] << L","
		<< value[2] << L","
		<< value[3] << L"]";

	return stream;
}

/*static*/ const Matrix4x4F& Matrix4x4F::Identity()
{
	static Matrix4x4F value = Matrix4x4F(
		Vector4F::UnitX(),
		Vector4F::UnitY(),
		Vector4F::UnitZ(),
		Vector4F::UnitW());
	return value;
}

/*static*/ Matrix4x4F Matrix4x4F::AffineTransformation(
	const Vector3F& scale,
	const Vector3F& rotationOrigin,
	const QuaternionF& rotation,
	const Vector3F& translation)
{
	auto scalingMatrix = Matrix4x4F::Scaling(scale);
	auto rotationOriginVector = Vector4F(rotationOrigin, ScalarF::Zero());
	auto rotationMatrix = Matrix4x4F::Rotation(rotation);
	auto translationVector = Vector4F(translation, ScalarF::Zero());

	// result = scalingMatrix * Inverse(rotationOriginMatrix) * rotationMatrix * rotationOriginMatrix * translationMatrix;
	auto result = scalingMatrix;
	result[3] -= rotationOriginVector;
	result *= rotationMatrix;
	result[3] += rotationOriginVector;
	result[3] += translationVector;

	return result;
}

/*static*/ Matrix4x4F Matrix4x4F::LookAtRH(
	const Vector3F& eyePosition,
	const Vector3F& focusPosition,
	const Vector3F& upDirection)
{
	// Look at right handed
	// Using the eye direction calculate the look to matrix
	Vector3F eyeDirection = focusPosition - eyePosition;
	return Matrix4x4F::LookToRH(eyePosition, eyeDirection, upDirection);
}

/*static*/ Matrix4x4F Matrix4x4F::LookToRH(
	const Vector3F& eyePosition,
	const Vector3F& eyeDirection,
	const Vector3F& upDirection)
{
	// Look to right handed
	assert(eyeDirection != Vector3F::Zero());
	assert(!eyeDirection.IsInfinite());
	assert(upDirection != Vector3F::Zero());
	assert(!upDirection.IsInfinite());

	Vector3F r2 = -eyeDirection.Normalize();

	Vector3F r0 = Vector3F::Cross(upDirection, r2);
	r0 = r0.Normalize();

	Vector3F r1 = Vector3F::Cross(r2, r0);

	Vector3F negEyePosition = -eyePosition;

	auto d0 = Vector3F::Dot(r0, negEyePosition);
	auto d1 = Vector3F::Dot(r1, negEyePosition);
	auto d2 = Vector3F::Dot(r2, negEyePosition);

	Matrix4x4F result;
	result[0] = Vector4F(r0, d0);
	result[1] = Vector4F(r1, d1);
	result[2] = Vector4F(r2, d2);
	result[3] = Matrix4x4F::Identity()[3];

	result = result.Transpose();

	return result;
}

/*static*/ Matrix4x4F Matrix4x4F::PerspectiveFovRH(
	float fovAngleY,
	float aspectRatio,
	const RangeF& depth)
{
	// TODO : SIMD VERSIONS
	float sinFov = std::sin(0.5f * fovAngleY);
	float cosFov = std::cos(0.5f * fovAngleY);

	float height = cosFov / sinFov;
	float width = height / aspectRatio;
	float fRange = depth.GetMax() / (depth.GetMin() - depth.GetMax());

	Matrix4x4F result;
	result[0] = Vector4F(width, 0.0f, 0.0f, 0.0f);
	result[1] = Vector4F(0.0f, height, 0.0f, 0.0f);
	result[2] = Vector4F(0.0f, 0.0f, fRange, -1.0f);
	result[3] = Vector4F(0.0f, 0.0f, (fRange * depth.GetMin()), 0.0f);

	return result;
}

/*static*/ Matrix4x4F Matrix4x4F::Scaling(const Vector3F& scale)
{
	auto dxMatrix = XMMatrixScalingFromVector(scale);

	// Convert to our matrix container
	Matrix4x4F result;
	result[0] = dxMatrix.r[0];
	result[1] = dxMatrix.r[1];
	result[2] = dxMatrix.r[2];
	result[3] = dxMatrix.r[3];

	return result;
}

/*static*/ Matrix4x4F Matrix4x4F::Translation(const Vector3F& scale)
{
	auto dxMatrix = XMMatrixTranslationFromVector(scale);

	// Convert to our matrix container
	Matrix4x4F result;
	result[0] = dxMatrix.r[0];
	result[1] = dxMatrix.r[1];
	result[2] = dxMatrix.r[2];
	result[3] = dxMatrix.r[3];

	return result;
}

/*static*/ Matrix4x4F Matrix4x4F::Rotation(const QuaternionF& rotation)
{
	auto dxMatrix = XMMatrixRotationQuaternion(rotation);

	// Convert to our matrix container
	Matrix4x4F result;
	result[0] = dxMatrix.r[0];
	result[1] = dxMatrix.r[1];
	result[2] = dxMatrix.r[2];
	result[3] = dxMatrix.r[3];

	return result;
}

/*static*/ Matrix4x4F Matrix4x4F::RotationX(float angle)
{
	float sinAngle = std::sin(angle);
	float cosAngle = std::cos(angle);

	Matrix4x4F result;
	result[0] = Vector4F(1.0f, 0.0f, 0.0f, 0.0f);
	result[1] = Vector4F(0.0f, cosAngle, sinAngle, 0.0f);
	result[2] = Vector4F(0.0f, -sinAngle, cosAngle, 0.0f);
	result[3] = Vector4F(0.0f, 0.0f, 0.0f, 1.0f);

	return result;
}

/*static*/ Matrix4x4F Matrix4x4F::RotationY(float angle)
{
	float sinAngle = std::sin(angle);
	float cosAngle = std::cos(angle);

	Matrix4x4F result;
	result[0] = Vector4F(cosAngle, 0.0f, -sinAngle, 0.0f);
	result[1] = Vector4F(0.0f, 1.0f, 0.0f, 0.0f);
	result[2] = Vector4F(sinAngle, 0.0f, cosAngle, 0.0f);
	result[3] = Vector4F(0.0f, 0.0f, 0.0f, 1.0f);

	return result;
}

/*static*/ Matrix4x4F Matrix4x4F::RotationZ(float angle)
{
	float sinAngle = std::sin(angle);
	float cosAngle = std::cos(angle);

	Matrix4x4F result;
	result[0] = Vector4F(cosAngle, sinAngle, 0.0f, 0.0f);
	result[1] = Vector4F(-sinAngle, cosAngle, 0.0f, 0.0f);
	result[2] = Vector4F(0.0f, 0.0f, 1.0f, 0.0f);
	result[3] = Vector4F(0.0f, 0.0f, 0.0f, 1.0f);

	return result;
}

Matrix4x4F::Matrix4x4F() :
	m_values({ Vector4F(), Vector4F(), Vector4F(), Vector4F() })
{
}

Matrix4x4F::Matrix4x4F(const float* values) :
	m_values({ 
		Vector4F(values[0], values[1], values[2], values[3]),
		Vector4F(values[4], values[5], values[6], values[7]),
		Vector4F(values[8], values[9], values[10], values[11]),
		Vector4F(values[12], values[13], values[14], values[15]) })
{
}

Matrix4x4F::Matrix4x4F(
	const Vector4F& row0,
	const Vector4F& row1,
	const Vector4F& row2,
	const Vector4F& row3) :
	m_values({ row0, row1, row2, row3 })
{
}

Matrix4x4F::Matrix4x4F(
	float m00, float m01, float m02, float m03,
	float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23,
	float m30, float m31, float m32, float m33) :
	m_values({
		Vector4F(m00, m01, m02, m03),
		Vector4F(m10, m11, m12, m13),
		Vector4F(m20, m21, m22, m23),
		Vector4F(m30, m31, m32, m33) })
{
}

Matrix4x4F& Matrix4x4F::operator=(const Matrix4x4F& rhs)
{
	m_values = rhs.m_values;
	return *this;
}

Matrix4x4F& Matrix4x4F::operator+=(const Matrix4x4F& rhs)
{
	*this = *this + rhs;
	return *this;
}

Matrix4x4F& Matrix4x4F::operator-=(const Matrix4x4F& rhs)
{
	*this = *this - rhs;
	return *this;
}

Matrix4x4F& Matrix4x4F::operator*=(const Matrix4x4F& rhs)
{
	*this = *this * rhs;
	return *this;
}

Matrix4x4F Matrix4x4F::operator+(const Matrix4x4F& rhs) const
{
	return Matrix4x4F(
		m_values[0] + rhs[0],
		m_values[1] + rhs[1],
		m_values[2] + rhs[2],
		m_values[3] + rhs[3]);
}

Matrix4x4F Matrix4x4F::operator-(const Matrix4x4F& rhs) const
{
	return Matrix4x4F(
		m_values[0] - rhs[0],
		m_values[1] - rhs[1],
		m_values[2] - rhs[2],
		m_values[3] - rhs[3]);
}

Matrix4x4F Matrix4x4F::operator*(const Matrix4x4F& rhs) const
{
	Matrix4x4F result;

	// Cache the invariants in registers
	Vector4F row = m_values[0];

	// Perform the operation on the first row
	result[0] = (rhs[0] * row.GetX()) + (rhs[1] * row.GetY()) + (rhs[2] * row.GetZ()) + (rhs[3] * row.GetW());

	// Repeat for all the other rows
	row = m_values[1];
	result[1] = (rhs[0] * row.GetX()) + (rhs[1] * row.GetY()) + (rhs[2] * row.GetZ()) + (rhs[3] * row.GetW());

	row = m_values[2];
	result[2] = (rhs[0] * row.GetX()) + (rhs[1] * row.GetY()) + (rhs[2] * row.GetZ()) + (rhs[3] * row.GetW());

	row = m_values[3];
	result[3] = (rhs[0] * row.GetX()) + (rhs[1] * row.GetY()) + (rhs[2] * row.GetZ()) + (rhs[3] * row.GetW());

	return result;
}

bool Matrix4x4F::operator==(const Matrix4x4F& rhs) const
{
	return
		m_values[0] == rhs[0] &&
		m_values[1] == rhs[1] &&
		m_values[2] == rhs[2] &&
		m_values[3] == rhs[3];
}

bool Matrix4x4F::operator!=(const Matrix4x4F& rhs) const
{
	return
		m_values[0] != rhs[0] ||
		m_values[1] != rhs[1] ||
		m_values[2] != rhs[2] ||
		m_values[3] != rhs[3];
}

Vector4F& Matrix4x4F::operator[](size_t index)
{
#ifdef _DEBUG
	return m_values.at(index);
#else
	return m_values[index];
#endif
}

const Vector4F& Matrix4x4F::operator[](size_t index) const
{
#ifdef _DEBUG
	return m_values.at(index);
#else
	return m_values[index];
#endif
}

Matrix4x4F Matrix4x4F::Transpose() const
{
	Matrix4x4F p;
	p[0] = VectorUtils::MergeXY(m_values[0], m_values[2]);
	p[1] = VectorUtils::MergeXY(m_values[1], m_values[3]);
	p[2] = VectorUtils::MergeZW(m_values[0], m_values[2]);
	p[3] = VectorUtils::MergeZW(m_values[1], m_values[3]);

	Matrix4x4F result;
	result[0] = VectorUtils::MergeXY(p[0], p[1]);
	result[1] = VectorUtils::MergeZW(p[0], p[1]);
	result[2] = VectorUtils::MergeXY(p[2], p[3]);
	result[3] = VectorUtils::MergeZW(p[2], p[3]);

	return result;
}
