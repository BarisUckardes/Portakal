#include "VulkanBuffer.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/Memory/VulkanMemoryHeap.h>
#include <Runtime/Vulkan/Buffer/VulkanBufferUtils.h>

namespace Portakal
{
    VulkanBuffer::VulkanBuffer(const GraphicsBufferDesc& desc, VulkanDevice* pDevice) : GraphicsBuffer(desc),mLogicalDevice(pDevice->GetVkLogicalDevice()),mAlignedHandle(uint64_max),mHandle(uint64_max),mBuffer(VK_NULL_HANDLE)
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
        const MemoryHandle memoryHandle = desc.pHeap->Allocate(requirements.size + requirements.alignment);
        const MemoryHandle alignedHandle = memoryHandle + (memoryHandle == 0 ? 0 : (requirements.alignment - (memoryHandle % requirements.alignment)));

        //Bind memory
        DEV_ASSERT(vkBindBufferMemory(mLogicalDevice, mBuffer, pHeap->GetVkMemory(), memoryHandle) == VK_SUCCESS,"VulkanBuffer","Failed to bind memory");

        //Set aligned handle
        SetMemoryProperties(memoryHandle, alignedHandle);
    }
    void VulkanBuffer::OnShutdown()
    {
        GraphicsBuffer::OnShutdown();

        vkDestroyBuffer(mLogicalDevice, mBuffer, nullptr);
    }
}
