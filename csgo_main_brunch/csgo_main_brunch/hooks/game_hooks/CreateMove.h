#pragma once
#include "../../interfaces/UserCmd.h"
#include "../../interfaces/Interfaces.h"
#include "../../offsets/csgo.hpp"
#include "../MinHook.h"
#include "../../hacks/Bhop.h"

using CreateMove = bool(__thiscall*)(void*, float, UserCmd*);
static CreateMove CreateMoveOriginal = nullptr;

bool __stdcall CreateMoveHook(float frameTime, UserCmd* cmd);

void CallCreateMoveHook();