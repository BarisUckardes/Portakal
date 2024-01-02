#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Resource/ResourceSubObject.h>
#include <Runtime/Memory/MemoryOwnedView.h>
#include <Runtime/Memory/MemoryView.h>
#include <Runtime/Resource/ResourceDescriptor.h>

namespace Portakal
{
	class RUNTIME_API Resource final
	{
	public:
		FORCEINLINE SharedHeap<ResourceSubObject> GetSubObject() const noexcept
		{
			return mSubObject;
		}
		FORCEINLINE MemoryView GetCachedData() const noexcept
		{
			return mCachedData;
		}
		FORCEINLINE Guid GetID() const noexcept
		{
			return mID;
		}
		FORCEINLINE String GetPath() const noexcept
		{
			return mPath;
		}
		FORCEINLINE String GetName() const noexcept
		{
			return mName;
		}
		FORCEINLINE String GetResourceType() const noexcept
		{
			return mType;
		}
		FORCEINLINE uint64 GetFileOffset() const noexcept
		{
			return mFileOffset;
		}
		FORCEINLINE uint64 GetFileSize() const noexcept
		{
			return mFileSize;
		}
		FORCEINLINE bool IsLoaded() const noexcept
		{
			return mLoaded;
		}
		FORCEINLINE bool IsCached() const noexcept
		{
			return mCached;
		}
		FORCEINLINE bool IsOptimized() const noexcept
		{
			return mOptimized;
		}

		void LoadSync();
		void LoadAsync();
		void UnloadSync();
		void UnloadAsync();
		void CacheSync();
		void CacheAsync();
		void FreeCacheSync();
		void FreeCacheAsync();
	private:
		Resource(const ResourceDescriptor& descriptor);
		~Resource();
	private:
		SharedHeap<ResourceSubObject> mSubObject;
		MemoryOwnedView* mCachedData;
		Guid mID;
		String mName;
		String mPath;
		String mType;
		uint64 mFileOffset;
		uint64 mFileSize;
		bool mLoaded;
		bool mCached;
		bool mOptimized;
	};
}
