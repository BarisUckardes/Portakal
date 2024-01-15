#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Guid.h>
#include "DomainFileDescriptor.reflected.h"

namespace Portakal
{
	PCLASS();
	struct EDITOR_API DomainFileDescriptor
	{
		PFIELD();
		String Target;
		PFIELD();
		String Type;
		PFIELD();
		Guid ID;
	};
}

