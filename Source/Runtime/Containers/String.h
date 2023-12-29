#pragma once
#include <Runtime/Core/Core.h>
#include "String.reflected.h"

namespace Portakal
{
	/**
	 * @class String
	 * @brief String class with basic string operations
	 */
	class Type;
	PCLASS();
	class RUNTIME_API String final
	{
	public:
		String(const char* pData, const uint64 sizeInBytes);
		String(const byte* pData, const uint64 sizeInBytes);
		String(const wchar_t* pData);
		String(const uint64 sizeInBytes);
		String(const char* pData);
		String(const String& other);
		String();
		~String();

		FORCEINLINE uint64 GetSize() const noexcept { return mSize; }
		FORCEINLINE char* GetSource() const noexcept { return mSource; }

		FORCEINLINE uint64 FindIndex(const String& target, const uint64 startIndex, const uint64 count = 0)const;
		FORCEINLINE uint64 FindIndex(const char target) const;
		FORCEINLINE uint64 FindIndex(const String& target) const;
		FORCEINLINE uint64 FindLastIndex(const String& target, const uint64 startIndex) const;
		FORCEINLINE uint64 GetCount(const char target) const;
		FORCEINLINE String GetSubset(const uint64 startIndex, const uint64 length) const;
		FORCEINLINE Type* GetType() const noexcept
		{
			return typeof(String);
		}
		String GetCopy() const;
		const char* GetCopyRaw() const;
		void Clear();

		const char* operator*() const { return mSource; }

		String operator+=(const String& other);
		String operator+=(const char* other);
		String operator+=(char other);
		String operator-=(const char* other);
		String operator-=(const String& other);

		String operator=(const String other);
		String operator=(const char* other);
		String operator=(const wchar_t* other);

		char operator[](unsigned int index) const { return mSource[index]; }

	private:
		char* mSource;
		uint64 mSize;
	};

	String operator+(const String& target0, const String& target1);
	bool operator==(const String& target0, const String& target1);
	bool operator!=(const String& target0, const String& target1);
}































































































