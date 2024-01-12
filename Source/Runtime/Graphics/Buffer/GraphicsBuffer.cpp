#include "GraphicsBuffer.h"

namespace Portakal
{
	GraphicsBuffer::GraphicsBuffer(const GraphicsBufferDesc& desc) : GraphicsMemoryObject(desc.pHeap),mUsages(desc.Usage),mSubItemCount(desc.SubItemCount),mSubItemSize(desc.SubItemSizeInBytes),mTotalSize(desc.SubItemCount*desc.SubItemSizeInBytes)
	{

	}
	void GraphicsBuffer::OnShutdown()
	{
		GraphicsMemoryObject::OnShutdown();
	}
}
