#pragma once
#include <Runtime/Resource/Resource.h>
#include <Runtime/Resource/ResourceDescriptor.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Object/API.h>

namespace Portakal
{
	class RUNTIME_API ResourceAPI : API<ResourceAPI>
	{
		friend class ResourceModule;
	public:
		static SharedHeap<Resource> RegisterResource(const String& descriptorPath);
		static void RemoveResource(const String& name);
		static void RemoveResource(const Guid& id);
		static SharedHeap<Resource> GetResource(const String& name);
		static SharedHeap<Resource> GetResource(const Guid& id);
	private:
		ResourceAPI();
		~ResourceAPI();
	private:
		Array<SharedHeap<Resource>> mResources;
	};
}
