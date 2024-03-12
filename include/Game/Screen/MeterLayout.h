#pragma once

#include "syati.h"

class MeterLayout : public LayoutActor {
public:
    MeterLayout(const char*, const char*);
    virtual ~MeterLayout();
    virtual void init(const JMapInfoIter&);
    virtual void control();
    void requestActive();
    void requestDeactivate();
    void requestPowerUp();
    void requestForceAppear();
    void requestPlayerMoving();
    void requestPlayerStopped();
    void initCount(s32);
    void setCount(s32);
    void exeAppear();
    void exeWaitStart();
    void exeWait();
    void exePowerUp();
    void exeMeterMove();
    void exeCounterMove();
    void exeRecover();
    void exeDamage();
    void exeBreakMeter();
    void exeZeroMeter();
    void exeZeroMeterBreak();
    void calcMarioHeadPosition(TVec2f*) const;
    void calcPowerUpMeterBasePosition(TVec2f*) const;
    void setAnimBase();
    void setCountAnimFrame();
    void setRecoveryCountAnimFrame();

    CountUpPaneRumbler* mPaneRumbler; // 0x2C
    s32 _30;
    s32 _34;
    TVec2f mFollowPosHPMeter; // 0x38
    TVec2f mFollowPosHitPointW; // 0x40
    f32 _48;
    f32 _4C;
    s32 _50;
    f32 _54;
    f32 _58;
};

namespace NrvMeterLayout {
    NERVE(MeterLayoutNrvHide);
    NERVE(MeterLayoutNrvAppear);
    NERVE(MeterLayoutNrvWait);
    NERVE(MeterLayoutNrvWaitStart);
    NERVE(MeterLayoutNrvPowerUp);
    NERVE(MeterLayoutNrvMeterMove);
    NERVE(MeterLayoutNrvCounterMove);
    NERVE(MeterLayoutNrvRecover);
    NERVE(MeterLayoutNrvDamage);
    NERVE(MeterLayoutNrvBreakMeter);
    NERVE(MeterLayoutNrvZeroMeter);
    NERVE(MeterLayoutNrvZeroMeterBreak);
};
