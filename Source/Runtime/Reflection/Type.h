#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Reflection/TypeCodes.h>
#include <Runtime/Reflection/TypeModes.h>
#include <Runtime/Reflection/EnumType.h>
#include <Runtime/Reflection/EnumValue.h>
#include <Runtime/Reflection/TypeCodes.h>
#include <Runtime/Reflection/Attribute.h>
#include "FieldMode.h"

namespace Portakal
{
	class Field;
	typedef void* (*DefaultHeapObjectGenerator)(void);
	class RUNTIME_API Type final
	{
		friend class ReflectionManifest;
		friend class TypeDispatcher;
	public:
		FORCEINLINE String GetName() const noexcept
		{
			return mName;
		}
		FORCEINLINE Uint32 GetSize() const noexcept
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

		template<typename T>
		T* GetAttribute() const noexcept
		{
			Type* pType = typeof(T);
			for (Attribute* pAttribute : mAttributes)
				if (pType == pAttribute->GetType())
					return (T*)pAttribute;
			return nullptr;
		}
		void* CreateDefaultHeapObject() const noexcept;
		Bool8 IsSubClassOf(const Type* pType) const noexcept;
	private:
		Type(const String& name, const Uint32 size, const TypeModes mode, const TypeCodes code, DefaultHeapObjectGenerator defaultObjectGenerator,Type** ppModuleAddress);
		~Type();

		void _RegisterEnum(const String& name, const Int64 value);
		void _RegisterField(Field* pField);
		void _SetBaseType(Type* pType);
		void _RegisterAttribute(Attribute* pAttribute);
	private:
		const String mName;
		const Uint32 mSize;
		const TypeModes mMode;
		const TypeCodes mCode;
		const DefaultHeapObjectGenerator mDefaultObjectGenerator;
		Array<Field*> mFields;
		Array<Attribute*> mAttributes;
		Array<EnumValue> mEnums;
		Type* mBaseType;
		Type** mModuleAddress;
	};



#define GENERATE_PRIMITIVE(type)\
	template<>\
	class TypeAccessor<type>\
	{\
		friend class TypeDispatcher;\
	public:\
		static Type* GetType()\
		{\
			return sType;\
		}\
	private:\
		static void SetType(Type* pType)\
		{\
			sType = pType;\
		}\
		static Type** GetTypeAddress()\
		{\
			return &sType;\
		}\
	private:\
		static inline Type* sType = nullptr;\
	};
#define GENERATE_CLASS_PRIMITIVE(type)\
	class type;\
	template<>\
	class TypeAccessor<type>\
	{\
		friend class TypeDispatcher;\
	public:\
		static Type* GetType()\
		{\
			return sType;\
		}\
	private:\
		static void SetType(Type* pType)\
		{\
			sType = pType;\
		}\
		static Type** GetTypeAddress()\
		{\
			return &sType;\
		}\
	private:\
		static inline Type* sType = nullptr;\
	};
#define GENERATE_ENUMCLASS_PRIMITIVE(type,dataType)\
	enum class type : dataType;\
	template<>\
	class TypeAccessor<type>\
	{\
		friend class TypeDispatcher;\
	public:\
		static Type* GetType()\
		{\
			return sType;\
		}\
	private:\
		static void SetType(Type* pType)\
		{\
			sType = pType;\
		}\
		static Type** GetTypeAddress()\
		{\
			return &sType;\
		}\
	private:\
		static inline Type* sType = nullptr;\
	};
}
