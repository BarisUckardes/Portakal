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
		static Color4 Red() { return Color4(255, 0, 0, 255); }
		static Color4 DarkRed() { return Color4(128, 0, 0, 255); }
		static Color4 Black() { return Color4(0, 0, 0, 255); }
		static Color4 Blue() { return Color4(0, 0, 256, 255); }
		static Color4 DarkBlue() { return Color4(0, 0, 128, 255); }
		static Color4 CornflowerBlue() { return Color4(100 / 255.0f, 149 / 255.0f, 237 / 255.0f, 255 / 255.0f); }
		static Color4 Green() { return Color4(0, 255, 0, 255); }
		static Color4 DarkGreen() { return Color4(0, 128, 0, 255); }

		Color4(const T r, const T g, const T b, const T a) : R(r), G(g), B(b), A(a)
		{

		}

		Color4(const Color4& other) : R(other.R), G(other.G), B(other.B), A(other.A)
		{

		}

		Color4() : R(0), G(0), B(0), A(0)
		{

		}

		T operator[](const Byte index) const
		{
			switch (index)
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

		Color4& operator=(const Color4& other)
		{
			R = other.R;
			G = other.G;
			B = other.B;
			A = other.A;

			return *this;
		}

		Color4& operator+=(const Color4& other)
		{
			R += other.R;
			G += other.G;
			B += other.B;
			A += other.A;

			return *this;
		}

		Color4& operator-=(const Color4& other)
		{
			R -= other.R;
			G -= other.G;
			B -= other.B;
			A -= other.A;

			return *this;
		}

		Color4& operator*=(const Color4& other)
		{
			R *= other.R;
			G *= other.G;
			B *= other.B;
			A *= other.A;

			return *this;
		}

		Color4& operator/=(const Color4& other)
		{
			R /= other.R;
			G /= other.G;
			B /= other.B;
			A /= other.A;

			return *this;
		}

		Color4& operator+=(const T& other)
		{
			R += other;
			G += other;
			B += other;
			A += other;

			return *this;
		}

		Color4 operator+(const Color4& other) const
		{
			return Color4(R + other.R, G + other.G, B + other.B, A + other.A);
		}

		Color4 operator-(const Color4& other) const
		{
			return Color4(R - other.R, G - other.G, B - other.B, A - other.A);
		}

		Color4 operator*(const Color4& other) const
		{
			return Color4(R * other.R, G * other.G, B * other.B, A * other.A);
		}

		Color4 operator/(const Color4& other) const
		{
			return Color4(R / other.R, G / other.G, B / other.B, A / other.A);
		}

		Color4 operator+(const T& other) const
		{
			return Color4(R + other, G + other, B + other, A + other);
		}

		Color4 operator-(const T& other) const
		{
			return Color4(R - other, G - other, B - other, A - other);
		}

		Color4 operator*(const T& other) const
		{
			return Color4(R * other, G * other, B * other, A * other);
		}

		Color4 operator/(const T& other) const
		{
			return Color4(R / other, G / other, B / other, A / other);
		}

		Bool8 operator==(const Color4& other) const
		{
			return R == other.R && G == other.G && B == other.B && A == other.A;
		}

		Bool8 operator!=(const Color4& other) const
		{
			return R != other.R || G != other.G || B != other.B || A != other.A;
		}

		Bool8 operator==(const T& other) const
		{
			return R == other && G == other && B == other && A == other;
		}

		Bool8 operator!=(const T& other) const
		{
			return R != other || G != other || B != other || A != other;
		}

		T R;
		T G;
		T B;
		T A;
	};

	typedef Color4<Int32> Color4I;
	typedef Color4<Uint32> Color4UI;
	typedef Color4<Uint16> Color4US;
	typedef Color4<Byte> Color4B;
	typedef Color4<float> Color4F;
	typedef Color4<double> Color4D;
}
