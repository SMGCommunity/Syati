#pragma once

#include "Game/Screen/LayoutActor.h"

class YoshiTargetMark : public LayoutActor {
public:
    YoshiTargetMark(const char *);
    virtual ~YoshiTargetMark();
    virtual void init(const JMapInfoIter &);
    virtual void appear();
    virtual void exeAppear();
    virtual void exeDisappear();
    virtual void control();
};

namespace NrvYoshiTargetMark {
    NERVE(YoshiTargetMarkNrvAppear);
    NERVE(YoshiTargetMarkNrvWait);
    NERVE(YoshiTargetMarkNrvDisappear);
}