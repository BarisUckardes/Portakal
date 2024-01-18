#include "BasicRenderAspect.h"

namespace Portakal
{
    void BasicRenderAspect::RegisterCamera(const BasicCamera* pCamera)
    {
        mCameras.Add(pCamera);
    }
    void BasicRenderAspect::RemoveCamera(const BasicCamera* pCamera)
    {
        mCameras.Remove(pCamera);
    }
    void BasicRenderAspect::RegisterRenderable(const BasicRenderable* pRenderable)
    {
        mRenderables.Add(pRenderable);
    }
    void BasicRenderAspect::RemoveRenderable(const BasicRenderable* pRenderable)
    {
        mRenderables.Remove(pRenderable);
    }
    void BasicRenderAspect::OnInitialize()
    {

    }
    void BasicRenderAspect::OnExecute()
    {

    }
}
