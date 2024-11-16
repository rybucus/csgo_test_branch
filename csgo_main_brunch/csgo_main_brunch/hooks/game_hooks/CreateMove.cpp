#include "CreateMove.h"

bool __stdcall CreateMoveHook(float frameTime, UserCmd* cmd)
{
	bool result = CreateMoveOriginal(interfaces::g_ClientMode, frameTime, cmd);

	if (!cmd || !cmd->commandNumber)
		return result;

	bhop(frameTime, cmd);

	/*
	static unsigned int clientDll = reinterpret_cast<unsigned int>(GetModuleHandle("client.dll"));

	if (!clientDll) {
		MessageBoxA(0, "clientDll", "bad", MB_OK);
	}

	const unsigned int localPlayer = *reinterpret_cast<unsigned int*>(clientDll + hazedumper::signatures::dwLocalPlayer);

	if (!localPlayer) {
		MessageBoxA(0, "localPlayer", "bad", MB_OK);
	}

	if (localPlayer) {
		if (!(*reinterpret_cast<int*>(localPlayer + hazedumper::netvars::m_fFlags) & 1)) {
			cmd->buttons &= ~IN_JUMP;
		}
	}*/ // бяе щрн онидер б shell();

	return false;
}

void CallCreateMoveHook()
{
	MH_CreateHook(
		(*static_cast<void***>(interfaces::g_ClientMode))[24],
		&CreateMoveHook,
		reinterpret_cast<void**>(&CreateMoveOriginal)
	);

	MH_EnableHook(MH_ALL_HOOKS);
}
