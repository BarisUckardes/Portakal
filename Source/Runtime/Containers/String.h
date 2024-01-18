#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	class String;
	template<>
	class TypeAccessor<String>
	{
		friend class TypeDispatcher;
	public:
		static Type* GetType()
		{
			return sType;
		}
	private:
		static void SetType(Type* pType)
		{
			sType = pType;
		}
		static Type** GetTypeAddress()
		{
			return &sType;
		}
	private:
		static inline Type* sType = nullptr;
	};

	/**
	 * @class String
	 * @brief String class with basic string operations
	 */
	class Type;
	class RUNTIME_API String final
	{
	public:
		static Int32 ToInt32(const String& text);
		static UInt32 ToUInt32(const String& text);
		static Int64 ToInt64(const String& text);
		static UInt64 ToUInt64(const String& text);
		static Float32 ToFloat32(const String& text);
		static Float64 ToFloat64(const String& text);
		static String FromInt32(const Int32 value);
		static String FromUInt32(const UInt32 value);
		static String FromInt64(const Int64 value);
		static String FromUInt64(const UInt64 value);
		static String FromFloat32(const Float32 value);
		static String FromFloat64(const Float64 value);
	public:
		String(const Char* pData, const UInt64 sizeInBytes);
		String(const Byte* pData, const UInt64 sizeInBytes);
		String(const wchar_t* pData);
		String(const UInt64 sizeInBytes);
		String(const Char* pData);
		String(const String& other);
		String();
		~String();

		FORCEINLINE UInt64 GetSize() const noexcept { return mSize; }
		FORCEINLINE Char* GetSource() const noexcept { return mSource; }

		FORCEINLINE UInt64 FindIndex(const String& target, const UInt64 startIndex, const UInt64 count = 0)const;
		FORCEINLINE UInt64 FindIndex(const Char target) const;
		FORCEINLINE UInt64 FindIndex(const String& target) const;
		FORCEINLINE UInt64 FindLastIndex(const String& target, const UInt64 startIndex) const;
		FORCEINLINE UInt64 GetCount(const Char target) const;
		FORCEINLINE String GetSubset(const UInt64 startIndex, const UInt64 length) const;
		FORCEINLINE Type* GetType() const noexcept
		{
			return typeof(String);
		}
		String GetCopy() const;
		const Char* GetCopyRaw() const;
		void Clear();

		const Char* operator*() const { return mSource; }

		String operator+=(const String& other);
		String operator+=(const Char* other);
		String operator+=(Char other);
		String operator-=(const Char* other);
		String operator-=(const String& other);

		String operator=(const String other);
		String operator=(const Char* other);
		String operator=(const wchar_t* other);

		Char operator[](unsigned int index) const { return mSource[index]; }

	private:
		Char* mSource;
		UInt64 mSize;
	};

	String operator+(const String& target0, const String& target1);
	Bool8 operator==(const String& target0, const String& target1);
	Bool8 operator!=(const String& target0, const String& target1);
}





































































































































