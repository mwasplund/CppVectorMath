// <copyright file="Matrix4x4F.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once
#include "VectorMath.h"
#include "Vector4F.h"

namespace VectorMath
{
	/// <summary>
	/// The matrix 4x4 floating point
	/// </summary>
	__declspec(align(16)) class Matrix4x4F
	{
		friend std::wostream& operator<<(std::wostream& stream, const Matrix4x4F& value);

	public:
		/// <summary>
		/// Get a reference to the identity matrix
		/// </summary>
		static const Matrix4x4F& Identity();

		static Matrix4x4F AffineTransformation(
			const Vector3F& scale,
			const Vector3F& rotationOrigin,
			const QuaternionF& rotation,
			const Vector3F& translation);

		static Matrix4x4F LookAtRH(
			const Vector3F& eyePosition,
			const Vector3F& focusPosition,
			const Vector3F& upDirection);

		static Matrix4x4F LookToRH(
			const Vector3F& eyePosition,
			const Vector3F& eyeDirection,
			const Vector3F& upDirection);

		static Matrix4x4F PerspectiveFovRH(
			float fovAngleY,
			float aspectRatio,
			float depthMin,
			float depthMax);

		static Matrix4x4F Scaling(const Vector3F& scale);
		static Matrix4x4F Translation(const Vector3F& translation);

		/// <summary>
		/// Construct a rotation transform matrix
		/// </summary>
		static Matrix4x4F Rotation(const QuaternionF& rotation);
		static Matrix4x4F RotationX(float angle);
		static Matrix4x4F RotationY(float angle);
		static Matrix4x4F RotationZ(float angle);

	public:
		/// <summary>
		/// Initialize a new instance of the Matrix4x4F class
		/// </summary>
		Matrix4x4F();
		Matrix4x4F(const float* values);
		Matrix4x4F(
			const Vector4F& row0,
			const Vector4F& row1,
			const Vector4F& row2,
			const Vector4F& row3);
		Matrix4x4F(
			float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33);

		/// <summary>
		/// Assignment Operators
		/// </summary>
		Matrix4x4F& operator=(const Matrix4x4F& rhs);
		Matrix4x4F& operator+=(const Matrix4x4F& rhs);
		Matrix4x4F& operator-=(const Matrix4x4F& rhs);
		Matrix4x4F& operator*=(const Matrix4x4F& rhs);

		/// <summary>
		/// Arithmetic Operators
		/// </summary>
		Matrix4x4F operator+(const Matrix4x4F& rhs) const;
		Matrix4x4F operator-(const Matrix4x4F& rhs) const;
		Matrix4x4F operator*(const Matrix4x4F& rhs) const;

		/// <summary>
		/// Comparison Operators
		/// </summary>
		bool operator==(const Matrix4x4F& rhs) const;
		bool operator!=(const Matrix4x4F& rhs) const;

		/// <summary>
		/// Member Access Operators
		/// </summary>
		Vector4F& operator[](size_t index);
		const Vector4F& operator[](size_t index) const;

		/// <summary>
		/// Transpose
		/// </summary>
		Matrix4x4F Transpose() const;

	private:
		/// <summary>
		/// The values
		/// </summary>
		std::array<Vector4F, 4> m_values;
	};
} // namespace VectorMath

