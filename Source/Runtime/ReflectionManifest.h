#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Reflection/ReflectionManifest.h>

extern "C"
{
	Portakal::ReflectionManifest* GenerateReflectionManifest()
	{
		Portakal::ReflectionManifest * pManifest = nullptr;

		//Generate types
		Portakal::Array<Portakal::Type*> types;

		//Create manifest
		pManifest = new Portakal::ReflectionManifest("Runtime", types);

		return pManifest;
	}
}
