#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	/**
	 * @class Pair
	 * @brief A class that holds a pair of values
	 */
	template<typename TKey, typename TValue>
	class Pair
	{
	public:
		Pair() = default;
		Pair(TKey key, TValue value) : mKey(key), mValue(value) {}
		Pair(const Pair& other) : mKey(other.mKey), mValue(other.mValue) {}
		~Pair() = default;

		void SetPair(TKey key, TValue value) { mKey = key; mValue = value; }
		TKey& GetRefKey() { return mKey; }
		TKey GetKey() const { return mKey; }

		TValue& GetRefValue() { return mValue; }
		TValue GetValue() const { return mValue; }

	private:
		TKey mKey;
		TValue mValue;
	};

	/**
	 * @class HashMap
	 * @brief A class that holds a map of key-value pairs. Acts as a basic implementation of std::unordered_map
	 */
	template<typename TKey, typename TValue>
	class HashMap
	{
	public:
		HashMap() = default;
		HashMap(const HashMap& other)
		{
			mData = other.mData;
		}

		HashMap(UInt32 size)
		{
			mData.Reserve(size);
		}

		~HashMap()
		{
			mData.Clear();
		}

		void Insert(TKey key, TValue value)
		{
			mData.Add(Pair<TKey, TValue>(key, value));
		}

		void Remove(TKey key)
		{
			for (UInt32 i = 0; i < mData.GetSize(); i++)
			{
				if (mData[i].GetKey() == key)
				{
					mData.RemoveAt(i);
					break;
				}
			}
		}

		FORCEINLINE TValue* operator[](TKey key)
		{
			for (UInt32 i = 0; i < mData.GetSize(); i++)
			{
				if (mData[i].GetKey() == key)
				{
					return mData[i].GetRefValue();
				}
			}

			return nullptr;
		}

		FORCEINLINE Pair<TKey, TValue>& GetPair(TKey key)
		{
			for (UInt32 i = 0; i < mData.GetSize(); i++)
			{
				if (mData[i].GetKey() == key)
				{
					return &mData[i];
				}
			}

			return nullptr;
		}

		FORCEINLINE TValue* Find(TKey key)
		{
			for (UInt32 i = 0; i < mData.GetSize(); i++)
			{
				if (mData[i].GetKey() == key)
				{
					return &mData[i].GetRefValue();
				}
			}

			return nullptr;
		}

		FORCEINLINE int FindIndex(TKey key)
		{
			for (UInt32 i = 0; i < mData.GetSize(); i++)
			{
				if (mData[i].GetKey() == key)
				{
					return i;
				}
			}

			return -1;
		}

		FORCEINLINE Bool8 Contains(TKey key)
		{
			for (UInt32 i = 0; i < mData.GetSize(); i++)
			{
				if (mData[i].GetKey() == key)
				{
					return true;
				}
			}

			return false;
		}

		FORCEINLINE Pair<TKey, TValue>& operator[](UInt32 index)
		{
			return mData[index];
		}

		FORCEINLINE Pair<TKey, TValue>* begin() { return mData.begin(); }
		FORCEINLINE Pair<TKey, TValue>* end() { return mData.end(); }

		FORCEINLINE UInt32 GetSize() const { return mData.GetSize(); }
		FORCEINLINE UInt32 GetCapacity() const { return mData.GetCapacity(); }


		void Clear() { mData.Clear(); }

	private:
		Array<Pair<TKey, TValue>> mData;
	};
}
