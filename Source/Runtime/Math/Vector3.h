#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Math/Math.h>

namespace Portakal
{
	/**
	 * @class Vector3
	 * @brief 3-Dimensional vector class
	 */
	template<typename T>
	struct RUNTIME_API Vector3
	{
	public:
		static T Distance(const Vector3 x, const Vector3 y)
		{
			const Vector3 dir = y - x;
			return dir.GetLength();
		}
		static T Dot(const Vector3 x, const Vector3 y)
		{
			return x.X * y.X + x.Y * y.Y + x.Z * y.Z;
		}

	public:
		Vector3(const T x, const T y, const T z) : X(x), Y(y), Z(z)
		{
		}

		Vector3(const T value) : X(value), Y(value), Z(value)
		{
		}

		Vector3(const Vector3& other) : X(other.X), Y(other.Y), Z(other.Z)
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

		Vector3 operator+(const Vector3& other) const
		{
			return Vector3(X + other.X, Y + other.Y, Z + other.Z);
		}

		Vector3 operator-(const Vector3& other) const
		{
			return Vector3(X - other.X, Y - other.Y, Z - other.Z);
		}

		Vector3 operator*(const Vector3& other) const
		{
			return Vector3(X * other.X, Y * other.Y, Z * other.Z);
		}

		Vector3 operator/(const Vector3& other) const
		{
			return Vector3(X / other.X, Y / other.Y, Z / other.Z);
		}

		Vector3 operator+(const T& other) const
		{
			return Vector3(X + other, Y + other, Z + other);
		}

		Vector3 operator-(const T& other) const
		{
			return Vector3(X - other, Y - other, Z - other);
		}

		Vector3 operator*(const T& other) const
		{
			return Vector3(X * other, Y * other, Z * other);
		}

		Vector3 operator/(const T& other) const
		{
			return Vector3(X / other, Y / other, Z / other);
		}

		Vector3& operator+=(const Vector3& other)
		{
			X += other.X;
			Y += other.Y;
			Z += other.Z;
			return *this;
		}

		Vector3& operator-=(const Vector3& other)
		{
			X -= other.X;
			Y -= other.Y;
			Z -= other.Z;
			return *this;
		}

		Vector3& operator*=(const Vector3& other)
		{
			X *= other.X;
			Y *= other.Y;
			Z *= other.Z;
			return *this;
		}

		Vector3& operator/=(const Vector3& other)
		{
			X /= other.X;
			Y /= other.Y;
			Z /= other.Z;
			return *this;
		}

		Vector3& operator+=(const T& other)
		{
			X += other;
			Y += other;
			Z += other;
			return *this;
		}

		Vector3& operator-=(const T& other)
		{
			X -= other;
			Y -= other;
			Z -= other;
			return *this;
		}

		Vector3& operator*=(const T& other)
		{
			X *= other;
			Y *= other;
			Z *= other;
			return *this;
		}

		Vector3& operator/=(const T& other)
		{
			X /= other;
			Y /= other;
			Z /= other;
			return *this;
		}

		bool operator==(const Vector3& other) const
		{
			return X == other.X && Y == other.Y && Z == other.Z;;
		}

		bool operator!=(const Vector3& other) const
		{
			return X != other.X || Y != other.Y || Z != other.Z;
		}

		bool operator==(const T& other) const
		{
			return X == other && Y == other && Z == other;
		}

		bool operator!=(const T& other) const
		{
			return X != other || Y != other;
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
