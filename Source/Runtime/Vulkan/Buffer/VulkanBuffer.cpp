#include "VulkanBuffer.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/Memory/VulkanMemoryHeap.h>
#include <Runtime/Vulkan/Buffer/VulkanBufferUtils.h>

namespace Portakal
{
    VulkanBuffer::VulkanBuffer(const GraphicsBufferDesc& desc, VulkanDevice* pDevice) : GraphicsBuffer(desc,pDevice),mLogicalDevice(pDevice->GetVkLogicalDevice()),mBuffer(VK_NULL_HANDLE)
    {
        //Get vk heap
        const VulkanMemoryHeap* pHeap = (const VulkanMemoryHeap*)desc.pHeap.GetHeap();

        //Create buffer
        VkBufferCreateInfo info = {};
        info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
        info.flags = VkBufferCreateFlags();
        info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
        info.usage = VulkanBufferUtils::GetUsages(desc.Usage);
        info.size = GetTotalSize();
        info.pNext = nullptr;

        DEV_ASSERT(vkCreateBuffer(mLogicalDevice, &info, nullptr, &mBuffer) == VK_SUCCESS, "VulkanBuffer", "Failed to create the buffer");

        //Get memory requirements
        VkMemoryRequirements requirements = {};
        vkGetBufferMemoryRequirements(mLogicalDevice, mBuffer, &requirements);

        //Get buffer memory
        const UInt64 memoryOffset = desc.pHeap->Allocate(requirements.size + requirements.alignment);
        const UInt64 alignedMemoryOffset = memoryOffset + (memoryOffset % requirements.alignment == 0 ? 0 : (requirements.alignment - (memoryOffset % requirements.alignment)));

        //Bind memory
        DEV_ASSERT(vkBindBufferMemory(mLogicalDevice, mBuffer, pHeap->GetVkMemory(), alignedMemoryOffset) == VK_SUCCESS,"VulkanBuffer","Failed to bind memory");

        mMemoryOffset = memoryOffset;
        mMemoryAlignedOffset = alignedMemoryOffset;
    }
    void VulkanBuffer::OnShutdown()
    {
        GraphicsBuffer::OnShutdown();
        vkDestroyBuffer(mLogicalDevice, mBuffer, nullptr);
    }
}
