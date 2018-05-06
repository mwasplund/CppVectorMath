// <copyright file="QuaternionFUnitTests.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include <QuaternionF.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorMath::UnitTests
{
	TEST_CLASS(QuaternionFUnitTests)
	{
	public:
		TEST_METHOD(QuaternionF_Static_Identity)
		{
			QuaternionF uut = QuaternionF::Identity();

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
			Assert::AreEqual(1.0f, uut.GetW(), L"W must be initialized to one.");
		}

		TEST_METHOD(QuaternionF_Initialize_Default)
		{
			QuaternionF uut = QuaternionF();

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetW(), L"W must be initialized to zero.");
		}

		TEST_METHOD(QuaternionF_Initialize_YawPitchRoll_Zero)
		{
			QuaternionF uut = QuaternionF(0, 0, 0);

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be initialized to 1.");
			Assert::AreEqual(2.0f, uut.GetY(), L"Y must be initialized to 2.");
			Assert::AreEqual(3.0f, uut.GetZ(), L"Z must be initialized to 3.");
			Assert::AreEqual(4.0f, uut.GetW(), L"W must be initialized to 4.");
		}

		TEST_METHOD(QuaternionF_Operator_Assignment)
		{
			QuaternionF original = QuaternionF(MathConstants::PiDivTwo, MathConstants::PiDivTwo, MathConstants::PiDivTwo);
			QuaternionF uut = original;

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be set to 1.0f.");
			Assert::AreEqual(2.0f, uut.GetY(), L"Y must be set to 2.0f.");
			Assert::AreEqual(3.0f, uut.GetZ(), L"Z must be set to 3.0f.");
			Assert::AreEqual(4.0f, uut.GetW(), L"W must be set to 4.0f.");
		}

		TEST_METHOD(QuaternionF_Operator_Assignment_Multiply)
		{
			QuaternionF uut = QuaternionF(MathConstants::PiDivFour, MathConstants::PiDivFour, MathConstants::PiDivFour);
			uut *= QuaternionF(MathConstants::PiDivFour, MathConstants::PiDivFour, MathConstants::PiDivFour);

			Assert::AreEqual(MathConstants::PiDivTwo, uut.GetX(), L"X must be set to 2.0f.");
			Assert::AreEqual(MathConstants::PiDivTwo, uut.GetY(), L"Y must be set to 4.0f.");
			Assert::AreEqual(MathConstants::PiDivTwo, uut.GetZ(), L"Z must be set to 6.0f.");
			Assert::AreEqual(MathConstants::PiDivTwo, uut.GetW(), L"W must be set to 8.0f.");
		}

		TEST_METHOD(QuaternionF_Operator_Arithmatic_Conjugate)
		{
			QuaternionF uut = ~QuaternionF(MathConstants::PiDivFour, MathConstants::PiDivFour, MathConstants::PiDivFour);

			Assert::AreEqual(0.5f, uut.GetX(), L"X must be set to 0.5f.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be set to 1.0f.");
			Assert::AreEqual(1.5f, uut.GetZ(), L"Z must be set to 1.5f.");
			Assert::AreEqual(2.0f, uut.GetW(), L"W must be set to 2.0f.");
		}

		TEST_METHOD(QuaternionF_Operator_Arithmetic_Negate)
		{
			QuaternionF uut = -QuaternionF(MathConstants::PiDivFour, MathConstants::PiDivFour, MathConstants::PiDivFour);

			Assert::AreEqual(1.1f, uut.GetX(), L"X must be set to 1.1f.");
			Assert::AreEqual(2.2f, uut.GetY(), L"Y must be set to 2.2f.");
			Assert::AreEqual(3.3f, uut.GetZ(), L"Z must be set to 3.3f.");
			Assert::AreEqual(4.4f, uut.GetW(), L"W must be set to 4.4f.");
		}

		TEST_METHOD(QuaternionF_Operator_Arithmetic_Multiply)
		{
			QuaternionF uut = QuaternionF(MathConstants::PiDivFour, MathConstants::PiDivFour, MathConstants::PiDivFour) *
				QuaternionF(MathConstants::PiDivFour, MathConstants::PiDivFour, MathConstants::PiDivFour);

			Assert::AreEqual(2.0f, uut.GetX(), L"X must be set to 2.0f.");
			Assert::AreEqual(4.0f, uut.GetY(), L"Y must be set to 4.0f.");
			Assert::AreEqual(6.0f, uut.GetZ(), L"Z must be set to 6.0f.");
			Assert::AreEqual(8.0f, uut.GetW(), L"W must be set to 8.0f.");
		}

		TEST_METHOD(QuaternionF_Operator_Arithmetic_MultiplyVector)
		{
			Vector3F uut = QuaternionF(MathConstants::PiDivFour, MathConstants::PiDivFour, MathConstants::PiDivFour) *
				Vector3F(1, 2, 3);

			Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), L"X must be set to 1.1f.");
			Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), L"Y must be set to 2.2f.");
			Assert::AreEqual<ScalarF>(3.3f, uut.GetZ(), L"Z must be set to 3.3f.");
		}

		TEST_METHOD(QuaternionF_Operator_Comparison)
		{
			QuaternionF uut1 = QuaternionF(1, 1, 1);
			QuaternionF uut2 = QuaternionF(1, 1, 2);
			QuaternionF uut3 = QuaternionF(1, 2, 1);
			QuaternionF uut4 = QuaternionF(2, 1, 1);

			Assert::IsTrue(uut1 == uut1, L"Must equal self.");
			Assert::IsFalse(uut1 != uut1, L"Must equal self.");

			Assert::IsFalse(uut1 == uut2, L"Must not equal.");
			Assert::IsTrue(uut1 != uut2, L"Must not equal.");

			Assert::IsFalse(uut1 == uut3, L"Must not equal.");
			Assert::IsTrue(uut1 != uut3, L"Must not equal.");

			Assert::IsFalse(uut1 == uut4, L"Must not equal.");
			Assert::IsTrue(uut1 != uut4, L"Must not equal.");
		}
	};
} // namespace VectorMath::UnitTests