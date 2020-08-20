#include <iostream>
#include <numbers>
#include <sstream>

import VectorMath;
import Soup.Test;

using namespace Soup::Test;

#include "Matrix4x4FUnitTests.gen.h"
#include "QuaternionFUnitTests.gen.h"
#include "ScalarFUnitTests.gen.h"
#include "Vector2FUnitTests.gen.h"
#include "Vector3FUnitTests.gen.h"
#include "Vector4FUnitTests.gen.h"

int main()
{
	std::cout << "Running Tests..." << std::endl;

	TestState state = { 0, 0 };

	state += RunMatrix4x4FUnitTests();
	state += RunQuaternionFUnitTests();
	state += RunScalarFUnitTests();
	state += RunVector2FUnitTests();
	state += RunVector3FUnitTests();
	state += RunVector4FUnitTests();

	std::cout << state.PassCount << " PASSED." << std::endl;
	std::cout << state.FailCount << " FAILED." << std::endl;

	if (state.FailCount > 0)
		return 1;
	else
		return 0;
}
