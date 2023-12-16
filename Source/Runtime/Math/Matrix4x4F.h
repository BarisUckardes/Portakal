#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/Memory.h>
#include <Runtime/Math/Math.h>
#include <Runtime/Math/Matrix3x3F.h>
#include <Runtime/Math/Vector4.h>

#include <initializer_list>

namespace Portakal
{
	class RUNTIME_API Matrix4x4F
	{
	public:
		static const Matrix4x4F Identity()
		{
			return
			{ 1,0,0,0
			,0,1,0,0
			,0,0,1,0
			,0,0,0,1 };
		}

		static const Matrix4x4F Zero()
		{
			return
			{ 0,0,0,0
			,0,0,0,0
			,0,0,0,0
			,0,0,0,0 };
		}

	public:
		Matrix4x4F() = default;
		Matrix4x4F(std::initializer_list<float> pList)
		{
			for (byte i = 0; i < 16; ++i)
				mData[i] = *(pList.begin() + i);
		}

		Matrix4x4F(const Vector4F& pRow0, const Vector4F& pRow1, const Vector4F& pRow2, const Vector4F& pRow3)
		{
			for (byte i = 0; i < 4; ++i)
			{
				mData[i] = pRow0[i];
				mData[i + 4] = pRow1[i];
				mData[i + 8] = pRow2[i];
				mData[i + 12] = pRow3[i];
			}
		}

		Matrix4x4F(Matrix4x4F& pOther)
		{
			Memory::Copy(mData, pOther.mData, sizeof(float) * 16);
		}

		Matrix4x4F(float pA11, float pA21, float pA31, float pA41,
				   float pA12, float pA22, float pA32, float pA42,
				   float pA13, float pA23, float pA33, float pA43,
				   float pA14, float pA24, float pA34, float pA44)
		{
			mData[0] = pA11; mData[1] = pA21; mData[2] = pA31; mData[3] = pA41;
			mData[4] = pA12; mData[5] = pA22; mData[6] = pA32; mData[7] = pA42;
			mData[8] = pA13; mData[9] = pA23; mData[10] = pA33; mData[11] = pA43;
			mData[12] = pA14; mData[13] = pA24; mData[14] = pA34; mData[15] = pA44;
		}

		Matrix4x4F(Matrix3x3F& pOther)
		{
			mData[0] = pOther[0]; mData[1] = pOther[1]; mData[2] = pOther[2]; mData[3] = 0;
			mData[4] = pOther[3]; mData[5] = pOther[4]; mData[6] = pOther[5]; mData[7] = 0;
			mData[8] = pOther[6]; mData[9] = pOther[7]; mData[10] = pOther[8]; mData[11] = 0;
			mData[12] = 0; mData[13] = 0; mData[14] = 0; mData[15] = 1;
		}

		Matrix4x4F operator=(Matrix4x4F& pOther)
		{
			Matrix4x4F result = Matrix4x4F::Identity();
			Memory::Copy(result.mData, pOther.mData, sizeof(float) * 16);

			return result;
		}

		Matrix4x4F& operator+=(Matrix4x4F& pOther)
		{
			for (byte i = 0; i < 4; i++)
				for (byte j = 0; j < 4; j++)
					(*this)(i, j) += pOther(i, j);
			return *this;
		}

		Matrix4x4F& operator-=(Matrix4x4F& pOther)
		{
			for (byte i = 0; i < 4; i++)
				for (byte j = 0; j < 4; j++)
					(*this)(i, j) -= pOther(i, j);
			return *this;
		}

		Matrix4x4F& operator*=(Matrix4x4F& pOther)
		{
			Matrix4x4F result;
			for (byte i = 0; i < 4; i++)
				for (byte j = 0; j < 4; j++)
					for (byte k = 0; k < 4; k++)
						result(i, j) += (*this)(i, k) * pOther(k, j);
			*this = result;
			return *this;
		}

		Matrix4x4F& operator*=(float pScalar)
		{
			for (byte i = 0; i < 4; i++)
				for (byte j = 0; j < 4; j++)
					(*this)(i, j) *= pScalar;
			return *this;
		}

		Matrix4x4F& operator/=(float pScalar)
		{
			for (byte i = 0; i < 4; i++)
				for (byte j = 0; j < 4; j++)
					(*this)(i, j) /= pScalar;
			return *this;
		}

