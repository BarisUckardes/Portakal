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
		D3DTextureView(const TextureViewDesc& desc, D3DDevice* pDevice, ComPtr<ID3D12DescriptorHeap> pRTVHeap);
		~D3DTextureView() override = default;

		FORCEINLINE ComPtr<ID3D12DescriptorHeap> GetShaderResourceView() const { return mShaderResourceView; }

		virtual void OnShutdown() override;
	private:
		ComPtr<ID3D12DescriptorHeap> mShaderResourceView;
	};
}