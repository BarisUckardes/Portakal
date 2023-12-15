#pragma once
#include <Runtime/Core/Core.h>
#include <corecrt_math.h>

namespace Portakal
{
	#define PI  3.1415926535897932384626433832795028841971693993751058209749445923078164062f
	#define	RadToDeg 180.0 / PI;
	#define DegToRad PI / 180.0;
	class RUNTIME_API Math final
	{
	public:
		template<typename T>
		FORCEINLINE static T Sqrt(const T value)
		{
			return sqrt(value);
		}

		template<typename T>
		FORCEINLINE static T Sin(const T value)
		{
			return sin(value);
		}

		template<typename T>
		FORCEINLINE static T Cos(const T value)
		{
			return cos(value);
		}

		template<typename T>
		FORCEINLINE static T Tan(const T value)
		{
			return tan(value);
		}

		template<typename T>
		FORCEINLINE static T Asin(const T value)
		{
			return asin(value);
		}

		template<typename T>
		FORCEINLINE static T Acos(const T value)
		{
			return acos(value);
		}

		template<typename T>
		FORCEINLINE static T Atan(const T value)
		{
			return atan(value);
		}

		template<typename T>
		FORCEINLINE static T Atan2(const T x,const T y)
		{
			return atan2(y,x);
		}

		template<typename T>
		FORCEINLINE static T Exp(const T value)
		{
			return exp(value);
		}

		template<typename T>
		FORCEINLINE static T Log(const T value)
		{
			return log(value);
		}

		template<typename T>
		FORCEINLINE static T Log2(const T value)
		{
			return log2(value);
		}

		template<typename T>
		FORCEINLINE static T Pow(const T value, const T power)
		{
			return pow(value, power);
		}

		template<typename T>
		FORCEINLINE static T Fmod(const T x, const T y)
		{
			return fmod(x, y);
		}

		template<typename T>
		FORCEINLINE static T Ceil(const T value)
		{
			return ceil(value);
		}

		template<typename T>
		FORCEINLINE static T Round(const T value)
		{
			return round(value);
		}

		template<typename T>
		FORCEINLINE static T Abs(const T value)
		{
			return fabs(value);
		}

		template<typename T>
		FORCEINLINE static T Sign(const T value)
		{
			return signbit(value);
		}

		template<typename T>
		FORCEINLINE static T Min(const T x, const T y)
		{
			return fmin(x, y);
		}

		template<typename T>
		FORCEINLINE static T Max(const T x, const T y)
		{
			return fmax(x, y);
		}

		template<typename T>
		FORCEINLINE static T Clamp(const T value, const T min, const T max)
		{
			return Min(Max(value, min), max);
		}

		template<typename T>
		FORCEINLINE static T Lerp(const T x, const T y, const T t)
		{
			return x + (y - x) * t;
		}

	public:
		Math() = delete;
		~Math() = delete;
	};
}
