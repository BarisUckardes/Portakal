#include "DirectInputSubsystem.h"
#include <Runtime/DirectInput/DirectInputKeyboard.h>
#include <Runtime/DirectInput/DirectInputMouse.h>

namespace Portakal
{

    struct DirectInputEnumProcContext
    {
        Array<InputDevice*> Devices;
        IDirectInput8* Input;
    };
    Bool8 DirectInputSubsystem::Initialize()
    {
        //Validate
        if (sInput != nullptr)
            return true;

        //Create input
        if (FAILED(DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&sInput, NULL)))
        {
            DEV_LOG("DirectInputSubsystem","Failed to initialize!");
            return false;
        }

        DEV_LOG("DirectInputSubsystem", "Initialized");
        return true;
    }
    BOOL CALLBACK EnumDeviceProc(LPCDIDEVICEINSTANCE instance, LPVOID pUserData)
    {
        const UInt64 deviceType = GET_DIDEVICE_TYPE(instance->dwDevType);
        DirectInputEnumProcContext* pContext = (DirectInputEnumProcContext*)pUserData;

        //Validate if devices are keyboard,mouse,gamepad etc.
        if (!(deviceType == DI8DEVTYPE_KEYBOARD || deviceType == DI8DEVTYPE_MOUSE))
            return DIENUM_CONTINUE;

        //Create device
        IDirectInputDevice8* pDevice = nullptr;
        if (pContext->Input->CreateDevice(instance->guidInstance, &pDevice, nullptr) != DI_OK)
            return DIENUM_CONTINUE;

        switch (deviceType)
        {
        case DI8DEVTYPE_KEYBOARD:
        {
            InputDevice* inputDevice = new DirectInputKeyboard(pDevice);
            inputDevice->SetName(instance->tszProductName);
            pContext->Devices.Add(inputDevice);
            break;
        }
        case DI8DEVTYPE_MOUSE:
        {
            InputDevice* inputDevice = new DirectInputMouse(pDevice);
            inputDevice->SetName(instance->tszProductName);
            pContext->Devices.Add(inputDevice);
            break;
        }
        case DI8DEVTYPE_JOYSTICK:
        case DI8DEVTYPE_GAMEPAD:
        default:
            return DIENUM_CONTINUE;
        }

        return DIENUM_CONTINUE;
    }
    void DirectInputSubsystem::GetInputDevices(Array<SharedHeap<InputDevice>>& devicesOut)
    {
        DirectInputEnumProcContext context = {};
        context.Input = sInput;
        if (FAILED(sInput->EnumDevices(DI8DEVCLASS_ALL,EnumDeviceProc,&context,DIEDFL_ATTACHEDONLY)))
        {
            DEV_LOG("DirectInputSubsystem", "Failed to enum devices");
            return;
        }

        for (auto& device : context.Devices)
            devicesOut.Add(device);
    }
}
