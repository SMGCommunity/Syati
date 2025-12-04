#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/LiveActorGroup.h"

class InfernoMario;

class InfernoMarioGenerator : public LiveActor {
public:
    InfernoMarioGenerator(const char *pName);
    ~InfernoMarioGenerator();
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void init(const JMapInfoIter &rIter);
    virtual void control();

    LiveActorGroup *mInfernoMarioGroup; // _90
    u32 _94;
    u32 mCount;                         // _98
    u32 _9C;
    u32 _A0;
    s32 _A4;
    u8 _A8;
};

namespace NrvInfernoMarioGenerator {
    NERVE(unk_807DA4D8);
    NERVE(unk_807DA4DC);
    NERVE(unk_807DA4E0);
    NERVE(unk_807DA4E4);
    NERVE(unk_807DA4E8);
}