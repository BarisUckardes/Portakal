#pragma once
#include <Editor/GUI/ContextMenu/IContextMenuItem.h>
#include <Runtime/Graphics/Sampler/SamplerDesc.h>
#include "CreateSamplerContextMenuItem.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomContextMenuItem, "Create Sampler");
	PCLASS();
	class EDITOR_API CreateSamplerContextMenuItem : public IContextMenuItem
	{
	public:
		GENERATE_OBJECT;
	public:
		CreateSamplerContextMenuItem() :mOpen(false), mMinFilter(SamplerFiltering::Nearest), mMagFilter(SamplerFiltering::Nearest), 
			mMipmapMode(SamplerMapMode::Nearest), mAddressModeU(SamplerAddressMode::Repeat), mAddressModeV(SamplerAddressMode::Repeat), 
			mAddressModeW(SamplerAddressMode::Repeat), mMipLodBias(0.0f), mMaxAnisotropy(1.0f), 
			mComparisonEnabled(false), mCompareOperation(CompareOperation::Always), mMinLod(0.0f), mMaxLod(0.0f), 
			mBorderColor(SamplerBorderColor::TransparentBlack)
		{

		}
		~CreateSamplerContextMenuItem() = default;

		virtual bool OnAction(DomainFolder* pFolder) override;
		virtual bool OnTick(DomainFolder* pFolder) override;
		virtual void OnShutdown() override;
	private:
		String mName;
		bool mOpen;

		SamplerFiltering mMinFilter;
		SamplerFiltering mMagFilter;
		SamplerMapMode mMipmapMode;
		SamplerAddressMode mAddressModeU;
		SamplerAddressMode mAddressModeV;
		SamplerAddressMode mAddressModeW;
		Float32 mMipLodBias;
		Float32 mMaxAnisotropy;
		Bool8 mComparisonEnabled;
		CompareOperation mCompareOperation;
		Float32 mMinLod;
		Float32 mMaxLod;
		SamplerBorderColor mBorderColor;
	};
}


