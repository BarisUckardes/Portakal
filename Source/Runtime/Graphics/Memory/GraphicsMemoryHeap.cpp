#include "GraphicsMemoryHeap.h"

namespace Portakal
{
    GraphicsMemoryHeap::GraphicsMemoryHeap(const GraphicsMemoryHeapDesc& desc) : mType(desc.Type),mSize(desc.SizeInBytes),mOccupiedSize(0)
    {
        //Add the first block
        mBlocks.Add({ false,desc.SizeInBytes });
    }
    MemoryHandle GraphicsMemoryHeap::Allocate(const UInt64 sizeInBytes)
    {
        //Check if it's active
        if (IsShutdown())
            return uint64_max;

        //Get root
        LinkedList<SubAllocationBlock>::Node* pNode = mBlocks.GetRoot();

        //Validate root
        if (pNode == nullptr)
        {
            DEV_LOG("GraphicsMemoryHeap", "Memory allocation chain root is empty!");
            return uint64_max;
        }

        UInt32 nodeIndex = 0;
        UInt64 offset = 0;
        Bool8 bFoundValidBlock = false;

        while (pNode != nullptr)
        {
            //Check if data is owned
            if (pNode->Data.bOwned)
            {
                nodeIndex++;
                offset += pNode->Data.SizeInBytes;
                pNode = pNode->Next;
                continue;
            }

            //Check if the requested size can fit into this block
            if (pNode->Data.SizeInBytes >= sizeInBytes)
            {
                bFoundValidBlock = true;
                break;
            }

            //Tick
            nodeIndex++;
            offset += pNode->Data.SizeInBytes;
            pNode = pNode->Next;
        }

        if (!bFoundValidBlock)
        {
            DEV_LOG("GraphicsMemoryHeap", "Failed to allocate the requested memory size");
            return uint64_max;
        }

        //Allocate implementation
        const MemoryHandle allocationHandle = AllocateCore(offset);
        const UInt64 remainingSize = pNode->Data.SizeInBytes - sizeInBytes;

        if (remainingSize == 0)
        {
            pNode->Data.bOwned = true;
        }
        else
        {
            pNode->Data.SizeInBytes = remainingSize;

            SubAllocationBlock newBlock = { true,sizeInBytes };
            mBlocks.Insert(newBlock, nodeIndex);
        }

        return allocationHandle;
    }
    void GraphicsMemoryHeap::Free(const MemoryHandle handle)
    {
        //Check if it's active
        if (IsShutdown())
            return;

        //Validate root
        LinkedList<SubAllocationBlock>::Node* pNode = mBlocks.GetRoot();
        if (pNode == nullptr)
        {
            DEV_LOG("GraphicsMemoryHeap", "Memory allocation chain root is empty!");
            return;
        }

        {
            //Find sub allocation block with the given offset
            UInt64 offset = 0;
            while (pNode != nullptr)
            {
                //Check
                if (offset == handle)
                    break;

                //Iterate
                offset += pNode->Data.SizeInBytes;
                pNode = pNode->Next;
            }
        }

        //Validate found sub allocation block
        if (pNode == nullptr)
        {
            DEV_LOG("GraphicsMemoryHeap", "Failed to find the block to free!");
            return;
        }

        //disown memory
        pNode->Data.bOwned = false;

        ////Do a compacting pass
        //LinkedList<SubAllocationBlock>::Node* pStartNode = mBlocks.GetRoot();
        //LinkedList<SubAllocationBlock>::Node* pEndNode = pStartNode->Next;
        //UInt32 freeBlockCount = 0;
        //UInt64 compactedBlockSize = 0;
        //while (pStartNode != nullptr)
        //{
        //    //Check if start node has a not owned memory block
        //    if (!pStartNode->Data.bOwned)
        //    {
        //        //Iterate and collect
        //        while (pEndNode != nullptr && !pEndNode->Data.bOwned)
        //        {
        //            //Get block size
        //            compactedBlockSize += pEndNode->Data.SizeInBytes;

        //            //Tick
        //            pEndNode = pEndNode->Next;
        //            freeBlockCount++;
        //        }

        //        //Check if there's a consecutive free blocks
        //        if (freeBlockCount > 1)
        //        {
        //            LinkedList<SubAllocationBlock>::Node* pTest = pStartNode->Next;
        //            while (pTest != pEndNode)
        //            {
        //                //Cache the next one
        //                LinkedList<SubAllocationBlock>::Node* pTemp = pTest->Next;

        //                //Delete the current one
        //                delete pTest;

        //                //Make the connections
        //                pTest = pTemp;
        //            }

        //            //Create new node
        //            LinkedList<SubAllocationBlock>::Node* pNewNode = new LinkedList<SubAllocationBlock>::Node();
        //            pNewNode->Data.bOwned = false;
        //            pNewNode->Data.SizeInBytes = compactedBlockSize;
        //            
        //            //Connect
        //            pNewNode->Next = pEndNode;
        //            pStartNode->Next = pNewNode;
        //        }
        //    }
        //  
        //    //Tick
        //    if (pStartNode == nullptr)
        //        break;

        //    pStartNode = pStartNode->Next;
        //    pEndNode = pStartNode->Next;
        //    freeBlockCount = 0;
        //    compactedBlockSize = 0;
        //}
    }
}
