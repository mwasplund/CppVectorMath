// <copyright file="Point3FUnitTests.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "pch.h"
#include <Point3F.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorMath::UnitTests
{
	TEST_CLASS(Point3FUnitTests)
	{
	public:
		TEST_METHOD(Point3F_Stream)
		{
			Point3F uut = Point3F(1, 2, 3);

			std::wstringstream stream;
			stream << uut;
			std::wstring value = stream.str();

			Assert::AreEqual(L"Point3F[1,2,3]", value.c_str(), L"Must match expected string.");
		}

		TEST_METHOD(Point3F_Static_Zero)
		{
			Point3F uut = Point3F::Zero();

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
		}

		TEST_METHOD(Point3F_Static_One)
		{
			Point3F uut = Point3F::One();

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be initialized to one.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be initialized to one.");
			Assert::AreEqual(1.0f, uut.GetZ(), L"Z must be initialized to one.");
		}

		TEST_METHOD(Point3F_Static_UnitX)
		{
			Point3F uut = Point3F::UnitX();

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be initialized to one.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
		}

		TEST_METHOD(Point3F_Static_UnitY)
		{
			Point3F uut = Point3F::UnitY();

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be initialized to one.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
		}

		TEST_METHOD(Point3F_Static_UnitZ)
		{
			Point3F uut = Point3F::UnitZ();

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual(1.0f, uut.GetZ(), L"Z must be initialized to one.");
		}

		TEST_METHOD(Point3F_Initialize_Default)
		{
			Point3F uut = Point3F();

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
		}

		TEST_METHOD(Point3F_Initialize_Values)
		{
			Point3F uut = Point3F(1, 2, 3);

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be initialized to 1.");
			Assert::AreEqual(2.0f, uut.GetY(), L"Y must be initialized to 2.");
			Assert::AreEqual(3.0f, uut.GetZ(), L"Z must be initialized to 3.");
		}

		TEST_METHOD(Point3F_Set_X)
		{
			Point3F uut = Point3F();
			uut.SetX(1);

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be set.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be not set.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be not set.");
		}

		TEST_METHOD(Point3F_Set_Y)
		{
			Point3F uut = Point3F();
			uut.SetY(1);

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be not set.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be set.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be not set.");
		}

		TEST_METHOD(Point3F_Set_Z)
		{
			Point3F uut = Point3F();
			uut.SetZ(1);

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be not set.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be not set.");
			Assert::AreEqual(1.0f, uut.GetZ(), L"Z must be set.");
		}

		TEST_METHOD(Point3F_Operator_Assignment)
		{
			Point3F original = Point3F(1, 2, 3);
			Point3F uut = original;

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be set to 1.");
			Assert::AreEqual(2.0f, uut.GetY(), L"Y must be set to 2.");
			Assert::AreEqual(3.0f, uut.GetZ(), L"Z must be set to 3.");
		}

		TEST_METHOD(Point3F_Operator_Assignment_Add)
		{
			Point3F uut = Point3F(1, 2, 3);
			uut += Point3F(0.1f, 0.2f, 0.3f);

			Assert::AreEqual(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual(2.2f, uut.GetY(), L"Y must be set to 2.2.");
			Assert::AreEqual(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
		}

		TEST_METHOD(Point3F_Operator_Assignment_Subtract)
		{
			Point3F uut = Point3F(1.2f, 2.4f, 3.6f);
			uut -= Point3F(0.1f, 0.2f, 0.3f);

			Assert::AreEqual(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual(2.2f, uut.GetY(), L"Y must be set to 2.2.");
			Assert::AreEqual(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
		}

		TEST_METHOD(Point3F_Operator_Assignment_Multiply)
		{
			Point3F uut = Point3F(1, 2, 3);
			uut *= Point3F(2, 2, 2);

			Assert::AreEqual(2.0f, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual(4.0f, uut.GetY(), L"Y must be set to 4.");
			Assert::AreEqual(6.0f, uut.GetZ(), L"Y must be set to 6.");
		}

		TEST_METHOD(Point3F_Operator_Assignment_Divide)
		{
			Point3F uut = Point3F(1, 2, 3);
			uut /= Point3F(2, 2, 2);

			Assert::AreEqual(0.5f, uut.GetX(), L"X must be set to 0.5.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be set to 1.0.");
			Assert::AreEqual(1.5f, uut.GetZ(), L"Z must be set to 1.5.");
		}

		TEST_METHOD(Point3F_Operator_Arithmetic_Add)
		{
			Point3F uut = Point3F(1, 2, 3) + Point3F(0.1f, 0.2f, 0.3f);

			Assert::AreEqual(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual(2.2f, uut.GetY(), L"Y must be set to 2.2.");
			Assert::AreEqual(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
		}

		TEST_METHOD(Point3F_Operator_Arithmetic_Subtract)
		{
			Point3F uut = Point3F(1.2f, 2.4f, 3.6f) - Point3F(0.1f, 0.2f, 0.3f);

			Assert::AreEqual(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual(2.2f, uut.GetY(), L"Y must be set to 2.2.");
			Assert::AreEqual(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
		}

		TEST_METHOD(Point3F_Operator_Arithmetic_Multiply)
		{
			Point3F uut = Point3F(1, 2, 3) * Point3F(2, 2, 2);

			Assert::AreEqual(2.0f, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual(4.0f, uut.GetY(), L"Y must be set to 4.");
			Assert::AreEqual(6.0f, uut.GetZ(), L"Z must be set to 6.");
		}

		TEST_METHOD(Point3F_Operator_Arithmetic_Divide)
		{
			Point3F uut = Point3F(1, 2, 3) / Point3F(2, 2, 2);

			Assert::AreEqual(0.5f, uut.GetX(), L"X must be set to 0.5.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be set to 1.0.");
			Assert::AreEqual(1.5f, uut.GetZ(), L"Z must be set to 1.5.");
		}

		TEST_METHOD(Point3F_Operator_Comparison)
		{
			Point3F uut1 = Point3F(1, 1, 1);
			Point3F uut2 = Point3F(2, 1, 1);
			Point3F uut3 = Point3F(1, 2, 1);
			Point3F uut4 = Point3F(1, 1, 2);

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