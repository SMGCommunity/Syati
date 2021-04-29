#pragma once

#include "JGeometry/TVec3.h"
#include "kamek.h"

class LiveActor;

namespace MR
{
    void initDefaultPos(LiveActor *, const JMapInfoIter &);

    bool isNear(const LiveActor *, const TVec3f &, f32);
    bool isNearPlayer(const LiveActor *, f32);
    bool isNearPlayerAnyTime(const LiveActor *, f32);

    void calcFrontVec(TVec3f *, const LiveActor *);
    void calcUpVec(TVec3f *, const LiveActor *);

    bool isInWater(const LiveActor *, const TVec3f &);

    void makeMtxTR(Mtx, const LiveActor *);
};
