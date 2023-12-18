#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryAccessFlags.h>
#include <Runtime/Graphics/Pipeline/PipelineStageFlags.h>

namespace Portakal
{
	struct RUNTIME_API RenderPassSubpassDependencyDesc
	{
		byte InputSubpass;
		GraphicsMemoryAccessFlags InputAccess;
		PipelineStageFlags InputStageFlags;

		byte OutputSubpass;
		GraphicsMemoryAccessFlags OutputAccess;
		PipelineStageFlags OutputStageFlags;
	};
}
