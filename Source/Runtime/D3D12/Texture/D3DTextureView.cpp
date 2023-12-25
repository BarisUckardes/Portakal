#include "D3DTextureView.h"

#include <Runtime/D3D12/Device/D3DDevice.h>
#include <Runtime/D3D12/Texture/D3DTexture.h>

namespace Portakal
{
	D3DTextureView::D3DTextureView(const TextureViewDesc& desc, D3DDevice* pDevice) : TextureView(desc)
	{
		D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
		srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
		srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
		srvDesc.Texture2D.MipLevels = desc.MipLevel;
		srvDesc.Texture2D.MostDetailedMip = 0;

		D3D12_CPU_DESCRIPTOR_HANDLE cpuHandle = mShaderResourceView->GetCPUDescriptorHandleForHeapStart();
		pDevice->GetDevice()->CreateShaderResourceView(((D3DTexture*)desc.pTexture.GetHeap())->GetTexture().Get(), &srvDesc, cpuHandle);

	}
	D3DTextureView::D3DTextureView(const TextureViewDesc& desc, D3DDevice* pDevice, ComPtr<ID3D12DescriptorHeap> pRTVHeap) : TextureView(desc)
	{
		mShaderResourceView = pRTVHeap;
	}
	void D3DTextureView::OnShutdown()
	{
	}
}