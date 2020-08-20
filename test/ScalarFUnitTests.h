// <copyright file="ScalarFUnitTests.h" company="mwasplund"> 
//   Copyright (c) mwasplund. All rights reserved.
// </copyright>

namespace VectorMath::UnitTests
{
	class ScalarFUnitTests
	{
	public:
		void Stream()
		{
			ScalarF uut = ScalarF(1);

			std::wstringstream stream;
			stream << uut;
			std::wstring value = stream.str();

			Assert::AreEqual<std::wstring>(L"[1]", value, "Must match expected string.");
		}

		void Initialize_Zero()
		{
			ScalarF uut = ScalarF::Zero();

			Assert::AreEqual(0.0f, uut.GetValue(), "Value must be initialized to zero.");
		}

		void Initialize_One()
		{
			ScalarF uut = ScalarF::One();

			Assert::AreEqual(1.0f, uut.GetValue(), "Value must be initialized to one.");
		}

		void Initialize_Default()
		{
			ScalarF uut = ScalarF();

			Assert::AreEqual(0.0f, uut.GetValue(), "Value must be initialized to zero.");
		}

		void Initialize_Values()
		{
			ScalarF uut = ScalarF(1);

			Assert::AreEqual(1.0f, uut.GetValue(), "Value must be initialized to 1.");
		}

		void Set_Value()
		{
			ScalarF uut = ScalarF();
			uut.SetValue(1);

			Assert::AreEqual(1.0f, uut.GetValue(), "Value must be set.");
		}

		void Operator_Assignment()
		{
			ScalarF original = ScalarF(1);
			ScalarF uut = original;

			Assert::AreEqual(1.0f, uut.GetValue(), "Value must be set to 1.");
		}

		void Operator_Assignment_Add()
		{
			ScalarF uut = ScalarF(1);
			uut += ScalarF(0.1f);

			Assert::AreEqual(1.1f, uut.GetValue(), "Value must be set to 1.1.");
		}

		void Operator_Assignment_Subtract()
		{
			ScalarF uut = ScalarF(1.2f);
			uut -= ScalarF(0.1f);

			Assert::AreEqual(1.1f, uut.GetValue(), "Value must be set to 1.1.");
		}

		void Operator_Assignment_Multiply()
		{
			ScalarF uut = ScalarF(1);
			uut *= ScalarF(2);

			Assert::AreEqual(2.0f, uut.GetValue(), "Value must be set to 2.");
		}

		void Operator_Assignment_Divide()
		{
			ScalarF uut = ScalarF(1);
			uut /= ScalarF(2);

			Assert::AreEqual(0.5f, uut.GetValue(), "Value must be set to 0.5.");
		}

		void Operator_Negate()
		{
			ScalarF original = ScalarF(1);
			ScalarF uut = -original;

			Assert::AreEqual(-1.0f, uut.GetValue(), "Value must be set to -1.");
		}

		void Operator_Arithmetic_Add()
		{
			ScalarF uut = ScalarF(1) + ScalarF(0.1f);

			Assert::AreEqual(1.1f, uut.GetValue(), "Value must be set to 1.1.");
		}

		void Operator_Arithmetic_Subtract()
		{
			ScalarF uut = ScalarF(1.2f) - ScalarF(0.1f);

			Assert::AreEqual(1.1f, uut.GetValue(), "Value must be set to 1.1.");
		}

		void Operator_Arithmetic_Multiply()
		{
			ScalarF uut = ScalarF(1) * ScalarF(2);

			Assert::AreEqual(2.0f, uut.GetValue(), "Value must be set to 2.");
		}

		void Operator_Arithmetic_Divide()
		{
			ScalarF uut = ScalarF(1) / ScalarF(2);

			Assert::AreEqual(0.5f, uut.GetValue(), "Value must be set to 0.5.");
		}

		void Operator_Arithmetic_MultiplyVector2F()
		{
			Vector2F uut = ScalarF(2) * Vector2F(1, 2);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), "Value must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), "Value must be set to 4.");
		}

		void Operator_Arithmetic_DivideVector2F()
		{
			Vector2F uut = ScalarF(2) / Vector2F(1, 2);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), "Value must be set to 2.0.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), "Value must be set to 1.0.");
		}

		void Operator_Arithmetic_MultiplyVector3F()
		{
			Vector3F uut = ScalarF(2) * Vector3F(1, 2, 3);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), "Value must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), "Value must be set to 4.");
			Assert::AreEqual<ScalarF>(6.0f, uut.GetZ(), "Value must be set to 6.");
		}

		void Operator_Arithmetic_DivideVector3F()
		{
			Vector3F uut = ScalarF(2) / Vector3F(1, 2, 4);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), "Value must be set to 2.0.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), "Value must be set to 1.0.");
			Assert::AreEqual<ScalarF>(0.5f, uut.GetZ(), "Value must be set to 0.5.");
		}

		void Operator_Arithmetic_MultiplyVector4F()
		{
			Vector4F uut = ScalarF(2) * Vector4F(1, 2, 3, 4);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), "Value must be set to 2.");
			Assert::AreEqual<ScalarF>(4.0f, uut.GetY(), "Value must be set to 4.");
			Assert::AreEqual<ScalarF>(6.0f, uut.GetZ(), "Value must be set to 6.");
			Assert::AreEqual<ScalarF>(8.0f, uut.GetW(), "Value must be set to 8.");
		}

		void Operator_Arithmetic_DivideVector4F()
		{
			Vector4F uut = ScalarF(2) / Vector4F(1, 2, 4, 8);

			Assert::AreEqual<ScalarF>(2.0f, uut.GetX(), "Value must be set to 2.0.");
			Assert::AreEqual<ScalarF>(1.0f, uut.GetY(), "Value must be set to 1.0.");
			Assert::AreEqual<ScalarF>(0.5f, uut.GetZ(), "Value must be set to 0.5.");
			Assert::AreEqual<ScalarF>(0.25f, uut.GetW(), "Value must be set to 0.25.");
		}

		void Operator_Comparison()
		{
			ScalarF uut1 = ScalarF(1);
			ScalarF uut2 = ScalarF(2);

			Assert::IsTrue(uut1 == uut1, "Must equal self.");
			Assert::IsFalse(uut1 != uut1, "Must equal self.");

			Assert::IsFalse(uut1 == uut2, "Must not equal.");
			Assert::IsTrue(uut1 != uut2, "Must not equal.");
		}

		void NearEqual()
		{
			float epsilon = std::numeric_limits<float>::epsilon();
			ScalarF uut1 = ScalarF(1);
			ScalarF uut2 = ScalarF(1 + epsilon);

			Assert::IsTrue(uut1 != uut2, "Must not equal.");
			Assert::IsTrue(uut1.NearEqual(uut2, epsilon), "Must be near equal.");
			Assert::IsTrue(uut2.NearEqual(uut1, epsilon), "Must be near equal.");
		}
	};
} // namespace VectorMath::UnitTests