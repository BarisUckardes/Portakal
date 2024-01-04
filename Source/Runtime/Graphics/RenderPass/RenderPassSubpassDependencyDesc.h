#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryAccessFlags.h>
#include <Runtime/Graphics/Pipeline/PipelineStageFlags.h>

namespace Portakal
{
	struct RUNTIME_API RenderPassSubpassDependencyDesc
	{
		Byte InputSubpass;
		GraphicsMemoryAccessFlags InputAccess;
		PipelineStageFlags InputStageFlags;

		Byte OutputSubpass;
		GraphicsMemoryAccessFlags OutputAccess;
		PipelineStageFlags OutputStageFlags;
	};
}
