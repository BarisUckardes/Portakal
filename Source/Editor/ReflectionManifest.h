
#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Reflection/ReflectionManifest.h>
#include <Runtime/Reflection/TypeDispatcher.h>

extern "C"
{
	__declspec(dllexport) Portakal::ReflectionManifest* GenerateModuleManifest()
	{
		Portakal::ReflectionManifest* pManifest = nullptr;

		//Create types here

        //Register enums here

        //Register fields here

        //Register attributes here

        //Register base types here

		//Create manifest here
		Portakal::Array<Portakal::Type*> types = {};
		pManifest = new Portakal::ReflectionManifest("Runtime", types);

		return pManifest;
	}
}
