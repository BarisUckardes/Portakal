#include "GraphicsMemoryHeap.h"

namespace Portakal
{
    GraphicsMemoryHeap::GraphicsMemoryHeap(const GraphicsMemoryHeapDesc& desc) : mType(desc.Type),mSize(desc.SizeInBytes),mOccupiedSize(0)
    {
        //Create block
        SubAllocationBlock initialBlock = {};
        initialBlock.bOwned = false;
        initialBlock.SizeInBytes = desc.SizeInBytes;
        mBlocks.Add(initialBlock);
    }
    UInt64 GraphicsMemoryHeap::Allocate(const UInt64 sizeInBytes)
    {
        //Check enough space is left
        const UInt64 sizeLeft = mSize - mOccupiedSize;
        if (sizeLeft < sizeInBytes)
            return uint64_max;

        //Look for an available space
        UInt64 offset = 0;
        for (UInt32 i = 0; i < mBlocks.GetSize(); i++)
        {
            SubAllocationBlock& block = mBlocks[i];
            if (block.bOwned)
            {
                offset += block.SizeInBytes;
                continue;
            }

            if (block.SizeInBytes < sizeInBytes)
            {
                offset += block.SizeInBytes;
                continue;
            }

            const UInt32 sizeLeft = block.SizeInBytes - sizeInBytes;
            block.SizeInBytes = sizeLeft;

            SubAllocationBlock newBlock = {};
            newBlock.bOwned = true;
            newBlock.SizeInBytes = sizeInBytes;
            mBlocks.AddAt(newBlock, i);
            mOccupiedSize += sizeInBytes;
            return offset;
        }

        return uint64_max;
    }
    void GraphicsMemoryHeap::Free(const UInt64 offsetInBytes)
    {
        //Find and free owned memory
        UInt64 currentOffset = 0;
        for (UInt32 i = 0; i < mBlocks.GetSize(); i++)
        {
            SubAllocationBlock& block = mBlocks[i];
            if (currentOffset != offsetInBytes)
            {
                currentOffset += block.SizeInBytes;
                continue;
            }

            block.bOwned = false;
            mOccupiedSize -= block.SizeInBytes;
            break;
        }

        //Compact
        for (UInt32 i = 0; i < mBlocks.GetSize(); i++)
        {
            SubAllocationBlock& block = mBlocks[i];
            CompactReport report = GetCompactReport(i);
            if (report.Min == report.Max)
                continue;

            Compact(report);

            if (report.Min < i)
            {
                const UInt32 diff = i - report.Min;
                i -= diff;
            }
        }

    }
    GraphicsMemoryHeap::CompactReport GraphicsMemoryHeap::GetCompactReport(const UInt32 index)
    {
        //Check min
        UInt32 min = index;
        for (UInt32 i = index; i > 0; i--)
        {
            SubAllocationBlock& block = mBlocks[i];
            if (block.bOwned)
                break;

            min--;
        }

        //Check max
        UInt32 max = index;
        for (UInt32 i = index; i < mBlocks.GetSize(); i++)
        {
            SubAllocationBlock& block = mBlocks[i];
            if (block.bOwned)
                break;

            max++;
        }

        return { min,max };
    }
    void GraphicsMemoryHeap::Compact(const CompactReport& report)
    {
        //Calculate size
        UInt64 size = 0;
        for (UInt32 i = report.Min; i < report.Max; i++)
        {
            SubAllocationBlock& block = mBlocks[i];
            size += block.SizeInBytes;
        }

        //Remove nodes
        const UInt32 removeCount = report.Max - report.Min;
        for (UInt32 i = 0; i < removeCount; i++)
            mBlocks.RemoveAt(report.Min);

        //Add single node
        SubAllocationBlock block = {};
        block.SizeInBytes = size;
        block.bOwned = false;
        mBlocks.AddAt(block, report.Min);
    }
}
