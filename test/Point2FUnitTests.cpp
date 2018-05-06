// <copyright file="Point2FUnitTests.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "pch.h"
#include <Point2F.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorMath::UnitTests
{
	TEST_CLASS(Point2FUnitTests)
	{
	public:
		TEST_METHOD(Point2F_Stream)
		{
			Point2F uut = Point2F(1, 2);

			std::wstringstream stream;
			stream << uut;
			std::wstring value = stream.str();

			Assert::AreEqual(L"Point2F[1,2]", value.c_str(), L"Must match expected string.");
		}

		TEST_METHOD(Point2F_Static_Zero)
		{
			Point2F uut = Point2F::Zero();

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be initialized to zero.");
		}

		TEST_METHOD(Point2F_Static_One)
		{
			Point2F uut = Point2F::One();

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be initialized to one.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be initialized to one.");
		}

		TEST_METHOD(Point2F_Static_UnitX)
		{
			Point2F uut = Point2F::UnitX();

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be initialized to one.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be initialized to zero.");
		}

		TEST_METHOD(Point2F_Static_UnitY)
		{
			Point2F uut = Point2F::UnitY();

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be initialized to one.");
		}

		TEST_METHOD(Point2F_Initialize_Default)
		{
			Point2F uut = Point2F();

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be initialized to zero.");
		}

		TEST_METHOD(Point2F_Initialize_Values)
		{
			Point2F uut = Point2F(1, 2);

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be initialized to 1.");
			Assert::AreEqual(2.0f, uut.GetY(), L"Y must be initialized to 2.");
		}

		TEST_METHOD(Point2F_Set_X)
		{
			Point2F uut = Point2F();
			uut.SetX(1);

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be set.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be not set.");
		}

		TEST_METHOD(Point2F_Set_Y)
		{
			Point2F uut = Point2F();
			uut.SetY(1);

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be not set.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be set.");
		}

		TEST_METHOD(Point2F_Operator_Assignment)
		{
			Point2F original = Point2F(1, 2);
			Point2F uut = original;

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be set to 1.");
			Assert::AreEqual(2.0f, uut.GetY(), L"Y must be set to 2.");
		}

		TEST_METHOD(Point2F_Operator_Assignment_Add)
		{
			Point2F uut = Point2F(1, 2);
			uut += Point2F(0.1f, 0.2f);

			Assert::AreEqual(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual(2.2f, uut.GetY(), L"Y must be set to 2.2.");
		}

		TEST_METHOD(Point2F_Operator_Assignment_Subtract)
		{
			Point2F uut = Point2F(1.2f, 2.4f);
			uut -= Point2F(0.1f, 0.2f);

			Assert::AreEqual(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual(2.2f, uut.GetY(), L"Y must be set to 2.2.");
		}

		TEST_METHOD(Point2F_Operator_Assignment_Multiply)
		{
			Point2F uut = Point2F(1, 2);
			uut *= Point2F(2, 2);

			Assert::AreEqual(2.0f, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual(4.0f, uut.GetY(), L"Y must be set to 4.");
		}

		TEST_METHOD(Point2F_Operator_Assignment_Divide)
		{
			Point2F uut = Point2F(1, 2);
			uut /= Point2F(2, 2);

			Assert::AreEqual(0.5f, uut.GetX(), L"X must be set to 0.5.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be set to 1.");
		}

		TEST_METHOD(Point2F_Operator_Arithmetic_Add)
		{
			Point2F uut = Point2F(1, 2) + Point2F(0.1f, 0.2f);

			Assert::AreEqual(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual(2.2f, uut.GetY(), L"Y must be set to 2.2.");
		}

		TEST_METHOD(Point2F_Operator_Arithmetic_Subtract)
		{
			Point2F uut = Point2F(1.2f, 2.4f) - Point2F(0.1f, 0.2f);

			Assert::AreEqual(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual(2.2f, uut.GetY(), L"Y must be set to 2.2.");
		}

		TEST_METHOD(Point2F_Operator_Arithmetic_Multiply)
		{
			Point2F uut = Point2F(1, 2) * Point2F(2, 2);

			Assert::AreEqual(2.0f, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual(4.0f, uut.GetY(), L"Y must be set to 4.");
		}

		TEST_METHOD(Point2F_Operator_Arithmetic_Divide)
		{
			Point2F uut = Point2F(1, 2) / Point2F(2, 2);

			Assert::AreEqual(0.5f, uut.GetX(), L"X must be set to 0.5.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be set to 1.");
		}

		TEST_METHOD(Point2F_Operator_Comparison)
		{
			Point2F uut1 = Point2F(1, 1);
			Point2F uut2 = Point2F(1, 2);
			Point2F uut3 = Point2F(2, 1);

			Assert::IsTrue(uut1 == uut1, L"Must equal self.");
			Assert::IsFalse(uut1 != uut1, L"Must equal self.");

			Assert::IsFalse(uut1 == uut2, L"Must not equal.");
			Assert::IsTrue(uut1 != uut2, L"Must not equal.");

			Assert::IsFalse(uut1 == uut3, L"Must not equal.");
			Assert::IsTrue(uut1 != uut3, L"Must not equal.");
		}
	};
} // namespace VectorMath::UnitTests