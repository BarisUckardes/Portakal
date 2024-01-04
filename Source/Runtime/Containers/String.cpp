#include "String.h"
#include <Runtime/Memory/Memory.h>

namespace Portakal
{
	Uint64 GetCharPointerSize(const Char* target)
	{
		unsigned int pSize = 0;
		while (target[pSize] != '\0')
			pSize++;
		return pSize;
	}

	Uint64 GetWCharPointerSize(const wchar_t* target)
	{
		const wchar_t* ptr = target;
		while (*ptr)
			++ptr;
		return ptr - target;
	}

	String::String(const Char* pData, const Uint64 sizeInBytes)
	{
		mSize = sizeInBytes;
		mSource = new Char[sizeInBytes + 1];

		Memory::Copy(mSource, pData, sizeInBytes);
		mSource[sizeInBytes] = '\0';
	}

	String::String(const Byte* pData, const Uint64 sizeInBytes)
	{
		mSize = sizeInBytes;
		mSource = new Char[sizeInBytes + 1];

		Memory::Copy(mSource, pData, sizeInBytes);
		mSource[sizeInBytes] = '\0';
	}

	String::String(const wchar_t* pData)
	{
		mSize = GetWCharPointerSize(pData);
		if (mSize == 0)
		{
			mSource = nullptr;
			return;
		}

		mSource = new Char[mSize + 1];
		for (Uint64 i = 0; i < mSize; i++)
			mSource[i] = (Char)pData[i];
		mSource[mSize] = '\0';
	}

	String::String(const Uint64 sizeInBytes)
	{
		mSize = sizeInBytes;
		mSource = new Char[sizeInBytes + 1];
		mSource[sizeInBytes] = '\0';
	}

	String::String(const Char* pData)
	{
		mSize = GetCharPointerSize(pData);
		if (mSize == 0)
		{
			mSource = nullptr;
			return;
		}

		mSource = new Char[mSize + 1];
		Memory::Copy(mSource, pData, mSize);
		mSource[mSize] = '\0';
	}

	String::String(const String& other)
	{
		mSize = other.mSize;
		mSource = new Char[mSize + 1];

		Memory::Copy(mSource, other.mSource, mSize);

		mSource[mSize] = '\0';
	}

	String::String()
	{
		mSource = nullptr;
		mSize = 0;
	}

	String::~String()
	{
		if (mSource != nullptr)
			delete[] mSource;

		mSource = nullptr;
		mSize = 0;
	}

	Uint64 String::FindIndex(const String& target, const Uint64 startIndex, const Uint64 count) const
	{
		if (startIndex >= mSize)
			return uint64_max;

		const Uint64 targetSize = target.GetSize();
		if (targetSize == 0)
			return uint64_max;

		if (targetSize > mSize)
			return uint64_max;

		Uint64 searchLength = mSize - targetSize;
		if (count > 0 && count < searchLength)
			searchLength = count;

		for (unsigned int i = startIndex; i < searchLength; i++)
		{
			if (mSource[i] == target[0])
			{
				Bool8 found = true;
				for (unsigned int j = 1; j < searchLength; j++)
				{
					if (mSource[i + j] != target[j])
					{
						found = false;
						break;
					}
				}

				if (found)
					return i;
			}
		}

		return uint64_max;
	}

	Uint64 String::FindIndex(const Char target) const
	{
		for (Uint64 i = 0; i < mSize; i++)
			if (mSource[i] == target)
				return i;

		return uint64_max;
	}

	Uint64 String::FindIndex(const String& target) const
	{
		const Uint64 targetSize = target.GetSize();
		if (targetSize == 0)
			return uint64_max;
		if (targetSize > mSize)
			return uint64_max;

		const Uint64 searchSize = mSize - targetSize;

		for (Uint64 i = 0; i < searchSize; i++)
		{
			if (mSource[i] == target[0])
			{
				Bool8 bFound = true;
				for (unsigned int j = 1; j < targetSize; j++)
				{
					if (mSource[i + j] != target[j])
					{
						bFound = false;
						break;
					}
				}

				if (bFound)
					return i;
			}
		}

		return uint64_max;
	}

	Uint64 String::FindLastIndex(const String& target, const Uint64 startIndex) const
	{
		if (startIndex >= mSize)
			return -1;

		const Uint64 targetSize = target.GetSize();
		if (targetSize == 0)
			return uint64_max;

		if (targetSize > mSize)
			return uint64_max;

		const Uint64 searchSize = mSize - targetSize;

		for (unsigned int i = searchSize; i > startIndex; i--)
		{
			if (mSource[i] == target[0])
			{
				Bool8 found = true;
				for (unsigned int j = 1; j < searchSize; j++)
				{
					if (mSource[i + j] != target[j])
					{
						found = false;
						break;
					}
				}

				if (found)
					return i;
			}
		}

		return uint64_max;
	}

	Uint64 String::GetCount(const Char target) const
	{
		Uint64 count = 0;
		for (Uint64 i = 0; i < mSize; i++)
			if (mSource[i] == target)
				count++;

		return count;
	}

	String String::GetSubset(const Uint64 startIndex, const Uint64 length) const
	{
		String subset(length);
		Memory::Copy(subset.GetSource(), mSource, length);
		return subset;
	}

	String String::GetCopy() const
	{
		String target(mSize);
		Memory::Copy(target.GetSource(), mSource, mSize);
		return target;
	}

