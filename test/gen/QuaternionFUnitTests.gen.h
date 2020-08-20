#pragma once
#include "QuaternionFUnitTests.h"

TestState RunQuaternionFUnitTests()
{
	auto className = "QuaternionFUnitTests";
	auto testClass = std::make_shared<VectorMath::UnitTests::QuaternionFUnitTests>();
	TestState state = { 0, 0 };
	state += Soup::Test::RunTest(className, "Static_Identity", [&testClass]() { testClass->Static_Identity(); });
	state += Soup::Test::RunTest(className, "Initialize_Default", [&testClass]() { testClass->Initialize_Default(); });
	// state += Soup::Test::RunTest(className, "Initialize_YawPitchRoll_Zero", [&testClass]() { testClass->Initialize_YawPitchRoll_Zero(); });
	// state += Soup::Test::RunTest(className, "Operator_Assignment", [&testClass]() { testClass->Operator_Assignment(); });
	// state += Soup::Test::RunTest(className, "Operator_Assignment_Multiply", [&testClass]() { testClass->Operator_Assignment_Multiply(); });
	// state += Soup::Test::RunTest(className, "Operator_Arithmatic_Conjugate", [&testClass]() { testClass->Operator_Arithmatic_Conjugate(); });
	// state += Soup::Test::RunTest(className, "Operator_Arithmetic_Negate", [&testClass]() { testClass->Operator_Assignment(); });
	// state += Soup::Test::RunTest(className, "Operator_Arithmetic_Multiply", [&testClass]() { testClass->Operator_Arithmetic_Multiply(); });
	// state += Soup::Test::RunTest(className, "Operator_Arithmetic_MultiplyVector", [&testClass]() { testClass->Operator_Arithmetic_MultiplyVector(); });
	// state += Soup::Test::RunTest(className, "Operator_Comparison", [&testClass]() { testClass->Operator_Comparison(); });
	return state;
}