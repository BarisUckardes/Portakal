#pragma once
#include <Runtime/Containers/Guid.h>
#include "ResourceDescriptor.reflected.h"

namespace Portakal
{
	PCLASS();
	struct RUNTIME_API ResourceDescriptor
	{
		PFIELD();
		String SourcePath;
		PFIELD();
		String ResourceType;
		PFIELD();
		String Name;
		PFIELD();
		Guid ID;
		PFIELD();
		UInt64 FileOffset;
		PFIELD();
		UInt64 FileSize;
		PFIELD();
		Bool8 bOptimized;
	};
}








































































































































