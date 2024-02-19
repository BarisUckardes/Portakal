#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Texture/TextureDesc.h>

namespace Portakal
{
	class RUNTIME_API Texture : public GraphicsDeviceObject
	{
	public:
		~Texture();

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
		FORCEINLINE UInt32 GetWidth() const noexcept
		{
			return mWidth;
		}
		FORCEINLINE UInt32 GetHeight() const noexcept
		{
			return mHeight;
		}
		FORCEINLINE UInt32 GetDepth() const noexcept
		{
			return mDepth;
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
		FORCEINLINE SharedHeap<GraphicsMemory> GetMemory() const noexcept
		{
			return mMemory;
		}
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept
		{
			return GraphicsDeviceObjectType::Texture;
		}
	protected:
		Texture(const TextureDesc& desc, GraphicsDevice* pDevice);

	private:
		const TextureType mType;
		const TextureUsage mUsages;
		const TextureFormat mFormat;
		const UInt32 mWidth;
		const UInt32 mHeight;
		const UInt32 mDepth;
		const Byte mMipLevels;
		const Byte mArrayLevels;
		const TextureSampleCount mSampleCount;
		SharedHeap<GraphicsMemory> mMemory;
	};
}
