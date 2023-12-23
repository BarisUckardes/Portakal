#include "Application.h"

namespace Portakal
{
    Application::Application() : mQuitReason("Unknown"),mQuitRequest(false)
    {
    }
    Application::~Application()
    {
    }
    void Application::RemoveModule(const uint32 index)
    {
        ApplicationModule* pModule = mModules[index];
        pModule->_SetState(ApplicationModuleState::NeedsFinalization);
        mModules.RemoveAt(index);
    }
    void Application::Run()
    {
        //Call initialize impl
        OnInitialize();

        //Run
        Array<ApplicationModule*> removedModules;
        while (!mQuitRequest)
        {
            //Call pre tick impl
            OnPreTick();

            //Call module ticks
            for (ApplicationModule* pModule : mModules)
            {
                //Check module state
                const ApplicationModuleState state = pModule->GetState();
                if (state == ApplicationModuleState::NeedsInitialization)
                {
                    pModule->_SetOwnerApplication(this);
                    pModule->OnInitialize();
                    pModule->_SetState(ApplicationModuleState::OK);
                }
                else if (state == ApplicationModuleState::NeedsFinalization)
                {
                    pModule->OnFinalize();
                    pModule->_SetOwnerApplication(nullptr);
                    removedModules.Add(pModule);
                    continue;
                }

                //Tick
                pModule->OnTick();
            }

            //Call post tick impl
            OnPostTick();

            //Clear removed modules
            for (ApplicationModule* pModule : removedModules)
                mModules.Remove(pModule);
            removedModules.Clear();
        }

        //Call finalize impl
        OnFinalize();

        //Post quit reason
        DEV_LOG("Application", "Quit reason-> %s", *mQuitReason);
    }
    void Application::PostQuitRequest(const String& reason)
    {
        mQuitRequest = true;
        mQuitReason = reason;
    }
}
