#include "DomainFile.h"
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Yaml/Yaml.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Runtime/Resource/ResourceAPI.h>
#include <Editor/Resource/ResourceSerializerAttribute.h>

namespace Portakal
{
	DomainFile::DomainFile(DomainFolder* pOwnerFolder,const String& path) : mPath(path),mOwnerFolder(pOwnerFolder)
	{
		//Read descriptor file
		String descriptorFileContent;
		if (!PlatformFile::Read(path, descriptorFileContent))
		{
			DEV_LOG("DomainFile", "Could not read the descriptor file");
			return;
		}

		//Get the object from yaml
		ResourceDescriptor descriptor = {};
		Yaml::ToObject<ResourceDescriptor>(descriptorFileContent, &descriptor);

		//Validate descriptor
		if (descriptor.Name == "" || descriptor.ID == Guid::Zero())
		{
			DEV_LOG("DomainFile", "Invalid descriptor name or id");
			return;
		}
		if (!PlatformFile::Exists(descriptor.Path))
		{
			DEV_LOG("DomainFile", "File specified inside the descriptor file is invalid");
			return;
		}

		//Find the serializer type
		Array<Type*> serializerTypes;
		Type* pFoundSerializerType = nullptr;
		ReflectionAPI::GetSubTypes(typeof(IResourceSerializer));
		for (Type* pType : serializerTypes)
		{
			ResourceSerializerAttribute* pAttribute = pType->GetAttribute<ResourceSerializerAttribute>();
			if (pAttribute == nullptr)
				continue;
			if (pAttribute->GetResourceType() != descriptor.ResourceType)
				continue;

			pFoundSerializerType = pType;
			break;
		}

		//Validate if serializer is found
		if (pFoundSerializerType == nullptr)
		{
			DEV_LOG("DomainFile", "Failed to find any suitable IResourceDeserializer for %s", descriptor.ResourceType);
		}

		//Create resource
		mResource = ResourceAPI::RegisterResource(path);

		//Set properties
		mSourcePath = descriptor.Path;
		SetName(descriptor.Name);
		OverrideID(descriptor.ID);
	}
	void DomainFile::OnShutdown()
	{
		mResource.Shutdown();
	}
}
