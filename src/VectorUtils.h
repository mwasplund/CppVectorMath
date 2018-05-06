// <copyright file="Vector3F.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once

namespace VectorMath
{
	/// <summary>
	/// The floating point vector s3D
	/// </summary>
	class VectorUtils
	{
	public:
		static Vector4F MergeXY(const Vector4F& lhs, const Vector4F& rhs);
		static Vector4F MergeZW(const Vector4F& lhs, const Vector4F& rhs);
	};
}
