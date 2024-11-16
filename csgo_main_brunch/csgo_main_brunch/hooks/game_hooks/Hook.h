#pragma once
#include "Windows.h"
#include "CreateMove.h"
#include "../MinHook.h"
#include "../../interfaces/Interfaces.h"

void SetupHooks() {
	MH_Initialize();
}

void WrapHooks() {
	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize();
}