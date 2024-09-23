#pragma once

#include "syati.h"

class PurpleCoinCounter : public LayoutActor {
public:
    PurpleCoinCounter(const char*);
    virtual ~PurpleCoinCounter();
    virtual void init(const JMapInfoIter&);
    virtual void appear();
    void validate();
    virtual void control();
    void updateCounter();
    void exeAppear();

    s32 mPurpleCoinNum; // 0x2C
    s32 mDisplayedPurpleCoinNum; // 0x30
    s32 _34;
    CounterLayoutAppearer* mCounterLayoutAppearer; // 0x38
    CountUpPaneRumbler* mPaneRumbler; // 0x3C
    bool isValidated; // 0x40
};

namespace NrvPurpleCoinCounter {
    NERVE(PurpleCoinCounterNrvWait);
    NERVE(PurpleCoinCounterNrvAppear);
};