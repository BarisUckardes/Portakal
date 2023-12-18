#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Object/Object.h>

namespace Portakal
{
    template<typename T>
    class SharedHeap
    {
    public:
        SharedHeap(const SharedHeap& other) : mData(nullptr), mReferenceCount(nullptr)
        {
            if (other.mData == nullptr)
            {
                mData = nullptr;
                mReferenceCount = nullptr;
                return;
            }

            mData = other.mData;
            mReferenceCount = other.mReferenceCount;

            IncrementReferenceCount();
        }
        SharedHeap(T* pObject) : mData(nullptr), mReferenceCount(nullptr)
        {
            mData = (Object*)pObject;
            if (pObject != nullptr)
                mReferenceCount = new uint32(1);
            else
                mReferenceCount = nullptr;

        }
        SharedHeap() : mData(nullptr), mReferenceCount(nullptr)
        {

        }
        ~SharedHeap()
        {
            Deference();
        }

        FORCEINLINE const bool IsShutdown() const noexcept { return (mData == nullptr || mData->IsShutdown()); }
        FORCEINLINE bool IsValid() const noexcept { return mData != nullptr; }
        FORCEINLINE T* GetHeap() const noexcept { return (T*)mData; }
        FORCEINLINE T** GetHeapAddress() noexcept { return (T**)&mData; }

        void Deference()
        {
            if (mReferenceCount == nullptr)
                return;

            *mReferenceCount = *mReferenceCount - 1;

            if (*mReferenceCount == 0)
                DeleteReference();

            mData = nullptr;
            mReferenceCount = nullptr;
        }
        void Shutdown() const
        {
            if (mData != nullptr)
                mData->Shutdown();
        }

        T* operator->() const noexcept
        {
            return (T*)mData;
        }
        template<typename TOther>
        SharedHeap<TOther> QueryAs() noexcept
        {
            TOther* pChecksum = dynamic_cast<TOther*>(mData);

            if (pChecksum == nullptr)
                return nullptr;

            IncrementReferenceCount();

            SharedHeap<TOther> other = nullptr;
            SharedHeap<T>* pTemp = (SharedHeap<T>*) & other;

            pTemp->mData = mData;
            pTemp->mReferenceCount = mReferenceCount;

            return other;
        }

        void operator =(const SharedHeap& other)
        {
            if (other.mData == nullptr)
            {
                mData = nullptr;
                mReferenceCount = nullptr;
                return;
            }

            mData = other.mData;
            mReferenceCount = other.mReferenceCount;

            IncrementReferenceCount();
        }
        template<typename TOther>
        void operator=(TOther* pData)
        {
            Deference();

            mData = (Object*)pData;
            mReferenceCount = new uint32(1);
        }
        void operator=(T* pData)
        {
            Deference();

            if (pData == nullptr)
            {
                mData = nullptr;
                mReferenceCount = nullptr;
                return;
            }

            mData = (Object*)pData;
            mReferenceCount = new uint32(1);
        }
        bool operator ==(const SharedHeap& other)
        {
            return mData == other.mData;

        }
        bool operator !=(const SharedHeap& other)
        {
            return mData != other.mData;
        }
        bool operator==(const T* pData)
        {
            return mData == (Object*)pData;
        }
        bool operator!=(const T* pData)
        {
            return mData != (Object*)pData;
        }

    protected:
        //virtual void SetNameCore(const String& name) {}

    private:
        void IncrementReferenceCount()
        {
            if (mReferenceCount != nullptr)
                *mReferenceCount = *mReferenceCount + 1;
        }

        void DeleteReference()
        {
            if (mData == nullptr)
                return;

            Shutdown();
            delete mData;
            delete mReferenceCount;
        }
    private:
        Object* mData;
        uint32* mReferenceCount;
    };
}
