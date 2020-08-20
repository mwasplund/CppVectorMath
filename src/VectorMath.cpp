// <copyright file="VectorMath.h" company="mwasplund"> 
//  Copyright (c) mwasplund. All rights reserved.
// </copyright>

module;

#include <iostream>
#include <array>

export module VectorMath;

namespace VectorMath
{
	export typedef std::array<float, 4> SimdVector;

	// Forward
	export class Matrix4x4F;
	export class QuaternionF;
	export class ScalarF;
	export class Vector2F;
	export class Vector3F;
	export class Vector4F;
}

#include "Matrix4x4F.h"
#include "QuaternionF.h"
#include "ScalarF.h"
#include "ScalarUtils.h"
#include "Vector2F.h"
#include "Vector2Utils.h"
#include "Vector3F.h"
#include "Vector3Utils.h"
#include "Vector4F.h"
#include "Vector4Utils.h"
#include "VectorUtils.h"