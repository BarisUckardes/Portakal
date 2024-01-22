#include "BasicCameraPainter.h"
#include <Runtime/World/Entity.h>
#include <imgui.h>

namespace Portakal
{
    void BasicCameraPainter::OnInitialize()
    {
        mCamera = GetTargetComponent().QueryAs<BasicCamera>();
    }
    void BasicCameraPainter::OnPaint()
    {
        //Field of view
        float fov = mCamera->GetFieldOfView();
        ImGui::SliderFloat("Field of view", &fov, 12, 179);
        mCamera->SetFieldOfView(fov);

        //Near plane
        float n = mCamera->GetNearPlane();
        ImGui::SliderFloat("Near plane", &n, -1000, 1000);
        mCamera->SetNearPlane(n);

        //Near plane
        float f = mCamera->GetFarPlane();
        ImGui::SliderFloat("Far plane", &f, -1000, 1000);
        mCamera->SetFarPlane(f);

    }
}
