#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <RUntime/Graphics/Texture/TextureViewDesc.h>

namespace Portakal
{
	class RUNTIME_API TextureView : public GraphicsDeviceObject
	{
	public:
		~TextureView();

		FORCEINLINE Byte GetArrayLevel() const noexcept
		{
			return mArrayLevel;
		}
		FORCEINLINE Byte GetMipLevel() const noexcept
		{
			return mMipLevel;
		}
		FORCEINLINE const SharedHeap<Texture> GetTargetTexture() const noexcept
		{
			return mTexture;
		}

		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::TextureView;
		}
	protected:
		TextureView(const TextureViewDesc& desc, GraphicsDevice* pDevice);

	private:
		const Byte mArrayLevel;
		const Byte mMipLevel;
		SharedHeap<Texture> mTexture;
	};
}
