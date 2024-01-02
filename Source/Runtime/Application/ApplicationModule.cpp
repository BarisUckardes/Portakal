#include "ApplicationModule.h"
#include <Runtime/Application/Application.h>

namespace Portakal
{
    void ApplicationModule::PostQuitRequest(const String& reason)
    {
        GetOwnerApplication()->PostQuitRequest(reason);
    }
    void ApplicationModule::_SetState(const ApplicationModuleState state)
    {
        mState = state;
    }
    void ApplicationModule::_SetOwnerApplication(Application* pApplication)
    {
        mOwnerApplication = pApplication;
    }
}
