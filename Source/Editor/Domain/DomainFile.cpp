#include "DomainFile.h"
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Yaml/Yaml.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Runtime/Resource/ResourceAPI.h>
#include <Editor/Resource/CustomResourceSerializer.h>
#include <Runtime/Platform/PlatformFile.h>

namespace Portakal
{
	
	void DomainFile::SaveSync()
	{

	}
	void DomainFile::LoadSnyc()
	{
		mResource->LoadSync();
	}

	void DomainFile::Delete()
	{
		if (IsShutdown())
			return;
	}

	DomainFile::DomainFile(DomainFolder* pOwnerFolder, const String& resourceType,const String& name, const Guid& id,const String& descriptorPath,const String& sourcePath,IResourceSerializer* pSerializer, Type* pThumnailType,Type* pOpenActionType) :
		mDescriptorPath(descriptorPath),mSourcePath(sourcePath), mOwnerFolder(pOwnerFolder), mSerializer(pSerializer),mThumbnailType(pThumnailType),mOpenActionType(pOpenActionType)
	{
		//Override name and id
		SetName(name);
		OverrideID(id);

		//Create resource
		ResourceDescriptor descriptor = {};
		descriptor.bOptimized = false;
		descriptor.FileOffset = 0;
		descriptor.FileSize = 0;
		descriptor.ID = id;
		descriptor.Name = name;
		descriptor.SourcePath = sourcePath;
		descriptor.ResourceType = resourceType;
		mResource = ResourceAPI::RegisterResource(descriptor);
		if (mResource.IsShutdown())
		{
			DEV_LOG("DomainFile", "Failed to create Runtime::Resource");
			return;
		}
	}

	void DomainFile::OnShutdown()
	{
		mResource.Shutdown();
	}
}
