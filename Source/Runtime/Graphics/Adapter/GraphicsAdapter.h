#pragma once
#include <Runtime/Object/Object.h>
#include <Runtime/Graphics/Adapter/GraphicsAdapterDesc.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	class RUNTIME_API GraphicsAdapter : public Object
	{
	public:
		GraphicsAdapter(const GraphicsAdapterDesc& desc) :
			mProductName(desc.ProductName),mVendorName(desc.VendorName),mSupportGeometryShader(desc.bSupportGeometryShader),mSupportComputeShader(desc.bSupportComputeShader),
			mColorAttachmentCount(desc.ColorAttachmentCount),mShaderTextureCount(desc.ShaderTextureCount),mShaderSamplerCount(desc.ShaderSamplerCount),mShaderBufferCount(desc.ShaderBufferCount),
			mVRam(desc.VRam),mImageDimensions(desc.ImageDimensions),mOwnerInstance(desc.pInstance)
		{
			SetName(desc.ProductName);
		}
		~GraphicsAdapter() = default;

		FORCEINLINE String GetProductName() const noexcept { return mProductName; }
		FORCEINLINE String GetVendorName() const noexcept { return mVendorName; }
		FORCEINLINE Bool8 DoesSupportGeometryShader() const noexcept { return mSupportGeometryShader; }
		FORCEINLINE Bool8 DoesSupportComputeShader() const noexcept { return mSupportComputeShader; }
		FORCEINLINE UInt8 GetColorAttachmentCount() const noexcept { return mColorAttachmentCount; }
		FORCEINLINE UInt32 GetShaderTextureCount() const noexcept { return mShaderTextureCount; }
		FORCEINLINE UInt32 GetShaderSamplerCount() const noexcept { return mShaderSamplerCount; }
		FORCEINLINE UInt32 GetShaderBufferCount() const noexcept { return mShaderBufferCount; }
		FORCEINLINE UInt64 GetVRam() const noexcept { return mVRam; }
		FORCEINLINE Vector3UI GetImageDimensions() const noexcept { return mImageDimensions; }
		FORCEINLINE GraphicsInstance* GetOwnerInstance() const noexcept
		{
			return mOwnerInstance;
		}
		SharedHeap<GraphicsDevice> CreateDevice();
	protected:
		virtual GraphicsDevice* CreateDeviceCore() = 0;
	private:

	private:
		const String mProductName;
		const String mVendorName;
		const Bool8 mSupportGeometryShader;
		Bool8 mSupportComputeShader;
		const UInt8 mColorAttachmentCount;
		const UInt32 mShaderTextureCount;
		const UInt32 mShaderSamplerCount;
		const UInt32 mShaderBufferCount;
		const UInt64 mVRam;
		const Vector3UI mImageDimensions;
		GraphicsInstance* mOwnerInstance;
		Array<SharedHeap<GraphicsDevice>> mDevices;
	};
}
