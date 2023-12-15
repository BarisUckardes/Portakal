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
		static T Distance(const Vector2 pX, const Vector2 pY)
		{
			const Vector2 dir = pY - pX;
			return dir.GetLength();
		}

		static T Dot(const Vector2 pX, const Vector2 pY)
		{
			return pX.X * pY.X + pX.Y * pY.Y;
		}

	public:
		Vector2(const T pX, const T pY) : X(pX), Y(pY)
		{
		}

		Vector2(const T pValue) : X(pValue), Y(pValue)
		{
		}

		Vector2(const Vector2& pOther) : X(pOther.X), Y(pOther.Y)
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

		Vector2 operator+(const Vector2& pOther) const
		{
			return Vector2(X + pOther.X, Y + pOther.Y);
		}

		Vector2 operator-(const Vector2& pOther) const
		{
			return Vector2(X - pOther.X, Y - pOther.Y);
		}

		Vector2 operator*(const Vector2& pOther) const
		{
			return Vector2(X * pOther.X, Y * pOther.Y);
		}

		Vector2 operator/(const Vector2& pOther) const
		{
			return Vector2(X / pOther.X, Y / pOther.Y);
		}

		Vector2 operator+(const T& pOther) const
		{
			return Vector2(X + pOther, Y + pOther);
		}

		Vector2 operator-(const T& pOther) const
		{
			return Vector2(X - pOther, Y - pOther);
		}

		Vector2 operator*(const T& pOther) const
		{
			return Vector2(X * pOther, Y * pOther);
		}

		Vector2 operator/(const T& pOther) const
		{
			return Vector2(X / pOther, Y / pOther);
		}

		Vector2& operator+=(const Vector2& pOther)
		{
			X += pOther.X;
			Y += pOther.Y;
			return *this;
		}

		Vector2& operator-=(const Vector2& pOther)
		{
			X -= pOther.X;
			Y -= pOther.Y;
			return *this;
		}

		Vector2& operator*=(const Vector2& pOther)
		{
			X *= pOther.X;
			Y *= pOther.Y;
			return *this;
		}

		Vector2& operator/=(const Vector2& pOther)
		{
			X /= pOther.X;
			Y /= pOther.Y;
			return *this;
		}

		Vector2& operator+=(const T& pOther)
		{
			X += pOther;
			Y += pOther;
			return *this;
		}

		Vector2& operator-=(const T& pOther)
		{
			X -= pOther;
			Y -= pOther;
			return *this;
		}

		Vector2& operator*=(const T& pOther)
		{
			X *= pOther;
			Y *= pOther;
			return *this;
		}

		Vector2& operator/=(const T& pOther)
		{
			X /= pOther;
			Y /= pOther;
			return *this;
		}

		bool operator==(const Vector2& pOther) const
		{
			return X == pOther.X && Y == pOther.Y;
		}

		bool operator!=(const Vector2& pOther) const
		{
			return X != pOther.X || Y != pOther.Y;
		}

		bool operator==(const T& pOther) const
		{
			return X == pOther && Y == pOther;
		}

		bool operator!=(const T& pOther) const
		{
			return X != pOther || Y != pOther;
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
