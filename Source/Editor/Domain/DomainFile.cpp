#include "DomainFile.h"
#include <Editor/Domain/DomainFolder.h>

#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Platform/PlatformMessage.h>

namespace Portakal
{
	DomainFile::DomainFile(const String& pFileDescriptorPath, DomainFolder* pFolder) : mFileDescriptorPath(pFileDescriptorPath),
		mParentFolder(pFolder), mResource(nullptr), mIsValid(false)
	{
		// Check if the file exists
		if (!PlatformFile::DoesExist(pFileDescriptorPath))
		{
			PlatformMessage::ShowMessageBox("File not found", "The file " + pFileDescriptorPath + " does not exist.");
			return;
		}
		else
			mIsValid = true;

		// Get the file name
		mFileName = PlatformFile::GetNameWithoutExtension(pFileDescriptorPath);

		// Get the file extension
		mFileExtension = PlatformFile::GetExtension(pFileDescriptorPath);

		// Get the file size
		PlatformFile::GetSize(pFileDescriptorPath, mFileSize);

		// Get the file last write time
		//PlatformFile::GetLastWriteTime(pFileDescriptorPath, mLastWriteTime);

		// Get the file resource
		// ????
	}

	DomainFile::~DomainFile()
	{
		delete mResource;
		mResource = nullptr;
	}
}
