#include "ResourceAPI.h"
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Yaml/Yaml.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Runtime/Resource/IResourceDeserializer.h>
#include <Runtime/Resource/ResourceDeserializerAttribute.h>

namespace Portakal
{
	void ResourceAPI::RegisterResource(const String& descriptorPath)
	{
		//Check API
		ResourceAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
		{
			DEV_LOG("ResourceAPI", "No resource API found!");
			return;
		}

		//Check file if exists
		if (!PlatformFile::Exists(descriptorPath))
		{
			DEV_LOG("ResourceAPI", "Given descriptor file path does not exist");
			return;
		}

		//Load descriptor
		String fileContent;
		if (!PlatformFile::Read(descriptorPath, fileContent))
		{
			DEV_LOG("ResourceAPI", "Failed to load the given descriptor file");
			return;
		}

		//Convert descriptor
		ResourceDescriptor descriptor = {};
		Yaml::ToObject<ResourceDescriptor>(fileContent,&descriptor);

		//Check resource name and id
		if (descriptor.Name == "" || descriptor.ID == Guid::Zero())
		{
			DEV_LOG("ResourceAPI", "Descriptor name or ID is invalid!");
			return;
		}

		//Check resource file path
		if (!PlatformFile::Exists(descriptor.Path))
		{
			DEV_LOG("ResourceAPI", "Given resource descriptor does not point to a valid resource!");
			return;
		}

		//Check resource type
		const Array<Type*> types = ReflectionAPI::GetSubTypes(typeof(IResourceDeserializer));
		if (types.IsEmpty())
		{
			DEV_LOG("ResourceAPI", "No IResourceDeserializer in this application!");
			return;
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
			return;
		}

		//Create deserializer
		IResourceDeserializer* pDeserializer = (IResourceDeserializer*)pFoundDeserializer->CreateDefaultHeapObject();

		//Create resource
		Resource* pResource = new Resource(descriptor,pDeserializer);
		pAPI->mResources.Add(pResource);
	}
	void ResourceAPI::RemoveResource(const String& name)
	{
	}
	void ResourceAPI::RemoveResource(const Guid& id)
	{
	}
	SharedHeap<Resource> ResourceAPI::GetResource(const String& name)
	{
		return SharedHeap<Resource>();
	}
	SharedHeap<Resource> ResourceAPI::GetResource(const Guid& id)
	{
		return SharedHeap<Resource>();
	}
	ResourceAPI::ResourceAPI()
	{
		mResources.Reserve(1000);
	}
	ResourceAPI::~ResourceAPI()
	{
	}
}
