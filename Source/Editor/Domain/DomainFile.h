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
		FORCEINLINE String GetDescriptorPath() const noexcept
		{
			return mPath;
		}
		FORCEINLINE String GetSourcePath() const noexcept
		{
			return mSourcePath;
		}
		FORCEINLINE TimeStamp GetLastChangeTime() noexcept;
	private:
		DomainFile(DomainFolder* pOwnerFolder,const String& path);
		~DomainFile() = default;

		void UpdateLastChangeTime();
		bool UpdateLastChangeTimeCheck();
		void Invalidate();
		virtual void OnShutdown() override;
	private:
		SharedHeap<Resource> mResource;
		DomainFolder* mOwnerFolder;
		IResourceDeserializer* mSerializer;
		String mPath;
		String mSourcePath;
		TimeStamp mLastChangeTime;
	};
}
