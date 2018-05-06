// <copyright file="ScalarF.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once

namespace VectorMath
{
	/// <summary>
	/// The scalar value
	/// </summary>
	class ScalarF
	{
		friend std::wostream& operator<<(std::wostream& stream, const ScalarF& value);
		friend class Vector4F;
		friend class Vector3F;
		friend class Vector2F;

	public:
		/// <summary>
		/// Defaults
		/// </summary>
		static ScalarF Zero();
		static ScalarF One();

	public:
		/// <summary>
		/// Initialize a new instance of the ScalarF class
		/// </summary>
		ScalarF();
		ScalarF(float value);

		/// <summary>
		/// Named Access
		/// </summary>
		float GetValue() const;
		void SetValue(float value);

		/// <summary>
		/// Assignment Operators
		/// </summary>
		ScalarF& operator=(const ScalarF& rhs);
		ScalarF& operator+=(const ScalarF& rhs);
		ScalarF& operator-=(const ScalarF& rhs);
		ScalarF& operator*=(const ScalarF& rhs);
		ScalarF& operator/=(const ScalarF& rhs);

		/// <summary>
		/// Arithmetic Operators
		/// </summary>
		ScalarF operator-() const;

		ScalarF operator+(const ScalarF& rhs) const;
		ScalarF operator-(const ScalarF& rhs) const;
		ScalarF operator*(const ScalarF& rhs) const;
		ScalarF operator/(const ScalarF& rhs) const;

		Vector2F operator*(const Vector2F& rhs) const;
		Vector2F operator/(const Vector2F& rhs) const;
		Vector3F operator*(const Vector3F& rhs) const;
		Vector3F operator/(const Vector3F& rhs) const;
		Vector4F operator*(const Vector4F& rhs) const;
		Vector4F operator/(const Vector4F& rhs) const;

		/// <summary>
		/// Comparison Operators
		/// </summary>
		bool operator==(const ScalarF& rhs) const;
		bool operator!=(const ScalarF& rhs) const;
		bool NearEqual(const ScalarF& rhs, const ScalarF& epsilon) const;

	private:
		/// <summary>
		/// Raw Access
		/// </summary>
		ScalarF(SimdVector values);
		operator SimdVector() const;

		/// <summary>
		/// The values
		/// </summary>
		SimdVector m_values;
	};
} // namespace VectorMath