	const Char* String::GetCopyRaw() const
	{
		Char* pTarget = new Char[mSize];
		Memory::Copy(pTarget, mSource, mSize);
		pTarget[mSize] = '\0';
		return pTarget;
	}

	void String::Clear()
	{
		if (mSource != nullptr)
			delete[] mSource;

		mSource = nullptr;
		mSize = 0;
	}

	String String::operator=(const String other)
	{
		mSize = other.GetSize();
		mSource = new Char[mSize + 1];
		Memory::Copy(mSource, other.GetSource(), mSize);
		mSource[mSize] = '\0';

		return String(mSource);
	}

	String String::operator=(const Char* other)
	{
		mSize = GetCharPointerSize(other);
		mSource = new Char[mSize + 1];
		Memory::Copy(mSource, other, mSize);
		mSource[mSize] = '\0';

		return String(mSource);
	}

	String String::operator=(const wchar_t* other)
	{
		mSize = GetWCharPointerSize(other);
		mSource = new Char[mSize + 1];
		for (Uint64 i = 0; i < mSize; i++)
			mSource[i] = (Char)other[i];
		mSource[mSize] = '\0';

		return String(mSource);
	}

	String String::operator+=(const String& other)
	{
		unsigned int pOtherLength = other.GetSize();
		unsigned int newLength = mSize + pOtherLength;

		Char* newSource = new Char[newLength + 1];

		Memory::Copy(newSource, mSource, mSize);
		Memory::Copy(newSource + mSize, other.GetSource(), pOtherLength);

		delete[] mSource;

		newSource[newLength] = '\0';

		mSource = newSource;
		mSize = newLength;

		return String(mSource);
	}

	String String::operator+=(const Char* other)
	{
		unsigned int pOtherLength = GetCharPointerSize(other);
		unsigned int newLength = mSize + pOtherLength;

		Char* newSource = new Char[newLength + 1];

		Memory::Copy(newSource, mSource, mSize);
		Memory::Copy(newSource + mSize, other, pOtherLength);

		delete[] mSource;

		newSource[newLength] = '\0';

		mSource = newSource;
		mSize = newLength;

		return String(mSource);
	}

	String String::operator+=(Char other)
	{
		unsigned int newLength = mSize + 1;

		Char* newSource = new Char[newLength + 1];

		Memory::Copy(newSource, mSource, mSize);
		newSource[mSize] = other;

		delete[] mSource;

		mSource = newSource;
		mSize = newLength;

		return String(mSource);
	}

	String String::operator-=(const Char* other)
	{
		unsigned int pOtherLength = GetCharPointerSize(other);
		unsigned int newLength = mSize - pOtherLength;

		Char* newSource = new Char[newLength + 1];

		unsigned int newSourceIndex = 0;
		for (unsigned int i = 0; i < mSize; i++)
		{
			Bool8 found = false;
			for (unsigned int j = 0; j < pOtherLength; j++)
			{
				if (mSource[i] == other[j])
				{
					found = true;
					break;
				}
			}

			if (!found)
			{
				newSource[newSourceIndex] = mSource[i];
				newSourceIndex++;
			}
		}

		newSource[newLength] = '\0';

		delete[] mSource;

		mSource = newSource;
		mSize = newLength;

		return String(mSource);
	}

	String String::operator-=(const String& other)
	{
		unsigned int pOtherLength = other.GetSize();
		unsigned int newLength = mSize - pOtherLength;

		Char* newSource = new Char[newLength + 1];

		unsigned int newSourceIndex = 0;
		for (unsigned int i = 0; i < mSize; i++)
		{
			Bool8 found = false;
			for (unsigned int j = 0; j < pOtherLength; j++)
			{
				if (mSource[i] == other[j])
				{
					found = true;
					break;
				}
			}

			if (!found)
			{
				newSource[newSourceIndex] = mSource[i];
				newSourceIndex++;
			}
		}

		newSource[newLength] = '\0';

		delete[] mSource;

		mSource = newSource;
		mSize = newLength;

		return String(mSource);
	}

	Bool8 operator==(const String& target0, const String& target1)
	{
		unsigned int target0Length = target0.GetSize();
		unsigned int target1Length = target1.GetSize();
		const Char* target0Source = target0.GetSource();
		const Char* target1Source = target1.GetSource();

		if (target0Length != target1Length)
			return false;

		for (unsigned int i = 0; i < target0Length; i++)
		{
			if (target0Source[i] != target1Source[i])
			{
				return false;
			}
		}

		return true;
	}

	String operator+(const String& target0, const String& target1)
	{
		unsigned int target0Length = target0.GetSize();
		unsigned int target1Length = target1.GetSize();
		unsigned int newLength = target0Length + target1Length;

		Char* newSource = new Char[newLength + 1];

		Memory::Copy(newSource, target0.GetSource(), target0Length);
		Memory::Copy(newSource + target0Length, target1.GetSource(), target1Length);

		newSource[newLength] = '\0';

		return String(newSource);
	}

	Bool8 operator!=(const String& target0, const String& target1)
	{
		unsigned int target0Length = target0.GetSize();
		unsigned int target1Length = target1.GetSize();
		const Char* target0Source = target0.GetSource();
		const Char* target1Source = target1.GetSource();

		if (target0Length != target1Length)
			return true;

		for (unsigned int i = 0; i < target0Length; i++)
		{
			if (target0Source[i] != target1Source[i])
			{
				return true;
			}
		}

		return false;
	}
}
