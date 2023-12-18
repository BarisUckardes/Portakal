#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/Command/CommandPool.h>

namespace Portakal
{
	struct RUNTIME_API CommandListDesc
	{
		SharedHeap<CommandPool> pPool;
	};
}
