#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Math/Math.h>

namespace Portakal
{
	/**
	 * @class Vector3
	 * @brief 3-Dimensional pVector class
	 */
	template<typename T>
	struct RUNTIME_API Vector3
	{
	public:
		static T Distance(const Vector3 pX, const Vector3 pY)
		{
			const Vector3 dir = pY - pX;
			return dir.GetLength();
		}
		static T Dot(const Vector3 pX, const Vector3 pY)
		{
			return pX.X * pY.X + pX.Y * pY.Y + pX.Z * pY.Z;
		}

	public:
		Vector3(const T pX, const T pY, const T z) : X(pX), Y(pY), Z(z)
		{
		}

		Vector3(const T pValue) : X(pValue), Y(pValue), Z(pValue)
		{
		}

		Vector3(const Vector3& pOther) : X(pOther.X), Y(pOther.Y), Z(pOther.Z)
		{
		}

		Vector3() : X(0), Y(0), Z(0)
		{
		}

		~Vector3() = default;

		FORCEINLINE T GetLength() const noexcept
		{
			return Math::Sqrt(X * X + Y * Y + Z * Z);
		}

		FORCEINLINE Vector3 GetNormalized() const noexcept
		{
			const T length = GetLength();

			return { X / length,Y / length ,Z / length };
		}

		FORCEINLINE Vector3 Cross(const Vector3& pOther) const noexcept
		{
			return { Y * pOther.Z - Z * pOther.Y,Z * pOther.X - X * pOther.Z,X * pOther.Y - Y * pOther.X };
		}

		FORCEINLINE float Dot(const Vector3& pOther) const noexcept
		{
			return X * pOther.X + Y * pOther.Y + Z * pOther.Z;
		}

		T operator[](const uint32 pIndex) const
		{
			switch (pIndex)
			{
			case 0:
				return X;
			case 1:
				return Y;
			case 2:
				return Z;
			default:
				return 0;
			}
		}

		Vector3 operator+(const Vector3& pOther) const
		{
			return Vector3(X + pOther.X, Y + pOther.Y, Z + pOther.Z);
		}

		Vector3 operator-(const Vector3& pOther) const
		{
			return Vector3(X - pOther.X, Y - pOther.Y, Z - pOther.Z);
		}

		Vector3 operator*(const Vector3& pOther) const
		{
			return Vector3(X * pOther.X, Y * pOther.Y, Z * pOther.Z);
		}

		Vector3 operator/(const Vector3& pOther) const
		{
			return Vector3(X / pOther.X, Y / pOther.Y, Z / pOther.Z);
		}

		Vector3 operator+(const T& pOther) const
		{
			return Vector3(X + pOther, Y + pOther, Z + pOther);
		}

		Vector3 operator-(const T& pOther) const
		{
			return Vector3(X - pOther, Y - pOther, Z - pOther);
		}

		Vector3 operator*(const T& pOther) const
		{
			return Vector3(X * pOther, Y * pOther, Z * pOther);
		}

		Vector3 operator/(const T& pOther) const
		{
			return Vector3(X / pOther, Y / pOther, Z / pOther);
		}

		Vector3& operator+=(const Vector3& pOther)
		{
			X += pOther.X;
			Y += pOther.Y;
			Z += pOther.Z;
			return *this;
		}

		Vector3& operator-=(const Vector3& pOther)
		{
			X -= pOther.X;
			Y -= pOther.Y;
			Z -= pOther.Z;
			return *this;
		}

		Vector3& operator*=(const Vector3& pOther)
		{
			X *= pOther.X;
			Y *= pOther.Y;
			Z *= pOther.Z;
			return *this;
		}

		Vector3& operator/=(const Vector3& pOther)
		{
			X /= pOther.X;
			Y /= pOther.Y;
			Z /= pOther.Z;
			return *this;
		}

		Vector3& operator+=(const T& pOther)
		{
			X += pOther;
			Y += pOther;
			Z += pOther;
			return *this;
		}

		Vector3& operator-=(const T& pOther)
		{
			X -= pOther;
			Y -= pOther;
			Z -= pOther;
			return *this;
		}

		Vector3& operator*=(const T& pOther)
		{
			X *= pOther;
			Y *= pOther;
			Z *= pOther;
			return *this;
		}

		Vector3& operator/=(const T& pOther)
		{
			X /= pOther;
			Y /= pOther;
			Z /= pOther;
			return *this;
		}

		bool operator==(const Vector3& pOther) const
		{
			return X == pOther.X && Y == pOther.Y && Z == pOther.Z;;
		}

		bool operator!=(const Vector3& pOther) const
		{
			return X != pOther.X || Y != pOther.Y || Z != pOther.Z;
		}

		bool operator==(const T& pOther) const
		{
			return X == pOther && Y == pOther && Z == pOther;
		}

		bool operator!=(const T& pOther) const
		{
			return X != pOther || Y != pOther;
		}

		T X;
		T Y;
		T Z;
	};

	typedef Vector3<int32> Vector3I;
	typedef Vector3<uint32> Vector3UI;
	typedef Vector3<uint16> Vector3US;
	typedef Vector3<byte> Vector3B;
	typedef Vector3<float> Vector3F;
	typedef Vector3<double> Vector3D;
}
