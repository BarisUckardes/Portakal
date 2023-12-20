#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Reflection/TypeCodes.h>
#include <Runtime/Reflection/TypeModes.h>
#include <Runtime/Reflection/EnumType.h>
#include <Runtime/Reflection/EnumValue.h>
#include <Runtime/Reflection/TypeCodes.h>

namespace Portakal
{
	class Field;
	class Attribute;
	typedef void* (*DefaultHeapObjectGenerator)(void);
	class RUNTIME_API Type
	{
	public:
		FORCEINLINE String GetName() const noexcept
		{
			return mName;
		}
		FORCEINLINE uint32 GetSize() const noexcept
		{
			return mSize;
		}
		FORCEINLINE TypeModes GetMode() const noexcept
		{
			return mMode;
		}
		FORCEINLINE TypeCodes GetCode() const noexcept
		{
			return mCode;
		}
		FORCEINLINE Array<Field*> GetFields() const noexcept
		{
			return mFields;
		}
		FORCEINLINE Array<Attribute*> GetAttributes() const noexcept
		{
			return mAttributes;
		}
		FORCEINLINE Array<EnumValue> GetEnums() const noexcept
		{
			return mEnums;
		}
	private:
		Type(const String& name, const uint32 size, const TypeModes mode, const TypeCodes code, DefaultHeapObjectGenerator defaultObjectGenerator, const Array<Field*>& fields, const Array<Attribute*>& attributes, const Array<EnumValue>& enumValues, Type** ppModuleAddress);
		~Type();
	private:
		const String mName;
		const uint32 mSize;
		const TypeModes mMode;
		const TypeCodes mCode;
		const DefaultHeapObjectGenerator mDefaultObjectGenerator;
		const Array<Field*> mFields;
		const Array<Attribute*> mAttributes;
		const Array<EnumValue> mEnums;
		Type** mModuleAddress;
	};

	template<typename T>
	class TypeAccessor
	{

	};

#define typeof(type) TypeAccessor<##type>::GetType()
#define RSTRUCT()
#define RCLASS()
#define RENUM()
#define RFIELD()
#define RATTRIBUTE(target,...)
}
