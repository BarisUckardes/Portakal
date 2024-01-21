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
		
		static Matrix4x4 Perspective(T fovy, T aspect, T zNear, T zFar)
		{
			T const tanHalfFovy = tan(fovy / static_cast<T>(2));

			Matrix4x4 result = Matrix4x4::Identity();
			result[0] = static_cast<T>(1) / (aspect * tanHalfFovy);
			result[5] = static_cast<T>(1) / (tanHalfFovy);
			result[10] = -(zFar + zNear) / (zFar - zNear);
			result[11] = -static_cast<T>(1);
			result[14] = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
			return result;
		}
		//0 1 2 3
		//4 5 6 7
		//8 9 10 11
		//12 13 14 15
		static Matrix4x4 LookAt(Vector3<T> const& eye, Vector3<T> const& center, Vector3<T> const& up)
		{
			Vector3<T> const f((center - eye).GetNormalized());
			Vector3<T> const s(Vector3<T>::Cross(f, up).GetNormalized());
			Vector3<T> const u(Vector3<T>::Cross(s, f));

			Matrix4x4 result = Matrix4x4::Identity();
			result[0] = s.X;
			result[4] = s.Y;
			result[8] = s.Z;
			result[1] = u.X;
			result[5] = u.Y;
			result[9] = u.Z;
			result[2] = -f.X;
			result[6] = -f.Y;
			result[10] = -f.Z;
			result[12] = -Vector3<T>::Dot(s, eye);
			result[13] = -Vector3<T>::Dot(u, eye);
			result[14] = Vector3<T>::Dot(f, eye);
			return result;
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
		Matrix4x4(std::initializer_list<T> pList)
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

		Matrix4x4(const Matrix4x4& other)
		{
			Memory::Copy(mData, other.mData, sizeof(T) * 16);
		}

		Matrix4x4(T a11, T a21, T a31, T a41,
				   T a12, float a22, T a32, T a42,
				   T a13, T a23, T a33, T a43,
				   T a14, T a24, T a34, T a44)
		{
			mData[0] = a11; mData[1] = a21; mData[2] = a31; mData[3] = a41;
			mData[4] = a12; mData[5] = a22; mData[6] = a32; mData[7] = a42;
			mData[8] = a13; mData[9] = a23; mData[10] = a33; mData[11] = a43;
			mData[12] = a14; mData[13] = a24; mData[14] = a34; mData[15] = a44;
		}

		/// <summary>
		/// Transposes this matrix
		/// </summary>
		FORCEINLINE void Transpose()
		{
			const T snapShot[16];
			Memory::Copy(mData, snapShot, 16 * sizeof(T));

			mData[0] = snapShot[0];
			mData[1] = snapShot[4];
			mData[2] = snapShot[8];
			mData[3] = snapShot[12];

			mData[4] = snapShot[1];
			mData[5] = snapShot[5];
			mData[6] = snapShot[9];
			mData[7] = snapShot[13];

			mData[8] = snapShot[2];
			mData[9] = snapShot[6];
			mData[10] = snapShot[10];
			mData[11] = snapShot[14];

			mData[12] = snapShot[3];
			mData[13] = snapShot[7];
			mData[14] = snapShot[11];
			mData[15] = snapShot[15];
		}

		/// <summary>
		/// Returns the transposed matrix
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Matrix4x4 GetTransposed() const
		{
			T snapShot[16];
			Memory::Copy((void*)mData, (void*)snapShot, 16 * sizeof(T));

			snapShot[0] = mData[0];
			snapShot[1] = mData[4];
			snapShot[2] = mData[8];
			snapShot[3] = mData[12];

			snapShot[4] = mData[1];
			snapShot[5] = mData[5];
			snapShot[6] = mData[9];
			snapShot[7] = mData[13];

			snapShot[8] = mData[2];
			snapShot[9] = mData[6];
			snapShot[10] = mData[10];
			snapShot[11] = mData[14];

			snapShot[12] = mData[3];
			snapShot[13] = mData[7];
			snapShot[14] = mData[11];
			snapShot[15] = mData[15];

			Matrix4x4<T> output = {};
#pragma unroll
			for (unsigned int i = 0; i < 16; i++)
				output.mData[i] = snapShot[i];

			return output;
		}

		Matrix4x4 operator=(Matrix4x4& other)
		{
			Matrix4x4 result = Matrix4x4::Identity();
			Memory::Copy(result.mData, other.mData, sizeof(T) * 16);

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

		Matrix4x4& operator*=(T scalar)
		{
			for (Byte i = 0; i < 4; i++)
				for (Byte j = 0; j < 4; j++)
					(*this)(i, j) *= scalar;
			return *this;
		}

		Matrix4x4& operator/=(T scalar)
		{
			for (Byte i = 0; i < 4; i++)
				for (Byte j = 0; j < 4; j++)
					(*this)(i, j) /= scalar;
			return *this;
		}

		T& operator[](Byte index) { return mData[index]; }
		const T& operator[](Byte index) const { return mData[index]; }
		T* GetData() { return mData; }

	private:
		T mData[16];
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
	Matrix4x4<T> operator*(Matrix4x4<T> const& left, T scalar)
	{
		Matrix4x4<T> result = Matrix4x4::Identity();
		for (Byte i = 0; i < 16; ++i)
			result[i] = left[i] * scalar;

		return result;
	}
	template<typename T>
	Matrix4x4<T> operator*(T scalar, Matrix4x4<T> const& right)
	{
		Matrix4x4<T> result = Matrix4x4::Identity();
		for (Byte i = 0; i < 16; ++i)
			result[i] = right[i] * scalar;

		return result;
	}
	template<typename T>
	Matrix4x4<T> operator/(Matrix4x4<T> const& left, T scalar)
	{
		Matrix4x4<T> result = Matrix4x4::Identity();
		for (Byte i = 0; i < 16; ++i)
			result[i] = left[i] / scalar;

		return result;
	}
	template<typename T>
	Matrix4x4<T> operator/(T scalar, Matrix4x4<T> const& right)
	{
		Matrix4x4<T> result = Matrix4x4::Identity();
		for (Byte i = 0; i < 16; ++i)
			result[i] = right[i] / scalar;

		return result;
	}

	typedef Matrix4x4<float> Matrix4x4F;
}
