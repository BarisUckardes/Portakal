#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Math/Math.h>
#include "Vector2F.reflected.h"

namespace Portakal
{
	PCLASS();
	struct RUNTIME_API Vector2F
	{
	public:
		static Float32 Distance(const Vector2F x, const Vector2F y)
		{
			const Vector2F dir = y - x;
			return dir.GetLength();
		}

		static Float32 Dot(const Vector2F x, const Vector2F y)
		{
			return x.X * y.X + x.Y * y.Y;
		}

	public:
		Vector2F(const Float32 x, const Float32 y) : X(x), Y(y)
		{
		}

		Vector2F(const Float32 value) : X(value), Y(value)
		{
		}

		Vector2F(const Vector2F& other) : X(other.X), Y(other.Y)
		{
		}

		Vector2F() : X(0), Y(0)
		{
		}

		~Vector2F() = default;

		FORCEINLINE Float32 GetLength() const noexcept
		{
			return Math::Sqrt(X * X + Y * Y);
		}
		FORCEINLINE Vector2F GetNormalized() const noexcept
		{
			const Float32 length = GetLength();

			return { X / length,Y / length };
		}

		Vector2F operator+(const Vector2F& other) const
		{
			return Vector2F(X + other.X, Y + other.Y);
		}

		Vector2F operator-(const Vector2F& other) const
		{
			return Vector2F(X - other.X, Y - other.Y);
		}

		Vector2F operator*(const Vector2F& other) const
		{
			return Vector2F(X * other.X, Y * other.Y);
		}

		Vector2F operator/(const Vector2F& other) const
		{
			return Vector2F(X / other.X, Y / other.Y);
		}

		Vector2F operator+(const Float32& other) const
		{
			return Vector2F(X + other, Y + other);
		}

		Vector2F operator-(const Float32& other) const
		{
			return Vector2F(X - other, Y - other);
		}

		Vector2F operator*(const Float32& other) const
		{
			return Vector2F(X * other, Y * other);
		}

		Vector2F operator/(const Float32& other) const
		{
			return Vector2F(X / other, Y / other);
		}

		Vector2F& operator+=(const Vector2F& other)
		{
			X += other.X;
			Y += other.Y;
			return *this;
		}

		Vector2F& operator-=(const Vector2F& other)
		{
			X -= other.X;
			Y -= other.Y;
			return *this;
		}

		Vector2F& operator*=(const Vector2F& other)
		{
			X *= other.X;
			Y *= other.Y;
			return *this;
		}

		Vector2F& operator/=(const Vector2F& other)
		{
			X /= other.X;
			Y /= other.Y;
			return *this;
		}

		Vector2F& operator+=(const Float32& other)
		{
			X += other;
			Y += other;
			return *this;
		}

		Vector2F& operator-=(const Float32& other)
		{
			X -= other;
			Y -= other;
			return *this;
		}

		Vector2F& operator*=(const Float32& other)
		{
			X *= other;
			Y *= other;
			return *this;
		}

		Vector2F& operator/=(const Float32& other)
		{
			X /= other;
			Y /= other;
			return *this;
		}

		Bool8 operator==(const Vector2F& other) const
		{
			return X == other.X && Y == other.Y;
		}

		Bool8 operator!=(const Vector2F& other) const
		{
			return X != other.X || Y != other.Y;
		}

		Bool8 operator==(const Float32& other) const
		{
			return X == other && Y == other;
		}

		Bool8 operator!=(const Float32& other) const
		{
			return X != other || Y != other;
		}

		PFIELD();
		Float32 X;
		PFIELD();
		Float32 Y;
	};
}












































