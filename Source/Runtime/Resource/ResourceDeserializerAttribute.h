#pragma once
#include <Runtime/Reflection/Reflection.h>
#include "ResourceDeserializerAttribute.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API ResourceDeserializerAttribute : public Attribute
	{
		GENERATE_OBJECT;
	public:
		ResourceDeserializerAttribute(const String& type) : mType(type)
		{

		}
		ResourceDeserializerAttribute() : mType("")
		{

		}
		~ResourceDeserializerAttribute() = default;

		FORCEINLINE String GetResourceType() const noexcept
		{
			return mType;
		}
	private:
		const String mType;
	};
}


































































































































