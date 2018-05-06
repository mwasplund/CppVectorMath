// <copyright file="Vector3F.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "VectorUtils.h"

#include "Vector4F.h"

using namespace DirectX;
using namespace VectorMath;

Vector4F VectorUtils::MergeXY(const Vector4F& lhs, const Vector4F& rhs)
{
	return XMVectorMergeXY(lhs, rhs);
}

Vector4F VectorUtils::MergeZW(const Vector4F& lhs, const Vector4F& rhs)
{
	return XMVectorMergeZW(lhs, rhs);
}
