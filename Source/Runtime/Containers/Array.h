#pragma once
#include <Runtime/Memory/Memory.h>
#include <initializer_list>
#include <Runtime/Containers/Iterator.h>

namespace Portakal
{
	template<typename T>
	class Array final
	{
	public:
		Array(const std::initializer_list<T> initList)
		{
			mData = new T[initList.size()];
			mSize = initList.size();
			mCapacity = initList.size();

			uint64 index = 0;
			for (const T& value : initList)
			{
				mData[value] = value;
				index++;
			}

		}
		Array(const Array& other)
		{
			mData = new T[other.mSize];
			mSize = other.mSize;
			mCapacity = other.mCapacity;

			Memory::Copy(mData, other.mData, mSize*sizeof(T));
		}
		Array(const uint64 size)
		{
			mData = new T[size];
			mSize = 0;
			mCapacity = size;
		}
		Array()
		{
			mData = nullptr;
			mSize = 0;
			mCapacity = 0;
		}

		FORCEINLINE bool Has(const T& element) const
		{
			for (uint64 i = 0; i < mSize; i++)
				if (mData[i] == element)
					return true;
			return false;
		}
		uint64 FindIndex(const T& element) const
		{
			for (uint64 i = 0; i < mSize; i++)
				if (mData[i] == element)
					return i;
			return uint64_max;
		}
		FORCEINLINE T* GetData() const noexcept
		{
			return mData;
		}
		FORCEINLINE uint64 GetSize() const noexcept
		{
			return mSize;
		}
		FORCEINLINE uint64 GetCapacity() const noexcept
		{
			return mCapacity;
		}
		FORCEINLINE T* GetLast() const noexcept
		{
			return mData[mSize - 1];
		}
		FORCEINLINE T* GetFirst() const noexcept
		{
			return mData[0];
		}
		FORCEINLINE bool IsEmpty() const noexcept
		{
			return mSize == 0;
		}


		void Add(const T& value)
		{
			if (mSize == 0)
				_Resize(1);
			if (mSize == mCapacity)
				_Resize(mCapacity*2);

			mData[mSize] = value;
			mSize++;
		}
		void AddAt(const T& value, const uint64 index)
		{
			if (index >= mSize)
				return;

			if (mSize == 0)
				_Resize(1);

			if (mSize == mCapacity)
				_Resize(mCapacity * 2);

			for (uint64 i = mSize;i>index;i--)
			{
				mData[i] = mData[i - 1];
			}

			mData[index] = value;
			mSize++;
		}
		bool Remove(const T& element)
		{
			const uint64 index = FindIndex(element);
			if (index == uint64_max)
				return false;

			for (uint64 i = index+1;i < mSize; i++)
			{
				mData[i - 1] = mData;
			}

			mSize--;

			return true;
		}
		void RemoveAt(const uint64 index)
		{
			if (index >= mSize)
				return;

			for (uint64 i = index + 1; i < mSize; i++)
			{
				mData[i - 1] = mData;
			}

			mSize--;
		}
		void Clear()
		{
			_Reset();

			mData = nullptr;
			mSize = 0;
			mCapacity = 0;
		}

		FORCEINLINE T& operator[](const uint64 index)
		{
			return mData[index];
		}
		FORCEINLINE T* operator*() const noexcept
		{
			return mData;
		}
		FORCEINLINE bool operator==(const Array& other) const
		{
			if (mSize != other.GetSize())
				return false;

			for (unsigned int i = 0; i < mSize; i++)
			{
				if (mData[i] != other.mData[i])
					return false;
			}

			return true;
		}

		FORCEINLINE bool operator!=(const Array& other) const
		{
			if (mSize != other.GetSize())
				return true;

			for (unsigned int i = 0; i < mSize; i++)
			{
				if (mData[i] != other.mData[i])
					return true;
			}

			return false;
		}

		Iterator<T> begin() const noexcept
		{
			return Iterator<T>(mData);
		}
		Iterator<T> end() const noexcept
		{
			return Iterator<T>(mData + mSize);
		}

	private:
		void _Resize(const uint64 size)
		{
			/*
			* Allocate and copy data
			*/
			T* pNewData = new T[size];
			Memory::Copy(pNewData, mData, mSize*sizeof(T));

			if (mData != nullptr)
				delete mData;

			mData = pNewData;
			mCapacity = size;

		}

		void _Reset()
		{
			if (mData != nullptr)
				delete[] mData;
			mData = nullptr;
			mSize = 0;
			mCapacity = 0;
		}
		T* mData;
		uint64 mSize;
		uint64 mCapacity;
	};
}
