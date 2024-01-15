#pragma once
#include <Runtime/Reflection/Reflection.h>
#include "CustomResourceSerializer.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API CustomResourceSerializer : public Attribute
	{
		GENERATE_OBJECT;
	public:
		CustomResourceSerializer(const String& resource,const Array<String>& importExtensions) : mResource(resource),mImportExtensions(importExtensions)
		{

		}
		CustomResourceSerializer() = default;
		~CustomResourceSerializer() = default;

		FORCEINLINE String GetResourceType() const noexcept
		{
			return mResource;
		}
		FORCEINLINE const Array<String> GetImportExtensions() const noexcept
		{
			return mImportExtensions;
		}
	private:
		const String mResource;
		const Array<String> mImportExtensions;
	};
}



































































































