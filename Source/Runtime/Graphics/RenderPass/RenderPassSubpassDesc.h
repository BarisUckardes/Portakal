#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Pipeline/PipelineBindPoint.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	struct RUNTIME_API RenderPassSubpassDesc
	{
		PipelineBindPoint BindPoint;
		Array<Byte> Attachments;
		Array<Byte> Inputs;
		Array<Byte> MultisampleInputs;
		Array<Byte> PreserveAttachments;
		Byte DepthStencilInput;
	};
}
