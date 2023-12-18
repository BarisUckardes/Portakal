#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Resource/ResourceTablePoolDesc.h>

namespace Portakal
{
    /**
     * @class ResourceTablePool
     * 
     * @brief Descriptor pool or ResourceTablePool is an object that manages memory for 
     * descriptor sets. It allows you to allocate descriptor sets from a pre-allocated 
     * pool of descriptors. Descriptor pools are created with a specified maximum number 
     * of each type of descriptor, and the Vulkan runtime manages the allocation and 
     * recycling of descriptor sets.
     */
    class RUNTIME_API ResourceTablePool : public GraphicsDeviceObject
    {
    public:
        ResourceTablePool(const ResourceTablePoolDesc& desc) : mEntries(desc.Entries), mMaxTables(desc.MaxTables)
        {

        }

        ~ResourceTablePool()
        {

        }

        FORCEINLINE const Array<ResourceTablePoolEntry>& GetEntries() const noexcept { return mEntries; }
        FORCEINLINE uint32 GetMaxTables() const noexcept { return mMaxTables; }

        FORCEINLINE virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final { return GraphicsDeviceObjectType::ResourceTablePool; }
    private:
        const Array<ResourceTablePoolEntry> mEntries;
        const uint32 mMaxTables;
    };
}
