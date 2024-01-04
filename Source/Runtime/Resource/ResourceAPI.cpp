#include "ResourceAPI.h"
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Yaml/Yaml.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Runtime/Resource/IResourceDeserializer.h>
#include <Runtime/Resource/ResourceDeserializerAttribute.h>

namespace Portakal
{
	SharedHeap<Resource> ResourceAPI::RegisterResource(const String& descriptorPath)
	{
		//Check API
		ResourceAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
		{
			DEV_LOG("ResourceAPI", "No resource API found!");
			return nullptr;
		}

		//Check file if exists
		if (!PlatformFile::Exists(descriptorPath))
		{
			DEV_LOG("ResourceAPI", "Given descriptor file path does not exist");
			return nullptr;
		}

		//Load descriptor
		String fileContent;
		if (!PlatformFile::Read(descriptorPath, fileContent))
		{
			DEV_LOG("ResourceAPI", "Failed to load the given descriptor file");
			return nullptr;
		}

		//Convert descriptor
		ResourceDescriptor descriptor = {};
		Yaml::ToObject<ResourceDescriptor>(fileContent,&descriptor);

		//Check resource name and id
		if (descriptor.Name == "" || descriptor.ID == Guid::Zero())
		{
			DEV_LOG("ResourceAPI", "Descriptor name or ID is invalid!");
			return nullptr;
		}

		//Check resource file path
		if (!PlatformFile::Exists(descriptor.Path))
		{
			DEV_LOG("ResourceAPI", "Given resource descriptor does not point to a valid resource!");
			return nullptr;
		}

		//Check resource type
		const Array<Type*> types = ReflectionAPI::GetSubTypes(typeof(IResourceDeserializer));
		if (types.IsEmpty())
		{
			DEV_LOG("ResourceAPI", "No IResourceDeserializer in this application!");
			return nullptr;
		}
		Type* pFoundDeserializer = nullptr;
		for (Type* pType : types)
		{
			//Get attribute
			const ResourceDeserializerAttribute* pAttribute = pType->GetAttribute<ResourceDeserializerAttribute>();
			if (pAttribute->GetResourceType() == descriptor.ResourceType)
			{
				pFoundDeserializer = pType;
				break;
			}
		}
		if (pFoundDeserializer == nullptr)
		{
			DEV_LOG("ResourceAPI", "No IResourceDeserializer found for the resource %s", descriptor.ResourceType);
			return nullptr;
		}

		//Create deserializer
		IResourceDeserializer* pDeserializer = (IResourceDeserializer*)pFoundDeserializer->CreateDefaultHeapObject();

		//Create resource
		SharedHeap<Resource> pResource = new Resource(descriptor,pDeserializer);
		pAPI->mResources.Add(pResource);

		return pResource;
	}
	void ResourceAPI::RemoveResource(const String& name)
	{
		//Get and validate API
		ResourceAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		//Search for the name
		for (UInt32 i = 0;i< pAPI->mResources.GetSize();i++)
		{
			const SharedHeap<Resource>& resource = pAPI->mResources[i];
			if (resource->GetName() == name)
			{
				resource.Shutdown();
				pAPI->mResources.RemoveAt(i);
				break;
			}
		}
	}
	void ResourceAPI::RemoveResource(const Guid& id)
	{
		//Get and validate API
		ResourceAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		//Search for the name
		for (UInt32 i = 0; i < pAPI->mResources.GetSize(); i++)
		{
			const SharedHeap<Resource>& resource = pAPI->mResources[i];
			if (resource->GetID() == id)
			{
				resource.Shutdown();
				pAPI->mResources.RemoveAt(i);
				break;
			}
		}
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
	ResourceAPI::ResourceAPI()
	{
		mResources.Reserve(1000);
	}
	ResourceAPI::~ResourceAPI()
	{
		for (const SharedHeap<Resource>& resource : mResources)
			resource.Shutdown();
	}
}
