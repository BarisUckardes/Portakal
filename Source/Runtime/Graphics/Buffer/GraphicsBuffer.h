#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Buffer/GraphicsBufferDesc.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryObject.h>

namespace Portakal
{
	class RUNTIME_API GraphicsBuffer :public GraphicsMemoryObject
	{
	public:
		GraphicsBuffer(const GraphicsBufferDesc& desc);
		~GraphicsBuffer() = default;

		FORCEINLINE GraphicsBufferUsage GetUsages() const noexcept
		{
			return mUsages;
		}
		FORCEINLINE Uint32 GetSubItemCount() const noexcept
		{
			return mSubItemCount;
		}
		FORCEINLINE Uint32 GetSubItemSize() const noexcept
		{
			return mSubItemSize;
		}
		FORCEINLINE Uint64 GetTotalSize() const noexcept
		{
			return mTotalSize;
		}
		
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::Buffer;
		}

	protected:
		virtual void OnShutdown() override;
	private:
		const GraphicsBufferUsage mUsages;
		const Uint32 mSubItemCount;
		const Uint32 mSubItemSize;
		const Uint64 mTotalSize;
	};
}
