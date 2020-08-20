#pragma once
#include "Vector3FUnitTests.h"

TestState RunVector3FUnitTests()
{
	auto className = "Vector3FUnitTests";
	auto testClass = std::make_shared<VectorMath::UnitTests::Vector3FUnitTests>();
	TestState state = { 0, 0 };
	state += Soup::Test::RunTest(className, "Stream", [&testClass]() { testClass->Stream(); });
	state += Soup::Test::RunTest(className, "Initialize_Zero", [&testClass]() { testClass->Initialize_Zero(); });
	state += Soup::Test::RunTest(className, "Initialize_One", [&testClass]() { testClass->Initialize_One(); });
	state += Soup::Test::RunTest(className, "Initialize_UnitX", [&testClass]() { testClass->Initialize_UnitX(); });
	state += Soup::Test::RunTest(className, "Initialize_UnitY", [&testClass]() { testClass->Initialize_UnitY(); });
	state += Soup::Test::RunTest(className, "Initialize_UnitZ", [&testClass]() { testClass->Initialize_UnitZ(); });
	state += Soup::Test::RunTest(className, "Initialize_Default", [&testClass]() { testClass->Initialize_Default(); });
	state += Soup::Test::RunTest(className, "Initialize_Values", [&testClass]() { testClass->Initialize_Values(); });
	state += Soup::Test::RunTest(className, "Set_X", [&testClass]() { testClass->Set_X(); });
	state += Soup::Test::RunTest(className, "Set_Y", [&testClass]() { testClass->Set_Y(); });
	state += Soup::Test::RunTest(className, "Set_Z", [&testClass]() { testClass->Set_Z(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment", [&testClass]() { testClass->Operator_Assignment(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment_Add", [&testClass]() { testClass->Operator_Assignment_Add(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment_Subtract", [&testClass]() { testClass->Operator_Assignment_Subtract(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment_Multiply", [&testClass]() { testClass->Operator_Assignment_Multiply(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment_MultiplyScalar", [&testClass]() { testClass->Operator_Assignment_MultiplyScalar(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment_Divide", [&testClass]() { testClass->Operator_Assignment_Divide(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment_DivideScalar", [&testClass]() { testClass->Operator_Assignment_DivideScalar(); });
	state += Soup::Test::RunTest(className, "Operator_Negate", [&testClass]() { testClass->Operator_Negate(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_Add", [&testClass]() { testClass->Operator_Arithmetic_Add(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_Subtract", [&testClass]() { testClass->Operator_Arithmetic_Subtract(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_Multiply", [&testClass]() { testClass->Operator_Arithmetic_Multiply(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_MultiplyScalar", [&testClass]() { testClass->Operator_Arithmetic_MultiplyScalar(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_Divide", [&testClass]() { testClass->Operator_Arithmetic_Divide(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_DivideScalar", [&testClass]() { testClass->Operator_Arithmetic_DivideScalar(); });
	state += Soup::Test::RunTest(className, "Operator_Comparison", [&testClass]() { testClass->Operator_Comparison(); });
	state += Soup::Test::RunTest(className, "NearEqual", [&testClass]() { testClass->NearEqual(); });
	return state;
}