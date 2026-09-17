#pragma once

#include "Game/NPC/NPCActor.h"

class TicoStateEatCoin;

class TicoFatCoin : public NPCActor {
public:
    TicoFatCoin(const char *pName);
    virtual ~TicoFatCoin();
    virtual void init(const JMapInfoIter &rIter);
    virtual void control();
    virtual void initAfterPlacement();

    bool branchFunc(u32);
    bool eventFunc(u32);

    s32 mRequiredCoins;     // _164
    ActorCameraInfo *_168;
    TicoStateEatCoin *_16C;
    Mtx _170;
    Mtx _1A0;
};

// Nerves