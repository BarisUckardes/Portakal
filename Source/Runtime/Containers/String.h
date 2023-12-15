#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	class RUNTIME_API String final
	{
	public:
		String(const char* pData, const uint64 sizeInBytes);
		String(const byte* pData, const uint64 sizeInBytes);
		String(const uint64 sizeInBytes);
		String(const char* pData);
		String(const String& other);
		String();

		FORCEINLINE uint64 GetSize() const noexcept
		{
			return mSize;
		}
		FORCEINLINE char* GetSource() const noexcept
		{
			return mSource;
		}
		FORCEINLINE uint64 FindIndex(const String& target, const uint64 startIndex, const uint64 count = 0)const;
		FORCEINLINE uint64 FindIndex(const char target) const;
		FORCEINLINE uint64 FindIndex(const String& target) const;
		FORCEINLINE uint64 FindLastIndex(const String& target, const uint64 startIndex) const;
		FORCEINLINE uint64 GetCount(const char target) const;
		FORCEINLINE String GetSubset(const uint64 startIndex, const uint64 length) const;

		void Clear();

		const char* operator*() const
		{
			return mSource;
		}

		String operator+=(const String& other);
		String operator+=(const char* other);
		String operator+=(char other);
		String operator-=(const char* other);
		String operator-=(const String& other);

		String operator=(const String& other);
		String operator=(const char* other);

		char operator[](unsigned int index) const { return mSource[index]; }
	private:
		char* mSource;
		uint64 mSize;
	};
}
