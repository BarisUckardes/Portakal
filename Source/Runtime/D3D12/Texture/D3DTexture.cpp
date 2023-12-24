#include "D3DTexture.h"

#include <Runtime/D3D12/Device/D3DDevice.h>
#include <Runtime/D3D12/Texture/D3DTextureUtils.h>

namespace Portakal
{
	D3DTexture::D3DTexture(const TextureDesc& desc, D3DDevice* pDevice) : Texture(desc, false), mSwapchain(false)
	{
		D3D12_RESOURCE_DESC resourceDesc = {};
		resourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
		resourceDesc.Alignment = 0;
		resourceDesc.Width = desc.Size.X;
		resourceDesc.Height = desc.Size.Y;
		resourceDesc.DepthOrArraySize = desc.ArrayLevels;
		resourceDesc.MipLevels = desc.MipLevels;
		resourceDesc.Format = D3DTextureUtils::GetD3DTextureFormat(desc.Format);
		resourceDesc.SampleDesc.Count = 1;
		resourceDesc.SampleDesc.Quality = 0;
		resourceDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
		resourceDesc.Flags = D3D12_RESOURCE_FLAG_NONE;

		D3D12_HEAP_PROPERTIES heapProperties = {};
		heapProperties.Type = D3D12_HEAP_TYPE_DEFAULT;
		heapProperties.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
		heapProperties.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
		heapProperties.CreationNodeMask = 1;
		heapProperties.VisibleNodeMask = 1;

		DEV_ASSERT(SUCCEEDED(pDevice->GetDevice()->CreateCommittedResource(&heapProperties, D3D12_HEAP_FLAG_NONE, &resourceDesc, D3D12_RESOURCE_STATE_COPY_DEST, 
				   nullptr, IID_PPV_ARGS(&mTexture))), "D3DTexture", "Failed to create D3DTexture");
	}
	D3DTexture::D3DTexture(const TextureDesc& desc, D3DDevice* pDevice, ComPtr<ID3D12Resource> pBuffer) : Texture(desc, true), mSwapchain(true)
	{
		mTexture = pBuffer;
	}
}