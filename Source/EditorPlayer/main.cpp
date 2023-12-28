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
#include <Runtime/Window/WindowModule.h>
#include <Runtime/Reflection/ReflectionModule.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <RUntime/World/Component.h>
#include <Runtime/World/Entity.h>
#include <Runtime/World/Scene.h>
#include <Runtime/World/SceneAspect.h>
#include <EditorPlayer/EditorPlayerApplication.h>
#include <EditorPlayer/EditorPlayerWindowModule.h>
#include <EditorPlayer/EditorPlayerGDeviceModule.h>

namespace Portakal
{
	void Run(const Array<String>& cmdArguments)
	{
		//Initialize platform
		Platform::InitializePlatformDependencies();

		//Create application
		EditorPlayerApplication* pApplication = new EditorPlayerApplication();

		//Add modules
		pApplication->RegisterModule<ReflectionModule>(0);
		pApplication->RegisterModule<WindowModule>(1);
		pApplication->RegisterModule<EditorPlayerWindowModule>(2);
		//pApplication->RegisterModule<EditorPlayerGDeviceModule>(3);

		//Run
		pApplication->Run();
	}
}
	
int main(const unsigned int argumentCount, const char** ppArguments)
{
	Portakal::Array<Portakal::String> cmdArguments;
	for (Portakal::uint32 i = 0; i < argumentCount; i++)
		cmdArguments.Add(ppArguments[i]);

	Portakal::Run(cmdArguments);
	return 0;
}