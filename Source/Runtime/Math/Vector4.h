#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Math/Math.h>

namespace Portakal
{
	template<typename _Tx>
	class Vector4
	{
	public:
		Vector4()
		{
			X = 0;
			Y = 0;
			Z = 0;
			W = 0;
		}

		Vector4(_Tx x, _Tx y, _Tx z, _Tx w)
		{
			X = x;
			Y = y;
			Z = z;
			W = w;
		}

		Vector4(const Vector4& other)
		{
			X = other.X;
			Y = other.Y;
			Z = other.Z;
			W = other.W;
		}

		Vector4(Vector4&& other) noexcept
		{
			X = other.X;
			Y = other.Y;
			Z = other.Z;
			W = other.W;
		}

		~Vector4() = default;

		NODISCARD _Tx Length() const noexcept
		{
			return Sqrt(X * X + Y * Y + Z * Z + W * W);
		}

		NODISCARD _Tx Distance(const Vector4& other) const noexcept
		{
			return (*this - other).Length();
		}

		NODISCARD _Tx Dot(const Vector4& other) const noexcept
		{
			return X * other.X + Y * other.Y + Z * other.Z;
		}

		NODISCARD Vector4 Cross(const Vector4& other) const noexcept
		{
			return Vector4(Y * other.Z - Z * other.Y, Z * other.X - X * other.Z, X * other.Y - Y * other.X, 0);
		}

		NODISCARD Vector4 Normalize() const noexcept
		{
			return *this / Length();
		}

		NODISCARD Vector4 Lerp(const Vector4& other, _Tx pTime) const noexcept
		{
			return *this + (other - *this) * pTime;
		}

		_Tx operator[](size_t index) const
		{
			switch (index)
			{
			case 0:
				return X;
			case 1:
				return Y;
			case 2:
				return Z;
			case 3:
				return W;
			default:
				throw "Index out of range";
			}
		}

		Vector4& operator=(const Vector4& other)
		{
			X = other.X;
			Y = other.Y;
			Z = other.Z;
			W = other.W;

			return *this;
		}

		Vector4& operator=(Vector4&& other)
		{
			X = other.X;
			Y = other.Y;
			Z = other.Z;
			W = other.W;

			return *this;
		}

		Vector4& operator+=(const Vector4& other)
		{
			X += other.X;
			Y += other.Y;
			Z += other.Z;
			W += other.W;

			return *this;
		}

		Vector4& operator-=(const Vector4& other)
		{
			X -= other.X;
			Y -= other.Y;
			Z -= other.Z;
			W -= other.W;

			return *this;
		}

		Vector4& operator*=(const Vector4& other)
		{
			X *= other.X;
			Y *= other.Y;
			Z *= other.Z;
			W *= other.W;

			return *this;
		}

		Vector4& operator/=(const Vector4& other)
		{
			X /= other.X;
			Y /= other.Y;
			Z /= other.Z;
			W /= other.W;

			return *this;
		}

		Vector4& operator+=(const _Tx& other)
		{
			X += other;
			Y += other;
			Z += other;
			W += other;

			return *this;
		}

		Vector4& operator-=(const _Tx& other)
		{
			X -= other;
			Y -= other;
			Z -= other;
			W -= other;

			return *this;
		}

		Vector4& operator*=(const _Tx& other)
		{
			X *= other;
			Y *= other;
			Z *= other;
			W *= other;

			return *this;
		}

		Vector4& operator/=(const _Tx& other)
		{
			X /= other;
			Y /= other;
			Z /= other;
			W /= other;

			return *this;
		}

		Vector4 operator+(const Vector4& other) const
		{
			return Vector4(X + other.X, Y + other.Y, Z + other.Z, W + other.W);
		}

		Vector4 operator-(const Vector4& other) const
		{
			return Vector4(X - other.X, Y - other.Y, Z - other.Z, W - other.W);
		}

		Vector4 operator*(const Vector4& other) const
		{
			return Vector4(X * other.X, Y * other.Y, Z * other.Z, W * other.W);
		}

		Vector4 operator/(const Vector4& other) const
		{
			return Vector4(X / other.X, Y / other.Y, Z / other.Z, W / other.W);
		}

		Vector4 operator+(const _Tx& other) const
		{
			return Vector4(X + other, Y + other, Z + other, W + other);
		}

		Vector4 operator-(const _Tx& other) const
		{
			return Vector4(X - other, Y - other, Z - other, W - other);
		}

		Vector4 operator*(const _Tx& other) const
		{
			return Vector4(X * other, Y * other, Z * other, W * other);
		}

		Vector4 operator/(const _Tx& other) const
		{
			return Vector4(X / other, Y / other, Z / other, W / other);
		}

		Bool8 operator==(const Vector4& other) const
		{
			return X == other.X && Y == other.Y && Z == other.Z && W == other.W;
		}

		Bool8 operator!=(const Vector4& other) const
		{
			return X != other.X || Y != other.Y || Z != other.Z || W != other.W;
		}

