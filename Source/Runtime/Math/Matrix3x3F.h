#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/Memory.h>
#include <Runtime/Math/Math.h>
#include <Runtime/Math/Vector3.h>

#include <initializer_list>

namespace Portakal
{
	class RUNTIME_API Matrix3x3F
	{
	public:
		static const Matrix3x3F Identity()
		{
			return
			{ 1,0,0,
			0,1,0,
			0,0,1 };
		}

		static const Matrix3x3F Zero()
		{
			return
			{ 0,0,0,
			0,0,0,
			0,0,0 };
		}

	public:
		Matrix3x3F() = default;
		Matrix3x3F(const std::initializer_list<float>& initList)
		{
			Byte i = 0;
			for (auto& pElement : initList)
			{
				mData[i++] = pElement;
			}
		}

		Matrix3x3F(const Vector3F& row0, const Vector3F& row1, const Vector3F& row2)
		{
			for (Byte i = 0; i < 4; ++i)
			{
				mData[i] = row0[i];
				mData[i + 4] = row1[i];
				mData[i + 7] = row2[i];
			}
		}

		Matrix3x3F(const Matrix3x3F& other)
		{
			Memory::Copy(mData, other.mData, sizeof(float) * 9);
		}

		Matrix3x3F(float a11, float a21, float a31,
				   float a12, float a22, float a32,
				   float a13, float a23, float a33)
		{
			mData[0] = a11; mData[1] = a21; mData[2] = a31;
			mData[3] = a12; mData[4] = a22; mData[5] = a32;
			mData[6] = a13; mData[7] = a23; mData[8] = a33;

		}

		Matrix3x3F& operator=(const Matrix3x3F& other)
		{
			for (Byte i = 0; i < 8; ++i)
			{
				mData[i] = other.mData[i];
			}
			return *this;
		}

		Matrix3x3F& operator+=(const Matrix3x3F& other)
		{
			for (Byte i = 0; i < 8; ++i)
			{
				mData[i] += other.mData[i];
			}
			return *this;
		}

		Matrix3x3F& operator-=(const Matrix3x3F& other)
		{
			for (Byte i = 0; i < 8; ++i)
			{
				mData[i] -= other.mData[i];
			}
			return *this;
		}

		Matrix3x3F& operator*=(const Matrix3x3F& other)
		{
			Matrix3x3F result = Matrix3x3F::Identity();
			for (Byte i = 0; i < 4; ++i)
			{
				for (Byte j = 0; i < 4; ++i)
				{
					result.mData[i * 4 + j] = 0;
					for (Byte k = 0; k < 4; ++k)
					{
						result.mData[i * 4 + j] += mData[i * 4 + k] * other.mData[k * 4 + j];
					}
				}
			}
			*this = result;
			return *this;
		}

		Matrix3x3F& operator*=(float scalar)
		{
			for (Byte i = 0; i < 9; ++i)
			{
				mData[i] *= scalar;
			}
			return *this;
		}

		Matrix3x3F& operator/=(float scalar)
		{
			for (Byte i = 0; i < 9; ++i)
			{
				mData[i] /= scalar;
			}
			return *this;
		}

		float& operator()(Byte row, Byte column) { return mData[row * 3 + column]; }
		const float& operator()(Byte row, Byte column) const { return mData[row * 3 + column]; }
		float& operator[](Byte index) { return mData[index]; }

		Vector3<float> GetRow(Byte row) const
		{
			return Vector3<float>(mData[row * 3], mData[row * 3 + 1], mData[row * 3 + 2]);
		}

		Vector3<float> GetColumn(Byte column) const
		{
			return Vector3<float>(mData[column], mData[column + 3], mData[column + 6]);
		}

		void SetRow(Byte index, const Vector3<float>& row)
		{
			mData[index * 3] = row[0];
			mData[index * 3 + 1] = row[1];
			mData[index * 3 + 2] = row[2];
		}

		void SetColumn(Byte index, const Vector3<float>& column)
		{
			mData[index] = column[0];
			mData[index + 3] = column[1];
			mData[index + 6] = column[2];
		}

	private:
		float mData[9];
	};

	Matrix3x3F operator+(Matrix3x3F const& left, Matrix3x3F const& right)
	{
		return Matrix3x3F(left) += right;
	}

	Matrix3x3F operator-(Matrix3x3F const& left, Matrix3x3F const& right)
	{
		return Matrix3x3F(left) -= right;
	}

	Matrix3x3F operator*(Matrix3x3F const& left, Matrix3x3F const& right)
	{
		return Matrix3x3F(left) *= right;
	}

	Matrix3x3F operator*(Matrix3x3F const& left, float scalar)
	{
		return Matrix3x3F(left) *= scalar;
	}

	Matrix3x3F operator*(float scalar, Matrix3x3F const& right)
	{
		return Matrix3x3F(right) *= scalar;
	}

	Matrix3x3F operator/(Matrix3x3F const& left, float scalar)
	{
		return Matrix3x3F(left) /= scalar;
	}
}
