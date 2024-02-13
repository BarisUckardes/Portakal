#pragma once
#include <Runtime/Reflection/Type.h>
#include <Runtime/Reflection/FieldMode.h>

namespace Portakal
{
	/// <summary>
	/// Type dispatcher utilities
	/// </summary>
	class RUNTIME_API TypeDispatcher final
	{
	public:
		static Type* CreateType(const String& name, const UInt32, const TypeModes mode, const TypeCodes code, const DefaultHeapObjectGenerator generator,Type** ppAddress);
		static void RegisterEnum(const String& name, const Int64 value, Type* pTargetType);
		static void RegisterField(const String& name, const UInt32 offset, Type* pFieldType,const FieldMode mode, Type* pTargetType);
		static void SetBaseType(Type* pTargetType, Type* pBaseType);
		static Type** GetTypeAddress(Type* pType);

		template<typename T>
		static Type** GetTypeAddress()
		{
			return TypeAccessor<T>::GetTypeAddress();
		}
		template<typename T>
		static void SetTypeAddress(Type* pType)
		{
			TypeAccessor<T>::SetType(pType);
		}
		template<typename T,typename... TArgs>
		static void RegisterAttribute(Type* pTargetType,TArgs... args)
		{
			T* pAttribute = new T(args...);
			pTargetType->_RegisterAttribute(pAttribute);
		}

		template <typename T1, typename T2>
		static inline size_t constexpr OffsetOf(T1 T2::* member)
		{
			T2 object{};
			return size_t(&(object.*member)) - size_t(&object);
		}
	public:
		TypeDispatcher() = delete;
		~TypeDispatcher() = delete;
	};
}
