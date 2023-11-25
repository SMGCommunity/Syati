#pragma once

#include "revolution.h"

class MarioActor;
class MarioState;

class Mario {
public:
    Mario(MarioActor *pMarioActor);

    void initMember();
    
    bool isStatusActive(u32 statusCode) const;
    void closeStatus(MarioState*);

    u8 _0[0xA9C];
};
