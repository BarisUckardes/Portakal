#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Descriptor/DescriptorSetLayoutDesc.h>

namespace Portakal
{
    /**
     * @class DescriptorSetLayout
     * 
     * @brief This class will define the types of the resources that will be 
     * accessible for the shader.
     */
    class RUNTIME_API DescriptorSetLayout : public GraphicsDeviceObject
    {
    public:
        DescriptorSetLayout(const DescriptorSetLayoutDesc& desc,GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice),mEntries(desc.Entries)
        {

        }
        ~DescriptorSetLayout()
        {

        }

        FORCEINLINE const Array<DescriptorSetLayoutEntry>& GetEntries() const noexcept { return mEntries; }
        FORCEINLINE virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final { return GraphicsDeviceObjectType::DescriptorSetLayout; }
    private:
        const Array<DescriptorSetLayoutEntry> mEntries;
    };
}
