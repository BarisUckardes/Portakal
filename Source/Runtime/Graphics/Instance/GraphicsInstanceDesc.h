#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Graphics/Device/GraphicsBackend.h>

namespace Portakal
{
	struct RUNTIME_API GraphicsInstanceDesc
	{
		GraphicsBackend Backend;
	};
}
