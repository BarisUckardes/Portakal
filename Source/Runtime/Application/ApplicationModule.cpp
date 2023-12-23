#include "ApplicationModule.h"

namespace Portakal
{
    void ApplicationModule::_SetState(const ApplicationModuleState state)
    {
        mState = state;
    }
    void ApplicationModule::_SetOwnerApplication(Application* pApplication)
    {
        mOwnerApplication = pApplication;
    }
}
