#pragma once
#include <Runtime/Reflection/Reflection.h>
#include "ResourceSerializerAttribute.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API ResourceSerializerAttribute : public Attribute
	{
		GENERATE_OBJECT;
	public:
		ResourceSerializerAttribute(const String& resource) : mResource(resource)
		{

		}
		ResourceSerializerAttribute() = default;
		~ResourceSerializerAttribute() = default;

		FORCEINLINE String GetResourceType() const noexcept
		{
			return mResource;
		}
	private:
		const String mResource;
	};
}














































































