#pragma once

#include "syati.h"

class StarCounter : public LayoutActor {
public: 
    StarCounter();
    virtual ~StarCounter();
    virtual void init(const JMapInfoIter&);
    virtual void appear();
    virtual void kill();
    virtual void control();
    void disappear();
    bool isWait() const;
    void exeCountUp();
    void exeDisappear();

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