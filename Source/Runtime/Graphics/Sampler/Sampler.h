#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Sampler/SamplerDesc.h>

namespace Portakal
{
	class RUNTIME_API Sampler : public GraphicsDeviceObject
	{
	public:
		~Sampler();

        FORCEINLINE const SamplerFiltering GetMinFilter() const
        {
            return mMinFilter;
        }
        FORCEINLINE const SamplerFiltering GetMagFilter() const
        {
            return mMagFilter;
        }
        FORCEINLINE const SamplerMapMode GetMipmapMode() const
        {
            return mMipmapMode;
        }
        FORCEINLINE const SamplerAddressMode GetAddressModeU() const
        {
            return mAddressModeU;
        }
        FORCEINLINE const SamplerAddressMode GetAddressModeV() const
        {
            return mAddressModeV;
        }
        FORCEINLINE const SamplerAddressMode GetAddressModeW() const
        {
            return mAddressModeW;
        }
        FORCEINLINE const Float32 GetMipLodBias() const
        {
            return mMipLodBias;
        }
        FORCEINLINE const Float32 GetMaxAnisotropy() const
        {
            return mMaxAnisotropy;
        }
        FORCEINLINE const bool IsComparisonEnabled() const
        {
            return mComparisonEnabled;
        }
        FORCEINLINE const CompareOperation GetCompareOperation() const
        {
            return mCompareOperation;
        }
        FORCEINLINE const Float32 GetMinLod() const
        {
            return mMinLod;
        }
        FORCEINLINE const Float32 GetMaxLod() const
        {
            return mMaxLod;
        }
        FORCEINLINE const SamplerBorderColor GetBorderColor() const
        {
            return mBorderColor;
        }

        FORCEINLINE virtual GraphicsDeviceObjectType GetObjectType() const noexcept override
        {
            return GraphicsDeviceObjectType::Sampler;
        }
	protected:
		Sampler(const SamplerDesc& desc, GraphicsDevice* pDevice);
	private:
        const SamplerFiltering mMinFilter;
        const SamplerFiltering mMagFilter;
        const SamplerMapMode mMipmapMode;
        const SamplerAddressMode mAddressModeU;
        const SamplerAddressMode mAddressModeV;
        const SamplerAddressMode mAddressModeW;
        const Float32 mMipLodBias;
        const Float32 mMaxAnisotropy;
        const Bool8 mComparisonEnabled;
        const CompareOperation mCompareOperation;
        const Float32 mMinLod;
        const Float32 mMaxLod;
        const SamplerBorderColor mBorderColor;
	};
}
