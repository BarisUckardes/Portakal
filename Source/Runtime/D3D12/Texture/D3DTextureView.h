#pragma once

#include <Runtime/Graphics/Texture/TextureView.h>

#include <Runtime/D3D12/D3DIncludes.h>

namespace Portakal
{
	class D3DDevice;
	class RUNTIME_API D3DTextureView : public TextureView
	{
	public:
		D3DTextureView(const TextureViewDesc& desc, D3DDevice* pDevice);
		D3DTextureView(const TextureViewDesc& desc, D3DDevice* pDevice, ComPtr<ID3D12DescriptorHeap> pDescriptorHeap);
		~D3DTextureView() = default;

		virtual void OnShutdown() override;
	private:
		const Bool8 mSwapchain;
		ComPtr<ID3D12DescriptorHeap> mDescriptorHeap;
	};
}