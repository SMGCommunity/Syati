#pragma once

#include "revolution.h"
#include "Game/Player/MarioModule.h"

class MarioActor;
class MarioState;

class Mario : public MarioModule {
public:
    Mario(MarioActor *pMarioActor);

    void initMember();
    
    bool isStatusActive(u32 statusCode) const;
    void closeStatus(MarioState*);

    void playSoundTrampleCombo(u8);
    
    void tryJump();
    void trySquatJump();
    void resetSleepTimer();

    void updateCubeCode();
    void updateCometCode();
    void updateOnSand();
    void updateOnPoison();

    bool isCurrentFloorSink() const;
    bool checkCurrentFloorCodeSevere(u32) const;

    u8 _0[0xA9C];
};
