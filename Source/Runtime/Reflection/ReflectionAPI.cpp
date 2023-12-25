#include "ReflectionAPI.h"
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>

namespace Portakal
{
    Assembly* ReflectionAPI::LoadLibraryReflection(const SharedHeap<PlatformLibrary>& pLibrary)
    {
        //Check library
        if (pLibrary.IsShutdown())
            return nullptr;

        //Check API
        ReflectionAPI* pAPI = GetUnderlyingAPI();
        if (pAPI == nullptr)
            return nullptr;
        
        //Create entry
        Entry entry = pAPI->CreateEntry(pLibrary, false);

        return entry.pAssembly;
    }
    const Assembly* ReflectionAPI::GetMainAssembly()
    {
        //Check API
        ReflectionAPI* pAPI = GetUnderlyingAPI();
        if (pAPI == nullptr)
            return nullptr;

        return pAPI->mMainEntry.pAssembly;
    }
    Array<const Assembly*> ReflectionAPI::GetAssemblies()
    {
        //Check API
        ReflectionAPI* pAPI = GetUnderlyingAPI();
        if (pAPI == nullptr)
            return {};

        Array<const Assembly*> assemblies;
        assemblies.Add(pAPI->mMainEntry.pAssembly);
        for (const Entry& entry : pAPI->mEntries)
            assemblies.Add(entry.pAssembly);

        return assemblies;
    }
    ReflectionAPI::ReflectionAPI()
    {
        Invalidate();
    }
    ReflectionAPI::~ReflectionAPI()
    {

    }
    void ReflectionAPI::Invalidate()
    {
        //Free and record each
        Array<String> libraryPaths;
        for (const Entry& entry : mEntries)
        {
            //Cache path
            libraryPaths.Add(entry.pLibrary->GetPath());

            //Delete manifest and assembly
            DeleteEntry(entry, false);
        }
        mEntries.Clear();

        //Load the libraries
        for (const String& path : libraryPaths)
        {
            //Load
            SharedHeap<PlatformLibrary> pLibrary = PlatformLibrary::Load(path);

            //Create
            CreateEntry(pLibrary,false);
        }

        //Get the main
        SharedHeap<PlatformLibrary> pMainLibrary = PlatformLibrary::GetCurrent();

        //Register the main
        CreateEntry(pMainLibrary, true);
    }
    ReflectionAPI::Entry ReflectionAPI::CreateEntry(const SharedHeap<PlatformLibrary>& pLibrary,const bool bMain)
    {
        //Try get loader proc
        GetManifestProc getProc = (GetManifestProc)pLibrary->GetSymbol("GenerateModuleManifest");
        if (getProc == nullptr)
            return {};

        //Call manifest
        ReflectionManifest* pManifest = getProc();
        if (pManifest == nullptr)
            return  {};

        //Create assembly
        Assembly* pAssembly = new Assembly(pLibrary->GetName(), pLibrary->GetPath(), pManifest->GetTypes());

        //Normalize the assembly
        Normalize(pAssembly);

        //Create entry
        Entry entry = {};
        entry.pLibrary = pLibrary;
        entry.pAssembly = pAssembly;
        entry.pManifest = pManifest;

        //Register entry
        if (bMain)
            mMainEntry = entry;
        else
            mEntries.Add(entry);

        return entry;
    }
    void ReflectionAPI::DeleteEntry(const Entry& entry, const bool bMain)
    {
        //Delete
        delete entry.pAssembly;
        delete entry.pManifest;
        if (!bMain)
            entry.pLibrary.Shutdown();
    }
    void ReflectionAPI::Normalize(Assembly* pAssembly)
    {
        //Get assembly types
        Array<Type*> assemblyTypes = pAssembly->GetTypes();
        
        //First normalize with the main
        if (!mMainEntry.pLibrary.IsShutdown())
        {
            Array<Type*> mainTypes = mMainEntry.pAssembly->GetTypes();
            for (Type* pAssemblyType : assemblyTypes)
            {
                for (Type* pMainType : mainTypes)
                {
                    if (pMainType->GetName() == pAssemblyType->GetName())
                    {
                        Type** pAddress = TypeDispatcher::GetTypeAddress(pAssemblyType);
                        *pAddress = pMainType;
                        break;
                    }
                }
            }
        }

        //Iterate and look for the matches
        for (Type* pAssemblyType : assemblyTypes)
        {
            for (const Entry& entry : mEntries)
            {
                const Array<Type*> types = entry.pAssembly->GetTypes();

                for (Type* pType : types)
                {
                    if (pType->GetName() == pAssemblyType->GetName())
                    {
                        Type** pAddress = TypeDispatcher::GetTypeAddress(pAssemblyType);
                        *pAddress = pType;
                        break;
                    }
               }
            }
        }


    }
}