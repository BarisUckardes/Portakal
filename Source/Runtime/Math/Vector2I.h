#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Math/Math.h>
#include "Vector2I.reflected.h"

namespace Portakal
{
	PCLASS();
	struct RUNTIME_API Vector2I
	{
	public:
		static Int32 Distance(const Vector2I x, const Vector2I y)
		{
			const Vector2I dir = y - x;
			return dir.GetLength();
		}

		static Int32 Dot(const Vector2I x, const Vector2I y)
		{
			return x.X * y.X + x.Y * y.Y;
		}

	public:
		Vector2I(const Int32 x, const Int32 y) : X(x), Y(y)
		{
		}

		Vector2I(const Int32 value) : X(value), Y(value)
		{
		}

		Vector2I(const Vector2I& other) : X(other.X), Y(other.Y)
		{
		}

		Vector2I() : X(0), Y(0)
		{
		}

		~Vector2I() = default;

		FORCEINLINE Int32 GetLength() const noexcept
		{
			return Math::Sqrt(X * X + Y * Y);
		}
		FORCEINLINE Vector2I GetNormalized() const noexcept
		{
			const Int32 length = GetLength();

			return { X / length,Y / length };
		}

		Vector2I operator+(const Vector2I& other) const
		{
			return Vector2I(X + other.X, Y + other.Y);
		}

		Vector2I operator-(const Vector2I& other) const
		{
			return Vector2I(X - other.X, Y - other.Y);
		}

		Vector2I operator*(const Vector2I& other) const
		{
			return Vector2I(X * other.X, Y * other.Y);
		}

		Vector2I operator/(const Vector2I& other) const
		{
			return Vector2I(X / other.X, Y / other.Y);
		}

		Vector2I operator+(const Int32& other) const
		{
			return Vector2I(X + other, Y + other);
		}

		Vector2I operator-(const Int32& other) const
		{
			return Vector2I(X - other, Y - other);
		}

		Vector2I operator*(const Int32& other) const
		{
			return Vector2I(X * other, Y * other);
		}

		Vector2I operator/(const Int32& other) const
		{
			return Vector2I(X / other, Y / other);
		}

		Vector2I& operator+=(const Vector2I& other)
		{
			X += other.X;
			Y += other.Y;
			return *this;
		}

		Vector2I& operator-=(const Vector2I& other)
		{
			X -= other.X;
			Y -= other.Y;
			return *this;
		}

		Vector2I& operator*=(const Vector2I& other)
		{
			X *= other.X;
			Y *= other.Y;
			return *this;
		}

		Vector2I& operator/=(const Vector2I& other)
		{
			X /= other.X;
			Y /= other.Y;
			return *this;
		}

		Vector2I& operator+=(const Int32& other)
		{
			X += other;
			Y += other;
			return *this;
		}

		Vector2I& operator-=(const Int32& other)
		{
			X -= other;
			Y -= other;
			return *this;
		}

		Vector2I& operator*=(const Int32& other)
		{
			X *= other;
			Y *= other;
			return *this;
		}

		Vector2I& operator/=(const Int32& other)
		{
			X /= other;
			Y /= other;
			return *this;
		}

		Bool8 operator==(const Vector2I& other) const
		{
			return X == other.X && Y == other.Y;
		}

		Bool8 operator!=(const Vector2I& other) const
		{
			return X != other.X || Y != other.Y;
		}

		Bool8 operator==(const Int32& other) const
		{
			return X == other && Y == other;
		}

		Bool8 operator!=(const Int32& other) const
		{
			return X != other || Y != other;
		}

		PFIELD();
		Int32 X;
		PFIELD();
		Int32 Y;
	};
}












































