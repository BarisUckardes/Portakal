#pragma once
#include <Runtime/Resource/Resource.h>
#include <Runtime/Resource/ResourceDescriptor.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Object/API.h>

namespace Portakal
{
	/// <summary>
	/// API for resource works
	/// </summary>
	class RUNTIME_API ResourceAPI : API<ResourceAPI>
	{
		friend class ResourceModule;
		friend class Resource;
	public:;
		static SharedHeap<Resource> GetResource(const String& name);
		static SharedHeap<Resource> GetResource(const Guid& id);
		static void GetResources(const String& type,Array<SharedHeap<Resource>>& resourcesOut);
	private:
		static void _RegisterResource(const SharedHeap<Resource>& pTargetResource);
		static void _RemoveResource(Resource* pTargetResource);
	private:
		ResourceAPI();
		~ResourceAPI();
	private:
		Array<SharedHeap<Resource>> mResources;
	};
}
