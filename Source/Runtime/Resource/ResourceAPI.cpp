#include "ResourceAPI.h"
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Yaml/Yaml.h>

namespace Portakal
{
	void ResourceAPI::RegisterResource(const String& descriptorPath)
	{
		//Check API
		ResourceAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		//Check file if exists
		if (!PlatformFile::Exists(descriptorPath))
			return;

		//Load descriptor
		String fileContent;
		if (!PlatformFile::Read(descriptorPath, fileContent))
			return;

		//Convert descriptor
		ResourceDescriptor descriptor = {};
		Yaml::ToObject<ResourceDescriptor>(fileContent,&descriptor);

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
