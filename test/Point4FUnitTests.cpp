// <copyright file="Point4FUnitTests.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include <Point4F.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorMath::UnitTests
{
	TEST_CLASS(Point4FUnitTests)
	{
	public:
		TEST_METHOD(Point4F_Stream)
		{
			Point4F uut = Point4F(1, 2, 3, 4);

			std::wstringstream stream;
			stream << uut;
			std::wstring value = stream.str();

			Assert::AreEqual(L"Point4F[1,2,3,4]", value.c_str(), L"Must match expected string.");
		}

		TEST_METHOD(Point4F_Static_Zero)
		{
			Point4F uut = Point4F::Zero();

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetW(), L"W must be initialized to zero.");
		}

		TEST_METHOD(Point4F_Static_One)
		{
			Point4F uut = Point4F::One();

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be initialized to one.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be initialized to one.");
			Assert::AreEqual(1.0f, uut.GetZ(), L"Z must be initialized to one.");
			Assert::AreEqual(1.0f, uut.GetW(), L"W must be initialized to one.");
		}

		TEST_METHOD(Point4F_Static_UnitX)
		{
			Point4F uut = Point4F::UnitX();

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be initialized to one.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetW(), L"W must be initialized to zero.");
		}

		TEST_METHOD(Point4F_Static_UnitY)
		{
			Point4F uut = Point4F::UnitY();

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be initialized to one.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetW(), L"W must be initialized to zero.");
		}

		TEST_METHOD(Point4F_Static_UnitZ)
		{
			Point4F uut = Point4F::UnitZ();

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual(1.0f, uut.GetZ(), L"Z must be initialized to one.");
			Assert::AreEqual(0.0f, uut.GetW(), L"W must be initialized to zero.");
		}

		TEST_METHOD(Point4F_Static_UnitW)
		{
			Point4F uut = Point4F::UnitW();

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
			Assert::AreEqual(1.0f, uut.GetW(), L"W must be initialized to one.");
		}

		TEST_METHOD(Point4F_Initialize_Default)
		{
			Point4F uut = Point4F();

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetW(), L"W must be initialized to zero.");
		}

		TEST_METHOD(Point4F_Initialize_Values)
		{
			Point4F uut = Point4F(1, 2, 3, 4);

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be initialized to 1.");
			Assert::AreEqual(2.0f, uut.GetY(), L"Y must be initialized to 2.");
			Assert::AreEqual(3.0f, uut.GetZ(), L"Z must be initialized to 3.");
			Assert::AreEqual(4.0f, uut.GetW(), L"W must be initialized to 4.");
		}

		TEST_METHOD(Point4F_Set_X)
		{
			Point4F uut = Point4F();
			uut.SetX(1);

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be set.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be not set.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be not set.");
			Assert::AreEqual(0.0f, uut.GetW(), L"W must be not set.");
		}

		TEST_METHOD(Point4F_Set_Y)
		{
			Point4F uut = Point4F();
			uut.SetY(1);

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be not set.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be set.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be not set.");
			Assert::AreEqual(0.0f, uut.GetW(), L"W must be not set.");
		}

		TEST_METHOD(Point4F_Set_Z)
		{
			Point4F uut = Point4F();
			uut.SetZ(1);

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be not set.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be not set.");
			Assert::AreEqual(1.0f, uut.GetZ(), L"Z must be set.");
			Assert::AreEqual(0.0f, uut.GetW(), L"W must be not set.");
		}

		TEST_METHOD(Point4F_Set_W)
		{
			Point4F uut = Point4F();
			uut.SetW(1);

			Assert::AreEqual(0.0f, uut.GetX(), L"X must be not set.");
			Assert::AreEqual(0.0f, uut.GetY(), L"Y must be not set.");
			Assert::AreEqual(0.0f, uut.GetZ(), L"Z must be not set.");
			Assert::AreEqual(1.0f, uut.GetW(), L"W must be set.");
		}

		TEST_METHOD(Point4F_Operator_Assignment)
		{
			Point4F original = Point4F(1, 2, 3, 4);
			Point4F uut = original;

			Assert::AreEqual(1.0f, uut.GetX(), L"X must be set to 1.");
			Assert::AreEqual(2.0f, uut.GetY(), L"Y must be set to 2.");
			Assert::AreEqual(3.0f, uut.GetZ(), L"Z must be set to 3.");
			Assert::AreEqual(4.0f, uut.GetW(), L"W must be set to 4.");
		}

		TEST_METHOD(Point4F_Operator_Assignment_Add)
		{
			Point4F uut = Point4F(1, 2, 3, 4);
			uut += Point4F(0.1f, 0.2f, 0.3f, 0.4f);

			Assert::AreEqual(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual(2.2f, uut.GetY(), L"Y must be set to 2.2.");
			Assert::AreEqual(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
			Assert::AreEqual(4.4f, uut.GetW(), L"W must be set to 4.4.");
		}

		TEST_METHOD(Point4F_Operator_Assignment_Subtract)
		{
			Point4F uut = Point4F(1.2f, 2.4f, 3.6f, 4.8f);
			uut -= Point4F(0.1f, 0.2f, 0.3f, 0.4f);

			Assert::AreEqual(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual(2.2f, uut.GetY(), L"Y must be set to 2.2.");
			Assert::AreEqual(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
			Assert::AreEqual(4.4f, uut.GetW(), L"W must be set to 4.4.");
		}

		TEST_METHOD(Point4F_Operator_Assignment_Multiply)
		{
			Point4F uut = Point4F(1, 2, 3, 4);
			uut *= Point4F(2, 2, 2, 2);

			Assert::AreEqual(2.0f, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual(4.0f, uut.GetY(), L"Y must be set to 4.");
			Assert::AreEqual(6.0f, uut.GetZ(), L"Y must be set to 6.");
			Assert::AreEqual(8.0f, uut.GetW(), L"W must be set to 8.");
		}

		TEST_METHOD(Point4F_Operator_Assignment_Divide)
		{
			Point4F uut = Point4F(1, 2, 3, 4);
			uut /= Point4F(2, 2, 2, 2);

			Assert::AreEqual(0.5f, uut.GetX(), L"X must be set to 0.5.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be set to 1.0.");
			Assert::AreEqual(1.5f, uut.GetZ(), L"Z must be set to 1.5.");
			Assert::AreEqual(2.0f, uut.GetW(), L"W must be set to 2.0.");
		}

		TEST_METHOD(Point4F_Operator_Arithmetic_Add)
		{
			Point4F uut = Point4F(1, 2, 3, 4) + Point4F(0.1f, 0.2f, 0.3f, 0.4f);

			Assert::AreEqual(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual(2.2f, uut.GetY(), L"Y must be set to 2.2.");
			Assert::AreEqual(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
			Assert::AreEqual(4.4f, uut.GetW(), L"W must be set to 4.4.");
		}

		TEST_METHOD(Point4F_Operator_Arithmetic_Subtract)
		{
			Point4F uut = Point4F(1.2f, 2.4f, 3.6f, 4.8f) - Point4F(0.1f, 0.2f, 0.3f, 0.4f);

			Assert::AreEqual(1.1f, uut.GetX(), L"X must be set to 1.1.");
			Assert::AreEqual(2.2f, uut.GetY(), L"Y must be set to 2.2.");
			Assert::AreEqual(3.3f, uut.GetZ(), L"Z must be set to 3.3.");
			Assert::AreEqual(4.4f, uut.GetW(), L"W must be set to 4.4.");
		}

		TEST_METHOD(Point4F_Operator_Arithmetic_Multiply)
		{
			Point4F uut = Point4F(1, 2, 3, 4) * Point4F(2, 2, 2, 2);

			Assert::AreEqual(2.0f, uut.GetX(), L"X must be set to 2.");
			Assert::AreEqual(4.0f, uut.GetY(), L"Y must be set to 4.");
			Assert::AreEqual(6.0f, uut.GetZ(), L"Z must be set to 6.");
			Assert::AreEqual(8.0f, uut.GetW(), L"W must be set to 8.");
		}

		TEST_METHOD(Point4F_Operator_Arithmetic_Divide)
		{
			Point4F uut = Point4F(1, 2, 3, 4) / Point4F(2, 2, 2, 2);

			Assert::AreEqual(0.5f, uut.GetX(), L"X must be set to 0.5.");
			Assert::AreEqual(1.0f, uut.GetY(), L"Y must be set to 1.0.");
			Assert::AreEqual(1.5f, uut.GetZ(), L"Z must be set to 1.5.");
			Assert::AreEqual(2.0f, uut.GetW(), L"W must be set to 2.0.");
		}

		TEST_METHOD(Point4F_Operator_Comparison)
		{
			Point4F uut1 = Point4F(1, 1, 1, 1);
			Point4F uut2 = Point4F(2, 1, 1, 1);
			Point4F uut3 = Point4F(1, 2, 1, 1);
			Point4F uut4 = Point4F(1, 1, 2, 1);
			Point4F uut5 = Point4F(1, 1, 1, 2);

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
	};
} // namespace VectorMath::UnitTests