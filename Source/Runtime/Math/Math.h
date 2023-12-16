#pragma once
#include <Runtime/Core/Core.h>
#include <corecrt_math.h>

namespace Portakal
{
	/**
	 * @class Math
	 * @brief Math utility tool
	 */
	class RUNTIME_API Math final
	{
	public:
		constexpr static float Epsilon = 2.7182818284590452353602874713526624977572470936999595749669676277240766303535f;
		constexpr static float Pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062f;
		constexpr static float RadToDeg = 180.0 / Pi;
		constexpr static float DegToRad = Pi / 180.0;

		template<typename T>
		FORCEINLINE static T Sqrt(const T pValue)
		{
			return sqrt(pValue);
		}

		template<typename T>
		FORCEINLINE static T Sin(const T pValue)
		{
			return sin(pValue);
		}

		template<typename T>
		FORCEINLINE static T Cos(const T pValue)
		{
			return cos(pValue);
		}

		template<typename T>
		FORCEINLINE static T Tan(const T pValue)
		{
			return tan(pValue);
		}

		template<typename T>
		FORCEINLINE static T Asin(const T pValue)
		{
			return asin(pValue);
		}

		template<typename T>
		FORCEINLINE static T Acos(const T pValue)
		{
			return acos(pValue);
		}

		template<typename T>
		FORCEINLINE static T Atan(const T pValue)
		{
			return atan(pValue);
		}

		template<typename T>
		FORCEINLINE static T Atan2(const T pX, const T pY)
		{
			return atan2(pY, pX);
		}

		template<typename T>
		FORCEINLINE static T Exp(const T pValue)
		{
			return exp(pValue);
		}

		template<typename T>
		FORCEINLINE static T Log(const T pValue)
		{
			return log(pValue);
		}

		template<typename T>
		FORCEINLINE static T Log2(const T pValue)
		{
			return log2(pValue);
		}

		template<typename T>
		FORCEINLINE static T Pow(const T pValue, const T power)
		{
			return pow(pValue, power);
		}

		template<typename T>
		FORCEINLINE static T Fmod(const T pX, const T pY)
		{
			return fmod(pX, pY);
		}

		template<typename T>
		FORCEINLINE static T Ceil(const T pValue)
		{
			return ceil(pValue);
		}

		template<typename T>
		FORCEINLINE static T Round(const T pValue)
		{
			return round(pValue);
		}

		template<typename T>
		FORCEINLINE static T Abs(const T pValue)
		{
			return fabs(pValue);
		}

		template<typename T>
		FORCEINLINE static T Sign(const T pValue)
		{
			return signbit(pValue);
		}

		template<typename T>
		FORCEINLINE static T Min(const T pX, const T pY)
		{
			return fmin(pX, pY);
		}

		template<typename T>
		FORCEINLINE static T Max(const T pX, const T pY)
		{
			return fmax(pX, pY);
		}

		template<typename T>
		FORCEINLINE static T Clamp(const T pValue, const T min, const T max)
		{
			return Min(Max(pValue, min), max);
		}

		template<typename T>
		FORCEINLINE static T Lerp(const T pX, const T pY, const T t)
		{
			return pX + (pY - pX) * t;
		}

	public:
		Math() = delete;
		~Math() = delete;
	};
}
