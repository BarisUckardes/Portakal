#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Containers/String.h>

namespace Portakal
{
	class RUNTIME_API Resource final
	{
	public:

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
