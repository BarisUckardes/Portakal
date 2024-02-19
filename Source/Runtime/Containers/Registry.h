#include <Runtime/Core/Core.h>

namespace Portakal
{
	/// <summary>
	/// Represents a single Registry entry. It contains Key&Value tupple
	/// </summary>
	/// <typeparam name="TKey"></typeparam>
	/// <typeparam name="TValue"></typeparam>
	template<typename TKey, typename TValue>
	struct RegistryEntry
	{
		RegistryEntry(const RegistryEntry& other)
		{
			Key = other.Key;
			Value = other.Value;
		}
		RegistryEntry()
		{
			Key = {};
			Value = {};
		}


		/// <summary>
		/// The key
		/// </summary>
		TKey Key;

		/// <summary>
		/// The value
		/// </summary>
		TValue Value;
	};

	/// <summary>
	/// Unlike array it holds tupples Key&Value
	/// Acts as a C# Dictionary
	/// </summary>
	/// <typeparam name="TKey"></typeparam>
	/// <typeparam name="TValue"></typeparam>
	template<typename TKey, typename TValue>
	class Registry
	{
	public:
		Registry(const Registry& target)
		{
			mArray = target.mArray;
		}
		Registry(const UInt32 preallocatedCount)
		{
			mArray = Array<RegistryEntry<TKey, TValue>>(preallocatedCount);
		}
		Registry()
		{

		}


		/// <summary>
		/// Returns the entry count of the registry
		/// </summary>
		/// <returns></returns>
		FORCEINLINE UInt32 GetSize() const noexcept
		{
			return mArray.GetSize();
		}

		/// <summary>
		/// Returns the value address of the given key
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		FORCEINLINE TValue* GetEntryValue(const TKey& key) const noexcept
		{
			for (UInt32 i = 0; i < mArray.GetSize(); i++)
			{
				RegistryEntry<TKey, TValue>& entry = mArray[i];
				if (entry.Key == key)
					return &entry.Value;
			}

			return nullptr;
		}

		/// <summary>
		/// Returns whether the given key exists
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		FORCEINLINE bool HasEntry(const TKey& key) const noexcept
		{
			for (UInt32 i = 0; i < mArray.GetSize(); i++)
			{
				RegistryEntry<TKey, TValue>& entry = mArray[i];
				if (entry.Key == key)
					return true;
			}

			return false;
		}

		/// <summary>
		/// Finds the index of the given key
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		FORCEINLINE int FindIndex(const TKey& key) const noexcept
		{
			for (UInt32 i = 0; i < mArray.GetSize(); i++)
			{
				RegistryEntry<TKey, TValue>& entry = mArray[i];
				if (entry.Key == key)
					return i;
			}

			return -1;
		}

		/// <summary>
		/// Registers anew entry
		/// </summary>
		/// <param name="key"></param>
		/// <param name="value"></param>
		/// <returns></returns>
		FORCEINLINE bool Register(const TKey& key, const TValue& value) noexcept
		{
			const int index = FindIndex(key);
			if (index != -1)
			{
				return false;
			}

			RegistryEntry<TKey, TValue> entry = {};
			entry.Key = key;
			entry.Value = value;
			mArray.Add(entry);

			return true;
		}

		/// <summary>
		/// Removes an existing key entry
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		FORCEINLINE bool Remove(const TKey& key) noexcept
		{
			const int index = FindIndex(key);
			if (index == -1)
				return false;

			mArray.RemoveIndex(index);

			return true;
		}

		/// <summary>
		/// Clears the registry
		/// </summary>
		void Clear()
		{
			mArray.Clear();
		}

		/// <summary>
		/// Index operator
		/// </summary>
		/// <param name="index"></param>
		/// <returns></returns>
		FORCEINLINE RegistryEntry<TKey, TValue>& operator[](const UInt32 index) const noexcept
		{
			return mArray[index];
		}

		FORCEINLINE RegistryEntry<TKey, TValue>* begin() { return mArray.begin(); }
		FORCEINLINE RegistryEntry<TKey, TValue>* end() { return mArray.end(); }

	private:
		Array<RegistryEntry<TKey, TValue>> mArray;
	};
}