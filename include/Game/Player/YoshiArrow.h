#pragma once

#include "Game/LiveActor.h"

class J3DJoint;

class YoshiArrow : public LiveActor {
public:
    YoshiArrow(const char *);
    virtual ~YoshiArrow();
    virtual void init(const JMapInfoIter &);
    virtual void appear();
    virtual void kill();
    virtual void control();
    virtual void calcAndSetBaseMtx();

    TMtx34f _90;
    f32 _C0;
    f32 _C4;
    J3DJoint *_C8;
    u32 _CC;
    TMtx34f _D0;
    f32 _100;
    f32 _104;
    f32 _108;
};