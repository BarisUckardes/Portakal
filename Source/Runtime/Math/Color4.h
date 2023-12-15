#pragma once
#include <Runtime/Math/Math.h>

namespace Portakal
{
	/**
	 * @class Color4
	 * @brief 4 component color class
	 */
	template<typename T>
	struct RUNTIME_API Color4
	{
		Color4(const T r, const T g, const T b, const T a) : R(r), G(g), B(b), A(a)
		{

		}

		Color4(const Color4& pOther) : R(pOther.R), G(pOther.G), B(pOther.B), A(pOther.A)
		{

		}

		Color4() : R(0), G(0), B(0), A(0)
		{

		}

		T operator[](const byte pIndex) const
		{
			switch (pIndex)
			{
			case 0:
				return R;
			case 1:
				return G;
			case 2:
				return B;
			case 3:
				return A;
			default:
				throw "Index out of range";
			}
		}

		Color4& operator=(const Color4& pOther)
		{
			R = pOther.R;
			G = pOther.G;
			B = pOther.B;
			A = pOther.A;

			return *this;
		}

		Color4& operator+=(const Color4& pOther)
		{
			R += pOther.R;
			G += pOther.G;
			B += pOther.B;
			A += pOther.A;

			return *this;
		}

		Color4& operator-=(const Color4& pOther)
		{
			R -= pOther.R;
			G -= pOther.G;
			B -= pOther.B;
			A -= pOther.A;

			return *this;
		}

		Color4& operator*=(const Color4& pOther)
		{
			R *= pOther.R;
			G *= pOther.G;
			B *= pOther.B;
			A *= pOther.A;

			return *this;
		}

		Color4& operator/=(const Color4& pOther)
		{
			R /= pOther.R;
			G /= pOther.G;
			B /= pOther.B;
			A /= pOther.A;

			return *this;
		}

		Color4& operator+=(const T& pOther)
		{
			R += pOther;
			G += pOther;
			B += pOther;
			A += pOther;

			return *this;
		}

		Color4 operator+(const Color4& pOther) const
		{
			return Color4(R + pOther.R, G + pOther.G, B + pOther.B, A + pOther.A);
		}

		Color4 operator-(const Color4& pOther) const
		{
			return Color4(R - pOther.R, G - pOther.G, B - pOther.B, A - pOther.A);
		}

		Color4 operator*(const Color4& pOther) const
		{
			return Color4(R * pOther.R, G * pOther.G, B * pOther.B, A * pOther.A);
		}

		Color4 operator/(const Color4& pOther) const
		{
			return Color4(R / pOther.R, G / pOther.G, B / pOther.B, A / pOther.A);
		}

		Color4 operator+(const T& pOther) const
		{
			return Color4(R + pOther, G + pOther, B + pOther, A + pOther);
		}

		Color4 operator-(const T& pOther) const
		{
			return Color4(R - pOther, G - pOther, B - pOther, A - pOther);
		}

		Color4 operator*(const T& pOther) const
		{
			return Color4(R * pOther, G * pOther, B * pOther, A * pOther);
		}

		Color4 operator/(const T& pOther) const
		{
			return Color4(R / pOther, G / pOther, B / pOther, A / pOther);
		}

		bool operator==(const Color4& pOther) const
		{
			return R == pOther.R && G == pOther.G && B == pOther.B && A == pOther.A;
		}

		bool operator!=(const Color4& pOther) const
		{
			return R != pOther.R || G != pOther.G || B != pOther.B || A != pOther.A;
		}

		bool operator==(const T& pOther) const
		{
			return R == pOther && G == pOther && B == pOther && A == pOther;
		}

		bool operator!=(const T& pOther) const
		{
			return R != pOther || G != pOther || B != pOther || A != pOther;
		}

		T R;
		T G;
		T B;
		T A;
	};

	typedef Color4<int32> Color4I;
	typedef Color4<uint32> Color4UI;
	typedef Color4<uint16> Color4US;
	typedef Color4<byte> Color4B;
	typedef Color4<float> Color4F;
	typedef Color4<double> Color4D;
}
