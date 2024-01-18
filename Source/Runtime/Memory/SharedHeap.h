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
                mReferenceCount = new UInt32(1);
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

        FORCEINLINE Bool8 IsShutdown() const noexcept { return (mData == nullptr || mData->IsShutdown()); }
        FORCEINLINE Bool8 IsAlive() const noexcept { return (mData != nullptr && !mData->IsShutdown()); }
        FORCEINLINE Bool8 IsValid() const noexcept { return mData != nullptr; }
        FORCEINLINE T* GetHeap() const noexcept { return (T*)mData; }
        FORCEINLINE T** GetHeapAddress() const noexcept { return (T**)&mData; }

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
        void Shutdown()
        {
            //Shutdown the underlying data
            if (mData != nullptr)
                mData->Shutdown();

            Deference();
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
            mReferenceCount = new UInt32(1);
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
            mReferenceCount = new UInt32(1);
        }
        Bool8 operator ==(const SharedHeap& other)
        {
            return mData == other.mData;

        }
        Bool8 operator !=(const SharedHeap& other)
        {
            return mData != other.mData;
        }
        Bool8 operator==(const T* pData)
        {
            return mData == (Object*)pData;
        }
        Bool8 operator!=(const T* pData)
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
        UInt32* mReferenceCount;
    };

    template<typename T>
    class SharedWeakHeap
    {
    public:
        SharedWeakHeap(const SharedHeap<T>& pTarget) : mData(pTarget.GetHeapAddress())
        {

        }
        ~SharedWeakHeap()
        {
            mData = nullptr;
        }

        FORCEINLINE bool IsShutdown() const noexcept
        {
            return mData == nullptr;
        }

        FORCEINLINE T* GetHeap() const noexcept
        {
            return *mData;
        }
        FORCEINLINE T** GetHeapAddress() const noexcept
        {
            return mData;
        }
        void operator=(const SharedHeap<T>& pTarget)
        {
            mData = pTarget.GetHeapAddress();
        }
        Bool8 operator ==(const SharedWeakHeap& other)
        {
            return mData == other.mData;

        }
        Bool8 operator !=(const SharedWeakHeap& other)
        {
            return mData != other.mData;
        }
        FORCEINLINE T* operator*() const noexcept
        {
            return *mData;
        }
    private:
        T** mData;
    };
}
