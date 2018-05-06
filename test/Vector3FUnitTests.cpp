// <copyright file="Vector3FUnitTests.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include <Vector3F.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorMath::UnitTests
{
	TEST_CLASS(Vector3FUnitTests)
	{
	public:
		TEST_METHOD(Vector3F_Stream)
		{
			Vector3F uut = Vector3F(1, 2, 3);

			std::wstringstream stream;
			stream << uut;
			std::wstring value = stream.str();

			Assert::AreEqual(L"[1,2,3]", value.c_str(), L"Must match expected string.");
		}

		TEST_METHOD(Vector3F_Initialize_Zero)
		{
			Vector3F uut = Vector3F::Zero();

			Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
		}

		TEST_METHOD(Vector3F_Initialize_One)
		{
			Vector3F uut = Vector3F::One();

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be initialized to one.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be initialized to one.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetZ(), L"Z must be initialized to one.");
		}

		TEST_METHOD(Vector3F_Initialize_UnitX)
		{
			Vector3F uut = Vector3F::UnitX();

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be initialized to one.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
		}

		TEST_METHOD(Vector3F_Initialize_UnitY)
		{
			Vector3F uut = Vector3F::UnitY();

			Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be initialized to one.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
		}

		TEST_METHOD(Vector3F_Initialize_UnitZ)
		{
			Vector3F uut = Vector3F::UnitZ();

			Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetZ(), L"Z must be initialized to one.");
		}

		TEST_METHOD(Vector3F_Initialize_Default)
		{
			Vector3F uut = Vector3F();

			Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
		}

		TEST_METHOD(Vector3F_Initialize_Values)
		{
			Vector3F uut = Vector3F(1, 2, 3);

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be initialized to 1.0f.");
			Assert::AreEqual<ScalarF>(2.0f, uut.GetY(), L"Y must be initialized to 2.0f.");
			Assert::AreEqual<ScalarF>(3.0f, uut.GetZ(), L"Z must be initialized to 3.0f.");
		}

		TEST_METHOD(Vector3F_Set_X)
		{
			Vector3F uut = Vector3F();
			uut.SetX(1);

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be set.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be not set.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetZ(), L"Z must be not set.");
		}

		TEST_METHOD(Vector3F_Set_Y)
		{
			Vector3F uut = Vector3F();
			uut.SetY(1);

			Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be not set.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetZ(), L"Z must be not set.");
		}

		TEST_METHOD(Vector3F_Set_Z)
		{
			Vector3F uut = Vector3F();
			uut.SetZ(1);

			Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be not set.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be not set.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetZ(), L"Z must be set.");
		}

		TEST_METHOD(Vector3F_Operator_Assignment)
		{
			Vector3F original = Vector3F(1, 2, 3);
			Vector3F uut = original;

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be set to 1.");
			Assert::AreEqual<ScalarF>(2.0f, uut.GetY(), L"Y must be set to 2.");
			Assert::AreEqual<ScalarF>(3.0f, uut.GetZ(), L"Z must be set to 3.");
		}

		TEST_METHOD(Vector3F_Operator_Assignment_Add)
		{
			Vector3F uut = Vector3F(1, 2, 3);
			uut += Vector3F(0.1f, 0.2f, 0.3f);

			Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), L"Y must be set to 2.2.");
			Assert::AreEqual<ScalarF>(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
		}

		TEST_METHOD(Vector3F_Operator_Assignment_Subtract)
		{
			Vector3F uut = Vector3F(1.2f, 2.4f, 3.6f);
			uut -= Vector3F(0.1f, 0.2f, 0.3f);

			Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), L"Y must be set to 2.2.");
			Assert::AreEqual<ScalarF>(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
		}

		TEST_METHOD(Vector3F_Operator_Assignment_Multiply)
		{
			Vector3F uut = Vector3F(1, 2, 3);
			uut *= Vector3F(2, 2, 2);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), L"Y must be set to 4.");
			Assert::AreEqual<ScalarF>(6.0f, uut.GetZ(), L"Z must be set to 6.");
		}

		TEST_METHOD(Vector3F_Operator_Assignment_Divide)
		{
			Vector3F uut = Vector3F(1, 2, 3);
			uut /= Vector3F(2, 2, 2);

			Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), L"X must be set to 0.5.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set to 1.0.");
			Assert::AreEqual<ScalarF>(1.5f, uut.GetZ(), L"Z must be set to 1.5.");
		}

		TEST_METHOD(Vector3F_Operator_Assignment_MultiplyScalar)
		{
			Vector3F uut = Vector3F(1, 2, 3);
			uut *= ScalarF(2);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), L"Y must be set to 4.");
			Assert::AreEqual<ScalarF>(6.0f, uut.GetZ(), L"Z must be set to 6.");
		}

		TEST_METHOD(Vector3F_Operator_Assignment_DivideScalar)
		{
			Vector3F uut = Vector3F(1, 2, 3);
			uut /= ScalarF(2);

			Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), L"X must be set to 0.5.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set to 1.0.");
			Assert::AreEqual<ScalarF>(1.5f, uut.GetZ(), L"Z must be set to 1.5.");
		}

		TEST_METHOD(Vector3F_Operator_Negate)
		{
			Vector3F original = Vector3F(1, 2, 3);
			Vector3F uut = -original;

			Assert::AreEqual<ScalarF>(-1.0f, uut.GetX(), L"X must be set to -1.");
			Assert::AreEqual<ScalarF>(-2.0f, uut.GetY(), L"Y must be set to -2.");
			Assert::AreEqual<ScalarF>(-3.0f, uut.GetZ(), L"Z must be set to -3.");
		}

		TEST_METHOD(Vector3F_Operator_Arithmetic_Add)
		{
			Vector3F uut = Vector3F(1, 2, 3) + Vector3F(0.1f, 0.2f, 0.3f);

			Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), L"Y must be set to 2.2.");
			Assert::AreEqual<ScalarF>(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
		}

		TEST_METHOD(Vector3F_Operator_Arithmetic_Subtract)
		{
			Vector3F uut = Vector3F(1.2f, 2.4f, 3.6f) - Vector3F(0.1f, 0.2f, 0.3f);

			Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), L"Y must be set to 2.2.");
			Assert::AreEqual<ScalarF>(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
		}

		TEST_METHOD(Vector3F_Operator_Arithmetic_Multiply)
		{
			Vector3F uut = Vector3F(1, 2, 3) * Vector3F(2, 2, 2);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), L"Y must be set to 4.");
			Assert::AreEqual<ScalarF>(6.0f, uut.GetZ(), L"Z must be set to 6.");
		}

		TEST_METHOD(Vector3F_Operator_Arithmetic_Divide)
		{
			Vector3F uut = Vector3F(1, 2, 3) / Vector3F(2, 2, 2);

			Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), L"X must be set to 0.5.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set to 1.0.");
			Assert::AreEqual<ScalarF>(1.5f, uut.GetZ(), L"Z must be set to 1.5.");
		}

		TEST_METHOD(Vector3F_Operator_Arithmetic_MultiplyScalar)
		{
			Vector3F uut = Vector3F(1, 2, 3) * ScalarF(2);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), L"Y must be set to 4.");
			Assert::AreEqual<ScalarF>(6.0f, uut.GetZ(), L"Z must be set to 6.");
		}

		TEST_METHOD(Vector3F_Operator_Arithmetic_DivideScalar)
		{
			Vector3F uut = Vector3F(1, 2, 3) / ScalarF(2);

			Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), L"X must be set to 0.5.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set to 1.0.");
			Assert::AreEqual<ScalarF>(1.5f, uut.GetZ(), L"Z must be set to 1.5.");
		}

		TEST_METHOD(Vector3F_Operator_Comparison)
		{
			Vector3F uut1 = Vector3F(1, 1, 1);
			Vector3F uut2 = Vector3F(1, 1, 2);
			Vector3F uut3 = Vector3F(1, 2, 1);
			Vector3F uut4 = Vector3F(2, 1, 1);

			Assert::IsTrue(uut1 == uut1, L"Must equal self.");
			Assert::IsFalse(uut1 != uut1, L"Must equal self.");

			Assert::IsFalse(uut1 == uut2, L"Must not equal.");
			Assert::IsTrue(uut1 != uut2, L"Must not equal.");

			Assert::IsFalse(uut1 == uut3, L"Must not equal.");
			Assert::IsTrue(uut1 != uut3, L"Must not equal.");

			Assert::IsFalse(uut1 == uut4, L"Must not equal.");
			Assert::IsTrue(uut1 != uut4, L"Must not equal.");
		}

		TEST_METHOD(Vector3F_NearEqual)
		{
			float epsilon = std::numeric_limits<float>::epsilon();
			Vector3F uut1 = Vector3F(1, 1, 1);
			Vector3F uut2 = Vector3F(1, 1, 1 + epsilon);
			Vector3F uut3 = Vector3F(1, 1 + epsilon, 1);
			Vector3F uut4 = Vector3F(1 + epsilon, 1, 1);

			Assert::IsTrue(uut1 != uut2, L"Must not equal.");
			Assert::IsTrue(uut1.NearEqual(uut2, epsilon), L"Must be near equal.");
			Assert::IsTrue(uut2.NearEqual(uut1, epsilon), L"Must be near equal.");

			Assert::IsTrue(uut1 != uut3, L"Must not equal.");
			Assert::IsTrue(uut1.NearEqual(uut3, epsilon), L"Must be near equal.");
			Assert::IsTrue(uut2.NearEqual(uut1, epsilon), L"Must be near equal.");

			Assert::IsTrue(uut1 != uut4, L"Must not equal.");
			Assert::IsTrue(uut1.NearEqual(uut4, epsilon), L"Must be near equal.");
			Assert::IsTrue(uut4.NearEqual(uut1, epsilon), L"Must be near equal.");
		}
	};
} // namespace VectorMath::UnitTests
