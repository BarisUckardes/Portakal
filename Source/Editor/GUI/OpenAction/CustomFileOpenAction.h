#pragma once
#include <Runtime/Reflection/Reflection.h>
#include "CustomFileOpenAction.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API CustomFileOpenAction : public Attribute
	{
		GENERATE_OBJECT;
	public:
		CustomFileOpenAction(const String& type) : mType(type)
		{

		}
		CustomFileOpenAction() : mType("Unknown")
		{

		}
		~CustomFileOpenAction() = default;

		FORCEINLINE String GetResourceType() const noexcept
		{
			return mType;
		}
	private:
		const String mType;
	};
}

