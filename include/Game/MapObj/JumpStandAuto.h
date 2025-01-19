#pragma once

#include "Game/LiveActor.h"

class JumpStandAuto : public LiveActor {
public:
    JumpStandAuto(const char *);
    ~JumpStandAuto();
    virtual void init(const JMapInfoIter &);
    virtual void attackSensor(HitSensor *, HitSensor *);
    void exeWait();
    void exeExtend();
    void jumpPlayer(f32);
};

namespace NrvJumpStandAuto {
    NERVE(JumpStandAutoNrvWait);
    NERVE(JumpStandAutoNrvExtend);
};