#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceDesc.h>

namespace Portakal
{
	struct RUNTIME_API VulkanDeviceDesc : public GraphicsDeviceDesc
	{
		Array<String> Extensions;
		Array<String> Layers;
	};
}
