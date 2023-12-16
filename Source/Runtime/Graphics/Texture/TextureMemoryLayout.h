#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API TextureMemoryLayout : byte
	{
		Unknown,
		ColorAttachment,
		DepthStencilAttachment,
		ShaderReadOnly,
		TransferSource,
		TransferDestination,
		DepthReadOnly,
		StencilReadOnly,
		Present
	};
}