#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Texture/TextureViewDesc.h>

namespace Portakal
{
	class RUNTIME_API TextureView : public GraphicsDeviceObject
	{
	public:
		TextureView(const TextureViewDesc& desc);
		~TextureView() = default;

		FORCEINLINE const Texture* GetTargetTexture() const noexcept
		{
			return mTargetTexture.GetHeap();
		}
		FORCEINLINE byte GetMipLevels() const noexcept
		{
			return mMipLevel;
		}
		FORCEINLINE byte GetArrayLevel() const noexcept
		{
			return mArrayLevel;
		}

		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::TextureView;
		}
	private:
		SharedHeap<Texture> mTargetTexture;
		byte mMipLevel;
		byte mArrayLevel;
	};
}
