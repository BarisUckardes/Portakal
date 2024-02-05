#include "ResourceAPI.h"
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Yaml/Yaml.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Runtime/Resource/IResourceDeserializer.h>
#include <Runtime/Resource/CustomResourceDeserializer.h>

namespace Portakal
{
	void ResourceAPI::_RegisterResource(const SharedHeap<Resource>& pTargetResource)
	{
		//Check API
		ResourceAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
		{
			DEV_LOG("ResourceAPI", "No resource API found!");
			return;
		}

		//Create resource
		pAPI->mResources.Add(pTargetResource);
	}
	void ResourceAPI::_RemoveResource(Resource* pTargetResource)
	{
		//Get and validate API
		ResourceAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		for (UInt32 i = 0; i < pAPI->mResources.GetSize(); i++)
		{
			const SharedHeap<Resource>& pResource = pAPI->mResources[i];
		}
		pAPI->mResources.Remove(pTargetResource);
	}
	
	SharedHeap<Resource> ResourceAPI::GetResource(const String& name)
	{
		//Get and validate API
		ResourceAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		//Search for the name
		for (UInt32 i = 0; i < pAPI->mResources.GetSize(); i++)
		{
			const SharedHeap<Resource>& resource = pAPI->mResources[i];
			if (resource->GetName() == name)
				return resource;
		}

		return nullptr;
	}
	SharedHeap<Resource> ResourceAPI::GetResource(const Guid& id)
	{
		//Get and validate API
		ResourceAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		//Search for the name
		for (UInt32 i = 0; i < pAPI->mResources.GetSize(); i++)
		{
			const SharedHeap<Resource>& resource = pAPI->mResources[i];
			if (resource->GetID() == id)
				return resource;
		}

		return nullptr;
	}
	void ResourceAPI::GetResources(const String& type, Array<SharedHeap<Resource>>& resourcesOut)
	{
		//Get and validate API
		ResourceAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		//Search for the resource
		for (const SharedHeap<Resource>& pResource : pAPI->mResources)
			if (pResource->GetResourceType() == type)
				resourcesOut.Add(pResource);
	}

	ResourceAPI::ResourceAPI()
	{

	}
	ResourceAPI::~ResourceAPI()
	{
		for (SharedHeap<Resource>& resource : mResources)
			resource.Shutdown();

		mResources.Clear();
	}
}
