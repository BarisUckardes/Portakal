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
		uint64 FileOffset;
		PFIELD();
		uint64 FileSize;
		PFIELD();
		bool8 bOptimized;
	};
}


















