#include "Application.h"
#include <Runtime/Reflection/ReflectionModule.h>

namespace Portakal
{
    Application::Application() : mQuitReason("Unknown"),mQuitRequest(false),mInvalidationRequest(false)
    {
        sApplication = this;
    }
    Application::~Application()
    {
        sApplication = nullptr;
    }
    void Application::RemoveModule(const UInt32 index)
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
            //Check if invalidation is required
            if (mInvalidationRequest)
            {
                //Pre invalidate
                for (ApplicationModule* pModule : mModules)
                {
                    if (pModule->GetState() != ApplicationModuleState::OK)
                        continue;

                    pModule->OnPreInvalidation();
                }

                //Invalidate

                //Post invalidate
                for (ApplicationModule* pModule : mModules)
                {
                    if (pModule->GetState() != ApplicationModuleState::OK)
                        continue;

                    pModule->OnPostInvalidation();
                }

                mInvalidationRequest = false;
            }

            //Call pre tick impl
            OnPreTick();

            //Call module ticks
            for (ApplicationModule* pModule : mModules)
            {
                //Get type
                const Type* pType = pModule->GetType();

                //Check module state
                const ApplicationModuleState state = pModule->GetState();
                if (state == ApplicationModuleState::NeedsInitialization)
                {
                    if(pType != nullptr)
                        DEV_LOG("Application", "Initializing module %s...", *pType->GetName());
                    else
                        DEV_LOG("Application", "Initializing unknown module X (Probably reflection module hasnt initialized or did not load the ReflectionManifest yet!)...");

                    pModule->_SetOwnerApplication(this);
                    pModule->OnInitialize();
                    pModule->_SetState(ApplicationModuleState::OK);
                    DEV_LOG("Application", "Finished initializing!");
                }
                else if (state == ApplicationModuleState::NeedsFinalization)
                {
                    //DEV_LOG("Application", "Finalizing module %s..", *pType->GetName());
                    pModule->OnFinalize();
                    pModule->_SetOwnerApplication(nullptr);
                    removedModules.Add(pModule);
                    DEV_LOG("Application", "Finished finalizing!");
                    continue;
                }

                //Tick
                pModule->OnTick();

                //Check for quit request
                if (mQuitRequest)
                    break;
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

        //Clear modules
        for (Int32 i = mModules.GetSize() - 1;i>=0; i--)
        {
            ApplicationModule* pModule = mModules[i];
            Type* pType = pModule->GetType();

            DEV_LOG("Application","Finalizing module %s..", *pType->GetName());
            mModules[i]->OnFinalize();
            DEV_LOG("Application","Finished finalizing %s!",*pType->GetName());
        }
        mModules.Clear();

        //Post quit reason
        DEV_LOG("Application", "Quit reason-> %s", *mQuitReason);
    }
    void Application::PostQuitRequest(const String& reason)
    {
        mQuitRequest = true;
        mQuitReason = reason;
    }
    void Application::PostInvalidationRequest(const String& reason)
    {
        mInvalidationRequest = true;
        mInvalidationReason = reason;
    }
    void Application::_RegisterAPI(Object* pAPI)
    {
        mAPIs.Add(pAPI);
    }
    void Application::_RemoveAPI(Object* pAPI)
    {
        mAPIs.Remove(pAPI);
    }
}
