#pragma once
#include <Runtime/Containers/Guid.h>
#include "ResourceDescriptor.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API ResourceDescriptor
	{
	public:
		ResourceDescriptor() = default;
		~ResourceDescriptor() = default;

		PFIELD();
		String Path;
		PFIELD();
		String ResourceType;
		PFIELD();
		String Name;
		PFIELD();
		Guid ID;
		PFIELD();
		Uint64 FileOffset;
		PFIELD();
		Uint64 FileSize;
		PFIELD();
		Bool8 bOptimized;
	};
}




























































































