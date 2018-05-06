// <copyright file="Matrix4x4FUnitTests.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include <Matrix4x4F.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorMath::UnitTests
{
	TEST_CLASS(Matrix4x4FUnitTests)
	{
	public:
		TEST_METHOD(Matrix4x4F_Static_Identity)
		{
			auto uut = Matrix4x4F::Identity();

			Assert::AreEqual(Vector4F::UnitX(), uut[0], L"Row0 must be correct.");
			Assert::AreEqual(Vector4F::UnitY(), uut[1], L"Row1 must be correct.");
			Assert::AreEqual(Vector4F::UnitZ(), uut[2], L"Row2 must be correct.");
			Assert::AreEqual(Vector4F::UnitW(), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Static_AffineTransformation)
		{
			auto scaling = Vector3F(10, 5, 2);
			auto rotationOrigin = Vector3F(1, 1, 1);
			auto rotation = QuaternionF(MathConstants::PiDivFour, MathConstants::PiDivFour, MathConstants::PiDivFour);
			auto translation = Vector3F(100, 200, 300);

			auto uut = Matrix4x4F::AffineTransformation(
				scaling,
				rotationOrigin,
				rotation,
				translation);

			auto rotationOriginMatrix = Matrix4x4F::Translation(rotationOrigin);
			auto expected =
				Matrix4x4F::Scaling(scaling) *
				rotationOriginMatrix.Transpose() *
				Matrix4x4F::Rotation(rotation) *
				rotationOriginMatrix *
				Matrix4x4F::Translation(translation);

			Assert::AreEqual(expected, uut, L"Verify result must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Static_LookAtRH)
		{
			Matrix4x4F uut;// TODO  = Matrix4x4F::LookAtRH();

			Assert::AreEqual(Vector4F(1, 0, 0, 0), uut[0], L"Row0 must be correct.");
			Assert::AreEqual(Vector4F(0, 1, 0, 0), uut[1], L"Row1 must be correct.");
			Assert::AreEqual(Vector4F(0, 0, 1, 0), uut[2], L"Row2 must be correct.");
			Assert::AreEqual(Vector4F(0, 0, 0, 1), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Static_PerspectiveFovRH)
		{
			Matrix4x4F uut; // TODO = Matrix4x4F::PerspectiveFovRH();

			Assert::AreEqual(Vector4F(1, 0, 0, 0), uut[0], L"Row0 must be correct.");
			Assert::AreEqual(Vector4F(0, 1, 0, 0), uut[1], L"Row1 must be correct.");
			Assert::AreEqual(Vector4F(0, 0, 1, 0), uut[2], L"Row2 must be correct.");
			Assert::AreEqual(Vector4F(0, 0, 0, 1), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Static_Scaling)
		{
			Matrix4x4F uut; // TODO = Matrix4x4F::Scaling();

			Assert::AreEqual(Vector4F(1, 0, 0, 0), uut[0], L"Row0 must be correct.");
			Assert::AreEqual(Vector4F(0, 1, 0, 0), uut[1], L"Row1 must be correct.");
			Assert::AreEqual(Vector4F(0, 0, 1, 0), uut[2], L"Row2 must be correct.");
			Assert::AreEqual(Vector4F(0, 0, 0, 1), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Static_Rotation_OneVector)
		{
			auto rotation = QuaternionF();
			Matrix4x4F uut = Matrix4x4F::Rotation(rotation);

			Assert::AreEqual(Vector4F(1, 0, 0, 0), uut[0], L"Row0 must be correct.");
			Assert::AreEqual(Vector4F(0, 1, 0, 0), uut[1], L"Row1 must be correct.");
			Assert::AreEqual(Vector4F(0, 0, 1, 0), uut[2], L"Row2 must be correct.");
			Assert::AreEqual(Vector4F(0, 0, 0, 1), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Static_RotationX)
		{
			float angle = MathConstants::PiDivFour;
			Matrix4x4F uut = Matrix4x4F::RotationX(angle);

			Assert::AreEqual(Vector4F(1, 0, 0, 0), uut[0], L"Row0 must be correct.");
			Assert::AreEqual(Vector4F(0, 1, 0, 0), uut[1], L"Row1 must be correct.");
			Assert::AreEqual(Vector4F(0, 0, 1, 0), uut[2], L"Row2 must be correct.");
			Assert::AreEqual(Vector4F(0, 0, 0, 1), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Static_RotationY)
		{
			float angle = MathConstants::PiDivFour;
			Matrix4x4F uut = Matrix4x4F::RotationY(angle);

			Assert::AreEqual(Vector4F(1, 0, 0, 0), uut[0], L"Row0 must be correct.");
			Assert::AreEqual(Vector4F(0, 1, 0, 0), uut[1], L"Row1 must be correct.");
			Assert::AreEqual(Vector4F(0, 0, 1, 0), uut[2], L"Row2 must be correct.");
			Assert::AreEqual(Vector4F(0, 0, 0, 1), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Static_RotationZ)
		{
			float angle = MathConstants::PiDivFour;
			Matrix4x4F uut = Matrix4x4F::RotationZ(angle);

			Assert::AreEqual(Vector4F(1, 0, 0, 0), uut[0], L"Row0 must be correct.");
			Assert::AreEqual(Vector4F(0, 1, 0, 0), uut[1], L"Row1 must be correct.");
			Assert::AreEqual(Vector4F(0, 0, 1, 0), uut[2], L"Row2 must be correct.");
			Assert::AreEqual(Vector4F(0, 0, 0, 1), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Initialize_Default)
		{
			Matrix4x4F uut = Matrix4x4F();

			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[0], L"Row0 must be initialized to zero.");
			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[1], L"Row1 must be initialized to zero.");
			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[2], L"Row2 must be initialized to zero.");
			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[3], L"Row3 must be initialized to zero.");
		}

		TEST_METHOD(Matrix4x4F_Initialize_Values)
		{
			Matrix4x4F uut = Matrix4x4F(
				1, 2, 3, 4,
				5, 6, 7, 8,
				9, 10, 11, 12,
				13, 14, 15, 16);

			Assert::AreEqual(Vector4F(1, 2, 3, 4), uut[0], L"Row0 must be correct.");
			Assert::AreEqual(Vector4F(5, 6, 7, 8), uut[1], L"Row1 must be correct.");
			Assert::AreEqual(Vector4F(9, 10, 11, 12), uut[2], L"Row2 must be correct.");
			Assert::AreEqual(Vector4F(13, 14, 15, 16), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Initialize_Rows)
		{
			Matrix4x4F uut = Matrix4x4F(
				Vector4F(1, 2, 3, 4),
				Vector4F(5, 6, 7, 8),
				Vector4F(9, 10, 11, 12),
				Vector4F(13, 14, 15, 16));

			Assert::AreEqual(Vector4F(1, 2, 3, 4), uut[0], L"Row0 must be correct.");
			Assert::AreEqual(Vector4F(5, 6, 7, 8), uut[1], L"Row1 must be correct.");
			Assert::AreEqual(Vector4F(9, 10, 11, 12), uut[2], L"Row2 must be correct.");
			Assert::AreEqual(Vector4F(13, 14, 15, 16), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Initialize_Array)
		{
			Matrix4x4F uut = Matrix4x4F(
				{
					1, 2, 3, 4,
					5, 6, 7, 8,
					9, 10, 11, 12,
					13, 14, 15, 16
				});

			Assert::AreEqual(Vector4F(1, 2, 3, 4), uut[0], L"Row0 must be correct.");
			Assert::AreEqual(Vector4F(5, 6, 7, 8), uut[1], L"Row1 must be correct.");
			Assert::AreEqual(Vector4F(9, 10, 11, 12), uut[2], L"Row2 must be correct.");
			Assert::AreEqual(Vector4F(13, 14, 15, 16), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Set_Row0)
		{
			Matrix4x4F uut = Matrix4x4F();
			uut[0] = Vector4F(1, 2, 3, 4);

			Assert::AreEqual(Vector4F(1, 2, 3, 4), uut[0], L"Row0 must be set.");
			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[1], L"Row1 must not be set.");
			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[2], L"Row2 must not be set.");
			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[3], L"Row3 must not be set.");
		}

		TEST_METHOD(Matrix4x4F_Set_Row1)
		{
			Matrix4x4F uut = Matrix4x4F();
			uut[1] = Vector4F(1, 2, 3, 4);

			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[0], L"Row0 must not be set.");
			Assert::AreEqual(Vector4F(1, 2, 3, 4), uut[1], L"Row1 must be set.");
			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[2], L"Row2 must not be set.");
			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[3], L"Row3 must not be set.");
		}

		TEST_METHOD(Matrix4x4F_Set_Row2)
		{
			Matrix4x4F uut = Matrix4x4F();
			uut[2] = Vector4F(1, 2, 3, 4);

			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[0], L"Row0 must not be set.");
			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[1], L"Row1 must not be set.");
			Assert::AreEqual(Vector4F(1, 2, 3, 4), uut[2], L"Row2 must be set.");
			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[3], L"Row3 must not be set.");
		}

		TEST_METHOD(Matrix4x4F_Set_Row3)
		{
			Matrix4x4F uut = Matrix4x4F();
			uut[3] = Vector4F(1, 2, 3, 4);

			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[0], L"Row0 must not be set.");
			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[1], L"Row1 must not be set.");
			Assert::AreEqual(Vector4F(0, 0, 0, 0), uut[2], L"Row2 must not be set.");
			Assert::AreEqual(Vector4F(1, 2, 3, 4), uut[3], L"Row3 must be set.");
		}

		TEST_METHOD(Matrix4x4F_Operator_Assignment)
		{
			Matrix4x4F original = Matrix4x4F(
				Vector4F(1, 2, 3, 4),
				Vector4F(5, 6, 7, 8),
				Vector4F(9, 10, 11, 12),
				Vector4F(13, 14, 15, 16));
			Matrix4x4F uut = original;

			Assert::AreEqual(Vector4F(1, 2, 3, 4), uut[0], L"Row0 must be correct.");
			Assert::AreEqual(Vector4F(5, 6, 7, 8), uut[1], L"Row1 must be correct.");
			Assert::AreEqual(Vector4F(9, 10, 11, 12), uut[2], L"Row2 must be correct.");
			Assert::AreEqual(Vector4F(13, 14, 15, 16), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Operator_Assignment_Add)
		{
			Matrix4x4F uut = Matrix4x4F(
				Vector4F(1, 2, 3, 4),
				Vector4F(5, 6, 7, 8),
				Vector4F(9, 10, 11, 12),
				Vector4F(13, 14, 15, 16));
			uut += Matrix4x4F(
				Vector4F(0.1f, 0.2f, 0.3f, 0.4f),
				Vector4F(0.5f, 0.6f, 0.7f, 0.8f),
				Vector4F(0.9f, 0.10f, 0.11f, 0.12f),
				Vector4F(0.13f, 0.14f, 0.15f, 0.16f));

			Assert::AreEqual(Vector4F(1.1f, 2.2f, 3.3f, 4.4f), uut[0], L"Row0 must be correct.");
			Assert::AreEqual(Vector4F(5.5f, 6.6f, 7.7f, 8.8f), uut[1], L"Row1 must be correct.");
			Assert::AreEqual(Vector4F(9.9f, 10.10f, 11.11f, 12.12f), uut[2], L"Row2 must be correct.");
			Assert::AreEqual(Vector4F(13.13f, 14.14f, 15.15f, 16.16f), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Operator_Assignment_Subtract)
		{
			Matrix4x4F uut = Matrix4x4F(
				Vector4F(0.2f, 0.4f, 0.6f, 0.8f),
				Vector4F(1.0f, 1.2f, 1.4f, 1.6f),
				Vector4F(1.8f, 2.0f, 2.2f, 2.4f),
				Vector4F(2.6f, 2.8f, 3.0f, 3.2f));
			uut -= Matrix4x4F(
				Vector4F(0.1f, 0.2f, 0.3f, 0.4f),
				Vector4F(0.5f, 0.6f, 0.7f, 0.8f),
				Vector4F(0.9f, 1.0f, 1.1f, 1.2f),
				Vector4F(1.3f, 1.4f, 1.5f, 1.6f));

			AssertEx::AreNearEqual(Vector4F(0.1f, 0.2f, 0.3f, 0.4f), uut[0], L"Row0 must be correct.");
			AssertEx::AreNearEqual(Vector4F(0.5f, 0.6f, 0.7f, 0.8f), uut[1], L"Row1 must be correct.");
			AssertEx::AreNearEqual(Vector4F(0.9f, 1.0f, 1.1f, 1.2f), uut[2], L"Row2 must be correct.");
			AssertEx::AreNearEqual(Vector4F(1.3f, 1.4f, 1.5f, 1.6f), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Operator_Assignment_Multiply)
		{
			Matrix4x4F uut = Matrix4x4F(
				Vector4F(1.0f, 1.1f, 1.2f, 1.3f),
				Vector4F(1.4f, 1.5f, 1.6f, 1.7f),
				Vector4F(1.8f, 1.9f, 2.0f, 2.1f),
				Vector4F(2.2f, 2.3f, 2.4f, 2.5f));
			uut *= Matrix4x4F(
				Vector4F(0.01f, 0.02f, 0.03f, 0.04f),
				Vector4F(0.05f, 0.06f, 0.07f, 0.08f),
				Vector4F(0.09f, 0.10f, 0.11f, 0.12f),
				Vector4F(0.13f, 0.14f, 0.15f, 0.16f));

			AssertEx::AreNearEqual(Vector4F(0.342f, 0.388f, 0.434f, 0.480f), uut[0], L"Row0 must be correct.");
			AssertEx::AreNearEqual(Vector4F(0.454f, 0.516f, 0.578f, 0.640f), uut[1], L"Row1 must be correct.");
			AssertEx::AreNearEqual(Vector4F(0.566f, 0.644f, 0.722f, 0.800f), uut[2], L"Row2 must be correct.");
			AssertEx::AreNearEqual(Vector4F(0.678f, 0.772f, 0.866f, 0.960f), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Operator_Arithmetic_Add)
		{
			Matrix4x4F uut =
				Matrix4x4F(
					Vector4F(1, 2, 3, 4),
					Vector4F(5, 6, 7, 8),
					Vector4F(9, 10, 11, 12),
					Vector4F(13, 14, 15, 16)) +
				Matrix4x4F(
					Vector4F(0.1f, 0.2f, 0.3f, 0.4f),
					Vector4F(0.5f, 0.6f, 0.7f, 0.8f),
					Vector4F(0.9f, 0.10f, 0.11f, 0.12f),
					Vector4F(0.13f, 0.14f, 0.15f, 0.16f));

			Assert::AreEqual(Vector4F(1.1f, 2.2f, 3.3f, 4.4f), uut[0], L"Row0 must be correct.");
			Assert::AreEqual(Vector4F(5.5f, 6.6f, 7.7f, 8.8f), uut[1], L"Row1 must be correct.");
			Assert::AreEqual(Vector4F(9.9f, 10.10f, 11.11f, 12.12f), uut[2], L"Row2 must be correct.");
			Assert::AreEqual(Vector4F(13.13f, 14.14f, 15.15f, 16.16f), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Operator_Arithmetic_Subtract)
		{
			Matrix4x4F uut =
				Matrix4x4F(
					Vector4F(0.2f, 0.4f, 0.6f, 0.8f),
					Vector4F(1.0f, 1.2f, 1.4f, 1.6f),
					Vector4F(1.8f, 2.0f, 2.2f, 2.4f),
					Vector4F(2.6f, 2.8f, 3.0f, 3.2f)) -
				Matrix4x4F(
					Vector4F(0.1f, 0.2f, 0.3f, 0.4f),
					Vector4F(0.5f, 0.6f, 0.7f, 0.8f),
					Vector4F(0.9f, 1.0f, 1.1f, 1.2f),
					Vector4F(1.3f, 1.4f, 1.5f, 1.6f));

			AssertEx::AreNearEqual(Vector4F(0.1f, 0.2f, 0.3f, 0.4f), uut[0], L"Row0 must be correct.");
			AssertEx::AreNearEqual(Vector4F(0.5f, 0.6f, 0.7f, 0.8f), uut[1], L"Row1 must be correct.");
			AssertEx::AreNearEqual(Vector4F(0.9f, 1.0f, 1.1f, 1.2f), uut[2], L"Row2 must be correct.");
			AssertEx::AreNearEqual(Vector4F(1.3f, 1.4f, 1.5f, 1.6f), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Operator_Arithmetic_Multiply)
		{
			Matrix4x4F uut =
				Matrix4x4F(
					Vector4F(1.0f, 1.1f, 1.2f, 1.3f),
					Vector4F(1.4f, 1.5f, 1.6f, 1.7f),
					Vector4F(1.8f, 1.9f, 2.0f, 2.1f),
					Vector4F(2.2f, 2.3f, 2.4f, 2.5f)) *
				Matrix4x4F(
					Vector4F(0.01f, 0.02f, 0.03f, 0.04f),
					Vector4F(0.05f, 0.06f, 0.07f, 0.08f),
					Vector4F(0.09f, 0.10f, 0.11f, 0.12f),
					Vector4F(0.13f, 0.14f, 0.15f, 0.16f));

			AssertEx::AreNearEqual(Vector4F(0.342f, 0.388f, 0.434f, 0.480f), uut[0], L"Row0 must be correct.");
			AssertEx::AreNearEqual(Vector4F(0.454f, 0.516f, 0.578f, 0.640f), uut[1], L"Row1 must be correct.");
			AssertEx::AreNearEqual(Vector4F(0.566f, 0.644f, 0.722f, 0.800f), uut[2], L"Row2 must be correct.");
			AssertEx::AreNearEqual(Vector4F(0.678f, 0.772f, 0.866f, 0.960f), uut[3], L"Row3 must be correct.");
		}

		TEST_METHOD(Matrix4x4F_Operator_Comparison)
		{
			Matrix4x4F uut1 = Matrix4x4F(
				1, 1, 1, 1,
				1, 1, 1, 1,
				1, 1, 1, 1,
				1, 1, 1, 1);

			Assert::IsTrue(uut1 == uut1, L"Must equal self.");

			for (auto i = 0; i < 4; i++)
			{
				Matrix4x4F uut2 = uut1;
				uut2[i] = Vector4F(100.0f, 100.0f, 100.0f, 100.0f);

				Assert::IsFalse(uut1 == uut2, L"Must not equal.");
				Assert::IsTrue(uut1 != uut2, L"Must not equal.");
			}
		}
	};
} // namespace VectorMath::UnitTests