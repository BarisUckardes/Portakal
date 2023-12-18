#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Texture/TextureDesc.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryObject.h>

namespace Portakal
{
	class RUNTIME_API Texture : public GraphicsMemoryObject
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
		FORCEINLINE bool IsSwapchain() const noexcept
		{
			return mSwapchain;
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
		const byte mMipLevels;
		const byte mArrayLevels;
		const TextureSampleCount mSampleCount;
		const bool mSwapchain;
	};
}
