#pragma once
#include <Runtime/Reflection/Attribute.h>

namespace Portakal
{
	class EDITOR_API ResourceSerializerAttribute : public Attribute
	{
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
