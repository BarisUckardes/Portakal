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
			return mPath;
		}
		FORCEINLINE String GetSourcePath() const noexcept
		{
			return mSourcePath;
		}

		FORCEINLINE TimeStamp GetLastChangeTime() noexcept;

		void SaveSync();
		void SaveAsync();
		void LoadSnyc();
		void LoadAsync();
		void Delete();
	private:
		DomainFile(DomainFolder* pOwnerFolder,const String& path);
		~DomainFile() = default;

		void UpdateLastChangeTime();
		bool UpdateLastChangeTimeCheck();
		void Invalidate();
		Type* FindSerializer(const String& target);
		void RefreshFiles();
		virtual void OnShutdown() override;
	private:
		SharedHeap<Resource> mResource;
		DomainFolder* mOwnerFolder;
		IResourceSerializer* mSerializer;
		String mPath;
		String mSourcePath;
		TimeStamp mLastChangeTime;
	};
}
