#pragma once
#include <Runtime/Reflection/Reflection.h>
#include "CustomObjectPainter.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API CustomObjectPainter : public Attribute
	{
		GENERATE_OBJECT;
	public:
		CustomObjectPainter(Type* pTargetType) : mTargetType(pTargetType)
		{

		}
		CustomObjectPainter() : mTargetType(nullptr)
		{

		}
		~CustomObjectPainter() = default;

		FORCEINLINE Type* GetTargetType() const noexcept
		{
			return mTargetType;
		}
	private:
		Type* mTargetType;
	};
}

