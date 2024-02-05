#pragma once
#include <Runtime/Reflection/Reflection.h>
#include "CustomResourceDeserializer.reflected.h"

namespace Portakal
{
	PCLASS();

	/// <summary>
	/// Attribute for marking a class as resource deserializer
	/// </summary>
	class RUNTIME_API CustomResourceDeserializer : public Attribute
	{
		GENERATE_OBJECT;
	public:
		CustomResourceDeserializer(const String& type) : mType(type)
		{

		}
		CustomResourceDeserializer() : mType("")
		{

		}
		~CustomResourceDeserializer() = default;

		FORCEINLINE String GetResourceType() const noexcept
		{
			return mType;
		}
	private:
		const String mType;
	};
}



































































































































