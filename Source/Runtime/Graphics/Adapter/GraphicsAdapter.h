#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Adapter/GraphicsAdapterDesc.h>
#include <vector>
#include <Runtime/Graphics/Device/GraphicsDeviceDesc.h>

namespace Portakal
{
	class GraphicsDevice;
	class RUNTIME_API GraphicsAdapter
	{
	public:
		~GraphicsAdapter();


		FORCEINLINE String GetProductName() const noexcept { return mProductName; }
		FORCEINLINE String GetVendorName() const noexcept { return mVendorName; }
		FORCEINLINE bool DoesSupportGeometryShader() const noexcept { return mSupportGeometryShader; }
		FORCEINLINE bool DoesSupportComputeShader() const noexcept { return mSupportComputeShader; }
		FORCEINLINE UInt32 GetColorAttachmentCount() const noexcept { return mColorAttachmentCount; }
		FORCEINLINE UInt32 GetShaderTextureCount() const noexcept { return mShaderTextureCount; }
		FORCEINLINE UInt32 GetShaderSamplerCount() const noexcept { return mShaderSamplerCount; }
		FORCEINLINE UInt32 GetShaderBufferCount() const noexcept { return mShaderBufferCount; }
		FORCEINLINE UInt64 GetMemory() const noexcept { return mMemory; }
		FORCEINLINE UInt32 GetImageWidth() const noexcept
		{
			return mImageWidth;
		}
		FORCEINLINE UInt32 GetImageHeight() const noexcept
		{
			return mImageHeight;
		}
		FORCEINLINE UInt32 GetImageDepth() const noexcept
		{
			return mImageDepth;
		}
		FORCEINLINE GraphicsInstance* GetOwnerInstance() const noexcept
		{
			return mOwnerInstance;
		}

		GraphicsDevice* CreateDevice(const GraphicsDeviceDesc* pDesc);
	protected:
		GraphicsAdapter(const GraphicsAdapterDesc& desc);
	protected:
		virtual GraphicsDevice* CreateDeviceCore(const GraphicsDeviceDesc* pDesc) = 0;
	private:
		const String mProductName;
		const String mVendorName;
		const Bool8 mSupportGeometryShader;
		const Bool8 mSupportComputeShader;
		const Byte mColorAttachmentCount;
		const UInt32 mShaderTextureCount;
		const UInt32 mShaderSamplerCount;
		const UInt32 mShaderBufferCount;
		const UInt64 mMemory;
		const UInt32 mImageWidth;
		const UInt32 mImageHeight;
		const UInt32 mImageDepth;
		GraphicsInstance* mOwnerInstance;
		Array<GraphicsDevice*> mDevices;
	};
}
