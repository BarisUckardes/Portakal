#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Math/Math.h>

namespace Portakal
{
	/**
	 * @class Vector2
	 * @brief 2-Dimensional pVector class
	 */
	template<typename T>
	struct RUNTIME_API Vector2
	{
	public:
		static T Distance(const Vector2 x, const Vector2 y)
		{
			const Vector2 dir = y - x;
			return dir.GetLength();
		}

		static T Dot(const Vector2 x, const Vector2 y)
		{
			return x.X * y.X + x.Y * y.Y;
		}

	public:
		Vector2(const T x, const T y) : X(x), Y(y)
		{
		}

		Vector2(const T value) : X(value), Y(value)
		{
		}

		Vector2(const Vector2& other) : X(other.X), Y(other.Y)
		{
		}

		Vector2() : X(0), Y(0)
		{
		}

		~Vector2() = default;

		FORCEINLINE T GetLength() const noexcept
		{
			return Math::Sqrt(X * X + Y * Y);
		}
		FORCEINLINE Vector2 GetNormalized() const noexcept
		{
			const T length = GetLength();

			return { X / length,Y / length };
		}

		Vector2 operator+(const Vector2& other) const
		{
			return Vector2(X + other.X, Y + other.Y);
		}

		Vector2 operator-(const Vector2& other) const
		{
			return Vector2(X - other.X, Y - other.Y);
		}

		Vector2 operator*(const Vector2& other) const
		{
			return Vector2(X * other.X, Y * other.Y);
		}

		Vector2 operator/(const Vector2& other) const
		{
			return Vector2(X / other.X, Y / other.Y);
		}

		Vector2 operator+(const T& other) const
		{
			return Vector2(X + other, Y + other);
		}

		Vector2 operator-(const T& other) const
		{
			return Vector2(X - other, Y - other);
		}

		Vector2 operator*(const T& other) const
		{
			return Vector2(X * other, Y * other);
		}

		Vector2 operator/(const T& other) const
		{
			return Vector2(X / other, Y / other);
		}

		Vector2& operator+=(const Vector2& other)
		{
			X += other.X;
			Y += other.Y;
			return *this;
		}

		Vector2& operator-=(const Vector2& other)
		{
			X -= other.X;
			Y -= other.Y;
			return *this;
		}

		Vector2& operator*=(const Vector2& other)
		{
			X *= other.X;
			Y *= other.Y;
			return *this;
		}

		Vector2& operator/=(const Vector2& other)
		{
			X /= other.X;
			Y /= other.Y;
			return *this;
		}

		Vector2& operator+=(const T& other)
		{
			X += other;
			Y += other;
			return *this;
		}

		Vector2& operator-=(const T& other)
		{
			X -= other;
			Y -= other;
			return *this;
		}

		Vector2& operator*=(const T& other)
		{
			X *= other;
			Y *= other;
			return *this;
		}

		Vector2& operator/=(const T& other)
		{
			X /= other;
			Y /= other;
			return *this;
		}

		bool operator==(const Vector2& other) const
		{
			return X == other.X && Y == other.Y;
		}

		bool operator!=(const Vector2& other) const
		{
			return X != other.X || Y != other.Y;
		}

		bool operator==(const T& other) const
		{
			return X == other && Y == other;
		}

		bool operator!=(const T& other) const
		{
			return X != other || Y != other;
		}

		T X;
		T Y;
	};

	typedef Vector2<int32> Vector2I;
	typedef Vector2<uint32> Vector2UI;
	typedef Vector2<uint16> Vector2US;
	typedef Vector2<byte> Vector2B;
	typedef Vector2<short> Vector2S;
	typedef Vector2<float> Vector2F;
	typedef Vector2<double> Vector2D;
}
