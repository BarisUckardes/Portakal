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
        Float32 fov = mCamera->GetFieldOfView();
        ImGui::SliderFloat32("Field of view", &fov, 12, 179);
        mCamera->SetFieldOfView(fov);

        //Near plane
        Float32 n = mCamera->GetNearPlane();
        ImGui::SliderFloat32("Near plane", &n, -1000, 1000);
        mCamera->SetNearPlane(n);

        //Near plane
        Float32 f = mCamera->GetFarPlane();
        ImGui::SliderFloat32("Far plane", &f, -1000, 1000);
        mCamera->SetFarPlane(f);

    }
}
