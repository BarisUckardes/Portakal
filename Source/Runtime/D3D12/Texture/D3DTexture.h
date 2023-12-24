#pragma once

#include <Runtime/Graphics/Texture/Texture.h>
#include <Runtime/D3D12/D3DIncludes.h>

namespace Portakal
{
	class D3DDevice;
	class RUNTIME_API D3DTexture : public Texture
	{
	public:
		D3DTexture(const TextureDesc& desc, D3DDevice* pDevice);
		D3DTexture(const TextureDesc& desc, D3DDevice* pDevice, ComPtr<ID3D12Resource> pBuffer);
		~D3DTexture() override = default;

		ComPtr<ID3D12Resource> GetTexture() const { return mTexture; }
	private:
		const bool mSwapchain;
		ComPtr<ID3D12Resource> mTexture;
	};
}
