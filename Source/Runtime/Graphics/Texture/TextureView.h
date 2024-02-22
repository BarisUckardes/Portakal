#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Texture/TextureViewDesc.h>

namespace Portakal
{
	class RUNTIME_API TextureView : public GraphicsDeviceObject
	{
	public:
		TextureView(const TextureViewDesc& desc,GraphicsDevice* pDevice);
		~TextureView() = default;

		FORCEINLINE const Texture* GetTargetTexture() const noexcept
		{
			return mTargetTexture.GetHeap();
		}
		FORCEINLINE Byte GetMipLevels() const noexcept
		{
			return mMipLevel;
		}
		FORCEINLINE Byte GetArrayLevel() const noexcept
		{
			return mArrayLevel;
		}

		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::TextureView;
		}
	private:
		SharedHeap<Texture> mTargetTexture;
		Byte mMipLevel;
		Byte mArrayLevel;
	};
}
