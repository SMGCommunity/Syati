#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/ActorCameraInfo.h"

class PowerStarAppearPoint : public LiveActor {
public:
    PowerStarAppearPoint(const char*);

    virtual ~PowerStarAppearPoint();
    virtual void init(const JMapInfoIter&);

    ActorCameraInfo* mCameraInfo;   // _90
};