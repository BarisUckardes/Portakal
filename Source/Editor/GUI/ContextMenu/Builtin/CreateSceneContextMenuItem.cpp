#include "CreateSceneContextMenuItem.h"
#include <imgui.h>
#include <misc/cpp/imgui_stdlib.h>
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Platform/PlatformPaths.h>
#include <Runtime/Resource/Scene/SceneDescriptor.h>
#include <Runtime/Yaml/Yaml.h>

namespace Portakal
{
	bool CreateSceneContextMenuItem::OnAction(DomainFolder* pFolder)
	{
		mOpen = true;
		return true;
	}
	bool CreateSceneContextMenuItem::OnTick(DomainFolder* pFolder)
	{
		if (mOpen)
		{
			ImGui::OpenPopup("SceneCreatePopup");
			mOpen = false;
		}

		if (ImGui::BeginPopup("SceneCreatePopup"))
		{
			ImGui::Text("Create Scene");
			ImGui::Separator();
			ImGui::Spacing();

			std::string temp(mName.GetSource(), mName.GetSize());
			ImGui::InputText("Name:", &temp);
			mName = temp.c_str();

			if (ImGui::Button("Create"))
			{
				//Create folder
				const String path = PlatformPaths::GetPersistentDataPath() + "\\" + mName + ".pscene";
				if (!PlatformFile::Create(path))
				{
					DEV_LOG("CreateSceneContextMenuItem", "Failed to create the scene file");
				}
				else
				{
					SceneDescriptor descriptor = {};
					String descriptorYAML = Yaml::ToYaml<SceneDescriptor>(&descriptor);
					PlatformFile::Write(path, descriptorYAML);
					pFolder->ImportExternalFile(path);
				}
				PlatformFile::Delete(path);

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
}
