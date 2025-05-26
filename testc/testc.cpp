#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>

DWORD getProcessIdByName(const wchar_t* procName) {
	DWORD procId = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);



	if (hSnap != INVALID_HANDLE_VALUE) {
		PROCESSENTRY32W procEntry;
		procEntry.dwSize = sizeof(procEntry);


		if (Process32First(hSnap, &procEntry)) {
			do {
				if (!_wcsicmp(procEntry.szExeFile, procName)) {
					procId = procEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}

	CloseHandle(hSnap);
	return procId;
}

int main() {
	const wchar_t* gameName = L"ac_client.exe";
	DWORD procId = getProcessIdByName(gameName);

	if (procId == 0) {
		std::cout << "Process not found: " << &gameName << std::endl;
		return 1;
	}
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);

	if (!hProcess) {
		std::cout << "error accessing process" << std::endl;
		return 1;
	}
	uintptr_t ammoAdress = 0x0077A250; // найденный адрес через cheat engine
	int ammoValue = 1337; // количество патронов

	WriteProcessMemory(hProcess, (LPVOID)ammoAdress, &ammoValue, sizeof(ammoValue), nullptr);
	std::cout << "Ammo value set to: " << ammoValue << std::endl;

	CloseHandle(hProcess);
	return 0;
}