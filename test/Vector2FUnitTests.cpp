// <copyright file="Vector2FUnitTests.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include <Vector2F.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorMath::UnitTests
{
	TEST_CLASS(Vector2FUnitTests)
	{
	public:
		TEST_METHOD(Vector2F_Stream)
		{
			Vector2F uut = Vector2F(1, 2);

			std::wstringstream stream;
			stream << uut;
			std::wstring value = stream.str();

			Assert::AreEqual(L"[1,2]", value.c_str(), L"Must match expected string.");
		}

		TEST_METHOD(Vector2F_Initialize_Zero)
		{
			Vector2F uut = Vector2F::Zero();

			Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be initialized to zero.");
		}

		TEST_METHOD(Vector2F_Initialize_One)
		{
			Vector2F uut = Vector2F::One();

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be initialized to one.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be initialized to one.");
		}

		TEST_METHOD(Vector2F_Initialize_UnitX)
		{
			Vector2F uut = Vector2F::UnitX();

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be initialized to one.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be initialized to zero.");
		}

		TEST_METHOD(Vector2F_Initialize_UnitY)
		{
			Vector2F uut = Vector2F::UnitY();

			Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be initialized to one.");
		}

		TEST_METHOD(Vector2F_Initialize_Default)
		{
			Vector2F uut = Vector2F();

			Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be initialized to zero.");
		}

		TEST_METHOD(Vector2F_Initialize_Values)
		{
			Vector2F uut = Vector2F(1, 2);

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be initialized to 1.0f.");
			Assert::AreEqual<ScalarF>(2.0f, uut.GetY(), L"Y must be initialized to 2.0f.");
		}

		TEST_METHOD(Vector2F_Set_X)
		{
			Vector2F uut = Vector2F();
			uut.SetX(1);

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be set.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be not set.");
		}

		TEST_METHOD(Vector2F_Set_Y)
		{
			Vector2F uut = Vector2F();
			uut.SetY(1);

			Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be not set.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set.");
		}

		TEST_METHOD(Vector2F_Operator_Assignment)
		{
			Vector2F original = Vector2F(1, 2);
			Vector2F uut = original;

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be set to 1.");
			Assert::AreEqual<ScalarF>(2.0f, uut.GetY(), L"Y must be set to 2.");
		}

		TEST_METHOD(Vector2F_Operator_Assignment_Add)
		{
			Vector2F uut = Vector2F(1, 2);
			uut += Vector2F(0.1f, 0.2f);

			Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), L"Y must be set to 2.2.");
		}

		TEST_METHOD(Vector2F_Operator_Assignment_Subtract)
		{
			Vector2F uut = Vector2F(1.2f, 2.4f);
			uut -= Vector2F(0.1f, 0.2f);

			Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), L"Y must be set to 2.2.");
		}

		TEST_METHOD(Vector2F_Operator_Assignment_Multiply)
		{
			Vector2F uut = Vector2F(1, 2);
			uut *= Vector2F(2, 2);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), L"Y must be set to 4.");
		}

		TEST_METHOD(Vector2F_Operator_Assignment_Divide)
		{
			Vector2F uut = Vector2F(1, 2);
			uut /= Vector2F(2, 2);

			Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), L"X must be set to 0.5.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set to 1.0.");
		}

		TEST_METHOD(Vector2F_Operator_Assignment_MultiplyScalar)
		{
			Vector2F uut = Vector2F(1, 2);
			uut *= ScalarF(2);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), L"Y must be set to 4.");
		}

		TEST_METHOD(Vector2F_Operator_Assignment_DivideScalar)
		{
			Vector2F uut = Vector2F(1, 2);
			uut /= ScalarF(2);

			Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), L"X must be set to 0.5.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set to 1.0.");
		}

		TEST_METHOD(Vector2F_Operator_Negate)
		{
			Vector2F original = Vector2F(1, 2);
			Vector2F uut = -original;

			Assert::AreEqual<ScalarF>(-1.0f, uut.GetX(), L"X must be set to -1.");
			Assert::AreEqual<ScalarF>(-2.0f, uut.GetY(), L"Y must be set to -2.");
		}

		TEST_METHOD(Vector2F_Operator_Arithmetic_Add)
		{
			Vector2F uut = Vector2F(1, 2) + Vector2F(0.1f, 0.2f);

			Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), L"Y must be set to 2.2.");
		}

		TEST_METHOD(Vector2F_Operator_Arithmetic_Subtract)
		{
			Vector2F uut = Vector2F(1.2f, 2.4f) - Vector2F(0.1f, 0.2f);

			Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), L"Y must be set to 2.2.");
		}

		TEST_METHOD(Vector2F_Operator_Arithmetic_Multiply)
		{
			Vector2F uut = Vector2F(1, 2) * Vector2F(2, 2);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), L"Y must be set to 4.");
		}

		TEST_METHOD(Vector2F_Operator_Arithmetic_Divide)
		{
			Vector2F uut = Vector2F(1, 2) / Vector2F(2, 2);

			Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), L"X must be set to 0.5.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set to 1.0.");
		}

		TEST_METHOD(Vector2F_Operator_Arithmetic_MultiplyScalar)
		{
			Vector2F uut = Vector2F(1, 2) * ScalarF(2);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), L"Y must be set to 4.");
		}

		TEST_METHOD(Vector2F_Operator_Arithmetic_DivideScalar)
		{
			Vector2F uut = Vector2F(1, 2) / ScalarF(2);

			Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), L"X must be set to 0.5.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set to 1.0.");
		}

		TEST_METHOD(Vector2F_Operator_Comparison)
		{
			Vector2F uut1 = Vector2F(1, 1);
			Vector2F uut2 = Vector2F(1, 2);
			Vector2F uut3 = Vector2F(2, 1);

			Assert::IsTrue(uut1 == uut1, L"Must equal self.");
			Assert::IsFalse(uut1 != uut1, L"Must equal self.");

			Assert::IsFalse(uut1 == uut2, L"Must not equal.");
			Assert::IsTrue(uut1 != uut2, L"Must not equal.");

			Assert::IsFalse(uut1 == uut3, L"Must not equal.");
			Assert::IsTrue(uut1 != uut3, L"Must not equal.");
		}

		TEST_METHOD(Vector2F_NearEqual)
		{
			float epsilon = std::numeric_limits<float>::epsilon();
			Vector2F uut1 = Vector2F(1, 1);
			Vector2F uut2 = Vector2F(1, 1 + epsilon);
			Vector2F uut3 = Vector2F(1 + epsilon, 1);

			Assert::IsTrue(uut1 != uut2, L"Must not equal.");
			Assert::IsTrue(uut1.NearEqual(uut2, epsilon), L"Must be near equal.");
			Assert::IsTrue(uut2.NearEqual(uut1, epsilon), L"Must be near equal.");

			Assert::IsTrue(uut1 != uut3, L"Must not equal.");
			Assert::IsTrue(uut1.NearEqual(uut3, epsilon), L"Must be near equal.");
			Assert::IsTrue(uut2.NearEqual(uut1, epsilon), L"Must be near equal.");
		}
	};
} // namespace VectorMath::UnitTests