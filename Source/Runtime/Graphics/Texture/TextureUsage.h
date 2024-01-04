#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API TextureUsage : Byte
	{
		None = 0,
		Sampled = 1,
		ColorAttachment = 2,
		DepthStencilAttachment = 4,
		Storage = 8,
		TransferSource = 16,
		TransferDestination = 32
	};
	GENERATE_FLAGS(TextureUsage, Byte);
}
