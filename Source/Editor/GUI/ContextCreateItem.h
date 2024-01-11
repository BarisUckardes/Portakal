#pragma once
#include <Runtime/Reflection/Reflection.h>
#include "ContextCreateItem.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API ContextCreateItem : public Attribute
	{
		GENERATE_OBJECT;
	public:
		ContextCreateItem(const String& name) : mName(name)
		{

		}
		ContextCreateItem() : mName("Unknown")
		{

		}
		~ContextCreateItem() = default;

		FORCEINLINE String GetName() const noexcept
		{
			return mName;
		}
	private:
		const String mName;
	};
}

