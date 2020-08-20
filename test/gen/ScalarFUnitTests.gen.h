#pragma once
#include "ScalarFUnitTests.h"

TestState RunScalarFUnitTests()
{
	auto className = "ScalarFUnitTests";
	auto testClass = std::make_shared<VectorMath::UnitTests::ScalarFUnitTests>();
	TestState state = { 0, 0 };
	state += Soup::Test::RunTest(className, "Stream", [&testClass]() { testClass->Stream(); });
	state += Soup::Test::RunTest(className, "Initialize_Zero", [&testClass]() { testClass->Initialize_Zero(); });
	state += Soup::Test::RunTest(className, "Initialize_One", [&testClass]() { testClass->Initialize_One(); });
	state += Soup::Test::RunTest(className, "Initialize_Default", [&testClass]() { testClass->Initialize_Default(); });
	state += Soup::Test::RunTest(className, "Initialize_Values", [&testClass]() { testClass->Initialize_Values(); });
	state += Soup::Test::RunTest(className, "Set_Value", [&testClass]() { testClass->Set_Value(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment", [&testClass]() { testClass->Operator_Assignment(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment_Add", [&testClass]() { testClass->Operator_Assignment_Add(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment_Subtract", [&testClass]() { testClass->Operator_Assignment_Subtract(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment_Multiply", [&testClass]() { testClass->Operator_Assignment_Multiply(); });
	state += Soup::Test::RunTest(className, "Operator_Assignment_Divide", [&testClass]() { testClass->Operator_Assignment_Divide(); });
	state += Soup::Test::RunTest(className, "Operator_Negate", [&testClass]() { testClass->Operator_Negate(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_Add", [&testClass]() { testClass->Operator_Arithmetic_Add(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_Subtract", [&testClass]() { testClass->Operator_Arithmetic_Subtract(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_Multiply", [&testClass]() { testClass->Operator_Arithmetic_Multiply(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_Divide", [&testClass]() { testClass->Operator_Arithmetic_Divide(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_MultiplyVector2F", [&testClass]() { testClass->Operator_Arithmetic_MultiplyVector2F(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_DivideVector2F", [&testClass]() { testClass->Operator_Arithmetic_DivideVector2F(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_MultiplyVector3F", [&testClass]() { testClass->Operator_Arithmetic_MultiplyVector3F(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_DivideVector3F", [&testClass]() { testClass->Operator_Arithmetic_DivideVector3F(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_MultiplyVector4F", [&testClass]() { testClass->Operator_Arithmetic_MultiplyVector4F(); });
	state += Soup::Test::RunTest(className, "Operator_Arithmetic_DivideVector4F", [&testClass]() { testClass->Operator_Arithmetic_DivideVector4F(); });
	state += Soup::Test::RunTest(className, "Operator_Comparison", [&testClass]() { testClass->Operator_Comparison(); });
	state += Soup::Test::RunTest(className, "NearEqual", [&testClass]() { testClass->NearEqual(); });
	return state;
}