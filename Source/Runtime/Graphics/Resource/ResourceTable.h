#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Resource/ResourceTableDesc.h>

namespace Portakal
{

    /**
     * @class ResourceTable
     * 
     * @brief Very similar mechanism with CommandList, but this time it's for resource tables. 
     * It is a wrapper for the resource table pool. We use this to keep track of the resource table 
     * pool and the resource table layouts. Which means that we can keep track of the buffers and 
     * shaders according to the resource table. It is the equivalent of the DescriptorSet in Vulkan and Dx12.
     * 
     * @throw Descriptor Sets are used to represent and manage resources that shaders 
     * (such as vertex or pixel shaders) in a graphics pipeline can access. 
     */
    class RUNTIME_API ResourceTable : public GraphicsDeviceObject
    {
    public:
        ResourceTable(const ResourceTableDesc& desc) : mOwnerPool(desc.pOwnerPool), mTargetLayout(desc.pTargetLayout)
        {}
        ~ResourceTable()
        {}

        const ResourceTablePool* GetOwnerPool() const
        {
            return mOwnerPool;
        }
        const ResourceTableLayout* GetTargetLayout() const
        {
            return mTargetLayout;
        }

        FORCEINLINE virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
        {
            return GraphicsDeviceObjectType::ResourceTable;
        }

    private:
        const ResourceTablePool* mOwnerPool;
        const ResourceTableLayout* mTargetLayout;
    };
}
