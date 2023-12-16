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
			mVRam(desc.VRam),mOwnerInstance(desc.pInstance)
		{

		}
		~GraphicsAdapter() = default;

		FORCEINLINE String GetProductName() const noexcept { return mProductName; }
		FORCEINLINE String GetVendorName() const noexcept { return mVendorName; }
		FORCEINLINE bool DoesSupportGeometryShader() const noexcept { return mSupportGeometryShader; }
		FORCEINLINE bool DoesSupportComputeShader() const noexcept { return mSupportComputeShader; }
		FORCEINLINE uint8 GetColorAttachmentCount() const noexcept { return mColorAttachmentCount; }
		FORCEINLINE uint32 GetShaderTextureCount() const noexcept { return mShaderTextureCount; }
		FORCEINLINE uint32 GetShaderSamplerCount() const noexcept { return mShaderSamplerCount; }
		FORCEINLINE uint32 GetShaderBufferCount() const noexcept { return mShaderBufferCount; }
		FORCEINLINE uint64 GetVRam() const noexcept { return mVRam; }
		FORCEINLINE SharedHeap<GraphicsInstance> GetOwnerInstance() const noexcept
		{
			return mOwnerInstance;
		}
		SharedHeap<GraphicsDevice> CreateDevice();
	protected:
		virtual GraphicsDevice* CreateDeviceCore() = 0;
	private:
		const String mProductName;
		const String mVendorName;
		const bool mSupportGeometryShader;
		bool mSupportComputeShader;
		const uint8 mColorAttachmentCount;
		const uint32 mShaderTextureCount;
		const uint32 mShaderSamplerCount;
		const uint32 mShaderBufferCount;
		const uint64 mVRam;
		SharedHeap<GraphicsInstance> mOwnerInstance;
		Array<SharedHeap<GraphicsDevice>> mDevices;
	};
}
