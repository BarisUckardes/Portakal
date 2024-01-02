#include "Resource.h"

namespace Portakal
{
	void Resource::LoadSync()
	{

	}
	void Resource::LoadAsync()
	{

	}
	void Resource::UnloadSync()
	{

	}
	void Resource::UnloadAsync()
	{

	}
	void Resource::CacheSync()
	{

	}
	void Resource::CacheAsync()
	{

	}
	void Resource::FreeCacheSync()
	{

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
