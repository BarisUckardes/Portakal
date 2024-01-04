#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Math/Math.h>
#include "Vector2US.reflected.h"

namespace Portakal
{
	PCLASS();
	struct RUNTIME_API Vector2US
	{
	public:
		static UInt16 Distance(const Vector2US x, const Vector2US y)
		{
			const Vector2US dir = y - x;
			return dir.GetLength();
		}

		static UInt16 Dot(const Vector2US x, const Vector2US y)
		{
			return x.X * y.X + x.Y * y.Y;
		}

	public:
		Vector2US(const UInt16 x, const UInt16 y) : X(x), Y(y)
		{
		}

		Vector2US(const UInt16 value) : X(value), Y(value)
		{
		}

		Vector2US(const Vector2US& other) : X(other.X), Y(other.Y)
		{
		}

		Vector2US() : X(0), Y(0)
		{
		}

		~Vector2US() = default;

		FORCEINLINE UInt16 GetLength() const noexcept
		{
			return Math::Sqrt(X * X + Y * Y);
		}
		FORCEINLINE Vector2US GetNormalized() const noexcept
		{
			const UInt16 length = GetLength();

			return Vector2US(X / length,Y / length);
		}

		Vector2US operator+(const Vector2US& other) const
		{
			return Vector2US(X + other.X, Y + other.Y);
		}

		Vector2US operator-(const Vector2US& other) const
		{
			return Vector2US(X - other.X, Y - other.Y);
		}

		Vector2US operator*(const Vector2US& other) const
		{
			return Vector2US(X * other.X, Y * other.Y);
		}

		Vector2US operator/(const Vector2US& other) const
		{
			return Vector2US(X / other.X, Y / other.Y);
		}

		Vector2US operator+(const UInt16& other) const
		{
			return Vector2US(X + other, Y + other);
		}

		Vector2US operator-(const UInt16& other) const
		{
			return Vector2US(X - other, Y - other);
		}

		Vector2US operator*(const UInt16& other) const
		{
			return Vector2US(X * other, Y * other);
		}

		Vector2US operator/(const UInt16& other) const
		{
			return Vector2US(X / other, Y / other);
		}

		Vector2US& operator+=(const Vector2US& other)
		{
			X += other.X;
			Y += other.Y;
			return *this;
		}

		Vector2US& operator-=(const Vector2US& other)
		{
			X -= other.X;
			Y -= other.Y;
			return *this;
		}

		Vector2US& operator*=(const Vector2US& other)
		{
			X *= other.X;
			Y *= other.Y;
			return *this;
		}

		Vector2US& operator/=(const Vector2US& other)
		{
			X /= other.X;
			Y /= other.Y;
			return *this;
		}

		Vector2US& operator+=(const UInt16& other)
		{
			X += other;
			Y += other;
			return *this;
		}

		Vector2US& operator-=(const UInt16& other)
		{
			X -= other;
			Y -= other;
			return *this;
		}

		Vector2US& operator*=(const UInt16& other)
		{
			X *= other;
			Y *= other;
			return *this;
		}

		Vector2US& operator/=(const UInt16& other)
		{
			X /= other;
			Y /= other;
			return *this;
		}

		Bool8 operator==(const Vector2US& other) const
		{
			return X == other.X && Y == other.Y;
		}

		Bool8 operator!=(const Vector2US& other) const
		{
			return X != other.X || Y != other.Y;
		}

		Bool8 operator==(const UInt16& other) const
		{
			return X == other && Y == other;
		}

		Bool8 operator!=(const UInt16& other) const
		{
			return X != other || Y != other;
		}

		PFIELD();
		UInt16 X;
		PFIELD();
		UInt16 Y;
	};
}










































