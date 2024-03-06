#pragma once

#include "syati.h"

class StarCounter : public LayoutActor {
public: 
    StarCounter();
    virtual void init(const JMapInfoIter&);
    virtual void appear();
    virtual void kill();
    void disappear();
    bool isWait() const;
    virtual void control();
    void exeCountUp();
    void exeDisappear();
    virtual ~StarCounter();

    s32 mPowerStarNum; // 0x2C
    CounterLayoutAppearer* mAppearer; // 0x30
    CountUpPaneRumbler* mPaneRumbler; // 0x34
};

namespace NrvStarCounter {
    NERVE(StarCounterNrvAppear);
    NERVE(StarCounterNrvWait);
    NERVE(StarCounterNrvCountUp);
    NERVE(StarCounterNrvDisappear);
};