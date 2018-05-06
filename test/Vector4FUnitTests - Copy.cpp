// <copyright file="Vector4FUnitTests.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "pch.h"
#include <Vector4F.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorMath
{
	namespace UnitTests
	{
		TEST_CLASS(Vector4FUnitTests)
		{
		public:
			TEST_METHOD(Vector4F_Initialize_Zero)
			{
				Vector4F uut = Vector4F::Zero();

				Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be initialized to zero.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be initialized to zero.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetW(), L"W must be initialized to zero.");
			}

			TEST_METHOD(Vector4F_Initialize_One)
			{
				Vector4F uut = Vector4F::One();

				Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be initialized to one.");
				Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be initialized to one.");
				Assert::AreEqual<ScalarF>(1.0f, uut.GetZ(), L"Z must be initialized to one.");
				Assert::AreEqual<ScalarF>(1.0f, uut.GetW(), L"W must be initialized to one.");
			}

			TEST_METHOD(Vector4F_Initialize_UnitX)
			{
				Vector4F uut = Vector4F::UnitX();

				Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be initialized to one.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be initialized to zero.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetW(), L"W must be initialized to zero.");
			}

			TEST_METHOD(Vector4F_Initialize_UnitY)
			{
				Vector4F uut = Vector4F::UnitY();

				Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be initialized to zero.");
				Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be initialized to one.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetW(), L"W must be initialized to zero.");
			}

			TEST_METHOD(Vector4F_Initialize_UnitZ)
			{
				Vector4F uut = Vector4F::UnitZ();

				Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be initialized to zero.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be initialized to zero.");
				Assert::AreEqual<ScalarF>(1.0f, uut.GetZ(), L"Z must be initialized to one.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetW(), L"W must be initialized to zero.");
			}

			TEST_METHOD(Vector4F_Initialize_UnitW)
			{
				Vector4F uut = Vector4F::UnitW();

				Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be initialized to zero.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be initialized to zero.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
				Assert::AreEqual<ScalarF>(1.0f, uut.GetW(), L"W must be initialized to one.");
			}

			TEST_METHOD(Vector4F_Initialize_Default)
			{
				Vector4F uut = Vector4F();

				Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be initialized to zero.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be initialized to zero.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetW(), L"W must be initialized to zero.");
			}

			TEST_METHOD(Vector4F_Initialize_Values)
			{
				Vector4F uut = Vector4F(1, 2, 3, 4);

				Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be initialized to 1.0f.");
				Assert::AreEqual<ScalarF>(2.0f, uut.GetY(), L"Y must be initialized to 2.0f.");
				Assert::AreEqual<ScalarF>(3.0f, uut.GetZ(), L"Z must be initialized to 3.0f.");
				Assert::AreEqual<ScalarF>(4.0f, uut.GetW(), L"W must be initialized to 4.0f.");
			}

			TEST_METHOD(Vector4F_Set_X)
			{
				Vector4F uut = Vector4F();
				uut.SetX(1);

				Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be set.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be not set.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetZ(), L"Z must be not set.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetW(), L"W must be not set.");
			}

			TEST_METHOD(Vector4F_Set_Y)
			{
				Vector4F uut = Vector4F();
				uut.SetY(1);

				Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be not set.");
				Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetZ(), L"Z must be not set.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetW(), L"W must be not set.");
			}

			TEST_METHOD(Vector4F_Set_Z)
			{
				Vector4F uut = Vector4F();
				uut.SetZ(1);

				Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be not set.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be not set.");
				Assert::AreEqual<ScalarF>(1.0f, uut.GetZ(), L"Z must be set.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetW(), L"W must be not set.");
			}
			TEST_METHOD(Vector4F_Set_W)
			{
				Vector4F uut = Vector4F();
				uut.SetW(1);

				Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), L"X must be not set.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), L"Y must be not set.");
				Assert::AreEqual<ScalarF>(0.0f, uut.GetZ(), L"Z must be not set.");
				Assert::AreEqual<ScalarF>(1.0f, uut.GetW(), L"W must be set.");
			}

			TEST_METHOD(Vector4F_Operator_Assignment)
			{
				Vector4F original = Vector4F(1, 2, 3, 4);
				Vector4F uut = original;

				Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), L"X must be set to 1.");
				Assert::AreEqual<ScalarF>(2.0f, uut.GetY(), L"Y must be set to 2.");
				Assert::AreEqual<ScalarF>(3.0f, uut.GetZ(), L"Z must be set to 3.");
				Assert::AreEqual<ScalarF>(4.0f, uut.GetW(), L"W must be set to 4.");
			}

			TEST_METHOD(Vector4F_Operator_Assignment_Add)
			{
				Vector4F uut = Vector4F(1, 2, 3, 4);
				uut += Vector4F(0.1f, 0.2f, 0.3f, 0.4f);

				Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), L"X must be set to 1.1.");
				Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), L"Y must be set to 2.2.");
				Assert::AreEqual<ScalarF>(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
				Assert::AreEqual<ScalarF>(4.4f, uut.GetW(), L"W must be set to 4.4.");
			}

			TEST_METHOD(Vector4F_Operator_Assignment_Subtract)
			{
				Vector4F uut = Vector4F(1.2f, 2.4f, 3.6f, 4.8f);
				uut -= Vector4F(0.1f, 0.2f, 0.3f, 0.4f);

				Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), L"X must be set to 1.1.");
				Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), L"Y must be set to 2.2.");
				Assert::AreEqual<ScalarF>(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
				Assert::AreEqual<ScalarF>(4.4f, uut.GetW(), L"W must be set to 4.4.");
			}

			TEST_METHOD(Vector4F_Operator_Assignment_Multiply)
			{
				Vector4F uut = Vector4F(1, 2, 3, 4);
				uut *= Vector4F(2, 2, 2, 2);

				Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), L"X must be set to 2.");
				Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), L"Y must be set to 4.");
				Assert::AreEqual<ScalarF>(6.0f, uut.GetZ(), L"Z must be set to 6.");
				Assert::AreEqual<ScalarF>(8.0f, uut.GetW(), L"W must be set to 8.");
			}

			TEST_METHOD(Vector4F_Operator_Assignment_Divide)
			{
				Vector4F uut = Vector4F(1, 2, 3, 4);
				uut /= Vector4F(2, 2, 2, 2);

				Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), L"X must be set to 0.5.");
				Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set to 1.0.");
				Assert::AreEqual<ScalarF>(1.5f, uut.GetZ(), L"Z must be set to 1.5.");
				Assert::AreEqual<ScalarF>(2.0f, uut.GetW(), L"W must be set to 2.0.");
			}

			TEST_METHOD(Vector4F_Operator_Assignment_MultiplyScalar)
			{
				Vector4F uut = Vector4F(1, 2, 3, 4);
				uut *= ScalarF(2);

				Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), L"X must be set to 2.");
				Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), L"Y must be set to 4.");
				Assert::AreEqual<ScalarF>(6.0f, uut.GetZ(), L"Z must be set to 6.");
				Assert::AreEqual<ScalarF>(8.0f, uut.GetW(), L"W must be set to 8.");
			}

			TEST_METHOD(Vector4F_Operator_Assignment_DivideScalar)
			{
				Vector4F uut = Vector4F(1, 2, 3, 4);
				uut /= ScalarF(2);

				Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), L"X must be set to 0.5.");
				Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set to 1.0.");
				Assert::AreEqual<ScalarF>(1.5f, uut.GetZ(), L"Z must be set to 1.5.");
				Assert::AreEqual<ScalarF>(2.0f, uut.GetW(), L"W must be set to 2.0.");
			}

			TEST_METHOD(Vector4F_Operator_Negate)
			{
				Vector4F original = Vector4F(1, 2, 3, 4);
				Vector4F uut = -original;

				Assert::AreEqual<ScalarF>(-1.0f, uut.GetX(), L"X must be set to -1.");
				Assert::AreEqual<ScalarF>(-2.0f, uut.GetY(), L"Y must be set to -2.");
				Assert::AreEqual<ScalarF>(-3.0f, uut.GetZ(), L"Z must be set to -3.");
				Assert::AreEqual<ScalarF>(-4.0f, uut.GetW(), L"W must be set to -4.");
			}

			TEST_METHOD(Vector4F_Operator_Arithmetic_Add)
			{
				Vector4F uut = Vector4F(1, 2, 3, 4) + Vector4F(0.1f, 0.2f, 0.3f, 0.4f);

				Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), L"X must be set to 1.1.");
				Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), L"Y must be set to 2.2.");
				Assert::AreEqual<ScalarF>(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
				Assert::AreEqual<ScalarF>(4.4f, uut.GetW(), L"W must be set to 4.4.");
			}

			TEST_METHOD(Vector4F_Operator_Arithmetic_Subtract)
			{
				Vector4F uut = Vector4F(1.2f, 2.4f, 3.6f, 4.8f) - Vector4F(0.1f, 0.2f, 0.3f, 0.4f);

				Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), L"X must be set to 1.1.");
				Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), L"Y must be set to 2.2.");
				Assert::AreEqual<ScalarF>(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
				Assert::AreEqual<ScalarF>(4.4f, uut.GetW(), L"W must be set to 4.4.");
			}

			TEST_METHOD(Vector4F_Operator_Arithmetic_Multiply)
			{
				Vector4F uut = Vector4F(1, 2, 3, 4) * Vector4F(2, 2, 2, 2);

				Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), L"X must be set to 2.");
				Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), L"Y must be set to 4.");
				Assert::AreEqual<ScalarF>(6.0f, uut.GetZ(), L"Z must be set to 6.");
				Assert::AreEqual<ScalarF>(8.0f, uut.GetW(), L"W must be set to 8.");
			}

			TEST_METHOD(Vector4F_Operator_Arithmetic_Divide)
			{
				Vector4F uut = Vector4F(1, 2, 3, 4) / Vector4F(2, 2, 2, 2);

				Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), L"X must be set to 0.5.");
				Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set to 1.0.");
				Assert::AreEqual<ScalarF>(1.5f, uut.GetZ(), L"Z must be set to 1.5.");
				Assert::AreEqual<ScalarF>(2.0f, uut.GetW(), L"W must be set to 2.0.");
			}

			TEST_METHOD(Vector4F_Operator_Arithmetic_MultiplyScalar)
			{
				Vector4F uut = Vector4F(1, 2, 3, 4) * ScalarF(2);

				Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), L"X must be set to 2.");
				Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), L"Y must be set to 4.");
				Assert::AreEqual<ScalarF>(6.0f, uut.GetZ(), L"Z must be set to 6.");
				Assert::AreEqual<ScalarF>(8.0f, uut.GetW(), L"W must be set to 8.");
			}

			TEST_METHOD(Vector4F_Operator_Arithmetic_DivideScalar)
			{
				Vector4F uut = Vector4F(1, 2, 3, 4) / ScalarF(2);

				Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), L"X must be set to 0.5.");
				Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), L"Y must be set to 1.0.");
				Assert::AreEqual<ScalarF>(1.5f, uut.GetZ(), L"Z must be set to 1.5.");
				Assert::AreEqual<ScalarF>(2.0f, uut.GetW(), L"W must be set to 2.0.");
			}

			TEST_METHOD(Vector4F_Operator_Comparison)
			{
				Vector4F uut1 = Vector4F(1, 1, 1, 1);
				Vector4F uut2 = Vector4F(1, 1, 1, 2);
				Vector4F uut3 = Vector4F(1, 1, 2, 1);
				Vector4F uut4 = Vector4F(1, 2, 1, 1);
				Vector4F uut5 = Vector4F(2, 1, 1, 1);

				Assert::IsTrue(uut1 == uut1, L"Must equal self.");
				Assert::IsFalse(uut1 != uut1, L"Must equal self.");

				Assert::IsFalse(uut1 == uut2, L"Must not equal.");
				Assert::IsTrue(uut1 != uut2, L"Must not equal.");

				Assert::IsFalse(uut1 == uut3, L"Must not equal.");
				Assert::IsTrue(uut1 != uut3, L"Must not equal.");

				Assert::IsFalse(uut1 == uut4, L"Must not equal.");
				Assert::IsTrue(uut1 != uut4, L"Must not equal.");

				Assert::IsFalse(uut1 == uut5, L"Must not equal.");
				Assert::IsTrue(uut1 != uut5, L"Must not equal.");
			}

			TEST_METHOD(Vector4F_NearEqual)
			{
				float epsilon = std::numeric_limits<float>::epsilon();
				Vector4F uut1 = Vector4F(1, 1, 1, 1);
				Vector4F uut2 = Vector4F(1, 1, 1, 1 + epsilon);
				Vector4F uut3 = Vector4F(1, 1, 1 + epsilon, 1);
				Vector4F uut4 = Vector4F(1, 1 + epsilon, 1, 1);
				Vector4F uut5 = Vector4F(1 + epsilon, 1, 1, 1);

				Assert::IsTrue(uut1 != uut2, L"Must not equal.");
				Assert::IsTrue(uut1.NearEqual(uut2, epsilon), L"Must be near equal.");
				Assert::IsTrue(uut2.NearEqual(uut1, epsilon), L"Must be near equal.");

				Assert::IsTrue(uut1 != uut3, L"Must not equal.");
				Assert::IsTrue(uut1.NearEqual(uut3, epsilon), L"Must be near equal.");
				Assert::IsTrue(uut2.NearEqual(uut1, epsilon), L"Must be near equal.");

				Assert::IsTrue(uut1 != uut4, L"Must not equal.");
				Assert::IsTrue(uut1.NearEqual(uut4, epsilon), L"Must be near equal.");
				Assert::IsTrue(uut4.NearEqual(uut1, epsilon), L"Must be near equal.");

				Assert::IsTrue(uut1 != uut5, L"Must not equal.");
				Assert::IsTrue(uut1.NearEqual(uut5, epsilon), L"Must be near equal.");
				Assert::IsTrue(uut5.NearEqual(uut1, epsilon), L"Must be near equal.");
			}
		};
	} // namespace UnitTests
} // namespace VectorMath