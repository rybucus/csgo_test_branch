#pragma once
#include "GetInterface.h"
#include "IBaseClientDll.h"
#include "IClientEntityList.h"

namespace interfaces {
	static IBaseClientDLL* g_IBaseClientDll = nullptr;
	static void* g_ClientMode = nullptr;
	static IClientEntityList* g_IClientEntityList = nullptr;
}

inline void initInterfaces(void) {
	interfaces::g_IBaseClientDll = GetInterface<IBaseClientDLL>("client.dll", "VClient018");
	interfaces::g_IClientEntityList = GetInterface<IClientEntityList>("client.dll", "VClientEntityList003");
	interfaces::g_ClientMode = **reinterpret_cast<void***>(((*reinterpret_cast<unsigned int**>(interfaces::g_IBaseClientDll))[10] + 5));
}