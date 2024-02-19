#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class GraphicsBufferUsage : Byte
	{
		Unknown = 0,
		VertexBuffer = 1,
		IndexBuffer = 2,
		ConstantBuffer = 4,
		Storage = 8,
		TransferSource = 16,
		TransferDestination = 32
	};

	GENERATE_FLAGS(GraphicsBufferUsage, Byte)
}
