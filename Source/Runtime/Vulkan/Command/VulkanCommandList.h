#pragma once
#include <Runtime/Graphics/Command/CommandList.h>
#include <vulkan.h>

namespace Portakal
{
    class VulkanDevice;
    class RUNTIME_API VulkanCommandList : public CommandList
    {
    public:
        VulkanCommandList(const CommandListDesc& desc, VulkanDevice* pDevice);
        ~VulkanCommandList() = default;

        FORCEINLINE VkCommandBuffer GetVkCommandBuffer() const noexcept { return mCommandBuffer; }
    private:

        // Inherited via CommandList
        virtual void BeginRecordingCore() override;
        virtual void EndRecordingCore() override;

        // Inherited via CommandList
        virtual void SetVertexBufferCore(const GraphicsBuffer* pBuffer) override;
        virtual void SetIndexBufferCore(const GraphicsBuffer* pBuffer, const CommandListIndexBufferType type) override;

        // Inherited via CommandList
        virtual void DrawIndexedCore(const uint32 indexCount, const uint32 indexOffset, const uint32 vertexOffset, const uint32 instanceCount, const uint32 instanceOffset) override;
        virtual void DispatchComputeCore(const uint32 groupX, const uint32 groupY, const uint32 groupZ) override;

        // Inherited via CommandList
        virtual void SetPipelineCore(const Pipeline* pPipeline) override;


        void SetViewportsCore(const ViewportDesc* pViewports, const byte count) override;
        void SetScissorsCore(const ScissorDesc* pScissors, const byte count) override;

        // Inherited via CommandList
        virtual void CopyBufferToTextureCore(const GraphicsBuffer* pBuffer, const Texture* Texture, const BufferTextureCopyDesc& desc) override;
        virtual void CopyBufferToBufferCore(const GraphicsBuffer* pSourceBuffer, const GraphicsBuffer* pDestinationBuffer, const BufferBufferCopyDesc& desc) override;
        virtual void CopyTextureToTextureCore(const Texture* pSourceTexture, const Texture* pDestinationTexture, const TextureCopyDesc& desc) override;

        // Inherited via CommandList
        virtual void SetTextureMemoryBarrierCore(const Texture* Texture, const CommandListTextureMemoryBarrierDesc& desc) override;
        virtual void SetBufferMemoryBarrierCore(const GraphicsBuffer* pBuffer, const BufferBarrierDesc& desc) override;

        // Inherited via CommandList
        void CommitResourcesCore(const Array<ResourceTable*>& resources) override;
    private:
        byte GetQueueFamilyIndex(const GraphicsQueueType type);

        virtual void OnShutdown() override;
    private:
        VkCommandBuffer mCommandBuffer;
    };

}
