#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API TextureMemoryLayout : Byte
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