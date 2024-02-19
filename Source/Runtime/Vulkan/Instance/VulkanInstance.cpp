#include "VulkanInstance.h"
#include <Runtime/Vulkan/Adapter/VulkanAdapter.h>

#ifdef Portakal_PLATFORM_WINDOWS
#include <Windows.h>
#include <vulkan_win32.h>
#endif
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Adapter/GraphicsAdapterDesc.h>

namespace Portakal
{
#ifdef Portakal_DEBUG
    PFN_vkCreateDebugUtilsMessengerEXT debugMessengerCreateProc = NULL;
    PFN_vkDestroyDebugUtilsMessengerEXT debugMessengerDestroyProc = NULL;
    static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallBack(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData)
    {

        DEV_LOG("VulkanDebug", "%s", pCallbackData->pMessage);
        return VK_FALSE;
    }
#endif

    VulkanInstance::VulkanInstance(const VulkanInstanceDesc* pDesc) : GraphicsInstance(pDesc),mInstance(VK_NULL_HANDLE),mDebugMessenger(VK_NULL_HANDLE)
    {
        //Get requested extensions
        std::vector<String> requestedExtensions;
        for (const String& extension : pDesc->Extensions)
            requestedExtensions.push_back(extension);

        //Get supported extension count
        UInt32 extensionCount = 0;
        DEV_ASSERT(vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr) == VK_SUCCESS, "VulkanInstance", "Failed to get instance extension count");
        DEV_ASSERT(extensionCount > 0, "VulkanInstance", "No extension found!");

        //Get supported extension
        std::vector<VkExtensionProperties> supportedExtensions(extensionCount);
        DEV_ASSERT(vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, supportedExtensions.data()) == VK_SUCCESS, "VulkanInstance", "Failed to get instance extensions");

#ifdef Portakal_DEBUG
        requestedExtensions.push_back({ VK_EXT_DEBUG_REPORT_EXTENSION_NAME ,false });
        requestedExtensions.push_back({ VK_EXT_DEBUG_UTILS_EXTENSION_NAME ,false });
#endif

        //Get the supported requested extension
        std::vector<const char*> extensions;
        for (UInt32 instanceExtensionIndex = 0; instanceExtensionIndex < requestedExtensions.size(); instanceExtensionIndex++)
        {
            const String& entry = requestedExtensions[instanceExtensionIndex];

            //Check if properties contains this extension
            bool bExtensionSupported = false;
            for (UInt32 supportedInstanceExtensionIndex = 0; supportedInstanceExtensionIndex < extensionCount; supportedInstanceExtensionIndex++)
            {
                const VkExtensionProperties& supportedInstanceExtensionProperty = supportedExtensions[supportedInstanceExtensionIndex];

                if (strcmp(*entry, supportedInstanceExtensionProperty.extensionName) == 0)
                {
                    extensions.push_back(*entry);
                    break;
                }
            }
        }

        //Get requested layers
        std::vector<String> requestedLayers;
        for (const String& layer : pDesc->Layers)
            requestedLayers.push_back(layer);

#ifdef Portakal_DEBUG
        requestedLayers.push_back("VK_LAYER_KHRONOS_validation");
