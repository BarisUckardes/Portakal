#pragma once
#include <Runtime/Reflection/Reflection.h>
#include "CustomComponentPainter.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API CustomComponentPainter : public Attribute
	{
		GENERATE_OBJECT;
	public:
		CustomComponentPainter(const Type* pType) : mTargetType(pType)
		{

		}
		CustomComponentPainter() : mTargetType(nullptr)
		{

		}
		~CustomComponentPainter() = default;

		FORCEINLINE const Type* GetTargetType() const noexcept
		{
			return mTargetType;
		}
	private:
		const Type* mTargetType;
	};
}


