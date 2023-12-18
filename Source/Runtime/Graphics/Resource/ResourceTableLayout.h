#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Resource/ResourceTableLayoutDesc.h>

namespace Portakal
{
    /**
     * @class ResourceTableLayout
     * 
     * @brief This class will define the types of the resources that will be 
     * accessible for the shader.
     */
    class RUNTIME_API ResourceTableLayout : public GraphicsDeviceObject
    {
    public:
        ResourceTableLayout(const ResourceTableLayoutDesc& desc) : mEntries(desc.Entries)
        {

        }
        ~ResourceTableLayout()
        {

        }

        FORCEINLINE const Array<ResourceLayoutEntry>& GetEntries() const noexcept { return mEntries; }
        FORCEINLINE virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final { return GraphicsDeviceObjectType::ResourceTableLayout; }
    private:
        const Array<ResourceLayoutEntry> mEntries;
    };
}
