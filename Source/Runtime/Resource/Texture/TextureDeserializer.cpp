#include "TextureDeserializer.h"
#include <Runtime/Resource/Texture/TextureResource.h>
#include <Runtime/Graphics/Texture/TextureLoader.h>
#include <Runtime/Graphics/GraphicsAPI.h>
namespace Portakal
{
	ResourceSubObject* TextureDeserializer::Deserialize(const MemoryView& view,const String& metaData)
	{
		//Get default device
		SharedHeap<GraphicsDevice> pDefaultDevice = GraphicsAPI::GetDefaultDevice();
		if (pDefaultDevice.IsShutdown())
			return nullptr;

		//Load the texture
		TextureLoadResult loadResult = {};
		if (!TextureLoader::LoadFromMemory(view, loadResult))
		{
			DEV_LOG("TextureDeserializer", "Failed to load from memory!");
			return nullptr;
		}
		const UInt64 totalSize = loadResult.Size.X * loadResult.Size.Y * 4;

		//Create dedicated memory heaps
		GraphicsMemoryHeapDesc deviceHeapDesc = {};
		deviceHeapDesc.SizeInBytes = totalSize*2;
		deviceHeapDesc.Type = GraphicsMemoryType::Device;
		SharedHeap<GraphicsMemoryHeap> deviceHeap = pDefaultDevice->CreateMemoryHeap(deviceHeapDesc);

		GraphicsMemoryHeapDesc hostHeapDesc = {};
		hostHeapDesc.SizeInBytes = totalSize*2;
		hostHeapDesc.Type = GraphicsMemoryType::Host;
		SharedHeap<GraphicsMemoryHeap> hostHeap = pDefaultDevice->CreateMemoryHeap(hostHeapDesc);

		//Create texture
		TextureResource* pTexture = new TextureResource();

		//Allocate texture
		TextureDesc textureDesc = {};
		textureDesc.Type = TextureType::Texture2D;
		textureDesc.Format = TextureFormat::R8_G8_B8_A8_UNorm;
		textureDesc.Usage = TextureUsage::Sampled | TextureUsage::TransferDestination;
		textureDesc.Size = { loadResult.Size.X,loadResult.Size.Y,1 };
		textureDesc.ArrayLevels = 1;
		textureDesc.MipLevels = 1;
		textureDesc.SampleCount = TextureSampleCount::SAMPLE_COUNT_1;
		textureDesc.pHeap = deviceHeap;
		pTexture->AllocateTexture(textureDesc, hostHeap, true, true);

		//Update texture data
		pTexture->Update(loadResult.pView,{0,0,0},TextureMemoryLayout::Unknown,GraphicsMemoryAccessFlags::TransferWrite,PipelineStageFlags::Transfer,GraphicsQueueType::Graphics,0,0);

		//Delete intermediate data
		delete loadResult.pView;
		loadResult.pView = nullptr;

		return pTexture;
	}
	ResourceSubObject* TextureDeserializer::DeserializeOptimized(const MemoryView& view,const String& metaData)
	{
		//Create texture
		TextureResource* pTexture = new TextureResource();

		//pTexture->AllocateTexture();

		//pTexture->UpdateTexture();

		return pTexture;
	}
}
