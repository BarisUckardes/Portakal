#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Descriptor/DescriptorSetPoolDesc.h>

namespace Portakal
{
    /**
     * @class DescriptorSetPool
     * 
     * @brief Descriptor pool or DescriptorSetPool is an object that manages memory for 
     * descriptor sets. It allows you to allocate descriptor sets from a pre-allocated 
     * pool of descriptors. Descriptor pools are created with a specified maximum number 
     * of each type of descriptor, and the Vulkan runtime manages the allocation and 
     * recycling of descriptor sets.
     */
    class RUNTIME_API DescriptorSetPool : public GraphicsDeviceObject
    {
    public:
        DescriptorSetPool(const DescriptorSetPoolDesc& desc,GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice), mEntries(desc.Entries), mMaxTables(desc.MaxTables)
        {

        }

        ~DescriptorSetPool()
        {

        }

        FORCEINLINE const Array<DescriptorSetPoolEntry>& GetEntries() const noexcept { return mEntries; }
        FORCEINLINE UInt32 GetMaxTables() const noexcept { return mMaxTables; }

        FORCEINLINE virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final { return GraphicsDeviceObjectType::DescriptorSetPool; }
    private:
        const Array<DescriptorSetPoolEntry> mEntries;
        const UInt32 mMaxTables;
    };
}
