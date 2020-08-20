// <copyright file="Vector2FUnitTests.h" company="mwasplund"> 
//   Copyright (c) mwasplund. All rights reserved.
// </copyright>

namespace VectorMath::UnitTests
{
	class Vector2FUnitTests
	{
	public:
		void Stream()
		{
			Vector2F uut = Vector2F(1, 2);

			std::wstringstream stream;
			stream << uut;
			std::wstring value = stream.str();

			Assert::AreEqual<std::wstring>(L"[1,2]", value.c_str(), "Must match expected string.");
		}

		void Initialize_Zero()
		{
			Vector2F uut = Vector2F::Zero();

			Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), "X must be initialized to zero.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), "Y must be initialized to zero.");
		}

		void Initialize_One()
		{
			Vector2F uut = Vector2F::One();

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), "X must be initialized to one.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), "Y must be initialized to one.");
		}

		void Initialize_UnitX()
		{
			Vector2F uut = Vector2F::UnitX();

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), "X must be initialized to one.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), "Y must be initialized to zero.");
		}

		void Initialize_UnitY()
		{
			Vector2F uut = Vector2F::UnitY();

			Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), "X must be initialized to zero.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), "Y must be initialized to one.");
		}

		void Initialize_Default()
		{
			Vector2F uut = Vector2F();

			Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), "X must be initialized to zero.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), "Y must be initialized to zero.");
		}

		void Initialize_Values()
		{
			Vector2F uut = Vector2F(1, 2);

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), "X must be initialized to 1.0f.");
			Assert::AreEqual<ScalarF>(2.0f, uut.GetY(), "Y must be initialized to 2.0f.");
		}

		void Set_X()
		{
			Vector2F uut = Vector2F();
			uut.SetX(1);

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), "X must be set.");
			Assert::AreEqual<ScalarF>(0.0f, uut.GetY(), "Y must be not set.");
		}

		void Set_Y()
		{
			Vector2F uut = Vector2F();
			uut.SetY(1);

			Assert::AreEqual<ScalarF>(0.0f, uut.GetX(), "X must be not set.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), "Y must be set.");
		}

		void Operator_Assignment()
		{
			Vector2F original = Vector2F(1, 2);
			Vector2F uut = original;

			Assert::AreEqual<ScalarF>(1.0f, uut.GetX(), "X must be set to 1.");
			Assert::AreEqual<ScalarF>(2.0f, uut.GetY(), "Y must be set to 2.");
		}

		void Operator_Assignment_Add()
		{
			Vector2F uut = Vector2F(1, 2);
			uut += Vector2F(0.1f, 0.2f);

			Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), "X must be set to 1.1.");
			Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), "Y must be set to 2.2.");
		}

		void Operator_Assignment_Subtract()
		{
			Vector2F uut = Vector2F(1.2f, 2.4f);
			uut -= Vector2F(0.1f, 0.2f);

			Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), "X must be set to 1.1.");
			Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), "Y must be set to 2.2.");
		}

		void Operator_Assignment_Multiply()
		{
			Vector2F uut = Vector2F(1, 2);
			uut *= Vector2F(2, 2);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), "X must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), "Y must be set to 4.");
		}

		void Operator_Assignment_Divide()
		{
			Vector2F uut = Vector2F(1, 2);
			uut /= Vector2F(2, 2);

			Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), "X must be set to 0.5.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), "Y must be set to 1.0.");
		}

		void Operator_Assignment_MultiplyScalar()
		{
			Vector2F uut = Vector2F(1, 2);
			uut *= ScalarF(2);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), "X must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), "Y must be set to 4.");
		}

		void Operator_Assignment_DivideScalar()
		{
			Vector2F uut = Vector2F(1, 2);
			uut /= ScalarF(2);

			Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), "X must be set to 0.5.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), "Y must be set to 1.0.");
		}

		void Operator_Negate()
		{
			Vector2F original = Vector2F(1, 2);
			Vector2F uut = -original;

			Assert::AreEqual<ScalarF>(-1.0f, uut.GetX(), "X must be set to -1.");
			Assert::AreEqual<ScalarF>(-2.0f, uut.GetY(), "Y must be set to -2.");
		}

		void Operator_Arithmetic_Add()
		{
			Vector2F uut = Vector2F(1, 2) + Vector2F(0.1f, 0.2f);

			Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), "X must be set to 1.1.");
			Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), "Y must be set to 2.2.");
		}

		void Operator_Arithmetic_Subtract()
		{
			Vector2F uut = Vector2F(1.2f, 2.4f) - Vector2F(0.1f, 0.2f);

			Assert::AreEqual<ScalarF>(1.1f, uut.GetX(), "X must be set to 1.1.");
			Assert::AreEqual<ScalarF>(2.2f, uut.GetY(), "Y must be set to 2.2.");
		}

		void Operator_Arithmetic_Multiply()
		{
			Vector2F uut = Vector2F(1, 2) * Vector2F(2, 2);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), "X must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), "Y must be set to 4.");
		}

		void Operator_Arithmetic_Divide()
		{
			Vector2F uut = Vector2F(1, 2) / Vector2F(2, 2);

			Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), "X must be set to 0.5.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), "Y must be set to 1.0.");
		}

		void Operator_Arithmetic_MultiplyScalar()
		{
			Vector2F uut = Vector2F(1, 2) * ScalarF(2);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), "X must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), "Y must be set to 4.");
		}

		void Operator_Arithmetic_DivideScalar()
		{
			Vector2F uut = Vector2F(1, 2) / ScalarF(2);

			Assert::AreEqual<ScalarF>(0.5f, uut.GetX(), "X must be set to 0.5.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), "Y must be set to 1.0.");
		}

		void Operator_Comparison()
		{
			Vector2F uut1 = Vector2F(1, 1);
			Vector2F uut2 = Vector2F(1, 2);
			Vector2F uut3 = Vector2F(2, 1);

			Assert::IsTrue(uut1 == uut1, "Must equal self.");
			Assert::IsFalse(uut1 != uut1, "Must equal self.");

			Assert::IsFalse(uut1 == uut2, "Must not equal.");
			Assert::IsTrue(uut1 != uut2, "Must not equal.");

			Assert::IsFalse(uut1 == uut3, "Must not equal.");
			Assert::IsTrue(uut1 != uut3, "Must not equal.");
		}

		void NearEqual()
		{
			float epsilon = std::numeric_limits<float>::epsilon();
			Vector2F uut1 = Vector2F(1, 1);
			Vector2F uut2 = Vector2F(1, 1 + epsilon);
			Vector2F uut3 = Vector2F(1 + epsilon, 1);

			Assert::IsTrue(uut1 != uut2, "Must not equal.");
			Assert::IsTrue(uut1.NearEqual(uut2, epsilon), "Must be near equal.");
			Assert::IsTrue(uut2.NearEqual(uut1, epsilon), "Must be near equal.");

			Assert::IsTrue(uut1 != uut3, "Must not equal.");
			Assert::IsTrue(uut1.NearEqual(uut3, epsilon), "Must be near equal.");
			Assert::IsTrue(uut2.NearEqual(uut1, epsilon), "Must be near equal.");
		}
	};
} // namespace VectorMath::UnitTests