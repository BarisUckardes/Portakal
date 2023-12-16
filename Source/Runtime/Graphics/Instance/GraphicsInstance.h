#pragma once
#include <Runtime/Graphics/Instance/GraphicsInstanceDesc.h>
#include <Runtime/Object/Object.h>

namespace Portakal
{
	class GraphicsAdapter;
	class RUNTIME_API GraphicsInstance : public Object
	{
		friend class SharedHeap<GraphicsInstance>;
	public:
		static SharedHeap<GraphicsInstance> Create(const GraphicsInstanceDesc& desc);
	public:
		FORCEINLINE Array<String> GetVulkanExtensions() const noexcept
		{
			return mVulkanExtensions;
		}
		FORCEINLINE GraphicsBackend GetBackend()const noexcept
		{
			return mBackend;
		}
		FORCEINLINE Array<SharedHeap<GraphicsAdapter>> GetAdapters() const noexcept
		{
			return mAdapters;
		}
	protected:
		GraphicsInstance(const GraphicsInstanceDesc& desc) : mVulkanExtensions(desc.VulkanExtensions), mBackend(desc.Backend)
		{

		}
		~GraphicsInstance() = default;

		void SetAdapters(const Array<SharedHeap<GraphicsAdapter>>& adapters);
	private:
		const Array<String> mVulkanExtensions;
		const GraphicsBackend mBackend;
		Array<SharedHeap<GraphicsAdapter>> mAdapters;
	};
}
