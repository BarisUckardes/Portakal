#include "ResourceModule.h"
#include <Runtime/Resource/ResourceAPI.h>

namespace Portakal
{
    void ResourceModule::OnInitialize()
    {
        mAPI = new ResourceAPI();
    }
    void ResourceModule::OnFinalize()
    {
        delete mAPI;
        mAPI = nullptr;
    }
    void ResourceModule::OnTick()
    {
    }
}
