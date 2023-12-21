#pragma once
#include <Runtime/Math/Vector2.h>
#include <Runtime/Memory/MemoryOwnedView.h>

namespace Portakal
{
	struct RUNTIME_API TextureLoadResult
	{
		Vector2US Size;
		MemoryOwnedView* pView;
	};
}
