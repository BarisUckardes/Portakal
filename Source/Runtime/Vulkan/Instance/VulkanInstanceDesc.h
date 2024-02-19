#pragma once
#include <Runtime/Graphics/Instance/GraphicsInstanceDesc.h>
#include <string>
#include <vector>

namespace Portakal
{
	struct RUNTIME_API VulkanInstanceDesc : public GraphicsInstanceDesc
	{
		Array<String> Extensions;
		Array<String> Layers;
		String ApplicationName;
		UInt32 ApplicationVersion;
		String EngineName;
		UInt32 APIVersion;
	};
}