		Bool8 operator==(const _Tx& other) const
		{
			return X == other && Y == other && Z == other && W == other;
		}

		Bool8 operator!=(const _Tx& other) const
		{
			return X != other || Y != other || Z != other || W != other;
		}

		_Tx X;
		_Tx Y;
		_Tx Z;
		_Tx W;
	};

	template<typename _Tx>
	Vector4<_Tx> operator+(const Vector4<_Tx>& left, const Vector4<_Tx>& right)
	{
		return Vector4<_Tx>(left.X + right.X, left.Y + right.Y, left.Z + right.Z, left.W + right.W);
	}

	template<typename _Tx>
	Vector4<_Tx> operator-(const Vector4<_Tx>& left, const Vector4<_Tx>& right)
	{
		return Vector4<_Tx>(left.X - right.X, left.Y - right.Y, left.Z - right.Z, left.W - right.W);
	}

	template<typename _Tx>
	Vector4<_Tx> operator*(const Vector4<_Tx>& left, const Vector4<_Tx>& right)
	{
		return Vector4<_Tx>(left.X * right.X, left.Y * right.Y, left.Z * right.Z, left.W * right.W);
	}

	template<typename _Tx>
	Vector4<_Tx> operator/(const Vector4<_Tx>& left, const Vector4<_Tx>& right)
	{
		return Vector4<_Tx>(left.X / right.X, left.Y / right.Y, left.Z / right.Z, left.W / right.W);
	}

	template<typename _Tx>
	Vector4<_Tx> operator+(const _Tx& other, const Vector4<_Tx>& pVector)
	{
		return Vector4<_Tx>(pVector.X + other, pVector.Y + other, pVector.Z + other, pVector.W + other);
	}

	template<typename _Tx>
	Vector4<_Tx> operator-(const _Tx& other, const Vector4<_Tx>& pVector)
	{
		return Vector4<_Tx>(pVector.X - other, pVector.Y - other, pVector.Z - other, pVector.W - other);
	}

	template<typename _Tx>
	Vector4<_Tx> operator*(const _Tx& other, const Vector4<_Tx>& pVector)
	{
		return Vector4<_Tx>(pVector.X * other, pVector.Y * other, pVector.Z * other, pVector.W * other);
	}

	template<typename _Tx>
	Vector4<_Tx> operator/(const _Tx& other, const Vector4<_Tx>& pVector)
	{
		return Vector4<_Tx>(pVector.X / other, pVector.Y / other, pVector.Z / other, pVector.W / other);
	}

	template<typename _Tx>
	Vector4<_Tx> operator+(const Vector4<_Tx>& pVector, const _Tx& other)
	{
		return Vector4<_Tx>(pVector.X + other, pVector.Y + other, pVector.Z + other, pVector.W + other);
	}

	template<typename _Tx>
	Vector4<_Tx> operator-(const Vector4<_Tx>& pVector, const _Tx& other)
	{
		return Vector4<_Tx>(pVector.X - other, pVector.Y - other, pVector.Z - other, pVector.W - other);
	}

	template<typename _Tx>
	Vector4<_Tx> operator*(const Vector4<_Tx>& pVector, const _Tx& other)
	{
		return Vector4<_Tx>(pVector.X * other, pVector.Y * other, pVector.Z * other, pVector.W * other);
	}

	template<typename _Tx>
	Vector4<_Tx> operator/(const Vector4<_Tx>& pVector, const _Tx& other)
	{
		return Vector4<_Tx>(pVector.X / other, pVector.Y / other, pVector.Z / other, pVector.W / other);
	}

	template<typename _Tx>
	_Tx DotProduct(const Vector4<_Tx>& left, const Vector4<_Tx>& right)
	{
		return left.X * right.X + left.Y * right.Y + left.Z * right.Z + left.W * right.W;
	}

	template<typename _Tx>
	Vector4<_Tx> CrossProduct(const Vector4<_Tx>& left, const Vector4<_Tx>& right)
	{
		return Vector4<_Tx>(
			left.Y * right.Z - left.Z * right.Y,
			left.Z * right.X - left.X * right.Z,
			left.X * right.Y - left.Y * right.X,
			0);
	}

	template<typename _Tx>
	Vector4<_Tx> LinearInterpolation(const Vector4<_Tx>& left, const Vector4<_Tx>& right, _Tx pFactor)
	{
		return Vector4<_Tx>(
			left.X + (right.X - left.X) * pFactor,
			left.Y + (right.Y - left.Y) * pFactor,
			left.Z + (right.Z - left.Z) * pFactor,
			left.W + (right.W - left.W) * pFactor);
	}

	typedef Vector4<Int32> Vector4I;
	typedef Vector4<UInt32> Vector4UI;
	typedef Vector4<UInt16> Vector4US;
	typedef Vector4<Byte> Vector4B;
	typedef Vector4<float> Vector4F;
	typedef Vector4<double> Vector4D;
}
