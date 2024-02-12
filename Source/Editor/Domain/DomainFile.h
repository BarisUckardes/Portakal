#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Resource/Resource.h>
#include <Editor/Resource/IResourceSerializer.h>
#include <Runtime/Time/TimeStamp.h>
#include <Editor/GUI/Thumbnail/IThumbnail.h>
#include <Editor/GUI/OpenAction/IFileOpenAction.h>

namespace Portakal
{
	class DomainFolder;
	class EDITOR_API DomainFile : public Object
	{
		friend class DomainFolder;
	public:
		FORCEINLINE SharedHeap<ResourceSubObject> GetSubObject() const noexcept
		{
			return mResource->GetSubObject();
		}
		FORCEINLINE String GetDescriptorPath() const noexcept
		{
			return mDescriptorPath;
		}
		FORCEINLINE String GetSourcePath() const noexcept
		{
			return mSourcePath;
		}


		void SaveSync();
		void LoadSync();
		void Delete();
		void WriteMeta(const String& meta);
		void Rename(const String& name);
		SharedHeap<TextureResource> GetThumbnail();
		void OpenFile();
	private:
		DomainFile(DomainFolder* pOwnerFolder, const String& resourceType,const String& name,const Guid& id,const String& descriptorPath,const String& sourcePath,IResourceSerializer* pSerializer,Type* pThumnailType,Type* openActionType);
		~DomainFile() = default;

		void _OnPreInvalidate();
		void _OnPostInvalidate();

		virtual void OnShutdown() override;
	private:
		SharedHeap<Resource> mResource;
		DomainFolder* mOwnerFolder;
		IResourceSerializer* mSerializer;
		IThumbnail* mThumbnail;
		IFileOpenAction* mOpenAction;
		String mDescriptorPath;
		String mSourcePath;
		String mMetaPath;
		TimeStamp mLastChangeTime;
	};
}
