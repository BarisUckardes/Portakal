#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{

	/**
	 * @enum GraphicsBufferUsage
	 * 
	 * @brief It is used to specify the usage of a buffer.
	 * 
	 * @throw Have no clue about the storage, transfer source and transfer destination. Transfers 
	 * are giving a basic idea by the name but don't know what storage is.
	 */
	enum class GraphicsBufferUsage : byte
	{
		Unknown = 0,
		VertexBuffer = 1,
		IndexBuffer = 2,
		ConstantBuffer = 4,
		Storage = 8,
		TransferSource = 16,
		TransferDestination = 32
	};

	GENERATE_FLAGS(GraphicsBufferUsage, byte)
}
