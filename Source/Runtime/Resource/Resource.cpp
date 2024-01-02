#include "Resource.h"
#include <Runtime/Platform/PlatformFile.h>

namespace Portakal
{
	void Resource::LoadSync()
	{
		//Abort if loaded
		if (mLoaded)
			return;

		//Get memory view
		MemoryView memory = {};
		if (mCached)
		{
			memory = mCachedData;
		}
		else
		{
			if (!PlatformFile::Read(mPath, memory, mFileOffset, mFileSize))
			{
				DEV_LOG("Resource", "Failed to load the file");
				return;
			}
		}

		//Deserialize
		mSubObject = mOptimized ? mDeserializer->DeserializeOptimized(memory) : mDeserializer->Deserialize(memory);
		mSubObject->_SetOwnerResource(this);
	}
	void Resource::LoadAsync()
	{

	}
	void Resource::UnloadSync()
	{
		//Abort if not loaded at all
		if (!mLoaded)
			return;

		//Shutdown resource sub object
		mSubObject.Shutdown();
	}
	void Resource::UnloadAsync()
	{

	}
	void Resource::CacheSync()
	{
		//Check if already cached
		if (mCached)
			return;

		//Load the data from the dis
		MemoryView memory;
		if (!PlatformFile::Read(mPath, memory, mFileOffset, mFileSize))
		{
			DEV_LOG("Resource", "Failed to load the cached data from the file");
			return;
		}
		mCachedData = new MemoryOwnedView(memory.GetMemory(),memory.GetSize());
	}
	void Resource::CacheAsync()
	{

	}
	void Resource::FreeCacheSync()
	{
		//Check if have cache
		if (!mCached)
			return;

		//Check if cache is valid
		if (mCachedData == nullptr)
			return;

		delete mCachedData;
		mCachedData = nullptr;
	}
	void Resource::FreeCacheAsync()
	{

	}
	void Resource::OnShutdown()
	{
		//Unload sync
		FreeCacheSync();
		UnloadSync();

		//Clear deserializer
		delete mDeserializer;
		mDeserializer = nullptr;
	}
	Resource::Resource(const ResourceDescriptor& descriptor,IResourceDeserializer* pDeserializer) :
		mID(descriptor.ID), mName(descriptor.Name), mPath(descriptor.Name), mType(descriptor.ResourceType), mFileOffset(descriptor.FileOffset), mFileSize(descriptor.FileSize), mOptimized(descriptor.bOptimized),mDeserializer(pDeserializer),
		mCached(false), mLoaded(false), mCachedData(nullptr)
	{
		//Find resource deserializer

	}
	Resource::~Resource()
	{
	}
}
