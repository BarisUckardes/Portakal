#pragma once

#include <Runtime/Input/KeyboardKeys.h>

namespace Portakal
{
    /**
     * @class DirectInputKeys
     * 
     * @brief Returns the Key values according to DirectInput.
     */
    class RUNTIME_API DirectInputKeys final
    {
    public:
        static KeyboardKeys GetKey(const UInt64 key);
    public:
        DirectInputKeys() = delete;
        ~DirectInputKeys() = delete;
    };

}

