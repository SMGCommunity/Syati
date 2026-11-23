#pragma once

#include "syati.h"

class SuddenDeathMeter : public LayoutActor {
public:
    SuddenDeathMeter(const char *, const char *);
    virtual ~SuddenDeathMeter();
    virtual void init(const JMapInfoIter &rIter);
    virtual void control();

    void initCount(s32);
    void setCount(s32);
    void setPowerUpMeterPosition(const TVec2f &);
    void setCountAnimFrame();
    void setRecoveryCountAnimFrame();

    void calcMarioHeadPosition(TVec2f *) const;
    void calcPowerUpMeterBasePosition(TVec2f *) const;
    
    void requestActive();
    void requestDeactivate();
    void requestPowerUp();
    void requestForceAppear();
    void requestPlayerMoving();
    
    void exeAppear();
    void exeWait();
    void exePowerUp();
    void exeMeterMove();
    void exeCounterMove();
    void exeBreakMeter();
    void exeZeroMeter();
    void exeZeroMeterBreak();

    CountUpPaneRumbler *mCountUpPaneRumbler;    // _2C
    TVec2f _30;
    TVec2f _38;
    s32 mCount;                                 // _40
    f32 _44;
    f32 _48;
};

namespace NrvSuddenDeathMeter {
    NERVE(SuddenDeathMeterNrvAppear);
    NERVE(SuddenDeathMeterNrvWait);
    NERVE(SuddenDeathMeterNrvPowerUp);
    NERVE(SuddenDeathMeterNrvMeterMove);
    NERVE(SuddenDeathMeterNrvCounterMove);
    NERVE(SuddenDeathMeterNrvBreakMeter);
    NERVE(SuddenDeathMeterNrvZeroMeter);
    NERVE(SuddenDeathMeterNrvZeroMeterBreak);
};