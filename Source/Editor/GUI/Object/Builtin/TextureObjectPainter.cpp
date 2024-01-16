#include "TextureObjectPainter.h"
#include <Editor/ImGui/ImGuiAPI.h>
#include <imgui.h>

namespace Portakal
{
    void TextureObjectPainter::OnInitialize()
    {
        mTexture = GetTargetObject().QueryAs<TextureResource>();
        mTextureBinding = ImGuiAPI::GetRenderer()->GetOrCreateTextureBinding(mTexture);
    }
    void TextureObjectPainter::OnPaint()
    {
        ImGui::Image(mTextureBinding->GetTable(), { 512,512 });
    }
}
