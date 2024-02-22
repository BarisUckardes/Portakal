#include "CommandPool.h"

namespace Portakal
{
    CommandPool::CommandPool(const CommandPoolDesc& desc,GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice), mType(desc.Type)
    {

    }
}
