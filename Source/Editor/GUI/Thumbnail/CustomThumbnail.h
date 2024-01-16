#pragma once
#include <Runtime/Reflection/Reflection.h>
#include "CustomThumbnail.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API CustomThumbnail : public Attribute
	{
		GENERATE_OBJECT;
	public:
		CustomThumbnail(const String& type) : mType(type)
		{

		}
		CustomThumbnail() = default;
		~CustomThumbnail() = default;

		FORCEINLINE String GetResourceType() const noexcept
		{
			return mType;
		}
	private:
		const String mType;
	};
}


