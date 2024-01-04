#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	class MemoryOwnedView;

	/**
	 * @class MemoryView
	 * @brief Blob Storage implementation for Portakal Engine. It is used for storing huge media, large file backups, and data logs in a single file.
	 * It is also used for storing data in a single file for the Portakal Engine. It enables developers to build data lakes and data warehouses.
	 */
	class RUNTIME_API MemoryView final
	{
	public:
		MemoryView(void* pMemory, const UInt64 sizeInBytes) : mMemory(pMemory), mSize(sizeInBytes)
		{}

		MemoryView(const MemoryView& other);
		MemoryView(const MemoryOwnedView* pView);
		MemoryView();
		~MemoryView();

		FORCEINLINE void* GetMemory() const noexcept { return mMemory; }
		FORCEINLINE UInt64 GetSize() const noexcept { return mSize; }

	private:
		void* mMemory;
		UInt64 mSize;
	};
}
