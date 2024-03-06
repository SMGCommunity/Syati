#pragma once

#include "syati.h"

class StarPieceCounter : public LayoutActor {
public: 
    StarPieceCounter(const char*);
    virtual void init(const JMapInfoIter&);
    virtual void appear();
    void forceAppear(bool);
    virtual void disappear(bool);
    bool isWait() const;
    void forceSync();
    bool tryOnModeTicoEat(bool);
    bool tryOffModeTicoEat();
    void control();
    void updateCounter();
    void updateCounterValue();
    bool isValidAppearSituation() const;
    bool tryChangeModeTicoEat(int);
    void exeHide();
    void exeAppear();
    void exeWait();
    void exeDisappear();
    virtual ~StarPieceCounter();

    s32 mStarPieceNum; // 0x2C
    s32 mDisplayStarPieceNum; // 0x30
    s32 _34;
    CounterLayoutAppearer* mAppearer; // 0x38
    CountUpPaneRumbler* mPaneRumbler; // 0x3C
    TVec2f mFollowPos; // 0x40
    s32 _48;
    s32 _4C;
};

namespace NrvStarPieceCounter {
    NERVE(StarPieceCounterNrvHide);
    NERVE(StarPieceCounterNrvAppear);
    NERVE(StarPieceCounterNrvWait);
    NERVE(StarPieceCounterNrvDisappear);
};
