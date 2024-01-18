#pragma once
#include <Runtime/World/Component.h>

namespace Portakal
{
	class RUNTIME_API InvalidComponent : public Component
	{
	public:
		InvalidComponent(const String& intendedType) : mIntendedType(intendedType)
		{

		}
		~InvalidComponent() = default;

		FORCEINLINE String GetIntendedType() const noexcept
		{
			return mIntendedType;
		}
	private:
		virtual void OnInitialize() override
		{

		}
	private:
		const String mIntendedType;
	};
}
