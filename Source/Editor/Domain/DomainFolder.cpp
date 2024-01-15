#include "DomainFolder.h"
#include <Runtime/Platform/PlatformDirectory.h>
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Editor/Resource/CustomResourceSerializer.h>
#include <Editor/Domain/DomainFile.h>
#include <Editor/Domain/DomainFileDescriptor.h>
#include <Editor/GUI/IThumbnail.h>
#include <Runtime/Yaml/Yaml.h>
#include <Editor/GUI/CustomThumbnail.h>

namespace Portakal
{
	SharedHeap<DomainFolder> DomainFolder::CreateFolder(const String& name)
	{
		//Check if folder already exists
		const String folderPath = mPath + "\\" + name;
		if (PlatformDirectory::Exists(folderPath))
		{
			DEV_LOG("DomainFolder", "This folder already exists!");
			return nullptr;
		}

		//Create physical aspect
		if (!PlatformDirectory::Create(folderPath))
		{
			DEV_LOG("DomainFolder", "Failed to create the folder");
			return nullptr;
		}

		//Create domain folder
		SharedHeap<DomainFolder> pFolder = new DomainFolder(this, folderPath);

		//Register
		mFolders.Add(pFolder);

		return pFolder;
	}
	SharedHeap<DomainFile> DomainFolder::ImportExternalFile(const String& outerPath)
	{
		//Get the extension
		const String name = PlatformFile::GetName(outerPath);
		const String nameWExtension = PlatformFile::GetNameWithoutExtension(outerPath);
		const String extension = PlatformFile::GetExtension(outerPath);
		const String descriptorPath = mPath + "\\" + nameWExtension + ".pfd";
		const String sourceFilePath = mPath + "\\" + name;

		//Check path
		if (PlatformFile::Exists(descriptorPath))
		{
			DEV_LOG("DomainFolder", "Descriptor file already exists for: %s", *descriptorPath);
			return nullptr;
		}

		//Find some serializers with this extension
		const Array<Type*> subTypes = ReflectionAPI::GetSubTypes(typeof(IResourceSerializer));
		Type* pSelectedType = nullptr;
		String selectedResourceType;
		for (Type* pType : subTypes)
		{
			//Get attribute
			CustomResourceSerializer* pAttribute = pType->GetAttribute<CustomResourceSerializer>();
			if (pAttribute == nullptr)
				continue;

			//Check if resource extensions matches
			const Array<String> extensions = pAttribute->GetImportExtensions();
			if (extensions.Has(extension))
			{
				pSelectedType = pType;
				selectedResourceType = pAttribute->GetResourceType();
				break;
			}
		}

		//Check if selected a type
		if (pSelectedType == nullptr)
			return nullptr;

		//Find thumbnail type
		Type* pThumbnailType = GetThumbnailType(selectedResourceType);

		//Create file descriptor
		DomainFileDescriptor descriptor = {};
		descriptor.ID = Guid::Create();
		descriptor.Type = selectedResourceType;
		descriptor.Target = name;

		const String descriptorYamlString = Yaml::ToYaml<DomainFileDescriptor>(&descriptor);
		if (!PlatformFile::Create(descriptorPath))
		{
			DEV_LOG("DomainFolder", "Failed to create %s DomainFile", *descriptorPath);
			return nullptr;
		}
		if (!PlatformFile::Write(descriptorPath, descriptorYamlString))
		{
			DEV_LOG("DomainFolder", "Failed to write to %s", *descriptorPath);
			PlatformFile::Delete(descriptorPath);
			return nullptr;
		}

		//Copy the target file
		if (!PlatformFile::Copy(outerPath, sourceFilePath))
		{
			DEV_LOG("DomainFolder", "Failed to copy for import! %s",*descriptorPath);
			PlatformFile::Delete(descriptorPath);
			return nullptr;
		}

		//Create serializer
		IResourceSerializer* pSerializer = (IResourceSerializer*)pSelectedType->CreateDefaultHeapObject();

		
		//Create domain file
		SharedHeap<DomainFile> pFile = new DomainFile(this,selectedResourceType,nameWExtension,descriptor.ID,descriptorPath,sourceFilePath,pSerializer, pThumbnailType);
		pFile->SetName(nameWExtension);
		pFile->OverrideID(descriptor.ID);

		mFiles.Add(pFile);

		return pFile;
	}
	bool DomainFolder::CheckIfFileExistsViaName(const String& name)
	{
		for (const SharedHeap<DomainFile>& pFile : mFiles)
			if (pFile->GetName() == name)
				return true;
		return false;
	}
	bool DomainFolder::CheckIfDescriptorExists(const String& descriptorPath)
	{
		for (const SharedHeap<DomainFile>& pFile : mFiles)
			if (pFile->GetDescriptorPath() == descriptorPath)
				return true;
		return false;
	}
	void DomainFolder::Delete()
	{
		if (IsShutdown())
			return;

		//Delete the physical aspect of the folder
		if (!PlatformDirectory::Delete(mPath))
		{
			DEV_LOG("DomainFolder", "Failed to delete the folder!");
			return;
		}

		//Shutdown
		Shutdown();
	}
	DomainFolder::DomainFolder(DomainFolder* pOwnerFolder, const String& path) : mOwnerFolder(pOwnerFolder),mPath(path)
	{
		//Set name
		const String name = PlatformDirectory::GetName(path);
		SetName(name);
		DEV_LOG("DomainFolder", "Found folder: %s", *path);

		//Search for files
		Array<String> files;
		PlatformDirectory::GetFileNamesViaExtension(path + "\\",".pfd",files);
		for (const String& file : files)
			ImportExistingFile(file);

		//Search for folders
		Array<String> folders;
		PlatformDirectory::GetFolderNames(path + "\\", folders);
		for (const String& folderPath : folders)
			mFolders.Add(new DomainFolder(this, folderPath));
	}
	
