#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "../csgo_main_brunch/interfaces/Interfaces.h"
#include "../csgo_main_brunch/hooks/MinHook.h"
#include "../csgo_main_brunch/interfaces/UserCmd.h"
#include "../csgo_main_brunch/offsets/csgo.hpp"
#include "hooks/game_hooks/Hook.h"

BOOL WINAPI MainThread(HMODULE instance) {
	/*AllocConsole();
	FILE* file;
	freopen_s(&file, "OUT$", "w", stdout);*/

	/*if (file)
		fclose(file);

	FreeConsole();*/

	initInterfaces();
	SetupHooks();

	while (!GetAsyncKeyState(VK_END)) {
		CallCreateMoveHook();
		Sleep(200);
	}

	WrapHooks();
	FreeLibraryAndExitThread(instance, 0);
	return FALSE;
}

BOOL APIENTRY DllMain(HMODULE instance, DWORD reason, LPVOID reserved) {
	switch (reason) {
	case DLL_PROCESS_ATTACH:
		const auto thread = CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread), instance, 0, nullptr);
		if (thread)
			CloseHandle(thread);
	}
	return TRUE;
}