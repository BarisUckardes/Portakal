#include "EditorTextureResource.h"
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Graphics/Texture/TextureLoader.h>
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
	EditorTextureResource::EditorTextureResource(const String& path) : EditorResource(path)
	{
		//Check path
		if (!PlatformFile::Exists(path))
		{
			DEV_LOG("EditorTextureResource", "Failed to find the specified file at %s", *path);
			return;
		}

		//Get default gd
		SharedHeap<GraphicsDevice> pDevice = GraphicsAPI::GetDefaultDevice();
		if (pDevice.IsShutdown())
		{
			DEV_LOG("EditorTextureResource", "No default graphics device found!");
			return;
		}

		//Load texture data
		TextureLoadResult result = {};
		if (!TextureLoader::LoadFromPath(path, result))
		{
			DEV_LOG("EditorTextureResource", "Failed to load the texture data");
			return;
		}

		//Create texture
		mTexture = new TextureResource(pDevice);

		//Set memory profile
		mTexture->SetMemoryProfile(GraphicsAPI::GetDefaultDeviceHeap(), GraphicsAPI::GetDefaultHostHeap());

		//Allocate texture
		TextureDesc desc = {};
		desc.Type = TextureType::Texture2D;
		desc.Format = TextureFormat::R8_G8_B8_A8_UNorm;
		desc.ArrayLevels = 1;
		desc.MipLevels = 1;
		desc.Size = { result.Size.X,result.Size.Y, 1};
		desc.SampleCount = TextureSampleCount::SAMPLE_COUNT_1;
		desc.Usage = TextureUsage::Sampled | TextureUsage::TransferDestination;
		desc.pHeap = nullptr;

		mTexture->AllocateTexture(desc, true, true);

		//Update texture data
		mTexture->Update(
			result.pView,
			{ 0,0,0 },
			TextureMemoryLayout::Unknown,
			GraphicsMemoryAccessFlags::ShaderRead,
			PipelineStageFlags::FragmentShader,
			GraphicsQueueType::Graphics,
			0, 0);

		//Clean up the raw texture data
		delete result.pView;
		result.pView = nullptr;
	}
	void EditorTextureResource::OnShutdown()
	{
		mTexture.Shutdown();
	}
}
