#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Buffer/GraphicsBufferDesc.h>

namespace Portakal
{
	class RUNTIME_API GraphicsBuffer :public GraphicsDeviceObject
	{
	public:
		GraphicsBuffer(const GraphicsBufferDesc& desc,GraphicsDevice* pDevice);
		~GraphicsBuffer() = default;

		FORCEINLINE GraphicsBufferUsage GetUsages() const noexcept
		{
			return mUsages;
		}
		FORCEINLINE UInt32 GetSubItemCount() const noexcept
		{
			return mSubItemCount;
		}
		FORCEINLINE UInt32 GetSubItemSize() const noexcept
		{
			return mSubItemSize;
		}
		FORCEINLINE UInt64 GetTotalSize() const noexcept
		{
			return mTotalSize;
		}
		FORCEINLINE SharedHeap<GraphicsMemory> GetMemory() const noexcept
		{
			return mHeap;
		}
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::Buffer;
		}

	protected:
		virtual void OnShutdown() override;
	private:
		const GraphicsBufferUsage mUsages;
		const UInt32 mSubItemCount;
		const UInt32 mSubItemSize;
		const UInt64 mTotalSize;
		SharedHeap<GraphicsMemory> mHeap;
	};
}
