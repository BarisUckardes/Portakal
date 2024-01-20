#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/Memory.h>
#include <Runtime/Math/Math.h>
#include <Runtime/Math/Vector4.h>
#include <Runtime/Math/Vector3.h>
#include <initializer_list>

namespace Portakal
{
	template<typename T>
	class RUNTIME_API Matrix4x4
	{
	public:
		static Matrix4x4 Translation(const Vector3<T>& pos)
		{
			return
			{
				1,0,0,0,
				0,1,0,0,
				0,0,1,0,
				pos.X,pos.Y,pos.Z,1
			};
		}
		static Matrix4x4 Scale(const Vector3<T>& scale)
		{
			return
			{
				scale.X,0,0,0,
				0,scale.Y,0,0,
				0,0,scale.Z,0,
				0,0,0,1
			};
		}
		static Matrix4x4 RotationX(const T rot)
		{
			return
			{
				1,0,0,0,
				0,Math::Cos(rot),-Math::Sin(rot),0,
				0,Math::Sin(rot),Math::Cos(rot),0,
				0,0,0,1
			};
		}
		static Matrix4x4 RotationY(const T rot)
		{
			return
			{
				Math::Cos(rot),0,Math::Sin(rot),0,
				0,1,0,0,
				-Math::Sin(rot),0,Math::Cos(rot),0,
				0,0,0,1
			};
		}
		static Matrix4x4 RotationZ(const T rot)
		{
			return
			{
				Math::Cos(rot),-Math::Sin(rot),0,0,
				Math::Sin(rot),Math::Cos(rot),0,0,
				0,0,1,0,
				0,0,0,1
			};
		}
		static Matrix4x4 Ortho(const T left, const T right, const T bottom, const T top, const T n, const T f)
		{
			return
			{
				(T)(2) / (right - left),0,0,0,
				0,(T)(2) / (top - bottom),0,0,
				0,0,(T)(2) / (f - n),0,
				0,0,0,0
			};
		}
		static Matrix4x4 Ortho(const T left, const T right, const T bottom, const T top, const T n, const T f, const T aspectRatio)
		{
			return
			{
				(T)(2) / (right - left),0,0,0,
				0,((T)(2) / (top - bottom)) * aspectRatio,0,0,
				0,0,(T)(2) / (f - n),0,
				(right + left) / (right - left),(top + bottom) / (top - bottom), (f + n) / (f - n),1
			};
		}
		static Matrix4x4 Perspective(const T f, const T n, const T aspect, const T fov)
		{
			const T tanh2 = Math::Tan(fov / 2);
			return
			{
				1/(aspect*tanh2),0,0,0,
				0,1/tanh2,0,0,
				0,0,-((f+n)/(f-n)),-(2*(f*n)/(f-n)),
				0,0,-1,0
			};
		}
		static const Matrix4x4 Identity()
		{
			return
			{ 1,0,0,0
			,0,1,0,0
			,0,0,1,0
			,0,0,0,1 };
		}

		static const Matrix4x4 Zero()
		{
			return
			{ 0,0,0,0
			,0,0,0,0
			,0,0,0,0
			,0,0,0,0 };
		}

	public:
		Matrix4x4() = default;
		Matrix4x4(std::initializer_list<float> pList)
		{
			for (Byte i = 0; i < 16; ++i)
				mData[i] = *(pList.begin() + i);
		}

		Matrix4x4(const Vector4F& row0, const Vector4F& row1, const Vector4F& row2, const Vector4F& pRow3)
		{
			for (Byte i = 0; i < 4; ++i)
			{
				mData[i] = row0[i];
				mData[i + 4] = row1[i];
				mData[i + 8] = row2[i];
				mData[i + 12] = pRow3[i];
			}
		}

		Matrix4x4(Matrix4x4& other)
		{
			Memory::Copy(mData, other.mData, sizeof(float) * 16);
		}

		Matrix4x4(float a11, float a21, float a31, float a41,
				   float a12, float a22, float a32, float a42,
				   float a13, float a23, float a33, float a43,
				   float a14, float a24, float a34, float a44)
		{
			mData[0] = a11; mData[1] = a21; mData[2] = a31; mData[3] = a41;
			mData[4] = a12; mData[5] = a22; mData[6] = a32; mData[7] = a42;
			mData[8] = a13; mData[9] = a23; mData[10] = a33; mData[11] = a43;
			mData[12] = a14; mData[13] = a24; mData[14] = a34; mData[15] = a44;
		}

