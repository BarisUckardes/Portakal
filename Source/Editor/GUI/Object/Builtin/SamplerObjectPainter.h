#pragma once
#include <Editor/GUI/Object/IObjectPainter.h>
#include <Runtime/Resource/Sampler/SamplerResource.h>
#include "SamplerObjectPainter.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomObjectPainter, typeof(Portakal::SamplerResource));
	PCLASS();
	class RUNTIME_API SamplerObjectPainter : public IObjectPainter
	{
		GENERATE_OBJECT;
	public:
		SamplerObjectPainter() = default;
		~SamplerObjectPainter() = default;

	private:
		// Inherited via IObjectPainter
		void OnInitialize() override;
		void OnPaint() override;

	private:
		SharedHeap<SamplerResource> mSamplerResource;
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

