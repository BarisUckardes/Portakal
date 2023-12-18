#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Texture/TextureDesc.h>

namespace Portakal
{
	class RUNTIME_API Texture : public GraphicsDeviceObject
	{
	public:
		Texture(const TextureDesc& desc,const bool bSwapchain);
		~Texture() = default;

		FORCEINLINE TextureType GetType() const noexcept
		{
			return mType;
		}
		FORCEINLINE TextureUsage GetUsages() const noexcept
		{
			return mUsages;
		}
		FORCEINLINE TextureFormat GetFormat() const noexcept
		{
			return mFormat;
		}
		FORCEINLINE Vector3US GetSize() const noexcept
		{
			return mSize;
		}
		FORCEINLINE byte GetMipLevels() const noexcept
		{
			return mMipLevels;
		}
		FORCEINLINE byte GetArrayLevels() const noexcept
		{
			return mArrayLevels;
		}
		FORCEINLINE TextureSampleCount GetSampleCount() const noexcept
		{
			return mSampleCount;
		}
		FORCEINLINE SharedHeap<GraphicsMemoryHeap> GetHeap() const noexcept
		{
			return mHeap;
		}
		FORCEINLINE bool IsSwapchain() const noexcept
		{
			return mSwapchain;
		}

		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::Texture;
		}
	private:
		const TextureType mType;
		const TextureUsage mUsages;
		const TextureFormat mFormat;
		const Vector3US mSize;
		const byte mMipLevels;
		const byte mArrayLevels;
		const TextureSampleCount mSampleCount;
		const SharedHeap<GraphicsMemoryHeap> mHeap;
		const bool mSwapchain;
	};
}
