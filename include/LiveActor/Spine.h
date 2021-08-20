#pragma once

#include "System/Nerve/Nerve.h"

class ActorStateKeeper;

class Spine
{
public:
    Spine(void *pExecutor, const Nerve *pNerve, s32 stateKeeperSize);

    void update();
    void setNerve(const Nerve *pNextNerve);
    const Nerve* getCurrentNerve() const;
    void changeNerve();

    void* mExecutor; // _0
    const Nerve* mCurState; // _4
    const Nerve* mNextState; // _8
    u32 mNerveStep; // _C
    ActorStateKeeper* mStateKeeper; // _10
};
