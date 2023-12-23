#include "ReflectionAPI.h"
#include <Runtime/Reflection/ReflectionManifest.h>

namespace Portakal
{
    typedef ReflectionManifest* (*GetManifestProc)();

    Assembly* ReflectionAPI::LoadLibraryReflection(const SharedHeap<PlatformLibrary>& pLibrary)
    {
        //Check library
        if (pLibrary.IsShutdown())
            return nullptr;

        //Check API
        ReflectionAPI* pAPI = GetUnderlyingAPI();
        if (pAPI == nullptr)
            return nullptr;

        //Try get loader proc
        GetManifestProc getProc = (GetManifestProc)pLibrary->GetSymbol("GenerateModuleManifest");
        if (getProc == nullptr)
            return nullptr;

        //Call manifest
        ReflectionManifest* pManifest = getProc();
        if (pManifest == nullptr)
            return nullptr;

        //Create assembly
        Assembly* pAssembly = new Assembly(pLibrary->GetName(),pLibrary->GetPath(), pManifest->GetTypes());

        //Create entry
        Entry entry = {};
        entry.pLibrary = pLibrary;
        entry.pManifest = pManifest;
        entry.pAssembly = pAssembly;
        pAPI->mEntries.Add(entry);

        return pAssembly;
    }
    ReflectionAPI::ReflectionAPI()
    {

    }
    ReflectionAPI::~ReflectionAPI()
    {

    }
    void ReflectionAPI::Refresh()
    {
        //Free and record each
        Array<String> libraryPaths;
        for(const Entry& entry : mEntries)
        {
            //Cache path
            libraryPaths.Add(entry.pLibrary->GetPath());

            //Delete manifest and assembly
            delete entry.pManifest;
            delete entry.pAssembly;
        }
        mEntries.Clear();

        //Load the libraries
        for (const String& path : libraryPaths)
        {
            SharedHeap<PlatformLibrary> pLibrary = PlatformLibrary::Load(path);
        }
    }
}
