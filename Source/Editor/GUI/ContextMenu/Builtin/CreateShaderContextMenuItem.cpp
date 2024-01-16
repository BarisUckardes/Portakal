#include "CreateShaderContextMenuItem.h"
#include <imgui.h>
#include <misc/cpp/imgui_stdlib.h>
#include <Runtime/Platform/PlatformPaths.h>
#include <Runtime/Platform/PlatformFile.h>
#include <Editor/ImGui/ImGuiUtils.h>
#include <Runtime/Yaml/Yaml.h>

namespace Portakal
{

    bool CreateShaderContextMenuItem::OnAction(DomainFolder* pFolder)
    {
        mOpen = true;
        return true;
    }

    bool CreateShaderContextMenuItem::OnTick(DomainFolder* pFolder)
    {
        if (mOpen)
        {
            ImGui::OpenPopup("ShaderCreatePopup");
            mOpen = false;
        }

        if (ImGui::BeginPopup("ShaderCreatePopup"))
        {
            ImGui::Text("Create Shader");
            ImGui::Separator();
            ImGui::Spacing();

            //Name
            std::string tempName(mName.GetSource(), mName.GetSize());
            ImGui::InputText("Name:", &tempName);
            mName = tempName.c_str();

            //Entry method
            std::string tempMethod(mEntryMethod.GetSource(), mEntryMethod.GetSize());
            ImGui::InputText("Entry method:", &tempMethod);
            mEntryMethod = tempMethod.c_str();

            //Stage
            mStage = ImGuiUtils::EnumBox<ShaderStage>("Stage", mStage);

            //Language
            mLanguage = ImGuiUtils::EnumBox<ShaderLanguage>("Language", mLanguage);

            if (ImGui::Button("Create"))
            {
                const String path = PlatformPaths::GetPersistentDataPath() + "\\" + mName + ".pshader";
                if (!PlatformFile::Create(path))
                {
                    DEV_LOG("CreateShaderContextMenuItem","Failed to create external copy");
                }
                else
                {
                    ShaderDescriptor descriptor = {};
                    descriptor.EntryMethodName = mEntryMethod;
                    descriptor.Stage = mStage;
                    descriptor.Language = mLanguage;
                    descriptor.Source = "No source yet";

                    const String descriptorYAML = Yaml::ToYaml<ShaderDescriptor>(&descriptor);
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
        return false;
    }

}
