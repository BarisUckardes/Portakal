#pragma once

#pragma warning(push)
#pragma warning(disable:6385)
#pragma warning(disable:6386)

#include <Runtime/Core/Core.h>
#include <Runtime/Containers/Iterator.h>
#include <Runtime/Memory/Memory.h>
#include <initializer_list>

namespace Portakal
{
	class ArrayBase
	{
	public:
		ArrayBase() = default;
		~ArrayBase() = default;

		virtual void AddIndirect() = 0;
		virtual void CreateIndirect(const UInt32 count) = 0;
		virtual void ClearIndirect() = 0;
	};

	template<typename T>
	class Array : public ArrayBase
	{
	public:
		virtual void ClearIndirect() override
		{
			Clear();
		}

		virtual void AddIndirect() override
		{
			Add({});
		}

		virtual void CreateIndirect(const UInt32 count) override
		{
			mSize = count;
			mCapacity = count;

			mData = new T[count];
			Memory::Set(mData, 0, count);
		}

		Array()
		{
			mData = nullptr;
			mSize = 0;
			mCapacity = 0;
		}

		Array(UInt32 size)
		{
			mData = new T[size];
			mSize = size;
			mCapacity = size;
		}

		Array(const std::initializer_list<T> initList)
		{
			mData = new T[initList.size()];
			mSize = initList.size();
			mCapacity = initList.size();

			UInt32 index = 0;
			for (const T& value : initList)
			{
				mData[index] = value;
				index++;
			}
		}

		Array(const Array& other)
		{
			mData = new T[other.GetCapacity()];
			mSize = other.GetSize();
			mCapacity = other.GetCapacity();

			for (UInt32 i = 0; i < mSize; i++)
			{
				mData[i] = other[i];
			}
		}

		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				mData = new T[other.GetCapacity()];
				mSize = other.GetSize();
				mCapacity = other.GetCapacity();

				for (UInt32 i = 0; i < mSize; i++)
				{
					mData[i] = other.mData[i];
				}
			}
			return *this;
		}

		~Array()
		{
			delete[] mData;
			mData = nullptr;
			mSize = 0;
			mCapacity = 0;
		}

		Bool8 Has(const T& element) const
		{

			for (UInt32 i = 0; i < mSize; i++)
			{
				if (mData[i] == element) // Has
					return true;
			}

			return false;
		}

		void Add(const T& value)
		{
			if (mSize == 0)
				_Resize(1);

			if (mSize == mCapacity)
				_Resize(mCapacity * 2);

			mData[mSize] = value;
			mSize++;
		}

		void AddAt(const T& value, int index)
		{
			if (index < 0 || index > mSize)
				return;

			if (mSize == 0)
				_Resize(1);

			if (mSize == mCapacity)
				_Resize(mCapacity * 2);

			for (UInt32 i = mSize; i > index; i--)
			{
				mData[i] = mData[i - 1];
			}

			mData[index] = value;
			mSize++;
		}

		void AddAt(T&& value, int index)
		{
			if (index < 0 || index > mSize)
				return;

			if (mSize == 0)
				_Resize(1);

			if (mSize == mCapacity)
				_Resize(mCapacity * 2);

			for (UInt32 i = mSize; i > index; i--)
			{
				mData[i] = mData[i - 1];
			}

			mData[index] = value;
			mSize++;
		}
		template<typename TOther>
		int FindIndex(const TOther& element) const
		{
			int index = -1;

			for (UInt32 i = 0; i < mSize; i++)
			{
				if (mData[i] == element)
				{
					index = i;
					break;
				}
			}

			return index;
		}

		template<typename TOther>
		Bool8 Remove(const TOther& element)
		{
			const int index = FindIndex(element);
			if (index == -1)
				return false;

			for (UInt32 i = index + 1; i < mSize; i++)
			{
				mData[i - 1] = mData[i];
			}

			mSize--;

			return true;
		}

		void RemoveLast()
		{
			if (mSize == 0)
				return;

			mSize--;
			if (mSize == 0)
				_Reset();
		}

		void RemoveFirst()
		{
			if (mSize == 0)
				return;

			for (UInt32 i = 0; i < mSize - 1; i++)
			{
				mData[i] = mData[i + 1];
			}

			mSize--;
			if (mSize == 0)
				_Reset();
		}

		void RemoveAt(UInt32 index)
		{
			if (index >= mSize)
				return;

			for (UInt32 i = index; i < mSize-1; i++)
			{
				mData[i] = mData[i + 1];
			}

			mSize--;
		}

		void RemoveAll()
		{
			_Reset();
		}

		void Clear()
		{
			_Reset();

			mData = nullptr;
			mSize = 0;
			mCapacity = 0;
		}

		void Reserve(UInt32 capacity)
		{
			if (capacity <= mCapacity)
				return;

			_Resize(capacity);
		}

		void Resize(UInt32 size)
		{
			if (size == mSize)
				return;

			if (size < mSize)
			{
				mSize = size;
				return;
			}

			if (size > mCapacity)
				_Resize(size);

			for (UInt32 i = mSize; i < size; i++)
			{
				mData[i] = T();
			}

			mSize = size;
		}

		NODISCARD const T& GetAt(int index) const { return mData[index]; }
		NODISCARD const T* GetDataConst() const { return mData; }
		NODISCARD T* GetData() { return mData; }
		NODISCARD T& operator[](int index) const { return mData[index]; }
		NODISCARD T& GetLast() const { return mData[mSize - 1]; }
		NODISCARD T& GetFirst() const { return mData[0]; }
		NODISCARD T& operator*() const { return mData; }

		NODISCARD UInt32 GetSize() const { return mSize; }
		NODISCARD UInt32 GetCapacity() const { return mCapacity; }

		NODISCARD Bool8 IsEmpty() const { return mSize == 0; }

		NODISCARD Bool8 IsValid() const { return mData != nullptr; }

		NODISCARD Bool8 operator==(const Array& other) const
		{
			if (mSize != other.GetSize())
				return false;

			for (UInt32 i = 0; i < mSize; i++)
			{
				if (mData[i] != other.mData[i])
					return false;
			}

			return true;
		}

		NODISCARD Bool8 operator!=(const Array& other) const
		{
			if (mSize != other.GetSize())
				return true;

			for (UInt32 i = 0; i < mSize; i++)
			{
				if (mData[i] != other.mData[i])
					return true;
			}

			return false;
		}


		Iterator<T> begin() const { return Iterator<T>(mData); }
		Iterator<T> end() const { return Iterator<T>(mData + mSize); }

	private:
		void _Resize(UInt32 newSize)
		{
			T* newData = new T[newSize];

			for (UInt32 i = 0; i < mSize; i++)
			{
				newData[i] = mData[i];
			}

			if (mData != nullptr)
				delete[] mData;

			mData = newData;
			mCapacity = newSize;
		}

		void _Reset()
		{
			delete[] mData;
			mData = nullptr;
			mSize = 0;
			mCapacity = 0;
		}

		T* mData;
		UInt32 mSize;
		UInt32 mCapacity;
	};
}

#pragma warning(pop)