#endif

        //Get supported layer count
        UInt32 layerCount = 0;
        DEV_ASSERT(vkEnumerateInstanceLayerProperties(&layerCount, nullptr) == VK_SUCCESS, "VulkanInstance", "Failed to get layer count");
        DEV_ASSERT(layerCount > 0, "VulkanInstance", "No layers found");

        std::vector<VkLayerProperties> supportedLayers(layerCount);
        DEV_ASSERT(vkEnumerateInstanceLayerProperties(&layerCount, supportedLayers.data()) == VK_SUCCESS, "VulkanInstance", "Failed to get layers");

        //Get supported layers
       Array<const char*> layers;
        for (const String& layerString : requestedLayers)
        {
            for (const VkLayerProperties& layer : supportedLayers)
            {
                if (strcmp(layer.layerName, *layerString) == 0)
                {
                    layers.Add(*layerString);
                    break;
                }
            }
        }

        //Create instance
        VkApplicationInfo appInfo = {};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = *pDesc->ApplicationName;
        appInfo.applicationVersion = pDesc->ApplicationVersion;
        appInfo.pEngineName = *pDesc->EngineName;
        appInfo.apiVersion = pDesc->APIVersion;

        VkInstanceCreateInfo instanceInfo = {};
        instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        instanceInfo.pApplicationInfo = &appInfo;
        instanceInfo.enabledExtensionCount = extensions.size();
        instanceInfo.ppEnabledExtensionNames = extensions.data();
        instanceInfo.enabledLayerCount = layers.GetSize();
        instanceInfo.ppEnabledLayerNames = layers.GetData();
        instanceInfo.pNext = nullptr;

        DEV_ASSERT(vkCreateInstance(&instanceInfo, nullptr, &mInstance) == VK_SUCCESS, "VulkanInstance", "Failed to create instance");

#ifdef Portakal_DEBUG
        //Get debug proc addresses
        debugMessengerCreateProc = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(mInstance, "vkCreateDebugUtilsMessengerEXT");
        debugMessengerDestroyProc = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(mInstance, "vkDestroyDebugUtilsMessengerEXT");

        DEV_ASSERT(debugMessengerCreateProc != nullptr, "VulkanInstance", "Failed to get vkCreateDebugUtilsMessengerEXT method!");
        DEV_ASSERT(debugMessengerDestroyProc != nullptr, "VulkanInstance", "Failed to get vkDestroyDebugUtilsMessengerEXT method!");

        //Create debug messenger
        VkDebugUtilsMessengerCreateInfoEXT debugMessengerInfo = {};
        debugMessengerInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
        debugMessengerInfo.messageSeverity =VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        debugMessengerInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
        debugMessengerInfo.pfnUserCallback = DebugCallBack;
        debugMessengerInfo.pUserData = nullptr;
        DEV_ASSERT(debugMessengerCreateProc(mInstance, &debugMessengerInfo, nullptr, &mDebugMessenger) == VK_SUCCESS, "VulkanInstance", "Failed to create VkDebugUtilsMessengerEXT");
#endif

        //Get physical device count
        UInt32 physicalDeviceCount = 0;
        DEV_ASSERT(vkEnumeratePhysicalDevices(mInstance, &physicalDeviceCount, nullptr) == VK_SUCCESS, "VulkanInstance", "Failed to get physical device count");
        DEV_ASSERT(physicalDeviceCount > 0, "VulkanInstance", "No physical devices found!");

        std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
        DEV_ASSERT(vkEnumeratePhysicalDevices(mInstance, &physicalDeviceCount, physicalDevices.data()) == VK_SUCCESS, "VulkanInstance", "Failed to get physical devices");

        //Create adapters
        Array<SharedHeap<GraphicsAdapter>> adapters;
        for (const VkPhysicalDevice device : physicalDevices)
        {
            VkPhysicalDeviceMemoryProperties memoryProperties = {};
            vkGetPhysicalDeviceMemoryProperties(device, &memoryProperties);

            VkPhysicalDeviceProperties deviceProperties = {};
            vkGetPhysicalDeviceProperties(device, &deviceProperties);

            GraphicsAdapterDesc adapterDesc = {};
            adapterDesc.ProductName = deviceProperties.deviceName;
            adapterDesc.VendorName = "N/A";
            adapterDesc.ImageWidth = deviceProperties.limits.maxImageDimension1D;
            adapterDesc.ImageHeight = deviceProperties.limits.maxImageDimension2D;
            adapterDesc.ImageDepth = deviceProperties.limits.maxImageDimension3D;
            adapterDesc.pInstance = this;
            adapters.Add(new VulkanAdapter(device,adapterDesc));
        }
        SetAdapters(adapters);
    }
    VulkanInstance::~VulkanInstance()
    {

    }
}