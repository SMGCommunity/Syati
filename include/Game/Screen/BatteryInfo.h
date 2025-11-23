#pragma once

#include "revolution.h"
#include "Game/Screen/LayoutActor.h"
#include "Game/System/NerveExecutor.h"

class BatteryInfo : public NerveExecutor {
public:
    BatteryInfo(LayoutActor *, const char *, s32);
    void exeEnought();
    void exeLowAppear();
    void exeLow();
    void exeLowHide();
    void exeCriticalAppear();
    void exeCritical();
    void exeNoneAppear();
    void exeNone();
    void exeNoneHide();
    bool exeStartAnimAndSetNerveIfStopped(const char *, const Nerve *);
    bool tryChangeNerveWithBatteryLeftAlreadyAppear();

    LayoutActor *mBatteryLayout;    // _8
    const char *pName;              // _C
    s32 mId;                        // _10
};

namespace NrvBatteryInfo {
    NERVE(BatteryInfoEnought);
    NERVE(BatteryInfoLowAppear);
    NERVE(BatteryInfoLow);
    NERVE(BatteryInfoLowDisappear);
    NERVE(BatteryInfoLowHide);
    NERVE(BatteryInfoDisappear);
    NERVE(BatteryInfoCriticalAppear);
    NERVE(BatteryInfoCritical);
    NERVE(BatteryInfoNoneAppear);
    NERVE(BatteryInfoNone);
    NERVE(BatteryInfoNoneDisappear);
    NERVE(BatteryInfoNoneHide);
};

class BatteryLayout : public LayoutActor {
public:
    BatteryLayout(const char *, bool);
    ~BatteryLayout();
    virtual void init(const JMapInfoIter &rIter);
    virtual void appear();
    virtual void control();

    BatteryInfo *mWinBatteryInfo1;  // _2C
    BatteryInfo *mWinBatteryInfo2;  // _30
};