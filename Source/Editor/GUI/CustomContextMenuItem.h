#pragma once
#include <Runtime/Reflection/Reflection.h>
#include "CustomContextMenuItem.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API CustomContextMenuItem : public Attribute
	{
		GENERATE_OBJECT;
	public:
		CustomContextMenuItem(const String& name) : mName(name)
		{

		}
		CustomContextMenuItem() : mName("Unknown")
		{

		}
		~CustomContextMenuItem() = default;

		FORCEINLINE String GetName() const noexcept
		{
			return mName;
		}
	private:
		const String mName;
	};
}
