		float& operator[](byte pIndex) { return mData[pIndex]; }
		const float& operator[](byte pIndex) const { return mData[pIndex]; }
		float& operator()(byte pRow, byte pColumn) { return mData[pRow * 4 + pColumn]; }

		float* GetData() { return mData; }

		Vector4<float> GetRow(byte pIndex) const
		{
			return Vector4<float>(mData[pIndex * 4], mData[pIndex * 4 + 1], mData[pIndex * 4 + 2], mData[pIndex * 4 + 3]);
		}

		Vector4<float> GetColumn(byte pIndex) const
		{
			return Vector4<float>(mData[pIndex], mData[pIndex + 4], mData[pIndex + 8], mData[pIndex + 12]);
		}

		void SetRow(byte pIndex, const Vector4<float>& pRow)
		{
			mData[pIndex * 4] = pRow[0];
			mData[pIndex * 4 + 1] = pRow[1];
			mData[pIndex * 4 + 2] = pRow[2];
			mData[pIndex * 4 + 3] = pRow[3];
		}

		void SetColumn(byte pIndex, const Vector4<float>& pColumn)
		{
			mData[pIndex] = pColumn[0];
			mData[pIndex + 4] = pColumn[1];
			mData[pIndex + 8] = pColumn[2];
			mData[pIndex + 12] = pColumn[3];
		}

	private:
		float mData[16];
	};

	Matrix4x4F operator+(Matrix4x4F const& pLeft, Matrix4x4F const& pRight)
	{
		Matrix4x4F result = Matrix4x4F::Identity();

		for (byte i = 0; i < 16; ++i)
			result[i] = pLeft[i] + pRight[i];

		return result;
	}

	Matrix4x4F operator-(Matrix4x4F const& pLeft, Matrix4x4F const& pRight)
	{
		Matrix4x4F result = Matrix4x4F::Identity();

		for (byte i = 0; i < 16; ++i)
			result[i] = pLeft[i] - pRight[i];

		return result;
	}

	Matrix4x4F operator*(Matrix4x4F const& pLeft, Matrix4x4F const& pRight)
	{
		Matrix4x4F result = Matrix4x4F::Identity();
		for (byte i = 0; i < 4; ++i)
		{
			result[i] = pLeft[i] * pRight[0] + pLeft[i + 4] * pRight[1] + pLeft[i + 8] * pRight[2] + pLeft[i + 12] * pRight[3];
			result[i + 4] = pLeft[i] * pRight[4] + pLeft[i + 4] * pRight[5] + pLeft[i + 8] * pRight[6] + pLeft[i + 12] * pRight[7];
			result[i + 8] = pLeft[i] * pRight[8] + pLeft[i + 4] * pRight[9] + pLeft[i + 8] * pRight[10] + pLeft[i + 12] * pRight[11];
			result[i + 12] = pLeft[i] * pRight[12] + pLeft[i + 4] * pRight[13] + pLeft[i + 8] * pRight[14] + pLeft[i + 12] * pRight[15];
		}
		return result;
	}

	Matrix4x4F operator*(Matrix4x4F const& pLeft, float pScalar)
	{
		Matrix4x4F result = Matrix4x4F::Identity();
		for (byte i = 0; i < 16; ++i)
			result[i] = pLeft[i] * pScalar;

		return result;
	}

	Matrix4x4F operator*(float pScalar, Matrix4x4F const& pRight)
	{
		Matrix4x4F result = Matrix4x4F::Identity();
		for (byte i = 0; i < 16; ++i)
			result[i] = pRight[i] * pScalar;

		return result;
	}

	Matrix4x4F operator/(Matrix4x4F const& pLeft, float pScalar)
	{
		Matrix4x4F result = Matrix4x4F::Identity();
		for (byte i = 0; i < 16; ++i)
			result[i] = pLeft[i] / pScalar;

		return result;
	}

	Matrix4x4F operator/(float pScalar, Matrix4x4F const& pRight)
	{
		Matrix4x4F result = Matrix4x4F::Identity();
		for (byte i = 0; i < 16; ++i)
			result[i] = pRight[i] / pScalar;

		return result;
	}

