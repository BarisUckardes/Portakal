#include "ShaderObjectPainter.h"
#include <Editor/ImGui/ImGuiAPI.h>
#include <imgui.h>
#include <Editor/ImGui/ImGuiUtils.h>

namespace Portakal
{
    void ShaderObjectPainter::OnInitialize()
    {
        //Get shader and validate
        mShader = GetTargetObject().QueryAs<ShaderResource>();
        if (mShader.IsShutdown())
            return;

        mSource = mShader->GetSource();

        if (mShader->GetShader().IsShutdown())
            return;

        mLanguage = mShader->GetShader()->GetLanguage();
        mStage = mShader->GetShader()->GetStage();
        mEntryPoint = mShader->GetShader()->GetEntryPoint();
    }
    void ShaderObjectPainter::OnPaint()
    {
        //Validate
        if (mShader.IsShutdown())
        {
            ImGui::Text("Invalid shader");
            return;
        }

        //Language
        mLanguage = ImGuiUtils::EnumBox<ShaderLanguage>("Language", mLanguage);

        //Stage
        mStage = ImGuiUtils::EnumBox<ShaderStage>("Stage", mStage);

        //entry method
        mEntryPoint = ImGuiUtils::TextField("Entry method", mEntryPoint);

        //Source
        mSource = ImGuiUtils::MultiTextField("Source", mSource);

        //compile&save
        if (ImGui::Button("Compile&Save"))
        {

        }
    }
}
