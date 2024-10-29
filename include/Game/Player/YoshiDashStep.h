#pragma once

#include "Game/LiveActor.h"

class YoshiDashStep : public LiveActor {
public:
    YoshiDashStep(const char *);
    virtual ~YoshiDashStep();
    virtual void init(const JMapInfoIter &);
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void control();
    virtual MtxPtr getBaseMtx() const;

    TMtx34f _90;
    u32 _C0;
};