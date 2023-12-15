#include "String.h"
#include <Runtime/Memory/Memory.h>

namespace Portakal
{
	uint64 GetCharPointerSize(const char* target)
	{
		unsigned int size = 0;
		while (target[size] != '\0')
			size++;
		return size;
	}

	String::String(const char* pData, const uint64 sizeInBytes)
	{
		mSize = sizeInBytes;
		mSource = new char[sizeInBytes + 1];

		Memory::Copy(mSource, pData, sizeInBytes);
		mSource[sizeInBytes] = '\0';
	}

	String::String(const byte* pData, const uint64 sizeInBytes)
	{
		mSize = sizeInBytes;
		mSource = new char[sizeInBytes + 1];

		Memory::Copy(mSource, pData, sizeInBytes);
		mSource[sizeInBytes] = '\0';
	}

	String::String(const uint64 sizeInBytes)
	{
		mSize = sizeInBytes;
		mSource = new char[sizeInBytes + 1];
		mSource[sizeInBytes] = '\0';
	}

	String::String(const char* pData)
	{
		mSize = GetCharPointerSize(pData);
		if (mSize == 0)
		{
			mSource = nullptr;
			return;
		}

		mSource = new char[mSize + 1];
		Memory::Copy(mSource, pData, mSize);
		mSource[mSize] = '\0';
	}

	String::String(const String& other)
	{
		mSize = other.mSize;
		mSource = new char[mSize + 1];

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

	uint64 String::FindIndex(const String& target, const uint64 startIndex, const uint64 count) const
	{
		if (startIndex >= mSize)
			return uint64_max;

		const uint64 targetSize = target.GetSize();
		if (targetSize == 0)
			return uint64_max;

		if (targetSize > mSize)
			return uint64_max;

		uint64 searchLength = mSize - targetSize;
		if (count > 0 && count < searchLength)
			searchLength = count;

		for (unsigned int i = startIndex; i < searchLength; i++)
		{
			if (mSource[i] == target[0])
			{
				bool found = true;
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

	uint64 String::FindIndex(const char target) const
	{
		for (uint64 i = 0; i < mSize; i++)
			if (mSource[i] == target)
				return i;

		return uint64_max;
	}

	uint64 String::FindIndex(const String& target) const
	{
		const uint64 targetSize = target.GetSize();
		if (targetSize == 0)
			return uint64_max;
		if (targetSize > mSize)
			return uint64_max;

		const uint64 searchSize = mSize - targetSize;

		for (uint64 i = 0; i < searchSize; i++)
		{
			if (mSource[i] == target[0])
			{
				bool bFound = true;
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

	uint64 String::FindLastIndex(const String& target, const uint64 startIndex) const
	{
		if (startIndex >= mSize)
			return -1;

		const uint64 targetSize = target.GetSize();
		if (targetSize == 0)
			return uint64_max;

		if (targetSize > mSize)
			return uint64_max;

		const uint64 searchSize = mSize - targetSize;

		for (unsigned int i = searchSize; i > startIndex; i--)
		{
			if (mSource[i] == target[0])
			{
				bool found = true;
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

	uint64 String::GetCount(const char target) const
	{
		uint64 count = 0;
		for (uint64 i = 0; i < mSize; i++)
			if (mSource[i] == target)
				count++;

		return count;
	}

	String String::GetSubset(const uint64 startIndex, const uint64 length) const
	{
		String subset(length);
		Memory::Copy(subset.GetSource(), mSource, length);
		return subset;
	}

	void String::Clear()
	{
		if (mSource != nullptr)
			delete[] mSource;

		mSource = nullptr;
		mSize = 0;
	}

	String String::operator=(const String& other)
	{
		mSize = other.GetSize();
		mSource = new char[mSize + 1];
		Memory::Copy(other.GetSource(), mSource, mSize);
		mSource[mSize] = '\0';

		return String(mSource);
	}

	String String::operator=(const char* other)
	{
		mSize = GetCharPointerSize(other);
		mSource = new char[mSize + 1];
		Memory::Copy(mSource, other, mSize);
		mSource[mSize] = '\0';

		return String(mSource);
	}


	String String::operator+=(const String& other)
	{
		unsigned int otherLength = other.GetSize();
		unsigned int newLength = mSize + otherLength;

		char* newSource = new char[newLength + 1];

		Memory::Copy(newSource, mSource, mSize);
		Memory::Copy(newSource + mSize, other.GetSource(), otherLength);

		delete[] mSource;

		newSource[newLength] = '\0';

		mSource = newSource;
		mSize = newLength;

		return String(mSource);
	}

	String String::operator+=(const char* other)
	{
		unsigned int otherLength = GetCharPointerSize(other);
		unsigned int newLength = mSize + otherLength;

		char* newSource = new char[newLength + 1];

		Memory::Copy(newSource, mSource, mSize);
		Memory::Copy(newSource + mSize, other, otherLength);

		delete[] mSource;

		newSource[newLength] = '\0';

		mSource = newSource;
		mSize = newLength;

		return String(mSource);
	}

	String String::operator+=(char other)
	{
		unsigned int newLength = mSize + 1;

		char* newSource = new char[newLength + 1];

		Memory::Copy(newSource, mSource, mSize);
		newSource[mSize] = other;

		delete[] mSource;

		mSource = newSource;
		mSize = newLength;

		return String(mSource);
	}

	String String::operator-=(const char* other)
	{
		unsigned int otherLength = GetCharPointerSize(other);
		unsigned int newLength = mSize - otherLength;

		char* newSource = new char[newLength + 1];

		unsigned int newSourceIndex = 0;
		for (unsigned int i = 0; i < mSize; i++)
		{
			bool found = false;
			for (unsigned int j = 0; j < otherLength; j++)
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
		unsigned int otherLength = other.GetSize();
		unsigned int newLength = mSize - otherLength;

		char* newSource = new char[newLength + 1];

		unsigned int newSourceIndex = 0;
		for (unsigned int i = 0; i < mSize; i++)
		{
			bool found = false;
			for (unsigned int j = 0; j < otherLength; j++)
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

	bool operator==(const String& target0, const String& target1)
	{
		unsigned int target0Length = target0.GetSize();
		unsigned int target1Length = target1.GetSize();
		const char* target0Source = target0.GetSource();
		const char* target1Source = target1.GetSource();

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

		char* newSource = new char[newLength + 1];

		Memory::Copy(newSource, target0.GetSource(), target0Length);
		Memory::Copy(newSource + target0Length, target1.GetSource(), target1Length);

		newSource[newLength] = '\0';

		return String(newSource);
	}

	bool operator!=(const String& target0, const String& target1)
	{
		unsigned int target0Length = target0.GetSize();
		unsigned int target1Length = target1.GetSize();
		const char* target0Source = target0.GetSource();
		const char* target1Source = target1.GetSource();

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
