#include "CreateSamplerContextMenuItem.h"
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Platform/PlatformPaths.h>
#include <Runtime/Resource/Sampler/SamplerDescriptor.h>
#include <Runtime/Yaml/Yaml.h>
#include <Editor/ImGui/ImGuiUtils.h>

#include <imgui.h>
#include <misc/cpp/imgui_stdlib.h>

namespace Portakal
{
	bool CreateSamplerContextMenuItem::OnAction(DomainFolder* pFolder)
	{
		mOpen = true;
		return true;
	}
	bool CreateSamplerContextMenuItem::OnTick(DomainFolder* pFolder)
	{
		if (mOpen)
		{
			ImGui::OpenPopup("Create Sampler");
			mOpen = false;
		}

		if (ImGui::BeginPopup("Create Sampler"))
		{
			ImGui::Text("Create Sampler");
			ImGui::Separator();
			ImGui::Spacing();

			// File Name
			std::string temp(mName.GetSource(), mName.GetSize());
			ImGui::InputText("Name:", &temp);
			mName = temp.c_str();

			// Descriptor Details
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

			if (ImGui::Button("Create"))
			{
				//Create folder
				const String path = PlatformPaths::GetPersistentDataPath() + "\\" + mName + ".psampler";
				if (!PlatformFile::Create(path))
				{
					DEV_LOG("CreateSamplerContextMenuItem", "Failed to create external copy");
				}
				else
				{
					SamplerDescriptor descriptor = {};
					descriptor.mMinFilter = mMinFilter;
					descriptor.mMagFilter = mMagFilter;
					descriptor.mMipmapMode = mMipmapMode;
					descriptor.mAddressModeU = mAddressModeU;
					descriptor.mAddressModeV = mAddressModeV;
					descriptor.mAddressModeW = mAddressModeW;
					descriptor.mMipLodBias = mMipLodBias;
					descriptor.mMaxAnisotropy = mMaxAnisotropy;
					descriptor.mComparisonEnabled = mComparisonEnabled;
					descriptor.mCompareOperation = mCompareOperation;
					descriptor.mMinLod = mMinLod;
					descriptor.mMaxLod = mMaxLod;
					descriptor.mBorderColor = mBorderColor;

					const String descriptorYAML = Yaml::ToYaml<SamplerDescriptor>(&descriptor);
					PlatformFile::Write(path, descriptorYAML);
					pFolder->ImportExternalFile(path);
				}
				ImGui::EndPopup();
				return false;
			}
			ImGui::EndPopup();
		}
		else
		{
			return false;
		}

		return true;
	}
	void CreateSamplerContextMenuItem::OnShutdown()
	{
	}
}
