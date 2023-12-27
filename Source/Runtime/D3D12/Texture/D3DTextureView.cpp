#include "D3DTextureView.h"

#include <Runtime/D3D12/Device/D3DDevice.h>
#include <Runtime/D3D12/Texture/D3DTexture.h>

#include <Runtime/D3D12/Texture/D3DTextureUtils.h>

namespace Portakal
{
	D3DTextureView::D3DTextureView(const TextureViewDesc& desc, D3DDevice* pDevice) : TextureView(desc), mSwapchain(false)
	{
	}
	D3DTextureView::D3DTextureView(const TextureViewDesc& desc, D3DDevice* pDevice, ComPtr<ID3D12DescriptorHeap> pDescriptorHeap) : TextureView(desc), mSwapchain(true)
	{
		mDescriptorHeap = pDescriptorHeap;
	}
	void D3DTextureView::OnShutdown()
	{
	}
}