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
			if (!PlatformFile::Read(mSourcePath, memory, mFileOffset, mFileSize))
			{
				DEV_LOG("Resource", "Failed to load the file");
				return;
			}
		}

		//Deserialize
		mSubObject = mOptimized ? mDeserializer->DeserializeOptimized(memory,mMetaData) : mDeserializer->Deserialize(memory,mMetaData);
		mSubObject->_SetOwnerResource(this);
		mSubObject->SetName(GetName());
		mSubObject->OverrideID(GetID());
		mLoaded = true;
		DEV_LOG("Resource", "Loaded resource %s", *GetName());
	}
	
	void Resource::UnloadSync()
	{
		//Abort if not loaded at all
		if (!mLoaded)
			return;

		//Shutdown resource sub object
		mSubObject.Shutdown();
	}
	
	void Resource::CacheSync()
	{
		//Check if already cached
		if (mCached)
			return;

		//Load the data from the dis
		MemoryView memory;
		if (!PlatformFile::Read(mSourcePath, memory, mFileOffset, mFileSize))
		{
			DEV_LOG("Resource", "Failed to load the cached data from the file");
			return;
		}
		mCachedData = new MemoryOwnedView(memory.GetMemory(),memory.GetSize());
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

	void Resource::SetMetaData(const String& metaData)
	{
		mMetaData = metaData;
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
		mSourcePath(descriptor.SourcePath), mType(descriptor.ResourceType), mFileOffset(descriptor.FileOffset), mFileSize(descriptor.FileSize), mOptimized(descriptor.bOptimized),mDeserializer(pDeserializer),
		mCached(false), mLoaded(false), mCachedData(nullptr)
	{
		//Find resource deserializer
		OverrideID(descriptor.ID);
		SetName(descriptor.Name);
	}
	Resource::~Resource()
	{
	}
}
