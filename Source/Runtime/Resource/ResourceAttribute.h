#pragma once
#include <Runtime/Reflection/Reflection.h>

namespace Portakal
{
	class RUNTIME_API ResourceAttribute : public Attribute
	{
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
