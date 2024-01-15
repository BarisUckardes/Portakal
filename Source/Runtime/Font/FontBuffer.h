#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Object/Object.h>

#include <Runtime/Font/FontBufferDesc.h>

namespace Portakal
{
	/**
	 * @class FontBuffer
	 * 
	 * @brief Holds the whole font buffer for per ttf/otf file.
	 */
	class RUNTIME_API FontBuffer : public Object
	{
	public:
		FontBuffer(const FontBufferDesc& desc);
		FontBuffer(const FontBuffer&) = delete;
		FontBuffer& operator=(const FontBuffer&) = delete;
		virtual ~FontBuffer() = default;

		FORCEINLINE UInt32 GetRows() const noexcept { return mRows; }
		FORCEINLINE UInt32 GetWidth() const noexcept { return mWidth; }
		FORCEINLINE Int32 GetPitch() const noexcept { return mPitch; }
		FORCEINLINE Byte* GetBuffer() const noexcept { return mBuffer; }
		FORCEINLINE UInt32 GetStandardPixelSize() const noexcept { return mStandardPixelSize; }

		FORCEINLINE FontPixelMode GetPixelMode() const noexcept { return mPixelMode; }
		FORCEINLINE FontThickness GetThickness() const noexcept { return mThickness; }
		FORCEINLINE FontStyle GetStyle() const noexcept { return mStyle; }

		virtual void OnShutdown() override {};

	private:
		UInt32 mRows;
		UInt32 mWidth;
		Int32 mPitch;
		Byte* mBuffer;
		UInt32 mStandardPixelSize;

		FontPixelMode mPixelMode;
		FontThickness mThickness;
		FontStyle mStyle;
	};
}
