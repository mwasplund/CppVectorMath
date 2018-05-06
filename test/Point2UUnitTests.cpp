// <copyright file="Point2UUnitTests.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "pch.h"
#include <Point2U.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorMath::UnitTests
{
	TEST_CLASS(Point2UUnitTests)
	{
	public:
		TEST_METHOD(Point2U_Stream)
		{
			Point2U uut = Point2U(1, 2);

			std::wstringstream stream;
			stream << uut;
			std::wstring value = stream.str();

			Assert::AreEqual(L"Point2U[1,2]", value.c_str(), L"Must match expected string.");
		}

		TEST_METHOD(Point2U_Static_Zero)
		{
			Point2U uut = Point2U::Zero();

			Assert::AreEqual(0u, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(0u, uut.GetY(), L"Y must be initialized to zero.");
		}

		TEST_METHOD(Point2U_Static_One)
		{
			Point2U uut = Point2U::One();

			Assert::AreEqual(1u, uut.GetX(), L"X must be initialized to one.");
			Assert::AreEqual(1u, uut.GetY(), L"Y must be initialized to one.");
		}

		TEST_METHOD(Point2U_Static_UnitX)
		{
			Point2U uut = Point2U::UnitX();

			Assert::AreEqual(1u, uut.GetX(), L"X must be initialized to one.");
			Assert::AreEqual(0u, uut.GetY(), L"Y must be initialized to zero.");
		}

		TEST_METHOD(Point2U_Static_UnitY)
		{
			Point2U uut = Point2U::UnitY();

			Assert::AreEqual(0u, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(1u, uut.GetY(), L"Y must be initialized to one.");
		}

		TEST_METHOD(Point2U_Initialize_Default)
		{
			Point2U uut = Point2U();

			Assert::AreEqual(0u, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(0u, uut.GetY(), L"Y must be initialized to zero.");
		}

		TEST_METHOD(Point2U_Initialize_Values)
		{
			Point2U uut = Point2U(1, 2);

			Assert::AreEqual(1u, uut.GetX(), L"X must be initialized to 1.");
			Assert::AreEqual(2u, uut.GetY(), L"Y must be initialized to 2.");
		}

		TEST_METHOD(Point2U_Set_X)
		{
			Point2U uut = Point2U();
			uut.SetX(1);

			Assert::AreEqual(1u, uut.GetX(), L"X must be set.");
			Assert::AreEqual(0u, uut.GetY(), L"Y must be not set.");
		}

		TEST_METHOD(Point2U_Set_Y)
		{
			Point2U uut = Point2U();
			uut.SetY(1);

			Assert::AreEqual(0u, uut.GetX(), L"X must be not set.");
			Assert::AreEqual(1u, uut.GetY(), L"Y must be set.");
		}

		TEST_METHOD(Point2U_Operator_Assignment)
		{
			Point2U original = Point2U(1, 2);
			Point2U uut = original;

			Assert::AreEqual(1u, uut.GetX(), L"X must be set to 1.");
			Assert::AreEqual(2u, uut.GetY(), L"Y must be set to 2.");
		}

		TEST_METHOD(Point2U_Operator_Assignment_Add)
		{
			Point2U uut = Point2U(1, 2);
			uut += Point2U(10, 20);

			Assert::AreEqual(11u, uut.GetX(), L"X must be set to 11.");
			Assert::AreEqual(22u, uut.GetY(), L"Y must be set to 22.");
		}

		TEST_METHOD(Point2U_Operator_Assignment_Subtract)
		{
			Point2U uut = Point2U(12, 24);
			uut -= Point2U(1, 2);

			Assert::AreEqual(11u, uut.GetX(), L"X must be set to 11.");
			Assert::AreEqual(22u, uut.GetY(), L"Y must be set to 22.");
		}

		TEST_METHOD(Point2U_Operator_Assignment_Multiply)
		{
			Point2U uut = Point2U(1, 2);
			uut *= Point2U(2, 2);

			Assert::AreEqual(2u, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual(4u, uut.GetY(), L"Y must be set to 4.");
		}

		TEST_METHOD(Point2U_Operator_Assignment_Divide)
		{
			Point2U uut = Point2U(6, 8);
			uut /= Point2U(2, 4);

			Assert::AreEqual(3u, uut.GetX(), L"X must be set to 3.");
			Assert::AreEqual(2u, uut.GetY(), L"Y must be set to 2.");
		}

		TEST_METHOD(Point2U_Operator_Arithmetic_Add)
		{
			Point2U uut = Point2U(1, 2) + Point2U(10, 20);

			Assert::AreEqual(11u, uut.GetX(), L"X must be set to 11.");
			Assert::AreEqual(22u, uut.GetY(), L"Y must be set to 22.");
		}

		TEST_METHOD(Point2U_Operator_Arithmetic_Subtract)
		{
			Point2U uut = Point2U(12, 24) - Point2U(1, 2);

			Assert::AreEqual(11u, uut.GetX(), L"X must be set to 11.");
			Assert::AreEqual(22u, uut.GetY(), L"Y must be set to 22.");
		}

		TEST_METHOD(Point2U_Operator_Arithmetic_Multiply)
		{
			Point2U uut = Point2U(2, 3) * Point2U(2, 4);

			Assert::AreEqual(4u, uut.GetX(), L"X must be set to 4.");
			Assert::AreEqual(12u, uut.GetY(), L"Y must be set to 12.");
		}

		TEST_METHOD(Point2U_Operator_Arithmetic_Divide)
		{
			Point2U uut = Point2U(2, 6) / Point2U(2, 3);

			Assert::AreEqual(1u, uut.GetX(), L"X must be set to 1.");
			Assert::AreEqual(2u, uut.GetY(), L"Y must be set to 2.");
		}

		TEST_METHOD(Point2U_Operator_Comparison)
		{
			Point2U uut1 = Point2U(1, 1);
			Point2U uut2 = Point2U(1, 2);
			Point2U uut3 = Point2U(2, 1);

			Assert::IsTrue(uut1 == uut1, L"Must equal self.");
			Assert::IsFalse(uut1 != uut1, L"Must equal self.");

			Assert::IsFalse(uut1 == uut2, L"Must not equal.");
			Assert::IsTrue(uut1 != uut2, L"Must not equal.");

			Assert::IsFalse(uut1 == uut3, L"Must not equal.");
			Assert::IsTrue(uut1 != uut3, L"Must not equal.");
		}
	};
} // namespace VectorMath::UnitTests