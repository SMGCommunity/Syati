#pragma once

#include "syati.h"

class MeterLayout;
class SuddenDeathMeter;

class MarioMeter : public NameObj {
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