#include "GraphicsQueue.h"

namespace Portakal
{
	GraphicsQueue::GraphicsQueue(const GraphicsQueueDesc& desc,GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice), mType(desc.Type)
	{

	}
}