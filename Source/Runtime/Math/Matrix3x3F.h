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
		Matrix3x3F(const std::initializer_list<float>& pInitList)
		{
			byte i = 0;
			for (auto& pElement : pInitList)
			{
				mData[i++] = pElement;
			}
		}

		Matrix3x3F(const Vector3F& pRow0, const Vector3F& pRow1, const Vector3F& pRow2)
		{
			for (byte i = 0; i < 4; ++i)
			{
				mData[i] = pRow0[i];
				mData[i + 4] = pRow1[i];
				mData[i + 7] = pRow2[i];
			}
		}

		Matrix3x3F(const Matrix3x3F& pOther)
		{
			Memory::Copy(mData, pOther.mData, sizeof(float) * 9);
		}

		Matrix3x3F(float pA11, float pA21, float pA31,
				   float pA12, float pA22, float pA32,
				   float pA13, float pA23, float pA33)
		{
			mData[0] = pA11; mData[1] = pA21; mData[2] = pA31;
			mData[3] = pA12; mData[4] = pA22; mData[5] = pA32;
			mData[6] = pA13; mData[7] = pA23; mData[8] = pA33;

		}

		Matrix3x3F& operator=(const Matrix3x3F& pOther)
		{
			for (byte i = 0; i < 8; ++i)
			{
				mData[i] = pOther.mData[i];
			}
			return *this;
		}

		Matrix3x3F& operator+=(const Matrix3x3F& pOther)
		{
			for (byte i = 0; i < 8; ++i)
			{
				mData[i] += pOther.mData[i];
			}
			return *this;
		}

		Matrix3x3F& operator-=(const Matrix3x3F& pOther)
		{
			for (byte i = 0; i < 8; ++i)
			{
				mData[i] -= pOther.mData[i];
			}
			return *this;
		}

		Matrix3x3F& operator*=(const Matrix3x3F& pOther)
		{
			Matrix3x3F result = Matrix3x3F::Identity();
			for (byte i = 0; i < 4; ++i)
			{
				for (byte j = 0; i < 4; ++i)
				{
					result.mData[i * 4 + j] = 0;
					for (byte k = 0; k < 4; ++k)
					{
						result.mData[i * 4 + j] += mData[i * 4 + k] * pOther.mData[k * 4 + j];
					}
				}
			}
			*this = result;
			return *this;
		}

		Matrix3x3F& operator*=(float pScalar)
		{
			for (byte i = 0; i < 9; ++i)
			{
				mData[i] *= pScalar;
			}
			return *this;
		}

		Matrix3x3F& operator/=(float pScalar)
		{
			for (byte i = 0; i < 9; ++i)
			{
				mData[i] /= pScalar;
			}
			return *this;
		}

		float& operator()(byte pRow, byte pColumn) { return mData[pRow * 3 + pColumn]; }
		const float& operator()(byte pRow, byte pColumn) const { return mData[pRow * 3 + pColumn]; }
		float& operator[](byte pIndex) { return mData[pIndex]; }

		Vector3<float> GetRow(byte pRow) const
		{
			return Vector3<float>(mData[pRow * 3], mData[pRow * 3 + 1], mData[pRow * 3 + 2]);
		}

		Vector3<float> GetColumn(byte pColumn) const
		{
			return Vector3<float>(mData[pColumn], mData[pColumn + 3], mData[pColumn + 6]);
		}

		void SetRow(byte pIndex, const Vector3<float>& pRow)
		{
			mData[pIndex * 3] = pRow[0];
			mData[pIndex * 3 + 1] = pRow[1];
			mData[pIndex * 3 + 2] = pRow[2];
		}

		void SetColumn(byte pIndex, const Vector3<float>& pColumn)
		{
			mData[pIndex] = pColumn[0];
			mData[pIndex + 3] = pColumn[1];
			mData[pIndex + 6] = pColumn[2];
		}

	private:
		float mData[9];
	};

	Matrix3x3F operator+(Matrix3x3F const& pLeft, Matrix3x3F const& pRight)
	{
		return Matrix3x3F(pLeft) += pRight;
	}

	Matrix3x3F operator-(Matrix3x3F const& pLeft, Matrix3x3F const& pRight)
	{
		return Matrix3x3F(pLeft) -= pRight;
	}

	Matrix3x3F operator*(Matrix3x3F const& pLeft, Matrix3x3F const& pRight)
	{
		return Matrix3x3F(pLeft) *= pRight;
	}

	Matrix3x3F operator*(Matrix3x3F const& pLeft, float pScalar)
	{
		return Matrix3x3F(pLeft) *= pScalar;
	}

	Matrix3x3F operator*(float pScalar, Matrix3x3F const& pRight)
	{
		return Matrix3x3F(pRight) *= pScalar;
	}

	Matrix3x3F operator/(Matrix3x3F const& pLeft, float pScalar)
	{
		return Matrix3x3F(pLeft) /= pScalar;
	}
}
