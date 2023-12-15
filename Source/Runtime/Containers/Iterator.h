#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
    template<typename T>
    class Iterator
    {
    public:
        Iterator() : mPtr(nullptr) {}
        Iterator(T* ptr) : mPtr(ptr) {}
        Iterator(const Iterator& other) : mPtr(other.mPtr) {}

        Iterator& operator=(const Iterator& other)
        {
            mPtr = other.mPtr;
            return *this;
        }

        Iterator(Iterator&& other) noexcept : mPtr(other.mPtr) { other.mPtr = nullptr; }

        Iterator& operator=(Iterator&& other) noexcept
        {
            mPtr = other.mPtr;
            other.mPtr = nullptr;
            return *this;
        }

        FORCEINLINE T* operator->() const noexcept { return mPtr; }
        FORCEINLINE T& operator*() const noexcept { return *mPtr; }
        FORCEINLINE operator T* () const noexcept { return mPtr; }
        FORCEINLINE bool operator==(const Iterator& other) const noexcept { return mPtr == other.mPtr; }
        FORCEINLINE bool operator!=(const Iterator& other) const noexcept { return mPtr != other.mPtr; }
        FORCEINLINE bool operator<(const Iterator& other) const noexcept { return mPtr < other.mPtr; }
        FORCEINLINE bool operator>(const Iterator& other) const noexcept { return mPtr > other.mPtr; }
        FORCEINLINE bool operator<=(const Iterator& other) const noexcept { return mPtr <= other.mPtr; }
        FORCEINLINE bool operator>=(const Iterator& other) const noexcept { return mPtr >= other.mPtr; }

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

        FORCEINLINE Iterator& operator+=(int value) noexcept
        {
            mPtr += value;
            return *this;
        }

        FORCEINLINE Iterator& operator-=(int value) noexcept
        {
            mPtr -= value;
            return *this;
        }

        FORCEINLINE Iterator operator+(int value) const noexcept { return Iterator(mPtr + value); }
        FORCEINLINE Iterator operator-(int value) const noexcept { return Iterator(mPtr - value); }
        FORCEINLINE int operator-(const Iterator& other) const noexcept { return mPtr - other.mPtr; }
        FORCEINLINE T& operator[](int index) const noexcept { return mPtr[index]; }
        FORCEINLINE T* Get() const noexcept { return mPtr; }
        FORCEINLINE bool IsValid() const noexcept { return mPtr != nullptr; }
        explicit operator bool() const noexcept { return IsValid(); }

    private:
        T* mPtr = nullptr;
    };
}
