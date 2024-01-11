#include "DomainFile.h"
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Yaml/Yaml.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Runtime/Resource/ResourceAPI.h>
#include <Editor/Resource/ResourceSerializerAttribute.h>
#include <Runtime/Platform/PlatformFile.h>

namespace Portakal
{
	TimeStamp DomainFile::GetLastChangeTime() noexcept
	{
		//Update last change
		UpdateLastChangeTime();

		return mLastChangeTime;
	}
	void DomainFile::SaveSync()
	{

	}
	void DomainFile::LoadSnyc()
	{

	}

	void DomainFile::Delete()
	{
		if (IsShutdown())
			return;
	}

	DomainFile::DomainFile(DomainFolder* pOwnerFolder,const String& path) : mPath(path),mOwnerFolder(pOwnerFolder),mSerializer(nullptr)
	{
		//Set properties
		mPath = path;

		//Refresh files
		RefreshFiles();

		//Find serializer type
		Type* pSerializerType = FindSerializer(mResource->GetResourceType());
		if (pSerializerType != nullptr)
			mSerializer = (IResourceSerializer*)pSerializerType->CreateDefaultHeapObject();
	}
	void DomainFile::UpdateLastChangeTime()
	{
		PlatformFile::GetFileLastChangeTime(mSourcePath, mLastChangeTime);
	}
	bool DomainFile::UpdateLastChangeTimeCheck()
	{
		const TimeStamp temp = mLastChangeTime;
		UpdateLastChangeTime();
		return temp != mLastChangeTime;
	}
	void DomainFile::Invalidate()
	{
		//Shutdown unload resource
		mResource.Shutdown();

		//Refresh file
		RefreshFiles();

		//Refresh serializer
		if (mSerializer != nullptr)
			delete mSerializer;
		mSerializer = nullptr;

		Type* pSerializerType = FindSerializer(mResource->GetResourceType());
		if (pSerializerType != nullptr)
			mSerializer = (IResourceSerializer*)pSerializerType->CreateDefaultHeapObject();
	}
	Type* DomainFile::FindSerializer(const String& target)
	{
		//Find the serializer type
		Array<Type*> serializerTypes = ReflectionAPI::GetSubTypes(typeof(IResourceSerializer));
		Type* pFoundSerializerType = nullptr;
		for (Type* pType : serializerTypes)
		{
			ResourceSerializerAttribute* pAttribute = pType->GetAttribute<ResourceSerializerAttribute>();
			if (pAttribute == nullptr)
				continue;
			if (pAttribute->GetResourceType() != target)
				continue;

			pFoundSerializerType = pType;
			break;
		}

		//Validate if serializer is found
		if (pFoundSerializerType == nullptr)
		{
			DEV_LOG("DomainFile", "Failed to find any suitable IResourceDeserializer for %s", target);
			return nullptr;
		}

		return pFoundSerializerType;
	}
	void DomainFile::RefreshFiles()
	{
		//Read descriptor file
		String descriptorFileContent;
		if (!PlatformFile::Read(mPath, descriptorFileContent))
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

		//Create resource
		mResource = ResourceAPI::RegisterResource(mPath);

		//Get last change time
		PlatformFile::GetFileLastChangeTime(mSourcePath, mLastChangeTime);

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
