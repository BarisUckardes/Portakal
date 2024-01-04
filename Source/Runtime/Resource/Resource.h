#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Resource/ResourceSubObject.h>
#include <Runtime/Memory/MemoryOwnedView.h>
#include <Runtime/Memory/MemoryView.h>
#include <Runtime/Resource/ResourceDescriptor.h>
#include <Runtime/Resource/IResourceDeserializer.h>

namespace Portakal
{
	class RUNTIME_API Resource : public Object
	{
		friend class ResourceAPI;
	public:
		FORCEINLINE SharedHeap<ResourceSubObject> GetSubObject() const noexcept
		{
			return mSubObject;
		}
		FORCEINLINE MemoryView GetCachedData() const noexcept
		{
			return mCachedData;
		}
		FORCEINLINE String GetPath() const noexcept
		{
			return mPath;
		}
		FORCEINLINE String GetResourceType() const noexcept
		{
			return mType;
		}
		FORCEINLINE Uint64 GetFileOffset() const noexcept
		{
			return mFileOffset;
		}
		FORCEINLINE Uint64 GetFileSize() const noexcept
		{
			return mFileSize;
		}
		FORCEINLINE Bool8 IsLoaded() const noexcept
		{
			return mLoaded;
		}
		FORCEINLINE Bool8 IsCached() const noexcept
		{
			return mCached;
		}
		FORCEINLINE Bool8 IsOptimized() const noexcept
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
		virtual void OnShutdown() override;
	private:
		Resource(const ResourceDescriptor& descriptor,IResourceDeserializer* pDeserializer);
		~Resource();
	private:
		SharedHeap<ResourceSubObject> mSubObject;
		MemoryOwnedView* mCachedData;
		IResourceDeserializer* mDeserializer;
		String mPath;
		String mType;
		Uint64 mFileOffset;
		Uint64 mFileSize;
		Bool8 mLoaded;
		Bool8 mCached;
		Bool8 mOptimized;
	};
}
