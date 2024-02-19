#include "DomainFile.h"
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Yaml/Yaml.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Runtime/Resource/ResourceAPI.h>
#include <Editor/Resource/CustomResourceSerializer.h>
#include <Runtime/Platform/PlatformFile.h>
#include <Editor/Domain/DomainFolder.h>
#include <Editor/Domain/DomainFileDescriptor.h>

namespace Portakal
{
	void DomainFile::SaveSync()
	{
		//Serialize to memory view
		MemoryOwnedView* pMemoryView = {};
		mSerializer->Serialize(this, mResource->GetSubObject().GetHeap(),&pMemoryView);

		//Write memory view
		if (!PlatformFile::Write(mSourcePath, pMemoryView))
			DEV_LOG("DomainFile", "Failed to save resource file");

		//Free memory
		if (pMemoryView != nullptr)
			delete pMemoryView;
	}
	void DomainFile::LoadSync()
	{
		mResource->LoadSync();
	}

	void DomainFile::Delete()
	{
		if (IsShutdown())
			return;
	}

	void DomainFile::WriteMeta(const String& meta)
	{
		//Validate meta path
		if (!PlatformFile::Exists(mMetaPath))
			PlatformFile::Create(mMetaPath);

		//Write yaml to meta
		if (!PlatformFile::Write(mMetaPath, meta))
			DEV_LOG("DomainFile", "Failed to write to meta");

		//Set resource meta
		mResource->SetMetaData(meta);
	}

	void DomainFile::Rename(const String& name)
	{
		//Rename source
		if (PlatformFile::Exists(mSourcePath))
		{
			const String path = (mSourcePath.GetSubset(0, mSourcePath.GetSize() - PlatformFile::GetName(mSourcePath).GetSize())) + name + PlatformFile::GetExtension(mSourcePath);
			PlatformFile::Rename(mSourcePath,path);
			mSourcePath = path;
		}

		//Rename descriptor
		if (PlatformFile::Exists(mDescriptorPath))
		{
			//Read descriptor
			String descriptorContent;
			PlatformFile::Read(mDescriptorPath, descriptorContent);

			//Convert yaml to descriptor
			DomainFileDescriptor descriptorOld = {};
			Yaml::ToObject<DomainFileDescriptor>(descriptorContent, &descriptorOld);

			//Create new descriptor
			DomainFileDescriptor descriptorNew = {};
			descriptorNew.ID = descriptorOld.ID;
			descriptorNew.Type = descriptorOld.Type;
			descriptorNew.Target = name + PlatformFile::GetExtension(descriptorOld.Target);

			//Write new descriptor
			const String newDescriptorYAML = Yaml::ToYaml<DomainFileDescriptor>(&descriptorNew);
			PlatformFile::Write(mDescriptorPath, newDescriptorYAML);

			//Rename
			String path = (mDescriptorPath.GetSubset(0, mDescriptorPath.GetSize() - PlatformFile::GetName(mDescriptorPath).GetSize())) + name + PlatformFile::GetExtension(mDescriptorPath);
			PlatformFile::Rename(mDescriptorPath, path);
			mDescriptorPath = path;
		}

		//Change name
		SetName(name);
		if (!mResource.IsShutdown())
			mResource->SetName(name);
	}

	SharedHeap<TextureResource> DomainFile::GetThumbnail()
	{
		return mThumbnail->GetThumbnailTexture(this);
	}
	void DomainFile::OpenFile()
	{
		//Abort if open action is nullptr
		if (mOpenAction == nullptr)
			return;

		mOpenAction->OnOpen(this);
	}


	DomainFile::DomainFile(DomainFolder* pOwnerFolder, const String& resourceType,const String& name, const Guid& id,const String& descriptorPath,const String& sourcePath,IResourceSerializer* pSerializer, Type* pThumnailType,Type* pOpenActionType) :
		mDescriptorPath(descriptorPath),mSourcePath(sourcePath), mOwnerFolder(pOwnerFolder), mSerializer(pSerializer),mThumbnail(nullptr),mOpenAction(nullptr)
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
		mResource = Resource::Create(descriptor);
		if (mResource.IsShutdown())
		{
			DEV_LOG("DomainFile", "Failed to create Runtime::Resource");
			return;
		}

		//Get meta data
		const String metaPath = mOwnerFolder->GetPath() + "\\" + GetName() + ".pmeta";
		mMetaPath = metaPath;

		//Try load meta data
		if (PlatformFile::Exists(metaPath))
		{
			String metaContent;
			if (!PlatformFile::Read(mMetaPath, metaContent))
				DEV_LOG("DomainFile", "Failed to write meta");

			mResource->SetMetaData(metaContent);
		}

		//Create thumbnail
		if(pThumnailType != nullptr)
			mThumbnail = (IThumbnail*)pThumnailType->CreateDefaultHeapObject();

		//Create open action
		if(pOpenActionType != nullptr)
			mOpenAction = (IFileOpenAction*)pOpenActionType->CreateDefaultHeapObject();
	}

	void DomainFile::_OnPreInvalidate()
	{
		if (mThumbnail != nullptr)
			delete mThumbnail;
		mThumbnail = nullptr;

		if (mOpenAction != nullptr)
			delete mOpenAction;
		mOpenAction = nullptr;
	}
	void DomainFile::_OnPostInvalidate()
	{
		//Look for the thumbnail
		Type* pFoundThumbnailType = nullptr;
		for (Type* pType : ReflectionAPI::GetSubTypes(typeof(IThumbnail)))
		{
			CustomThumbnail* pAttr = pType->GetAttribute<CustomThumbnail>();
			if (pAttr == nullptr)
				continue;

			if (pAttr->GetResourceType() == mResource->GetResourceType())
				continue;

			pFoundThumbnailType = pType;
		}

		//Look for the open action
		Type* pFoundOpenActionType = nullptr;
		for (Type* pType : ReflectionAPI::GetSubTypes(typeof(IThumbnail)))
		{
			CustomFileOpenAction* pAttr = pType->GetAttribute<CustomFileOpenAction>();
			if (pAttr == nullptr)
				continue;

			if (pAttr->GetResourceType() == mResource->GetResourceType())
				continue;

			pFoundOpenActionType = pType;
		}

		//Create thumbnail
		if (pFoundThumbnailType != nullptr)
			mThumbnail = (IThumbnail*)pFoundThumbnailType->CreateDefaultHeapObject();

		//Create open file action
		if (pFoundOpenActionType != nullptr)
			mOpenAction = (IFileOpenAction*)pFoundOpenActionType->CreateDefaultHeapObject();

	}
	void DomainFile::OnShutdown()
	{
		mResource.Shutdown();
	}
}
