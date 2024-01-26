#pragma once

#include "Game/LiveActor/LiveActor.h"

class CloudMarioHat : public LiveActor {
public:
    CloudMarioHat(const char *pName);
    virtual void init(const JMapInfoIter &rIter);
    virtual void initAfterPlacement();
    virtual void calcAnim();
    virtual void appear();
    virtual void control();
    virtual void calcAndSetBaseMtx();
};