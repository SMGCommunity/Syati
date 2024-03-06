#pragma once

#include "syati.h"

class PlayerLeft : public LayoutActor {
public:
    PlayerLeft(const char*);
    virtual void init(const JMapInfoIter&);
    virtual void appear();
    void forceAppear();
    void disappear();
    bool isWait() const;
    virtual void control();
    void exeHide();
    void exeAppear();
    void exeWait();
    void exeDisappear();
    virtual ~PlayerLeft();

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