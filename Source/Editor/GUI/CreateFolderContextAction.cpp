#include "CreateFolderContextAction.h"
#include <imgui.h>

namespace Portakal
{
    bool CreateFolderContextAction::OnAction(DomainFolder* pFolder)
    {
        mOpen = true;
        return true;
    }
    bool CreateFolderContextAction::OnTick(DomainFolder* pFolder)
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
            if (ImGui::Button("Create"))
            {
                ImGui::EndPopup();
                return false;
            }
            ImGui::EndPopup();
        }

        return true;
    }
    void CreateFolderContextAction::OnShutdown()
    {

    }
}
