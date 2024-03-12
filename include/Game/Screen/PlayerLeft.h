#pragma once

#include "syati.h"

class PlayerLeft : public LayoutActor {
public:
    PlayerLeft(const char*);
    virtual ~PlayerLeft();
    virtual void init(const JMapInfoIter&);
    virtual void appear();
    virtual void control();
    void forceAppear();
    void disappear();
    bool isWait() const;
    void exeHide();
    void exeAppear();
    void exeWait();
    void exeDisappear();
    s32 mNumPlayersLeft; // 0x2C
    CounterLayoutAppearer* mAppearer; // 0x30
    CountUpPaneRumbler* mPaneRumbler; // 0x34
    s32 _38;
};

namespace NrvPlayerLeft {
    NERVE(PlayerLeftNrvHide);
    NERVE(PlayerLeftNrvAppear);
    NERVE(PlayerLeftNrvWait);
    NERVE(PlayerLeftNrvDisappear);
};