	void DomainFolder::ImportExistingFile(const String& descriptorPath)
	{
		//Check if this descriptor file is already registered
		if (CheckIfDescriptorExists(descriptorPath))
			return;

		//Load descriptor file
		String fileContent;
		if (!PlatformFile::Read(descriptorPath, fileContent))
		{
			DEV_LOG("DomainFolder", "Failed to reimport %s", descriptorPath);
			return;
		}

		DomainFileDescriptor descriptor;
		Yaml::ToObject<DomainFileDescriptor>(fileContent, &descriptor);

		//Check if source file exists
		const String sourcePath = mPath + "\\" + descriptor.Target;
		if (!PlatformFile::Exists(sourcePath))
		{
			DEV_LOG("DomainFolder", "Cannot reimport since source file does not exists");
			PlatformFile::Delete(descriptorPath);
			return;
		}

		//Get serializer type
		Type* pSerializerType = GetSerializerType(descriptor.Type);
		if (pSerializerType == nullptr)
		{
			DEV_LOG("DomainFolder", "Cannot reimport since serializer implementation for resource type %s was absent", descriptor.Type);
			return;
		}

		//Find thumbnail type
		Type* pThumbnailType = GetThumbnailType(descriptor.Type);

		//Register DomainFile
		SharedHeap<DomainFile> pFile = new DomainFile(this,descriptor.Type,PlatformFile::GetNameWithoutExtension(descriptor.Target),descriptor.ID, descriptorPath, sourcePath, (IResourceSerializer*)pSerializerType->CreateDefaultHeapObject(),pThumbnailType);
		pFile->SetName(PlatformFile::GetNameWithoutExtension(descriptorPath));
		pFile->OverrideID(descriptor.ID);
		mFiles.Add(pFile);
	}

	Type* DomainFolder::GetSerializerType(const String& resourceType)
	{
		const Array<Type*> subTypes = ReflectionAPI::GetSubTypes(typeof(IResourceSerializer));
		for (Type* pType : subTypes)
		{
			//Get attribute
			CustomResourceSerializer* pAttribute = pType->GetAttribute<CustomResourceSerializer>();
			if (pAttribute == nullptr)
				continue;

			//Check type
			if (pAttribute->GetResourceType() == resourceType)
				return pType;
		}

		return nullptr;
	}

	Type* DomainFolder::GetThumbnailType(const String& resourceType)
	{
		//Find thumbnail type
		const Array<Type*> thumbnailTypes = ReflectionAPI::GetSubTypes(typeof(IThumbnail));
		for (Type* pType : thumbnailTypes)
		{
			//Get attribute
			CustomThumbnail* pAttribute = pType->GetAttribute<CustomThumbnail>();
			if (pAttribute == nullptr)
				continue;

			if (pAttribute->GetResourceType() == resourceType)
				return pType;
		}

		return nullptr;
	}

	void DomainFolder::_OnSubFolderDeleted(const DomainFolder* pTargetFolder)
	{
		mFolders.Remove(pTargetFolder);
	}

	void DomainFolder::_OnSubFileDeleted(const DomainFile* pFile)
	{
		mFiles.Remove(pFile);
	}

	void DomainFolder::OnShutdown()
	{
		//First notify the owner folder that this folder is removed
		if (mOwnerFolder != nullptr)
		{
			mOwnerFolder->_OnSubFolderDeleted(this);
		}

		//Shutdown files
		for (SharedHeap<DomainFile>& pFile : mFiles)
			pFile.Shutdown();

		//Shutdown folders
		for (SharedHeap<DomainFolder>& pFolder : mFolders)
			pFolder.Shutdown();

		mFolders.Clear();
	}
}
