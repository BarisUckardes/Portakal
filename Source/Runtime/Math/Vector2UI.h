#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Math/Math.h>
#include "Vector2UI.reflected.h"

namespace Portakal
{
	PCLASS();
	struct RUNTIME_API Vector2UI
	{
	public:
		static Uint32 Distance(const Vector2UI x, const Vector2UI y)
		{
			const Vector2UI dir = y - x;
			return dir.GetLength();
		}

		static Uint32 Dot(const Vector2UI x, const Vector2UI y)
		{
			return x.X * y.X + x.Y * y.Y;
		}

	public:
		Vector2UI(const Uint32 x, const Uint32 y) : X(x), Y(y)
		{
		}

		Vector2UI(const Uint32 value) : X(value), Y(value)
		{
		}

		Vector2UI(const Vector2UI& other) : X(other.X), Y(other.Y)
		{
		}

		Vector2UI() : X(0), Y(0)
		{
		}

		~Vector2UI() = default;

		FORCEINLINE Uint32 GetLength() const noexcept
		{
			return Math::Sqrt(X * X + Y * Y);
		}
		FORCEINLINE Vector2UI GetNormalized() const noexcept
		{
			const Uint32 length = GetLength();

			return { X / length,Y / length };
		}

		Vector2UI operator+(const Vector2UI& other) const
		{
			return Vector2UI(X + other.X, Y + other.Y);
		}

		Vector2UI operator-(const Vector2UI& other) const
		{
			return Vector2UI(X - other.X, Y - other.Y);
		}

		Vector2UI operator*(const Vector2UI& other) const
		{
			return Vector2UI(X * other.X, Y * other.Y);
		}

		Vector2UI operator/(const Vector2UI& other) const
		{
			return Vector2UI(X / other.X, Y / other.Y);
		}

		Vector2UI operator+(const Uint32& other) const
		{
			return Vector2UI(X + other, Y + other);
		}

		Vector2UI operator-(const Uint32& other) const
		{
			return Vector2UI(X - other, Y - other);
		}

		Vector2UI operator*(const Uint32& other) const
		{
			return Vector2UI(X * other, Y * other);
		}

		Vector2UI operator/(const Uint32& other) const
		{
			return Vector2UI(X / other, Y / other);
		}

		Vector2UI& operator+=(const Vector2UI& other)
		{
			X += other.X;
			Y += other.Y;
			return *this;
		}

		Vector2UI& operator-=(const Vector2UI& other)
		{
			X -= other.X;
			Y -= other.Y;
			return *this;
		}

		Vector2UI& operator*=(const Vector2UI& other)
		{
			X *= other.X;
			Y *= other.Y;
			return *this;
		}

		Vector2UI& operator/=(const Vector2UI& other)
		{
			X /= other.X;
			Y /= other.Y;
			return *this;
		}

		Vector2UI& operator+=(const Uint32& other)
		{
			X += other;
			Y += other;
			return *this;
		}

		Vector2UI& operator-=(const Uint32& other)
		{
			X -= other;
			Y -= other;
			return *this;
		}

		Vector2UI& operator*=(const Uint32& other)
		{
			X *= other;
			Y *= other;
			return *this;
		}

		Vector2UI& operator/=(const Uint32& other)
		{
			X /= other;
			Y /= other;
			return *this;
		}

		Bool8 operator==(const Vector2UI& other) const
		{
			return X == other.X && Y == other.Y;
		}

		Bool8 operator!=(const Vector2UI& other) const
		{
			return X != other.X || Y != other.Y;
		}

		Bool8 operator==(const Uint32& other) const
		{
			return X == other && Y == other;
		}

		Bool8 operator!=(const Uint32& other) const
		{
			return X != other || Y != other;
		}

		PFIELD();
		Uint32 X;
		PFIELD();
		Uint32 Y;
	};
}






















