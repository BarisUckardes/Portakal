#pragma once
#include <Runtime/Reflection/Reflection.h>
#include "ContextMenuItem.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API ContextMenuItem : public Attribute
	{
		GENERATE_OBJECT;
	public:
		ContextMenuItem(const String& name) : mName(name)
		{

		}
		ContextMenuItem() : mName("Unknown")
		{

		}
		~ContextMenuItem() = default;

		FORCEINLINE String GetName() const noexcept
		{
			return mName;
		}
	private:
		const String mName;
	};
}





































