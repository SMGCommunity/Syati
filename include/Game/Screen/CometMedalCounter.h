#pragma once

#include "syati.h"

class CometMedalCounter : public LayoutActor {
public:
    CometMedalCounter();
    virtual ~CometMedalCounter();
    virtual void init(const JMapInfoIter&);
    virtual void appear();
    void forceAppear();
    void disappear();
    bool isWait() const;
    void control();
    bool isAppearInCurrentScenario() const;
    void exeAppear();
    void exeWait();
    void exeFlash();
    void exeDisappear();

    s32 _2C;
    CounterLayoutAppearer* mAppearer; // 0x30;
    f32 _34;
    f32 _38;
    bool mIsCollected; // 0x3C
    bool _3D;
};

namespace NrvCometMedalCounter {
    NERVE(CometMedalCounterNrvDisappear);
    NERVE(CometMedalCounterNrvFlash);
    NERVE(CometMedalCounterNrvWait);
    NERVE(CometMedalCounterNrvAppear);
    NERVE(CometMedalCounterNrvHidden);
};