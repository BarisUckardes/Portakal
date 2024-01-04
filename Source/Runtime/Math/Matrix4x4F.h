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
			for (Byte i = 0; i < 16; ++i)
				mData[i] = *(pList.begin() + i);
		}

		Matrix4x4F(const Vector4F& row0, const Vector4F& row1, const Vector4F& row2, const Vector4F& pRow3)
		{
			for (Byte i = 0; i < 4; ++i)
			{
				mData[i] = row0[i];
				mData[i + 4] = row1[i];
				mData[i + 8] = row2[i];
				mData[i + 12] = pRow3[i];
			}
		}

		Matrix4x4F(Matrix4x4F& other)
		{
			Memory::Copy(mData, other.mData, sizeof(float) * 16);
		}

		Matrix4x4F(float a11, float a21, float a31, float a41,
				   float a12, float a22, float a32, float a42,
				   float a13, float a23, float a33, float a43,
				   float a14, float a24, float a34, float a44)
		{
			mData[0] = a11; mData[1] = a21; mData[2] = a31; mData[3] = a41;
			mData[4] = a12; mData[5] = a22; mData[6] = a32; mData[7] = a42;
			mData[8] = a13; mData[9] = a23; mData[10] = a33; mData[11] = a43;
			mData[12] = a14; mData[13] = a24; mData[14] = a34; mData[15] = a44;
		}

		Matrix4x4F(Matrix3x3F& other)
		{
			mData[0] = other[0]; mData[1] = other[1]; mData[2] = other[2]; mData[3] = 0;
			mData[4] = other[3]; mData[5] = other[4]; mData[6] = other[5]; mData[7] = 0;
			mData[8] = other[6]; mData[9] = other[7]; mData[10] = other[8]; mData[11] = 0;
			mData[12] = 0; mData[13] = 0; mData[14] = 0; mData[15] = 1;
		}

		Matrix4x4F operator=(Matrix4x4F& other)
		{
			Matrix4x4F result = Matrix4x4F::Identity();
			Memory::Copy(result.mData, other.mData, sizeof(float) * 16);

			return result;
		}

		Matrix4x4F& operator+=(Matrix4x4F& other)
		{
			for (Byte i = 0; i < 4; i++)
				for (Byte j = 0; j < 4; j++)
					(*this)(i, j) += other(i, j);
			return *this;
		}

		Matrix4x4F& operator-=(Matrix4x4F& other)
		{
			for (Byte i = 0; i < 4; i++)
				for (Byte j = 0; j < 4; j++)
					(*this)(i, j) -= other(i, j);
			return *this;
		}

		Matrix4x4F& operator*=(Matrix4x4F& other)
		{
			Matrix4x4F result;
			for (Byte i = 0; i < 4; i++)
				for (Byte j = 0; j < 4; j++)
					for (Byte k = 0; k < 4; k++)
						result(i, j) += (*this)(i, k) * other(k, j);
			*this = result;
			return *this;
		}

		Matrix4x4F& operator*=(float scalar)
		{
			for (Byte i = 0; i < 4; i++)
				for (Byte j = 0; j < 4; j++)
					(*this)(i, j) *= scalar;
			return *this;
		}

		Matrix4x4F& operator/=(float scalar)
		{
			for (Byte i = 0; i < 4; i++)
				for (Byte j = 0; j < 4; j++)
					(*this)(i, j) /= scalar;
			return *this;
		}

		float& operator[](Byte index) { return mData[index]; }
		const float& operator[](Byte index) const { return mData[index]; }
		float& operator()(Byte row, Byte column) { return mData[row * 4 + column]; }

		float* GetData() { return mData; }

		Vector4<float> GetRow(Byte index) const
		{
			return Vector4<float>(mData[index * 4], mData[index * 4 + 1], mData[index * 4 + 2], mData[index * 4 + 3]);
		}

		Vector4<float> GetColumn(Byte index) const
		{
			return Vector4<float>(mData[index], mData[index + 4], mData[index + 8], mData[index + 12]);
		}

		void SetRow(Byte index, const Vector4<float>& row)
		{
			mData[index * 4] = row[0];
			mData[index * 4 + 1] = row[1];
			mData[index * 4 + 2] = row[2];
			mData[index * 4 + 3] = row[3];
		}

		void SetColumn(Byte index, const Vector4<float>& column)
		{
			mData[index] = column[0];
			mData[index + 4] = column[1];
			mData[index + 8] = column[2];
			mData[index + 12] = column[3];
		}

	private:
		float mData[16];
	};

	Matrix4x4F operator+(Matrix4x4F const& left, Matrix4x4F const& right)
	{
		Matrix4x4F result = Matrix4x4F::Identity();

		for (Byte i = 0; i < 16; ++i)
			result[i] = left[i] + right[i];

		return result;
	}

	Matrix4x4F operator-(Matrix4x4F const& left, Matrix4x4F const& right)
	{
		Matrix4x4F result = Matrix4x4F::Identity();

		for (Byte i = 0; i < 16; ++i)
			result[i] = left[i] - right[i];

		return result;
	}

	Matrix4x4F operator*(Matrix4x4F const& left, Matrix4x4F const& right)
	{
		Matrix4x4F result = Matrix4x4F::Identity();
		for (Byte i = 0; i < 4; ++i)
		{
			result[i] = left[i] * right[0] + left[i + 4] * right[1] + left[i + 8] * right[2] + left[i + 12] * right[3];
			result[i + 4] = left[i] * right[4] + left[i + 4] * right[5] + left[i + 8] * right[6] + left[i + 12] * right[7];
			result[i + 8] = left[i] * right[8] + left[i + 4] * right[9] + left[i + 8] * right[10] + left[i + 12] * right[11];
			result[i + 12] = left[i] * right[12] + left[i + 4] * right[13] + left[i + 8] * right[14] + left[i + 12] * right[15];
		}
		return result;
	}

	Matrix4x4F operator*(Matrix4x4F const& left, float scalar)
	{
		Matrix4x4F result = Matrix4x4F::Identity();
		for (Byte i = 0; i < 16; ++i)
			result[i] = left[i] * scalar;

		return result;
	}

	Matrix4x4F operator*(float scalar, Matrix4x4F const& right)
	{
		Matrix4x4F result = Matrix4x4F::Identity();
		for (Byte i = 0; i < 16; ++i)
			result[i] = right[i] * scalar;

		return result;
	}

	Matrix4x4F operator/(Matrix4x4F const& left, float scalar)
	{
		Matrix4x4F result = Matrix4x4F::Identity();
		for (Byte i = 0; i < 16; ++i)
			result[i] = left[i] / scalar;

		return result;
	}

	Matrix4x4F operator/(float scalar, Matrix4x4F const& right)
	{
		Matrix4x4F result = Matrix4x4F::Identity();
		for (Byte i = 0; i < 16; ++i)
			result[i] = right[i] / scalar;

		return result;
	}

	Matrix4x4F CreatePerspectiveMatrix(float fov, float aspectRatio, float nearPlane, float farPlane)
	{
		float tanHalfFov = tanf(fov / 2.0f);
		float zRange = farPlane - nearPlane;

		Matrix4x4F result = Matrix4x4F::Identity();
		result(0, 0) = 1.0f / (aspectRatio * tanHalfFov);
		result(1, 1) = 1.0f / tanHalfFov;
		result(2, 2) = -(farPlane + nearPlane) / zRange;
		result(2, 3) = -(2.0f * farPlane * nearPlane) / zRange;
		result(3, 2) = -1.0f;

		return result;
	}

	Matrix4x4F CreateOrthographicMatrix(float left, float right, float pBottom, float pTop, float nearPlane, float farPlane)
	{
		float width = right - left;
		float height = pTop - pBottom;
		float depth = farPlane - nearPlane;

		Matrix4x4F result = Matrix4x4F::Identity();
		result(0, 0) = 2.0f / width;
		result(1, 1) = 2.0f / height;
		result(2, 2) = -2.0f / depth;
		result(3, 0) = -(right + left) / width;
		result(3, 1) = -(pTop + pBottom) / height;
		result(3, 2) = -(farPlane + nearPlane) / depth;

		return result;
	}

	Matrix4x4F CreateViewMatrix(const Vector3F& position, const Vector3F& forward, const Vector3F& up)
	{
		Vector3F zAxis = forward.GetNormalized();
		Vector3F xAxis = up.Cross(zAxis).GetNormalized();
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
		result(3, 0) = -xAxis.Dot(position);
		result(3, 1) = -yAxis.Dot(position);
		result(3, 2) = -zAxis.Dot(position);

		return result;
	}

	Matrix4x4F CreateViewMatrix(const Vector3F& position, const Matrix3x3F& orientation)
	{
		Vector3F xAxis = orientation.GetColumn(0);
		Vector3F yAxis = orientation.GetColumn(1);
		Vector3F zAxis = orientation.GetColumn(2);

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
		result(3, 0) = -xAxis.Dot(position);
		result(3, 1) = -yAxis.Dot(position);
		result(3, 2) = -zAxis.Dot(position);


		return result;
	}

	Matrix4x4F CreateViewMatrix(const Vector3F& position, const Vector3F& forward, const Vector3F& up, const Vector3F& right)
	{
		Matrix4x4F result = Matrix4x4F::Identity();
		result(0, 0) = right.X;
		result(0, 1) = right.Y;
		result(0, 2) = right.Z;
		result(1, 0) = up.X;
		result(1, 1) = up.Y;
		result(1, 2) = up.Z;
		result(2, 0) = forward.X;
		result(2, 1) = forward.Y;
		result(2, 2) = forward.Z;
		result(3, 0) = -right.Dot(position);
		result(3, 1) = -up.Dot(position);
		result(3, 2) = -forward.Dot(position);

		return result;
	}
}
