#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Descriptor/DescriptorSetDesc.h>

namespace Portakal
{

    /**
     * @class DescriptorSet
     * 
     * @brief Very similar mechanism with CommandList, but this time it's for resource tables. 
     * It is a wrapper for the resource table pool. We use this to keep track of the resource table 
     * pool and the resource table layouts. Which means that we can keep track of the buffers and 
     * shaders according to the resource table. It is the equivalent of the DescriptorSet in Vulkan and Dx12.
     * 
     * @throw Descriptor Sets are used to represent and manage resources that shaders 
     * (such as vertex or pixel shaders) in a graphics pipeline can access. 
     */
    class RUNTIME_API DescriptorSet : public GraphicsDeviceObject
    {
    public:
        DescriptorSet(const DescriptorSetDesc& desc,GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice), mOwnerPool(desc.pOwnerPool), mTargetLayout(desc.pTargetLayout)
        {}
        ~DescriptorSet()
        {}

        const DescriptorSetPool* GetOwnerPool() const
        {
            return mOwnerPool;
        }
        const DescriptorSetLayout* GetTargetLayout() const
        {
            return mTargetLayout;
        }

        FORCEINLINE virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
        {
            return GraphicsDeviceObjectType::DescriptorSet;
        }

    private:
        const DescriptorSetPool* mOwnerPool;
        const DescriptorSetLayout* mTargetLayout;
    };
}
