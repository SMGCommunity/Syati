#pragma once

#include "revolution/types.h"

class ActorPoseTQ : public TQuat4f {
public:
    ActorPoseTQ(); // 8022CAE0

    TVec3f _10;
};

// void unk_800102E0(ActorPoseTQ *, LiveActor *);
// void unk_80010600(ActorPoseTQ *, LiveActor *, f32, f32);