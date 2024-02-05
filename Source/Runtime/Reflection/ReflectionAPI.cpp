#include "ReflectionAPI.h"
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>
#include <Runtime/Application/Application.h>

namespace Portakal
{

    Array<Assembly*> ReflectionAPI::GetAssemblies()
    {
        return Application::GetCurrent()->GetAssemblies();
    }
    Array<Type*> ReflectionAPI::GetSubTypes(const Type* pTargetType)
    {
        Array<Type*> subTypes;
        Array<Assembly*> assemblies = GetAssemblies();
        if (assemblies.GetSize() == 0)
            return subTypes;

        for (const Assembly* pAssembly : assemblies)
        {
            const Array<Type*>& types = pAssembly->GetTypes();
            for (Type* pType : types)
            {
                if (pType->IsSubClassOf(pTargetType))
                    subTypes.Add(pType);
            }
        }

        return subTypes;
    }
    Type* ReflectionAPI::GetType(const String& name)
    {
        Array<Assembly*> assemblies = GetAssemblies();
        if (assemblies.GetSize() == 0)
            return nullptr;

        for (const Assembly* pAssembly : assemblies)
        {
            const Array<Type*>& types = pAssembly->GetTypes();
            for (Type* pType : types)
                if (pType->GetName() == name)
                    return pType;
        }

        return nullptr;
    }
}
