#pragma once
#include <Runtime/Reflection/Reflection.h>
#include "CustomResourceImporterAttribute.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API CustomResourceImporterAttribute : public Attribute
	{
		GENERATE_OBJECT;
	public:
		CustomResourceImporterAttribute(const String& resourceType,const Array<String>& extensions) : mResourceType(resourceType),mExtensions(extensions)
		{

		}
		CustomResourceImporterAttribute() = default;

		~CustomResourceImporterAttribute() = default;

	private:
		const String mResourceType;
		const Array<String> mExtensions;
	};
}

