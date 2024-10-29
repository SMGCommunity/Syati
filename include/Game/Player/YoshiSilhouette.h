#pragma once

#include "Game/LiveActor.h"
#include "Yoshi.h"

class YoshiSilhouette : public LiveActor {
public:
    YoshiSilhouette(Yoshi *);
    virtual ~YoshiSilhouette();
    virtual void init(const JMapInfoIter &);
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void movement();
    virtual void calcAnim();
    virtual void calcViewAndEntry();
    virtual void draw() const;

    u32 _90;
    u8 _94;
};