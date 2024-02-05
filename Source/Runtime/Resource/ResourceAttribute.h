#pragma once
#include <Runtime/Reflection/Reflection.h>
#include "ResourceAttribute.reflected.h"

namespace Portakal
{
	PCLASS();
	/// <summary>
	/// Attribute for marking a class as a resource
	/// </summary>
	class RUNTIME_API ResourceAttribute : public Attribute
	{
		GENERATE_OBJECT;
	public:
		ResourceAttribute(const String& type) : mType(type)
		{

		}
		ResourceAttribute() : mType("")
		{

		}
		~ResourceAttribute() = default;

		FORCEINLINE String GetResourceType() const noexcept
		{
			return mType;
		}
	private:
		const String mType;
	};
}

