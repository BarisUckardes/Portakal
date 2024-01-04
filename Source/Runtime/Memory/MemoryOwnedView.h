#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/**
	 * @class MemoryOwnedView
	 * @brief Owned version of the MemoryView. It will create a copy 
	 * of the target memory. The data will be freed when the instance 
	 * goes beyond scope.
	 */
	class RUNTIME_API MemoryOwnedView final
	{
	public:
		MemoryOwnedView(void* pMemory, const UInt64 sizeInBytes);
		MemoryOwnedView(void* pMemoryStart, void* pMemoryEnd);
		MemoryOwnedView(const MemoryOwnedView& other) = delete;
		~MemoryOwnedView();

		FORCEINLINE void* GetMemory() const noexcept { return mMemory; }
		FORCEINLINE UInt64 GetSize() const noexcept { return mSize; }

	private:
		void* mMemory;
		UInt64 mSize;
	};
}
