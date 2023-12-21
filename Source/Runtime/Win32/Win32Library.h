#pragma once
#include <Runtime/Platform/PlatformLibrary.h>
#include <Windows.h>

namespace Portakal
{
	class RUNTIME_API Win32Library : public PlatformLibrary
	{
		friend class PlatformLibrary;
	public:
		static SharedHeap<PlatformLibrary> Load(const String& path);
	private:
		static SharedHeap<PlatformLibrary> LoadCurrent();
	public:
		Win32Library(HINSTANCE handle);
		Win32Library(const String& path);
		~Win32Library() = default;

		virtual PlatformLibraryHandle GetSymbol(const String& name) override;
		virtual void OnShutdown() override;
	private:
		HINSTANCE mHandle;
	};
}
