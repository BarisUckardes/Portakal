#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Resource/Resource.h>
#include <Editor/Resource/IResourceSerializer.h>
#include <Runtime/Time/TimeStamp.h>

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
		FORCEINLINE Type* GetThumbnailType() const noexcept
		{
			return mThumbnailType;
		}
		FORCEINLINE Type* GetOpenActionType() const noexcept
		{
			return mOpenActionType;
		}

		void SaveSync();
		void LoadSync();
		void Delete();
		void WriteMeta(const String& meta);
		void Rename(const String& name);
	private:
		DomainFile(DomainFolder* pOwnerFolder, const String& resourceType,const String& name,const Guid& id,const String& descriptorPath,const String& sourcePath,IResourceSerializer* pSerializer,Type* pThumnailType,Type* openActionType);
		~DomainFile() = default;

		virtual void OnShutdown() override;
	private:
		SharedHeap<Resource> mResource;
		DomainFolder* mOwnerFolder;
		IResourceSerializer* mSerializer;
		Type* mThumbnailType;
		Type* mOpenActionType;
		String mDescriptorPath;
		String mSourcePath;
		String mMetaPath;
		TimeStamp mLastChangeTime;
	};
}