		Matrix4x4 operator=(Matrix4x4& other)
		{
			Matrix4x4 result = Matrix4x4::Identity();
			Memory::Copy(result.mData, other.mData, sizeof(float) * 16);

			return result;
		}

		Matrix4x4& operator+=(Matrix4x4& other)
		{
			for (Byte i = 0; i < 4; i++)
				for (Byte j = 0; j < 4; j++)
					(*this)(i, j) += other(i, j);
			return *this;
		}

		Matrix4x4& operator-=(Matrix4x4& other)
		{
			for (Byte i = 0; i < 4; i++)
				for (Byte j = 0; j < 4; j++)
					(*this)(i, j) -= other(i, j);
			return *this;
		}

		Matrix4x4& operator*=(Matrix4x4& other)
		{
			Matrix4x4 result;
			for (Byte i = 0; i < 4; i++)
				for (Byte j = 0; j < 4; j++)
					for (Byte k = 0; k < 4; k++)
						result(i, j) += (*this)(i, k) * other(k, j);
			*this = result;
			return *this;
		}

		Matrix4x4& operator*=(float scalar)
		{
			for (Byte i = 0; i < 4; i++)
				for (Byte j = 0; j < 4; j++)
					(*this)(i, j) *= scalar;
			return *this;
		}

		Matrix4x4& operator/=(float scalar)
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

	template<typename T>
	Matrix4x4<T> operator+(Matrix4x4<T> const& left, Matrix4x4<T> const& right)
	{
		Matrix4x4<T> result = Matrix4x4::Identity();

		for (Byte i = 0; i < 16; ++i)
			result[i] = left[i] + right[i];

		return result;
	}
	template<typename T>
	Matrix4x4<T> operator-(Matrix4x4<T> const& left, Matrix4x4<T> const& right)
	{
		Matrix4x4<T> result = Matrix4x4::Identity();

		for (Byte i = 0; i < 16; ++i)
			result[i] = left[i] - right[i];

		return result;
	}
	template<typename T>
	Matrix4x4<T> operator*(Matrix4x4<T> const& left, Matrix4x4<T> const& right)
	{
		Matrix4x4<T> result = Matrix4x4<T>::Identity();
		for (Byte i = 0; i < 4; ++i)
		{
			result[i] = left[i] * right[0] + left[i + 4] * right[1] + left[i + 8] * right[2] + left[i + 12] * right[3];
			result[i + 4] = left[i] * right[4] + left[i + 4] * right[5] + left[i + 8] * right[6] + left[i + 12] * right[7];
			result[i + 8] = left[i] * right[8] + left[i + 4] * right[9] + left[i + 8] * right[10] + left[i + 12] * right[11];
			result[i + 12] = left[i] * right[12] + left[i + 4] * right[13] + left[i + 8] * right[14] + left[i + 12] * right[15];
		}
		return result;
	}
	template<typename T>
	Matrix4x4<T> operator*(Matrix4x4<T> const& left, float scalar)
	{
		Matrix4x4<T> result = Matrix4x4::Identity();
		for (Byte i = 0; i < 16; ++i)
			result[i] = left[i] * scalar;

		return result;
	}
	template<typename T>
	Matrix4x4<T> operator*(float scalar, Matrix4x4<T> const& right)
	{
		Matrix4x4<T> result = Matrix4x4::Identity();
		for (Byte i = 0; i < 16; ++i)
			result[i] = right[i] * scalar;

		return result;
	}
	template<typename T>
	Matrix4x4<T> operator/(Matrix4x4<T> const& left, float scalar)
	{
		Matrix4x4<T> result = Matrix4x4::Identity();
		for (Byte i = 0; i < 16; ++i)
			result[i] = left[i] / scalar;

		return result;
	}
	template<typename T>
	Matrix4x4<T> operator/(float scalar, Matrix4x4<T> const& right)
	{
		Matrix4x4<T> result = Matrix4x4::Identity();
		for (Byte i = 0; i < 16; ++i)
			result[i] = right[i] / scalar;

		return result;
	}

	typedef Matrix4x4<float> Matrix4x4F;
}
