#include "SamplerObjectPainter.h"
#include <Editor/ImGui/ImGuiAPI.h>
#include <imgui.h>
#include <Editor/ImGui/ImGuiUtils.h>

namespace Portakal
{
	void SamplerObjectPainter::OnInitialize()
	{
        // Get sampler and validate
        mSamplerResource = GetTargetObject().QueryAs<SamplerResource>();
        if (mSamplerResource.IsShutdown())
            return;

		mSampler = mSamplerResource->GetSampler();
		if (mSampler.IsShutdown())
			return;

        // Get sampler values
		mMinFilter = mSamplerResource->GetSampler()->GetMinFilter();
		mMagFilter = mSamplerResource->GetSampler()->GetMagFilter();
		mMipmapMode = mSamplerResource->GetSampler()->GetMipmapMode();
		mAddressModeU = mSamplerResource->GetSampler()->GetAddressModeU();
		mAddressModeV = mSamplerResource->GetSampler()->GetAddressModeV();
		mAddressModeW = mSamplerResource->GetSampler()->GetAddressModeW();
		mMipLodBias = mSamplerResource->GetSampler()->GetMipLodBias();
		mMaxAnisotropy = mSamplerResource->GetSampler()->GetMaxAnisotropy();
		mComparisonEnabled = mSamplerResource->GetSampler()->IsComparisonEnabled();
		mCompareOperation = mSamplerResource->GetSampler()->GetCompareOperation();
		mMinLod = mSamplerResource->GetSampler()->GetMinLod();
		mMaxLod = mSamplerResource->GetSampler()->GetMaxLod();
		mBorderColor = mSamplerResource->GetSampler()->GetBorderColor();
	}
	void SamplerObjectPainter::OnPaint()
	{
		// Validate
		if (mSampler.IsShutdown() || mSamplerResource.IsShutdown())
		{
			ImGui::Text("Invalid sampler");
			return;
		}

		// Sampler values
		mMinFilter = ImGuiUtils::EnumBox<SamplerFiltering>("MinFilter", mMinFilter);
		mMagFilter = ImGuiUtils::EnumBox<SamplerFiltering>("MagFilter", mMagFilter);
		mMipmapMode = ImGuiUtils::EnumBox<SamplerMapMode>("MipmapMode", mMipmapMode);
		mAddressModeU = ImGuiUtils::EnumBox<SamplerAddressMode>("AddressModeU", mAddressModeU);
		mAddressModeV = ImGuiUtils::EnumBox<SamplerAddressMode>("AddressModeV", mAddressModeV);
		mAddressModeW = ImGuiUtils::EnumBox<SamplerAddressMode>("AddressModeW", mAddressModeW);
		mMipLodBias = ImGuiUtils::Float32Field("MipLodBias", mMipLodBias);
		mMaxAnisotropy = ImGuiUtils::Float32Field("MaxAnisotropy", mMaxAnisotropy);
		mComparisonEnabled = ImGuiUtils::Checkbox("ComparisonEnabled", mComparisonEnabled);
		mCompareOperation = ImGuiUtils::EnumBox<CompareOperation>("CompareOperation", mCompareOperation);
		mMinLod = ImGuiUtils::Float32Field("MinLod", mMinLod);
		mMaxLod = ImGuiUtils::Float32Field("MaxLod", mMaxLod);
		mBorderColor = ImGuiUtils::EnumBox<SamplerBorderColor>("BorderColor", mBorderColor);

		// Save & Hot Reload
		if (ImGui::Button("Save & Hot Reload"))
		{

		}
	}
}
