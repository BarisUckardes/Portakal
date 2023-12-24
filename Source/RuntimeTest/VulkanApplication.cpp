#include "VulkanApplication.h"
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Runtime/TestClass.h>

namespace Portakal
{
	void VulkanApplication::OnInitialize()
	{

	}
	void VulkanApplication::OnFinalize()
	{

	}
	bool bDone = false;
	void VulkanApplication::OnPreTick()
	{
		if (bDone)
			return;

		//Reflection stuff
		const Assembly* pAssembly = ReflectionAPI::GetMainAssembly();
		if (pAssembly == nullptr)
			return;

		const Array<Type*> types = pAssembly->GetTypes();
		for (const Type* pType : types)
			DEV_LOG("VulkanApplication", "Found type: %s", *pType->GetName());

		Type* pType = typeof(TestClass);
		bDone = true;
	}
	void VulkanApplication::OnPostTick()
	{

	}
}
