#include "Win32Dialog.h"
#include <tchar.h>
#include <ShlObj_core.h>
#include <comdef.h>

namespace Portakal
{
	String Win32Dialog::CreateOpenFileDialog(const String& filter)
	{
		String output = {};
		IFileOpenDialog* pFileDialog = nullptr;
		IShellItemFilter* pFilter = nullptr;

		/*
		* Create file open dialog
		*/
		if (FAILED(CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_PPV_ARGS(&pFileDialog))))
		{
			DEV_LOG("Win32Dialog", "Failed to create CLSID_FileOpenDialog");
			return output;
		}

		/*
		* Show dialog
		*/
		if (FAILED(pFileDialog->Show(NULL)))
		{
			DEV_LOG("Win32DÝalog", "Failed to show file dialog");
			return output;
		}

		/*
		* Get result
		*/
		IShellItem* pItem = nullptr;
		if (FAILED(pFileDialog->GetResult(&pItem)))
		{
			DEV_LOG("Win32Dialog","Failed to get the result");
			return output;
		}

		/*
		* Get result display name
		*/
		PWSTR filePath;
		if (FAILED(pItem->GetDisplayName(SIGDN_FILESYSPATH, &filePath)))
		{
			DEV_LOG("Win32Dialog", "Failed to get sys path display name");
			return output;
		}

		/*
		* Get path
		*/
		_bstr_t b(filePath);
		output = b.operator const Char* ();
		CoTaskMemFree(filePath);

		pItem->Release();

		pFileDialog->Release();

		return output;
	}
	String Win32Dialog::CreateOpenFolderDialog()
	{
		String output = {};
		IFileOpenDialog* pFileDialog = nullptr;
		IShellItemFilter* pFilter = nullptr;

		/*
		* Create file open dialog
		*/
		if (FAILED(CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_PPV_ARGS(&pFileDialog))))
		{
			DEV_LOG("Win32Dialog", "Failed to create CLSID_FileOpenDialog");
			return output;
		}

		/*
		* Set only folders
		*/
		pFileDialog->SetOptions(FOS_PICKFOLDERS);

		/*
		* Show dialog
		*/
		if (FAILED(pFileDialog->Show(NULL)))
		{
			DEV_LOG("Win32DÝalog", "Failed to show file dialog");
			return output;
		}

		/*
		* Get result
		*/
		IShellItem* pItem = nullptr;
		if (FAILED(pFileDialog->GetResult(&pItem)))
		{
			DEV_LOG("Win32Dialog", "Failed to get the result");
			return output;
		}

		/*
		* Get result display name
		*/
		PWSTR filePath;
		if (FAILED(pItem->GetDisplayName(SIGDN_FILESYSPATH, &filePath)))
		{
			DEV_LOG("Win32Dialog", "Failed to get sys path display name");
			return output;
		}

		/*
		* Get path
		*/
		_bstr_t b(filePath);
		output = b.operator const Char* ();
		CoTaskMemFree(filePath);

		pItem->Release();

		pFileDialog->Release();

		return output;
	}
}