	Matrix4x4F CreatePerspectiveMatrix(float pFov, float pAspectRatio, float pNearPlane, float pFarPlane)
	{
		float tanHalfFov = tanf(pFov / 2.0f);
		float zRange = pFarPlane - pNearPlane;

		Matrix4x4F result = Matrix4x4F::Identity();
		result(0, 0) = 1.0f / (pAspectRatio * tanHalfFov);
		result(1, 1) = 1.0f / tanHalfFov;
		result(2, 2) = -(pFarPlane + pNearPlane) / zRange;
		result(2, 3) = -(2.0f * pFarPlane * pNearPlane) / zRange;
		result(3, 2) = -1.0f;

		return result;
	}

	Matrix4x4F CreateOrthographicMatrix(float pLeft, float pRight, float pBottom, float pTop, float pNearPlane, float pFarPlane)
	{
		float width = pRight - pLeft;
		float height = pTop - pBottom;
		float depth = pFarPlane - pNearPlane;

		Matrix4x4F result = Matrix4x4F::Identity();
		result(0, 0) = 2.0f / width;
		result(1, 1) = 2.0f / height;
		result(2, 2) = -2.0f / depth;
		result(3, 0) = -(pRight + pLeft) / width;
		result(3, 1) = -(pTop + pBottom) / height;
		result(3, 2) = -(pFarPlane + pNearPlane) / depth;

		return result;
	}

	Matrix4x4F CreateViewMatrix(const Vector3F& pPosition, const Vector3F& pForward, const Vector3F& pUp)
	{
		Vector3F zAxis = pForward.GetNormalized();
		Vector3F xAxis = pUp.Cross(zAxis).GetNormalized();
		Vector3F yAxis = zAxis.Cross(xAxis);

		Matrix4x4F result = Matrix4x4F::Identity();
		result(0, 0) = xAxis.X;
		result(0, 1) = xAxis.Y;
		result(0, 2) = xAxis.Z;
		result(1, 0) = yAxis.X;
		result(1, 1) = yAxis.Y;
		result(1, 2) = yAxis.Z;
		result(2, 0) = zAxis.X;
		result(2, 1) = zAxis.Y;
		result(2, 2) = zAxis.Z;
		result(3, 0) = -xAxis.Dot(pPosition);
		result(3, 1) = -yAxis.Dot(pPosition);
		result(3, 2) = -zAxis.Dot(pPosition);

		return result;
	}

	Matrix4x4F CreateViewMatrix(const Vector3F& pPosition, const Matrix3x3F& pOrientation)
	{
		Vector3F xAxis = pOrientation.GetColumn(0);
		Vector3F yAxis = pOrientation.GetColumn(1);
		Vector3F zAxis = pOrientation.GetColumn(2);

		Matrix4x4F result = Matrix4x4F::Identity();
		result(0, 0) = xAxis.X;
		result(0, 1) = xAxis.Y;
		result(0, 2) = xAxis.Z;
		result(1, 0) = yAxis.X;
		result(1, 1) = yAxis.Y;
		result(1, 2) = yAxis.Z;
		result(2, 0) = zAxis.X;
		result(2, 1) = zAxis.Y;
		result(2, 2) = zAxis.Z;
		result(3, 0) = -xAxis.Dot(pPosition);
		result(3, 1) = -yAxis.Dot(pPosition);
		result(3, 2) = -zAxis.Dot(pPosition);


		return result;
	}

	Matrix4x4F CreateViewMatrix(const Vector3F& pPosition, const Vector3F& pForward, const Vector3F& pUp, const Vector3F& pRight)
	{
		Matrix4x4F result = Matrix4x4F::Identity();
		result(0, 0) = pRight.X;
		result(0, 1) = pRight.Y;
		result(0, 2) = pRight.Z;
		result(1, 0) = pUp.X;
		result(1, 1) = pUp.Y;
		result(1, 2) = pUp.Z;
		result(2, 0) = pForward.X;
		result(2, 1) = pForward.Y;
		result(2, 2) = pForward.Z;
		result(3, 0) = -pRight.Dot(pPosition);
		result(3, 1) = -pUp.Dot(pPosition);
		result(3, 2) = -pForward.Dot(pPosition);

		return result;
	}
}
