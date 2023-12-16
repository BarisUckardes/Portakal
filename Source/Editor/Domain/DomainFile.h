#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Guid.h>

namespace Portakal
{
	class Resource;
	class DomainFolder;

	/**
	 * @class DomainFile
	 * @brief The File descriptor in the Editor's Content Browser.
	 */
	class EDITOR_API DomainFile
	{
	private:
		struct FileDescriptor
		{
			String FileName;
			String FileExtension;
			String ResourceType;
			uint64 FileSize;
			Resource* Resource;
			String LastModified;
			Guid ResourceID;
		};
	public:
		DomainFile(const String& pFileDescriptorPath, DomainFolder* pFolder);
		~DomainFile();

		FORCEINLINE DomainFolder* GetParentFolder() const noexcept { return mParentFolder; }
		FORCEINLINE Resource* GetResource() const noexcept { return mResource; }
		FORCEINLINE const String& GetFileDescriptorPath() const noexcept { return mFileDescriptorPath; }
		FORCEINLINE const String& GetSourceFilePath() const noexcept { return mSourceFilePath; }
		FORCEINLINE const String& GetFileName() const noexcept { return mFileName; }
		FORCEINLINE const String& GetResourceType() const noexcept { return mResourceType; }
		FORCEINLINE const Guid& GetResourceID() const noexcept { return mResourceID; }
		FORCEINLINE bool IsValid() const noexcept { return mIsValid; }

		void SetFileName(const String& pNewName);
		void MoveFileTo(DomainFolder* pFolder);
		void RenameFile(const String& pNewName);
		void DeleteFile();
		void CopyFileTo(DomainFolder* pFolder);

	private:
		DomainFolder* mParentFolder;
		Resource* mResource;
		String mFileDescriptorPath;
		String mSourceFilePath;
		String mFileName;
		String mFileExtension;
		uint64 mFileSize;
		String mResourceType;
		Guid mResourceID;
		bool mIsValid;
	};
}
