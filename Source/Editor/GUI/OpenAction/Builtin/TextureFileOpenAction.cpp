#include "TextureFileOpenAction.h"
#include <Editor/Domain/DomainFile.h>
#include <Editor/GUI/Object/EditorObjectAPI.h>

namespace Portakal
{
    void TextureFileOpenAction::OnOpen(DomainFile* pFile)
    {
        EditorObjectAPI::SignalObject(pFile->GetSubObject().QueryAs<Object>());
    }
}
