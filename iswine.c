#include <windows.h>
#include <ddk/ntapi.h>
#include <stdio.h>

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

	char szWineVersion[256] = { 0 };

	if (NtQuerySystemInformation((SYSTEM_INFORMATION_CLASS) 1000, szWineVersion, sizeof(szWineVersion), NULL) == 0)
	{
		char* pVer = szWineVersion;
		char* pBuild = pVer + strlen(pVer) + 1;
		char* pSysName = pBuild + strlen(pBuild) + 1;
		char* pRelease = pSysName + strlen(pSysName) + 1;
		char szWineStr[512] = { 0 };
		snprintf(szWineStr,
			sizeof(szWineStr),
			"Wine version: %s\r\nWine build: %s\r\nHost system: %s\r\nHost release: %s",
			pVer, pBuild, pSysName, pRelease);
		MessageBoxA(NULL, szWineStr, "Is Wine?", MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		MessageBoxA(NULL, "You are not running under Wine...", "Is Wine?", MB_OK | MB_ICONERROR);
	}
	return 0;
}
