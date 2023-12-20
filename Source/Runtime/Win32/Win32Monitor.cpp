#include "Win32Monitor.h"

namespace Portakal
{
#define WIN32_MAX_MONITORS 32
    struct MonitorProcData
    {
        HMONITOR Monitors[WIN32_MAX_MONITORS];
        unsigned int ProcIndex;
    };
    BOOL CALLBACK MonitorEnumProc(HMONITOR monitor, HDC monitorContext, LPRECT rect, LPARAM userData)
    {
        MonitorProcData* pData = (MonitorProcData*)userData;
        pData->Monitors[pData->ProcIndex] = monitor;
        pData->ProcIndex++;

        return TRUE;
    }
    Array<SharedHeap<PlatformMonitor>> Win32Monitor::GetAvailableMonitors()
    {
        const HINSTANCE processHandle = GetModuleHandle(NULL);

        MonitorProcData procData = {};
        procData.ProcIndex = 0;
        if (EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, (LPARAM)&procData) == 0)
        {
            return {};
        }

        Array<SharedHeap<PlatformMonitor>> monitors;
        for (unsigned int monitorIndex = 0; monitorIndex < procData.ProcIndex; monitorIndex++)
        {
            const HMONITOR monitorHandle = procData.Monitors[monitorIndex];

            MONITORINFOEX monitorInformation;
            monitorInformation.cbSize = sizeof(monitorInformation);
            if (GetMonitorInfo(monitorHandle, &monitorInformation) == 0)
            {
                continue;
            }

            DEVMODE  currentDisplayModeWin32 = {};
            currentDisplayModeWin32.dmSize = sizeof(currentDisplayModeWin32);
            if (EnumDisplaySettings(monitorInformation.szDevice, ENUM_CURRENT_SETTINGS, &currentDisplayModeWin32) == 0)
            {

            }
            MonitorDisplayMode currentDisplayMode = {};
            currentDisplayMode.BitsPerPixel = currentDisplayModeWin32.dmBitsPerPel;
            currentDisplayMode.RefreshRate = currentDisplayModeWin32.dmDisplayFrequency;
            currentDisplayMode.Width = currentDisplayModeWin32.dmPelsWidth;
            currentDisplayMode.Height = currentDisplayModeWin32.dmPelsHeight;


            Array<MonitorDisplayMode> displayModes;
            unsigned int modeIndex = 0;
            if (EnumDisplaySettings(monitorInformation.szDevice, 0, &currentDisplayModeWin32) == 0)
            {
                continue;
            }
            while (true)
            {
                if (EnumDisplaySettings(monitorInformation.szDevice, modeIndex, &currentDisplayModeWin32) == 0)
                    break;


                MonitorDisplayMode displayMode = {};
                displayMode.Width = currentDisplayModeWin32.dmPelsWidth;
                displayMode.Height = currentDisplayModeWin32.dmPelsHeight;
                displayMode.BitsPerPixel = currentDisplayModeWin32.dmBitsPerPel;
                displayMode.RefreshRate = currentDisplayModeWin32.dmDisplayFrequency;

                displayModes.Add(displayMode);
                modeIndex++;
            }

            Win32Monitor* pMonitor = new Win32Monitor(monitorHandle, currentDisplayMode, displayModes, monitorInformation.rcMonitor.left, monitorInformation.rcMonitor.top, monitorInformation.rcMonitor.right - monitorInformation.rcMonitor.left, monitorInformation.rcMonitor.bottom - monitorInformation.rcMonitor.top);
            pMonitor->SetName(monitorInformation.szDevice);
            DEV_LOG("Win32Monitor", "Monitor : %s", monitorInformation.szDevice);
            monitors.Add(pMonitor);
        }

        return monitors;
    }
    SharedHeap<PlatformMonitor> Win32Monitor::GetPrimaryMonitor()
    {
        //Get process handle
        const HINSTANCE processHandle = GetModuleHandle(NULL);

        //Enum monitors
        MonitorProcData procData = {};
        procData.ProcIndex = 0;
        if (EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, (LPARAM)&procData) == 0)
            return nullptr;

        //Get monitor
        const HMONITOR monitorHandle = procData.Monitors[0];

        MONITORINFOEX monitorInformation = {};
        monitorInformation.cbSize = sizeof(monitorInformation);
        if (GetMonitorInfo(monitorHandle, &monitorInformation) == 0)
            return nullptr;

        DEVMODE currentDisplayModeWin32 = {};
        currentDisplayModeWin32.dmSize = sizeof(currentDisplayModeWin32);
        if (EnumDisplaySettings(monitorInformation.szDevice, ENUM_CURRENT_SETTINGS, &currentDisplayModeWin32) == 0)
            return nullptr;

        MonitorDisplayMode currentDisplayMode = {};
        currentDisplayMode.BitsPerPixel = currentDisplayModeWin32.dmBitsPerPel;
        currentDisplayMode.RefreshRate = currentDisplayModeWin32.dmDisplayFrequency;
        currentDisplayMode.Width = currentDisplayModeWin32.dmPelsWidth;
        currentDisplayMode.Height = currentDisplayModeWin32.dmPelsHeight;

        Array<MonitorDisplayMode> displayModes;
        unsigned int modeIndex = 0;
        if (EnumDisplaySettings(monitorInformation.szDevice, 0, &currentDisplayModeWin32) == 0)
        {
            return nullptr;
        }
        while (true)
        {
            if (EnumDisplaySettings(monitorInformation.szDevice, modeIndex, &currentDisplayModeWin32) == 0)
                break;


            MonitorDisplayMode displayMode = {};
            displayMode.Width = currentDisplayModeWin32.dmPelsWidth;
            displayMode.Height = currentDisplayModeWin32.dmPelsHeight;
            displayMode.BitsPerPixel = currentDisplayModeWin32.dmBitsPerPel;
            displayMode.RefreshRate = currentDisplayModeWin32.dmDisplayFrequency;

            displayModes.Add(displayMode);
            modeIndex++;
        }
        Win32Monitor* pMonitor = new Win32Monitor(monitorHandle, currentDisplayMode, displayModes, currentDisplayModeWin32.dmPosition.x, currentDisplayModeWin32.dmPosition.y,monitorInformation.rcMonitor.right - monitorInformation.rcMonitor.left,monitorInformation.rcMonitor.bottom-monitorInformation.rcMonitor.top);
        pMonitor->SetName(monitorInformation.szDevice);
        return pMonitor;
    }
    Win32Monitor::Win32Monitor(const HMONITOR handle,
        const MonitorDisplayMode& currentDisplayMode,
        const Array<MonitorDisplayMode>& displayModes, const int32 positionX,
        const int32 positionY,const uint16 width,const uint16 height) :
        mHandle(handle), PlatformMonitor({ positionX, positionY }, {width,height}, currentDisplayMode, displayModes)
    {
       
    }
    void Win32Monitor::OnShutdown()
    {
    }
}
