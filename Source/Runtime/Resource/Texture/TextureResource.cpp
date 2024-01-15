#include "TextureResource.h"
#include <Runtime/Graphics/Command/CommandList.h>
#include <Runtime/Graphics/Texture/TextureUtils.h>
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
    TextureResource::TextureResource(const SharedHeap<GraphicsDevice>& pDevice)
    {
        mDevice = pDevice;
        CreateInternalResources();
    }
    TextureResource::TextureResource()
    {
        mDevice = GraphicsAPI::GetDefaultDevice();
        CreateInternalResources();
    }
    void TextureResource::AllocateTexture(const TextureDesc& desc, const SharedHeap<GraphicsMemoryHeap>& pHostHeap, const Bool8 bAllocateStagebuffersUpfront,const Bool8 bCreateViewsUpfront)
    {
        //Validate if shutdown
        if (IsShutdown())
        {
            DEV_LOG("TextureResource", "Failed to allocate texture due to the Object is shutdown!");
            return;
        }

        //Check graphics device
        if (mDevice.IsShutdown())
            return;

        //Clear former texture setup
        Clear();

        //Create texture
        mTexture = mDevice->CreateTexture(desc);

        //Create mip data
        for (UInt32 arrayIndex = 0; arrayIndex < desc.ArrayLevels; arrayIndex++)
        {
            Array<MipData> mips;
            for (UInt32 mipIndex = 0; mipIndex < desc.MipLevels; mipIndex++)
            {
                MipData mipData = {};

                //Create views upfront if requested
                if (bCreateViewsUpfront)
                {
                    TextureViewDesc viewDesc = {};
                    viewDesc.pTexture = mTexture;
                    viewDesc.MipLevel = mipIndex;
                    viewDesc.ArrayLevel = arrayIndex;
                    mipData.pView = mDevice->CreateTextureView(viewDesc);
                }

                //Create staging buffers if requested
                if (bAllocateStagebuffersUpfront)
                {
                    GraphicsBufferDesc bufferDesc = {};
                    bufferDesc.pHeap = pHostHeap;
                    bufferDesc.SubItemCount = 1;
                    bufferDesc.SubItemSizeInBytes = TextureUtils::GetFormatSize(desc.Format)*desc.Size.X*desc.Size.Y*desc.Size.Z;
                    bufferDesc.Usage = GraphicsBufferUsage::TransferSource;
                    mipData.pStageBuffer = mDevice->CreateBuffer(bufferDesc);
                }

                mips.Add(mipData);
            }

            mData.Add(mips);
        }

        //Set properties
        mDesc = desc;
        mHostHeap = pHostHeap;
    }
    SharedHeap<TextureView> TextureResource::CreateView(const Byte mipLevel, const Byte arrayLevel)
    {
        //Validate if shutdown
        if (IsShutdown())
        {
            DEV_LOG("TextureResource", "Failed to allocate texture due to the Object is shutdown!");
            return nullptr;
        }

        //Check graphics device
        if (mDevice.IsShutdown())
            return nullptr;

        //Check if array and mips are supported
        if (mipLevel >= mDesc.MipLevels || arrayLevel >= mDesc.ArrayLevels)
        {
            DEV_LOG("TextureResource", "Invalid mip/array levels");
            return nullptr;
        }

        //Get mip data
        MipData& data = mData[arrayLevel][mipLevel];
        if (data.pView.IsShutdown())
            return nullptr;

        //Create view
        TextureViewDesc desc = {};
        desc.ArrayLevel = arrayLevel;
        desc.MipLevel = mipLevel;
        desc.pTexture = mTexture;
        data.pView = mDevice->CreateTextureView(desc);

        return data.pView;
    }
    SharedHeap<TextureView> TextureResource::GetView(const Byte mipLevel, const Byte arrayLevel)
    {
        //Validate if shutdown
        if (IsShutdown())
        {
            DEV_LOG("TextureResource", "Failed to allocate texture due to the Object is shutdown!");
            return nullptr;
        }

        //Check graphics device
        if (mDevice.IsShutdown())
            return nullptr;

        //Check if array and mips are supported
        if (mipLevel >= mDesc.MipLevels || arrayLevel >= mDesc.ArrayLevels)
        {
            DEV_LOG("TextureResource", "Invalid mip/array levels");
            return nullptr;
        }

        //Get mip
        MipData& mip = mData[arrayLevel][mipLevel];
        if (mip.pView.IsShutdown())
        {
            TextureViewDesc desc = {};
            desc.ArrayLevel = arrayLevel;
            desc.MipLevel = mipLevel;
            desc.pTexture = mTexture.GetHeap();
            mip.pView = mDevice->CreateTextureView(desc);
        }
        return mip.pView;
    }
    void TextureResource::Update(const MemoryView& memory, const Vector3US offset, const TextureMemoryLayout inputMemoryLayout, const GraphicsMemoryAccessFlags inputAccessFlags, const PipelineStageFlags inputPipelineFlags, const GraphicsQueueType inputQueueType, const Byte mipLevel, const Byte arrayLevel)
    {
        //Validate if shutdown
        if (IsShutdown())
        {
            DEV_LOG("TextureResource", "Failed to allocate texture due to the Object is shutdown!");
            return;
        }

        //Check graphics device
        if (mDevice.IsShutdown())
            return;

        //Check if array and mips are supported
        if (mipLevel >= mDesc.MipLevels || arrayLevel >= mDesc.ArrayLevels)
        {
            DEV_LOG("TextureResource", "Invalid mip/array levels");
            return;
        }

        //Get mipdata
        MipData& mipData = mData[arrayLevel][mipLevel];

        //Check if it's required to create stage buffer
        if (mipData.pStageBuffer.IsShutdown())
        {
            GraphicsBufferDesc desc = {};
            desc.SubItemCount = 1;
            desc.SubItemSizeInBytes = 1;
            desc.Usage = GraphicsBufferUsage::TransferSource;
            desc.pHeap = mHostHeap;

            mipData.pStageBuffer = mDevice->CreateBuffer(desc);
        }

        //Update host buffer
        GraphicsBufferHostUpdateDesc hostBufferUpdateDesc = {};
        hostBufferUpdateDesc.OffsetInBytes = 0;
        hostBufferUpdateDesc.View = memory;
        mDevice->UpdateHostBuffer(mipData.pStageBuffer.GetHeap(), hostBufferUpdateDesc);

        //Begin cmd buffer
        mCmdList->BeginRecording();

        //Translate texture layout to transfer dest
        CommandListTextureMemoryBarrierDesc preBarrierDesc = {};
        preBarrierDesc.SourceQueue = inputQueueType;
        preBarrierDesc.SourceAccessFlags = inputAccessFlags;
        preBarrierDesc.SourceStageFlags = inputPipelineFlags;
        preBarrierDesc.SourceLayout = inputMemoryLayout;
        preBarrierDesc.AspectFlags = TextureAspectFlags::Color;

        preBarrierDesc.DestinationQueue = GraphicsQueueType::Graphics;
        preBarrierDesc.DestinationAccessFlags = GraphicsMemoryAccessFlags::TransferWrite;
        preBarrierDesc.DestinationStageFlags = PipelineStageFlags::Transfer;
        preBarrierDesc.DestinationLayout = TextureMemoryLayout::TransferDestination;
        preBarrierDesc.AspectFlags = TextureAspectFlags::Color;
        mCmdList->SetTextureMemoryBarrier(mTexture.GetHeap(), preBarrierDesc);

        //Copy host buffer to texture
        BufferTextureCopyDesc bufferTextureCopyDesc = {};
        bufferTextureCopyDesc.BufferOffsetInBytes = 0;
        bufferTextureCopyDesc.TextureArrayIndex = arrayLevel;
        bufferTextureCopyDesc.TextureMipIndex = mipLevel;
        bufferTextureCopyDesc.TextureOffsetInPixels = offset;
        bufferTextureCopyDesc.TextureSize = mTexture->GetSize();
        mCmdList->CopyBufferToTexture(mipData.pStageBuffer.GetHeap(), mTexture.GetHeap(), bufferTextureCopyDesc);
        
        //Translate texture back to it's input layout
        CommandListTextureMemoryBarrierDesc postBarrierDesc = {};
        postBarrierDesc.SourceQueue = GraphicsQueueType::Graphics;
        postBarrierDesc.SourceAccessFlags = GraphicsMemoryAccessFlags::TransferWrite;
        postBarrierDesc.SourceStageFlags = PipelineStageFlags::Transfer;
        postBarrierDesc.SourceLayout = TextureMemoryLayout::TransferDestination;
        postBarrierDesc.AspectFlags = TextureAspectFlags::Color;

        postBarrierDesc.DestinationQueue = inputQueueType;
        postBarrierDesc.DestinationAccessFlags = GraphicsMemoryAccessFlags::ShaderRead;
        postBarrierDesc.DestinationStageFlags = PipelineStageFlags::FragmentShader;
        postBarrierDesc.DestinationLayout = TextureMemoryLayout::ShaderReadOnly;
        postBarrierDesc.AspectFlags = TextureAspectFlags::Color;
        mCmdList->SetTextureMemoryBarrier(mTexture.GetHeap(), postBarrierDesc);

        //End recording
        mCmdList->EndRecording();

        //Submit command list
        mDevice->SubmitCommandLists(mCmdList.GetHeapAddress(),1,GraphicsQueueType::Graphics,mFence.GetHeap());

        //Wait for commands to finish
        mDevice->WaitFences(mFence.GetHeapAddress(), 1);
    }
    void TextureResource::CreateInternalResources()
    {
        CommandPoolDesc cmdPoolDesc = {};
        cmdPoolDesc.Type = CommandPoolType::Graphics;
        mCmdPool = mDevice->CreateCommandPool(cmdPoolDesc);

        CommandListDesc cmdListDesc = {};
        cmdListDesc.pPool = mCmdPool;
        mCmdList = mDevice->CreateCommandList(cmdListDesc);

        mFence = mDevice->CreateFence();
    }
    void TextureResource::Clear()
    {
        //Clear views
        for (const Array<MipData>& arrayLevel : mData)
        {
            for (MipData& mipData : arrayLevel)
            {
                mipData.pStageBuffer.Shutdown();
                mipData.pView.Shutdown();
            }
        }
        mData.Clear();

        //Destroy texture
        mTexture.Shutdown();
    }
    void TextureResource::OnShutdown()
    {
        Clear();
    }
}
