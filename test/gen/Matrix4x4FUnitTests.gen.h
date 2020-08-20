#pragma once
#include "Matrix4x4FUnitTests.h"

TestState RunMatrix4x4FUnitTests()
{
	auto className = "Matrix4x4FUnitTests";
	auto testClass = std::make_shared<VectorMath::UnitTests::Matrix4x4FUnitTests>();
	TestState state = { 0, 0 };
	state += Soup::Test::RunTest(className, "Static_Identity", [&testClass]() { testClass->Static_Identity(); });
	// state += Soup::Test::RunTest(className, "Static_AffineTransformation", [&testClass]() { testClass->Static_AffineTransformation(); });
	// state += Soup::Test::RunTest(className, "Static_LookAtRH", [&testClass]() { testClass->Static_LookAtRH(); });
	// state += Soup::Test::RunTest(className, "Static_PerspectiveFovRH", [&testClass]() { testClass->Static_PerspectiveFovRH(); });
	// state += Soup::Test::RunTest(className, "Static_Scaling", [&testClass]() { testClass->Static_Scaling(); });
	// state += Soup::Test::RunTest(className, "Static_Rotation_OneVector", [&testClass]() { testClass->Static_Rotation_OneVector(); });
	// state += Soup::Test::RunTest(className, "Static_RotationX", [&testClass]() { testClass->Static_RotationX(); });
	// state += Soup::Test::RunTest(className, "Static_RotationY", [&testClass]() { testClass->Static_RotationY(); });
	// state += Soup::Test::RunTest(className, "Static_RotationZ", [&testClass]() { testClass->Static_RotationZ(); });
	state += Soup::Test::RunTest(className, "Initialize_Default", [&testClass]() { testClass->Initialize_Default(); });
	state += Soup::Test::RunTest(className, "Initialize_Values", [&testClass]() { testClass->Initialize_Values(); });
	state += Soup::Test::RunTest(className, "Initialize_Rows", [&testClass]() { testClass->Initialize_Rows(); });
	state += Soup::Test::RunTest(className, "Initialize_Array", [&testClass]() { testClass->Initialize_Array(); });
	state += Soup::Test::RunTest(className, "Set_Row0", [&testClass]() { testClass->Set_Row0(); });
	state += Soup::Test::RunTest(className, "Set_Row1", [&testClass]() { testClass->Set_Row1(); });
	state += Soup::Test::RunTest(className, "Set_Row2", [&testClass]() { testClass->Set_Row2(); });
	state += Soup::Test::RunTest(className, "Set_Row3", [&testClass]() { testClass->Set_Row3(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment", [&testClass]() { testClass->Operator_Assignment(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment_Add", [&testClass]() { testClass->Operator_Assignment_Add(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment_Subtract", [&testClass]() { testClass->Operator_Assignment_Subtract(); });
	// state += Soup::Test::RunTest(className, "Operator_Assignment_Multiply", [&testClass]() { testClass->Operator_Assignment_Multiply(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_Add", [&testClass]() { testClass->Operator_Arithmetic_Add(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_Subtract", [&testClass]() { testClass->Operator_Arithmetic_Subtract(); });
	// state += Soup::Test::RunTest(className, "Operator_Arithmetic_Multiply", [&testClass]() { testClass->Operator_Arithmetic_Multiply(); });
	state += Soup::Test::RunTest(className, "Operator_Comparison", [&testClass]() { testClass->Operator_Comparison(); });
	return state;
}