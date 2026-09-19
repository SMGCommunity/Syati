#pragma once

#include "Game/LiveActor/LiveActor.h"

/* FINISHED */

class WaterFortressRain : public LiveActor {
public:
    WaterFortressRain(const char *pName);

    virtual void init(const JMapInfoIter &rIter);
    virtual void control();

    void exeRain();
    void exeRainSlow();

    /* 0x90 */ TMtx34f mRainEffectMtx;
};

namespace NrvWaterFortressRain {
    NERVE(WaterFortressRainNrvRain);
    NERVE(WaterFortressRainNrvRainSlow);
}
