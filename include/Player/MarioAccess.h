#pragma once

#include "kamek.h"

class LiveActor;

class MarioAccess
{
public:
    static LiveActor* getPlayerActor();
    
    static void forceKill(u32, u32);
};