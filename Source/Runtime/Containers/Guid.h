#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Reflection/Reflection.h>
#include "Guid.reflected.h"

namespace Portakal
{
	/**
	 * @class Guid
	 * @brief 32-bit globally unique identifier.
	 */
	PCLASS();
	class RUNTIME_API Guid : public Class
	{
		GENERATE_OBJECT;
	public:
		static Guid Create();
		static Guid Create(const uint32 a, const uint32 b, const uint32 c, const uint32 d);
		static Guid Zero();
		static Guid Parse(const String& str);
		static bool TryParse(const String& str, Guid& out);
		static bool IsEmpty(const Guid& guid);
		static String ToString(const Guid& guid);
		static String FromString(const String& str);
	public:
		Guid(const uint32 a, const uint32 b, const uint32 c, const uint32 d);
		Guid(const Guid& other);
		Guid();
		~Guid() = default;

		Guid& operator=(const Guid& other);
		Guid& operator=(Guid&& other) noexcept;

		bool operator==(const Guid& other) const;
		bool operator!=(const Guid& other) const;

		uint32 A;
		uint32 B;
		uint32 C;
		uint32 D;
	};
}



