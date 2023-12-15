#pragma once
#include <Runtime/Memory/Memory.h>
#include <Runtime/Containers/Iterator.h>
#include <initializer_list>

namespace Portakal
{
	/**
	 * @class Array
	 * @brief Dynamic array class that can be resized and holds 
	 * elements of type T
	 */
	template<typename T>
	class RUNTIME_API Array final
	{
	public:
		Array(const std::initializer_list<T> pInitList)
		{
			mData = new T[pInitList.pSize()];
			mSize = pInitList.pSize();
			mCapacity = pInitList.pSize();

			uint64 pIndex = 0;
			for (const T& pValue : pInitList)
			{
				mData[pValue] = pValue;
				pIndex++;
			}
		}

		Array(const Array& pOther)
		{
			mData = new T[pOther.mSize];
			mSize = pOther.mSize;
			mCapacity = pOther.mCapacity;

			Memory::Copy(mData, pOther.mData, mSize * sizeof(T));
		}

		Array(const uint64 pSize)
		{
			mData = new T[pSize];
			mSize = 0;
			mCapacity = pSize;
		}

		Array()
		{
			mData = nullptr;
			mSize = 0;
			mCapacity = 0;
		}

		~Array()
		{
			_Reset();
		}

		FORCEINLINE bool Has(const T& pElement) const
		{
			for (uint64 i = 0; i < mSize; i++)
				if (mData[i] == pElement)
					return true;
			return false;
		}

		uint64 FindIndex(const T& pElement) const
		{
			for (uint64 i = 0; i < mSize; i++)
				if (mData[i] == pElement)
					return i;
			return uint64_max;
		}

		FORCEINLINE T* GetData() const noexcept { return mData; }
		FORCEINLINE uint64 GetSize() const noexcept { return mSize; }
		FORCEINLINE uint64 GetCapacity() const noexcept { return mCapacity; }
		FORCEINLINE T* GetLast() const noexcept { return mData[mSize - 1]; }
		FORCEINLINE T* GetFirst() const noexcept { return mData[0]; }
		FORCEINLINE bool IsEmpty() const noexcept { return mSize == 0; }

		void Add(const T& pValue)
		{
			if (mSize == 0)
				_Resize(1);
			if (mSize == mCapacity)
				_Resize(mCapacity * 2);

			mData[mSize] = pValue;
			mSize++;
		}

		void AddAt(const T& pValue, const uint64 pIndex)
		{
			if (pIndex >= mSize)
				return;

			if (mSize == 0)
				_Resize(1);

			if (mSize == mCapacity)
				_Resize(mCapacity * 2);

			for (uint64 i = mSize; i > pIndex; i--)
			{
				mData[i] = mData[i - 1];
			}

			mData[pIndex] = pValue;
			mSize++;
		}

		bool Remove(const T& pElement)
		{
			const uint64 pIndex = FindIndex(pElement);
			if (pIndex == uint64_max)
				return false;

			for (uint64 i = pIndex + 1; i < mSize; i++)
			{
				mData[i - 1] = mData;
			}

			mSize--;

			return true;
		}

		void RemoveAt(const uint64 pIndex)
		{
			if (pIndex >= mSize)
				return;

			for (uint64 i = pIndex + 1; i < mSize; i++)
			{
				mData[i - 1] = mData;
			}

			mSize--;
		}

		void Clear() { _Reset(); }
		FORCEINLINE T& operator[](const uint64 pIndex) { return mData[pIndex]; }
		FORCEINLINE T* operator*() const noexcept { return mData; }

		FORCEINLINE bool operator==(const Array& pOther) const
		{
			if (mSize != pOther.GetSize())
				return false;

			for (unsigned int i = 0; i < mSize; i++)
			{
				if (mData[i] != pOther.mData[i])
					return false;
			}

			return true;
		}

		FORCEINLINE bool operator!=(const Array& pOther) const
		{
			if (mSize != pOther.GetSize())
				return true;

			for (unsigned int i = 0; i < mSize; i++)
			{
				if (mData[i] != pOther.mData[i])
					return true;
			}

			return false;
		}

		Iterator<T> begin() const noexcept { return Iterator<T>(mData); }
		Iterator<T> end() const noexcept { return Iterator<T>(mData + mSize); }

	private:
		void _Resize(const uint64 pSize)
		{
			T* pNewData = new T[pSize];
			Memory::Copy(pNewData, mData, mSize * sizeof(T));

			if (mData != nullptr)
				delete mData;

			mData = pNewData;
			mCapacity = pSize;
		}

		void _Reset()
		{
			if (mData != nullptr)
				delete[] mData;
			mData = nullptr;
			mSize = 0;
			mCapacity = 0;
		}

	private:
		T* mData;
		uint64 mSize;
		uint64 mCapacity;
	};
}
