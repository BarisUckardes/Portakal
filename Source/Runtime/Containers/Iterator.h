#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
    /**
     * @class Iterator
     * @brief Iterator class for iterating over containers
     */
    template<typename T>
    class Iterator
    {
    public:
        Iterator() : mPtr(nullptr) {}
        Iterator(T* ptr) : mPtr(ptr) {}
        Iterator(const Iterator& pOther) : mPtr(pOther.mPtr) {}

        Iterator& operator=(const Iterator& pOther)
        {
            mPtr = pOther.mPtr;
            return *this;
        }

        Iterator(Iterator&& pOther) noexcept : mPtr(pOther.mPtr) { pOther.mPtr = nullptr; }

        Iterator& operator=(Iterator&& pOther) noexcept
        {
            mPtr = pOther.mPtr;
            pOther.mPtr = nullptr;
            return *this;
        }

        FORCEINLINE T* operator->() const noexcept { return mPtr; }
        FORCEINLINE T& operator*() const noexcept { return *mPtr; }
        FORCEINLINE operator T* () const noexcept { return mPtr; }
        FORCEINLINE bool operator==(const Iterator& pOther) const noexcept { return mPtr == pOther.mPtr; }
        FORCEINLINE bool operator!=(const Iterator& pOther) const noexcept { return mPtr != pOther.mPtr; }
        FORCEINLINE bool operator<(const Iterator& pOther) const noexcept { return mPtr < pOther.mPtr; }
        FORCEINLINE bool operator>(const Iterator& pOther) const noexcept { return mPtr > pOther.mPtr; }
        FORCEINLINE bool operator<=(const Iterator& pOther) const noexcept { return mPtr <= pOther.mPtr; }
        FORCEINLINE bool operator>=(const Iterator& pOther) const noexcept { return mPtr >= pOther.mPtr; }

        FORCEINLINE Iterator& operator++() noexcept
        {
            ++mPtr;
            return *this;
        }

        FORCEINLINE Iterator& operator--() noexcept
        {
            --mPtr;
            return *this;
        }

        FORCEINLINE Iterator operator++(int) noexcept
        {
            Iterator temp = *this;
            ++mPtr;
            return temp;
        }

        FORCEINLINE Iterator operator--(int) noexcept
        {
            Iterator temp = *this;
            --mPtr;
            return temp;
        }

        FORCEINLINE Iterator& operator+=(int pValue) noexcept
        {
            mPtr += pValue;
            return *this;
        }

        FORCEINLINE Iterator& operator-=(int pValue) noexcept
        {
            mPtr -= pValue;
            return *this;
        }

        FORCEINLINE Iterator operator+(int pValue) const noexcept { return Iterator(mPtr + pValue); }
        FORCEINLINE Iterator operator-(int pValue) const noexcept { return Iterator(mPtr - pValue); }
        FORCEINLINE int operator-(const Iterator& pOther) const noexcept { return mPtr - pOther.mPtr; }
        FORCEINLINE T& operator[](int pIndex) const noexcept { return mPtr[pIndex]; }
        FORCEINLINE T* Get() const noexcept { return mPtr; }
        FORCEINLINE bool IsValid() const noexcept { return mPtr != nullptr; }
        explicit operator bool() const noexcept { return IsValid(); }

    private:
        T* mPtr = nullptr;
    };
}
