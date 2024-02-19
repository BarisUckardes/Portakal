#include "Win32Error.h"
#include <Runtime/Containers/Array.h>
#include <Windows.h>

namespace Portakal
{
	String Win32Error::GetCurrentError()
	{
        /**
        * Get error message id
        */
        const DWORD errorMessageID = GetLastError();
        if (errorMessageID == 0)
            return "";

        LPSTR messageBuffer = NULL;

        /**
         * Get message string from win32
         */
        const UInt64 sizeInBytes = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

        String message(messageBuffer, sizeInBytes);

        LocalFree(messageBuffer);

        return message;
	}
}
