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
		static Guid Create(const UInt32 a, const UInt32 b, const UInt32 c, const UInt32 d);
		static Guid Zero();
		static Guid Parse(const String& str);
		static Bool8 TryParse(const String& str, Guid& out);
		static Bool8 IsEmpty(const Guid& guid);
		static String ToString(const Guid& guid);
		static String FromString(const String& str);
	public:
		Guid(const UInt32 a, const UInt32 b, const UInt32 c, const UInt32 d);
		Guid(const Guid& other);
		Guid();
		~Guid() = default;

		Guid& operator=(const Guid& other);
		Guid& operator=(Guid&& other) noexcept;

		Bool8 operator==(const Guid& other) const;
		Bool8 operator!=(const Guid& other) const;

		PFIELD();
		UInt32 A;
		PFIELD();
		UInt32 B;
		PFIELD();
		UInt32 C;
		PFIELD();
		UInt32 D;
	};
}







































































































































































