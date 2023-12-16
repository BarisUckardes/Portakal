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

		Vector4(_Tx pX, _Tx pY, _Tx z, _Tx w)
		{
			X = pX;
			Y = pY;
			Z = z;
			W = w;
		}

		Vector4(const Vector4& pOther)
		{
			X = pOther.X;
			Y = pOther.Y;
			Z = pOther.Z;
			W = pOther.W;
		}

		Vector4(Vector4&& pOther) noexcept
		{
			X = pOther.X;
			Y = pOther.Y;
			Z = pOther.Z;
			W = pOther.W;
		}

		~Vector4() = default;

		NODISCARD _Tx Length() const noexcept
		{
			return Sqrt(X * X + Y * Y + Z * Z + W * W);
		}

		NODISCARD _Tx Distance(const Vector4& pOther) const noexcept
		{
			return (*this - pOther).Length();
		}

		NODISCARD _Tx Dot(const Vector4& pOther) const noexcept
		{
			return X * pOther.X + Y * pOther.Y + Z * pOther.Z;
		}

		NODISCARD Vector4 Cross(const Vector4& pOther) const noexcept
		{
			return Vector4(Y * pOther.Z - Z * pOther.Y, Z * pOther.X - X * pOther.Z, X * pOther.Y - Y * pOther.X, 0);
		}

		NODISCARD Vector4 Normalize() const noexcept
		{
			return *this / Length();
		}

		NODISCARD Vector4 Lerp(const Vector4& pOther, _Tx pTime) const noexcept
		{
			return *this + (pOther - *this) * pTime;
		}

		_Tx operator[](size_t pIndex) const
		{
			switch (pIndex)
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

		Vector4& operator=(const Vector4& pOther)
		{
			X = pOther.X;
			Y = pOther.Y;
			Z = pOther.Z;
			W = pOther.W;

			return *this;
		}

		Vector4& operator=(Vector4&& pOther)
		{
			X = pOther.X;
			Y = pOther.Y;
			Z = pOther.Z;
			W = pOther.W;

			return *this;
		}

		Vector4& operator+=(const Vector4& pOther)
		{
			X += pOther.X;
			Y += pOther.Y;
			Z += pOther.Z;
			W += pOther.W;

			return *this;
		}

		Vector4& operator-=(const Vector4& pOther)
		{
			X -= pOther.X;
			Y -= pOther.Y;
			Z -= pOther.Z;
			W -= pOther.W;

			return *this;
		}

		Vector4& operator*=(const Vector4& pOther)
		{
			X *= pOther.X;
			Y *= pOther.Y;
			Z *= pOther.Z;
			W *= pOther.W;

			return *this;
		}

		Vector4& operator/=(const Vector4& pOther)
		{
			X /= pOther.X;
			Y /= pOther.Y;
			Z /= pOther.Z;
			W /= pOther.W;

			return *this;
		}

		Vector4& operator+=(const _Tx& pOther)
		{
			X += pOther;
			Y += pOther;
			Z += pOther;
			W += pOther;

			return *this;
		}

		Vector4& operator-=(const _Tx& pOther)
		{
			X -= pOther;
			Y -= pOther;
			Z -= pOther;
			W -= pOther;

			return *this;
		}

		Vector4& operator*=(const _Tx& pOther)
		{
			X *= pOther;
			Y *= pOther;
			Z *= pOther;
			W *= pOther;

			return *this;
		}

		Vector4& operator/=(const _Tx& pOther)
		{
			X /= pOther;
			Y /= pOther;
			Z /= pOther;
			W /= pOther;

			return *this;
		}

		Vector4 operator+(const Vector4& pOther) const
		{
			return Vector4(X + pOther.X, Y + pOther.Y, Z + pOther.Z, W + pOther.W);
		}

		Vector4 operator-(const Vector4& pOther) const
		{
			return Vector4(X - pOther.X, Y - pOther.Y, Z - pOther.Z, W - pOther.W);
		}

		Vector4 operator*(const Vector4& pOther) const
		{
			return Vector4(X * pOther.X, Y * pOther.Y, Z * pOther.Z, W * pOther.W);
		}

		Vector4 operator/(const Vector4& pOther) const
		{
			return Vector4(X / pOther.X, Y / pOther.Y, Z / pOther.Z, W / pOther.W);
		}

		Vector4 operator+(const _Tx& pOther) const
		{
			return Vector4(X + pOther, Y + pOther, Z + pOther, W + pOther);
		}

		Vector4 operator-(const _Tx& pOther) const
		{
			return Vector4(X - pOther, Y - pOther, Z - pOther, W - pOther);
		}

		Vector4 operator*(const _Tx& pOther) const
		{
			return Vector4(X * pOther, Y * pOther, Z * pOther, W * pOther);
		}

		Vector4 operator/(const _Tx& pOther) const
		{
			return Vector4(X / pOther, Y / pOther, Z / pOther, W / pOther);
		}

		bool operator==(const Vector4& pOther) const
		{
			return X == pOther.X && Y == pOther.Y && Z == pOther.Z && W == pOther.W;
		}

		bool operator!=(const Vector4& pOther) const
		{
			return X != pOther.X || Y != pOther.Y || Z != pOther.Z || W != pOther.W;
		}

		bool operator==(const _Tx& pOther) const
		{
			return X == pOther && Y == pOther && Z == pOther && W == pOther;
		}

		bool operator!=(const _Tx& pOther) const
		{
			return X != pOther || Y != pOther || Z != pOther || W != pOther;
		}

		_Tx X;
		_Tx Y;
		_Tx Z;
		_Tx W;
	};

	template<typename _Tx>
	Vector4<_Tx> operator+(const Vector4<_Tx>& pLeft, const Vector4<_Tx>& pRight)
	{
		return Vector4<_Tx>(pLeft.X + pRight.X, pLeft.Y + pRight.Y, pLeft.Z + pRight.Z, pLeft.W + pRight.W);
	}

	template<typename _Tx>
	Vector4<_Tx> operator-(const Vector4<_Tx>& pLeft, const Vector4<_Tx>& pRight)
	{
		return Vector4<_Tx>(pLeft.X - pRight.X, pLeft.Y - pRight.Y, pLeft.Z - pRight.Z, pLeft.W - pRight.W);
	}

	template<typename _Tx>
	Vector4<_Tx> operator*(const Vector4<_Tx>& pLeft, const Vector4<_Tx>& pRight)
	{
		return Vector4<_Tx>(pLeft.X * pRight.X, pLeft.Y * pRight.Y, pLeft.Z * pRight.Z, pLeft.W * pRight.W);
	}

	template<typename _Tx>
	Vector4<_Tx> operator/(const Vector4<_Tx>& pLeft, const Vector4<_Tx>& pRight)
	{
		return Vector4<_Tx>(pLeft.X / pRight.X, pLeft.Y / pRight.Y, pLeft.Z / pRight.Z, pLeft.W / pRight.W);
	}

	template<typename _Tx>
	Vector4<_Tx> operator+(const _Tx& pOther, const Vector4<_Tx>& pVector)
	{
		return Vector4<_Tx>(pVector.X + pOther, pVector.Y + pOther, pVector.Z + pOther, pVector.W + pOther);
	}

	template<typename _Tx>
	Vector4<_Tx> operator-(const _Tx& pOther, const Vector4<_Tx>& pVector)
	{
		return Vector4<_Tx>(pVector.X - pOther, pVector.Y - pOther, pVector.Z - pOther, pVector.W - pOther);
	}

	template<typename _Tx>
	Vector4<_Tx> operator*(const _Tx& pOther, const Vector4<_Tx>& pVector)
	{
		return Vector4<_Tx>(pVector.X * pOther, pVector.Y * pOther, pVector.Z * pOther, pVector.W * pOther);
	}

	template<typename _Tx>
	Vector4<_Tx> operator/(const _Tx& pOther, const Vector4<_Tx>& pVector)
	{
		return Vector4<_Tx>(pVector.X / pOther, pVector.Y / pOther, pVector.Z / pOther, pVector.W / pOther);
	}

	template<typename _Tx>
	Vector4<_Tx> operator+(const Vector4<_Tx>& pVector, const _Tx& pOther)
	{
		return Vector4<_Tx>(pVector.X + pOther, pVector.Y + pOther, pVector.Z + pOther, pVector.W + pOther);
	}

	template<typename _Tx>
	Vector4<_Tx> operator-(const Vector4<_Tx>& pVector, const _Tx& pOther)
	{
		return Vector4<_Tx>(pVector.X - pOther, pVector.Y - pOther, pVector.Z - pOther, pVector.W - pOther);
	}

	template<typename _Tx>
	Vector4<_Tx> operator*(const Vector4<_Tx>& pVector, const _Tx& pOther)
	{
		return Vector4<_Tx>(pVector.X * pOther, pVector.Y * pOther, pVector.Z * pOther, pVector.W * pOther);
	}

	template<typename _Tx>
	Vector4<_Tx> operator/(const Vector4<_Tx>& pVector, const _Tx& pOther)
	{
		return Vector4<_Tx>(pVector.X / pOther, pVector.Y / pOther, pVector.Z / pOther, pVector.W / pOther);
	}

	template<typename _Tx>
	_Tx DotProduct(const Vector4<_Tx>& pLeft, const Vector4<_Tx>& pRight)
	{
		return pLeft.X * pRight.X + pLeft.Y * pRight.Y + pLeft.Z * pRight.Z + pLeft.W * pRight.W;
	}

	template<typename _Tx>
	Vector4<_Tx> CrossProduct(const Vector4<_Tx>& pLeft, const Vector4<_Tx>& pRight)
	{
		return Vector4<_Tx>(
			pLeft.Y * pRight.Z - pLeft.Z * pRight.Y,
			pLeft.Z * pRight.X - pLeft.X * pRight.Z,
			pLeft.X * pRight.Y - pLeft.Y * pRight.X,
			0);
	}

	template<typename _Tx>
	Vector4<_Tx> LinearInterpolation(const Vector4<_Tx>& pLeft, const Vector4<_Tx>& pRight, _Tx pFactor)
	{
		return Vector4<_Tx>(
			pLeft.X + (pRight.X - pLeft.X) * pFactor,
			pLeft.Y + (pRight.Y - pLeft.Y) * pFactor,
			pLeft.Z + (pRight.Z - pLeft.Z) * pFactor,
			pLeft.W + (pRight.W - pLeft.W) * pFactor);
	}

	typedef Vector4<int32> Vector4I;
	typedef Vector4<uint32> Vector4UI;
	typedef Vector4<uint16> Vector4US;
	typedef Vector4<byte> Vector4B;
	typedef Vector4<float> Vector4F;
	typedef Vector4<double> Vector4D;
}
