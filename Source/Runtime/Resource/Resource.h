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
	/// <summary>
	/// Represents a single resource within the Runtime. These resources can represent anything. Texture, Audio, Font, Mesh or some other custom data
	/// </summary>
	class RUNTIME_API Resource : public Object
	{
		friend class ResourceAPI;
	public:
		static SharedHeap<Resource> Create(const ResourceDescriptor& descriptor);
	public:
		FORCEINLINE SharedHeap<ResourceSubObject> GetSubObject() const noexcept
		{
			return mSubObject;
		}
		FORCEINLINE MemoryView GetCachedData() const noexcept
		{
			return mCachedData;
		}
		FORCEINLINE String GetSourcePath() const noexcept
		{
			return mSourcePath;
		}
		FORCEINLINE String GetResourceType() const noexcept
		{
			return mType;
		}
		FORCEINLINE UInt64 GetFileOffset() const noexcept
		{
			return mFileOffset;
		}
		FORCEINLINE UInt64 GetFileSize() const noexcept
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
		void UnloadSync();
		void CacheSync();
		void FreeCacheSync();
		void SetMetaData(const String& metaData);
		virtual void OnShutdown() override;
	private:
		Resource(const ResourceDescriptor& descriptor,IResourceDeserializer* pDeserializer);
		~Resource();
	private:
		SharedHeap<ResourceSubObject> mSubObject;
		MemoryOwnedView* mCachedData;
		IResourceDeserializer* mDeserializer;
		String mSourcePath;
		String mType;
		UInt64 mFileOffset;
		UInt64 mFileSize;
		Bool8 mLoaded;
		Bool8 mCached;
		Bool8 mOptimized;
		String mMetaData;

	};
}
