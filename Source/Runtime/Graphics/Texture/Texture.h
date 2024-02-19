#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Texture/TextureDesc.h>

namespace Portakal
{
	class RUNTIME_API Texture : public GraphicsDeviceObject
	{
	public:
		Texture(const TextureDesc& desc,const Bool8 bSwapchain);
		~Texture() = default;

		FORCEINLINE TextureType GetTextureType() const noexcept
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
		FORCEINLINE Byte GetMipLevels() const noexcept
		{
			return mMipLevels;
		}
		FORCEINLINE Byte GetArrayLevels() const noexcept
		{
			return mArrayLevels;
		}
		FORCEINLINE TextureSampleCount GetSampleCount() const noexcept
		{
			return mSampleCount;
		}
		FORCEINLINE Bool8 IsSwapchain() const noexcept
		{
			return mSwapchain;
		}
		FORCEINLINE SharedHeap<GraphicsMemoryHeap> GetMemory() const noexcept
		{
			return mHeap;
		}

		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::Texture;
		}

		virtual void OnShutdown() override;
	private:
		const TextureType mType;
		const TextureUsage mUsages;
		const TextureFormat mFormat;
		const Vector3US mSize;
		const Byte mMipLevels;
		const Byte mArrayLevels;
		const TextureSampleCount mSampleCount;
		const Bool8 mSwapchain;
		SharedHeap<GraphicsMemoryHeap> mHeap;
	};
}
