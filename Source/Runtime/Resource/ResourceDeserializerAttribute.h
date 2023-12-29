#pragma once
#include <Runtime/Reflection/Reflection.h>

namespace Portakal
{
	class RUNTIME_API ResourceDeserializerAttribute : public Attribute
	{
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
