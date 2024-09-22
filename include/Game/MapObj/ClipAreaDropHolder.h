#pragma once

#include "JSystem.h"
#include "Game/LiveActor/LiveActorGroup.h"

class ClipAreaDropHolder : LiveActorGroup {
    public:
        ClipAreaDropHolder(const char *, s32);

};

namespace MR {
    NameObj *createClipAreaDropHolder();
    bool getDeadClipAreaDrop();
    bool appearClipAreaDrop(const TVec3f &, f32);
    bool killClipAreaDrop(const TVec3f &, s32, s32, s32, f32);
};