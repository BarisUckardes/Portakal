#pragma once
#include <Runtime/Graphics/Instance/GraphicsInstanceDesc.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class GraphicsAdapter;
	class RUNTIME_API GraphicsInstance
	{
	public:
		static GraphicsInstance* Create(const GraphicsInstanceDesc* pDesc);
	public:
		~GraphicsInstance();

		FORCEINLINE GraphicsBackend GetBackend() const noexcept
		{
			return mBackend;
		}

		FORCEINLINE SharedHeap<GraphicsAdapter> GetAdapter(const Byte index)
		{
			if (index >= mAdapters.GetSize())
				return nullptr;

			return mAdapters[index];
		}

		FORCEINLINE const Array<SharedHeap<GraphicsAdapter>>& GetAdapters() const noexcept
		{
			return mAdapters;
		}
	protected:
		GraphicsInstance(const GraphicsInstanceDesc* pDesc);
		void SetAdapters(const Array<SharedHeap<GraphicsAdapter>>& adapters);
	private:
		const GraphicsBackend mBackend;
		Array<SharedHeap<GraphicsAdapter>> mAdapters;
	};
}
