#pragma once

#include "syati.h"
#include "Game/Screen/CountUpPaneRumbler.h"

class CoinCounter : public LayoutActor {
public:
    CoinCounter(const char*);
    virtual void init(const JMapInfoIter&);
    virtual void appear();
    void forceAppear(bool);
    void disappear(bool);
    bool isWait() const;
    void forceSync();
    virtual void control();
    void updateCounter();
    void exeHide();
    void exeAppear();
    void exeWait();
    void exeDisappear();
    virtual ~CoinCounter();

    s32 mCoinNum; // 0x2C
    s32 mDisplayedCoinNum; // 0x30
    s32 _34;
    CounterLayoutAppearer* mAppearer; // 0x38
    CountUpPaneRumbler* mPaneRumbler; // 0x3C
    bool _40;
    TVec2f mFollowPos; // 0x44
    bool _4C;
};

namespace NrvCoinCounter {
    NERVE(CoinCounterNrvHide);
    NERVE(CoinCounterNrvAppear);
    NERVE(CoinCounterNrvWait);
    NERVE(CoinCounterNrvDisappear);
};