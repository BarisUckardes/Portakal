#include "DisplayAspect.h"

namespace Portakal
{
    void DisplayAspect::RegisterDisplay(const SharedHeap<RenderTargetResource>& pDisplay)
    {
        if (mDisplays.Has(pDisplay))
            return;

        mDisplays.Add(pDisplay);
    }
    void DisplayAspect::RemoveDisplay(const SharedHeap<RenderTargetResource>& pDisplay)
    {
        if (!mDisplays.Has(pDisplay))
            return;

        mDisplays.Remove(pDisplay);
    }
    void DisplayAspect::OnInitialize()
    {

    }
    void DisplayAspect::OnExecute()
    {

    }
}
