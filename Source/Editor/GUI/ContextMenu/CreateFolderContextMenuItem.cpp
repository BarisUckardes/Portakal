#include "CreateFolderContextMenuItem.h"
#include <imgui.h>
#include <misc/cpp/imgui_stdlib.cpp>

namespace Portakal
{
    bool CreateFolderContextMenuItem::OnAction(DomainFolder* pFolder)
    {
        mOpen = true;
        return true;
    }
    bool CreateFolderContextMenuItem::OnTick(DomainFolder* pFolder)
    {
        if (mOpen)
        {
            ImGui::OpenPopup("FolderCreatePopup");
            mOpen = false;
        }

        if (ImGui::BeginPopup("FolderCreatePopup"))
        {
            ImGui::Text("Create folder");
            ImGui::Separator();
            ImGui::Spacing();

            std::string temp(mName.GetSource(), mName.GetSize());
            ImGui::InputText("Name:",&temp);
            mName = temp.c_str();

            if (ImGui::Button("Create"))
            {
                //Create folder
                pFolder->CreateFolder(mName);
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
    void CreateFolderContextMenuItem::OnShutdown()
    {

    }
}
