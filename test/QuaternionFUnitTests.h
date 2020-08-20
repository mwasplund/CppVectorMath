// <copyright file="QuaternionFUnitTests.h" company="mwasplund"> 
//   Copyright (c) mwasplund. All rights reserved.
// </copyright>

namespace VectorMath::UnitTests
{
	class QuaternionFUnitTests
	{
	public:
		void Static_Identity()
		{
			QuaternionF uut = QuaternionF::Identity();

			Assert::AreEqual(0.0f, uut.GetValues()[0], "X must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetValues()[1], "Y must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetValues()[2], "Z must be initialized to zero.");
			Assert::AreEqual(1.0f, uut.GetValues()[3], "W must be initialized to one.");
		}

		void Initialize_Default()
		{
			QuaternionF uut = QuaternionF();

			Assert::AreEqual(0.0f, uut.GetValues()[0], "X must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetValues()[1], "Y must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetValues()[2], "Z must be initialized to zero.");
			Assert::AreEqual(0.0f, uut.GetValues()[3], "W must be initialized to zero.");
		}

		void Initialize_YawPitchRoll_Zero()
		{
			QuaternionF uut = QuaternionF(0, 0, 0);

			Assert::AreEqual(1.0f, uut.GetValues()[0], "X must be initialized to 1.");
			Assert::AreEqual(2.0f, uut.GetValues()[1], "Y must be initialized to 2.");
			Assert::AreEqual(3.0f, uut.GetValues()[2], "Z must be initialized to 3.");
			Assert::AreEqual(4.0f, uut.GetValues()[3], "W must be initialized to 4.");
		}

		void Operator_Assignment()
		{
			QuaternionF original = QuaternionF(
				std::numbers::pi_v<float> / 2,
				std::numbers::pi_v<float> / 2,
				std::numbers::pi_v<float> / 2);
			QuaternionF uut = original;

			Assert::AreEqual(1.0f, uut.GetValues()[0], "X must be set to 1.0f.");
			Assert::AreEqual(2.0f, uut.GetValues()[1], "Y must be set to 2.0f.");
			Assert::AreEqual(3.0f, uut.GetValues()[2], "Z must be set to 3.0f.");
			Assert::AreEqual(4.0f, uut.GetValues()[3], "W must be set to 4.0f.");
		}

		void Operator_Assignment_Multiply()
		{
			QuaternionF uut = QuaternionF(
				std::numbers::pi_v<float> / 4,
				std::numbers::pi_v<float> / 4,
				std::numbers::pi_v<float> / 4);
			uut *= QuaternionF(
				std::numbers::pi_v<float> / 4,
				std::numbers::pi_v<float> / 4,
				std::numbers::pi_v<float> / 4);

			Assert::AreEqual(std::numbers::pi_v<float> / 2, uut.GetValues()[0], "X must be set to 2.0f.");
			Assert::AreEqual(std::numbers::pi_v<float> / 2, uut.GetValues()[1], "Y must be set to 4.0f.");
			Assert::AreEqual(std::numbers::pi_v<float> / 2, uut.GetValues()[2], "Z must be set to 6.0f.");
			Assert::AreEqual(std::numbers::pi_v<float> / 2, uut.GetValues()[3], "W must be set to 8.0f.");
		}

		void Operator_Arithmatic_Conjugate()
		{
			QuaternionF uut = ~QuaternionF(std::numbers::pi_v<float> / 4, std::numbers::pi_v<float> / 4, std::numbers::pi_v<float> / 4);

			Assert::AreEqual(0.5f, uut.GetValues()[0], "X must be set to 0.5f.");
			Assert::AreEqual(1.0f, uut.GetValues()[1], "Y must be set to 1.0f.");
			Assert::AreEqual(1.5f, uut.GetValues()[2], "Z must be set to 1.5f.");
			Assert::AreEqual(2.0f, uut.GetValues()[3], "W must be set to 2.0f.");
		}

		void Operator_Arithmetic_Negate()
		{
			QuaternionF uut = -QuaternionF(std::numbers::pi_v<float> / 4, std::numbers::pi_v<float> / 4, std::numbers::pi_v<float> / 4);

			Assert::AreEqual(1.1f, uut.GetValues()[0], "X must be set to 1.1f.");
			Assert::AreEqual(2.2f, uut.GetValues()[1], "Y must be set to 2.2f.");
			Assert::AreEqual(3.3f, uut.GetValues()[2], "Z must be set to 3.3f.");
			Assert::AreEqual(4.4f, uut.GetValues()[3], "W must be set to 4.4f.");
		}

		void Operator_Arithmetic_Multiply()
		{
			QuaternionF uut = QuaternionF(std::numbers::pi_v<float> / 4, std::numbers::pi_v<float> / 4, std::numbers::pi_v<float> / 4) *
				QuaternionF(std::numbers::pi_v<float> / 4, std::numbers::pi_v<float> / 4, std::numbers::pi_v<float> / 4);

			Assert::AreEqual(2.0f, uut.GetValues()[0], "X must be set to 2.0f.");
			Assert::AreEqual(4.0f, uut.GetValues()[1], "Y must be set to 4.0f.");
			Assert::AreEqual(6.0f, uut.GetValues()[2], "Z must be set to 6.0f.");
			Assert::AreEqual(8.0f, uut.GetValues()[3], "W must be set to 8.0f.");
		}

		void Operator_Arithmetic_MultiplyVector()
		{
			Vector3F uut = QuaternionF(std::numbers::pi_v<float> / 4, std::numbers::pi_v<float> / 4, std::numbers::pi_v<float> / 4) *
				Vector3F(1, 2, 3);

			Assert::AreEqual<ScalarF>(1.1f, uut.GetValues()[0], "X must be set to 1.1f.");
			Assert::AreEqual<ScalarF>(2.2f, uut.GetValues()[1], "Y must be set to 2.2f.");
			Assert::AreEqual<ScalarF>(3.3f, uut.GetValues()[2], "Z must be set to 3.3f.");
		}

		void Operator_Comparison()
		{
			QuaternionF uut1 = QuaternionF(1, 1, 1);
			QuaternionF uut2 = QuaternionF(1, 1, 2);
			QuaternionF uut3 = QuaternionF(1, 2, 1);
			QuaternionF uut4 = QuaternionF(2, 1, 1);

			Assert::IsTrue(uut1 == uut1, "Must equal self.");
			Assert::IsFalse(uut1 != uut1, "Must equal self.");

			Assert::IsFalse(uut1 == uut2, "Must not equal.");
			Assert::IsTrue(uut1 != uut2, "Must not equal.");

			Assert::IsFalse(uut1 == uut3, "Must not equal.");
			Assert::IsTrue(uut1 != uut3, "Must not equal.");

			Assert::IsFalse(uut1 == uut4, "Must not equal.");
			Assert::IsTrue(uut1 != uut4, "Must not equal.");
		}
	};
} // namespace VectorMath::UnitTests