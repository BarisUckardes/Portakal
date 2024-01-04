#pragma once
#include <Runtime/Reflection/Type.h>
#include <Runtime/Reflection/FieldMode.h>

namespace Portakal
{
	class RUNTIME_API Field final
	{
		friend class TypeDispatcher;
	public:
		FORCEINLINE String GetName() const noexcept
		{
			return mName;
		}
		FORCEINLINE const Type* GetType() const noexcept
		{
			return mFieldType;
		}
		FORCEINLINE const Type* GetArrayElementType() const noexcept
		{
			return mArrayElementType;
		}
		FORCEINLINE FieldMode GetMode() const noexcept
		{
			return mMode;
		}
		FORCEINLINE Uint32 GetOffset() const noexcept
		{
			return mOffset;
		}

		template<typename TValue>
		void SetValue(void* pObject, const TValue& value) const noexcept
		{
			Byte* pObjectByte = (Byte*)pObject + mOffset;
			TValue* pValue = (TValue*)pObjectByte;
			*pValue = value;
		}
		template<typename TValue>
		TValue GetValue(const void* pObject) const noexcept
		{
			Byte* pObjectByte = (Byte*)pObject + mOffset;
			return *(TValue*)pObjectByte;
		}
		template<typename TAddress>
		TAddress* GetAddress(void* pObject) const noexcept
		{
			Byte* pObjectByte = (Byte*)pObject + mOffset;
			return (TAddress*)pObjectByte;
		}
	private:
		Field(const String& name,const Type* pFieldType,const FieldMode mode,const Uint32 offset);
		~Field();
	private:
		const String mName;
		const Type* mFieldType;
		const Type* mArrayElementType;
		const FieldMode mMode;
		const Uint32 mOffset;

	};
}
