#include "Bhop.h"

void bhop(float frameTime, UserCmd* cmd)
{
	IClientEntity* localPlayer = interfaces::g_IClientEntityList->GetClientEntity(1);

	if (localPlayer) {
		if (!(*reinterpret_cast<int*>(localPlayer + hazedumper::netvars::m_fFlags) & 1)) {
			cmd->buttons &= ~IN_JUMP;
		}
	}
}
