#include "EditorPlayerProjectModule.h"
#include <Editor/Project/ProjectGenerator.h>
#include <Editor/Project/ProjectAPI.h>

namespace Portakal
{
    void EditorPlayerProjectModule::OnInitialize()
    {
        const String projectFolderPath = ProjectAPI::GetFolderPath();
        //ProjectGenerator::GenerateProject("PortakalTestProject", projectFolderPath);
    }
    void EditorPlayerProjectModule::OnFinalize()
    {

    }
    void EditorPlayerProjectModule::OnTick()
    {

    }
}
