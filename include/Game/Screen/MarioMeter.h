#pragma once

#include "Game/Screen/MeterLayout.h"
#include "Game/Screen/SuddenDeathMeter.h"

class MarioMeter : public NameObj {
public:
    MarioMeter(const char*);
    virtual ~MarioMeter();
    virtual void init(const JMapInfoIter&);
    void initLifeCount(s32);
    void setLifeCount(s32);
    void powerUp();
    void requestForceAppearHPMeter();
    void requestPlayerMoving();
    void requestPlayerStopped();
    void activate();
    void deactivate();

    MeterLayout* mMeterLayout;
    SuddenDeathMeter* mSuddenDeathMeter;
    bool _1C;
};