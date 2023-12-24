#pragma once
#include <Runtime/Reflection/Type.h>

namespace Portakal
{
	class RUNTIME_API TypeDispatcher final
	{
	public:
		static Type* CreateType(const String& name, const uint32, const TypeModes mode, const TypeCodes code, const DefaultHeapObjectGenerator generator,Type** ppAddress);
		static void RegisterEnum(const String& name, const int64 value, Type* pTargetType);
		static void RegisterField(const String& name, const uint32 offset, Type* pFieldType, Type* pTargetType);
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
	public:
		TypeDispatcher() = delete;
		~TypeDispatcher() = delete;
	};
}
