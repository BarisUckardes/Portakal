#pragma once
#include <Runtime/Graphics/Command/CommandPool.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	struct RUNTIME_API CommandListDesc
	{
		SharedHeap<CommandPool> pCmdPool;
	};
}
