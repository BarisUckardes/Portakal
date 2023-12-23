#include <stdio.h>
#include <Runtime/Math/Math.h>
#include <Runtime/Math/Color4.h>
#include <Runtime/Math/Vector2.h>
#include <Runtime/Math/Vector3.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Object/Object.h>
#include <Runtime/Object/API.h>
#include <Runtime/Platform/PlatformClipboard.h>
#include <Runtime/Platform/PlatformConsole.h>
#include <Runtime/Platform/PlatformCriticalSection.h>
#include <Runtime/Platform/PlatformDialog.h>
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Platform/PlatformDirectory.h>
#include <Runtime/Platform/PlatformError.h>
#include <Runtime/Platform/PlatformGuid.h>
#include <Runtime/Platform/PlatformWindow.h>
#include <Runtime/Platform/Platform.h>
#include <Runtime/Graphics/Instance/GraphicsInstance.h>
#include <Runtime/Graphics/Adapter/GraphicsAdapter.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Swapchain/Swapchain.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryHeap.h>
#include <Runtime/Graphics/RenderPass/RenderPass.h>
#include <Runtime/Graphics/Buffer/GraphicsBuffer.h>
#include <Runtime/Graphics/Sampler/Sampler.h>
#include <Runtime/Graphics/Shader/Shader.h>
#include <Runtime/Graphics/Command/CommandList.h>
#include <Runtime/Graphics/Pipeline/Pipeline.h>
#include <Runtime/Graphics/Resource/ResourceTable.h>
#include <Runtime/Graphics/Resource/ResourceTableLayout.h>
#include <Runtime/Graphics/Resource/ResourceTablePool.h>
#include <Runtime/Platform/PlatformMonitor.h>
#include <Runtime/Platform/PlatformLibrary.h>
#include <Runtime/Platform/PlatformMessage.h>
#include <Runtime/Platform/PlatformMutex.h>
#include <Runtime/Platform/PlatformProcess.h>
#include <Runtime/Platform/PlatformRegistry.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Runtime/ReflectionManifest.h>
#include <RuntimeTest/VulkanApplication.h>
#include <Runtime/Window/WindowModule.h>
#include <RuntimeTest/VulkanWindowCreateModule.h>
#include <RuntimeTest/VulkanGraphicsModule.h>

namespace Portakal
{
	
	void RunVulkanTest()
	{
		//Initialize platform
		Platform::InitializePlatformDependencies();

		//Create application
		VulkanApplication* pApplication = new VulkanApplication();

		//Add modules
		pApplication->RegisterModule<WindowModule>(0);
		pApplication->RegisterModule<VulkanWindowCreateModule>(1);
		pApplication->RegisterModule<VulkanGraphicsModule>(2);

		//Run application
		pApplication->Run();
	}

#ifdef STBI_IMPLEMENTED
	#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#endif


	void RunD3DTest()
	{
		int width, height, channels;
		const byte* annen = stbi_load("C:/Users/mtunc/Pictures/Stickers/marvel-venom-with-protruding-tongue-sticker.png", &width, &height, &channels, 4);

		// Check size of image
		if (width != 981 || height != 1001)
		{
			DEV_LOG("D3DTest", "Image size is not correct");
			return;
		}
		else
		{
			DEV_LOG("D3DTest", "Image size is correct");
			return;
		}
	}
}

int main(const unsigned int argumentCount, const char** ppArguments)
{
	//Portakal::RunD3DTest()
	Portakal::RunVulkanTest();
	return 0;
}
