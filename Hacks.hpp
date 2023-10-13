#pragma once
#include <Windows.h>
#include <Psapi.h>

struct HACK {
	UINT64 dwAddress;
	BYTE* szOriginalBytes;
	BYTE* szNewBytes;
	INT nSize;
};

namespace Hacks
{
	VOID WriteHackBytes(HACK hHack, BOOL bEnable);

	namespace Resource
	{
		VOID ReduceRAM();
	}

	namespace Window
	{
		VOID SetTransparent(HWND hWindow);
		VOID DisableTransparent(HWND hWindow);
	}

}