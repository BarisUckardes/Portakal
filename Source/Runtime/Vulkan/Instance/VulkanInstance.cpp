#include "VulkanInstance.h"
#include <Runtime/Vulkan/Adapter/VulkanAdapter.h>

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Windows.h>
#include <vulkan_win32.h>
#endif
namespace Portakal
{
#ifdef PORTAKAL_DEBUG
    PFN_vkCreateDebugUtilsMessengerEXT debugMessengerCreateProc = NULL;
    PFN_vkDestroyDebugUtilsMessengerEXT debugMessengerDestroyProc = NULL;
    static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallBack(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData)
    {

        DEV_LOG("VkDebugMessenger", "%s", pCallbackData->pMessage);

        return VK_FALSE;
    }
#endif

    VulkanInstance::VulkanInstance(const GraphicsInstanceDesc& desc) : GraphicsInstance(desc)
    {
        struct ExtensionEntry
        {
            const char* pName;
            bool bSupported;
        };
        //Create instance extension array
        Array<ExtensionEntry> instanceRequestedExtensions;
        for (const String& extension : desc.VulkanExtensions)
            instanceRequestedExtensions.Add({ extension.GetCopyRaw(),false });

        //Get supported extension count
        uint32 supportedInstanceExtensionCount = 0;
        DEV_ASSERT(vkEnumerateInstanceExtensionProperties(nullptr, &supportedInstanceExtensionCount, nullptr) == VK_SUCCESS, "VulkanInstance", "Failed to enumarate the instance extensions!");
        DEV_ASSERT(supportedInstanceExtensionCount > 0, "VulkanInstance", "No instance extension found!");

        //Get supported extensions
        Array<VkExtensionProperties> supportedInstanceExtensions(supportedInstanceExtensionCount);
        DEV_ASSERT(vkEnumerateInstanceExtensionProperties(nullptr, &supportedInstanceExtensionCount, supportedInstanceExtensions.GetData()) == VK_SUCCESS, "VulkanInstance", "Failed to enumarate the instance extensions!");


        //Add required extensions
        instanceRequestedExtensions.Add({ VK_KHR_SURFACE_EXTENSION_NAME ,false});
        instanceRequestedExtensions.Add({ VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME ,false});
        //Get entries
#ifdef PORTAKAL_PLATFORM_WINDOWS
        instanceRequestedExtensions.Add({ VK_KHR_WIN32_SURFACE_EXTENSION_NAME ,false});
#endif

#ifdef PORTAKAL_DEBUG
        instanceRequestedExtensions.Add({ VK_EXT_DEBUG_REPORT_EXTENSION_NAME ,false});
        instanceRequestedExtensions.Add({ VK_EXT_DEBUG_UTILS_EXTENSION_NAME ,false});
#endif

        //Check if extension names are supported
        for (uint32 instanceExtensionIndex = 0; instanceExtensionIndex < instanceRequestedExtensions.GetSize(); instanceExtensionIndex++)
        {
            ExtensionEntry& entry = instanceRequestedExtensions[instanceExtensionIndex];

            //Check if properties contains this extension
            bool bExtensionSupported = false;
            for (uint32 supportedInstanceExtensionIndex = 0; supportedInstanceExtensionIndex < supportedInstanceExtensionCount; supportedInstanceExtensionIndex++)
            {
                const VkExtensionProperties& supportedInstanceExtensionProperty = supportedInstanceExtensions[supportedInstanceExtensionIndex];

                if (strcmp(entry.pName, supportedInstanceExtensionProperty.extensionName) == 0)
                {
                    bExtensionSupported = true;
                    break;
                }
            }

            entry.bSupported = bExtensionSupported;
        }

        //Filter extensions
        Array<const char*> selectedExtensions;
        Array<const char*> unsupportedExtensions;
        for (uint32 i = 0; i < instanceRequestedExtensions.GetSize(); i++)
        {
            ExtensionEntry& entry = instanceRequestedExtensions[i];
            if (entry.bSupported)
                selectedExtensions.Add(entry.pName);
            else
                unsupportedExtensions.Add(entry.pName);
        }

        //Get supported layers
        uint32 instanceSupportedLayerCount = 0;
        DEV_ASSERT(vkEnumerateInstanceLayerProperties(&instanceSupportedLayerCount, nullptr) == VK_SUCCESS, "VulkanInstance", "Failed to get the instance layer properties");
        DEV_ASSERT(instanceSupportedLayerCount > 0, "VulkanInstance", "No valid instance layer is supported!");

        Array<VkLayerProperties> instanceSupportedLayers(instanceSupportedLayerCount);
        DEV_ASSERT(vkEnumerateInstanceLayerProperties(&instanceSupportedLayerCount, instanceSupportedLayers.GetData()) == VK_SUCCESS, "VulkanInstance", "Failed to get the instance layer properties!");

#if PORTAKAL_DEBUG
        for (const VkLayerProperties& properties : instanceSupportedLayers)
            DEV_LOG("VulkanInstance", "Layer [%s] supported!", properties.layerName);
#endif

        //Get layers
        Array<const char*> instanceSelectedLayerNames = {};
#ifdef PORTAKAL_DEBUG
        instanceSelectedLayerNames.Add("VK_LAYER_KHRONOS_validation");
#endif

        //Create vk instance
        VkApplicationInfo appInfo = {};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Runtime";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "Runtime";
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo instanceInfo = {};
        instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        instanceInfo.pApplicationInfo = &appInfo;
        instanceInfo.enabledExtensionCount = selectedExtensions.GetSize();
        instanceInfo.ppEnabledExtensionNames = selectedExtensions.GetData();
        instanceInfo.enabledLayerCount = instanceSelectedLayerNames.GetSize();
        instanceInfo.ppEnabledLayerNames = instanceSelectedLayerNames.GetData();

        DEV_ASSERT(vkCreateInstance(&instanceInfo, nullptr, &mInstance) == VK_SUCCESS, "VulkanInstance", "Failed to create vulkan instance!");


#ifdef PORTAKAL_DEBUG
        //Get debug proc addresses
        debugMessengerCreateProc = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(mInstance, "vkCreateDebugUtilsMessengerEXT");
        debugMessengerDestroyProc = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(mInstance, "vkDestroyDebugUtilsMessengerEXT");

        DEV_ASSERT(debugMessengerCreateProc != nullptr, "VulkanInstance", "Failed to get vkCreateDebugUtilsMessengerEXT method!");
        DEV_ASSERT(debugMessengerDestroyProc != nullptr, "VulkanInstance", "Failed to get vkDestroyDebugUtilsMessengerEXT method!");

        //Create debug messenger
        VkDebugUtilsMessengerCreateInfoEXT debugMessengerInfo = {};
        debugMessengerInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
        debugMessengerInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        debugMessengerInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
        debugMessengerInfo.pfnUserCallback = DebugCallBack;
        debugMessengerInfo.pUserData = nullptr;
        DEV_ASSERT(debugMessengerCreateProc(mInstance, &debugMessengerInfo, nullptr, &mDebugMessenger) == VK_SUCCESS, "VulkanInstance", "Failed to create VkDebugUtilsMessengerEXT");

        for (const char* pName : selectedExtensions)
            DEV_LOG("VulkanInstance", "Extension [%s] is enabled", pName);
        for (const char* pName : unsupportedExtensions)
            DEV_LOG("VUlkanInstance", "Extension [%s] is not supported", pName);
        for (const char* pName : instanceSelectedLayerNames)
            DEV_LOG("VulkanInstance", "Layer [%s] is enabled", pName);
#endif


        //Get physical devices
        uint32 physicalDeviceCount = 0;
        DEV_ASSERT(vkEnumeratePhysicalDevices(mInstance, &physicalDeviceCount, 0) == VK_SUCCESS, "VulkanInstance", "Failed to enumarate physical devices!");
        DEV_ASSERT(physicalDeviceCount > 0, "VulkanInstance", "No physical gpus found!");

        Array<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
        DEV_ASSERT(vkEnumeratePhysicalDevices(mInstance, &physicalDeviceCount, physicalDevices.GetData()) == VK_SUCCESS, "VulkanInstance", "Failed to enumarate physical devices");

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
            adapterDesc.ImageDimensions = { deviceProperties.limits.maxImageDimension1D,deviceProperties.limits.maxImageDimension2D ,deviceProperties.limits.maxImageDimension3D };
            DEV_LOG("VulkanInstance", "Physical device [%s] found", *adapterDesc.ProductName);
            adapters.Add(new VulkanAdapter(adapterDesc, device));
        }

        //Set devices
        SetAdapters(adapters);

        DEV_LOG("VulkanInstance", "Initialized!");

    }
    void VulkanInstance::OnShutdown()
    {
        vkDestroyInstance(mInstance, nullptr);
        DEV_LOG("VulkanInstance", "Shutdown!");
    }
}
