#pragma once
#include <Runtime/Reflection/Type.h>
#include <Runtime/Reflection/FieldMode.h>

namespace Portakal
{
	/// <summary>
	/// Representing data fields within the Type information
	/// </summary>
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
		FORCEINLINE FieldMode GetMode() const noexcept
		{
			return mMode;
		}
		FORCEINLINE UInt32 GetOffset() const noexcept
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
		Field(const String& name,const Type* pFieldType,const FieldMode mode,const UInt32 offset);
		~Field();
	private:
		const String mName;
		const Type* mFieldType;
		const FieldMode mMode;
		const UInt32 mOffset;

	};
}
