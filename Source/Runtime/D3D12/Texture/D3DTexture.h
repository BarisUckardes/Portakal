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
		~D3DTexture() = default;

		ComPtr<ID3D12Resource> GetTextureResource() const { return mTexture; }

	private:
		const Bool8 mSwapchain;
		ComPtr<ID3D12Resource> mTexture;
	};
}
