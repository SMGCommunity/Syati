#pragma once

#include "syati.h"

class Yoshi;

class YoshiTongue : public LiveActor {
public:
    YoshiTongue(Yoshi *, const char *);
    virtual ~YoshiTongue();
    virtual void init(const JMapInfoIter &);
    virtual void control();
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void calcAndSetBaseMtx();

    Yoshi *mYoshi; // _90
    FixedPosition *mTonguePos; // _94
    u32 _98;
    f32 _9C;
    f32 _A0;
    f32 _A4;
    f32 _A8;
    f32 _AC;
    f32 _B0;
    f32 _B4;
    u8 _B8;
    u8 _B9;
    f32 _BC;
    TVec3f _C0;
    u32 *_CC; // 8041D740
    u32 _D0;
    u32 _D4;
    f32 _D8;
    f32 _DC;
    f32 _E0;
    f32 _E4;
    LiveActor *mTongues[4]; // _E8
};