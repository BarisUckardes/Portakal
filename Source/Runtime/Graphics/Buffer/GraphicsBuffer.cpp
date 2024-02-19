#include "GraphicsBuffer.h"

namespace Portakal
{
	GraphicsBuffer::GraphicsBuffer(const GraphicsBufferDesc& desc) : mUsages(desc.Usage),mSubItemCount(desc.SubItemCount),mSubItemSize(desc.SubItemSizeInBytes),mTotalSize(desc.SubItemCount*desc.SubItemSizeInBytes),mHeap(desc.pHeap)
	{

	}
	void GraphicsBuffer::OnShutdown()
	{

	}
}
