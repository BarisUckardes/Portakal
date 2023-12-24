
#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>
#include "Source\Runtime\TestClass.h"
#include "External\Glslang\Include\Common.h"
#include "Source\Runtime\Application\ApplicationModule.h"
#include "Source\Runtime\Object\Object.h"
#include "Source\Runtime\Platform\PlatformType.h"

extern "C"
{
	__declspec(dllexport) Portakal::ReflectionManifest* GenerateModuleManifest()
	{
		Portakal::ReflectionManifest* pManifest = nullptr;

		//Create types here
		Portakal::Type* pTestClass = Portakal::TypeDispatcher::CreateType("TestClass",sizeof(Portakal::TestClass),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,nullptr,Portakal::TypeDispatcher::GetTypeAddress<Portakal::TestClass>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::TestClass>(pTestClass);
;		Portakal::Type* pCommon = Portakal::TypeDispatcher::CreateType("Common",sizeof(Portakal::Common),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,nullptr,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Common>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Common>(pCommon);
;		Portakal::Type* pApplicationModule = Portakal::TypeDispatcher::CreateType("ApplicationModule",sizeof(Portakal::ApplicationModule),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,nullptr,Portakal::TypeDispatcher::GetTypeAddress<Portakal::ApplicationModule>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::ApplicationModule>(pApplicationModule);
;		Portakal::Type* pObject = Portakal::TypeDispatcher::CreateType("Object",sizeof(Portakal::Object),Portakal::TypeModes::Class,Portakal::TypeCodes::Composed,nullptr,Portakal::TypeDispatcher::GetTypeAddress<Portakal::Object>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::Object>(pObject);
;		Portakal::Type* pPlatformType = Portakal::TypeDispatcher::CreateType("PlatformType",sizeof(Portakal::PlatformType),Portakal::TypeModes::Enum,Portakal::TypeCodes::Composed,nullptr,Portakal::TypeDispatcher::GetTypeAddress<Portakal::PlatformType>());
		Portakal::TypeDispatcher::SetTypeAddress<Portakal::PlatformType>(pPlatformType);
;
        //Register enums here
		Portakal::TypeDispatcher::RegisterEnum("Windows",112,pPlatformType);
		Portakal::TypeDispatcher::RegisterEnum("Linux",113,pPlatformType);
		Portakal::TypeDispatcher::RegisterEnum("Mac",155,pPlatformType);
		Portakal::TypeDispatcher::RegisterEnum("PS5",156,pPlatformType);
		Portakal::TypeDispatcher::RegisterEnum("Switch",157,pPlatformType);

        //Register fields here
		Portakal::TypeDispatcher::RegisterField("mMyType",offsetof(Portakal::TestClass,mMyType),typeof(Portakal::uint32),pTestClass);
		Portakal::TypeDispatcher::RegisterField("mMahString",offsetof(Portakal::TestClass,mMahString),typeof(Portakal::String),pTestClass);

        //Register attributes here

        //Register base types here
		Portakal::TypeDispatcher::SetBaseType(typeof(Portakal::TestClass),typeof(Portakal::Object));

		//Create manifest here
		Portakal::Array<Portakal::Type*> types = {pTestClass,pCommon,pApplicationModule,pObject,pPlatformType,};
		pManifest = new Portakal::ReflectionManifest("Runtime", types);

		return pManifest;
	}
}
